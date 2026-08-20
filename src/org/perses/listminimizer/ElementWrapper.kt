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

import com.google.common.base.MoreObjects

/**
 * We intentionally use the original hashcode and equals of the class for identity-based
 * equality.
 */
class ElementWrapper<out T : Any>(
  override val index: Int,
  val element: T,
  var elementPayload: Any,
) : Comparable<IWithIndex>,
  IWithIndex {
  // If it is marked as deleted, then it is deleted. Otherwise, it might be deleted without
  // being marked.
  var deleted: Boolean = false
    private set

  fun markAsDeleted() {
    deleted = true
  }

  override fun compareTo(other: IWithIndex): Int = index.compareTo(other.index)

  override fun toString(): String =
    MoreObjects
      .toStringHelper(this)
      .add("index", index)
      .add("element", element::class.qualifiedName)
      .add("payload", elementPayload::class.qualifiedName)
      .toString()
}

interface IWithIndex {
  val index: Int
}
