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

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Token
import org.perses.antlr.AntlrGrammarUtil

/**
 * Wraps the [lexer] built by [lexerFactory] so the characters it cannot tokenize are captured instead
 * of silently skipped. It builds the lexer itself, drops the lexer's default error listeners -- which
 * a freshly built lexer carries and which would otherwise throw on the first un-lexable character (a
 * [org.perses.grammar.FailOnErrorAntlrErrorListener]) or spam stderr (a `ConsoleErrorListener`) -- and
 * attaches a [DroppedCharacterCollector], which records each un-lexable character and rewinds the
 * input so lexing resumes from the next one. Taking a factory rather than a prebuilt lexer keeps the
 * wrapper the sole owner: a lexer still wired to throw never escapes to the caller. This is the one
 * place in the codebase that sets up error-tolerant lexing; callers do not touch the listeners.
 *
 * What to DO with the dropped characters is left to the callsite, because it differs:
 *  - A real-grammar parser streams [lexer] and, after parsing, splices [droppedCharacters] into the
 *    finished tree by position -- the parser must never see them as tokens (its grammar has no rule
 *    for a stray `\` or `@`).
 *  - An adaptor grammar that accepts any token (Dyck's `OTHER*`, FlatTokenList's `TOKEN*`) instead
 *    merges them into the stream with [readAllDefaultChannelTokensWithDroppedCharacters].
 */
class ErrorTolerantLexer(
  lexerFactory: () -> Lexer,
) {
  val lexer: Lexer = lexerFactory()
  private val droppedCharacterCollector = DroppedCharacterCollector()

  init {
    lexer.removeErrorListeners()
    lexer.addErrorListener(droppedCharacterCollector)
  }

  /** The characters the lexer could not tokenize; populated as [lexer] is consumed. */
  val droppedCharacters: List<DroppedCharacter>
    get() = droppedCharacterCollector.dropped

  /**
   * Drains [lexer] and returns its default-channel tokens together with the dropped characters, each
   * mapped through the caller's adapter and ordered by source position. For adaptor lexers whose
   * grammar accepts any token directly in the stream.
   *
   * Both inputs are already sorted by source offset -- the lexer emits its tokens left to right, and
   * the collector appends each dropped character as lexing advances -- and their offsets are disjoint,
   * so this is a linear two-way merge rather than a concatenate-then-sort.
   */
  fun <T : Token> readAllDefaultChannelTokensWithDroppedCharacters(
    adaptToken: (Token) -> T,
    adaptDroppedCharacter: (DroppedCharacter) -> T,
  ): ImmutableList<T> {
    val realTokens = AntlrGrammarUtil.readAllTokensInDefaultChannel(lexer)
    val dropped = droppedCharacterCollector.dropped
    val merged = ImmutableList.builder<T>()
    var i = 0
    var j = 0
    while (i < realTokens.size && j < dropped.size) {
      if (realTokens[i].startIndex < dropped[j].charIndex) {
        merged.add(adaptToken(realTokens[i++]))
      } else {
        merged.add(adaptDroppedCharacter(dropped[j++]))
      }
    }
    while (i < realTokens.size) merged.add(adaptToken(realTokens[i++]))
    while (j < dropped.size) merged.add(adaptDroppedCharacter(dropped[j++]))
    return merged.build()
  }
}
