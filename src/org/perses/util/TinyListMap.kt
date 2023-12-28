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

class TinyListMap<K, V> {

  private val entries = ArrayList<Entry<K, V>>(2)

  fun size() = entries.size

  fun get(key: K): V? {
    for (entry in entries) {
      if (entry.key == key) {
        return entry.value
      }
    }
    return null
  }

  fun putOrThrowIfPresent(key: K, value: V) {
    check(get(key) == null)
    entries.add(Entry(key, value))
  }

  fun asSequence() = entries.asSequence()

  data class Entry<K, V>(val key: K, val value: V)
}
