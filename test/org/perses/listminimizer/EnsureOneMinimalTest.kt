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

@RunWith(JUnit4::class)
class EnsureOneMinimalTest : AbstractListMinimizerTest<String>() {
  private class OnlyEnsureOneMinimal(
    arguments: ListMinimizerArguments<String, String>,
  ) : AbstractListMinimizer<String, String>(arguments) {
    override fun reduceNonEmptyInput() {
      ensureOneMinimal()
    }
  }

  private fun test(
    property: List<String>,
    expected: List<String>,
  ): List<String> =
    runMinimizerTest(
      input = ImmutableList.of("a", "b", "c", "d", "e", "f", "g", "h"),
      property = property,
      expected = expected,
    ) {
      OnlyEnsureOneMinimal(it)
    }

  @Test
  fun testContinuesPastADeletionAndWrapsAround() {
    assertThat(test(property = listOf("a", "e"), expected = listOf("a", "e")))
      .containsExactly(
        "",
        "bcdefgh",
        "acdefgh",
        "adefgh",
        "aefgh",
        "afgh",
        "aegh",
        "aeh",
        "ae",
        // a is not retested after each deletion, only once the scan wraps around.
        "e",
        "a",
      ).inOrder()
  }

  @Test
  fun testDoesNotRetestTheEmptyList() {
    assertThat(test(property = listOf("h"), expected = listOf("h")))
      .containsExactly("", "bcdefgh", "cdefgh", "defgh", "efgh", "fgh", "gh", "h")
      .inOrder()
  }
}
