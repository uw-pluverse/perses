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
package org.perses.util

import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.lang.RuntimeException

@RunWith(JUnit4::class)
class GCMonitoringTest {
  @Ignore("TODO(cnsun): need to implement GCMonitoring.")
  @Test
  fun test() {
    try {
      val gcMonitor = GCMonitoring()
      val list = mutableListOf<ByteArray>()
      while (true) {
        println("under pressure?" + gcMonitor.isMemoryPressureHigh())
        list.add(ByteArray(size = 1024 * 500))
        ByteArray(size = 1024)
        Thread.sleep(1000)
      }
    } catch (e: OutOfMemoryError) {
      val runtime = Runtime.getRuntime()
      val free = runtime.freeMemory()
      val max = runtime.maxMemory()
      val total = runtime.totalMemory()
      println("After OOM: $free, $max, $total")
      throw RuntimeException("After OOM: $free, $max, $total", e)
    }
  }
}
