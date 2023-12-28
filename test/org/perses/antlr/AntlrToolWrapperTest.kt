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

import com.google.common.truth.Truth.assertThat
import com.google.common.truth.Truth.assertWithMessage
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.util.AntlrToolWrapper
import org.perses.util.FileNameContentPair
import java.nio.file.Files
import kotlin.io.path.deleteRecursively
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class AntlrToolWrapperTest {

  private val tempDir = Files.createTempDirectory(javaClass.simpleName)!!
  val packageName = "org.perses.test"
  val outputDir = tempDir.resolve(packageName.replace('.', '/'))

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testCombinedGrammar() {
    val parserFile = tempDir.resolve("CombinedGrammar.g4").apply {
      writeText(
        """
        grammar CombinedGrammar;
        start : 'a';
        """.trimIndent(),
      )
    }

    val wrapper = AntlrToolWrapper(
      packageName = packageName,
      parserFile = parserFile,
      lexerFile = null,
      outputDir = outputDir.toString(),
    )
    assertThat(Files.exists(outputDir)).isFalse()
    wrapper.call()
    assertThat(Files.exists(outputDir)).isTrue()
    assertThat(Files.exists(outputDir.resolve("CombinedGrammarParser.java"))).isTrue()
    assertThat(Files.exists(outputDir.resolve("CombinedGrammarLexer.java"))).isTrue()
  }

  @Test
  fun testSeparateGrammar() {
    val parserFile = tempDir.resolve("Parser.g4").apply {
      writeText(
        """
        parser grammar Parser;
        options {
            tokenVocab=Lexer;
        }
        start: ID;
        """.trimIndent(),
      )
    }
    val lexerFile = tempDir.resolve("Lexer.g4").apply {
      writeText(
        """
        lexer grammar Lexer;
        ID: 'a';
        """.trimIndent(),
      )
    }

    val wrapper = AntlrToolWrapper(
      packageName,
      parserFile,
      lexerFile,
      outputDir.toString(),
    )
    assertThat(Files.exists(outputDir)).isFalse()
    wrapper.call()
    assertThat(Files.exists(outputDir)).isTrue()
    assertThat(Files.exists(outputDir.resolve("Parser.java"))).isTrue()
    assertThat(Files.exists(outputDir.resolve("Lexer.java"))).isTrue()
  }

  @Test
  fun testAcceptingCombinedParser_accept() {
    AntlrToolWrapper.doesAntlrAcceptGrammar(
      FileNameContentPair.createFromString(
        fileName = "Test",
        content = """
        grammar Test;
        start:'a';
        """.trimIndent(),
      ),
    ).let {
      assertWithMessage(it.message).that(it.accpeted).isTrue()
    }
  }

  @Test
  fun testAcceptingCombinedParser_reject() {
    AntlrToolWrapper.doesAntlrAcceptGrammar(
      FileNameContentPair.createFromString(
        fileName = "Test",
        content = """
        grammar Test;
        start
        """.trimIndent(),
      ),
    ).let {
      assertWithMessage(it.message).that(it.accpeted).isFalse()
    }
  }

  @Test
  fun testAcceptingSeparateGrammar_accept() {
    AntlrToolWrapper.doesAntlrAcceptGrammar(
      parserGrammar = FileNameContentPair.createFromString(
        fileName = "Parser",
        content = """
          parser grammar Parser;
          options {
              tokenVocab=Lexer;
          }
          start: ID;
        """.trimIndent(),
      ),
      lexerGrammar = FileNameContentPair.createFromString(
        fileName = "Lexer",
        content = """
          lexer grammar Lexer;
          ID: 'a';
        """.trimIndent(),
      ),
    ).let {
      assertWithMessage(it.message).that(it.accpeted).isTrue()
    }
  }

  @Test
  fun testAcceptingSeparateGrammar_reject() {
    AntlrToolWrapper.doesAntlrAcceptGrammar(
      parserGrammar = FileNameContentPair.createFromString(
        fileName = "Parser",
        content = """
          parser grammar Parser;
          options {
              tokenVocab=Lexer;
          }
          start: ID;
        """.trimIndent(),
      ),
      lexerGrammar = FileNameContentPair.createFromString(
        fileName = "Lexer",
        content = """
          lexer grammar Lexer;
          ID;
        """.trimIndent(),
      ),
    ).let {
      assertWithMessage(it.message).that(it.accpeted).isFalse()
    }
  }
}
