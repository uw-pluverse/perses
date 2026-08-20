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

import com.google.common.base.Strings
import java.util.concurrent.atomic.AtomicInteger

/**
 * Issues zero-padded sequence numbers, so that a lexical sort of the results is also the order they
 * were issued in. Used to name generated directories and files that would otherwise sort as 1, 10,
 * 2 -- and to give a shared sequence to several producers that must not collide.
 */
class AtomicSequenceGenerator(
  private val start: Int = 1,
  private val minLengthForPadding: Int,
) {
  init {
    require(minLengthForPadding > 0)
  }

  private val generator = AtomicInteger(start)

  /**
   * How many ids have been issued -- not the counter's current value, so a non-zero [start] does not
   * inflate it. Exposed so a caller that bounds the sequence can consult the generator rather than
   * keep a second counter of its own in step with it.
   */
  val issuedCount: Int
    get() = generator.get() - start

  fun next(): String = format(generator.getAndIncrement())

  private fun format(sequence: Int): String =
    Strings.padStart(sequence.toString(), minLengthForPadding, '0')
}
