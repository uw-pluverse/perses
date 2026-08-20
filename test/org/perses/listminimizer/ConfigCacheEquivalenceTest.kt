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
package org.perses.listminimizer

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class ConfigCacheEquivalenceTest {
  private val baseElements = ImmutableList.of("a", "b", "c", "d", "e")
  private val baseProgram =
    baseElements.indices
      .map { index ->
        ElementWrapper(index, baseElements[index], "payload")
      }.let { ImmutableList.copyOf(it) }

  @Test
  fun testBasicEquivalence() {
    val configCache = ConfigCache<String>()
    val rccCache = RccConfigCache(baseProgram)

    val config1 = ImmutableList.of(baseProgram[0], baseProgram[1])
    val config2 = ImmutableList.of(baseProgram[2], baseProgram[3])

    // Both should start empty
    assertThat(configCache.contains(config1)).isFalse()
    assertThat(rccCache.contains(config1)).isFalse()

    // Adding to both
    configCache.add(config1)
    rccCache.add(config1)
    configCache.add(config2)
    rccCache.add(config2)

    // Both should contain added elements
    assertThat(configCache.contains(config1)).isTrue()
    assertThat(rccCache.contains(config1)).isTrue()
    assertThat(configCache.contains(config2)).isTrue()
    assertThat(rccCache.contains(config2)).isTrue()

    assertThat(configCache.size).isEqualTo(rccCache.size)
  }

  @Test
  fun testPruningEquivalence() {
    val configCache = ConfigCache<String>()
    val rccCache = RccConfigCache(baseProgram)

    // config1 is a sublist of the new best we will set later
    val config1 = ImmutableList.of(baseProgram[0], baseProgram[2]) // [a, c]
    // config2 is NOT a sublist of the new best we will set later
    val config2 = ImmutableList.of(baseProgram[1], baseProgram[3]) // [b, d]

    configCache.add(config1)
    rccCache.add(config1)
    configCache.add(config2)
    rccCache.add(config2)

    // New best is [a, c, e] (index 0, 2, 4)
    val newBest = ImmutableList.of(baseProgram[0], baseProgram[2], baseProgram[4])

    configCache.refreshAndUpdateBest(newBest)
    rccCache.refreshAndUpdateBest(newBest)

    // RccConfigCache should KEEP config1 because it's a sublist of [a, c, e]
    assertThat(rccCache.contains(config1)).isTrue()
    // RccConfigCache should DROP config2 because 'b' and 'd' are not in [a, c, e]
    assertThat(rccCache.contains(config2)).isFalse()

    // ConfigCache behavior: it drops everything >= newBest.size (3)
    // Both config1 and config2 have size 2, so ConfigCache (with current logic) KEEPS both!
    // This shows RccConfigCache is more accurate but compatible (it's a subset or superset depending on perspective,
    // but definitely safe for correctness).
    assertThat(configCache.contains(config1)).isTrue()
    assertThat(configCache.contains(config2)).isTrue()
  }

  @Test
  fun testEmptyConfig() {
    val configCache = ConfigCache<String>()
    val rccCache = RccConfigCache(baseProgram)

    val emptyConfig = ImmutableList.of<ElementWrapper<String>>()

    configCache.add(emptyConfig)
    rccCache.add(emptyConfig)

    assertThat(configCache.contains(emptyConfig)).isTrue()
    assertThat(rccCache.contains(emptyConfig)).isTrue()

    val newBest = ImmutableList.of(baseProgram[0])
    configCache.refreshAndUpdateBest(newBest)
    rccCache.refreshAndUpdateBest(newBest)

    assertThat(configCache.contains(emptyConfig)).isTrue()
    assertThat(rccCache.contains(emptyConfig)).isTrue()
  }
}
