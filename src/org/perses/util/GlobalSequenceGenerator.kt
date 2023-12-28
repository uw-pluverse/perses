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
package org.perses.util

import com.google.common.base.Strings
import java.util.concurrent.atomic.AtomicInteger

/**
 * This class is used to differentiate two timestamps. If
 * two timestamps are collected adjacent in time, they might
 * be the same. This class can make sure that in a JVM process
 * we have a monotonically increasing clock.
 */
object GlobalSequenceGenerator {
  private val generator = AtomicInteger()

  fun next() = generator.getAndIncrement()

  fun nextWithPadding(paddingLength: Int, paddingChar: Char = '0'): String {
    return Strings.padStart(next().toString(), paddingLength, paddingChar)
  }
}
