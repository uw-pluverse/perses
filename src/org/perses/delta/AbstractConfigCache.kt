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
package org.perses.delta

import com.google.common.collect.ImmutableList

abstract class AbstractConfigCache<T> {

  abstract fun add(config: ConfigurationBasedOnElementSystemIdentity)

  abstract fun contains(config: ConfigurationBasedOnElementSystemIdentity): Boolean

  abstract fun deleteStaleConfigs(newSize: Int)
}

class NullConfigCache<T> : AbstractConfigCache<T>() {

  override fun add(config: ConfigurationBasedOnElementSystemIdentity) {}

  override fun contains(config: ConfigurationBasedOnElementSystemIdentity): Boolean {
    return false
  }

  override fun deleteStaleConfigs(newSize: Int) {}
}

class ConfigCache<T>(
  private val enableRefresh: Boolean = false,
) : AbstractConfigCache<T>() {

  private val cache = HashSet<ConfigurationBasedOnElementSystemIdentity>()

  val size: Int
    get() = cache.size

  override fun add(config: ConfigurationBasedOnElementSystemIdentity) {
    check(!cache.contains(config)) { "A cache item was created before. This is unexpected." }
    cache.add(config)
  }

  override fun contains(config: ConfigurationBasedOnElementSystemIdentity): Boolean {
    return cache.contains(config)
  }

  override fun deleteStaleConfigs(newSize: Int) {
    if (!enableRefresh) {
      return
    }
    val cacheIterator = cache.iterator()
    while (cacheIterator.hasNext()) {
      val config = cacheIterator.next()
      if (config.size >= newSize) {
        cacheIterator.remove()
      }
    }
  }
}

data class ConfigurationBasedOnElementSystemIdentity(
  private val configList: ImmutableList<*>,
) {

  val size: Int
    get() = configList.size

  private val hashcode = configList.let { list ->
    var result = 17
    list.forEach { result = 31 * result + System.identityHashCode(it) }
    result
  }

  override fun hashCode(): Int {
    return hashcode
  }

  override fun equals(other: Any?): Boolean {
    if (this === other) return true
    if (other == null || javaClass != other.javaClass) {
      return false
    }
    other as ConfigurationBasedOnElementSystemIdentity
    val size = configList.size
    if (size != other.configList.size) return false
    // Referential equality
    for (i in 0 until size) {
      if (configList[i] !== other.configList[i]) {
        return false
      }
    }
    return true
  }
}
