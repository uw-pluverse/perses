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
package org.perses.util.shell

@JvmInline
value class ExitCode(val intValue: Int) {

  init {
    require(intValue in MIN_EXIT_CODE..MAX_EXIT_CODE) { intValue }
  }

  fun isZero() = intValue == 0

  fun isNonZero() = intValue != 0

  companion object {
    private const val MIN_EXIT_CODE = 0
    private const val MAX_EXIT_CODE = 255
    val ZERO = ExitCode(0)
    val ONE = ExitCode(1)
  }
}
