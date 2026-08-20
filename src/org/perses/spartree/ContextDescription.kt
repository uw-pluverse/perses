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
package org.perses.spartree

import com.google.common.collect.ImmutableList

class ContextDescription(
  private val prefix: ContextDescription?,
  private val postfix: ImmutableList<String>,
) {
  fun pieces(): Sequence<String> =
    if (prefix == null) {
      postfix.asSequence()
    } else {
      prefix.pieces() + postfix.asSequence()
    }

  val string by lazy {
    buildString {
      append('[')
      pieces().joinTo(buffer = this, separator = ":")
      append(']')
    }
  }

  fun createByAppending(postfix: ImmutableList<String>): ContextDescription =
    ContextDescription(prefix = this, postfix = postfix)

  fun createByAppending(postfix: String): ContextDescription =
    createByAppending(postfix = ImmutableList.of(postfix))

  override fun toString(): String = string

  companion object {
    fun of(piece: String): ContextDescription =
      ContextDescription(prefix = null, ImmutableList.of(piece))

    fun of(pieces: ImmutableList<String>): ContextDescription =
      ContextDescription(prefix = null, postfix = pieces)

    fun copyOf(pieces: ImmutableList.Builder<String>): ContextDescription =
      ContextDescription(prefix = null, postfix = pieces.build())
  }
}
