/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.reduction.reducer.token

import com.google.common.collect.ImmutableList
import org.perses.reduction.cache.AbstractProgramEncoding
import org.perses.reduction.reducer.token.AbstractSlicingTask.EnumAsyncRunResult
import java.util.ArrayDeque

class SlicingTaskConcurrentExecutor<TASK : AbstractSlicingTask>(
  tasks: ImmutableList<TASK>,
  private val workingDequeExpectedSize: Int,
) {
  private val workingDeque = ArrayDeque<TASK>()
  private val respawnDeque = ArrayDeque<TASK>()
  private val pendingDeque = ArrayDeque(tasks)

  init {
    require(workingDequeExpectedSize > 0)
  }

  fun run() {
    val visitedCacheKeys = HashSet<AbstractProgramEncoding<*>>()
    while (true) {
      val next = nextTask(visitedCacheKeys) ?: return
      val bestFound = next.waitAndApplyEditIfSuccess()
      if (bestFound) {
        cancelTasks()
        visitedCacheKeys.clear()
      }
      populateTasks(visitedCacheKeys)
    }
  }

  private fun nextTask(
    visitedCacheKeys: HashSet<AbstractProgramEncoding<*>>,
  ): AbstractSlicingTask? {
    populateTasks(visitedCacheKeys)
    if (workingDeque.isEmpty()) {
      return null
    }
    val result = workingDeque.removeFirst()
    populateTasks(visitedCacheKeys)
    return result
  }

  private fun populateTasks(
    visitedCacheKeys: HashSet<AbstractProgramEncoding<*>>,
  ) {
    while (workingDeque.size < workingDequeExpectedSize && pendingDeque.isNotEmpty()) {
      val newTask = pendingDeque.removeFirst()
      when (newTask.tryAsyncRun(visitedCacheKeys)) {
        EnumAsyncRunResult.PRECONDITION_FAIL -> {
          // this task will be deleted forever
        }
        EnumAsyncRunResult.CACHE_HIT -> {
          // reusable when best found within current granularity
          respawnDeque.addLast(newTask)
        }
        EnumAsyncRunResult.TEST_SUBMITTED -> {
          // task submitted to test service
          workingDeque.addLast(newTask)
        }
      }
    }
  }

  private fun cancelTasks() {
    while (workingDeque.isNotEmpty()) {
      val task = workingDeque.removeLast()
      task.cancel()
      pendingDeque.addFirst(task)
    }

    // add tasks to pendingDeque in the order of slicing interval.
    while (respawnDeque.isNotEmpty()) {
      pendingDeque.addFirst(respawnDeque.removeLast())
    }
  }
}
