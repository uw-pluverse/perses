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

import com.fasterxml.jackson.annotation.JsonIgnore
import org.perses.util.shell.ExitCode

/** The result of a test, including runtime information, i.e., time, exit code.  */
data class PropertyTestResult(
  val exitCode: ExitCode,
  val elapsedMillis: Int,
) {
  @get:JsonIgnore
  val isInteresting: Boolean
    get() = exitCode.isZero()

  @get:JsonIgnore
  val isNotInteresting: Boolean
    get() = !isInteresting

  companion object {
    val INTERESTING_RESULT = PropertyTestResult(ExitCode.ZERO, elapsedMillis = 0)
    val NON_INTERESTING_RESULT = PropertyTestResult(ExitCode.ONE, elapsedMillis = 0)

    fun of(
      exitCode: Int,
      elapsedMillis: Int,
    ) = PropertyTestResult(
      ExitCode(exitCode),
      elapsedMillis,
    )
  }
}
