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
package org.perses.antlr.pnf

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.ast.PersesAlternativeBlockAst

@RunWith(JUnit4::class)
class MutableGrammarTest : AbstractMutableGrammarTest() {

  val grammar = MutableGrammar()

  @Test
  fun testReturnValueOfRemove() {
    assertThat(grammar.removeRule(nameA)).isNull()
    grammar.getAltBlock(nameA)
    assertThat(grammar.removeRule(nameA)).isNull()

    val block = grammar.getAltBlock(nameA)
    block.addIfNotEquivalent(refA)
    assertThat(grammar.removeRule(nameA)).isSameInstanceAs(block)
  }

  @Test
  fun testToImmutableMultiMap() {
    grammar.getAltBlock(nameA).addIfNotEquivalent(refA)
    grammar.getAltBlock(nameA).addIfNotEquivalent(refB)
    grammar.getAltBlock(nameB).addIfNotEquivalent(refA)
    grammar.getAltBlock(nameB).addIfNotEquivalent(refB)
    val map = grammar.toImmutableMultiMap()
    assertThat(map.entries().asSequence().map { it.key }.toList())
      .containsExactly(nameA, nameA, nameB, nameB).inOrder()
    assertThat(map.entries().asSequence().map { it.value }.toList())
      .containsExactly(refA, refB, refA, refB).inOrder()
  }

  @Test
  fun testIsEmpty() {
    assertThat(grammar.isEmpty).isTrue()
    assertThat(grammar.isNotEmpty).isFalse()

    val block = grammar.getAltBlock(nameA)
    assertThat(block.isEmpty).isTrue()
    assertThat(grammar.isEmpty).isTrue()

    block.addIfNotEquivalent(refA)
    assertThat(grammar.isEmpty).isFalse()
    assertThat(grammar.getAltBlock(nameA)).isSameInstanceAs(block)
  }

  @Test
  fun testEmptyAltBlocksShouldBeIgnored() {
    grammar.getAltBlock(nameA)
    grammar.getAltBlock(nameB)

    assertThat(grammar.isEmpty).isTrue()
  }

  @Test
  fun testaddIfInequivalent() {
    assertThat(grammar.getAltBlock(nameA).addIfNotEquivalent(refA)).isTrue()
    assertThat(grammar.nonEmptyAltBlockSequence().asIterable()).hasSize(1)
    assertThat(grammar.getAltBlock(nameA)[0]).isSameInstanceAs(refA)

    assertThat(grammar.getAltBlock(nameA).addIfNotEquivalent(refA)).isFalse()
    assertThat(grammar.nonEmptyAltBlockSequence().asIterable()).hasSize(1)

    assertThat(grammar.getAltBlock(nameB).addIfNotEquivalent(refA)).isTrue()
    assertThat(grammar.nonEmptyAltBlockSequence().asIterable()).hasSize(2)
  }

  @Test
  fun testremoveAlt() {
    grammar.getAltBlock(nameA).addIfNotEquivalent(refA)
    grammar.getAltBlock(nameB).addIfNotEquivalent(refB)

    assertThat(grammar.getAltBlock(nameA).removeAlt(refA)).isTrue()
    assertThat(grammar.getAltBlock(nameA).removeAlt(refB)).isFalse()
    assertThat(grammar.getAltBlock(nameB).removeAlt(refA)).isFalse()
    assertThat(grammar.getAltBlock(nameB).removeAlt(refB)).isTrue()
  }

  @Test
  fun testDecomposeAltBlockAndAddIfDistinct() {
    val blockBottom = PersesAlternativeBlockAst(ImmutableList.of(refA, refB))
    val blockTop = PersesAlternativeBlockAst(ImmutableList.of(blockBottom, refC))
    val nameTop = createName("top")

    MutableGrammar().let { grammar ->
      grammar.getAltBlock(nameTop).decomposeAltBlockAndAddIfInequivalent(blockTop)
      assertThat(grammar.getAltBlock(nameTop)).containsExactly(
        refA,
        refB,
        refC,
      ).inOrder()
    }

    MutableGrammar().let { grammar ->
      grammar.getAltBlock(nameTop).addIfNotEquivalent(refC)
      grammar.getAltBlock(nameTop).decomposeAltBlockAndAddIfInequivalent(blockTop)
      assertThat(grammar.getAltBlock(nameTop)).containsExactly(
        refC,
        refA,
        refB,
      ).inOrder()
    }
  }
}
