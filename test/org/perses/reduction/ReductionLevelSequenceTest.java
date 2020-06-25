/*
 * Copyright (C) 2018-2020 University of Waterloo.
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

package org.perses.reduction;

import com.google.common.collect.ImmutableList;
import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

@RunWith(JUnit4.class)
public class ReductionLevelSequenceTest {

  @Test
  public void testFixedLevelSequenceEmptyAndNocontinous() {
    final IReductionLevelSequence seq =
        new IReductionLevelSequence.FixedLevelSequence(ImmutableList.of(), false);
    Assert.assertFalse(seq.hasNext());
    try {
      seq.nextLevel();
      Assert.fail();
    } catch (Exception e) {
    }
  }

  @Test
  public void testFixedLevelSequenceNonemptyAndNoContinuous() {
    final IReductionLevelSequence seq =
        new IReductionLevelSequence.FixedLevelSequence(ImmutableList.of(1), false);
    Assert.assertTrue(seq.hasNext());
    Assert.assertEquals(1, seq.nextLevel());
    Assert.assertFalse(seq.hasNext());
    try {
      seq.nextLevel();
      Assert.fail();
    } catch (Exception e) {

    }
  }

  @Test
  public void testFixedLevelSequenceEmptyAndContinous() {
    final IReductionLevelSequence seq =
        new IReductionLevelSequence.FixedLevelSequence(ImmutableList.of(), true);
    Assert.assertTrue(seq.hasNext());

    Assert.assertEquals(1, seq.nextLevel());
    Assert.assertTrue(seq.hasNext());
    Assert.assertEquals(2, seq.nextLevel());
    Assert.assertTrue(seq.hasNext());
    Assert.assertEquals(3, seq.nextLevel());
    Assert.assertTrue(seq.hasNext());
    Assert.assertEquals(4, seq.nextLevel());
  }

  @Test
  public void testContinuousLevelSequence() {
    final IReductionLevelSequence seq = new IReductionLevelSequence.ContinuousLevelSequence();
    Assert.assertTrue(seq.hasNext());

    Assert.assertEquals(1, seq.nextLevel());
    Assert.assertTrue(seq.hasNext());
    Assert.assertEquals(2, seq.nextLevel());
    Assert.assertTrue(seq.hasNext());
    Assert.assertEquals(3, seq.nextLevel());
    Assert.assertTrue(seq.hasNext());
    Assert.assertEquals(4, seq.nextLevel());
    Assert.assertTrue(seq.hasNext());
  }
}
