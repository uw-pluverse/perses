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

import org.perses.util.lazyAssert
import org.perses.antlr.RuleHierarchyEntry
import org.perses.antlr.RuleType
import org.perses.antlr.pnf.AstUtil
import org.perses.util.lazyAssert

/** A spar-tree node for a parser rule.  */
class ParserRuleSparTreeNode internal constructor(
  nodeId: Int,
  antlrRule: RuleHierarchyEntry,
) : AbstractInternalSparTreeNode(nodeId, antlrRule) {
  override val ruleType = AstUtil.computeNodeType(antlrRule.ruleDef)

  init {
    require(ruleType.isParserRule) { ruleType }
  }

  fun getKleeneElementRuleTypeOrThrow(): RuleHierarchyEntry {
    lazyAssert({ isKleenePlusRuleNode || isKleeneStarRuleNode }) { this }
    lazyAssert({ childCount > 0 }) { this }
    val elementTypeCandidates =
      children
        .asSequence()
        .mapNotNull { it.payload!!.expectedAntlrRuleType }
        .distinct()
        .toList()
    lazyAssert({ elementTypeCandidates.size == 1 }) { elementTypeCandidates }
    return elementTypeCandidates.single()
  }

  override val labelPrefix: String
    get() =
      when (ruleType) {
        RuleType.KLEENE_PLUS -> "(+)"
        RuleType.KLEENE_STAR -> "(*)"
        RuleType.OPTIONAL -> "(?)"
        RuleType.ALT_BLOCKS -> "(|:$ruleName)"
        RuleType.OTHER_RULE -> ruleName ?: "<N.A.>"
        else -> error("Cannot reach here. $this")
      }

  override fun asParserRule(): ParserRuleSparTreeNode = this

  override fun internalCopyCurrentNode(computedNewNodeId: Int): ParserRuleSparTreeNode =
    ParserRuleSparTreeNode(computedNewNodeId, antlrRule!!)
}
