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

import com.google.common.base.MoreObjects
import com.google.common.base.Objects
import org.perses.util.Util.lazyAssert

abstract class AbstractEditOperation<T> {
  abstract val base: T?
  abstract val revision: T?

  fun toPair(): Pair<T?, T?> = Pair(base, revision)

  final override fun equals(other: Any?): Boolean {
    if (other == null) {
      return false
    }
    if (other.javaClass !== javaClass) {
      return false
    }
    val o = other as AbstractEditOperation<*>
    return base == o.base && revision == o.revision
  }

  final override fun hashCode(): Int {
    return Objects.hashCode(javaClass, base, revision)
  }

  final override fun toString(): String {
    return MoreObjects.toStringHelper(this)
      .add("base", base)
      .add("revision", revision)
      .toString()
  }

  class Insert<T>(override val revision: T) : AbstractEditOperation<T>() {
    override val base: T? = null
  }

  class Keep<T>(override val base: T) : AbstractEditOperation<T>() {
    override val revision = base
  }

  class Delete<T>(override val base: T) : AbstractEditOperation<T>() {
    override val revision: T? = null
  }

  class Replace<T>(override val base: T, override val revision: T) : AbstractEditOperation<T>() {
    init {
      lazyAssert { base != revision }
    }
  }
}
