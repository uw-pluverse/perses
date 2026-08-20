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

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.util.concurrent.Callable

@RunWith(JUnit4::class)
class AtomicSequenceGeneratorTest {
  @Test
  fun testIdsAreZeroPaddedSoTheySortInIssueOrder() {
    val generator = AtomicSequenceGenerator(minLengthForPadding = 2)

    (1..9).forEach { assertThat(generator.next()).isEqualTo("0$it") }
    assertThat(generator.next()).isEqualTo("10")
    assertThat(generator.next()).isEqualTo("11")
  }

  @Test
  fun testIssuedCountIgnoresTheStartingValue() {
    val fromZero = AtomicSequenceGenerator(start = 0, minLengthForPadding = 3)
    assertThat(fromZero.issuedCount).isEqualTo(0)
    assertThat(fromZero.next()).isEqualTo("000")
    assertThat(fromZero.issuedCount).isEqualTo(1)

    // The count is of ids issued, not the counter's value, so a non-zero start does not inflate it.
    val fromSeven = AtomicSequenceGenerator(start = 7, minLengthForPadding = 3)
    assertThat(fromSeven.issuedCount).isEqualTo(0)
    assertThat(fromSeven.next()).isEqualTo("007")
    assertThat(fromSeven.issuedCount).isEqualTo(1)
  }


  /** The class is named for its atomicity, so no two producers may be handed the same id. */
  @Test
  fun testConcurrentProducersNeverShareAnId() {
    val generator = AtomicSequenceGenerator(start = 0, minLengthForPadding = 4)
    val threadCount = 8
    val perThread = 100
    val pool = DaemonThreadPool.create(numThreads = threadCount, creatorObject = this)
    try {
      val issued =
        pool
          .invokeAll(
            (1..threadCount).map { Callable { (1..perThread).map { generator.next() } } },
          ).flatMap { it.get() }

      assertThat(issued).hasSize(threadCount * perThread)
      assertThat(issued.toSet()).hasSize(threadCount * perThread)
      assertThat(generator.issuedCount).isEqualTo(threadCount * perThread)
    } finally {
      DaemonThreadPool.shutdownOrThrow(pool)
    }
  }
}
