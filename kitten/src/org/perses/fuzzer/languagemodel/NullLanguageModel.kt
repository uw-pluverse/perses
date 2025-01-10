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

import org.perses.grammar.AbstractParserFacade
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy
import org.perses.spartree.SparTree
import java.util.Random

class NullLanguageModel(
  parserFacade: AbstractParserFacade,
) : AbstractLanguageModel(parserFacade) {

  override fun updateModelAndGetFeatureOfSparTree(tree: SparTree): FeatureOfSparTree = HashMap()

  override val size: Int
    get() = 0

  override fun getRarenessOfMostRareFeature(featureOfSparTree: FeatureOfSparTree): Double = 0.0

  override fun isRare(featureOfSparTree: FeatureOfSparTree): Boolean = false

  override fun isVeryCommon(featureOfSparTree: FeatureOfSparTree): Boolean = false

  override fun selectIndexOfNodeToBeReplaced(
    nodeList: List<AbstractSparTreeNode>,
    featureOfSparTree: FeatureOfSparTree?,
    random: Random,
  ): Int? {
    return if (nodeList.isEmpty()) {
      null
    } else {
      random.nextInt(nodeList.size)
    }
  }

  override fun selectReplacingNode(
    nodeList: List<AbstractSparTreeNode>,
    featureOfSparTree: FeatureOfSparTree?,
    random: Random,
  ): AbstractSparTreeNode? {
    return if (nodeList.isEmpty()) {
      null
    } else {
      nodeList[random.nextInt(nodeList.size)].recursiveDeepCopy(ReuseNodeIdStrategy)
    }
  }

  override fun printDatabase(): String {
    return ""
  }

  override fun changeStatusOfGuidance() {}
}
