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
package org.perses.util.shell

@JvmInline
value class ExitCode(val intValue: Int) {

  init {
    require(intValue in MIN_EXIT_CODE_INT..MAX_EXIT_CODE_INT) { intValue }
  }

  fun isZero() = intValue == 0

  fun isNonZero() = intValue != 0

  companion object {
    const val MIN_EXIT_CODE_INT = 0
    const val MAX_EXIT_CODE_INT = 255
    const val DEFAULT_ERROR_EXIT_CODE_INT = 241

    val ZERO = ExitCode(0)
    val ONE = ExitCode(1)
  }
}
