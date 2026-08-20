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

import com.google.common.flogger.FluentLogger
import com.sun.source.tree.CompilationUnitTree
import com.sun.source.tree.IdentifierTree
import com.sun.source.tree.MemberSelectTree
import com.sun.source.tree.MethodTree
import com.sun.source.tree.Tree
import com.sun.source.tree.VariableTree
import com.sun.source.util.JavacTask
import com.sun.source.util.TreePathScanner
import com.sun.source.util.Trees
import org.antlr.v4.runtime.CharStreams
import org.antlr.v4.runtime.Token
import org.eclipse.lsp4j.Position
import org.perses.grammar.java.Java8Lexer
import org.perses.reduction.semantics.SemanticTokenType
import org.perses.util.java.JavacWrapper
import java.nio.file.Path
import javax.lang.model.element.Element
import javax.lang.model.element.ElementKind
import javax.tools.DiagnosticCollector
import javax.tools.JavaFileObject
import javax.tools.ToolProvider

class JavacDependencyAnalyzer(
  private val sourceFile: Path,
) {
  private val compiler =
    ToolProvider.getSystemJavaCompiler()
      ?: error("System Java compiler not found. Please ensure you are running with a JDK.")

  private val diagnostics = DiagnosticCollector<JavaFileObject>()
  private val fileManager = compiler.getStandardFileManager(diagnostics, null, null)

  private val compilationUnit: CompilationUnitTree
  private val trees: Trees
  private val task: JavacTask

  init {
    val fileObjects = fileManager.getJavaFileObjects(sourceFile.toFile())
    val options = mutableListOf<String>()
    val classpath = JavacWrapper.getJarsOnClasspath()
    if (classpath.isNotEmpty()) {
      options.add("-classpath")
      options.add(classpath.joinToString(java.io.File.pathSeparator))
    }

    task = compiler.getTask(null, fileManager, diagnostics, options, null, fileObjects) as JavacTask
    compilationUnit = task.parse().first()
    task.analyze()
    trees = Trees.instance(task)
  }

  private val allSourceTokens: List<Token> by lazy {
    val source = compilationUnit.sourceFile.getCharContent(true).toString()
    val lexer = Java8Lexer(CharStreams.fromString(source))
    val tokens = mutableListOf<Token>()
    var t = lexer.nextToken()
    while (t.type != Token.EOF) {
      tokens.add(t)
      t = lexer.nextToken()
    }
    tokens
  }

  val defUseMap: Map<LspSemanticToken, List<LspSemanticToken>> by lazy {
    buildDefUseMap()
  }

  private fun buildDefUseMap(): Map<LspSemanticToken, List<LspSemanticToken>> {
    val elementToDef = mutableMapOf<Element, LspSemanticToken>()
    val elementToUses = mutableMapOf<Element, MutableList<LspSemanticToken>>()

    val scanner =
      object : TreePathScanner<Void?, Void?>() {
        override fun visitVariable(
          node: VariableTree,
          p: Void?,
        ): Void? {
          val element = trees.getElement(currentPath)
          if (element != null) {
            val token = createToken(node, element)
            if (token != null) {
              elementToDef[element] = token
            }
          }
          return super.visitVariable(node, p)
        }

        override fun visitMethod(
          node: MethodTree,
          p: Void?,
        ): Void? {
          val element = trees.getElement(currentPath)
          if (element != null) {
            val token = createToken(node, element)
            if (token != null) {
              elementToDef[element] = token
            }
          }
          return super.visitMethod(node, p)
        }

        override fun visitIdentifier(
          node: IdentifierTree,
          p: Void?,
        ): Void? {
          val element = trees.getElement(currentPath)
          if (element != null) {
            val token = createToken(node, element)
            if (token != null) {
              elementToUses.getOrPut(element) { mutableListOf() }.add(token)
            }
          }
          return super.visitIdentifier(node, p)
        }

        override fun visitMemberSelect(
          node: MemberSelectTree,
          p: Void?,
        ): Void? {
          val element = trees.getElement(currentPath)
          if (element != null) {
            val token = createToken(node, element)
            if (token != null) {
              elementToUses.getOrPut(element) { mutableListOf() }.add(token)
            }
          }
          return super.visitMemberSelect(node, p)
        }

        override fun visitImport(
          node: com.sun.source.tree.ImportTree,
          p: Void?,
        ): Void? {
          // Ignore imports as they are not needed for def-use analysis and cause lexeme collisions.
          return null
        }
      }

    scanner.scan(compilationUnit, null)

    return elementToDef.entries.associate { (element, defToken) ->
      val uses = elementToUses[element] ?: emptyList<LspSemanticToken>()
      val filteredUses = uses.filter { it.position != defToken.position }
      defToken to filteredUses
    }
  }

  private fun createToken(
    tree: Tree,
    element: Element,
  ): LspSemanticToken? {
    val lexeme = element.simpleName.toString()
    if (lexeme == "<init>") return null

    val positions = trees.sourcePositions
    val startPosRaw = positions.getStartPosition(compilationUnit, tree).toInt()
    val endPosRaw = positions.getEndPosition(compilationUnit, tree).toInt()

    // Skip synthetic nodes or nodes with invalid positions (e.g., parameters of synthetic constructors in anonymous classes).
    if (startPosRaw < 0 || endPosRaw < 0 || startPosRaw > endPosRaw) return null

    var startPos = startPosRaw
    var endPos = endPosRaw

    // For MethodTree, VariableTree, and MemberSelectTree, we want the position of the identifier,
    // not the whole tree (which includes modifiers, type, or the expression before '.').
    if (tree is VariableTree || tree is MethodTree || tree is MemberSelectTree) {
      val source = compilationUnit.sourceFile.getCharContent(true).toString()

      // Refine range to avoid matching identifiers in bodies or initializers
      var searchEnd = endPos
      var searchStart = startPos

      when (tree) {
        is MethodTree -> {
          val body = tree.body
          if (body != null) {
            val bodyStart = positions.getStartPosition(compilationUnit, body).toInt()
            if (bodyStart in 0 until searchEnd) {
              searchEnd = bodyStart
            }
          }
        }
        is VariableTree -> {
          val initializer = tree.initializer
          if (initializer != null) {
            val initializerStart = positions.getStartPosition(compilationUnit, initializer).toInt()
            if (initializerStart in 0 until searchEnd) {
              searchEnd = initializerStart
            }
          }
        }
        is MemberSelectTree -> {
          // For a.b.c, the last identifier 'c' is what we want.
          // It's after the dot.
          if (startPos in 0 until endPos && endPos <= source.length) {
            val treeSource = source.substring(startPos, endPos)
            val lastDot = treeSource.lastIndexOf('.')
            if (lastDot != -1) {
              searchStart += lastDot + 1
            }
          }
        }
      }

      if (searchStart < 0 ||
        searchEnd < 0 ||
        searchStart > searchEnd ||
        searchEnd > source.length
      ) {
        return null
      }

      val refinedSource = source.substring(searchStart, searchEnd)

      // Filter existing tokens that fall within the refined range
      val matchingTokens =
        allSourceTokens.filter {
          it.startIndex >= searchStart &&
            it.stopIndex < searchEnd &&
            it.type == Java8Lexer.Identifier &&
            it.text == lexeme
        }

      check(matchingTokens.size <= 1) {
        "Multiple matches for lexeme '$lexeme' in ${tree.kind} at ${compilationUnit.sourceFile.name}: $matchingTokens in '$refinedSource'"
      }

      val token = matchingTokens.lastOrNull()
      if (token != null) {
        // startIndex is already relative to the whole file
        startPos = token.startIndex
      } else {
        // If we can't find the exact token in the refined range, it might be safer to skip or use the original startPos
        // For VariableTree/MethodTree, if we can't find the identifier token, something is wrong.
        if (tree is VariableTree || tree is MethodTree) {
          return null
        }
      }
    }

    val lineMap = compilationUnit.lineMap
    val line = lineMap.getLineNumber(startPos.toLong()) - 1
    val column = lineMap.getColumnNumber(startPos.toLong()) - 1
    val type =
      when (element.kind) {
        ElementKind.LOCAL_VARIABLE,
        ElementKind.RESOURCE_VARIABLE,
        ElementKind.EXCEPTION_PARAMETER,
        -> SemanticTokenType.VARIABLE
        ElementKind.PARAMETER -> SemanticTokenType.PARAMETER
        ElementKind.FIELD -> SemanticTokenType.FIELD
        ElementKind.METHOD -> SemanticTokenType.METHOD
        ElementKind.CONSTRUCTOR -> SemanticTokenType.METHOD
        ElementKind.CLASS,
        ElementKind.INTERFACE,
        ElementKind.ENUM,
        ElementKind.ANNOTATION_TYPE,
        -> SemanticTokenType.of("class")
        else -> return null
      }

    // Determine modifiers
    val modifiers = mutableListOf<String>()
    if (tree is VariableTree || tree is MethodTree) {
      modifiers.add("definition")
      modifiers.add("declaration")
    }

    return LspSemanticToken(
      type = type,
      lexeme = lexeme,
      modifiers = modifiers,
      position = Position(line.toInt(), column.toInt()),
      length = lexeme.length,
    )
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
