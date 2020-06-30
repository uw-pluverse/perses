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

package org.perses.listener;

import org.perses.PersesRuntimeException;
import org.perses.reduction.AbstractReductionEvent;
import org.perses.reduction.AbstractReductionEvent.ReductionStartEvent;
import org.perses.util.TimeSpan;

import java.io.*;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

/** Created by neo on 12/8/16. */
public class ReductionProfileListener extends DefaultReductionListener implements Serializable {

  protected final Map<String, String> comments;

  private TimeSpan.Builder timeSpanBuilder;

  private BufferedWriter textualWriter;

  private ObjectOutputStream eventStream;

  public ReductionProfileListener(final File textualFile) {
    this.comments = new HashMap<>();

    try {
      this.textualWriter = new BufferedWriter(new FileWriter(textualFile));
      this.eventStream =
          new ObjectOutputStream(
              new FileOutputStream(
                  new File(textualFile.getParentFile(), textualFile.getName() + ".event")));
    } catch (IOException e) {
      throw new PersesRuntimeException(e);
    }
  }

  @Override
  public void onReductionStart(ReductionStartEvent event) {
    timeSpanBuilder = TimeSpan.Builder.start(event.getCurrentTimeMillis());
  }

  @Override
  public void onReductionEnd(AbstractReductionEvent.ReductionEndEvent event) {
    final TimeSpan time = timeSpanBuilder.end(event.getCurrentTimeMillis());
    timeSpanBuilder = null;

    try {
      textualWriter.append("\n\n");
      textualWriter
          .append("reduction started at ")
          .append(new Date(time.getStartTimeMillis()).toString())
          .append('\n');
      textualWriter
          .append("          finished at ")
          .append(new Date(time.getEndTimeMillis()).toString())
          .append('\n');
      textualWriter.append("elapsed time is ").append(time.getFormattedElaspedTime()).append('\n');
      textualWriter.append('\n');

      for (Map.Entry<String, String> entry : this.comments.entrySet()) {
        textualWriter
            .append("====================Comment (")
            .append(entry.getKey())
            .append(")====================\n");
        textualWriter.append(entry.getValue());
        textualWriter.append('\n').append('\n');
      }

      this.textualWriter.close();
      this.eventStream.close();
    } catch (IOException e) {
      throw new PersesRuntimeException(e);
    }
  }

  private void saveEvent(IProfileEvent event) {
    try {
      this.textualWriter.append(event.toString()).append('\n');
      this.eventStream.writeObject(event);
    } catch (IOException e) {
      throw new PersesRuntimeException(e);
    }
  }

  @Override
  public void onFixpointIterationStart(AbstractReductionEvent.FixpointIterationStartEvent event) {
    IProfileEvent.FixpointIterationEvent fixpointEvent =
        new IProfileEvent.FixpointIterationEvent(event.getProgramSize(), true);
    this.saveEvent(fixpointEvent);
  }

  @Override
  public void onFixpointIterationEnd(AbstractReductionEvent.FixpointIterationEndEvent event) {
    this.saveEvent(new IProfileEvent.FixpointIterationEvent(event.getProgramSize(), false));
  }

  @Override
  public void onLevelReductionStart(AbstractReductionEvent.LevelReductionStartEvent event) {
    this.saveEvent(
        new IProfileEvent.LevelReductionEvent(event.getProgramSize(), true, event.getLevel()));
  }

  @Override
  public void onLevelReductionEnd(AbstractReductionEvent.LevelReductionEndEvent event) {
    this.saveEvent(
        new IProfileEvent.LevelReductionEvent(event.getProgramSize(), false, event.getLevel()));
  }

  @Override
  public void onLevelGranularityReductionStart(
      AbstractReductionEvent.LevelGranularityReductionStartEvent event) {
    this.saveEvent(
        new IProfileEvent.GranularityEvent(
            event.getProgramSize(), true, event.getMaxNumOfNodesPerPartition()));
  }

  @Override
  public void onLevelGranularityReductionEnd(
      AbstractReductionEvent.LevelGranularityReductionEndEvent event) {
    this.saveEvent(
        new IProfileEvent.GranularityEvent(
            event.getProgramSize(), false, event.getMaxNumOfNodesPerPartition()));
  }

  public void addComment(String name, String comment) {
    this.comments.put(name, comment);
  }

  @Override
  public void onNodeReductionStart(AbstractReductionEvent.NodeReductionStartEvent event) {
    throw new UnsupportedOperationException();
  }

  @Override
  public void onNodeReductionEnd(AbstractReductionEvent.NodeReductionEndEvent event) {
    throw new UnsupportedOperationException();
  }
}
