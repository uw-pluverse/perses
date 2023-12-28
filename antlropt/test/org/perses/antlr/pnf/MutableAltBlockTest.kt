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

import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.ast.PersesRuleReferenceAst

@RunWith(JUnit4::class)
class MutableAltBlockTest : AbstractMutableGrammarTest() {

  val block = MutableAltBlock()

  @Test
  fun test_isEmpty() {
    assertThat(block.isEmpty).isTrue()
    assertThat(block.isNotEmpty).isFalse()
    assertThat(block.size()).isEqualTo(0)
  }

  @Test
  fun test_addIfNotEquivalent() {
    assertThat(block.addIfNotEquivalent(refA)).isTrue()
    assertThat(block.size()).isEqualTo(1)
    assertThat(block.asSequence().toList()).containsExactly(refA)
    assertThat(block.asIterable().toList()).containsExactly(refA)
    assertThat(block[0]).isSameInstanceAs(refA)

    assertThat(block.addIfNotEquivalent(refA)).isFalse()
    assertThat(block.size()).isEqualTo(1)
    assertThat(block.isEmpty).isFalse()
    assertThat(block.isNotEmpty).isTrue()

    assertThat(block.addIfNotEquivalent(refB)).isTrue()
    assertThat(block.size()).isEqualTo(2)
    assertThat(block[1]).isSameInstanceAs(refB)
  }

  @Test
  fun testReplace_throw() {
    val block = MutableAltBlock()
    block.addIfNotEquivalent(refA)
    Assert.assertThrows(Exception::class.java) {
      block.replace(refA, refA)
    }

    Assert.assertThrows(Exception::class.java) {
      block.replace(refA, PersesRuleReferenceAst.create(refA.ruleNameHandle))
    }

    block.addIfNotEquivalent(refB)
    Assert.assertThrows(Exception::class.java) {
      block.replace(refA, refB)
    }
  }

  @Test
  fun testReplace() {
    val block = MutableAltBlock()
    block.addIfNotEquivalent(refA)
    block.addIfNotEquivalent(refB)
    block.addIfNotEquivalent(refC)

    assertThat(block.asIterable()).containsExactly(
      refA,
      refB,
      refC,
    ).inOrder()

    block.replace(refB, refD)
    assertThat(block.asIterable()).containsExactly(
      refA,
      refD,
      refC,
    ).inOrder()
  }
}
