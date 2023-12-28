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

import com.google.common.collect.ImmutableList
import org.perses.TestUtility.createTokenizedProgramFromFile
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram
import org.perses.reduction.PropertyTestResult
import org.perses.reduction.cache.QueryCacheConfiguration.Companion.withLightweightRefreshing
import org.perses.util.Fraction
import java.util.Random

class CompactQueryCacheBenchmark {
  val random = Random(1999)

  private fun run() {
    println("parsing the base program.")
    val baseProgram =
      createTokenizedProgramFromFile("test/org/perses/reduction/cache/clang-22704.c")
    val rcc = CompactQueryCache(
      baseProgram,
      NullQueryCacheProfiler(),
      withLightweightRefreshing(Fraction(0, 100)),
    )
    val rccLit = RccMemLitQueryCache(
      baseProgram,
      NullQueryCacheProfiler(),
      withLightweightRefreshing(Fraction(0, 100)),
    )
    var currentBaseProgram = baseProgram
    println("Start to run...")
    var totalIterations = 0
    val start = System.currentTimeMillis()
    while (currentBaseProgram.tokenCount() > 100) {
      if (++totalIterations >= MAX_ITERATIONS) {
        break
      }
      println("A new iteration...$totalIterations")
      for (i in 0..999) {
        val program = randomDelete(currentBaseProgram, random, 200)
        val rccCacheResult = rcc.getCachedResult(program)
        if (rccCacheResult.isHit()) {
          continue
        }
        rcc.addResult(rccCacheResult.asCacheMiss(), PropertyTestResult.of(1, 0))
        val rcclitCacheResult = rccLit.getCachedResult(program)
        rccLit.addResult(rcclitCacheResult.asCacheMiss(), PropertyTestResult.of(1, 0))
      }
      currentBaseProgram = randomDelete(currentBaseProgram, random, 50)
      rcc.evictEntriesLargerThan(currentBaseProgram)
      rccLit.evictEntriesLargerThan(currentBaseProgram)
      println("evict entries....")
    }
    val end = System.currentTimeMillis()
    println("Elapsed time: " + (end - start) / 1000 + " seconds.")
  }

  companion object {
    const val MAX_ITERATIONS = 80

    @JvmStatic
    fun main(args: Array<String>) {
      CompactQueryCacheBenchmark().run()
    }

    private fun randomDelete(
      base: TokenizedProgram,
      random: Random,
      maxDeleteLength: Int,
    ): TokenizedProgram {
      val tokens = base.tokens
      val position = random.nextInt(tokens.size - 3)
      val length = Math.max(1, random.nextInt(Math.min(maxDeleteLength, tokens.size - position)))
      return TokenizedProgram(
        ImmutableList.builder<PersesTokenFactory.PersesToken>()
          .addAll(tokens.subList(0, position))
          .addAll(tokens.subList(position + length, tokens.size))
          .build(),
        base.factory,
      )
    }
  }
}
