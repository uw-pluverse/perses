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

import com.google.common.primitives.ImmutableLongArray

@JvmInline
value class Superpixel internal constructor(@PublishedApi internal val pixels: ImmutableLongArray) {

  val size: Int
    get() = pixels.length()

  @Suppress("NOTHING_TO_INLINE")
  inline fun get(index: Int): Pixel = Pixel(pixels.get(index))

  class Builder(initialCapacity: Int = 10) {
    private val builder = ImmutableLongArray.builder(initialCapacity)

    var size: Int = 0
      private set

    fun add(pixel: Pixel): Builder {
      builder.add(pixel.longValue)
      return this
    }

    fun build() = Superpixel(builder.build())
  }
}
