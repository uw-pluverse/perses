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
package org.perses.listminimizer

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import kotlin.random.Random

@RunWith(JUnit4::class)
class PristineDeferredRestartDeltaDebuggerTest : AbstractListMinimizerTest<String>() {
  private val input = ImmutableList.of("a", "b", "c", "d", "e", "f", "g", "h")

  private fun test(
    property: List<String>,
    expected: List<String>,
    input: ImmutableList<String> = this.input,
  ): List<String> =
    runMinimizerTest(input = input, property = property, expected = expected) {
      PristineDeferredRestartDeltaDebugger(it)
    }

  @Test
  fun testBlocksHaveAFixedStride() {
    assertThat(
      test(
        property = listOf("a"),
        expected = listOf("a"),
        input = ImmutableList.of("a", "b", "c", "d", "e", "f", "g"),
      ),
    ).containsExactly(
      "",
      // S = 3 cuts 7 elements into [a b c] [d e f] [g], not [a b c] [d e] [f g].
      "defg",
      "abcg",
      "abc",
      // Single-element sweep #1; sweep #2 has nothing but the whole list to delete.
      "bc",
      "ac",
      "a",
    ).inOrder()
  }

  @Test
  fun testCoarseSweepsDoNotRestart() {
    assertThat(test(property = listOf("a", "e"), expected = listOf("a", "e")))
      .containsExactly(
        "",
        // S = 4
        "efgh",
        "abcd",
        // S = 2
        "cdefgh",
        "abefgh",
        "abgh",
        "abef",
        // Single-element sweep #1 deletes b and f; sweep #2 reaches the fixpoint.
        "bef",
        "aef",
        "af",
        "ae",
        "e",
        "a",
      ).inOrder()
  }

  @Test
  fun testRandomContainmentPropertiesAreMinimizedExactly() {
    val random = Random(20260923)
    repeat(200) {
      val property = input.filter { random.nextInt(4) == 0 }
      test(property = property, expected = property)
    }
  }
}
