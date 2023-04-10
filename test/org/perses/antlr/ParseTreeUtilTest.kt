/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.antlr

import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.CharStreams
import org.antlr.v4.runtime.CommonTokenStream
import org.antlr.v4.runtime.ParserInterpreter
import org.antlr.v4.runtime.tree.ParseTree
import org.antlr.v4.runtime.tree.RuleNode
import org.antlr.v4.runtime.tree.TerminalNode
import org.antlr.v4.tool.Grammar
import org.antlr.v4.tool.LexerGrammar
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.ParseTreeUtil.getRuleName
import org.perses.antlr.ParseTreeUtil.getTokenName

@RunWith(JUnit4::class)
class ParseTreeUtilTest {

  @Test
  fun test() {
    val lexerGrammar = LexerGrammar(
      """
          lexer grammar L;
          A : 'a' ;
          B : 'b' ;
          C : 'c' ;
          D : 'd' ;
      """.trimIndent(),
    )
    val parserGrammar = Grammar(
      """
      parser grammar T;
      start : other C ;
      other: (A|B)* d ;
      d: 'd' ;
      """.trimIndent(),
      lexerGrammar,
    )
    val lexEngine = lexerGrammar.createLexerInterpreter(CharStreams.fromString("a b d c"))
    val tokens = CommonTokenStream(lexEngine)
    val parser: ParserInterpreter = parserGrammar.createParserInterpreter(tokens)
    val tree: ParseTree = parser.parse(parserGrammar.rules.get("start")!!.index)
    println(tree)

    val ruleNodeStart = tree as RuleNode

    assertThat(ruleNodeStart.childCount).isEqualTo(2)
    val ruleNodeOther = tree.getChild(0) as RuleNode
    val tokenNodeC = tree.getChild(1) as TerminalNode

    assertThat(ruleNodeOther.childCount).isEqualTo(3)
    val tokenNodeA = ruleNodeOther.getChild(0) as TerminalNode
    val tokenNodeB = ruleNodeOther.getChild(1) as TerminalNode
    val ruleNodeD = ruleNodeOther.getChild(2) as RuleNode

    assertThat(ruleNodeD.childCount).isEqualTo(1)
    val tokenNodeD = ruleNodeD.getChild(0) as TerminalNode

    assertThat(getRuleName(ruleNodeStart, parser)).isEqualTo("start")
    assertThat(getRuleName(ruleNodeOther, parser)).isEqualTo("other")
    assertThat(getRuleName(ruleNodeD, parser)).isEqualTo("d")

    assertThat(getTokenName(tokenNodeA, lexEngine)).isEqualTo("A")
    assertThat(getTokenName(tokenNodeB, lexEngine)).isEqualTo("B")
    assertThat(getTokenName(tokenNodeC, lexEngine)).isEqualTo("C")
    assertThat(getTokenName(tokenNodeD, lexEngine)).isEqualTo("D")

    assertThat(getTokenName(tokenNodeA.symbol, lexEngine)).isEqualTo("A")
  }
}
