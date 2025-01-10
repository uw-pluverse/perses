/*
 * Copyright (C) 2018-2025 University of Waterloo.
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

import com.google.common.truth.Truth
import java.lang.AssertionError

object TruthExt {

  fun assertTrimmedNonBlankLinesEqual(
    toBeTested: String,
    vararg expectedLines: String,
  ) {
    val actual = toBeTested.lines().map { it.trim() }.filter { it.isNotBlank() }
    val expected = expectedLines.toList()
    if (actual != expected) {
      System.err.println()
    }
    try {
      Truth.assertThat(actual).isEqualTo(expected)
    } catch (e: Throwable) {
      throw AssertionError(
        """|Expected list is 
           |${expected.joinToString(separator = "\n")}
           |
           |Actual list is
           |${actual.joinToString(separator = "\n")}
           |
        """.trimMargin(),
        e,
      )
    }
  }
}
