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
package org.perses.antlr

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.reducer.codegen.GrammarMainStubFactory
import org.perses.grammar.adhoc.LanguageAdhoc
import org.perses.grammar.adhoc.ParserFacadeStubFactory
import java.lang.reflect.InvocationTargetException
import java.nio.file.Path
import java.nio.file.Paths
import java.util.zip.ZipFile
import kotlin.io.path.deleteRecursively
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class CompilersTest : AbstractAntlrrdcTest() {

  val workingDir: Path = tempDir.resolve(this::class.simpleName)

  @After
  fun teardown() {
    close()
  }

  override fun close() {
    super.close()
    workingDir.deleteRecursively()
  }

  @Test
  fun testJarfileCanFail() {
    val compiler = AntlrCompiler.createFromFiles(
      parserFile = parserGrammarPath,
      lexerFile = lexerGrammarPath,
      startRuleName = "start",
      workingDirectory = workingDir,
      stubFactory = GrammarMainStubFactory(
        testPrograms = ImmutableList.of(valid1, valid2),
      ),
      packageName = "org.perses.antlr",
      jarFileCustomizer = {},
    )
    val jarFile = compiler.run()
    valid1.writeText("junk")
    valid2.writeText("junk2")
    Assert.assertThrows(InvocationTargetException::class.java) {
      jarFile.expensiveRunMain()
    }
  }

  @Test
  fun testSimpleGrammar() {
    val compiler = AntlrCompiler.createFromFiles(
      parserFile = parserGrammarPath,
      lexerFile = lexerGrammarPath,
      startRuleName = "start",
      workingDirectory = workingDir,
      stubFactory = GrammarMainStubFactory(
        testPrograms = ImmutableList.of(valid1, valid2),
      ),
      packageName = "org.perses.antlr",
      jarFileCustomizer = {},
    )
    val jarFile = compiler.run()

    ZipFile(jarFile.path.toFile()).use { zipFile ->
      val entryNames = zipFile.entries().asSequence().map { it.name }.toList()
      assertThat(entryNames).containsExactly(
        "org/perses/antlr/TestLexer.class",
        "org/perses/antlr/TestLexer.java",
        "org/perses/antlr/TestLexer.g4",
        "org/perses/antlr/TestParser${'$'}StartContext.class",
        "org/perses/antlr/TestParser.class",
        "org/perses/antlr/TestParser.java",
        "org/perses/antlr/TestParser.g4",
        "org/perses/antlr/TestParserMain.class",
        "org/perses/antlr/TestParserMain.java",
      )
    }
    jarFile.expensiveTestParsable(valid1)
    jarFile.expensiveTestParsable(valid2)
    jarFile.expensiveRunMain()
  }

  @Test
  fun testSolidityGrammar() {
    val solidityProgramExample = tempDir.resolve("solidity_hello_world.sol").apply {
      this.writeText(
        """
            contract helloWorld {
             function renderHelloWorld () public pure returns (string) {
               return 'helloWorld';
             }
            }
        """.trimIndent(),
      )
    }
    val compiler = AntlrCompiler.createFromFiles(
      parserFile = Paths.get("src/org/perses/grammar/solidity/Solidity.g4"),
      lexerFile = Paths.get("src/org/perses/grammar/solidity/SolidityLexer.g4"),
      startRuleName = "sourceUnit",
      workingDirectory = workingDir,
      stubFactory = GrammarMainStubFactory(
        testPrograms = ImmutableList.of(solidityProgramExample),
      ),
      packageName = "org.perses.antlr",
      jarFileCustomizer = {},
    )
    val jarFile = compiler.run()
    jarFile.expensiveTestParsable(solidityProgramExample)
    jarFile.expensiveRunMain()
  }

  @Test
  fun testNullLexerFile() {
    val compiler = AntlrCompiler.createFromFiles(
      parserFile = combinedGrammarPath,
      lexerFile = null,
      startRuleName = "start",
      workingDirectory = workingDir,
      stubFactory = GrammarMainStubFactory(
        testPrograms = ImmutableList.of(valid1, valid2),
      ),
      packageName = "org.perses.antlr",
      jarFileCustomizer = {},
    )
    val jarFile = compiler.run()
    jarFile.expensiveTestParsable(valid1)
    jarFile.expensiveTestParsable(valid2)
    jarFile.expensiveRunMain()
  }

  @Test
  fun testGenerateParserFacadeCombined() {
    val compiler = AntlrCompiler.createFromFiles(
      parserFile = combinedGrammarPath,
      lexerFile = null,
      startRuleName = "start",
      workingDirectory = workingDir,
      stubFactory = ParserFacadeStubFactory(
        grammarName = "TestCombined",
        parserFile = combinedGrammarPath,
        lexerFile = null,
        languageKindSetting = ParserFacadeStubFactory.YamlLanguageKindSetting(
          LanguageAdhoc.INSTANCE.toYamlString(),
        ),
        parserFacadeClassSimpleName = "TestCombinedAdhocParserFacade",
        tokenNamesOfIdentifiers = listOf("ID"),
      ),
      packageName = "org.perses.grammar.adhoc",
      jarFileCustomizer = {},
    )
    val jarFile = compiler.run()
    ZipFile(jarFile.path.toFile()).use { zipFile ->
      val entryNames = zipFile.entries().asSequence().map { it.name }.toList()
      assertThat(entryNames).containsExactly(
        "org/perses/grammar/adhoc/TestCombinedAdhocParserFacade.class",
        "org/perses/grammar/adhoc/TestCombinedAdhocParserFacade.java",
        "org/perses/grammar/adhoc/TestCombinedLexer.class",
        "org/perses/grammar/adhoc/TestCombinedLexer.java",
        "org/perses/grammar/adhoc/TestCombinedParser\$StartContext.class",
        "org/perses/grammar/adhoc/TestCombinedParser.class",
        "org/perses/grammar/adhoc/TestCombinedParser.java",
        "org/perses/grammar/adhoc/TestCombined.g4",
      )
    }
  }

  @Test
  fun testGenerateParserFacadeSeperate() {
    val compiler = AntlrCompiler.createFromFiles(
      parserFile = parserGrammarPath,
      lexerFile = lexerGrammarPath,
      startRuleName = "start",
      workingDirectory = workingDir,
      stubFactory = ParserFacadeStubFactory(
        grammarName = "Test",
        parserFile = combinedGrammarPath,
        lexerFile = null,
        languageKindSetting = ParserFacadeStubFactory.YamlLanguageKindSetting(
          LanguageAdhoc.INSTANCE.toYamlString(),
        ),
        parserFacadeClassSimpleName = "TestAdhocParserFacade",
        tokenNamesOfIdentifiers = listOf("ID"),
      ),
      packageName = "org.perses.grammar.adhoc",
      jarFileCustomizer = {},
    )
    val jarFile = compiler.run()
    ZipFile(jarFile.path.toFile()).use { zipFile ->
      val entryNames = zipFile.entries().asSequence().map { it.name }.toList()
      assertThat(entryNames).containsExactly(
        "org/perses/grammar/adhoc/TestAdhocParserFacade.class",
        "org/perses/grammar/adhoc/TestAdhocParserFacade.java",
        "org/perses/grammar/adhoc/TestLexer.class",
        "org/perses/grammar/adhoc/TestLexer.java",
        "org/perses/grammar/adhoc/TestLexer.g4",
        "org/perses/grammar/adhoc/TestParser\$StartContext.class",
        "org/perses/grammar/adhoc/TestParser.class",
        "org/perses/grammar/adhoc/TestParser.java",
        "org/perses/grammar/adhoc/TestParser.g4",
      )
    }
  }
}
