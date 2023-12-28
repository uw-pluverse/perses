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
package org.perses.spartree

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.antlr.ast.PersesPlusAst
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.grammar.c.LanguageC
import org.perses.program.printer.PrinterRegistry
import org.perses.spartree.AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy
import java.nio.file.Paths

@RunWith(JUnit4::class)
class SparTreeTest {

  private val tree = TestUtility.createSparTreeFromFile(
    Paths.get("test_data/parentheses/t.c"),
  )

  private val nodeToTokensMap = TestUtility.createNodeToTokensMap(tree)

  @Test
  fun test_getRemainingLexerRuleNodes() {
    val tree = TestUtility.createSparTreeFromString(
      """
      int c;
      """.trimIndent(),
      LanguageC,
    )
    tree.remainingLexerRuleNodes
      .asSequence()
      .map { it.token.text }
      .joinToString(separator = " ")
      .let {
        assertThat(it).contains("int c ;")
      }
  }

  @Test
  fun testChildExpectedTypeShouldMatchKleeneElementType() {
    val tree = TestUtility.createSparTreeFromString(
      """
        int a;
        int b;
      """.trimIndent(),
      LanguageC,
    )
    tree.printTreeStructureToStdout()
    print('\n')
    val (firstInt, secondInt) = tree.getTokenNodeForText("int")
    val (firstSemicolon, secondSemicolon) = tree.getTokenNodeForText(";")
    val tokenA = tree.getTokenNodeForText("a").single()
    val tokenB = tree.getTokenNodeForText("b").single()
    val firstDecl = AbstractTreeNode.findLowestAncestor(
      firstInt,
      firstSemicolon,
      tokenA,
    )
    val secondDecl = AbstractTreeNode.findLowestAncestor(
      secondInt,
      secondSemicolon,
      tokenB,
    )
    assertThat(
      firstDecl.payload!!.expectedAntlrRuleType!!,
    ).isEqualTo(
      secondDecl.payload!!.expectedAntlrRuleType!!,
    )
    val kleene = AbstractTreeNode.findLowestAncestor(firstDecl, secondDecl)
    val kleeneRuleDef = kleene.antlrRule!!.ruleDef.body
    assertThat(kleeneRuleDef).isInstanceOf(PersesPlusAst::class.java)
    val kleeneElementType = tree.grammarHierarchy.getRuleHierarchyEntryWithNameOrThrow(
      (kleeneRuleDef.getChild(0) as PersesRuleReferenceAst).ruleNameHandle.ruleName,
    )
    assertThat(
      firstDecl.payload!!.expectedAntlrRuleType!!,
    ).isEqualTo(kleeneElementType)
  }

  @Test
  fun testChildHoisting() {
    val node1Key = ImmutableList.of(
      "{",
      "{",
      "{",
      "{",
      "{",
      "printf",
      "(",
      "(",
      "\"hello world\\n\"",
      ")",
      ")",
      ";",
      "}",
      "}",
      "}",
      "}",
      "}",
    )
    val node1 = nodeToTokensMap.getNode(node1Key, "compoundStatement")
    val node2Key = ImmutableList.of(
      "{", "printf", "(", "(", "\"hello world\\n\"", ")", ")", ";", "}",
    )
    val node2 = nodeToTokensMap.getNode(node2Key, "compoundStatement")
    val edit = tree.createNodeReplacementEdit(
      ChildHoistingActionSet.createByReplacingSingleNode(
        node1,
        node2,
        "[test]replacement",
      ),
    )
    val programByEdit = edit.program
    assertThat(
      PrinterRegistry.printToStringInOrigFormat(programByEdit).replace("\\s+".toRegex(), ""),
    )
      .isEqualTo("intmain(){printf((\"helloworld\\n\"));}")
    tree.applyEdit(edit)
    val programByTree = tree.programSnapshot
    assertThat(programByEdit.tokens)
      .containsExactlyElementsIn(programByTree.tokens)
      .inOrder()
  }

  @Test
  fun testAnyNodeReplacement() {
    val node1Key = ImmutableList.of(
      "{",
      "{",
      "{",
      "{",
      "{",
      "printf",
      "(",
      "(",
      "\"hello world\\n\"",
      ")",
      ")",
      ";",
      "}",
      "}",
      "}",
      "}",
      "}",
    )

    val expectedInput =
      """
        int main(){
          printf(("hello world\n"));
        }
      """.trimIndent().replace(System.lineSeparator(), "").replace(" ", "")

    val node1 = nodeToTokensMap.getNode(node1Key, "compoundStatement")
    val node2Key = ImmutableList.of(
      "{", "printf", "(", "(", "\"hello world\\n\"", ")", ")", ";", "}",
    )
    val node2 = nodeToTokensMap.getNode(node2Key, "compoundStatement")

    val replacingNode = node2.recursiveDeepCopy(ReuseNodeIdStrategy)

    // remove inputNode out of the tree
    val builder = NodeDeletionActionSet.Builder("edit 1")
    builder.deleteNode(node2)
    val actionSet = builder.build()
    val edit1 = tree.createNodeDeletionEdit(actionSet)
    tree.applyEdit(edit1)

    val edit = tree.createAnyNodeReplacementEdit(
      ChildHoistingActionSet.createByReplacingSingleNode(
        node1,
        replacingNode,
        "[test]replacement",
      ),
    )
    val programByEdit = edit.program
    assertThat(
      PrinterRegistry.printToStringInOrigFormat(programByEdit).replace("\\s+".toRegex(), ""),
    ).isEqualTo(expectedInput)
    tree.applyEdit(edit)
    val programByTree = tree.programSnapshot
    assertThat(programByEdit.tokens)
      .containsExactlyElementsIn(programByTree.tokens)
      .inOrder()
  }

  @Test
  fun testSingleUntypesArgInCFunction() {
    val tree = TestUtility.createSparTreeFromFile(
      Paths.get("test_data/misc/main_with_1_arg.c"),
    )
    tree.printTreeStructureToStdout()
  }
}
