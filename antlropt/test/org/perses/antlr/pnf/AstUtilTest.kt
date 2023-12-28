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
import org.perses.antlr.GrammarTestingUtility
import org.perses.antlr.GrammarTestingUtility.createTerminal
import org.perses.antlr.ast.PersesPlusAst
import org.perses.antlr.ast.PersesStarAst
import org.perses.antlr.pnf.AstUtil.convertStarToPlus

@RunWith(JUnit4::class)
class AstUtilTest {

  @Test
  fun testConvertStarToPlusWithSingleTerminalAsBody() {
    val a = createTerminal("a")
    val star = PersesStarAst.createGreedy(createTerminal("a"))

    convertStarToPlus(listOf(a, star)).let { result ->
      assertThat(result).hasSize(1)
      val plus = result.single() as PersesPlusAst
      assertThat(plus.sourceCode).isEqualTo("a+")
    }
    convertStarToPlus(listOf(star, a)).let { result ->
      assertThat(result).hasSize(1)
      val plus = result.single() as PersesPlusAst
      assertThat(plus.sourceCode).isEqualTo("a+")
    }
    val b = createTerminal("b")
    val c = createTerminal("c")
    convertStarToPlus(listOf(b, a, star, c)).let { result ->
      assertThat(result).hasSize(3)
      assertThat(result.first()).isSameInstanceAs(b)
      assertThat(result.last()).isSameInstanceAs(c)
      assertThat(result[1].sourceCode).isEqualTo("a+")
    }
    convertStarToPlus(listOf(b, star, a, c)).let { result ->
      assertThat(result).hasSize(3)
      assertThat(result.first()).isSameInstanceAs(b)
      assertThat(result.last()).isSameInstanceAs(c)
      assertThat(result[1].sourceCode).isEqualTo("a+")
    }
  }

  @Test
  fun testConvertStarToPlusWithSeqAsBody() {
    val a = GrammarTestingUtility.createTerminal("a")
    val b = GrammarTestingUtility.createTerminal("b")
    val star = PersesStarAst.createGreedy(
      GrammarTestingUtility.createSeqOfTerminals("a", "b"),
    )
    convertStarToPlus(listOf(a, b, star)).let { result ->
      assertThat(result).hasSize(1)
      val plus = result.single() as PersesPlusAst
      assertThat(plus.sourceCode).isEqualTo("(a b)+")
    }
    convertStarToPlus(listOf(star, a, b)).let { result ->
      val plus = result.single() as PersesPlusAst
      assertThat(plus.sourceCode).isEqualTo("(a b)+")
    }
  }

  @Test
  fun testConvertMultipleStarToPlus() {
    val a = createTerminal("a")
    val star = PersesStarAst.createGreedy(a)
    convertStarToPlus(listOf(a, star, a, star, a, star)).let { result ->
      assertThat(result).hasSize(3)
      assertThat(result.first().sourceCode).isEqualTo("a+")
      assertThat(result[1].sourceCode).isEqualTo("a+")
      assertThat(result.last().sourceCode).isEqualTo("a+")
    }
  }
}
