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

import com.google.common.truth.Truth.assertThat
import difflib.ChangeDelta
import difflib.DeleteDelta
import difflib.InsertDelta
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.PersesDiffUtil.diff

@RunWith(JUnit4::class)
class PersesDiffUtilTest {

  @Test
  fun testDeletion() {
    val diff = diff(listOf("a", "b"), listOf("b")) { a, b ->
      a == b
    }
    val deltas = diff.deltas
    assertThat(deltas).hasSize(1)
    assertThat(deltas.first()).isInstanceOf(DeleteDelta::class.java)
  }

  @Test
  fun testInsertion() {
    val diff = diff(listOf("a", "c"), listOf("a", "b", "c")) { a, b ->
      a == b
    }
    val deltas = diff.deltas
    assertThat(deltas).hasSize(1)
    assertThat(deltas.first()).isInstanceOf(InsertDelta::class.java)
  }

  @Test
  fun testReplacement() {
    val diff = diff(listOf("a", "c"), listOf("a", "b")) { a, b ->
      a == b
    }
    val deltas = diff.deltas
    assertThat(deltas).hasSize(1)
    assertThat(deltas.first()).isInstanceOf(ChangeDelta::class.java)
  }
}
