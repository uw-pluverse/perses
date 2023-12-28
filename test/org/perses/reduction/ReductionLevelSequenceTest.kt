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
package org.perses.reduction

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.IReductionLevelSequence.ContinuousLevelSequence
import org.perses.reduction.IReductionLevelSequence.FixedLevelSequence

@RunWith(JUnit4::class)
class ReductionLevelSequenceTest {
  @Test
  fun testFixedLevelSequenceEmptyAndNocontinous() {
    val seq: IReductionLevelSequence = FixedLevelSequence(ImmutableList.of(), false)
    Assert.assertFalse(seq.hasNext())
    Assert.assertThrows(Throwable::class.java) {
      seq.nextLevel()
    }
  }

  @Test
  fun testFixedLevelSequenceNonemptyAndNoContinuous() {
    val seq: IReductionLevelSequence = FixedLevelSequence(ImmutableList.of(1), false)
    Assert.assertTrue(seq.hasNext())
    assertThat(seq.nextLevel()).isEqualTo(1)
    Assert.assertFalse(seq.hasNext())
    Assert.assertThrows(Throwable::class.java) {
      seq.nextLevel()
    }
  }

  @Test
  fun testFixedLevelSequenceEmptyAndContinous() {
    val seq: IReductionLevelSequence = FixedLevelSequence(ImmutableList.of(), true)
    Assert.assertTrue(seq.hasNext())
    assertThat(seq.nextLevel()).isEqualTo(1)
    Assert.assertTrue(seq.hasNext())
    assertThat(seq.nextLevel()).isEqualTo(2)
    Assert.assertTrue(seq.hasNext())
    assertThat(seq.nextLevel()).isEqualTo(3)
    Assert.assertTrue(seq.hasNext())
    assertThat(seq.nextLevel()).isEqualTo(4)
  }

  @Test
  fun testContinuousLevelSequence() {
    val seq: IReductionLevelSequence = ContinuousLevelSequence()
    Assert.assertTrue(seq.hasNext())
    assertThat(seq.nextLevel()).isEqualTo(1)
    Assert.assertTrue(seq.hasNext())
    assertThat(seq.nextLevel()).isEqualTo(2)
    Assert.assertTrue(seq.hasNext())
    assertThat(seq.nextLevel()).isEqualTo(3)
    Assert.assertTrue(seq.hasNext())
    assertThat(seq.nextLevel()).isEqualTo(4)
    Assert.assertTrue(seq.hasNext())
  }
}
