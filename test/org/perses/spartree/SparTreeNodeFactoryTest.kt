/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.program.TokenizedProgramFactory

@RunWith(JUnit4::class)
class SparTreeNodeFactoryTest {
  val language = LanguageC
  val facade = TestUtility.getFacade(language)
  val sparTreeNodeFactory =
    SparTreeNodeFactory(
      metaTokenInfoDb = facade.metaTokenInfoDb,
      tokenizedProgramFactory = TokenizedProgramFactory.createEmptyFactory(language),
      grammarHierarchy = facade.ruleHierarchy,
    )

  @Test
  fun testCreateGroupingSparTreeNodeForTokens() {
    val tokens = facade.tokenizeString("int a;", fileName = "none")
    val result = sparTreeNodeFactory.createGroupingSparTreeNodeForTokens(tokens)
    assertThat(result.childCount).isEqualTo(3)
    result.immutableChildView.forEach {
      assertThat(it).isInstanceOf(LexerRuleSparTreeNode::class.java)
      assertThat(it.payload).isInstanceOf(AbstractNodePayload.SinglePayload::class.java)
      (it.payload as AbstractNodePayload.SinglePayload).let { payload ->
        assertThat(payload.actualAntlrRuleType).isNull()
        assertThat(payload.expectedAntlrRuleType).isNull()
      }
    }
    assertThat(result.immutableChildView.map { it.asLexerRule().token.lexemeText })
      .containsExactly(
        "int",
        "a",
        ";",
      ).inOrder()
  }
}
