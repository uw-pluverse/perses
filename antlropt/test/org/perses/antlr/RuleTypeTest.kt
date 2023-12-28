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
package org.perses.antlr

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class RuleTypeTest {

  @Test
  fun testVALUES() {
    assertThat(RuleType.VALUES).containsExactlyElementsIn(RuleType.values())
  }

  @Test
  fun testPrefixShouldBeNonempty() {
    RuleType.VALUES.forEach {
      assertThat(it.signaturePrefix).isNotEmpty()
    }
  }

  @Test
  fun testIsLexerRule() {
    assertThat(RuleType.isLexerRule("A")).isTrue()
    assertThat(RuleType.isParserRule("A")).isFalse()
  }

  @Test
  fun testAddPrefixIfMissing() {
    val suffix = "suffix"
    val newName = RuleType.ALT_BLOCKS.addPrefixIfMissing(suffix)
    assertThat(newName).isEqualTo(RuleType.ALT_BLOCKS.signaturePrefix + suffix)
    assertThat(newName.length).isGreaterThan(suffix.length)

    assertThat(RuleType.ALT_BLOCKS.addPrefixIfMissing(newName)).isEqualTo(newName)
  }
}
