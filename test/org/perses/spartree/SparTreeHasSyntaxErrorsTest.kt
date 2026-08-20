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
package org.perses.spartree

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.c.PnfCParserFacade
import org.perses.spartree.AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy

/**
 * The [SparTree.hasSyntaxErrors] flag is the signal the driver uses to decide whether the Dyck
 * reduction pass runs in `auto` mode, so it must reflect how the tree was parsed and survive a copy.
 */
@RunWith(JUnit4::class)
class SparTreeHasSyntaxErrorsTest {
  private val cFacade = PnfCParserFacade()

  private fun build(sourceCode: String, errorMode: ParseErrorHandling): SparTree =
    SparTreeParserUtility.buildSparTree(
      sourceCode = sourceCode,
      parserFacade = cFacade,
      specifiedSparTreeNodeFactory = null,
      simplifyTree = true,
      canonicalTokenCountComputer = { null },
      errorMode = errorMode,
    )

  @Test
  fun cleanParseHasNoSyntaxErrors() {
    assertThat(build("int a = 3 ;", ParseErrorHandling.STRICT).hasSyntaxErrors).isFalse()
    // Even valid input parsed tolerantly recovers nothing, so still no errors.
    assertThat(build("int a = 3 ;", ParseErrorHandling.TOLERANT).hasSyntaxErrors).isFalse()
  }

  @Test
  fun tolerantParseOfInvalidInputHasSyntaxErrors() {
    // `{ 4 }` in expression position is balanced but no C production can place it; the tolerant parse
    // recovers a tree and records the syntax error.
    assertThat(build("int a = 3 { 4 } ;", ParseErrorHandling.TOLERANT).hasSyntaxErrors).isTrue()
  }

  @Test
  fun deepCopyPreservesHasSyntaxErrors() {
    val tolerant = build("int a = 3 { 4 } ;", ParseErrorHandling.TOLERANT)
    assertThat(tolerant.deepCopy(ReuseNodeIdStrategy).result.hasSyntaxErrors).isTrue()

    val clean = build("int a = 3 ;", ParseErrorHandling.STRICT)
    assertThat(clean.deepCopy(ReuseNodeIdStrategy).result.hasSyntaxErrors).isFalse()
  }
}
