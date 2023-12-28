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

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility.createTokenizedProgramFromString
import org.perses.grammar.c.LanguageC
import org.perses.reduction.PropertyTestResult

@RunWith(JUnit4::class)
class NullQueryCacheTest {

  private val cache = NullQueryCache()

  @Test
  fun test() {
    assertThat(cache.size()).isEqualTo(0)
    val program = createTokenizedProgramFromString("int a;", LanguageC)
    val cachedResult = cache.getCachedResult(program)
    assertThat(cachedResult.isMiss()).isTrue()
    cache.addResult(cachedResult.asCacheMiss(), PropertyTestResult.INTERESTING_RESULT)
    assertThat(cache.size()).isEqualTo(0)
    cache.evictEntriesLargerThan(program)
    assertThat(cache.size()).isEqualTo(0)
  }
}
