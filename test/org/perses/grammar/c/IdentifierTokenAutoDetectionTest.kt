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
package org.perses.grammar.c

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.toTokenType

@RunWith(JUnit4::class)
class IdentifierTokenAutoDetectionTest {
  /**
   * The C facade is authoritative (`includeAutoDetectedIdentifierTokenTypes = false`),
   * so its effective identifier set is exactly its explicit token (`Identifier`).
   */
  @Test
  fun fusedIdentifierTokenTypesIsExactlyTheExplicitToken() {
    assertThat(CParserFacade().fusedIdentifierTokenTypes)
      .containsExactly(OptCLexer.Identifier.toTokenType())
  }
}
