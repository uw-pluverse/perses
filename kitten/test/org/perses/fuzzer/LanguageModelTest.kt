/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.fuzzer

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.languagemodel.NDepthTreeModel
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.grammar.c.LanguageC
import java.io.File
import java.nio.file.Files
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class LanguageModelTest {

  private val tempDir = Files.createTempDirectory(javaClass.simpleName)
  private val test =
    """
        int main () {
          return 0;
        }
    """.trimIndent()
  private val anotherTest =
    """
      int main () {
        printf("Hello");
      }
    """.trimIndent()

  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  private val parserFacadeFactory =
    SingleParserFacadeFactory.builderWithBuiltinLanguages().build()

  @Test
  fun testIsInteresting() {
    val nDepthTreeModel = NDepthTreeModel(
      contextSizeLimit = 5,
      parserFacadeFactory.getParserFacadeListForOrNull(LanguageC)!!
        .defaultParserFacade.create(),
      allowToEnableGuidance = true,
    )
    val program1 = File(tempDir.toFile(), "test_1.c")
    val program2 = File(tempDir.toFile(), "test_2.c")
    val parserFacade = SingleParserFacadeFactory
      .builderWithBuiltinLanguages()
      .build()
      .getParserFacadeListForOrNull(LanguageC)!!
      .defaultParserFacade.create()
    program1.writeText(test)
    program2.writeText(anotherTest)
    val tree1 = SparTreeFuzzer
      .fromFile(parserFacade, program1)
      .sparTree
    val tree2 = SparTreeFuzzer
      .fromFile(parserFacade, program2)
      .sparTree
    val feature1 = nDepthTreeModel.updateModelAndGetFeatureOfSparTree(tree1)
    assertThat(nDepthTreeModel.getRarenessOfMostRareFeature(feature1)).isEqualTo(1.0)
    var feature2 = nDepthTreeModel.updateModelAndGetFeatureOfSparTree(tree2)
    assertThat(nDepthTreeModel.getRarenessOfMostRareFeature(feature2)).isEqualTo(1.0)

    nDepthTreeModel.updateModelAndGetFeatureOfSparTree(tree2)
    feature2 = nDepthTreeModel.updateModelAndGetFeatureOfSparTree(tree2)
    assertThat(nDepthTreeModel.getRarenessOfMostRareFeature(feature2)).isEqualTo(1.0 / 3)
  }
}
