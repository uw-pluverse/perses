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
package org.perses.antlr.reducer.pass

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.AbstractAntlrrdcTest
import org.perses.antlr.ast.PersesAstBuilder
import kotlin.io.path.readText

@RunWith(JUnit4::class)
class ActionNodeCollectorTest : AbstractAntlrrdcTest() {

  @Test
  fun test() {
    val grammar = PersesAstBuilder.loadGrammarFromString(
      parserWithActions.readText(),
    )
    val actions = ActionNodeCollector
      .collectActionNodes(grammar)
      .asSequence()
      .map { it.sourceCode }
      .toList()
    assertThat(actions).hasSize(3)
    assertThat(
      actions,
    ).containsExactly(
      """{System.out.println("");}""",
      """{System.out.println("");}""",
      """{System.out.println("action");}""",
    )
  }
}
