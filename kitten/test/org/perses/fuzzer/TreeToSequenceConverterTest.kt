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
package org.perses.fuzzer

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.languagemodel.NodeRepresentation
import org.perses.fuzzer.languagemodel.NodeRepresentationList
import java.io.File
import java.nio.file.Files
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class TreeToSequenceConverterTest {
  private val tempDir = Files.createTempDirectory(javaClass.simpleName)

  // Covers each encoding path once: the top-level Kleene star with several children,
  // collapsed stmt -> assign and stmt -> print chains, a nested block with its own
  // Kleene star, both expr alternatives, and both atom alternatives.
  private val test =
    """
    x = 1;
    {
      print x + y;
    }
    """.trimIndent()

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testSparTreeToSequence() {
    val program = File(tempDir.toFile(), "test.tiny")
    program.writeText(test)
    val treeFuzzer = SparTreeFuzzer.fromFile(TinyGrammarFacade.facade, program)
    val seq = TreeToSequenceConverter.convertWithPreOrder(treeFuzzer.sparTree.realRoot)
    // In pre-order: the top-level Kleene star with two statements, stmt -> assign,
    // expr -> atom for `1`, stmt -> block, the block's single-statement Kleene star,
    // stmt -> print, and expr -> addition for `x + y`. The node types are the ids of
    // kleene_star__program_1 (4), stmt (5), and expr (9) in the normalized grammar.
    assertThat(seq).isEqualTo(
      ImmutableList
        .of(
          NodeRepresentation.create(nodeType = 4, featureValue = 1),
          NodeRepresentation.create(nodeType = 5, featureValue = 0),
          NodeRepresentation.create(nodeType = 9, featureValue = 0),
          NodeRepresentation.create(nodeType = 5, featureValue = 2),
          NodeRepresentation.create(nodeType = 4, featureValue = 0),
          NodeRepresentation.create(nodeType = 5, featureValue = 1),
          NodeRepresentation.create(nodeType = 9, featureValue = 1),
        ).fold(NodeRepresentationList.Builder()) { acc, nodeRepresentation ->
          acc.add(nodeRepresentation)
          acc
        }.build(),
    )
  }
}
