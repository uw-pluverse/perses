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
package org.perses.grammar.flattokenlist

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.PnfCLexer

/**
 * The flat token list must carry the characters the underlying real lexer could not tokenize, in
 * source order -- otherwise the TopFormFlatReducer's reconstruction drops them, which silently breaks
 * a `\`-newline splice such as `st\<newline>atic` (the mutation in three unparseable splice
 * benchmarks) into two tokens the C preprocessor no longer rejoins.
 */
@RunWith(JUnit4::class)
class FlatTokenListLexerTest {

  private val facade = FlatTokenListParserFacade(PnfCLexer::class.java)

  private fun texts(code: String) = facade.tokenizeString(code).map { it.text }

  @Test
  fun anUnlexableBackslashSpliceIsKeptInTheFlatList() {
    assertThat(texts("st\\\natic")).containsExactly("st", "\\", "atic").inOrder()
  }

  @Test
  fun aStrayCharacterIsKeptBetweenItsNeighbours() {
    assertThat(texts("a@b")).containsExactly("a", "@", "b").inOrder()
  }

  @Test
  fun aLexableFileIsUnchanged() {
    assertThat(texts("int x = 1;")).containsExactly("int", "x", "=", "1", ";").inOrder()
  }
}
