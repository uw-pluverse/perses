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

val ASSERTION_ENABLED: Boolean = AssertionStatusProbe::class.java.desiredAssertionStatus()

private object AssertionStatusProbe

inline fun lazyAssert(test: () -> Boolean) {
  lazyAssert(test) { "" }
}

inline fun lazyAssert(
  test: () -> Boolean,
  message: () -> Any?,
) {
  if (ASSERTION_ENABLED) {
    val result: Boolean
    try {
      result = test()
    } catch (t: Throwable) {
      throw IllegalStateException(message().toString(), t)
    }
    check(result) {
      message() ?: "null"
    }
  }
}
