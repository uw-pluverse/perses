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

import org.perses.reduction.ReductionListenerManager
import org.perses.reduction.TreeEditWithItsResult
import org.perses.reduction.partition.Partition
import org.perses.tree.spar.AbstractNodeActionSetCache
import org.perses.tree.spar.AbstractSparTreeEdit
import java.util.ArrayDeque
import java.util.Optional
import java.util.function.Function

class BfsDeltaDebugger constructor(
  listenerManager: ReductionListenerManager,
  nodeActionSetCache: AbstractNodeActionSetCache,
  treeEditTester: Function<AbstractSparTreeEdit, Optional<TreeEditWithItsResult>>
) :
  AbstractSpecialDeltaDebugger(listenerManager, nodeActionSetCache, treeEditTester) {

  override fun pollFromWorklist(worklist: ArrayDeque<Partition>): Partition {
    return worklist.pollFirst()
  }

  override fun addToWorklist(worklist: ArrayDeque<Partition>, partitions: Array<out Partition>) {
    for (i in partitions.indices.reversed()) {
      worklist.addLast(partitions[i])
    }
  }
}
