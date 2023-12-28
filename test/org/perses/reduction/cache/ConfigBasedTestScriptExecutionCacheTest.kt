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
package org.perses.reduction.cache

import com.google.common.collect.Collections2
import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.program.TokenizedProgram
import org.perses.reduction.PropertyTestResult

@RunWith(JUnit4::class)
class ConfigBasedTestScriptExecutionCacheTest {

  private val cache = ConfigBasedQueryCache()
  val origProgram = TestUtility.createTokenizedProgramFromString(
    """
      int a, b, c, d;
    """.trimIndent(),
    LanguageC,
  )
  val factory = origProgram.factory
  val tokens = origProgram.tokens

  val token_int = tokens[0]
  val token_a = tokens.find { it.text.equals("a") }!!
  val token_b = tokens.find { it.text.equals("b") }!!
  val token_c = tokens.find { it.text.equals("c") }!!
  val token_d = tokens.find { it.text.equals("d") }!!

  val emptyProgram = TokenizedProgram(
    ImmutableList.of(),
    origProgram.factory,
  )
  val oneTokenProgram = TokenizedProgram(
    ImmutableList.of(token_a),
    origProgram.factory,
  )
  val twoTokenProgram = TokenizedProgram(
    ImmutableList.of(token_a, token_b),
    origProgram.factory,
  )
  val threeTokenProgram = TokenizedProgram(
    ImmutableList.of(token_a, token_b, token_c),
    origProgram.factory,
  )
  val testResult = PropertyTestResult.of(exitCode = 1, elapsedMilliseconds = 1)

  @Test
  fun test_cache_miss_for_single_token_program() {
    assertThat(cache.getCachedResult(oneTokenProgram).isHit()).isFalse()
  }

  @Test
  fun test_cache_miss_for_two_token_program() {
    assertThat(cache.getCachedResult(twoTokenProgram).isHit()).isFalse()
  }

  @Test
  fun test_cache_miss_for_LongProgram() {
    assertThat(cache.getCachedResult(origProgram).isHit()).isFalse()
  }

  @Test
  fun test_cache_miss_for_EmptyProgram() {
    val cachedResult = cache.getCachedResult(emptyProgram)
    assertThat(cachedResult.isHit()).isFalse()
  }

  @Test
  fun test_cache_hit_for_empty_program() {
    addToCache(emptyProgram, testResult)
    val cacheResult = cache.getCachedResult(emptyProgram)
    assertThat(cacheResult.isHit()).isTrue()
    assertThat(cacheResult.asCacheHit().testResult).isEqualTo(testResult)
  }

  fun addToCache(program: TokenizedProgram, testResult: PropertyTestResult) {
    val cacheMiss = cache.getCachedResult(program).asCacheMiss()
    cache.addResult(cacheMiss, testResult)
  }

  @Test
  fun test_cache_hit_for_one_token_program() {
    assertThat(cache.getCachedResult(oneTokenProgram).isHit()).isFalse()
    addToCache(oneTokenProgram, testResult)
    val cacheResult = cache.getCachedResult(oneTokenProgram)
    assertThat(cacheResult.isHit()).isTrue()
    assertThat(cacheResult.asCacheHit().testResult).isEqualTo(testResult)
  }

  @Test
  fun test_cache_hit_for_two_token_program() {
    assertThat(cache.getCachedResult(twoTokenProgram).isHit()).isFalse()
    addToCache(twoTokenProgram, testResult)
    val cacheResult = cache.getCachedResult(twoTokenProgram)
    assertThat(cacheResult.isHit()).isTrue()
    assertThat(cacheResult.asCacheHit().testResult).isEqualTo(testResult)
  }

  @Test
  fun test_cache_hit_for_three_token_program() {
    assertThat(cache.getCachedResult(threeTokenProgram).isHit()).isFalse()
    addToCache(threeTokenProgram, testResult)
    val cacheResult = cache.getCachedResult(threeTokenProgram)
    assertThat(cacheResult.isHit()).isTrue()

    assertThat(cache.getCachedResult(oneTokenProgram).isHit()).isFalse()
    assertThat(cache.getCachedResult(twoTokenProgram).isHit()).isFalse()
  }

  @Test
  fun test_cache_add_empty_then_one_then_two_then_three() {
    addToCache(emptyProgram, testResult)
    addToCache(oneTokenProgram, testResult)
    addToCache(twoTokenProgram, testResult)
    addToCache(threeTokenProgram, testResult)

    assertThat(cache.getCachedResult(emptyProgram).isHit()).isTrue()
    assertThat(cache.getCachedResult(oneTokenProgram).isHit()).isTrue()
    assertThat(cache.getCachedResult(twoTokenProgram).isHit()).isTrue()
    assertThat(cache.getCachedResult(threeTokenProgram).isHit()).isTrue()
  }

  @Test
  fun test_cache_add_three_two_one_empty() {
    addToCache(threeTokenProgram, testResult)
    addToCache(twoTokenProgram, testResult)
    addToCache(oneTokenProgram, testResult)
    addToCache(emptyProgram, testResult)

    assertThat(cache.getCachedResult(emptyProgram).isHit()).isTrue()
    assertThat(cache.getCachedResult(oneTokenProgram).isHit()).isTrue()
    assertThat(cache.getCachedResult(twoTokenProgram).isHit()).isTrue()
    assertThat(cache.getCachedResult(threeTokenProgram).isHit()).isTrue()
  }

  @Test
  fun test_cache_enumerate_token_sequences() {
    val tokenList = listOf(token_a, token_b, token_c, token_d, token_int)
    val permutations = Collections2.permutations(tokenList)
    assertThat(permutations.size).isEqualTo(120)
    for (p in permutations) {
      val program = TokenizedProgram(ImmutableList.copyOf(p), factory)
      assertThat(cache.getCachedResult(program).isHit()).isFalse()
    }
    for (p in permutations) {
      addToCache(TokenizedProgram(ImmutableList.copyOf(p), factory), testResult)
    }
    for (p in permutations) {
      val program = TokenizedProgram(ImmutableList.copyOf(p), factory)
      assertThat(cache.getCachedResult(program).isHit()).isTrue()
    }
    assertThat(cache.getCachedResult(origProgram).isHit()).isFalse()
    addToCache(origProgram, testResult)
    assertThat(cache.getCachedResult(origProgram).isHit()).isTrue()
  }
}
