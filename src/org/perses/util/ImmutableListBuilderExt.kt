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

/**
 * An [ImmutableList.Builder] that also tracks how many elements it holds.
 *
 * Guava's builder does not expose its element count, so callers that need to know whether anything
 * has been added -- or how much -- end up keeping a parallel counter and updating it at every call
 * site, which is easy to get out of sync. This keeps the count next to the builder it describes.
 */
class ImmutableListBuilderExt<T : Any> {
  private val builder = ImmutableList.builder<T>()

  var size: Int = 0
    private set

  fun isEmpty(): Boolean = size == 0

  fun isNotEmpty(): Boolean = size > 0

  fun add(element: T): ImmutableListBuilderExt<T> {
    builder.add(element)
    ++size
    return this
  }

  fun addAll(elements: Iterable<T>): ImmutableListBuilderExt<T> {
    elements.forEach { add(it) }
    return this
  }

  fun build(): ImmutableList<T> = builder.build()
}
