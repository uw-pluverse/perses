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

import com.google.common.truth.Truth.assertThat
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class TableForTextPrintingTest {
  @Test
  fun testPrintBasic() {
    val data =
      listOf(
        listOf("Header1", "Header2"),
        listOf("Row1Col1", "Row1Col2"),
        listOf("R2C1", "R2C2"),
      )
    val table = TableForTextPrinting(data)
    val expected =
      """
      | Header1  Header2
      |Row1Col1 Row1Col2
      |    R2C1     R2C2
      """.trimMargin()
    assertThat(table.print()).isEqualTo(expected)
  }

  @Test
  fun testPrintWithSeparator() {
    val data =
      listOf(
        listOf("A", "B"),
        listOf("C", "D"),
      )
    val table = TableForTextPrinting(data, columnSeparator = " | ")
    val expected =
      """
      |A | B
      |C | D
      """.trimMargin()
    assertThat(table.print()).isEqualTo(expected)
  }

  @Test
  fun testEmptyData() {
    assertThrows(IllegalArgumentException::class.java) {
      TableForTextPrinting(emptyList())
    }
  }

  @Test
  fun testInconsistentRowSizes() {
    val data =
      listOf(
        listOf("A", "B"),
        listOf("C"),
      )
    assertThrows(IllegalArgumentException::class.java) {
      TableForTextPrinting(data)
    }
  }

  @Test
  fun testPadding() {
    val data =
      listOf(
        listOf("Short", "LongerHeader"),
        listOf("LongerContent", "Short"),
      )
    val table = TableForTextPrinting(data)
    val expected =
      """
      |        Short LongerHeader
      |LongerContent        Short
      """.trimMargin()
    assertThat(table.print()).isEqualTo(expected)
  }
}
