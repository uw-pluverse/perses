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
package org.perses.grammar

import org.antlr.v4.runtime.ANTLRErrorListener
import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.RecognitionException
import org.antlr.v4.runtime.Recognizer
import org.antlr.v4.runtime.atn.ATNConfigSet
import org.antlr.v4.runtime.dfa.DFA
import org.perses.antlr.SyntaxError
import java.util.BitSet

/**
 * The tolerant counterpart of [FailOnErrorAntlrErrorListener]: instead of throwing on the first
 * syntax error, it records every error and lets ANTLR's [org.antlr.v4.runtime.DefaultErrorStrategy]
 * run its recovery to completion, so the caller gets the recovered parse tree plus the full list of
 * errors. This is what lets Perses build a tree for a syntactically invalid program.
 */
class CollectingAntlrErrorListener(
  private val sourceFile: String,
) : ANTLRErrorListener {
  private val mutableErrors = ArrayList<SyntaxError>()

  val errors: List<SyntaxError>
    get() = mutableErrors

  val hasError: Boolean
    get() = mutableErrors.isNotEmpty()

  override fun syntaxError(
    recognizer: Recognizer<*, *>?,
    offendingSymbol: Any?,
    line: Int,
    charPositionInLine: Int,
    msg: String?,
    e: RecognitionException?,
  ) {
    mutableErrors.add(SyntaxError(line, charPositionInLine, msg ?: "", offendingSymbol))
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
