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
package org.perses.listminimizer

import com.google.common.collect.ImmutableList

abstract class AbstractConfigCache<T : Any> {
  abstract fun add(config: ImmutableList<ElementWrapper<T>>)

  abstract fun contains(config: ImmutableList<ElementWrapper<T>>): Boolean

  abstract fun refreshAndUpdateBest(newBest: ImmutableList<ElementWrapper<T>>)
}

class NullConfigCache<T : Any> : AbstractConfigCache<T>() {
  override fun add(config: ImmutableList<ElementWrapper<T>>) {}

  override fun contains(config: ImmutableList<ElementWrapper<T>>): Boolean = false

  override fun refreshAndUpdateBest(newBest: ImmutableList<ElementWrapper<T>>) {}
}

class ConfigCache<T : Any> : AbstractConfigCache<T>() {
  private val cache = HashSet<ImmutableList<ElementWrapper<T>>>()

  val size: Int
    get() = cache.size

  override fun add(config: ImmutableList<ElementWrapper<T>>) {
    check(
      !cache.contains(config),
    ) { "A cache item was created before. This is unexpected." }
    cache.add(config)
  }

  override fun contains(config: ImmutableList<ElementWrapper<T>>): Boolean = cache.contains(config)

  override fun refreshAndUpdateBest(newBest: ImmutableList<ElementWrapper<T>>) {
    val newSize = newBest.size
    cache.removeIf { it.size >= newSize }
  }
}
