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
import org.perses.util.Util.lazyAssert

abstract class AbstractOrigFormatVisitor(
  val program: TokenizedProgram,
  protected val tokenPositionProvider: AbstractTokenPositionProvider,
  protected val tokenPlacementListener: AbstractTokenPlacementListener?,
) {

  abstract fun isControlToken(token: PersesToken): Boolean

  abstract fun visitControlToken(token: PersesToken)

  abstract fun visitLine(line: List<PersesToken>)

  protected open fun onVisitEnd() {}

  val result = FastStringBuilder(capacity = program.tokenCount() * 5)

  fun visit(): AbstractOrigFormatVisitor {
    val tokens = program.tokens
    val tokenCount = tokens.size
    var currentLineNumber = 1
    val currentLine = ArrayList<PersesToken>()

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
      val lineNo = tokenPositionProvider.getLine(token)
      lazyAssert { lineNo > 0 }
      lazyAssert { currentLineNumber <= lineNo }
      if (currentLineNumber == lineNo) {
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
