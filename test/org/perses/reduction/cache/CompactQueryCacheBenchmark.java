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
package org.perses.reduction.cache;

import com.google.common.collect.ImmutableList;
import java.io.IOException;
import java.util.Random;
import org.perses.TestUtility;
import org.perses.program.PersesTokenFactory.PersesToken;
import org.perses.program.TokenizedProgram;
import org.perses.reduction.PropertyTestResult;
import org.perses.util.Fraction;

public class CompactQueryCacheBenchmark {

  public static final int MAX_ITERATIONS = 80;
  final Random random = new Random(1999);

  private void run() {
    System.out.println("parsing the base program.");
    final TokenizedProgram baseProgram =
        TestUtility.createTokenizedProgramFromFile("test/org/perses/reduction/cache/clang-22704.c");

    final CompactQueryCache rcc =
        new CompactQueryCache(
            baseProgram,
            new NullQueryCacheProfiler(),
            QueryCacheConfiguration.withLightweightRefreshing(new Fraction(0, 100)));

    final RccMemLitQueryCache rccLit =
        new RccMemLitQueryCache(
            baseProgram,
            new NullQueryCacheProfiler(),
            QueryCacheConfiguration.withLightweightRefreshing(new Fraction(0, 100)));

    TokenizedProgram currentBaseProgram = baseProgram;
    System.out.println("Start to run...");
    int totalIterations = 0;
    final long start = System.currentTimeMillis();
    while (currentBaseProgram.tokenCount() > 100) {
      if (++totalIterations >= MAX_ITERATIONS) {
        break;
      }
      System.out.println("A new iteration..." + totalIterations);
      for (int i = 0; i < 1000; ++i) {
        TokenizedProgram program = randomDelete(currentBaseProgram, random, 200);

        AbstractCacheRetrievalResult rccCacheResult = rcc.getCachedResult(program);
        if (rccCacheResult.isHit()) {
          continue;
        }
        rcc.addResult(rccCacheResult.asCacheMiss(), new PropertyTestResult(1, 0));

        AbstractCacheRetrievalResult rcclitCacheResult = rccLit.getCachedResult(program);
        rccLit.addResult(rcclitCacheResult.asCacheMiss(), new PropertyTestResult(1, 0));
      }
      currentBaseProgram = randomDelete(currentBaseProgram, random, 50);
      rcc.evictEntriesLargerThan(currentBaseProgram);
      rccLit.evictEntriesLargerThan(currentBaseProgram);
      System.out.println("evict entries....");
    }
    final long end = System.currentTimeMillis();
    System.out.println("Elapsed time: " + (end - start) / 1000 + " seconds.");
  }

  public static void main(String[] args) throws IOException {
    new CompactQueryCacheBenchmark().run();
  }

  private static TokenizedProgram randomDelete(
      TokenizedProgram base, Random random, int maxDeleteLength) {
    ImmutableList<PersesToken> tokens = base.getTokens();
    final int position = random.nextInt(tokens.size() - 3);
    final int length =
        Math.max(1, random.nextInt(Math.min(maxDeleteLength, tokens.size() - position)));

    return new TokenizedProgram(
        ImmutableList.<PersesToken>builder()
            .addAll(tokens.subList(0, position))
            .addAll(tokens.subList(position + length, tokens.size()))
            .build(),
        base.getFactory());
  }
}
