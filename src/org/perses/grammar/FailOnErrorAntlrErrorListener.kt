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

import org.antlr.v4.runtime.ANTLRErrorListener
import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.RecognitionException
import org.antlr.v4.runtime.Recognizer
import org.antlr.v4.runtime.atn.ATNConfigSet
import org.antlr.v4.runtime.dfa.DFA
import java.lang.StringBuilder
import java.util.BitSet

class FailOnErrorAntlrErrorListener(private val sourceFile: String) : ANTLRErrorListener {
  override fun syntaxError(
    recognizer: Recognizer<*, *>?,
    offendingSymbol: Any?,
    line: Int,
    charPositionInLine: Int,
    msg: String?,
    e: RecognitionException?,
  ) {
    val details = StringBuilder()
    details.append("recognizer: ").append(recognizer).append('\n')
    details.append("offendingSymbol: ").append(offendingSymbol).append('\n')
    details.append("line: ").append(line).append('\n')
    details.append("column: ").append(charPositionInLine).append('\n')
    details.append("msg: ").append(msg).append('\n')
    throw AntlrFailureException(e!!, sourceFile, details.toString())
  }

  override fun reportAmbiguity(
    parser: Parser?,
    dfa: DFA?,
    i: Int,
    i1: Int,
    b: Boolean,
    bitSet: BitSet?,
    atnConfigSet: ATNConfigSet?,
  ) {
  }

  override fun reportAttemptingFullContext(
    parser: Parser?,
    dfa: DFA?,
    i: Int,
    i1: Int,
    bitSet: BitSet?,
    atnConfigSet: ATNConfigSet?,
  ) {
  }

  override fun reportContextSensitivity(
    parser: Parser?,
    dfa: DFA?,
    i: Int,
    i1: Int,
    i2: Int,
    atnConfigSet: ATNConfigSet?,
  ) {
  }
}
