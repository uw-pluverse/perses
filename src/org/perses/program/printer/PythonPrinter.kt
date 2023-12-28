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
package org.perses.program.printer

import org.perses.program.AbstractLazySourceCode
import org.perses.program.TokenizedProgram

class PythonPrinter private constructor(
  val keepBlankLines: Boolean,
  val tokenPositionProvider: AbstractTokenPositionProvider,
) :
  AbstractTokenizedProgramPrinter() {

  override fun print(
    program: TokenizedProgram,
    tokenPlacementListener: AbstractTokenPlacementListener?,
  ): AbstractLazySourceCode {
    return object : AbstractLazySourceCode() {
      override fun computeStringBuilder() =
        PythonFormatPrintingVisitor(
          program,
          keepBlankLines,
          numSpacesPerIndent = 4,
          tokenPositionProvider = tokenPositionProvider,
          tokenPlacementListener = tokenPlacementListener,
        ).visit().result
    }
  }

  override fun extraEquals(other: Any): Boolean {
    if (other !is PythonPrinter) {
      return false
    }
    return keepBlankLines == other.keepBlankLines
  }

  override fun extraHashCode(): Int {
    return keepBlankLines.hashCode()
  }

  companion object {
    fun getOrigFormat(tokenPositionProvider: AbstractTokenPositionProvider) =
      PythonPrinter(keepBlankLines = true, tokenPositionProvider)
    fun getCompactOrigFormat(tokenPositionProvider: AbstractTokenPositionProvider) =
      PythonPrinter(keepBlankLines = false, tokenPositionProvider)
  }
}
