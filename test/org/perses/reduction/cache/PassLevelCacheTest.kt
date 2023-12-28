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
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.cache.PassLevelCache.PassLevelCacheResult
import org.perses.reduction.reducer.PersesNodePrioritizedBfsReducer
import org.perses.reduction.reducer.PersesNodePrioritizedDfsReducer
import org.perses.util.FileNameContentPair

@RunWith(JUnit4::class)
class PassLevelCacheTest {

  private val cache = PassLevelCache()
  private val bfsReducer = PersesNodePrioritizedBfsReducer.META
  private val dfsReducer = PersesNodePrioritizedDfsReducer.META

  @Test
  fun test() {
    cache.update(bfsReducer) {
      ImmutableList.of(FileNameContentPair.createFromString("file", "content"))
    }.also {
      assertThat(it).isEqualTo(PassLevelCacheResult.NEW)
    }
    cache.update(bfsReducer) {
      ImmutableList.of(FileNameContentPair.createFromString("file", "content"))
    }.also {
      assertThat(it).isEqualTo(PassLevelCacheResult.EXISTING_ALREADY)
    }
    cache.update(dfsReducer) {
      ImmutableList.of(FileNameContentPair.createFromString("file", "content"))
    }.also {
      assertThat(it).isEqualTo(PassLevelCacheResult.NEW)
    }
    cache.update(dfsReducer) {
      ImmutableList.of(FileNameContentPair.createFromString("file", "content"))
    }.also {
      assertThat(it).isEqualTo(PassLevelCacheResult.EXISTING_ALREADY)
    }

    cache.update(dfsReducer) {
      ImmutableList.of(FileNameContentPair.createFromString("file", "content b"))
    }.also {
      assertThat(it).isEqualTo(PassLevelCacheResult.NEW)
    }
    cache.update(dfsReducer) {
      ImmutableList.of(FileNameContentPair.createFromString("file", "content b"))
    }.also {
      assertThat(it).isEqualTo(PassLevelCacheResult.EXISTING_ALREADY)
    }
  }
}
