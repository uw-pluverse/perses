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
package org.perses.reduction

import org.perses.program.AbstractReductionFile
import org.perses.reduction.io.AbstractReductionIOManager

// Cannot use the full name, e.g., Program, IOManager, or Self due to kotlin's bug.
abstract class AbstractReducerContext<
  P,
  M : AbstractReductionIOManager<P, M>,
  I : AbstractReducerContext<P, M, I>,
>(
  val ioManager: M,
  val executorService: TestScriptExecutorService,
  /** The mutable file this reduction reduces; its reduced content is the program the reducers
   * pass to [AbstractReductionIOManager.createOutputManager]. */
  val fileUnderReduction: AbstractReductionFile<*, *>,
) {
  private val piggybackPayload = HashMap<Any, Any>()

  fun computePiggybackPayloadIfAbsent(
    key: Any,
    valueComputer: (Any) -> Any,
  ): Any = piggybackPayload.computeIfAbsent(key, valueComputer)
}
