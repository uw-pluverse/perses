/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.reduction.scheduler

import com.google.common.base.MoreObjects
import org.perses.PersesConstants
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.StatsOfFilesBeingReduced

sealed class AbstractSchedulerEvent {
  val persesUniverseTime = PersesConstants.elapsedTimeSpan()

  final override fun hashCode(): Int = super.hashCode()

  final override fun equals(other: Any?): Boolean = super.equals(other)

  class ReducerCallEvent(
    val reducer: ReducerAnnotation,
    val exceptionStackTrace: String?,
  ) : AbstractSchedulerEvent() {
    override fun toString(): String =
      MoreObjects
        .toStringHelper(this)
        .add(
          "reducer",
          reducer,
        ).also {
          if (exceptionStackTrace != null) {
            it.add("exception", exceptionStackTrace)
          }
        }.toString()
  }

  class StatsSnapshotEvent(
    val stats: StatsOfFilesBeingReduced,
    val numberOfNonDeletionIterations: Int,
    val fileContentChangedWrtPrevious: Boolean,
  ) : AbstractSchedulerEvent()
}
