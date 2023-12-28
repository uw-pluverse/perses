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

data class Fraction(val numerator: Int, val denominator: Int) {
  init {
    check(numerator >= 0) { "The numerator should be within [0,100]. $numerator" }
    check(denominator > 0) { "The denominator should be positive $denominator" }
    check(numerator <= denominator) {
      "The numerator cannot be greater than denominator: $numerator/$denominator"
    }
  }

  fun multiply(value: Int) = value * numerator / denominator

  companion object {
    @JvmStatic
    fun parse(string: String): Fraction {
      val separatorIndex = string.indexOf('/')
      if (separatorIndex < 0) {
        return Fraction(numerator = Integer.parseInt(string.trim()), denominator = 1)
      }
      val numerator = Integer.parseInt(string.substring(0, separatorIndex).trim())
      val denominator = Integer.parseInt(string.substring(separatorIndex + 1).trim())
      return Fraction(numerator, denominator)
    }
  }
}
