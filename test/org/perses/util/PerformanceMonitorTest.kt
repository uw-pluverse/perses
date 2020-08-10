package org.perses.util

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.PerformanceMonitor.IActionOnLongRunningTask

@RunWith(JUnit4::class)
class PerformanceMonitorTest {

  val action = Action()
  val monitor = PerformanceMonitor<Any>(
    sleepIntervalMillis = SLEEP_INTERVAL,
    actionOnLongRunningTask = action
  )

  @Test
  fun testShutdown() {
    assertThat(monitor.isClosed()).isFalse()
    Thread.sleep(TEN_SECONDS)
    monitor.close()
    assertThat(monitor.isClosed()).isTrue()
  }

  @Test
  fun testDetectLongRunningTasks() {
    val task1 = Object()
    monitor.onTaskStart(task1)
    Thread.sleep(SLEEP_INTERVAL.toLong() * 2)
    assertThat(action.longRunningTasks).isNotEmpty()
    assertThat(action.longRunningTasks[0].task).isSameInstanceAs(task1)
    assertThat(action.longRunningTasks[0].threshold).isEqualTo(SLEEP_INTERVAL)

    assertThat(monitor.finishedTaskCount()).isEqualTo(0)

    monitor.close()
  }

  @Test
  fun testDurationList() {
    val task1 = Object()
    monitor.onTaskStart(task1)
    monitor.onTaskEnd(task1)

    assertThat(monitor.maxDuration()).isEqualTo(monitor.minDuration())

    val task2 = Object()
    monitor.onTaskStart(task2)
    monitor.onTaskEnd(task2)

    assertThat(monitor.finishedTaskCount()).isEqualTo(2)
    assertThat(monitor.maxDuration()).isAtLeast(monitor.minDuration())

    monitor.close()
  }

  @After
  fun teardown() {
    assertThat(monitor.isClosed()).isTrue()
  }

  data class TaskInfo(val task: Any, val duration: Int, val threshold: Int)

  class Action : IActionOnLongRunningTask<Any> {
    val longRunningTasks = ArrayList<TaskInfo>()

    override fun onLongRunningTask(task: Any, duration: Int, threshold: Int) {
      longRunningTasks.add(TaskInfo(task, duration, threshold))
    }
  }

  companion object {
    const val TEN_SECONDS = 1000 * 10L
    const val SLEEP_INTERVAL = 20
  }
}
