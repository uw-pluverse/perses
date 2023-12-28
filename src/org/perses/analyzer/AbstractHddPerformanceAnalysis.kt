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
package org.perses.analyzer

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.listener.IProfileEvent
import java.io.EOFException
import java.io.ObjectInputStream
import java.nio.file.Files
import java.nio.file.Path

abstract class AbstractHddPerformanceAnalysis protected constructor(protected val eventFile: Path) {
  protected val events: ImmutableList<IProfileEvent> = loadEvents(eventFile)

  fun analyze() {
    performAnalysis()
  }

  protected abstract fun performAnalysis()
  private fun loadEvents(eventFile: Path): ImmutableList<IProfileEvent> {
    logger.atInfo().log("Loading events from %s", eventFile)
    val builder = ImmutableList.builder<IProfileEvent>()
    try {
      ObjectInputStream(Files.newInputStream(eventFile)).use { stream ->
        var event = stream.readObject() as IProfileEvent?
        while (event != null) {
          builder.add(event)
          event = stream.readObject() as IProfileEvent
        }
      }
    } catch (e: EOFException) {
      // Ignore EOF exception.
    }
    return builder.build()
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
