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
import java.util.logging.Level
import java.util.logging.LogRecord

@RunWith(JUnit4::class)
class RelativeTimeFormatterTest {
  private val formatter = RelativeTimeFormatter()

  @Test
  fun testAMessageIsFormattedWithItsLevel() {
    val formatted = formatter.format(LogRecord(Level.WARNING, "something happened"))

    assertThat(formatted).contains("WARNING")
    assertThat(formatted).contains("something happened")
  }

  /**
   * A cause is attached by `FluentLogger.withCause()` and by any JUL logger setting `thrown`. A
   * formatter that ignores it turns "the exception was reported" into a message with no exception,
   * which is worse than never attaching one.
   */
  @Test
  fun testAnAttachedCauseIsReported() {
    val record = LogRecord(Level.WARNING, "recording failed")
    record.thrown = IllegalStateException("the underlying reason")

    val formatted = formatter.format(record)

    assertThat(formatted).contains("recording failed")
    assertThat(formatted).contains("IllegalStateException")
    assertThat(formatted).contains("the underlying reason")
    // The stack trace, not merely the exception's toString, is what identifies which check fired.
    assertThat(formatted).contains("RelativeTimeFormatterTest")
  }

  /** A wrapped failure must report the original too, or the useful half is the half that is lost. */
  @Test
  fun testAChainedCauseIsReportedInFull() {
    val record = LogRecord(Level.WARNING, "recording failed")
    record.thrown =
      IllegalStateException(
        "could not write the problem",
        IllegalArgumentException("an element owns no tokens"),
      )

    val formatted = formatter.format(record)

    assertThat(formatted).contains("could not write the problem")
    assertThat(formatted).contains("Caused by")
    assertThat(formatted).contains("an element owns no tokens")
  }

  @Test
  fun testARecordWithoutACauseGainsNothing() {
    val formatted = formatter.format(LogRecord(Level.INFO, "plain"))

    assertThat(formatted.trim()).endsWith("plain")
  }
}
