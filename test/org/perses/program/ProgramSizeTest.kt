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
package org.perses.program

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class ProgramSizeTest {
  @Test
  fun testWithNewPayload() {
    val originalSize =
      ProgramSize(
        payload = "OriginalPayload",
        canonicalTokenCount = 10,
        surrogateTokenCount = 20,
        totalCharacterCount = 100,
        nonBlankCharacterCount = 9,
      )

    val newSize = originalSize.withNewPayload(42)

    assertThat(newSize.payload).isEqualTo(42)
    assertThat(newSize.canonicalTokenCount).isEqualTo(10)
    assertThat(newSize.surrogateTokenCount).isEqualTo(20)
    assertThat(newSize.totalCharacterCount).isEqualTo(100)
    assertThat(newSize.nonBlankCharacterCount).isEqualTo(9)
  }

  @Test
  fun testWithNewPayloadNullable() {
    val originalSize =
      ProgramSize(
        payload = "Hello",
        canonicalTokenCount = 5,
        surrogateTokenCount = 2,
        totalCharacterCount = 15,
        nonBlankCharacterCount = 4,
      )

    val newSize = originalSize.withNewPayload(Unit)

    assertThat(newSize.canonicalTokenCount).isEqualTo(5)
    assertThat(newSize.surrogateTokenCount).isEqualTo(2)
    assertThat(newSize.totalCharacterCount).isEqualTo(15)
    assertThat(newSize.nonBlankCharacterCount).isEqualTo(4)
  }

  @Test
  fun testWithoutPayloadKeepsEveryCountAndDropsTheProgram() {
    val originalSize =
      ProgramSize(
        payload = "Hello",
        canonicalTokenCount = 5,
        surrogateTokenCount = 2,
        totalCharacterCount = 15,
        nonBlankCharacterCount = 4,
      )

    val strippedSize = originalSize.withoutPayload()

    assertThat(strippedSize.payload).isEqualTo(Unit)
    assertThat(strippedSize.canonicalTokenCount).isEqualTo(5)
    assertThat(strippedSize.surrogateTokenCount).isEqualTo(2)
    assertThat(strippedSize.totalCharacterCount).isEqualTo(15)
    assertThat(strippedSize.nonBlankCharacterCount).isEqualTo(4)
    assertThat(strippedSize.compareTo(originalSize)).isEqualTo(0)
  }

  @Test
  fun testCompareTo() {
    // 1. Compare canonicalTokenCount
    val size1 = ProgramSize("A", 10, 20, 100, 9)
    val size2 = ProgramSize("B", 11, 20, 100, 9)
    assertThat(size1).isLessThan(size2)
    assertThat(size2).isGreaterThan(size1)

    // 2. Compare nonBlankCharacterCount
    val size5 = ProgramSize("A", 10, 20, 100, 9)
    val size6 = ProgramSize("B", 10, 20, 100, 10)
    assertThat(size5).isLessThan(size6)
    assertThat(size6).isGreaterThan(size5)

    // 3. Compare totalCharacterCount
    val size7 = ProgramSize("A", 10, 20, 100, 9)
    val size8 = ProgramSize("B", 10, 20, 101, 9)
    assertThat(size7).isLessThan(size8)
    assertThat(size8).isGreaterThan(size7)

    // 4. Compare surrogateTokenCount
    val size3 = ProgramSize("A", 10, 20, 100, 9)
    val size4 = ProgramSize("B", 10, 21, 100, 9)
    assertThat(size3).isLessThan(size4)
    assertThat(size4).isGreaterThan(size3)

    // 5. Equal
    val size9 = ProgramSize("A", 10, 20, 100, 9)
    val size10 = ProgramSize("B", 10, 20, 100, 9)
    assertThat(size9.compareTo(size10)).isEqualTo(0)
  }
}
