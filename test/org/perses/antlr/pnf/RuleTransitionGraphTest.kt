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
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class RuleTransitionGraphTest : PnfLeftTestGrammar() {
  @Test
  fun testTransitionGraphCanBeBuilt() {
    assertThat(a.ruleName).isEqualTo("a")
    assertThat(b.ruleName).isEqualTo("b")
    assertThat(c.ruleName).isEqualTo("c")
    assertThat(d.ruleName).isEqualTo("d")
    assertThat(edge_a.sourceCode.replace(" ", ""))
      .isEqualTo("(bc|d)?")
    assertThat(edge_ad.sourceCode).isEqualTo("a d")
    assertThat(edge_cd.sourceCode).isEqualTo("c d")
  }
}
