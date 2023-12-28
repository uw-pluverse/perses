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

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class PixelTest {

  val pixel = Pixel.create(x = 0, y = 0, red = 0, green = 0, blue = 0, alpha = 0)
  val pixel2 = Pixel.create(x = 1, y = 2, red = 3, green = 4, blue = 5, alpha = 6)

  @Test
  fun testZeroPixel() {
    assertThat(pixel.x).isEqualTo(0)
    assertThat(pixel.y).isEqualTo(0)
    assertThat(pixel.alpha).isEqualTo(0)
    assertThat(pixel.red).isEqualTo(0)
    assertThat(pixel.green).isEqualTo(0)
    assertThat(pixel.blue).isEqualTo(0)
  }

  @Test
  fun testComplexPixel() {
    val pixel = pixel2
    assertThat(pixel.x).isEqualTo(1)
    assertThat(pixel.y).isEqualTo(2)
    assertThat(pixel.red).isEqualTo(3)
    assertThat(pixel.green).isEqualTo(4)
    assertThat(pixel.blue).isEqualTo(5)
    assertThat(pixel.alpha).isEqualTo(6)
  }

  @Test
  fun testSuperpixel() {
    val superpixel = Superpixel.Builder()
      .add(pixel)
      .add(pixel2)
      .build()

    assertThat(superpixel.get(0).longValue).isEqualTo(pixel.longValue)
    assertThat(superpixel.get(1).longValue).isEqualTo(pixel2.longValue)
    assertThat(superpixel.size).isEqualTo(2)
  }
}
