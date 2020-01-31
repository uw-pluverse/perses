/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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

import org.junit.Assert;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.listener.IProfileEvent;

/** Created by neo on 12/17/16. */
@RunWith(JUnit4.class)
public class ProfileTest {

  @Test
  public void testLabelReductionEventToString() {
    final IProfileEvent startEvent = new IProfileEvent.LevelReductionEvent(0, true, 2);
    Assert.assertEquals(
        startEvent.toString().trim(),
        "LevelReductionEvent\t[Start"
            + "]\ttime="
            + startEvent.getTimeInMilliseconds()
            + "\ttokenCount=0\tlevel=2");

    final IProfileEvent endEvent = new IProfileEvent.LevelReductionEvent(0, false, 3);
    Assert.assertEquals(
        endEvent.toString().trim(),
        "LevelReductionEvent\t"
            + "[End]\ttime="
            + endEvent.getTimeInMilliseconds()
            + "\ttokenCount=0\tlevel=3");
  }

  @Test
  public void testGranularityEvent() {
    final IProfileEvent startEvent = new IProfileEvent.GranularityEvent(1, true, 3);
    Assert.assertEquals(
        startEvent.toString().trim(),
        "GranularityEvent\t"
            + "[Start]\ttime="
            + startEvent.getTimeInMilliseconds()
            + "\ttokenCount=1\tgranularity=3");

    final IProfileEvent endEvent = new IProfileEvent.GranularityEvent(1, false, 3);
    Assert.assertEquals(
        endEvent.toString().trim(),
        "GranularityEvent\t[End"
            + "]\ttime="
            + endEvent.getTimeInMilliseconds()
            + "\ttokenCount=1\tgranularity=3");
  }

  @Test
  public void testFixpointIterationEvent() {
    IProfileEvent start = new IProfileEvent.FixpointIterationEvent(1, true);
    Assert.assertEquals(
        "FixpointIterationEvent\t[Start]\ttime=" + start.getTimeInMilliseconds() + "\ttokenCount=1",
        start.toString().trim());

    IProfileEvent end = new IProfileEvent.FixpointIterationEvent(2, false);
    Assert.assertEquals(
        "FixpointIterationEvent\t[End]\ttime=" + end.getTimeInMilliseconds() + "\ttokenCount=2",
        end.toString().trim());
  }
}
