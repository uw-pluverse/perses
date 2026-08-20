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
import org.antlr.v4.runtime.CharStream
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.LexerNoViableAltException
import org.antlr.v4.runtime.Parser
import org.antlr.v4.runtime.RecognitionException
import org.antlr.v4.runtime.Recognizer
import org.antlr.v4.runtime.atn.ATNConfigSet
import org.antlr.v4.runtime.dfa.DFA
import org.antlr.v4.runtime.misc.Interval
import java.util.BitSet

/**
 * A single input character the lexer could not match, dropped during error recovery. [charIndex] is
 * its offset and [text] is that one character.
 */
class DroppedCharacter(
  val charIndex: Int,
  val line: Int,
  val column: Int,
  val text: String,
)

/**
 * Records the characters the lexer drops on a [LexerNoViableAltException], one character per event.
 *
 * Each event drops exactly ONE character -- the one at [LexerNoViableAltException.getStartIndex],
 * where the lexer found no viable token. [syntaxError] rewinds the input to `startIndex` so ANTLR's
 * recovery consumes just that character and the lexer re-lexes from the next one; anything the failed
 * match speculatively consumed past `startIndex` is thus re-lexed, not dropped.
 *
 * The rule is grammar-agnostic (drop the offending char, retry from the next), but its effect on a
 * multi-character un-lexable sequence depends on the grammar, because the tail is re-lexed with the
 * normal rules. Two consequences worth knowing:
 *  - Good: the dropped run is always a single character, so it can never itself carry a `\n`. That is
 *    what fixes the `\`-newline line splice -- the newline is re-lexed as ordinary line structure
 *    (one newline, not the two the old multi-character run produced), so reconstruction round-trips.
 *  - Accepted cost: a partial keyword match is re-lexed into that keyword. E.g. `#if ` (a failed
 *    `#define` match consuming `#if`) becomes `#` dropped + the `if` keyword, and `#else` becomes `#`
 *    + the `else` keyword, rather than being dropped as one unit. The tolerant spar-tree goldens
 *    reflect this. (The alternative -- dropping the whole consumed span -- is not robust: a span that
 *    consumes through a `\n` would end in `\n` and reintroduce the doubled-newline bug.)
 *
 * The dropped characters are deliberately *not* re-injected into the token stream: doing so makes the
 * parser treat them as errors and mangles the surrounding structure. Instead they are spliced back
 * into the finished parse tree by position (see the tolerant parse path in [AbstractParserFacade]),
 * so the parser sees a clean stream and the dropped characters still become leaves.
 */
class DroppedCharacterCollector : ANTLRErrorListener {
  private val mutableDropped = ArrayList<DroppedCharacter>()

  val dropped: List<DroppedCharacter>
    get() = mutableDropped

  override fun syntaxError(
    recognizer: Recognizer<*, *>?,
    offendingSymbol: Any?,
    line: Int,
    charPositionInLine: Int,
    msg: String?,
    e: RecognitionException?,
  ) {
    if (recognizer !is Lexer || e !is LexerNoViableAltException) {
      return
    }
    val input = recognizer.inputStream as CharStream
    val startIndex = e.startIndex
    if (startIndex < 0 || startIndex >= input.size()) {
      return
    }
    mutableDropped.add(
      DroppedCharacter(
        charIndex = startIndex,
        line = line,
        column = charPositionInLine,
        text = input.getText(Interval.of(startIndex, startIndex)),
      ),
    )
    // Rewind so ANTLR's recovery drops only startIndex and re-lexes whatever the failed match
    // speculatively consumed past it. Recovery (Lexer.recover) consumes one char from here.
    input.seek(startIndex)
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
