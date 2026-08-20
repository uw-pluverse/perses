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
package org.perses.reduction.reducer.trec

import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.CommonToken
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.ReducerFunctionalTestUtility

@RunWith(JUnit4::class)
class TokenCanonicalizerTest {
  @Test
  fun testBuildTDTree() {
    ReducerFunctionalTestUtility(
      reductionFolder = "test/org/perses/benchmark_toys/wasm/",
      testScript = "r.sh",
      sourceFile = "t.wat",
      reducerAnnotation = TokenCanonicalizer.META,
    ).use {
      val driver = it.reductionDriver
      val reducer =
        driver
          .createMainReducerCreator()
          .create(it.reducerContext)
          .single() as TokenCanonicalizer
      assertThat(reducer.reducerAnnotation).isSameInstanceAs(TokenCanonicalizer.META)
      val floatToken =
        it.reducerContext.configuration.canonicalParserFacade.transformLiteralIntoSingleToken(
          "0.9",
        )
      val intToken =
        it.reducerContext.configuration.canonicalParserFacade.transformLiteralIntoSingleToken(
          "0",
        )
      assertThat(floatToken.type).isNotEqualTo(intToken.type)
      val tdTree =
        reducer.buildTDTree(
          it.sparTree.sparTreeNodeFactory.createLexerRuleSparTreeNodeForAntlrToken(
            CommonToken(floatToken.type, intToken.text),
            overridingPosition = null,
          ),
        )
      assertThat(tdTree.toLexeme()).isEqualTo(intToken.text)
    }
  }

  @Test
  fun testConversionBetweenIndexAndId0() {
    val index = 0
    val id = TokenCanonicalizer.convertIndexToId(index, baseChar = 'a')
    assertThat(id).isEqualTo("a")
  }

  @Test
  fun testConversionBetweenIndexAndId1() {
    val index = 10
    val id = TokenCanonicalizer.convertIndexToId(index, baseChar = 'a')
    assertThat(id).isEqualTo("k")
  }

  @Test
  fun testConversionBetweenIndexAndId2() {
    val index = 100
    val id = TokenCanonicalizer.convertIndexToId(index, baseChar = 'a')
    assertThat(id).isEqualTo("dw")
  }

  @Test
  fun testConversionBetweenIndexAndUpperCaseId0() {
    assertThat(TokenCanonicalizer.convertIndexToId(index = 0, baseChar = 'A')).isEqualTo("A")
  }

  @Test
  fun testConversionBetweenIndexAndUpperCaseId1() {
    assertThat(TokenCanonicalizer.convertIndexToId(index = 10, baseChar = 'A')).isEqualTo("K")
  }

  @Test
  fun testConversionBetweenIndexAndUpperCaseId2() {
    assertThat(TokenCanonicalizer.convertIndexToId(index = 100, baseChar = 'A')).isEqualTo("DW")
  }
}
