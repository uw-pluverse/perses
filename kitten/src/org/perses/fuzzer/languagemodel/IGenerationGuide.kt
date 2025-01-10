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
package org.perses.fuzzer.languagemodel

import com.google.common.collect.ImmutableList
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.spartree.ParserRuleSparTreeNode
import java.util.Random

interface IGenerationGuide {
  val contextSizeLimit: Int
  fun getValueWithLowestProbability(
    rule: RuleNameHandle,
    context: GenerationContext,
    candidates: List<Int>,
    random: Random,
  ): Int

  class GenerationContext(
    private val sizeLimit: Int,
  ) {
    val content = HashMap<ParserRuleSparTreeNode, MutableNodeRepresentationList>()
    private var ancestorNodesForCurrentNode = ImmutableList.of<ParserRuleSparTreeNode>()
    fun getAncestorNodesForCurrentNode(): ImmutableList<ParserRuleSparTreeNode> =
      ancestorNodesForCurrentNode

    fun update(
      node: ParserRuleSparTreeNode,
      featureValue: Int,
    ) {
      val representation = NodeRepresentation.create(
        node.antlrRule!!.ruleDef.ruleNameHandle.id,
        featureValue,
      )
      assert(content[node] == null)
      content[node] = MutableNodeRepresentationList.create(sizeLimit).apply {
        add(representation)
      }
      ancestorNodesForCurrentNode.iterator().forEach {
        val entry = content[it] ?: return@forEach
        if (entry.size == sizeLimit) {
          // That's how sizeLimit works. It should be noticed that the generation is in BFS
          // order, and NodeRepresentationList is also collected in BFS order.
          // When content[it] == sizeLimit, the distance between current node we try to generate
          // and 'it' equals 'sizeLimit+1', so we don't need 'it' for following guidance which
          // means it can be removed from generation context.
          content.remove(it)
        } else {
          entry.add(representation)
        }
      }
    }

    fun setAncestorsForGuidance(
      node: ParserRuleSparTreeNode,
    ) {
      val builder = ImmutableList.builder<ParserRuleSparTreeNode>()
      var ancestor = node.parent
      while (ancestor != null) {
        assert(ancestor is ParserRuleSparTreeNode)
        if (content.containsKey(ancestor)) {
          builder.add(ancestor as ParserRuleSparTreeNode)
        }
        ancestor = ancestor.parent
      }
      ancestorNodesForCurrentNode = builder.build()
    }
  }
}
