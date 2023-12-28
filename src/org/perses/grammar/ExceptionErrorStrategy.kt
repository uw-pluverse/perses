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
package org.perses.grammar

import org.antlr.v4.runtime.DefaultErrorStrategy
import org.antlr.v4.runtime.InputMismatchException
import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.RecognitionException

/**
 * taken from stackoverflow: https://stackoverflow.com/questions/18132078/handling-errors-in-antlr4
 */
class ExceptionErrorStrategy : DefaultErrorStrategy() {
  override fun recover(recognizer: Parser?, e: RecognitionException?) {
    throw e!!
  }

  public override fun reportInputMismatch(recognizer: Parser, e: InputMismatchException) {
    val msg = buildString {
      append("mismatched input " + getTokenErrorDisplay(e.offendingToken))
      append('\n')
      append(" expecting one of ")
      append(e.expectedTokens.toString(recognizer.vocabulary))
    }
    val ex = RecognitionException(
      msg,
      recognizer,
      recognizer.inputStream,
      recognizer.context,
    )
    ex.initCause(e)
    throw ex
  }

  public override fun reportMissingToken(recognizer: Parser) {
    beginErrorCondition(recognizer)
    val t = recognizer.currentToken
    val expecting = getExpectedTokens(recognizer)
    val msg = buildString {
      append("missing ")
      append(expecting.toString(recognizer.vocabulary))
      append(" at ").append(getTokenErrorDisplay(t))
    }
    throw RecognitionException(
      msg,
      recognizer,
      recognizer.inputStream,
      recognizer.context,
    )
  }
}
