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

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class ImmutableListBuilderExtTest {
  @Test
  fun aFreshBuilderIsEmpty() {
    val builder = ImmutableListBuilderExt<String>()
    assertThat(builder.size).isEqualTo(0)
    assertThat(builder.isEmpty()).isTrue()
    assertThat(builder.isNotEmpty()).isFalse()
    assertThat(builder.build()).isEmpty()
  }

  @Test
  fun addUpdatesTheSize() {
    val builder = ImmutableListBuilderExt<String>()
    builder.add("a")
    assertThat(builder.size).isEqualTo(1)
    builder.add("b")
    assertThat(builder.size).isEqualTo(2)
    assertThat(builder.isEmpty()).isFalse()
    assertThat(builder.isNotEmpty()).isTrue()
    assertThat(builder.build()).containsExactly("a", "b").inOrder()
  }

  @Test
  fun addAllUpdatesTheSize() {
    val builder = ImmutableListBuilderExt<String>()
    builder.addAll(ImmutableList.of("a", "b", "c"))
    assertThat(builder.size).isEqualTo(3)
    builder.addAll(emptyList())
    assertThat(builder.size).isEqualTo(3)
    builder.addAll(sequenceOf("d").asIterable())
    assertThat(builder.size).isEqualTo(4)
    assertThat(builder.build()).containsExactly("a", "b", "c", "d").inOrder()
  }

  @Test
  fun addAndAddAllAreChainable() {
    val list =
      ImmutableListBuilderExt<String>()
        .add("a")
        .addAll(ImmutableList.of("b", "c"))
        .add("d")
        .build()
    assertThat(list).containsExactly("a", "b", "c", "d").inOrder()
  }

  @Test
  fun duplicatesAreCountedSeparately() {
    val builder = ImmutableListBuilderExt<String>()
    builder.add("a").add("a")
    assertThat(builder.size).isEqualTo(2)
    assertThat(builder.build()).containsExactly("a", "a")
  }
}
