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
package org.perses.grammar.c

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.ParseErrorHandling

/**
 * Covers [org.perses.grammar.DroppedCharacterCollector] through the tolerant parse: it drops exactly
 * ONE character per LexerNoViableAlt (the one at startIndex) and rewinds so the lexer re-lexes
 * whatever the failed match speculatively consumed past it. The dropped run is therefore always a
 * single character and can never carry a newline -- which is what keeps a `\`-newline splice from
 * being doubled on reconstruction. Observed via the leaves the tolerant parse splices the dropped
 * characters back in as.
 */
@RunWith(JUnit4::class)
class DroppedCharacterCollectorTest {

  private val facade = PnfCParserFacade()

  /** Every leaf of the tolerant parse tree, including the dropped-character leaves, in order. */
  private fun leaves(input: String): List<String> =
    TestUtility.extractTokenTexts(
      facade.parseString(input, errorMode = ParseErrorHandling.TOLERANT).tree,
    )

  @Test
  fun aStrayCharacterIsDroppedAsASingleCharacterLeaf() {
    assertThat(leaves("int a;@ int b;")).contains("@")
  }

  @Test
  fun consecutiveUnlexableCharactersBecomeSeparateSingleCharacterLeaves() {
    val at = leaves("a @@@ b").filter { it.contains("@") }
    assertThat(at).containsExactly("@", "@", "@")
  }

  @Test
  fun aBackslashIsDroppedAloneAndTheNewlineIsReLexedNotSwallowed() {
    // The old behavior produced a "\\\n" leaf (backslash + the newline the universal-character-name
    // rule speculatively consumed). Now the backslash is dropped alone and the newline is re-lexed as
    // line structure, so it is a plain "\" leaf and the second line's tokens still appear.
    val leaves = leaves("int a;\\\nint b;")
    assertThat(leaves).contains("\\")
    assertThat(leaves).containsAtLeast("int", "b", ";").inOrder()
  }

  @Test
  fun noLeafEverContainsANewline() {
    // The invariant that makes the fix robust regardless of grammar: a single-character drop can
    // never straddle a line boundary, so the printer's line-structure newline is never doubled.
    for (input in listOf("a\\\nb", "x\\\n\\\ny", "p;@\nq", "\\\n", "int a;@ int b;")) {
      assertThat(leaves(input).any { it.contains("\n") }).isFalse()
    }
  }
}
