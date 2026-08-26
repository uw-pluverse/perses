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

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList

object StringUtil {
  @JvmStatic
  fun computePercentage(
    numerator: Int,
    denominator: Int,
    prefix: String = "$numerator/$denominator=",
  ): String {
    val percentageValue = numerator * 100.0 / denominator
    if (percentageValue < 0.000000000001) {
      return prefix + "0.00%"
    }
    val string = String.format("%.30f%%", percentageValue)
    val length = string.length
    var places: Int = 2
    if (percentageValue >= 1) {
      return prefix + printDecimalWithPlaces(percentageValue, places)
    }
    val dotIndex = string.indexOf('.')
    if (dotIndex > 0) {
      // adjust the places
      var indexOfFirstZero = dotIndex + 1
      while (indexOfFirstZero < length) {
        if (string[indexOfFirstZero] != '0') {
          break
        }
        ++indexOfFirstZero
      }
      if (indexOfFirstZero < length && indexOfFirstZero - dotIndex > places) {
        places = indexOfFirstZero - dotIndex + 1
      }
    }
    return prefix + printDecimalWithPlaces(percentageValue, places)
  }

  private fun printDecimalWithPlaces(
    value: Double,
    places: Int,
  ): String = String.format("%.${places}f%%", value)

  fun hasWhitespace(string: String): Boolean {
    val length = string.length
    for (i in 0 until length) {
      val c = string[i]
      if (Character.isWhitespace(c)) {
        return true
      }
    }
    return false
  }

  data class UtfChar(
    val char: Char,
    val indexInString: Int,
  ) {
    override fun toString(): String =
      MoreObjects
        .toStringHelper(this)
        .add("char", char)
        .add("code", char.code)
        .add("index_in_string", indexInString)
        .toString()
  }

  fun findUtf16Chars(string: String): ImmutableList<UtfChar> =
    string.toCharArray().withIndex().filter { it.value.code > 255 }.transformToImmutableList {
      UtfChar(char = it.value, indexInString = it.index)
    }

  fun extractNonBlankLinesAndTrim(string: String): List<String> =
    string
      .lines()
      .map {
        it.trim()
      }.filter { it.isNotBlank() }
}
