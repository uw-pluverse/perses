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
package org.perses.util;

import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

/** Test for {@link TimeSpan} */
@RunWith(JUnit4.class)
public class TimeSpanTest {
  @Test
  public void testBuilder() {
    TimeSpan.Builder builder = new TimeSpan.Builder(2000);
    TimeSpan span = builder.createTimeSpan(3000);
    Truth.assertThat(span.getEndTimeMillis()).isEqualTo(3000);
    Truth.assertThat(span.getStartTimeMillis()).isEqualTo(2000);
    Truth.assertThat(span.getElapsedTimeInMillis()).isEqualTo(1000);
    Truth.assertThat(span.getFormattedElaspedTime()).isEqualTo("1 second");
    Truth.assertThat(span.getElapsedTimeInSeconds()).isEqualTo(1);
  }
}
