/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.analyzer;

import com.google.common.collect.ImmutableList;
import com.google.common.flogger.FluentLogger;
import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.UncheckedIOException;
import java.nio.file.Files;
import java.nio.file.Path;
import org.perses.listener.IProfileEvent;

public abstract class AbstractHddPerformanceAnalysis {
  private static final FluentLogger logger = FluentLogger.forEnclosingClass();

  protected final ImmutableList<IProfileEvent> events;

  protected final Path eventFile;

  protected AbstractHddPerformanceAnalysis(Path eventFile) {
    this.events = loadEvents(eventFile);
    this.eventFile = eventFile;
  }

  public final void analyze() {
    this.performAnalysis();
  }

  protected abstract void performAnalysis();

  private ImmutableList<IProfileEvent> loadEvents(Path eventFile) {
    logger.atInfo().log("Loading events from %s", eventFile);
    ImmutableList.Builder<IProfileEvent> builder = ImmutableList.builder();
    try (ObjectInputStream stream = new ObjectInputStream(Files.newInputStream(eventFile))) {
      for (IProfileEvent event = ((IProfileEvent) stream.readObject());
          event != null;
          event = ((IProfileEvent) stream.readObject())) {
        builder.add(event);
      }
    } catch (EOFException e) {
    } catch (IOException e) {
      throw new UncheckedIOException(e);
    } catch (ClassNotFoundException e) {
      throw new RuntimeException(e);
    }
    return builder.build();
  }
}
