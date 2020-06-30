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

package org.perses.util;

import com.google.common.annotations.VisibleForTesting;
import com.google.common.base.Joiner;
import com.google.common.base.MoreObjects;

import java.io.Serializable;
import java.util.ArrayList;

import static com.google.common.base.Preconditions.checkArgument;

/** Representation of a time span. */
public final class TimeSpan implements Serializable {

  private final long startMillis;
  private final long endMillis;

  private TimeSpan(long startMillis, long endMillis) {
    checkArgument(startMillis <= endMillis);
    checkArgument(startMillis > 0);
    checkArgument(endMillis > 0);
    this.startMillis = startMillis;
    this.endMillis = endMillis;
  }

  public long getStartTimeMillis() {
    return startMillis;
  }

  public long getEndTimeMillis() {
    return endMillis;
  }

  public long getElapsedTimeInSeconds() {
    return getElapsedTimeInMillis() / 1000;
  }

  public long getElapsedTimeInMillis() {
    return getEndTimeMillis() - getStartTimeMillis();
  }

  @Override
  public String toString() {
    return MoreObjects.toStringHelper(this)
        .add("startMillis", startMillis)
        .add("endMillis", endMillis)
        .add("formatted", getFormattedElaspedTime())
        .toString();
  }

  public String getFormattedElaspedTime() {
    long time = this.getElapsedTimeInSeconds();
    return formatSeconds(time);
  }

  public static final class Builder {

    private final long startMillis;

    @VisibleForTesting
    Builder(long startMillis) {
      this.startMillis = startMillis;
    }

    public static Builder start(long nowInMillis) {
      return new Builder(nowInMillis);
    }

    public TimeSpan end(long nowInMillis) {
      return createTimeSpan(nowInMillis);
    }

    public long getStartMillis() {
      return startMillis;
    }

    @VisibleForTesting
    TimeSpan createTimeSpan(long endMillis) {
      return new TimeSpan(startMillis, endMillis);
    }
  }

  private static String formatTimeComponent(long value, String component) {
    checkArgument(value > 0);
    if (value == 1) {
      return "1 " + component;
    } else {
      return value + " " + component + "s";
    }
  }

  private static String formatSeconds(long seconds) {
    if (seconds == 1) {
      return "1 second";
    }
    if (seconds <= 60) {
      return seconds + " seconds";
    }
    final StringBuilder builder = new StringBuilder();
    builder.append(seconds).append(" seconds (");

    ArrayList<String> components = new ArrayList<>(/*initialCapacity=*/ 5);

    final long days = seconds / (24 * 3600);
    if (days > 0) {
      components.add(formatTimeComponent(days, "day"));
    }
    seconds %= 24 * 3600;

    final long hours = seconds / 3600;
    if (hours > 0) {
      components.add(formatTimeComponent(hours, "hour"));
    }
    seconds %= 3600;

    final long minutes = seconds / 60;
    if (minutes > 0) {
      components.add(formatTimeComponent(minutes, "minute"));
    }
    seconds %= 60;

    if (seconds > 0) {
      components.add(formatTimeComponent(seconds, "second"));
    }

    builder.append(Joiner.on(' ').join(components));
    builder.append(")");
    return builder.toString();
  }
}
