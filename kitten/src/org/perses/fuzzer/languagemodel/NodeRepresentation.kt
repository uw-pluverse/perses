/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.fuzzer.languagemodel

@JvmInline
value class NodeRepresentation @PublishedApi internal constructor(
  val longValue: Long,
) {

  override fun toString(): String {
    return buildString {
      append(NodeRepresentation::class.java.simpleName).append('(')
      append("nodeType=").append(nodeType).append(", ")
      append("featureValue=").append(featureValue)
      append(')')
    }
  }

  val nodeType: Int
    get() = longValue.ushr(32).toInt()

  val featureValue: Int
    // TODO: can we just simply downcast the long to an int?
    get() = longValue.and(0xFFFFL).toInt()

  companion object {
    fun create(nodeType: Int, featureValue: Int): NodeRepresentation {
      return NodeRepresentation(encodeToLong(nodeType, featureValue))
    }

    private fun encodeToLong(nodeType: Int, featureValue: Int): Long {
      return nodeType.toLong().shl(32).or(featureValue.toLong())
    }
  }
}
