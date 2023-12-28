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

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.program.printer.PrinterRegistry
import org.perses.spartree.AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy
import org.perses.util.SimpleStack

@RunWith(JUnit4::class)
class SparTreeCopierTest {

  val original = TestUtility.createSparTreeFromString(
    """
      int a = b;
      int c = d;
    """.trimIndent(),
    LanguageC,
  )

  val copy = original.deepCopy(ReuseNodeIdStrategy)

  @Test
  fun testOutputtingProgramInOrigFormat() {
    val origProgram = PrinterRegistry.printToStringInOrigFormat(original.programSnapshot)
    val copyProgram = PrinterRegistry.printToStringInOrigFormat(copy.programSnapshot)
    assertThat(origProgram).isEqualTo(copyProgram)
  }

  @Test
  fun testDeepCopyWithSparTreeNodeFactoryAsNodeIdCopyStrategy() {
    val anotherCopy = original.deepCopy(original.sparTreeNodeFactory)
    val stack = SimpleStack.of(Pair(copy.root, anotherCopy.root))
    while (stack.isNotEmpty()) {
      val (a, b) = stack.remove()
      assertThat(a::class.java).isSameInstanceAs(b::class.java)
      if (a is LexerRuleSparTreeNode && b is LexerRuleSparTreeNode) {
        assertThat(a.token.text).isEqualTo(b.token.text)
      }
      assertThat(a.nodeId).isNotEqualTo(b.nodeId)
      assertThat(a.antlrRule).isSameInstanceAs(b.antlrRule)
      assertThat(a.childCount).isEqualTo(b.childCount)
      val childCount = a.childCount
      (0 until childCount).forEach {
        stack.add(Pair(a.getChild(it), b.getChild(it)))
      }
    }
  }

  @Test
  fun testVisitRemainingTokens() {
    val originalTokens = original.leafNodeSequence()
      .map { it.token.text }.toList()
    val copyTokens = copy.leafNodeSequence()
      .map { it.token.text }.toList()

    assertThat(originalTokens).isEqualTo(copyTokens)
  }

  @Test
  fun testObjectIdentitiesShouldBeDifferent() {
    assertThat(original).isNotSameInstanceAs(copy)
    val originalNodes = ArrayList<AbstractSparTreeNode>()
    original.root.preOrderVisit {
      originalNodes.add(it)
      it.immutableChildView
    }

    val copyNodes = ArrayList<AbstractSparTreeNode>()
    copy.root.preOrderVisit {
      copyNodes.add(it)
      it.immutableChildView
    }
    assertThat(originalNodes.size).isEqualTo(copyNodes.size)
    originalNodes.asSequence().zip(copyNodes.asSequence()).forEach {
      assertThat(it.first.antlrRule).isSameInstanceAs(it.second.antlrRule)
      assertThat(it.first.isQuantifierNode).isEqualTo(it.second.isQuantifierNode)
      assertThat(it.first.isTokenNode).isEqualTo(it.second.isTokenNode)
      assertThat(it.first::class).isEqualTo(it.second::class)
      if (it.first is ParserRuleSparTreeNode) {
        check(it.second is ParserRuleSparTreeNode)
        assertThat(
          (it.first as ParserRuleSparTreeNode).ruleType,
        ).isEqualTo((it.second as ParserRuleSparTreeNode).ruleType)
      }
      assertThat(it.first.ruleName).isEqualTo(it.second.ruleName)
      assertThat(it.first.childCount).isEqualTo(it.second.childCount)
    }
  }

  @Test
  fun testPrintTreeStructureShouldBeTheSame() {
    val origString = original.printTreeStructure()
      .split('\n').map { it.trimEnd() }
    val copyString = copy.printTreeStructure()
      .split('\n').map { it.trimEnd() }
    assertThat(origString.size).isEqualTo(copyString.size)
    origString.asSequence().zip(copyString.asSequence()).forEach {
      assertThat(it.first).isEqualTo(it.second)
    }
  }
}
