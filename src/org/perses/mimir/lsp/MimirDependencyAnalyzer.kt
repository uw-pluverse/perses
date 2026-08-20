/*
 * Copyright (C) 2018-2026 University of Waterloo.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
package org.perses.mimir.lsp

import com.google.common.collect.ImmutableMap
import com.google.common.flogger.FluentLogger
import org.eclipse.lsp4j.ClientCapabilities
import org.eclipse.lsp4j.DidOpenTextDocumentParams
import org.eclipse.lsp4j.DocumentSymbol
import org.eclipse.lsp4j.DocumentSymbolCapabilities
import org.eclipse.lsp4j.InitializeParams
import org.eclipse.lsp4j.InitializedParams
import org.eclipse.lsp4j.Position
import org.eclipse.lsp4j.ReferenceContext
import org.eclipse.lsp4j.ReferenceParams
import org.eclipse.lsp4j.SemanticTokensCapabilities
import org.eclipse.lsp4j.SemanticTokensClientCapabilitiesRequests
import org.eclipse.lsp4j.SemanticTokensParams
import org.eclipse.lsp4j.SymbolInformation
import org.eclipse.lsp4j.TextDocumentClientCapabilities
import org.eclipse.lsp4j.TextDocumentIdentifier
import org.eclipse.lsp4j.TextDocumentItem
import org.eclipse.lsp4j.WorkspaceFolder
import org.eclipse.lsp4j.jsonrpc.messages.Either
import org.eclipse.lsp4j.launch.LSPLauncher
import org.eclipse.lsp4j.services.LanguageServer
import org.perses.reduction.semantics.SemanticTokenType
import org.perses.util.AutoDeletableFolder
import org.perses.util.DaemonThreadPool
import org.perses.util.SimpleStack
import org.perses.util.ktFine
import org.perses.util.shell.ShellCommandOnPath
import java.io.Closeable
import java.nio.file.Files
import java.nio.file.Path
import java.util.concurrent.TimeUnit
import java.util.concurrent.TimeoutException
import kotlin.io.path.extension
import kotlin.io.path.readText

/**
 * TODO(Hongxu): need to refine this.
 */
class MimirDependencyAnalyzer(
  languageServer: ShellCommandOnPath,
  sourceFile: Path,
) : Closeable {
  init {
    require(Files.isRegularFile(sourceFile)) {
      "Source file does not exist: $sourceFile"
    }
  }

  private val closer = SimpleStack<Closeable>()

  private val sourceFile = sourceFile.toAbsolutePath()
  private val fileUri = this.sourceFile.toUri().toString()
  private val textDocumentIdentifier = TextDocumentIdentifier(fileUri)

  private val sourceCode = sourceFile.readText()
  private val linesOfSourceCode = sourceCode.lines()
  private val process =
    ProcessBuilder(languageServer.normalizedCommand)
      .redirectError(ProcessBuilder.Redirect.DISCARD)
      .start()
      .also { process ->
        closer.add(
          Closeable {
            process.descendants().forEach { it.destroy() }
            process.destroy()
          },
        )
        closer.add(process.inputStream)
        closer.add(process.errorStream)
        closer.add(process.outputStream)
      }

  val executorService =
    DaemonThreadPool
      .create(
        numThreads = 5,
        creatorObject = this,
      ).also {
        closer.add(Closeable { DaemonThreadPool.shutdownOrThrow(it) })
      }
  private val server: LanguageServer =
    run {
      val client = MimirLanguageServerClient()
      val launcher =
        LSPLauncher
          .Builder<LanguageServer>()
          .setLocalService(client)
          .setRemoteInterface(LanguageServer::class.java)
          .setInput(process.inputStream)
          .setOutput(process.outputStream)
          .validateMessages(true)
          .setExecutorService(executorService)
          .create()
      val listenFuture = launcher.startListening()
      closer.add(Closeable { listenFuture.cancel(true) })
      launcher.remoteProxy
    }.also { server ->
      closer.add(
        Closeable {
          server.shutdown().get(1000, TimeUnit.MILLISECONDS)
          server.exit()
        },
      )
    }

  /**
   * We use an isolated temporary directory as the workspace root for the language server.
   * This prevents JLS from identifying the entire repository as its workspace (by searching
   * for a WORKSPACE file in parent directories), which can lead to significant slowness
   * as the server attempts to scan and index the whole project.
   */
  private val isolatedWorkspaceRoot =
    AutoDeletableFolder
      .createTempDir("perses_mimir_lsp_workspace_")
      .also { closer.add(it) }

  // 2. Agnostic Initialization
  @Suppress("DEPRECATION")
  private val initParams =
    InitializeParams().apply {
      val workspaceFolderUri = isolatedWorkspaceRoot.file.toUri().toString()
      rootUri = workspaceFolderUri
      workspaceFolders = listOf(WorkspaceFolder(workspaceFolderUri, "workspace"))
      capabilities =
        ClientCapabilities().apply {
          textDocument =
            TextDocumentClientCapabilities().apply {
              documentSymbol =
                DocumentSymbolCapabilities().apply { hierarchicalDocumentSymbolSupport = true }
              semanticTokens =
                SemanticTokensCapabilities().apply {
                  requests = SemanticTokensClientCapabilitiesRequests(true)
                  formats = listOf("relative")
                  tokenTypes =
                    listOf(
                      SemanticTokenType.VARIABLE.typeName,
                      "parameter",
                      SemanticTokenType.FUNCTION.typeName,
                      SemanticTokenType.METHOD.typeName,
                      "class",
                      "interface",
                      "enum",
                      "typeParameter",
                      "type",
                      "member",
                      "event",
                      "property",
                      "macro",
                      "label",
                      "comment",
                      "string",
                      "keyword",
                      "number",
                      "regexp",
                      "operator",
                    )
                  tokenModifiers =
                    listOf(
                      "declaration",
                      "definition",
                      "readonly",
                      "static",
                      "deprecated",
                      "abstract",
                      "async",
                      "modification",
                      "documentation",
                      "defaultLibrary",
                    )
                }
            }
        }
    }
  private val serverCapabilities =
    server
      .initialize(initParams)
      .let { future ->
        try {
          future.get(1, TimeUnit.MINUTES)
        } catch (e: TimeoutException) {
          if (!process.isAlive) {
            throw RuntimeException(
              "Language server process died before initialization. Exit code: ${process.exitValue()}",
              e,
            )
          }
          throw e
        }
      }.let {
        server.initialized(InitializedParams())
        it.capabilities
      }

  init {
    // TODO(cnsun): use the language kind for the language id.
    val languageId =
      when (sourceFile.extension.lowercase()) {
        "java" -> "java"
        "c" -> "c"
        "h" -> "c"
        "cpp" -> "cpp"
        "hpp" -> "cpp"
        else -> "c" // Default to c for now
      }
    // 3. Open File
    server.textDocumentService.didOpen(
      DidOpenTextDocumentParams(
        TextDocumentItem(fileUri, languageId, 1, sourceCode),
      ),
    )
  }

  private val semanticTokenProvider =
    serverCapabilities.semanticTokensProvider

  private val typeMapping =
    semanticTokenProvider?.legend?.tokenTypes ?: emptyList<String>()
  private val modifierMapping =
    semanticTokenProvider?.legend?.tokenModifiers ?: emptyList<String>()

  private val interestingTokenTypes =
    setOf(
      SemanticTokenType.VARIABLE,
      SemanticTokenType.PARAMETER,
      SemanticTokenType.FIELD,
      SemanticTokenType.FUNCTION,
      SemanticTokenType.METHOD,
      // JDTLS often classifies Java fields as "property" in its semantic tokens.
      SemanticTokenType.PROPERTY,
    )

  private val decodedSemanticTokens: List<LspSemanticToken> =
    if (semanticTokenProvider != null) {
      server.textDocumentService
        .semanticTokensFull(
          SemanticTokensParams(textDocumentIdentifier),
        ).get()
        .let { rawSemanticTokens ->
          decodeDynamicTokens(
            data = rawSemanticTokens.data,
            typeMapping = typeMapping,
            modifierMapping = modifierMapping,
          )
        }
    } else {
      logger.atInfo().log("Semantic tokens not supported, falling back to documentSymbol...")
      gatherTokensViaDocumentSymbol()
    }

  @Suppress("DEPRECATION")
  private fun gatherTokensViaDocumentSymbol(): List<LspSemanticToken> {
    val future =
      server.textDocumentService.documentSymbol(
        org.eclipse.lsp4j.DocumentSymbolParams(textDocumentIdentifier),
      )
    val symbols = future.get() ?: return emptyList()
    val result = mutableListOf<LspSemanticToken>()

    fun processSymbol(symbol: Either<SymbolInformation, DocumentSymbol>) {
      if (symbol.isLeft) {
        val info = symbol.left
        val range = info.location.range
        val type = asSemanticTokenType(info.kind)
        result.add(
          LspSemanticToken(
            type = type,
            lexeme = info.name,
            modifiers = listOf("definition", "declaration"),
            position = range.start,
            length = info.name.length,
          ),
        )
      } else {
        val doc = symbol.right
        val range = doc.selectionRange ?: doc.range
        val type = asSemanticTokenType(doc.kind)
        result.add(
          LspSemanticToken(
            type = type,
            lexeme = doc.name,
            modifiers = listOf("definition", "declaration"),
            position = range.start,
            length = doc.name.length,
          ),
        )
        doc.children?.forEach {
          processSymbol(
            Either
              .forRight(it),
          )
        }
      }
    }

    symbols.forEach { processSymbol(it) }
    return result
  }

  private fun asSemanticTokenType(kind: org.eclipse.lsp4j.SymbolKind): SemanticTokenType =
    when (kind) {
      org.eclipse.lsp4j.SymbolKind.Variable -> SemanticTokenType.VARIABLE
      org.eclipse.lsp4j.SymbolKind.Field -> SemanticTokenType.FIELD
      org.eclipse.lsp4j.SymbolKind.Method -> SemanticTokenType.METHOD
      org.eclipse.lsp4j.SymbolKind.Function -> SemanticTokenType.FUNCTION
      org.eclipse.lsp4j.SymbolKind.Class -> SemanticTokenType.of("class")
      org.eclipse.lsp4j.SymbolKind.Interface -> SemanticTokenType.of("class")
      org.eclipse.lsp4j.SymbolKind.Enum -> SemanticTokenType.of("class")
      org.eclipse.lsp4j.SymbolKind.Constant -> SemanticTokenType.VARIABLE
      org.eclipse.lsp4j.SymbolKind.Namespace -> SemanticTokenType.of("namespace")
      org.eclipse.lsp4j.SymbolKind.Property -> SemanticTokenType.FIELD
      else -> SemanticTokenType.of("keyword")
    }

  private val startPosition2DecodedSemanticTokens =
    ImmutableMap
      .builder<Position, LspSemanticToken>()
      .also { builder ->
        decodedSemanticTokens.forEach { token ->
          builder.put(token.position, token)
        }
      }.build()

  private val interestingDecodedSemanticTokens =
    decodedSemanticTokens.filter { it.type in interestingTokenTypes }
  private val lexemeFrequencyMap =
    interestingDecodedSemanticTokens
      .groupBy { it.lexeme }
      .map { it.key to it.value.count() }
      .toMap()

  private val isJava = sourceFile.extension.lowercase() == "java"

  val interestingDefsOrDecls =
    interestingDecodedSemanticTokens.filter {
      if (isJava) {
        it.isDeclaration || it.isDefinition
      } else {
        it.isDefinition && !it.isDeclarationOnlyButNotDefinition
      }
    }

  val defUseMap: Map<LspSemanticToken, List<LspSemanticToken>> = buildDefUseMap()

  private fun buildDefUseMap(): Map<LspSemanticToken, List<LspSemanticToken>> =
    interestingDefsOrDecls.associateWith { defToken ->
      logger.ktFine {
        val position = defToken.position
        val positionString = "line=${position.line},column=${position.character}"
        "Finding references for ${defToken.lexeme} at $positionString"
      }
      val lexeme = defToken.lexeme
      if (lexemeFrequencyMap.getOrDefault(lexeme, defaultValue = 0) < 2) {
        // The element is not used elsewhere.
        emptyList()
      } else {
        findReferences(defToken)
      }
    }

  override fun close() {
    val exceptions = mutableListOf<Throwable>()
    while (closer.isNotEmpty()) {
      val resource = closer.remove()
      try {
        resource.close()
      } catch (e: Exception) {
        exceptions.add(e)
      }
    }
    if (exceptions.isNotEmpty()) {
      throw RuntimeException(
        """Exceptions occurred while closing ${this::class.qualifiedName}
          |
          |${exceptions.joinToString(separator = "\n") { it.message.toString() }}
        """.trimMargin(),
        exceptions.first(),
      )
    }
  }

  fun findReferences(defToken: LspSemanticToken): List<LspSemanticToken> {
    val defPosition = defToken.position
    val future =
      server.textDocumentService
        .references(
          ReferenceParams().apply {
            textDocument = TextDocumentIdentifier(fileUri)
            position = defPosition
            context = ReferenceContext(true)
          },
        )
    val referenceLocations = future.get(10, TimeUnit.SECONDS) ?: emptyList()

    val result =
      referenceLocations
        .map { location ->
          startPosition2DecodedSemanticTokens[location.range.start]
            ?: run {
              // Synthesize a token if it's missing (happens with JLS fallback)
              val start = location.range.start
              val end = location.range.end
              val length =
                if (start.line ==
                  end.line
                ) {
                  end.character - start.character
                } else {
                  defToken.length
                }
              LspSemanticToken(
                type = defToken.type,
                lexeme = getLexeme(start, length),
                modifiers = emptyList(),
                position = start,
                length = length,
              )
            }
        }.filter { referenceToken ->
          // exclude the definition token.
          referenceToken.position != defPosition &&
            // exclude declaration, as declaration depends on nothing.
            !referenceToken.isDeclarationOnlyButNotDefinition
        }
    return result
  }

  fun getLexeme(
    position: Position,
    length: Int,
  ): String {
    val line = linesOfSourceCode.getOrNull(position.line) ?: return ""
    val start = position.character

    // Ensure we don't go out of bounds
    val end = (start + length).coerceAtMost(line.length)

    return if (start < line.length) {
      line.substring(start, end)
    } else {
      ""
    }
  }

  fun decodeDynamicTokens(
    data: List<Int>,
    typeMapping: List<String>,
    modifierMapping: List<String>,
  ): List<LspSemanticToken> {
    val result = mutableListOf<LspSemanticToken>()
    var currentLine = 0
    var currentChar = 0
    for (i in data.indices step 5) {
      val deltaLine = data[i]
      val deltaChar = data[i + 1]
      val length = data[i + 2]
      currentLine += deltaLine
      currentChar = if (deltaLine > 0) deltaChar else currentChar + deltaChar

      val typeIndex = data[i + 3]
      val modifierBitmask = data[i + 4]

      val modifiers = mutableListOf<String>()
      for (bit in modifierMapping.indices) {
        if ((modifierBitmask and (1 shl bit)) != 0) {
          modifiers.add(modifierMapping[bit])
        }
      }

      val position = Position(currentLine, currentChar)
      result.add(
        LspSemanticToken(
          type = SemanticTokenType.of(typeMapping.getOrElse(typeIndex) { "unknown" }),
          lexeme = getLexeme(position, length),
          modifiers = modifiers,
          position = position,
          length = length,
        ),
      )
    }
    return result
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
