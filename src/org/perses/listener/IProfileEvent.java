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

package org.perses.listener;

import java.io.Serializable;

public interface IProfileEvent extends Serializable {

  long getTimeInMilliseconds();

  abstract class AbstractProfileEvent implements IProfileEvent {

    private static int EVENT_ID_SEQ;

    private final int eventId;

    private final long timeInMilliseconds;

    private final int programSize;

    private final boolean isStartEvent;

    protected AbstractProfileEvent(int programSize, boolean isStartEvent) {
      this.programSize = programSize;
      this.eventId = EVENT_ID_SEQ++;
      this.timeInMilliseconds = System.currentTimeMillis();
      this.isStartEvent = isStartEvent;
    }

    public boolean isStartEvent() {
      return isStartEvent;
    }

    public int getProgramSize() {
      return programSize;
    }

    public int getEventId() {
      return eventId;
    }

    public final String toString() {
      final StringBuilder builder = new StringBuilder();
      builder.append(this.getClass().getSimpleName()).append('\t');
      builder.append(this.isStartEvent ? "[Start]" : "[End]").append('\t');
      builder.append("time=").append(this.timeInMilliseconds).append('\t');
      builder.append("tokenCount=").append(this.programSize).append('\t');
      this.specificPropertiesToString(builder);
      return builder.toString();
    }

    protected abstract void specificPropertiesToString(StringBuilder builder);

    @Override
    public final long getTimeInMilliseconds() {
      return timeInMilliseconds;
    }
  }

  class FixpointIterationEvent extends AbstractProfileEvent {

    public FixpointIterationEvent(int programSize, boolean isStartEvent) {
      super(programSize, isStartEvent);
    }

    @Override
    protected void specificPropertiesToString(StringBuilder builder) {}
  }

  class LevelReductionEvent extends AbstractProfileEvent {

    private final int level;

    public LevelReductionEvent(int programSize, boolean isStartEvent, int level) {
      super(programSize, isStartEvent);
      this.level = level;
    }

    public int getLevel() {
      return level;
    }

    @Override
    protected void specificPropertiesToString(StringBuilder builder) {
      builder.append("level=").append(this.level).append('\t');
    }
  }

  class GranularityEvent extends AbstractProfileEvent {

    private final int granularity;

    public GranularityEvent(int programSize, boolean isStartEvent, int granularity) {
      super(programSize, isStartEvent);
      this.granularity = granularity;
    }

    public int getGranularity() {
      return granularity;
    }

    @Override
    protected void specificPropertiesToString(StringBuilder builder) {
      builder.append("granularity=").append(this.granularity).append('\t');
    }
  }
}
