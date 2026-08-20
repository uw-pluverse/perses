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
package org.perses.reduction.reducer.vulcan.pattern

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC

@RunWith(JUnit4::class)
class LocalExhaustivePatternReducerTest {
  @Test
  fun testComputeCandidateNodeSequencesToSlideThrough() {
    val tree =
      TestUtility.createSparTreeFromString(
        sourceCode = "int main() { return 0; }",
        LanguageC,
      )
    val granularity = 4
    val nodeSequences =
      LocalExhaustivePatternReducer.computeSequenceOfCandidateNodesToSlideThrough(
        tree,
        granularity,
      )
    assertThat(nodeSequences.first().size).isAtLeast(granularity)
    assertThat(nodeSequences.last().size).isEqualTo(tree.programSnapshot.canonicalTokenCount)
    nodeSequences.zipWithNext { first, second ->
      assertThat(first.any { !it.isTokenNode() })
      assertThat(first.size).isLessThan(second.size)
    }
    val firstLevel = nodeSequences.first()
    firstLevel
      .filter { !it.isTokenNode() }
      .forEach { it.delete() }
    assertThat(nodeSequences.count()).isEqualTo(1)
  }
}
