/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.util.hashing

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class EnumShaAlgorithmTest {
  @Test
  fun test() {
    val string = "a"
    val sha512 = EnumShaAlgorithm.SHA512.hashString(string).toString()
    val sha256 = EnumShaAlgorithm.SHA256.hashString(string).toString()
    assertThat(sha512).hasLength(128)
    assertThat(sha256).hasLength(64)
    assertThat(sha512).isNotEqualTo(sha256)
  }
}
