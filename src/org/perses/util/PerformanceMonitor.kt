package org.perses.util

import com.google.common.collect.MapMaker
import it.unimi.dsi.fastutil.ints.IntArrayList
import java.util.concurrent.ConcurrentMap
import java.util.concurrent.ExecutorService
import java.util.concurrent.Executors
import java.util.concurrent.TimeUnit

class PerformanceMonitor<T>(
  private val sleepIntervalMillis: Int,
  private val actionOnLongRunningTask: IActionOnLongRunningTask<T>
) : AutoCloseable {

  private val thread: ExecutorService = Executors.newFixedThreadPool(1)
  private val durationList = DurationList()

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
        val threshold = Math.max(durationList.maxDuration, sleepIntervalMillis)

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

  fun finishedTaskCount() = durationList.size()

  fun maxDuration() = durationList.maxDuration

  fun minDuration() = durationList.minDuration

  class DurationList {
    private val durationList = IntArrayList()

    var minDuration = Int.MAX_VALUE
      private set

    var maxDuration = Int.MIN_VALUE
      private set

    fun addDuration(duration: Int) {
      assert(duration >= 0)
      durationList.add(duration)
      minDuration = Math.min(minDuration, duration)
      maxDuration = Math.max(maxDuration, duration)
    }

    fun size() = durationList.size
  }

  fun finalize() {
    check(isClosed())
  }

  interface IActionOnLongRunningTask<T> {
    fun onLongRunningTask(task: T, duration: Int, threshold: Int)
  }
}
