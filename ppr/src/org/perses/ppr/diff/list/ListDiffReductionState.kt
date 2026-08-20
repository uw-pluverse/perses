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
package org.perses.ppr.diff.list

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.program.AbstractPersesToken
import org.perses.util.AbstractEditOperation
import org.perses.util.ktInfo

class ListDiffReductionState(
  initialDiff: ImmutableList<AbstractEditOperation<AbstractPersesToken>>,
  private val listenerOnUpdate: (ImmutableList<AbstractEditOperation<AbstractPersesToken>>) -> Unit,
) {
  var bestDiff: ImmutableList<AbstractEditOperation<AbstractPersesToken>> = initialDiff
    private set

  fun updateBestDiff(newBestDiff: ImmutableList<AbstractEditOperation<AbstractPersesToken>>) {
    logger.ktInfo { "Found a smaller diff(insert+replace). #ops is ${newBestDiff.size}" }
    bestDiff = newBestDiff
    listenerOnUpdate(newBestDiff)
  }

  init {
    updateBestDiff(bestDiff)
  }

  companion object {
    val logger = FluentLogger.forEnclosingClass()
  }
}
