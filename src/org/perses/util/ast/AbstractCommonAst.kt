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
package org.perses.util.ast

import java.io.ByteArrayOutputStream
import java.io.PrintStream
import java.nio.charset.StandardCharsets

abstract class AbstractCommonAst<Self : AbstractCommonAst<Self>> :
  Comparable<Self> {

  val sourceCode: String by lazy {
    val baos = ByteArrayOutputStream()
    PrintStream(baos, true, StandardCharsets.UTF_8.name()).use {
      toSourceCode(
        it,
        Indent.createEmptyIndent(numOfSpacesPerIndent = INDENT_INCREAMENT),
        multiLineMode = true,
      )
    }
    baos.toString()
  }

  abstract val precedence: IPrecedence

  protected open val extraLabelForTreeStructurePrinting: String
    get() = ""
  abstract val childCount: Int

  abstract fun toSourceCode(stream: PrintStream, indent: Indent, multiLineMode: Boolean)

  fun printTreeStructure(): String {
    val baos = ByteArrayOutputStream()
    PrintStream(baos, true, StandardCharsets.UTF_8.name()).use {
      printTreeStructure(it, Indent.FOUR_CHAR_EMPTY_INDENT)
    }
    return baos.toString()
  }

  fun printTreeStructure(stream: PrintStream, indent: Indent) {
    indent.printIndent(stream)
      .append(javaClass.simpleName)
      .append(" ")
      .append(extraLabelForTreeStructurePrinting)
      .print('\n')
    val newIndent = indent.increasedIndent
    foreachChild {
      it.printTreeStructure(stream, newIndent)
    }
  }

  abstract fun getChild(index: Int): Self

  inline fun foreachChild(consumer: (Self) -> Unit) {
    var i = 0
    val size = childCount
    while (i < size) {
      consumer(getChild(i))
      ++i
    }
  }

  override fun compareTo(other: Self): Int {
    return sourceCode.compareTo(other.sourceCode)
  }

  companion object {
    @JvmStatic
    protected val INDENT_INCREAMENT = 4
  }
}
