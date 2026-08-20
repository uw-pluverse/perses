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
import org.perses.reduction.cache.PassLevelCache.PassLevelCacheResult
import org.perses.reduction.reducer.PersesNodeReducerAnnotations
import org.perses.util.hashing.EnumShaAlgorithm

@RunWith(JUnit4::class)
class PassLevelCacheTest {
  private val cache = PassLevelCache()
  private val bfsReducer = PersesNodeReducerAnnotations.PrioritizedBfs
  private val dfsReducer = PersesNodeReducerAnnotations.PrioritizedDfs

  // Two distinct classes standing in for two parser-facade classes; the cache only compares them by
  // identity, so the concrete types are irrelevant.
  private val facadeA: Class<*> = String::class.java
  private val facadeB: Class<*> = StringBuilder::class.java

  private fun update(
    reducer: org.perses.reduction.ReducerAnnotation,
    facadeClass: Class<*>,
    content: String,
  ) = cache.update(reducer, facadeClass) {
    EnumShaAlgorithm.SHA512.createFromListOfStrings(listOf(content))
  }

  @Test
  fun test() {
    assertThat(update(bfsReducer, facadeA, "content")).isEqualTo(PassLevelCacheResult.NEW)
    assertThat(update(bfsReducer, facadeA, "content")).isEqualTo(PassLevelCacheResult.EXISTING_ALREADY)
    assertThat(update(dfsReducer, facadeA, "content")).isEqualTo(PassLevelCacheResult.NEW)
    assertThat(update(dfsReducer, facadeA, "content")).isEqualTo(PassLevelCacheResult.EXISTING_ALREADY)

    assertThat(update(dfsReducer, facadeA, "content b")).isEqualTo(PassLevelCacheResult.NEW)
    assertThat(update(dfsReducer, facadeA, "content b")).isEqualTo(PassLevelCacheResult.EXISTING_ALREADY)
  }

  @Test
  fun differentParserFacadesAreDistinctKeys() {
    // Same reducer and content, different facade: must be a NEW key, not an already-done skip, since
    // the reducer's result on that content depends on the grammar the tree was built under.
    assertThat(update(dfsReducer, facadeA, "content")).isEqualTo(PassLevelCacheResult.NEW)
    assertThat(update(dfsReducer, facadeB, "content")).isEqualTo(PassLevelCacheResult.NEW)
    assertThat(update(dfsReducer, facadeA, "content")).isEqualTo(PassLevelCacheResult.EXISTING_ALREADY)
    assertThat(update(dfsReducer, facadeB, "content")).isEqualTo(PassLevelCacheResult.EXISTING_ALREADY)
  }
}
