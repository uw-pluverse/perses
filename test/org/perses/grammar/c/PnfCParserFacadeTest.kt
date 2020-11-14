/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
import com.google.common.io.Files
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.program.LanguageKindTestUtil
import java.io.File

@RunWith(JUnit4::class)
class PnfCParserFacadeTest {

  private val facade = PnfCParserFacade()
  private val workingDir = Files.createTempDir()

  @After
  fun teardown() {
    workingDir.deleteRecursively()
  }

  @Test
  fun testGoldenPnfCGrammar() {
    val content = facade.antlrGrammar.asCombined().grammar.sourceCode
    val golden = File("test/org/perses/grammar/c/golden_pnf_c.g4").readText()
    assertThat(content).isEqualTo(golden)
  }

  @Test
  fun testCodeFormats() {
    LanguageKindTestUtil.assertCodeFormatsDoNotProduceSyntaxticallyInvalidPrograms(
      facade,
      File("test_data/delta_1/t.c")
    )
  }

  @Test
  fun testDefaultFormatterCommand() {
    val tempFile = File(workingDir, "t.c")
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
