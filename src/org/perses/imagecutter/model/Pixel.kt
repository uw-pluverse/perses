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
package org.perses.imagecutter.model

@JvmInline
value class Pixel @PublishedApi internal constructor(val longValue: Long) {

  val x: Int
    get() = longValue.ushr(48).toInt()

  val y: Int
    get() = longValue.ushr(32).toInt().and(0xFF)

  val alpha: Int
    get() = longValue.ushr(24).toInt().and(0xF)

  val red: Int
    get() = longValue.ushr(16).toInt().and(0xF)

  val green: Int
    get() = longValue.ushr(8).toInt().and(0xF)

  val blue: Int
    get() = longValue.and(0xFL).toInt()

  companion object {

    fun create(
      x: Int,
      y: Int,
      red: Int,
      green: Int,
      blue: Int,
      alpha: Int,
    ): Pixel {
      require(x in 0..UShort.MAX_VALUE.toInt())
      require(y in 0..UShort.MAX_VALUE.toInt())
      require(red in 0..255)
      require(green in 0..255)
      require(blue in 0..255)
      require(alpha in 0..255)
      return Pixel(
        x.toLong().shl(48)
          or y.toLong().shl(32)
          or alpha.toLong().shl(24)
          or red.toLong().shl(16)
          or green.toLong().shl(8)
          or blue.toLong(),
      )
    }
  }
}
