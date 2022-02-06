/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.delta

import com.google.common.collect.ImmutableList

class Partition<T>(
  private val baseList: ImmutableList<T>,
  private val startIndex: Int,
  private val endIndexExclusive: Int
) {

  fun toList() = baseList.subList(startIndex, endIndexExclusive)

  fun computeComplement(): ImmutableList<T> {
    val result = ImmutableList.builder<T>()
    for (i in 0 until startIndex) {
      result.add(baseList.get(i))
    }
    for (i in endIndexExclusive until baseList.size) {
      result.add(baseList.get(i))
    }
    return result.build()
  }

  init {
    require(startIndex < endIndexExclusive)
  }
}
