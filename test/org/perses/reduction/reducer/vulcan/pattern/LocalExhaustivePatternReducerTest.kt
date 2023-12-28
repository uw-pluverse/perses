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
package org.perses.reduction.reducer.vulcan.pattern

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.reduction.reducer.vulcan.pattern.EnumOperation.DELETE
import org.perses.reduction.reducer.vulcan.pattern.EnumOperation.KEEP
import org.perses.reduction.reducer.vulcan.pattern.NumOfDeletesToPatterns.Companion.createDeletionPatterns
import org.perses.reduction.reducer.vulcan.pattern.NumOfDeletesToPatterns.Companion.createOperationListWithGivenNumOfDeletes
import org.perses.reduction.reducer.vulcan.pattern.NumOfDeletesToPatterns.Companion.createPatternsWithGivenNumOfDeletes

@RunWith(JUnit4::class)
class LocalExhaustivePatternReducerTest {

  @Test
  fun testGetDeletionPatterns() {
    LocalExhaustivePatternReducer.getDeletionPatterns(
      patternLength = 4,
    ).let {
      assertThat(it.patternCount).isEqualTo(16)
    }
    LocalExhaustivePatternReducer.getDeletionPatterns(
      patternLength = 5,
    ).let {
      assertThat(it.patternCount).isEqualTo(32)
    }
  }

  @Test
  fun testPatternSet_total_1() {
    val patternSet = createDeletionPatterns(totalNumberOfOperations = 1)
    assertThat(patternSet.patternCount).isEqualTo(2)
    assertThat(patternSet.patternLength).isEqualTo(1)

    patternSet.getPatternsWithGivenNumOfDeletes(numOfDeletes = 0).let {
      assertThat(it).hasSize(1)
      assertThat(it.single().numOfKeeps).isEqualTo(1)
      assertThat(it.single().numOfDeletes).isEqualTo(0)
    }

    patternSet.getPatternsWithGivenNumOfDeletes(numOfDeletes = 1).let {
      assertThat(it).hasSize(1)
      assertThat(it.single().numOfDeletes).isEqualTo(1)
      assertThat(it.single().numOfKeeps).isEqualTo(0)
    }
  }

  @Test
  fun testPatternSet_total_2() {
    val patternSet = createDeletionPatterns(totalNumberOfOperations = 2)
    assertThat(patternSet.patternCount).isEqualTo(4)
    assertThat(patternSet.patternLength).isEqualTo(2)

    patternSet.getPatternsWithGivenNumOfDeletes(numOfDeletes = 0).let {
      assertThat(it).hasSize(1)
      assertThat(it.single().numOfDeletes).isEqualTo(0)
      assertThat(it.single().numOfKeeps).isEqualTo(2)
    }
    patternSet.getPatternsWithGivenNumOfDeletes(numOfDeletes = 1).let {
      assertThat(it).hasSize(2)

      assertThat(it.first().numOfDeletes).isEqualTo(1)
      assertThat(it.first().numOfKeeps).isEqualTo(1)

      assertThat(it.last().numOfKeeps).isEqualTo(1)
      assertThat(it.last().numOfDeletes).isEqualTo(1)
    }
    patternSet.getPatternsWithGivenNumOfDeletes(numOfDeletes = 2).let {
      assertThat(it).hasSize(1)
      assertThat(it.single().numOfDeletes).isEqualTo(2)
      assertThat(it.single().numOfKeeps).isEqualTo(0)
    }
  }

  @Test
  fun testPattern() {
    val pattern = TokenEditPattern(ImmutableList.of(KEEP, DELETE))
    assertThat(pattern.patternLength).isEqualTo(2)
    assertThat(pattern.numOfDeletes).isEqualTo(1)
    assertThat(pattern.numOfKeeps).isEqualTo(1)
  }

  @Test
  fun testCreatePatternsWithGivenNumOfDeletes_total_2_deletes_1() {
    val patterns = createPatternsWithGivenNumOfDeletes(
      totalNumberOfOperations = 2,
      numOfDeletes = 1,
    )
    assertThat(patterns).hasSize(2)
    assertThat(patterns[0].operations).containsExactly(
      KEEP,
      DELETE,
    ).inOrder()
    assertThat(patterns[1].operations).containsExactly(
      DELETE,
      KEEP,
    )
  }

  @Test
  fun testCreatePatternsWithGivenNumOfDeletes_total_3_deletes_2() {
    val patterns = createPatternsWithGivenNumOfDeletes(
      totalNumberOfOperations = 3,
      numOfDeletes = 2,
    )
    assertThat(patterns).hasSize(3)
    assertThat(patterns[0].operations).containsExactly(
      KEEP,
      DELETE,
      DELETE,
    ).inOrder()
    assertThat(patterns[1].operations).containsExactly(
      DELETE,
      KEEP,
      DELETE,
    ).inOrder()
    assertThat(patterns[2].operations).containsExactly(
      DELETE,
      DELETE,
      KEEP,
    )
  }

  @Test
  fun testCreateOperationListWithGivenNumOfDeletes_empty() {
    val list = createOperationListWithGivenNumOfDeletes(
      totalNumberOfOperations = 0,
      numOfDeletes = 0,
    )
    assertThat(list).isEmpty()
  }

  @Test
  fun testCreateOperationListWithGivenNumOfDeletes_one() {
    createOperationListWithGivenNumOfDeletes(
      totalNumberOfOperations = 1,
      numOfDeletes = 0,
    ).let {
      assertThat(it).containsExactly(KEEP).inOrder()
    }

    createOperationListWithGivenNumOfDeletes(
      totalNumberOfOperations = 1,
      numOfDeletes = 1,
    ).let {
      assertThat(it).containsExactly(DELETE).inOrder()
    }
  }

  @Test
  fun testCreateOperationListWithGivenNumOfDeletes_two() {
    createOperationListWithGivenNumOfDeletes(
      totalNumberOfOperations = 2,
      numOfDeletes = 0,
    ).let {
      assertThat(it).containsExactly(KEEP, KEEP)
    }
    createOperationListWithGivenNumOfDeletes(
      totalNumberOfOperations = 2,
      numOfDeletes = 1,
    ).let {
      assertThat(it).containsExactly(KEEP, DELETE)
    }
    createOperationListWithGivenNumOfDeletes(
      totalNumberOfOperations = 2,
      numOfDeletes = 2,
    ).let {
      assertThat(it).containsExactly(DELETE, DELETE)
    }
  }

  @Test
  fun testComputeCandidateNodeSequencesToSlideThrough() {
    val tree = TestUtility.createSparTreeFromString(
      sourceCode = "int main() { return 0; }",
      LanguageC,
    )
    val granularity = 4
    val nodeSequences = LocalExhaustivePatternReducer.computeSequenceOfCandidateNodesToSlideThrough(
      tree,
      granularity,
    )
    assertThat(nodeSequences.first().size).isAtLeast(granularity)
    assertThat(nodeSequences.last().size).isEqualTo(tree.tokenCount)
    nodeSequences.zipWithNext { first, second ->
      assertThat(first.any { !it.isTokenNode })
      assertThat(first.size).isLessThan(second.size)
    }
    val firstLevel = nodeSequences.first()
    firstLevel.filter { !it.isTokenNode }
      .forEach { it.delete() }
    assertThat(nodeSequences.count()).isEqualTo(1)
  }
}
