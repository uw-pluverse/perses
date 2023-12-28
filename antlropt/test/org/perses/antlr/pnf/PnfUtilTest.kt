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
package org.perses.antlr.pnf

import com.google.common.truth.Truth.assertThat
import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.RuleType
import org.perses.antlr.ast.AstTag
import org.perses.antlr.pnf.PnfUtil.getRuleTypeIfQuantifiedOrThrow

@RunWith(JUnit4::class)
class PnfUtilTest {
  @Test
  fun test_getRuleTypeIfQuantifiedOrThrow() {
    assertThat(getRuleTypeIfQuantifiedOrThrow(AstTag.STAR)).isEqualTo(RuleType.KLEENE_STAR)
    assertThat(getRuleTypeIfQuantifiedOrThrow(AstTag.PLUS)).isEqualTo(RuleType.KLEENE_PLUS)
    assertThat(getRuleTypeIfQuantifiedOrThrow(AstTag.OPTIONAL)).isEqualTo(RuleType.OPTIONAL)
    Assert.assertThrows(Exception::class.java) {
      getRuleTypeIfQuantifiedOrThrow(AstTag.ALTERNATIVE_BLOCK)
    }
  }
}
