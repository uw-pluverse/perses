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

import org.perses.listminimizer.localexhaust.LocalExhaustWindowedMinimizer
import org.perses.listminimizer.xfs.BfsListMinimizer
import org.perses.listminimizer.xfs.DeltaDebugger
import org.perses.listminimizer.xfs.DfsListMinimizer

object ListMinimizerFactory {
  fun <T : Any, Payload> create(
    type: EnumListMinimizerType,
    args: ListMinimizerArguments<T, Payload>,
  ): AbstractListMinimizer<T, Payload> =
    when (type) {
      EnumListMinimizerType.BFS -> BfsListMinimizer(args)
      EnumListMinimizerType.PRISTINE_DDMIN -> PristineDeltaDebugger(args)
      EnumListMinimizerType.DFS -> DfsListMinimizer(args)
      EnumListMinimizerType.PERSES_VARIANT_OF_PRISTINE -> DeltaDebugger(args)
      EnumListMinimizerType.PROBDD -> PristineProbabilisticDeltaDebugger(args)
      EnumListMinimizerType.CDD -> CounterBasedDeltaDebugger(args)
      EnumListMinimizerType.WDD -> WeightedDeltaDebugger(args)
      EnumListMinimizerType.WPROBDD -> WeightedProbabilisticDeltaDebugger(args)
      EnumListMinimizerType.WINDOWED_SLICER -> WindowedSlicer(args)
      EnumListMinimizerType.LOCAL_EXHAUSTIVE_PATTERN_ENUMERATION ->
        LocalExhaustWindowedMinimizer(
          args,
        )
    }

  fun <T : Any, Payload> create(
    deltaDebuggerClassName: String,
    args: ListMinimizerArguments<T, Payload>,
  ): AbstractListMinimizer<T, Payload> {
    val deltaDebuggerClass = Class.forName(deltaDebuggerClassName)
    @Suppress("UNCHECKED_CAST")
    return deltaDebuggerClass
      .getConstructor(
        ListMinimizerArguments::class.java,
      ).newInstance(
        args,
      ) as AbstractListMinimizer<T, Payload>
  }
}
