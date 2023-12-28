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

import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgram
import org.perses.program.printer.AbstractTokenizedProgramPrinter.AbstractTokenPlacementListener
import org.perses.program.printer.AbstractTokenizedProgramPrinter.AbstractTokenPositionProvider
import org.perses.util.FastStringBuilder

open class OrigFormatPrintingVisitor(
  program: TokenizedProgram,
  keepBlankLines: Boolean,
  tokenPositionProvider: AbstractTokenPositionProvider,
  tokenPlacementListener: AbstractTokenPlacementListener?,
) : AbstractOrigFormatPrintingVisitor(
  program,
  keepBlankLines,
  tokenPositionProvider,
  tokenPlacementListener,
) {

  override fun isControlToken(token: PersesToken) = false

  override fun visitControlToken(token: PersesToken) {
    // Do nothing.
  }

  override fun printNonEmptyLine(line: List<PersesToken>, builder: FastStringBuilder) {
    printNonEmptyLine(
      startPositionInLine = 0,
      line = line,
      builder = builder,
    )
  }
}
