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

import com.google.common.collect.ImmutableList
import java.util.ArrayDeque

class SlicingTaskConcurrentExecutor<TASK : AbstractSlicingTask>(
  tasks: ImmutableList<TASK>,
  private val workingDequeExpectedSize: Int
) {
  private val workingDeque = ArrayDeque<TASK>()
  private val pendingDeque = ArrayDeque<TASK>(tasks)

  init {
    require(workingDequeExpectedSize > 0)
  }

  fun run() {
    while (true) {
      val next = nextTask() ?: return
      val bestFound = next.waitAndApplyEditIfSuccess()
      if (bestFound) {
        cancelTasks()
      }
      populateTasks()
    }
  }

  private fun nextTask(): AbstractSlicingTask? {
    populateTasks()
    if (workingDeque.isEmpty()) {
      return null
    }
    val result = workingDeque.removeFirst()
    populateTasks()
    return result
  }

  private fun populateTasks() {
    while (workingDeque.size < workingDequeExpectedSize && pendingDeque.isNotEmpty()) {
      val newTask = pendingDeque.removeFirst()
      if (newTask.tryAsyncRun()) {
        workingDeque.addLast(newTask)
      }
    }
  }

  private fun cancelTasks() {
    val iterator = workingDeque.descendingIterator()
    while (iterator.hasNext()) {
      val task = iterator.next()
      task.cancel()
      pendingDeque.addFirst(task)
    }
    workingDeque.clear()
  }
}
