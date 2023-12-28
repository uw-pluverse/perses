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
package org.perses.antlr.atn

import com.google.common.truth.Truth.assertThat
import objectexplorer.MemoryMeasurer
import org.junit.Assert
import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.toTokenType
import org.perses.util.Util

@RunWith(JUnit4::class)
class LexerAtnWrapperTest {

  val c = LexerAtnWrapper(OrigCLexer::class.java)
  val test = LexerAtnWrapper(TestLexer::class.java)

  @Test
  fun test() {
    c.metaTokenInfoDB.asSequence()
      .zip(c.metaTokenInfoDB.asSequence()).forEach { (first, second) ->
        println("$first, $second")
        try {
          c.canBeConcatWithoutSpace(first.tokenType, second.tokenType)
        } catch (e: Throwable) {
          Assert.fail(
            buildString {
              appendLine("processing $first, $second")
              appendLine("Exception message: ${e.message}")
              appendLine("Stack trace:")
              appendLine(e.stackTraceToString())
            },
          )
        }
      }
    val klasses = HashSet<Class<*>>()
    val bytes = MemoryMeasurer.measureBytes(c) {
      val klass = it::class.java
      klasses.add(klass)
      true
    }.toInt()
    klasses.sortedBy { it.canonicalName }.forEach { println(it) }
    assertThat(bytes).isLessThan(Util.SpaceSize.megaBytes(11).bytes)
  }

  @Ignore("The current algorithm does not handle non-greedy matching.")
  @Test
  fun testBlockCommentWithBlockComment() {
    val tokenType = OrigCLexer.BlockComment.toTokenType()
    assertThat(c.canBeConcatWithoutSpace(tokenType, tokenType)).isTrue()
  }

  @Ignore
  @Test
  fun testCanBeSubsumedForNonGreedyMatching() {
    val nfa = test.copyTokenNfa(TestLexer.GreedyWildcard.toTokenType())
    println(nfa.printTopology())
    val nfa2 = test.copyTokenNfa(TestLexer.NonGreedyWildcard.toTokenType())
    println(nfa2.printTopology())
    Assert.fail()
  }

  @Test
  fun testIdWithId() {
    val tokenType = OrigCLexer.Identifier.toTokenType()
    assertThat(c.canBeConcatWithoutSpace(tokenType, tokenType)).isFalse()
  }
}
