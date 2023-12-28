/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.grammar.adhoc

import com.google.common.hash.Hashing
import org.perses.PersesConstants
import org.perses.antlr.ast.PersesAstBuilder
import org.perses.grammar.AbstractParserFacade
import org.perses.program.LanguageKind
import org.perses.util.YamlUtil
import org.perses.util.java.JarFile
import org.perses.util.toImmutableList
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.StandardCopyOption
import kotlin.io.path.readText
import kotlin.reflect.KClass
import kotlin.reflect.full.createInstance

class AdhocGrammarConfiguration(
  val parserFile: Path,
  val lexerFile: Path?,
  val parserBase: Path?,
  val lexerBase: Path?,
  packageName: String?,
  parserFacadeClassSimpleName: String?,
  val languageKindYamlFile: Path?,
  val existingLanguageKindClassFullName: String?,
  val startRuleName: String,
  tokenNamesOfIdentifiers: List<String>,
) {

  val parserGrammar = readAntlrGrammar(parserFile)
  val packageName = packageName ?: computeGrammarPackageName(parserGrammar.grammarName)
  val parserFacadeClassSimpleName = parserFacadeClassSimpleName
    ?: parserGrammar.grammarName + "AdhocParserFacade"
  val sortedDistinctTokenNamesOfIdentifiers = tokenNamesOfIdentifiers
    .asSequence()
    .sorted()
    .distinct()
    .toImmutableList()

  val parserFacadeClassFullName: String
    get() = "$packageName.$parserFacadeClassSimpleName"

  init {
    require(Files.isRegularFile(parserFile))
    require(lexerFile == null || Files.isRegularFile(lexerFile))
    requireNotNull(parserGrammar.getRuleDefinition(startRuleName)) {
      "Cannot find the start rule witht he name $startRuleName"
    }
    require(languageKindYamlFile == null || Files.isRegularFile(languageKindYamlFile))
    require(existingLanguageKindClassFullName != null || languageKindYamlFile != null)
    require(parserBase == null || Files.isRegularFile(parserBase))
    require(lexerBase == null || Files.isRegularFile(lexerBase))
  }

  fun computeDirectoryForGrammar(
    persesConstants: PersesConstants,
  ): Path {
    val adhocGrammarRoot = persesConstants
      .getPersesRootFolderOrCreate().getPersesAdhocRootOrCreate()
    val hash = computeContentHashCode()
    return adhocGrammarRoot.file.resolve(
      "${parserGrammar.grammarName}/$hash",
    )
  }

  fun computeJarFilePathPathForGrammar(persesConstants: PersesConstants): Path {
    return computeDirectoryForGrammar(persesConstants)
      .resolve("perses_adhoc_language_support.jar")
  }

  fun loadJarFile(persesConstants: PersesConstants): ParserFacadeJarFile {
    val path = computeJarFilePathPathForGrammar(persesConstants)
    check(Files.isRegularFile(path)) { "Jar file $path is not a file." }
    return ParserFacadeJarFile.from(
      path,
    )
  }

  fun computeContentHashCode(): String {
    val combinedParserLexer = buildString {
      append(parserFile.readText()).append("\n")
      lexerFile?.readText()?.let { append(it).append("\n") }
      append("package-name=").append("\n")
      append("parser-facade-class-simple-name:").append(parserFacadeClassSimpleName).append("\n")
      append("language-kind-yaml-file:").append(languageKindYamlFile).append("\n")
      append("existing-language-kind-class-simple-name:")
        .append(existingLanguageKindClassFullName)
        .append("\n")
      append("token-names-of-identifiers:")
        .append(sortedDistinctTokenNamesOfIdentifiers)
        .append("\n")
    }
    return Hashing.sha256().hashString(
      combinedParserLexer,
      StandardCharsets.UTF_8,
    ).toString()
  }

  fun copyGrammarFilesToDirectory(dir: Path) {
    Files.copy(
      parserFile,
      dir.resolve(parserFile.fileName),
      StandardCopyOption.REPLACE_EXISTING,
    )
    lexerFile?.let {
      Files.copy(
        lexerFile,
        dir.resolve(lexerFile.fileName),
        StandardCopyOption.REPLACE_EXISTING,
      )
    }
    parserBase?.let {
      Files.copy(
        parserBase,
        dir.resolve(parserBase.fileName),
        StandardCopyOption.REPLACE_EXISTING,
      )
    }
    lexerBase?.let {
      Files.copy(
        lexerBase,
        dir.resolve(lexerBase.fileName),
        StandardCopyOption.REPLACE_EXISTING,
      )
    }
  }

  companion object {
    fun readAntlrGrammar(parserFile: Path) = PersesAstBuilder
      .loadGrammarFromString(parserFile.readText())

    fun computeGrammarPackageName(grammarName: String) =
      "org.perses.grammar.adhoc.${grammarName.lowercase()}"
  }

  class ParserFacadeJarFile private constructor(
    jarFile: JarFile,
  ) {
    @Suppress("UNCHECKED_CAST")
    val klass = jarFile.loadMainClass().kotlin as KClass<out AbstractParserFacade>
    val languageKind = klass.java.getField("LANGUAGE").get(null) as LanguageKind
    fun createParserFacade(): AbstractParserFacade {
      return klass.createInstance()
    }

    companion object {
      const val FIELD_NAME_LANGUAGE = "LANGUAGE"
      const val LANGUAGE_INFO_FILE_PATH = "META-INFO/language_info.yaml"

      fun from(path: Path): ParserFacadeJarFile {
        return ParserFacadeJarFile(
          JarFile(path, readLanguageInfoOrNull(path)!!.parserFacadeClassFullName),
        )
      }

      fun isParserFacadeJarFile(path: Path): Boolean {
        return readLanguageInfoOrNull(path) != null
      }

      private fun readLanguageInfoOrNull(path: Path): LanguageInfo? {
        return try {
          val yaml = JarFile.readTextFileInZipFile(
            path,
            LANGUAGE_INFO_FILE_PATH,
          )
          return YamlUtil.fromYamlString(yaml, LanguageInfo::class.java)
        } catch (e: Exception) {
          null
        }
      }
    }

    data class LanguageInfo(val parserFacadeClassFullName: String) {
      fun toYamlString(): String {
        return YamlUtil.toYamlString(this)
      }
    }
  }
}
