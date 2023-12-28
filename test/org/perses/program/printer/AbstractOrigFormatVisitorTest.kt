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
package org.perses.program.printer

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.program.PersesTokenFactory.PersesToken

@RunWith(JUnit4::class)
class AbstractOrigFormatVisitorTest {

  val program = TestUtility.createTokenizedProgramFromString(
    """int a;
      |
      |int b;
      |
      |int c;
    """.trimMargin(),
    LanguageC,
  )

  val visitor = object : AbstractOrigFormatVisitor(
    program,
    AbstractTokenizedProgramPrinter.AbstractTokenPositionProvider.DefaultProvider,
    tokenPlacementListener = null,
  ) {

    override fun isControlToken(token: PersesToken): Boolean {
      return false
    }

    override fun visitControlToken(token: PersesToken) {
    }

    override fun visitLine(line: List<PersesToken>) {
      result.append(line.joinToString(" ") { it.text })
    }
  }

  @Test
  fun test() {
    visitor.visit()
    val result = visitor.result.toString().trim()
    assertThat(result)
      .isEqualTo("int a ;int b ;int c ;")
  }
}
