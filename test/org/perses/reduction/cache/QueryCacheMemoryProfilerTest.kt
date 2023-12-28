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

import com.google.common.primitives.ImmutableIntArray
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility.createTokenizedProgramFromString
import org.perses.grammar.c.LanguageC
import org.perses.program.TokenizedProgram
import org.perses.reduction.PropertyTestResult
import org.perses.reduction.cache.QueryCacheMemoryProfiler.Companion.computeMemoryInBytes
import org.perses.util.Fraction
import org.perses.util.Util
import org.perses.util.toImmutableList

@RunWith(JUnit4::class)
class QueryCacheMemoryProfilerTest {

  @Test
  fun testBuiltinTypes() {
    assertThat(computeMemoryInBytes(1).bytes).isEqualTo(16)
    assertThat(computeMemoryInBytes("").bytes).isEqualTo(40)
    assertThat(computeMemoryInBytes("abc").bytes).isEqualTo(48)
  }

  @Test
  fun testTokenizedProgramShouldBeIgnored() {
    val program = createTokenizedProgramFromString(
      "int a;int b; int c;",
      LanguageC,
    )
    assertThat(computeMemoryInBytes(Holder(program)).bytes).isEqualTo(16)
    assertThat(computeMemoryInBytes(Holder(program.factory)).bytes).isEqualTo(16)
    assertThat(computeMemoryInBytes(Holder(listOf(1, 2, 3, 4))).bytes).isEqualTo(136)
  }

  class Holder<T>(val program: T)

  @Test
  fun testStringQueryCache() {
    testCache(
      expectedByteCount = 680,
      extraIncludedClasses = setOf(
        String::class.java.name,
        ContentStringBasedQueryCache.ContentStringEncoding::class.java.name,
        ByteArray::class.java.name,
      ),
    ) { baseProgram ->
      ContentStringBasedQueryCache(
        baseProgram,
        AbstractQueryCacheProfiler.NULL_PROFILER,
        QueryCacheConfiguration.noLightweightRefreshing(Fraction(1, 1)),
      )
    }
  }

  @Test
  fun testShaQueryCache() {
    testCache(
      expectedByteCount = 1280,
      extraIncludedClasses = setOf(
        ByteArray::class.java.name,
        Util.SHA512HashCode::class.java.name,
        ContentSHA512Encoding::class.java.name,
        "com.google.common.hash.HashCode${'$'}BytesHashCode",
        IntArray::class.java.name,
        ImmutableIntArray::class.java.name,
      ),
    ) { baseProgram ->
      ContentSHA512BasedQueryCache(
        baseProgram,
        AbstractQueryCacheProfiler.NULL_PROFILER,
        QueryCacheConfiguration.noLightweightRefreshing(Fraction(1, 1)),
      )
    }
  }

  @Test
  fun testRccMemLitQueryCache() {
    testCache(
      expectedByteCount = 600,
      extraIncludedClasses = setOf(
        IntArray::class.java.name,
        "org.perses.reduction.cache.CompactProgramEncoding" +
          "$" + "Companion" + "$" + "createCompressedEncoding" + "$" + "1",
      ),
    ) { baseProgram ->
      RccMemLitQueryCache(
        baseProgram,
        AbstractQueryCacheProfiler.NULL_PROFILER,
        QueryCacheConfiguration.noLightweightRefreshing(Fraction(1, 1)),
      )
    }
  }

  @Test
  fun testRccQueryCache() {
    testCache(
      expectedByteCount = 600,
      extraIncludedClasses = setOf(
        IntArray::class.java.name,
        "org.perses.reduction.cache.CompactProgramEncoding" +
          "$" + "Companion" + "$" + "createCompressedEncoding" + "$" + "1",
      ),
    ) { baseProgram ->
      CompactQueryCache(
        baseProgram,
        AbstractQueryCacheProfiler.NULL_PROFILER,
        QueryCacheConfiguration.noLightweightRefreshing(Fraction(1, 1)),
      )
    }
  }

  private fun testCache(
    expectedByteCount: Int,
    extraIncludedClasses: Set<String>,
    cacheCreator: (TokenizedProgram) -> AbstractQueryCache,
  ) {
    val baseProgram = createTokenizedProgramFromString("int a, b;", LanguageC)
    val cache = cacheCreator(baseProgram)
    createSubprograms(baseProgram).forEach {
      val cacheMiss = cache.getCachedResult(it)
      if (cacheMiss.isMiss()) {
        cache.addResult(cacheMiss.asCacheMiss(), PropertyTestResult.NON_INTERESTING_RESULT)
      }
    }
    val result = computeMemoryInBytes(cache)
    assertThat(result.includedClasses.map { it.name }).containsExactlyElementsIn(
      (
        extraIncludedClasses + setOf(
          "[Ljava.util.HashMap${'$'}Node;",
          cache::class.java.name,
          "java.util.HashMap${'$'}Node",
          HashMap::class.java.name,
        )
        ).toSet(),
    )
    assertThat(
      listOf(
        TokenizedProgram::class.java,
        AbstractQueryCacheProfiler.NULL_PROFILER.javaClass,
        PropertyTestResult::class.java,
        QueryCacheConfiguration::class.java,
        ContentSHA512Encoder::class.java,
        LinearScanTokenizedProgramEncoder::class.java,
        ContentStringBasedQueryCache.ContentStringEncoder::class.java,
        RccMemoryLitProgramEncoder::class.java,
        ContentStringBasedQueryCache.ContentStringEncoder::class.java,
      ),
    ).containsAtLeastElementsIn(result.excludedClasses)
    assertThat(result.bytes.toInt()).isEqualTo(expectedByteCount)
  }

  private fun createSubprograms(program: TokenizedProgram): List<TokenizedProgram> {
    val tokens = program.tokens
    val factory = program.factory
    val result = mutableListOf<TokenizedProgram>()
    for (excluded in tokens) {
      result.add(TokenizedProgram(tokens.filter { it === excluded }.toImmutableList(), factory))
    }
    return result
  }
}
