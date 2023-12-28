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
package org.perses.util

import com.google.common.util.concurrent.ListeningExecutorService
import com.google.common.util.concurrent.MoreExecutors
import java.time.Duration
import java.util.concurrent.ExecutorService
import java.util.concurrent.Executors

object DaemonThreadPool {

  fun create(numThreads: Int): ListeningExecutorService {
    return MoreExecutors.listeningDecorator(
      Executors.newFixedThreadPool(
        numThreads,
      ) { runnable ->
        val thread = Executors.defaultThreadFactory().newThread(runnable)
        thread.isDaemon = true
        thread
      },
    )
  }

  fun createSingleThreadPool() = create(numThreads = 1)

  private val DEFAULT_SHUTDOWN_DURATION: Duration = Duration.ofMinutes(2)

  fun shutdownOrThrow(
    executorService: ExecutorService,
    shutdownDuration: Duration = DEFAULT_SHUTDOWN_DURATION,
  ) {
    check(MoreExecutors.shutdownAndAwaitTermination(executorService, shutdownDuration)) {
      "Fail to shutdown executor service within $shutdownDuration"
    }
  }

  fun waitInfinitelyToShutdown(executorService: ExecutorService) {
    shutdownOrThrow(executorService, Duration.ofDays(99))
  }
}
