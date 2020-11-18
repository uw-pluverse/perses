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
package org.perses.reduction.reducer

import org.perses.reduction.FutureExecutionResultInfo
import org.perses.tree.spar.SparTree

abstract class AbstractSlicingTask(val tree: SparTree) {

  protected var futureResult: FutureExecutionResultInfo? = null

  abstract fun tryAsyncRun(): Boolean

  fun cancel() {
    if (futureResult != null) {
      futureResult!!.cancel()
      futureResult = null
    }
  }

  abstract fun waitAndApplyEditIfSuccess(): Boolean
}
