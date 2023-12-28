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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.DaemonThreadPool
import java.util.concurrent.atomic.AtomicBoolean
import kotlin.coroutines.cancellation.CancellationException

@RunWith(JUnit4::class)
class RestrictedFutureTest {

  private val service = DaemonThreadPool.createSingleThreadPool()

  @After
  fun teardown() {
    DaemonThreadPool.shutdownOrThrow(service)
  }

  @Test
  fun testCancelWithInterruption() {
    val future = RestrictedFuture(
      service.submit {
        Thread.sleep(999999999)
      },
      defaultKeepTrying = true,
      defaultTimeoutInSeconds = 1,
    )
    assertThat(future.isCancelled()).isFalse()
    assertThat(future.isDone()).isFalse()

    future.cancelWithInterruption()

    assertThat(future.isCancelled()).isTrue()
    assertThat(future.isDone()).isTrue()
  }

  @Test
  fun testGetWithTimeoutWarningsKeepTrying() {
    val future = RestrictedFuture(
      service.submit {
        Thread.sleep(999999999)
      },
      defaultTimeoutInSeconds = 1,
      defaultKeepTrying = true,
    )
    assertThat(future.isCancelled()).isFalse()
    assertThat(future.isDone()).isFalse()

    val localService = DaemonThreadPool.createSingleThreadPool()
    localService.submit {
      Thread.sleep(1000 * 10.toLong())
      future.cancelWithInterruption()
    }
    val counter = AtomicBoolean(false)
    Assert.assertThrows(CancellationException::class.java) {
      future.getWithTimeoutWarnings() {
        counter.set(true)
      }
    }
    assertThat(counter.get()).isTrue()
    DaemonThreadPool.shutdownOrThrow(localService)
  }

  @Test
  fun testGetWithTimeoutWarningsWithoutKeepTrying() {
    val future = RestrictedFuture(
      service.submit {
        Thread.sleep(999999999)
      },
      defaultTimeoutInSeconds = 1,
      defaultKeepTrying = true,
    )
    assertThat(future.isCancelled()).isFalse()
    assertThat(future.isDone()).isFalse()

    val counter = AtomicBoolean(false)
    val result = future.getWithTimeoutWarnings(keepTrying = false) {
      counter.set(true)
    }
    assertThat(result).isNull()
    assertThat(counter.get()).isTrue()
  }
}
