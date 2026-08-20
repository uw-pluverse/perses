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
package org.perses.reduction.reducer.latra.language

import org.perses.util.ast.Indent
import java.io.PrintStream

abstract class AbstractPatternClause(
  val pattern: AbstractLatraPattern,
) : AbstractLatraAst() {
  override fun hashCode(): Int = this.pattern.hashCode() * 31 + this::class.hashCode()

  override fun equals(other: Any?): Boolean {
    if (this === other) {
      return true
    }
    if (javaClass != other?.javaClass) {
      return false
    }
    return (other as AbstractPatternClause).pattern == pattern
  }

  override val childCount: Int
    get() = 0

  override fun getChild(index: Int): AbstractLatraAst {
    error("Unexpected child at index $index in $this")
  }

  override fun toSourceCode(
    stream: PrintStream,
    indent: Indent,
    multiLineMode: Boolean,
  ) {
    stream.print(pattern.originalSourceCode)
  }
}
