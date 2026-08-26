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

data class SpaceSize(
  val bytes: Long,
) {
  fun toKiloBytes() = bytes / 1000

  fun toMegaBytes() = toKiloBytes() / 1000

  fun toGigaBytes() = toMegaBytes() / 1000

  companion object {
    fun megaBytes(mb: Long): SpaceSize = kiloBytes(kb = mb * 1000)

    fun kiloBytes(kb: Long) = SpaceSize(bytes = kb * 1000)
  }
}
