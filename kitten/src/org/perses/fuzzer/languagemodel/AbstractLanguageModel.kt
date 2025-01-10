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

import it.unimi.dsi.fastutil.objects.Object2IntOpenHashMap
import org.perses.grammar.AbstractParserFacade
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.ParserRuleSparTreeNode
import org.perses.spartree.SparTree
import java.util.Random

typealias NodeSequenceToFrequencyMap = Object2IntOpenHashMap<NodeRepresentationList>
typealias FeatureOfSparTree = HashMap<ParserRuleSparTreeNode, NodeRepresentationList>

abstract class AbstractLanguageModel(val parserFacade: AbstractParserFacade) {

  var numberOfTreesSeen = 0
    protected set

  var numberOfFeatureNodesExtracted: Int = 0
    protected set

  protected var rareThreshold = 3.0

  var allowToEnableGuidance = false

  var guidanceEnabled = false

  // return true if the given sequence is interesting
  abstract fun updateModelAndGetFeatureOfSparTree(tree: SparTree): FeatureOfSparTree

  fun getAverageNumberOfFeatureNodesOfSparTree(): Int {
    return if (numberOfTreesSeen == 0) {
      Int.MAX_VALUE
    } else {
      numberOfFeatureNodesExtracted / numberOfTreesSeen
    }
  }

  abstract val size: Int
  abstract fun getRarenessOfMostRareFeature(featureOfSparTree: FeatureOfSparTree): Double
  abstract fun isRare(featureOfSparTree: FeatureOfSparTree): Boolean
  abstract fun isVeryCommon(featureOfSparTree: FeatureOfSparTree): Boolean
  abstract fun selectIndexOfNodeToBeReplaced(
    nodeList: List<AbstractSparTreeNode>,
    featureOfSparTree: FeatureOfSparTree?,
    random: Random,
  ): Int?

  abstract fun selectReplacingNode(
    nodeList: List<AbstractSparTreeNode>,
    featureOfSparTree: FeatureOfSparTree?,
    random: Random,
  ): AbstractSparTreeNode?

  abstract fun printDatabase(): String

  abstract fun changeStatusOfGuidance()
}
