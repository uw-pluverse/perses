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
package org.perses.reduction.reducer.token

import com.google.common.truth.Truth.assertThat
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.reduction.AbstractReducerFunctionalTest
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTree

@RunWith(JUnit4::class)
class TokenSlicerTest : AbstractReducerFunctionalTest() {

  private var sparTree: SparTree? = null
  private var tokens: List<LexerRuleSparTreeNode>? = null

  @Before
  fun setup() {
    sparTree = TestUtility.createSparTreeFromFile("test_data/delta_1/t.c")
    tokens = sparTree!!.remainingLexerRuleNodes
  }

  @Test
  fun testInvalidSyntaxExitCodeIsNotZero() {
    assertThat(TokenSlicer.INVALID_SYNTAX_EXIT_CODE).isNotEqualTo(0)
  }

  @Test
  fun testExtractLexerRuleNodes() {
    val textTokens = tokens!!.asSequence().map { it.token }.toList()
    assertThat(textTokens)
      .containsExactlyElementsIn(sparTree!!.programSnapshot.tokens).inOrder()
  }

  @Test
  fun testCreateNodeDeletionActionSetReverse_last_element_with_count_eq_1() {
    val actionSet = TokenSlicer.createNodeDeletionActionSetReverse(
      tokens!!,
      inclusiveEndIndex = tokens!!.size - 1,
      tokenCountToDelete = 1,
    )
    assertThat(actionSet.actions).hasSize(1)
    assertThat(actionSet.actions.first().targetNode).isSameInstanceAs(tokens!!.last())
  }

  @Test
  fun testCreateNodeDeletionActionSetReverse_first_element_with_count_eq_1() {
    val actionSet = TokenSlicer.createNodeDeletionActionSetReverse(
      tokens!!,
      inclusiveEndIndex = 0,
      tokenCountToDelete = 1,
    )
    assertThat(actionSet.actions).hasSize(1)
    assertThat(actionSet.actions.first().targetNode).isSameInstanceAs(tokens!!.first())
  }

  @Test
  fun testCreateNodeDeletionActionSetReverse_last_element_with_count_eq_2() {
    val actionSet = TokenSlicer.createNodeDeletionActionSetReverse(
      tokens!!,
      inclusiveEndIndex = tokens!!.size - 1,
      tokenCountToDelete = 2,
    )
    assertThat(actionSet.actions).hasSize(2)
    assertThat(actionSet.actions.first().targetNode).isSameInstanceAs(tokens!!.last())
    assertThat(actionSet.actions.last().targetNode).isSameInstanceAs(tokens!![tokens!!.size - 2])
  }

  @Test
  fun testCreateNodeDeletionActionSetReverse_second_element_with_count_eq_2() {
    val actionSet = TokenSlicer.createNodeDeletionActionSetReverse(
      tokens!!,
      inclusiveEndIndex = 1,
      tokenCountToDelete = 2,
    )
    assertThat(actionSet.actions).hasSize(2)
    assertThat(actionSet.actions.first().targetNode).isSameInstanceAs(tokens!![1])
    assertThat(actionSet.actions.last().targetNode).isSameInstanceAs(tokens!!.first())
  }

  @Test
  fun testReduceDelta1() {
    runCTestSubject(
      "test_data/delta_1",
      TokenSlicer.META,
      """
        |int printf();
        |int main() {
        |  printf("world\n");
        |}
      """.trimMargin(),
    )
  }

  @Test
  fun testReduceScalaHelloWorld() {
    runScalaTestSubject(
      "test_data/scala_helloworld",
      TokenSlicer.META,
      """
      |object Hello {
      | def main(args: Array[String]) =
      |   println("Hello, world")
      |}
      """.trimMargin(),
    )
  }
}
