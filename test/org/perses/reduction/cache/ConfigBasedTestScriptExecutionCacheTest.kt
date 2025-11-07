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
package org.perses.reduction.cache

import com.google.common.collect.Collections2
import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.program.TokenizedProgram
import org.perses.reduction.PropertyTestResult
import org.perses.reduction.io.CommonReductionIOManagerData

@RunWith(JUnit4::class)
class ConfigBasedTestScriptExecutionCacheTest :
  CommonReductionIOManagerData(ConfigBasedTestScriptExecutionCacheTest::class.java) {
  private val cache = ConfigBasedQueryCache()
  val origProgram =
    TestUtility.createTokenizedProgramFromString(
      """
      int a, b, c, d;
      """.trimIndent(),
      LanguageC,
    )
  val factory = origProgram.factory
  val tokens = origProgram.tokens

  val tokenInt = tokens[0]
  val tokenA = tokens.find { it.lexemeText.equals("a") }!!
  val tokenB = tokens.find { it.lexemeText.equals("b") }!!
  val tokenC = tokens.find { it.lexemeText.equals("c") }!!
  val tokenD = tokens.find { it.lexemeText.equals("d") }!!

  @After
  fun tearDown() {
    close()
  }

  val emptyProgram =
    TokenizedProgram(
      ImmutableList.of(),
      origProgram.factory,
    )
  val oneTokenProgram =
    TokenizedProgram(
      ImmutableList.of(tokenA),
      origProgram.factory,
    )
  val twoTokenProgram =
    TokenizedProgram(
      ImmutableList.of(tokenA, tokenB),
      origProgram.factory,
    )
  val threeTokenProgram =
    TokenizedProgram(
      ImmutableList.of(tokenA, tokenB, tokenC),
      origProgram.factory,
    )
  val testResult = PropertyTestResult.of(exitCode = 1, elapsedMillis = 1)

  private fun getCachedResult(program: TokenizedProgram): AbstractCacheRetrievalResult =
    cache.getCachedResult(
      program,
      outputManager = outputManagerFactory.createManagerFor(program),
    )

  @Test
  fun test_cache_miss_for_single_token_program() {
    assertThat(getCachedResult(oneTokenProgram).isHit()).isFalse()
  }

  @Test
  fun test_cache_miss_for_two_token_program() {
    assertThat(getCachedResult(twoTokenProgram).isHit()).isFalse()
  }

  @Test
  fun test_cache_miss_for_LongProgram() {
    assertThat(getCachedResult(origProgram).isHit()).isFalse()
  }

  @Test
  fun test_cache_miss_for_EmptyProgram() {
    val cachedResult = getCachedResult(emptyProgram)
    assertThat(cachedResult.isHit()).isFalse()
  }

  @Test
  fun test_cache_hit_for_empty_program() {
    addToCache(emptyProgram, testResult)
    val cacheResult = getCachedResult(emptyProgram)
    assertThat(cacheResult.isHit()).isTrue()
  }

  fun addToCache(
    program: TokenizedProgram,
    testResult: PropertyTestResult,
  ) {
    val cacheMiss = getCachedResult(program).asCacheMiss()
    cache.cacheProgramAndResult(cacheMiss, testResult)
  }

  @Test
  fun test_cache_hit_for_one_token_program() {
    assertThat(getCachedResult(oneTokenProgram).isHit()).isFalse()
    addToCache(oneTokenProgram, testResult)
    val cacheResult = getCachedResult(oneTokenProgram)
    assertThat(cacheResult.isHit()).isTrue()
  }

  @Test
  fun test_cache_hit_for_two_token_program() {
    assertThat(getCachedResult(twoTokenProgram).isHit()).isFalse()
    addToCache(twoTokenProgram, testResult)
    val cacheResult = getCachedResult(twoTokenProgram)
    assertThat(cacheResult.isHit()).isTrue()
  }

  @Test
  fun test_cache_hit_for_three_token_program() {
    assertThat(getCachedResult(threeTokenProgram).isHit()).isFalse()
    addToCache(threeTokenProgram, testResult)
    val cacheResult = getCachedResult(threeTokenProgram)
    assertThat(cacheResult.isHit()).isTrue()

    assertThat(getCachedResult(oneTokenProgram).isHit()).isFalse()
    assertThat(getCachedResult(twoTokenProgram).isHit()).isFalse()
  }

  @Test
  fun test_cache_add_empty_then_one_then_two_then_three() {
    addToCache(emptyProgram, testResult)
    addToCache(oneTokenProgram, testResult)
    addToCache(twoTokenProgram, testResult)
    addToCache(threeTokenProgram, testResult)

    assertThat(getCachedResult(emptyProgram).isHit()).isTrue()
    assertThat(getCachedResult(oneTokenProgram).isHit()).isTrue()
    assertThat(getCachedResult(twoTokenProgram).isHit()).isTrue()
    assertThat(getCachedResult(threeTokenProgram).isHit()).isTrue()
  }

  @Test
  fun test_cache_add_three_two_one_empty() {
    addToCache(threeTokenProgram, testResult)
    addToCache(twoTokenProgram, testResult)
    addToCache(oneTokenProgram, testResult)
    addToCache(emptyProgram, testResult)

    assertThat(getCachedResult(emptyProgram).isHit()).isTrue()
    assertThat(getCachedResult(oneTokenProgram).isHit()).isTrue()
    assertThat(getCachedResult(twoTokenProgram).isHit()).isTrue()
    assertThat(getCachedResult(threeTokenProgram).isHit()).isTrue()
  }

  @Test
  fun test_cache_enumerate_token_sequences() {
    val tokenList = listOf(tokenA, tokenB, tokenC, tokenD, tokenInt)
    val permutations = Collections2.permutations(tokenList)
    assertThat(permutations.size).isEqualTo(120)
    for (p in permutations) {
      val program = TokenizedProgram(ImmutableList.copyOf(p), factory)
      assertThat(getCachedResult(program).isHit()).isFalse()
    }
    for (p in permutations) {
      addToCache(TokenizedProgram(ImmutableList.copyOf(p), factory), testResult)
    }
    for (p in permutations) {
      val program = TokenizedProgram(ImmutableList.copyOf(p), factory)
      assertThat(getCachedResult(program).isHit()).isTrue()
    }
    assertThat(getCachedResult(origProgram).isHit()).isFalse()
    addToCache(origProgram, testResult)
    assertThat(getCachedResult(origProgram).isHit()).isTrue()
  }
}
