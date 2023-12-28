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
package org.perses.antlr.ast

import com.google.common.base.Joiner
import com.google.common.collect.ImmutableList
import org.perses.util.ast.Indent
import java.io.PrintStream

abstract class AbstractPersesEnumAst protected constructor(
  private val enumName: String,
  private val values: ImmutableList<String>,
) : AbstractPersesAst() {

  init {
    require(values.toHashSet().size == values.size)
  }

  override fun getChild(index: Int): AbstractPersesAst {
    throw UnsupportedOperationException()
  }

  override fun toSourceCode(stream: PrintStream, indent: Indent, multiLineMode: Boolean) {
    if (values.isEmpty()) {
      return
    }
    stream.print(enumName)
    stream.print(" { ")
    stream.print(Joiner.on(", ").join(values))
    stream.print(" }")
    stream.print("\n")
  }

  final override val tag: AstTag?
    get() = null

  override val childCount: Int
    get() = 0
}
