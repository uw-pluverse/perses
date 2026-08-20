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
package org.perses.listminimizer

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class ListSliderTest {
  private val deleted = mutableSetOf<Int>()

  private fun createSlider(
    expectedWindowSize: Int,
    vararg elements: Int,
  ): BackwardWindowSlider<Int> =
    BackwardWindowSlider(
      expectedWindowSize,
      list = elements.toList(),
    ) {
      deleted.contains(it)
    }

  @Test
  fun slidingWindowReturnsCorrectElements() {
    val slider = createSlider(expectedWindowSize = 3, 1, 2, 3, 4, 5)
    assertThat(slider.slideBackByOnePosition()).containsExactly(3, 4, 5).inOrder()
    assertThat(slider.slideBackByOnePosition()).containsExactly(2, 3, 4).inOrder()
    assertThat(slider.slideBackByOnePosition()).containsExactly(1, 2, 3).inOrder()
    assertThat(slider.slideBackByOnePosition()).isEmpty()
    assertThat(slider.slideBackByOnePosition()).isEmpty()
  }

  @Test
  fun slidingWindowSkipsDeletedElements() {
    val slider = createSlider(expectedWindowSize = 3, 1, 2, 3, 4, 5)
    deleted.addAll(listOf(5, 4))
    assertThat(slider.slideBackByOnePosition()).containsExactly(1, 2, 3).inOrder()
    assertThat(slider.slideBackByOnePosition()).isEmpty()
  }

  @Test
  fun slidingWindowSkipsDeletedElementsTwo() {
    val slider = createSlider(expectedWindowSize = 3, 1, 2, 3, 4, 5)
    assertThat(slider.slideBackByOnePosition()).containsExactly(3, 4, 5).inOrder()
    deleted.addAll(listOf(5, 4))
    assertThat(slider.slideBackByOnePosition()).containsExactly(1, 2, 3).inOrder()
    deleted.addAll(listOf(1, 2, 3))
    assertThat(slider.slideBackByOnePosition()).isEmpty()
  }

  @Test
  fun slidingWindowSkipsDeletedElementsThree() {
    val slider = createSlider(expectedWindowSize = 3, 1, 2, 3, 4, 5)
    assertThat(slider.slideBackByOnePosition()).containsExactly(3, 4, 5).inOrder()
    deleted.addAll(listOf(2, 4))
    assertThat(slider.slideBackByOnePosition()).containsExactly(1, 3).inOrder()
    assertThat(slider.slideBackByOnePosition()).isEmpty()
  }

  @Test
  fun slidingWindowHandlesEmptyList() {
    val slider = createSlider(expectedWindowSize = 3)
    val result = slider.slideBackByOnePosition()
    assertThat(result).isEmpty()
  }

  @Test
  fun slidingWindowHandlesWindowSizeLargerThanList() {
    val list = listOf(1, 2)
    val slider = createSlider(expectedWindowSize = 5, 1, 2)
    assertThat(slider.slideBackByOnePosition()).containsExactly(1, 2).inOrder()
    assertThat(slider.slideBackByOnePosition()).isEmpty()
  }

  @Test
  fun slidingWindowHandlesAllElementsMarkedAsDeleted() {
    val list = listOf(1, 2, 3)
    val slider =
      BackwardWindowSlider(expectedWindowSize = 2, list = list) {
        deleted.contains(it)
      }
    deleted.addAll(list)
    assertThat(slider.slideBackByOnePosition()).isEmpty()
  }

  @Test
  fun slidingWindowHandlesNegativeWindowSize() {
    assertThat(
      kotlin
        .runCatching {
          BackwardWindowSlider(expectedWindowSize = -1, list = listOf(1, 2, 3)) {
            deleted.contains(it)
          }
        }.exceptionOrNull(),
    ).isInstanceOf(IllegalArgumentException::class.java)
  }

  @Test
  fun slidingWindowHandlesNonDistinctElements() {
    val list = listOf(1, 2, 2, 3)
    assertThat(
      kotlin
        .runCatching {
          BackwardWindowSlider(expectedWindowSize = 2, list = list) {
            deleted.contains(it)
          }
        }.exceptionOrNull(),
    ).isInstanceOf(IllegalStateException::class.java)
  }
}
