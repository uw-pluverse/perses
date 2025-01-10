/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.listminimizer

import org.perses.listminimizer.xfs.BfsDeltaDebugger
import org.perses.listminimizer.xfs.DeltaDebugger
import org.perses.listminimizer.xfs.DfsDeltaDebugger

object ListInputMinimizerFactory {

  fun <T : Any, Payload>create(
    type: EnumListInputMinimizerType,
    args: AbstractListInputMinimizer.Arguments<T, Payload>,
  ): AbstractListInputMinimizer<T, Payload> {
    return when (type) {
      EnumListInputMinimizerType.BFS -> BfsDeltaDebugger(args)
      EnumListInputMinimizerType.PRISTINE -> PristineDeltaDebugger(args)
      EnumListInputMinimizerType.DFS -> DfsDeltaDebugger(args)
      EnumListInputMinimizerType.PERSES_VARIANT_OF_PRISTINE -> DeltaDebugger(args)
      EnumListInputMinimizerType.PROBDD -> PristineProbabilisticDeltaDebugger(args)
      EnumListInputMinimizerType.CDD -> CounterBasedDeltaDebugger(args)
      EnumListInputMinimizerType.WDD -> WeightedDeltaDebugger(args)
      EnumListInputMinimizerType.WPROBDD -> WeightedProbabilisticDeltaDebugger(args)
    }
  }

  fun <T : Any, Payload> create(
    deltaDebuggerClassName: String,
    args: AbstractListInputMinimizer.Arguments<T, Payload>,
  ): AbstractListInputMinimizer<T, Payload> {
    val deltaDebuggerClass = Class.forName(deltaDebuggerClassName)
    @Suppress("UNCHECKED_CAST")
    return deltaDebuggerClass.getConstructor(
      AbstractListInputMinimizer.Arguments::class.java,
    ).newInstance(
      args,
    ) as AbstractListInputMinimizer<T, Payload>
  }
}
