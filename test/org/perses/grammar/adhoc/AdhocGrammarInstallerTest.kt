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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.PersesConstants
import org.perses.antlr.AbstractAntlrrdcTest
import org.perses.grammar.AbstractParserFacade
import org.perses.program.SerializableLanguageKind
import java.nio.file.Files
import java.util.zip.ZipFile
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class AdhocGrammarInstallerTest : AbstractAntlrrdcTest() {

  val workingDir = tempDir.resolve("empty_working_dir").apply {
    Files.createDirectories(this)
  }

  val languageKindYamlFile = tempDir.resolve("language_kind_adhoc.yaml").apply {
    writeText(LanguageAdhoc.INSTANCE.toYamlString())
  }

  @After
  fun teardown() {
    close()
  }

  @Test
  fun test_adhoc_installer_generates_jar_seperate() {
    val testPersesConstants = PersesConstants.createCustomizedConstants(workingDir)
    val testOptions = CommandOptions()
    testOptions.compulsoryFlags.parserGrammar = parserGrammarPath
    testOptions.compulsoryFlags.lexerGrammar = lexerGrammarPath
    testOptions.compulsoryFlags.startRuleName = "start"
    testOptions.compulsoryFlags.languageKindYamlFile = languageKindYamlFile
    testOptions.compulsoryFlags.tokenNamesOfIdentifiers = listOf("ID")
    testOptions.validate()

    val installer = AdhocGrammarInstaller(
      testOptions.computeAdhocGrammarConfiguration(),
      testPersesConstants,
      testOptions.outputFlags.output,
      enablePnfNormalization = true,
    )
    val generatedJar = installer.run()
    assertThat(generatedJar.path.toString()).isEqualTo(
      workingDir.resolve(
        ".perses/installed_adhoc_languages/TestParser/" +
          testOptions.compulsoryFlags.createAdhocGrammarConfiguration().computeContentHashCode() +
          "/perses_adhoc_language_support.jar",
      ).toString(),
    )
    assertThat(generatedJar.mainClassFullName).isEqualTo(
      "org.perses.grammar.adhoc.testparser.TestParserAdhocParserFacade",
    )

    ZipFile(generatedJar.path.toFile()).use { zipFile ->
      val entryNames = zipFile.entries().asSequence().map { it.name }.toList()
      assertThat(entryNames).containsExactly(
        "META-INFO/language_info.yaml",
        "org/perses/grammar/adhoc/testparser/PnfTestParser${'$'}StartContext.class",
        "org/perses/grammar/adhoc/testparser/PnfTestParser.class",
        "org/perses/grammar/adhoc/testparser/PnfTestParser.java",
        "org/perses/grammar/adhoc/testparser/PnfTestParser.g4",
        "org/perses/grammar/adhoc/testparser/PnfTestParser\$Kleene_plus__start_1Context.class",
        "org/perses/grammar/adhoc/testparser/TestLexer.class",
        "org/perses/grammar/adhoc/testparser/TestLexer.java",
        "org/perses/grammar/adhoc/testparser/TestLexer.g4",
        "org/perses/grammar/adhoc/testparser/TestParserAdhocParserFacade.class",
        "org/perses/grammar/adhoc/testparser/TestParserAdhocParserFacade.java",
      )
    }
    val facade = generatedJar.loadMainClass().getConstructor().newInstance() as AbstractParserFacade
    val language = facade.language
    assertThat(SerializableLanguageKind.LanguageKindData.from(language)).isEqualTo(
      SerializableLanguageKind.LanguageKindData.from(LanguageAdhoc.INSTANCE),
    )
  }

  @Test
  fun test_adhoc_installer_generates_jar_combined() {
    val testPersesConstants = PersesConstants.createCustomizedConstants(workingDir)
    val testOptions = CommandOptions()
    testOptions.compulsoryFlags.parserGrammar = combinedGrammarPath
    testOptions.compulsoryFlags.lexerGrammar = null
    testOptions.compulsoryFlags.startRuleName = "start"
    testOptions.compulsoryFlags.languageKindYamlFile = languageKindYamlFile
    testOptions.compulsoryFlags.tokenNamesOfIdentifiers = listOf("ID")
    testOptions.validate()

    val installer = AdhocGrammarInstaller(
      testOptions.computeAdhocGrammarConfiguration(),
      testPersesConstants,
      testOptions.outputFlags.output,
      enablePnfNormalization = true,
    )
    val generatedJar = installer.run()
    assertThat(generatedJar.path.toString()).isEqualTo(
      workingDir.resolve(
        ".perses/installed_adhoc_languages/TestCombined/" +
          testOptions.compulsoryFlags.createAdhocGrammarConfiguration().computeContentHashCode() +
          "/perses_adhoc_language_support.jar",
      ).toString(),
    )
    assertThat(generatedJar.mainClassFullName).isEqualTo(
      "org.perses.grammar.adhoc.testcombined.TestCombinedAdhocParserFacade",
    )

    ZipFile(generatedJar.path.toFile()).use { zipFile ->
      val entryNames = zipFile.entries().asSequence().map { it.name }.toList()
      assertThat(entryNames).containsExactly(
        "META-INFO/language_info.yaml",
        "org/perses/grammar/adhoc/testcombined/PnfTestCombinedParser${'$'}StartContext.class",
        "org/perses/grammar/adhoc/testcombined/PnfTestCombinedParser.class",
        "org/perses/grammar/adhoc/testcombined/PnfTestCombinedParser.java",
        "org/perses/grammar/adhoc/testcombined/PnfTestCombinedLexer.class",
        "org/perses/grammar/adhoc/testcombined/PnfTestCombinedLexer.java",
        "org/perses/grammar/adhoc/testcombined/PnfTestCombined.g4",
        "org/perses/grammar/adhoc/testcombined/TestCombinedAdhocParserFacade.class",
        "org/perses/grammar/adhoc/testcombined/TestCombinedAdhocParserFacade.java",
      )
    }
  }

  @Test
  fun testAdHocInstallerWithExistingLanguageKind() {
    val testPersesConstants = PersesConstants.createCustomizedConstants(workingDir)
    val testOptions = CommandOptions()
    testOptions.compulsoryFlags.parserGrammar = combinedGrammarPath
    testOptions.compulsoryFlags.lexerGrammar = null
    testOptions.compulsoryFlags.startRuleName = "start"
    testOptions.compulsoryFlags.existingLanguageKindClassFullName =
      LanguageAdhoc::class.java.canonicalName
    testOptions.compulsoryFlags.tokenNamesOfIdentifiers = listOf("ID")

    testOptions.validate()
    val installer = AdhocGrammarInstaller(
      testOptions.computeAdhocGrammarConfiguration(),
      testPersesConstants,
      testOptions.outputFlags.output,
      enablePnfNormalization = true,
    )
    val generatedJar = installer.run()
    val facade = generatedJar.loadMainClass().getConstructor().newInstance() as AbstractParserFacade
    val langauge = facade.language
    assertThat(langauge).isSameInstanceAs(LanguageAdhoc.INSTANCE)
  }

  @Test
  fun testAdHocInstallerWithNullFormatter() {
    val nonFormmatterConfiguration = """---
      name: "test"
      extensions:
      - "cp"
      - "c"
      defaultCodeFormatControl: "ORIG_FORMAT"
      origCodeFormatControl: "ORIG_FORMAT"
      allowedCodeFormatControl:
      - "ORIG_FORMAT"
      - "COMPACT_ORIG_FORMAT"
    """

    val resultConfiguration = """---
      name: "test"
      extensions:
      - "cp"
      - "c"
      defaultCodeFormatControl: "ORIG_FORMAT"
      origCodeFormatControl: "ORIG_FORMAT"
      allowedCodeFormatControl:
      - "ORIG_FORMAT"
      - "COMPACT_ORIG_FORMAT"
      defaultFormatterCommands: []
    """

    val languageKindNonFormmatterFile = tempDir.resolve("language_kind_adhoc_non_format.yaml")
      .apply {
        writeText(nonFormmatterConfiguration)
      }

    val testPersesConstants = PersesConstants.createCustomizedConstants(workingDir)
    val testOptions = CommandOptions()
    testOptions.compulsoryFlags.parserGrammar = parserGrammarPath
    testOptions.compulsoryFlags.lexerGrammar = lexerGrammarPath
    testOptions.compulsoryFlags.startRuleName = "start"
    testOptions.compulsoryFlags.languageKindYamlFile = languageKindNonFormmatterFile
    testOptions.compulsoryFlags.tokenNamesOfIdentifiers = listOf("ID")
    testOptions.validate()

    val installer = AdhocGrammarInstaller(
      testOptions.computeAdhocGrammarConfiguration(),
      testPersesConstants,
      testOptions.outputFlags.output,
      enablePnfNormalization = true,
    )
    val generatedJar = installer.run()
    assertThat(generatedJar.path.toString()).isEqualTo(
      workingDir.resolve(
        ".perses/installed_adhoc_languages/TestParser/" +
          testOptions.compulsoryFlags.createAdhocGrammarConfiguration().computeContentHashCode() +
          "/perses_adhoc_language_support.jar",
      ).toString(),
    )
    assertThat(generatedJar.mainClassFullName).isEqualTo(
      "org.perses.grammar.adhoc.testparser.TestParserAdhocParserFacade",
    )

    val facade = generatedJar.loadMainClass().getConstructor().newInstance() as AbstractParserFacade
    val langauge = facade.language
    assertThat(langauge).isEqualTo(SerializableLanguageKind.fromYamlString(resultConfiguration))
  }
}
