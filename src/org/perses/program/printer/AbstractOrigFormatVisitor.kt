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
package org.perses.program.printer

import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram
import org.perses.program.printer.AbstractTokenizedProgramPrinter.AbstractTokenPlacementListener
import org.perses.program.printer.AbstractTokenizedProgramPrinter.AbstractTokenPositionProvider
import org.perses.util.FastStringBuilder

abstract class AbstractOrigFormatVisitor(
  val program: TokenizedProgram,
  protected val tokenPositionProvider: AbstractTokenPositionProvider,
  protected val tokenPlacementListener: AbstractTokenPlacementListener?,
) {
  abstract fun isControlToken(token: PersesTokenFactory.AbstractPersesToken): Boolean

  abstract fun visitControlToken(token: PersesTokenFactory.AbstractPersesToken)

  abstract fun visitLine(line: List<PersesTokenFactory.AbstractPersesToken>)

  protected open fun onVisitEnd() {}

  val result = FastStringBuilder(capacity = program.tokenCount * 5)

  fun visit(): AbstractOrigFormatVisitor {
    val tokens = program.tokens
    val tokenCount = tokens.size
    var currentLineNumber = 1
    val currentLine = ArrayList<PersesTokenFactory.AbstractPersesToken>()

    for (i in 0..tokenCount) {
      if (i == tokenCount) {
        visitLine(currentLine)
        currentLine.clear()
        break
      }
      val token = tokens[i]
      if (isControlToken(token)) {
        visitControlToken(token)
        visitLine(currentLine)
        currentLine.clear()
        continue
      }
      val lineNo =
        if (token is PersesTokenFactory.PersesAntlrToken) {
          tokenPositionProvider.getLine(token)
        } else {
          currentLineNumber
        }
      if (currentLineNumber == lineNo) {
        /*
         * A token might be on a lower lines due to token insertion. Then we do not assume it is
         * on the current line, but assume it starts a new line.
         */
        currentLine.add(token)
      } else {
        visitLine(currentLine)
        currentLineNumber = lineNo
        currentLine.clear()
        currentLine.add(token)
      }
    }
    onVisitEnd()
    return this
  }
}
