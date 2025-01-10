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

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.fuzzer.languagemodel.NodeRepresentation
import org.perses.fuzzer.languagemodel.NodeRepresentationList
import java.io.File
import java.nio.file.Files
import java.nio.file.Paths
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class TreeToSequenceConverterTest {

  private val tempDir = Files.createTempDirectory(javaClass.simpleName)
  private val test =
    """
        int main () {
          return 0;
        }
    """.trimIndent()
  private val rustTest =
    """
      fn main() {
        println!("hello_world");
      }
    """.trimIndent()

  @OptIn(ExperimentalPathApi::class)
  @After
  fun teardown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testSparTreeToSequence() {
    var program = File(tempDir.toFile(), "test.c")
    program.writeText(test)
    var parserFacade = TestUtility.generateAdhocFacade(
      Paths.get("kitten/test/fuzzer_test_data/grammar_for_testing/OrigC.g4"),
      startRule = "compilationUnit",
      tokenNamesOfIdentifiers = listOf("Identifier"),
      workingDir = tempDir,
      enablePnfNormalization = true,
    )
    var treeFuzzer =
      SparTreeFuzzer.fromFile(parserFacade, program)
    var seq = TreeToSequenceConverter.convertWithPreOrder(treeFuzzer.sparTree.root)
    assertThat(seq).isEqualTo(
      ImmutableList.of(
        NodeRepresentation.create(nodeType = 230, featureValue = 0),
        NodeRepresentation.create(nodeType = 342, featureValue = 0),
        NodeRepresentation.create(nodeType = 362, featureValue = 0),
        NodeRepresentation.create(nodeType = 233, featureValue = 0),
        NodeRepresentation.create(nodeType = 163, featureValue = 0),
        NodeRepresentation.create(nodeType = 164, featureValue = 6),
        NodeRepresentation.create(nodeType = 325, featureValue = 0),
        NodeRepresentation.create(nodeType = 322, featureValue = 1),
        NodeRepresentation.create(nodeType = 224, featureValue = 0),
        NodeRepresentation.create(nodeType = 341, featureValue = 0),
        NodeRepresentation.create(nodeType = 361, featureValue = 1),
        NodeRepresentation.create(nodeType = 413, featureValue = 5),
        NodeRepresentation.create(nodeType = 228, featureValue = 2),
        NodeRepresentation.create(nodeType = 226, featureValue = 0),
        NodeRepresentation.create(nodeType = 347, featureValue = 0),
      ).fold(NodeRepresentationList.Builder()) { acc, nodeRepresentation ->
        acc.add(nodeRepresentation)
        acc
      }.build(),
    )
    program = File(tempDir.toFile(), "test.rs")
    program.writeText(rustTest)
    parserFacade = TestUtility.generateAdhocFacade(
      Paths.get("kitten/test/fuzzer_test_data/grammar_for_testing/Rust.g4"),
      startRule = "crate",
      tokenNamesOfIdentifiers = listOf("Ident"),
      workingDir = tempDir,
      enablePnfNormalization = true,
    )
    treeFuzzer =
      SparTreeFuzzer.fromFile(parserFacade, program)
    seq = TreeToSequenceConverter.convertWithPreOrder(treeFuzzer.sparTree.root)
    assertThat(seq).isEqualTo(
      ImmutableList.of(
        NodeRepresentation.create(nodeType = 34, featureValue = 0),
        NodeRepresentation.create(nodeType = 41, featureValue = 0),
        NodeRepresentation.create(nodeType = 42, featureValue = 8),
        NodeRepresentation.create(nodeType = 91, featureValue = 0),
        NodeRepresentation.create(nodeType = 291, featureValue = 0),
        NodeRepresentation.create(nodeType = 294, featureValue = 0),
        NodeRepresentation.create(nodeType = 41, featureValue = 4),
        NodeRepresentation.create(nodeType = 190, featureValue = 0),
        NodeRepresentation.create(nodeType = 379, featureValue = 1),
        NodeRepresentation.create(nodeType = 685, featureValue = 0),
        NodeRepresentation.create(nodeType = 177, featureValue = 0),
        NodeRepresentation.create(nodeType = 100, featureValue = 0),
      ).fold(NodeRepresentationList.Builder()) { acc, nodeRepresentation ->
        acc.add(nodeRepresentation)
        acc
      }.build(),
    )
  }
}
