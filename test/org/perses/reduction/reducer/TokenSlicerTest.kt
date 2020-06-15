package org.perses.reduction.reducer

import com.google.common.truth.Truth.assertThat
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.reduction.AbstractReducerFunctionalTest
import org.perses.tree.spar.LexerRuleSparTreeNode
import org.perses.tree.spar.SparTree

@RunWith(JUnit4::class)
class TokenSlicerTest : AbstractReducerFunctionalTest() {

  private var sparTree: SparTree? = null
  private var tokens: List<LexerRuleSparTreeNode>? = null

  @Before
  fun setup() {
    sparTree = TestUtility.createSparTreeFromFile("test_data/delta_1/t.c")
    tokens = TokenSlicer.extractLexerRuleNodes(sparTree!!)
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
      startIndex = tokens!!.size - 1,
      tokenCountToSlice = 1
    )
    assertThat(actionSet.actions).hasSize(1)
    assertThat(actionSet.actions.first().targetNode).isSameInstanceAs(tokens!!.last())
  }

  @Test
  fun testCreateNodeDeletionActionSetReverse_first_element_with_count_eq_1() {
    val actionSet = TokenSlicer.createNodeDeletionActionSetReverse(
      tokens!!,
      startIndex = 0,
      tokenCountToSlice = 1
    )
    assertThat(actionSet.actions).hasSize(1)
    assertThat(actionSet.actions.first().targetNode).isSameInstanceAs(tokens!!.first())
  }

  @Test
  fun testCreateNodeDeletionActionSetReverse_last_element_with_count_eq_2() {
    val actionSet = TokenSlicer.createNodeDeletionActionSetReverse(
      tokens!!,
      startIndex = tokens!!.size - 1,
      tokenCountToSlice = 2
    )
    assertThat(actionSet.actions).hasSize(2)
    assertThat(actionSet.actions.first().targetNode).isSameInstanceAs(tokens!!.last())
    assertThat(actionSet.actions.last().targetNode).isSameInstanceAs(tokens!![tokens!!.size - 2])
  }

  @Test
  fun testCreateNodeDeletionActionSetReverse_second_element_with_count_eq_2() {
    val actionSet = TokenSlicer.createNodeDeletionActionSetReverse(
      tokens!!,
      startIndex = 1,
      tokenCountToSlice = 2
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
        |int main() {
        |  printf("world\n");
        |}
      """.trimMargin()
    )
  }
}
