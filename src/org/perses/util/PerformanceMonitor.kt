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
package org.perses.util

import com.google.common.collect.MapMaker
import java.util.concurrent.ConcurrentMap
import java.util.concurrent.ExecutorService
import java.util.concurrent.Executors
import java.util.concurrent.TimeUnit
import java.util.concurrent.atomic.AtomicInteger

/**
 * This class has to be THREAD_SAFE.
 */
class PerformanceMonitor<T>(
  private val sleepIntervalMillis: Int,
  private val actionOnLongRunningTask: IActionOnLongRunningTask<T>
) : AutoCloseable {

  private val thread: ExecutorService = Executors.newFixedThreadPool(1)
  private val durationList = ThreadSafeDurationStat()

  private val runningTaskToStartTimeMap: ConcurrentMap<T, Long> = MapMaker()
    .weakKeys()
    .initialCapacity(100)
    .concurrencyLevel(10)
    .makeMap()

  init {
    require(sleepIntervalMillis > 10)
    thread.submit {
      while (true) {
        Thread.sleep(sleepIntervalMillis.toLong())
        val threshold = Math.max(durationList.maxDuration(), sleepIntervalMillis)

        val now = System.currentTimeMillis()
        var iterator = runningTaskToStartTimeMap.iterator()
        while (iterator.hasNext()) {
          val entry = iterator.next()
          val key = entry.key
          val startTimeMillis = entry.value
          val duration = (now - startTimeMillis).toInt()
          if (duration >= threshold) {
            actionOnLongRunningTask.onLongRunningTask(key, duration, threshold)
          }
        }
      }
    }
  }

  /**
   * This method is thread-safe.
   */
  fun onTaskStart(task: T) {
    runningTaskToStartTimeMap[task] = System.currentTimeMillis()
  }

  fun onTaskEnd(task: T) {
    val startTime = runningTaskToStartTimeMap.remove(task) ?: return
    durationList.addDuration((System.currentTimeMillis() - startTime).toInt())
  }

  override fun close() {
    thread.shutdownNow()
    thread.awaitTermination(2, TimeUnit.SECONDS)
  }

  fun isClosed() = thread.isTerminated

  fun finishedTaskCount() = durationList.durationCount()

  fun maxDuration() = durationList.maxDuration()

  fun minDuration() = durationList.minDuration()

  class ThreadSafeDurationStat {
    private val numOfDurations = AtomicInteger(0)
    private val minDuration = AtomicInteger(Integer.MAX_VALUE)
    private val maxDuration = AtomicInteger(Integer.MIN_VALUE)

    fun addDuration(duration: Int) {
      check(duration >= 0)
      numOfDurations.incrementAndGet()
      minDuration.accumulateAndGet(duration, Math::min)
      maxDuration.accumulateAndGet(duration, Math::max)
    }

    fun maxDuration() = maxDuration.get()
    fun minDuration() = minDuration.get()
    fun durationCount() = numOfDurations.get()
  }

  fun finalize() {
    check(isClosed())
  }

  interface IActionOnLongRunningTask<T> {
    fun onLongRunningTask(task: T, duration: Int, threshold: Int)
  }
}
