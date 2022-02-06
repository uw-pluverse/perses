/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.grammar.c

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.AntlrGrammarUtil
import org.perses.program.LanguageKindTestUtil
import java.nio.file.Files
import java.nio.file.Paths
import kotlin.io.path.readText
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class PnfCParserFacadeTest {

  private val facade = PnfCParserFacade()
  private val workingDir = Files.createTempDirectory("PnfCParserFacadeTest_")

  @After
  fun teardown() {
    workingDir.toFile().deleteRecursively()
  }

  @Test
  fun testDirective() {
    val content = """
      #include <stdio.h>
      
      int main() {
        printf("hello\n");
        return 0;
      }
    """.trimIndent()
    val tree = facade.parseString(content).tree
    val tokenizedProgram = AntlrGrammarUtil.convertParseTreeToProgram(tree, facade.language).tokens
    assertThat(tokenizedProgram).isNotEmpty()
    assertThat(tokenizedProgram.first().text).isEqualTo("#include <stdio.h>")
  }

  @Test
  fun testCodeFormats() {
    LanguageKindTestUtil.assertCodeFormatsDoNotProduceSyntacticallyInvalidPrograms(
      facade,
      Paths.get("test_data/delta_1/t.c")
    )
  }

  @Test
  fun testDefaultFormatterCommand() {
    val tempFile = workingDir.resolve("t.c")
    val orig = """int
      |main(){
      |return 0;}
    """.trimMargin()
    tempFile.writeText(orig)
    facade.language.getDefaultWorkingFormatter()!!
      .runWith(ImmutableList.of(tempFile.toString()))
    val formatted = tempFile.readText()
    assertThat(orig).isNotEqualTo(formatted)
  }
}
