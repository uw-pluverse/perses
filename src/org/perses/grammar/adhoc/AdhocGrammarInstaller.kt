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

import com.google.common.flogger.FluentLogger
import org.perses.PersesConstants
import org.perses.antlr.AntlrCompiler
import org.perses.antlr.pnf.PnfNormalizer
import org.perses.grammar.adhoc.AdhocGrammarConfiguration.ParserFacadeJarFile.LanguageInfo
import org.perses.util.Util
import org.perses.util.java.JarFile
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path
import java.util.zip.ZipEntry
import kotlin.io.path.readText

class AdhocGrammarInstaller(
  private val configuration: AdhocGrammarConfiguration,
  private val persesConstants: PersesConstants,
  private val outputPath: Path?,
  private val enablePnfNormalization: Boolean,
) {

  fun run(): JarFile {
    val grammarRootFolder = createDirectoryForGrammar(
      configuration,
      persesConstants,
    )
    val grammarSourceFolder = createGrammarSourceFolder(
      grammarRootFolder,
      configuration.packageName,
    )
    configuration.copyGrammarFilesToDirectory(grammarSourceFolder)

    val pnfGrammar = if (enablePnfNormalization) {
      normalizePNF(grammarSourceFolder)
    } else {
      grammarSourceFolder.resolve(configuration.parserFile.fileName)
    }

    val workingDirectory = Util.ensureDirExists(
      grammarRootFolder.resolve("generate_jar"),
    )

    Util.clearDirectory(workingDirectory)

    val compiler = AntlrCompiler.createFromFiles(
      parserFile = pnfGrammar,
      lexerFile = configuration.lexerFile,
      parserBase = configuration.parserBase,
      lexerBase = configuration.lexerBase,
      startRuleName = configuration.startRuleName,
      workingDirectory = workingDirectory,
      stubFactory = ParserFacadeStubFactory(
        grammarName = configuration.parserGrammar.grammarName,
        parserFile = pnfGrammar,
        lexerFile = configuration.lexerFile,
        languageKindSetting = if (configuration.languageKindYamlFile != null) {
          ParserFacadeStubFactory.YamlLanguageKindSetting(
            configuration.languageKindYamlFile!!.readText(),
          )
        } else {
          ParserFacadeStubFactory.ExistingLanguageKindSetting(
            configuration.existingLanguageKindClassFullName!!,
          )
        },
        parserFacadeClassSimpleName = configuration.parserFacadeClassSimpleName,
        tokenNamesOfIdentifiers = configuration.sortedDistinctTokenNamesOfIdentifiers,
      ),
      packageName = configuration.packageName,
      jarFileCustomizer = { zipStream ->
        val zipEntry = ZipEntry(
          AdhocGrammarConfiguration.ParserFacadeJarFile.LANGUAGE_INFO_FILE_PATH,
        )
        zipStream.putNextEntry(zipEntry)
        LanguageInfo(configuration.parserFacadeClassFullName).toYamlString().let {
          zipStream.write(it.toByteArray(StandardCharsets.UTF_8))
        }
        zipStream.closeEntry()
      },
    )
    val jarFile = compiler.run()
    return if (outputPath == null) {
      jarFile.moveTo(configuration.computeJarFilePathPathForGrammar(persesConstants))
    } else {
      jarFile.moveTo(outputPath)
    }
  }

  private fun createGrammarSourceFolder(
    grammarRootFolder: Path,
    packageName: String,
  ): Path {
    val sourceFolder = grammarRootFolder.resolve(packageName.replace(".", "/"))
    val result = Files.createDirectories(sourceFolder)
    Util.ensureDirExists(result)
    return result
  }

  private fun normalizePNF(
    grammarSourceFolder: Path,
  ): Path {
    val outputFile = grammarSourceFolder.resolve("Pnf" + configuration.parserFile.fileName)

    PnfNormalizer(
      configuration.parserFile,
      configuration.lexerFile,
      configuration.startRuleName,
      outputFile,
    ).run()
    return outputFile
  }

  companion object {

    private fun createDirectoryForGrammar(
      grammarConfiguration: AdhocGrammarConfiguration,
      persesConstants: PersesConstants,
    ): Path {
      val result = grammarConfiguration.computeDirectoryForGrammar(persesConstants)
      Util.ensureDirExists(result)
      return result
    }

    val logger = FluentLogger.forEnclosingClass()
  }
}
