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

  @Test
  fun testComputeSha512ForString() {
    val string = "hello"
    val sha512 = EnumShaAlgorithm.SHA512.createFromString(string)
    assertThat(sha512.numOfStrings).isEqualTo(1)
    assertThat(sha512.getLengthOfString(0)).isEqualTo(string.length)
    assertThat(sha512.digest.toString()).isEqualTo(
      "9b71d224bd62f3785d96d46ad3ea3d73319bfbc2890caa" +
        "dae2dff72519673ca72323c3d99ba5c11d7c7acc6e14b8c5da0c4663475c2e5c3adef46f73bcdec043",
    )
  }

  @Test
  fun testComputeShaForListOfStrings() {
    val sha = EnumShaAlgorithm.SHA512
    val list =
      listOf(
        sha.hashListOfStrings(emptyList()),
        sha.hashListOfStrings(listOf("")),
        sha.hashListOfStrings(listOf("", "")),
        sha.hashListOfStrings(listOf("ab", "")),
        sha.hashListOfStrings(listOf("", "ab")),
        sha.hashListOfStrings(listOf("", "", "")),
        sha.hashListOfStrings(listOf("a", "")),
        sha.hashListOfStrings(listOf("", "a")),
      )
    assertThat(list.toSet()).containsExactlyElementsIn(list)
    assertThat(list.toSet().size).isEqualTo(list.size)
  }
}
