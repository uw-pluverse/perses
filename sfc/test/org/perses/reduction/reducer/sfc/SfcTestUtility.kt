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
package org.perses.reduction.reducer.sfc

import com.google.common.collect.ImmutableList
import org.perses.TestUtility
import org.perses.grammar.AbstractParserFacade
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTree
import java.nio.file.Path

/** What every SFC test needs: a grammar to convert against, and a subtree to convert. */
object SfcTestUtility {
  /**
   * A facade for a grammar written inline in a test.
   *
   * [grammarName] must differ per facade: the generated facades share one JVM, and the grammar
   * a facade reads is a resource next to its own class, so two facades of the same name would
   * read the same grammar. In particular, a test comparing the PNF-normalized form of a grammar
   * with the original one needs two names.
   */
  fun createFacadeForGrammar(
    grammarName: String,
    grammarContent: String,
    workingDir: Path,
    enablePnfNormalization: Boolean,
    startRule: String = "start",
    tokenNamesOfIdentifiers: List<String> = listOf("ID"),
  ): AbstractParserFacade =
    TestUtility.generateAdhocFacade(
      combinedGrammarName = grammarName,
      combinedGrammarContent = grammarContent,
      startRule = startRule,
      tokenNamesOfIdentifiers = tokenNamesOfIdentifiers,
      workingDir = workingDir,
      enablePnfNormalization = enablePnfNormalization,
    )

  fun AbstractParserFacade.templatesOfRule(
    ruleName: String,
  ): ImmutableList<RuleAlternativeTemplate> =
    RuleAlternativeTemplateBuilder(this)
      .templatesOf(ruleHierarchy.getRuleHierarchyEntryWithNameOrThrow(ruleName))

  fun AbstractParserFacade.ruleNamed(ruleName: String) =
    ruleHierarchy.getRuleHierarchyEntryWithNameOrThrow(ruleName)

  /** The lexemes of the subtree, separated by a single space, as the tests spell them. */
  val AbstractSparTreeNode.spelling: String
    get() = tokenListCostlyComputed.joinToString(separator = " ")

  /** The topmost node whose subtree spells [lexemes]. */
  fun SparTree.findNodeSpelling(lexemes: String): AbstractSparTreeNode {
    var result: AbstractSparTreeNode? = null
    realRoot.preOrderVisit { node ->
      if (result == null && node.spelling == lexemes) {
        result = node
      }
      node.immutableChildView
    }
    return checkNotNull(result) { "No node spells '$lexemes'." }
  }
}
