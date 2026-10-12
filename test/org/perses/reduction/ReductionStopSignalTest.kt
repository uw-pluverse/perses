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
package org.perses.reduction

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class ReductionStopSignalTest {
  private val signal = ReductionStopSignal()

  @Test
  fun testNoRequestMeansNoStop() {
    assertThat(signal.isStopRequested).isFalse()
    assertThat(signal.stopRequests).isEmpty()
  }

  @Test
  fun testEveryRequestIsKeptInOrder() {
    signal.requestStop("first")
    signal.requestStop("second")

    assertThat(signal.isStopRequested).isTrue()
    assertThat(signal.stopRequests.map { it.reason }).containsExactly("first", "second").inOrder()
  }

  @Test
  fun testARequestRecordsItsRequester() {
    requestStopFromHere()

    val request = signal.stopRequests.single()
    assertThat(request.threadName).isEqualTo(Thread.currentThread().name)
    assertThat(request.stackTrace.first().methodName).isEqualTo("requestStopFromHere")
    assertThat(request.describe()).contains("requestStopFromHere")
  }

  private fun requestStopFromHere() {
    signal.requestStop("from here")
  }
}
