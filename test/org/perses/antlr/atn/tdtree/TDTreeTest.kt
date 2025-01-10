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
package org.perses.antlr.atn.tdtree

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.antlr.atn.OrigCLexer

@RunWith(JUnit4::class)
class TDTreeTest {

  val tree = TDTree()
  private val cLexerWrapper = LexerAtnWrapper(OrigCLexer::class.java)

  @Test
  fun testToLexemeForCharNode() {
    val node = tree.createCharNode('a', allowedAsciiChars = ImmutableList.of())
    tree.root.addChild(node)
    assertThat(tree.toLexeme()).isEqualTo("a")
    assertThat(tree.toLexeme(blanketedNodes = setOf(node))).isEqualTo("")
  }

  @Test
  fun testGetCanonicalLexemeList() {
    val tokenType = cLexerWrapper.metaTokenInfoDB
      .getTokenInfoWithName("Constant")!!.tokenType
    val lexeme = "0xffull"
    val tree = cLexerWrapper.createTDTree(lexeme, tokenType)
    assertThat(tree.root.getCanonicalLexemeList(countLimitPerChar = 2))
      .containsExactlyElementsIn(
        listOf(
          "0Xffull",
          "0x0full",
          "0x1full",
          "0xf0ull",
          "0xf1ull",
          "0xffUll",
        ),
      )
  }
}
