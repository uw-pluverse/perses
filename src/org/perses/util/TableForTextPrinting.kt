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

import com.google.common.base.Strings

class TableForTextPrinting(
  val data: List<List<String>>,
  val columnSeparator: String = " ",
) {
  init {
    require(data.isNotEmpty())
    val sizeOfFirstRow = data.first().size
    data.forEach { require(it.size == sizeOfFirstRow) { it } }
  }

  private val maxLengthPerColumn =
    data.first().withIndex().map { (index, _) ->
      data.maxOf { it[index].length }
    }

  fun print(): String =
    data.joinToString(separator = "\n") { row ->
      row.withIndex().joinToString(separator = columnSeparator) { (columnIndex, cell) ->
        val maxColumnLength = maxLengthPerColumn[columnIndex]
        Strings.padStart(cell, maxColumnLength, ' ')
      }
    }
}
