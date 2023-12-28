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
package org.perses.reduction

import com.google.common.flogger.FluentLogger
import com.google.common.util.concurrent.ListenableFuture
import org.perses.util.ktWarning
import java.util.concurrent.TimeUnit
import java.util.concurrent.TimeoutException

class RestrictedFuture<T>(
  private val future: ListenableFuture<T>,
  private val defaultTimeoutInSeconds: Long,
  private val defaultKeepTrying: Boolean,
) {

  fun cancelWithInterruption() = future.cancel(true) // true means mayInterruptIfRunning

  fun getWithTimeoutWarnings(
    timeoutInSeconds: Long = defaultTimeoutInSeconds,
    keepTrying: Boolean = defaultKeepTrying,
    timeoutHandler: () -> Unit = {
      logger.ktWarning { TestScriptExecutorService.MSG_SCRIPT_RUN_TOO_LONG }
    },
  ): T? {
    while (true) {
      try {
        return future.get(timeoutInSeconds, TimeUnit.SECONDS)
      } catch (e: TimeoutException) {
        timeoutHandler()
        if (!keepTrying) {
          return null
        }
        continue
      }
    }
  }

  fun isDone() = future.isDone

  fun isCancelled() = future.isCancelled

  companion object {
    val logger = FluentLogger.forEnclosingClass()
  }
}
