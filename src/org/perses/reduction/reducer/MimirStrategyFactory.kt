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
package org.perses.reduction.reducer

import org.perses.reduction.reducer.EnumMimirReductionAlgorithm.BOTTOM_LAYER_FIRST_THEN_TOPDOWN_PLUS
import org.perses.reduction.reducer.EnumMimirReductionAlgorithm.DAG_AS_LIST
import org.perses.reduction.reducer.EnumMimirReductionAlgorithm.DFS_DAG
import org.perses.reduction.reducer.EnumMimirReductionAlgorithm.FINER_DAG_AS_LIST
import org.perses.reduction.reducer.EnumMimirReductionAlgorithm.FINE_DAG_AS_LIST

/**
 * A factory class for creating Mimir reduction strategies.
 */
object MimirStrategyFactory {
  /**
   * Creates a Mimir reduction strategy based on the given algorithm.
   */
  fun create(mimirReductionAlgorithm: EnumMimirReductionAlgorithm): AbstractMimirStrategy =
    when (mimirReductionAlgorithm) {
      DFS_DAG -> MimirStrategyDfsDag()
      DAG_AS_LIST -> MimirStrategyDagAsList()
      FINE_DAG_AS_LIST -> MimirStrategyFineDagAsList()
      FINER_DAG_AS_LIST -> MimirStrategyFinerDagAsList()
      BOTTOM_LAYER_FIRST_THEN_TOPDOWN_PLUS -> MimirStrategyBottomLayerThenTopDown()

      else -> MimirStrategyLayerByLayer()
    }
}
