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
package org.perses.reduction.event

import org.perses.program.ProgramSize
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.spartree.AbstractSparTreeEdit

class BestProgramUpdateEvent(
  val currentFixpointIteration: FixpointIterationStartEvent,
  currentTimeMillis: Long,
  perFileSizeMetrics: PerFileSizeMetrics,
  val programSizeBefore: ProgramSize<*>,
  val programSizeAfter: ProgramSize<*>,
  val appliedEdit: AbstractSparTreeEdit<*>,
) : AbstractReductionEventWithProgramSize(currentTimeMillis, perFileSizeMetrics) {
  init {
    // FIXME(cnsun): this also needs to check the num of chars of tokens in the case of ==.
    //   FIXME(cnsun): fix this assertion
    //   check(programSizeBefore >= programSizeAfter)
  }

  override fun initialPerFileSizeMetrics(): PerFileSizeMetrics =
    currentFixpointIteration.initialPerFileSizeMetrics()

  override val prefixLabelFromRootToHere: String
    get() = currentFixpointIteration.prefixLabelFromRootToHere
}
