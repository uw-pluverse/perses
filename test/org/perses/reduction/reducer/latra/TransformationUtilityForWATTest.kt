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
package org.perses.reduction.reducer.latra

import com.google.common.truth.Truth.assertThat
import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.wasm.WebAssemblyParserFacade
import org.perses.reduction.reducer.latra.language.AbstractLatraPattern
import org.perses.reduction.reducer.latra.language.AbstractPatternElement
import org.perses.spartree.AbstractTreeNode
import org.perses.util.toImmutableList
import org.perses.util.transformToImmutableList

@RunWith(JUnit4::class)
class TransformationUtilityForWATTest {
  private val inputString =
    """
          (module
            (func ${'$'}add_two_numbers (param ${'$'}a i32) (param ${'$'}b i32) (result i32)
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
              (i32.add (local.get ${'$'}a) (local.get ${'$'}b))
            )
          )
    """
  private val facade = WebAssemblyParserFacade()
  private val tree =
    TestUtility.createSparTreeFromString(inputString, facade, simplifyTree = false)

  val allTokens = tree.leafNodeSequence().toList()
  val leftParenOfFunc =
    allTokens
      .filter { it.token.lexemeText == "(" }
      .drop(1)
      .first()
  val funcToken = allTokens.first { it.token.lexemeText == "func" }
  val funcNode = AbstractTreeNode.findLowestAncestor(listOf(leftParenOfFunc, funcToken))
  val tokens = funcNode.leafNodeSequence().transformToImmutableList { it.asLexerRule() }

  @Ignore("TODO(cnsun): this needs to be fixed with a better matching algorithm.")
  @Test
  fun testMatchTokensToPatternNotSupportedYet() {
    val patternContent = """
        ( func :[funcName] :[args+] ( result :[return_type])
          :[body+]
        )
      """
    val pattern =
      AbstractLatraPattern.parseMatchingPattern(
        patternContent,
        facade,
      )
    val result = TransformationUtility.matchTokensToPattern(pattern, tokens)
    assertThat(result).isInstanceOf(TransformationUtility.PatternMatchingResult.Match::class.java)
  }

  @Test
  fun testMatchTokensToPattern() {
    val patternElements =
      AbstractLatraPattern.parseMatchingPattern(
        """
        ( func :[funcName] (param :[argName1] :[argType1]) (param :[argName2] :[argType2]) 
          (result :[return_type])
          :[body+]
        )
      """,
        facade,
      )

    assertThat(tokens[0].token.lexemeText).isEqualTo("(")
    assertThat(tokens[1].token.lexemeText).isEqualTo("func")
    assertThat(tokens.joinToString { it.token.lexemeText }).contains("local.get")

    val result =
      TransformationUtility.matchTokensToPattern(
        pattern = patternElements,
        tokens = tokens,
      )
    assertThat(result).isInstanceOf(TransformationUtility.PatternMatchingResult.Match::class.java)
    val matchResult = result as TransformationUtility.PatternMatchingResult.Match
    val bindingOfBody = matchResult.holeBindings[AbstractPatternElement.Hole.HoleName(("body"))]!!
    bindingOfBody
      .flatMap { it.leafNodeSequence() }
      .map { it.token.lexemeText }
      .toImmutableList()
      .let { tokens ->
        assertThat(tokens).hasSize(44)
      }
  }
}
