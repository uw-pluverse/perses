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
package org.perses.listminimizer.xfs

import com.google.common.collect.ImmutableList
import org.perses.listminimizer.AbstractListInputMinimizer
import org.perses.listminimizer.Partition
import java.util.ArrayDeque

class BfsDeltaDebugger<T : Any, PropertyPayload>(
  arguments: AbstractListInputMinimizer.Arguments<T, PropertyPayload>,
) : AbstractSpecialDeltaDebugger<T, PropertyPayload>(arguments) {

  override fun pollFromWorklist(
    worklist: ArrayDeque<Partition<ElementWrapper<T>>>,
  ): Partition<ElementWrapper<T>> {
    return worklist.pollFirst()
  }

  override fun addToWorklist(
    worklist: ArrayDeque<Partition<ElementWrapper<T>>>,
    partitions: ImmutableList<Partition<ElementWrapper<T>>>,
  ) {
    for (i in partitions.indices.reversed()) {
      worklist.addLast(partitions[i])
    }
  }
}
