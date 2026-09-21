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
package org.perses.reduction.cache

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility.createTokenizedProgramFromString
import org.perses.grammar.c.LanguageC
import org.perses.reduction.TestScriptVerdict
import org.perses.reduction.io.AbstractOutputManager
import org.perses.reduction.io.CommonReductionIOManagerData
import org.perses.util.ImmutableIntArray

@RunWith(JUnit4::class)
class ContentShaHashBasedFormatQueryCacheTest :
  CommonReductionIOManagerData(ContentShaHashBasedFormatQueryCacheTest::class.java) {
  private val cache =
    ContentShaHashBasedFormatQueryCache(AbstractQueryCacheProfiler.NULL_PROFILER)

  private fun outputManagerFor(sourceCode: String): AbstractOutputManager =
    outputManagerFactory.createManagerFor(
      createTokenizedProgramFromString(sourceCode, LanguageC),
    )

  private fun recordUninteresting(outputManager: AbstractOutputManager) {
    cache.recordUninteresting(
      outputManager,
      ImmutableIntArray.of(1),
      TestScriptVerdict.NON_INTERESTING,
    )
  }

  @Test
  fun test_an_uninteresting_program_is_a_hit_afterwards() {
    val outputManager = outputManagerFor("int a;")
    assertThat(cache.lookUp(outputManager).isMiss).isTrue()
    recordUninteresting(outputManager)
    assertThat(cache.lookUp(outputManager).isHit).isTrue()
    assertThat(cache.cacheSize()).isEqualTo(1)
  }

  /**
   * The list-minimizer evaluation driver clears the cache before every measurement, so that several
   * minimizers sharing one process each start as empty as a separate process would. Nothing else
   * calls [ContentShaHashBasedFormatQueryCache.clearCache] outside the out-of-memory path, so this
   * is the only place that mechanism is exercised.
   */
  @Test
  fun test_clearing_makes_every_recorded_program_a_miss_again() {
    val first = outputManagerFor("int a;")
    val second = outputManagerFor("int b;")
    recordUninteresting(first)
    recordUninteresting(second)
    assertThat(cache.cacheSize()).isEqualTo(2)

    cache.clearCache()

    assertThat(cache.cacheSize()).isEqualTo(0)
    assertThat(cache.lookUp(first).isMiss).isTrue()
    assertThat(cache.lookUp(second).isMiss).isTrue()
  }

  @Test
  fun test_clearing_an_empty_cache_is_harmless() {
    cache.clearCache()
    assertThat(cache.cacheSize()).isEqualTo(0)
  }
}
