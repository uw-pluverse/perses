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
package org.perses.delta

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.PropertyTestResult.Companion.INTERESTING_RESULT
import org.perses.reduction.PropertyTestResult.Companion.NON_INTERESTING_RESULT
import kotlin.collections.HashMap

@RunWith(JUnit4::class)
class PristineDeltaDebuggerTest {

  val input = ImmutableList.of("a", "b", "c", "d", "e")

  val dummyHandler = { _: ImmutableList<AbstractDeltaDebugger.ElementWrapper<String>>, _: String ->
  }

  @Test
  fun test_a() {
    test(property = listOf("a"), expected = listOf("a"))
    test(property = listOf("c"), expected = listOf("c"))
    test(property = listOf(), expected = listOf())
    test(property = listOf("a", "b", "c", "d", "e"), expected = listOf("a", "b", "c", "d", "e"))
    test(property = listOf("a", "e"), expected = listOf("a", "e")).let { testHistory ->
      assertThat(testHistory).containsExactly(
        // n = 1
        "",
        // n = 2
        "abc", "de", "de", "abc",
        // n = 4
        "ab", "c", "d", "e", "cde", "abde", "abe", "ab",
        // n = 2
        "ab", "e", "e", "ab",
        // n = 3
        "a", "b", "e", "be", "ae", "a",
        // n = 2
        "a", "e", "e", "a",
      ).inOrder()
    }
  }

  private fun test(
    property: List<String>,
    expected: List<String>,
    enableCache: Boolean = false,
  ): ImmutableList<String>? {
    val testHistory = ArrayList<String>()

    val propertyTest =
      IPropertyTester<String, String> { configuration ->
        val candidate = configuration.candidate
        testHistory.add(candidate.joinToString(separator = ""))
        if (candidate.containsAll(property)) {
          PropertyTestResultWithPayload(INTERESTING_RESULT, "payload")
        } else {
          PropertyTestResultWithPayload(NON_INTERESTING_RESULT, "payload")
        }
      }

    val debugger = PristineDeltaDebugger<String, String>(
      AbstractDeltaDebugger.Arguments(
        needToTestEmpty = true,
        input,
        propertyTest,
        dummyHandler,
        descriptionPrefix = "",
      ),
      enableCache,
    )
    val result = debugger.reduce()
    assertThat(result).isEqualTo(expected)
    return ImmutableList.copyOf(testHistory)
  }

  @Test
  fun testConfigCache() {
    // reduction correctness
    test(property = listOf(), expected = listOf(), enableCache = true)
    test(property = listOf("a"), expected = listOf("a"), enableCache = true)
    test(
      property = listOf("a", "b", "c", "d", "e"),
      expected = listOf("a", "b", "c", "d", "e"),
      enableCache = true,
    )

    // cache effectiveness
    test(property = listOf("a", "e"), expected = listOf("a", "e"), enableCache = true)
      .let { testHistory ->
        assertThat(testHistory).containsExactly(
          // n = 1
          "",
          // n = 2
          "abc", "de",
          // n = 4
          "ab", "c", "d", "e", "cde", "abde",
          // n = 3
          "abe",
          // n = 3
          "a", "b", "be", "ae",
        ).inOrder()
      }
  }

  @Test
  fun testConfigCacheRefresh() {
    // refresh 0%; refresh on every update
    val configCache = ConfigCache<String>(
      enableRefresh = true,
    )
    val config5 = ConfigurationBasedOnElementSystemIdentity(
      ImmutableList.of("a", "b", "c", "d", "e"),
    )
    val config4 = ConfigurationBasedOnElementSystemIdentity(ImmutableList.of("a", "b", "c", "d"))
    val config3 = ConfigurationBasedOnElementSystemIdentity(ImmutableList.of("a", "b", "c"))
    val config2 = ConfigurationBasedOnElementSystemIdentity(ImmutableList.of("a", "b"))
    val config1 = ConfigurationBasedOnElementSystemIdentity(ImmutableList.of("a"))
    configCache.add(config5)
    configCache.add(config4)
    configCache.add(config3)
    configCache.add(config2)
    configCache.add(config1)
    assertThat(configCache.size).isEqualTo(5)

    configCache.deleteStaleConfigs(newSize = 4)
    assertThat(configCache.size).isEqualTo(3)
    assertThat(configCache.contains(config4)).isFalse()
    assertThat(configCache.contains(config3)).isTrue()
    assertThat(configCache.contains(config2)).isTrue()
    assertThat(configCache.contains(config1)).isTrue()

    configCache.deleteStaleConfigs(newSize = 3)
    assertThat(configCache.size).isEqualTo(2)
    assertThat(configCache.contains(config3)).isFalse()
    assertThat(configCache.contains(config2)).isTrue()
    assertThat(configCache.contains(config1)).isTrue()

    configCache.deleteStaleConfigs(newSize = 2)
    assertThat(configCache.size).isEqualTo(1)
    assertThat(configCache.contains(config2)).isFalse()
    assertThat(configCache.contains(config1)).isTrue()
  }

  @Test
  fun testConfigurationHashAndEquals() {
    // dummy but unique objects
    data class Token(private val text: String)
    val token1 = Token("int")
    val token2 = Token("int")
    val token3 = Token("a")

    // hashcode remains the same
    val token1HashCode = token1.hashCode()
    assertThat(token1HashCode == token1.hashCode())
    // same hashCode() but different identityHashCode()
    assertThat(token1.hashCode() == token2.hashCode()).isTrue()
    assertThat(token1 == token2).isTrue() // structural equality
    assertThat(token1 !== token2).isTrue() // referential equality
    assertThat(System.identityHashCode(token1))
      .isNotEqualTo(System.identityHashCode(token2))

    // compare configs with the same content but different token objects
    val config1 = ConfigurationBasedOnElementSystemIdentity(ImmutableList.of(token1, token3))
    val config2 = ConfigurationBasedOnElementSystemIdentity(ImmutableList.of(token2, token3))

    assertThat(config1.hashCode() != config2.hashCode()).isTrue()
    assertThat(config1 != config2).isTrue()
    assertThat(config1.hashCode())
      .isEqualTo(
        ConfigurationBasedOnElementSystemIdentity(ImmutableList.of(token1, token3)).hashCode(),
      )

    // test behavior in HashMap
    val cache = HashMap<ConfigurationBasedOnElementSystemIdentity, Int>()
    cache.put(config1, 1001)

    assertThat(cache.get(config1)).isEqualTo(1001)
    assertThat(
      cache.get(ConfigurationBasedOnElementSystemIdentity(ImmutableList.of(token1, token3))),
    )
      .isEqualTo(1001)
    assertThat(cache.get(config2)).isNull()

    cache.put(config2, 1002)

    assertThat(
      cache.get(ConfigurationBasedOnElementSystemIdentity(ImmutableList.of(token2, token3))),
    )
      .isEqualTo(1002)
  }
}
