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

import org.perses.antlr.ast.AbstractPersesQuantifiedAst
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.fuzzer.TreeToSequenceConverter
import org.perses.grammar.AbstractParserFacade
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy
import org.perses.spartree.ParserRuleSparTreeNode
import org.perses.spartree.SparTree
import java.util.Random

class NDepthTreeModel(
  override val contextSizeLimit: Int,
  parserFacade: AbstractParserFacade,
  allowToEnableGuidance: Boolean,
) : AbstractLanguageModel(parserFacade), IGenerationGuide {

  init {
    super.allowToEnableGuidance = allowToEnableGuidance
  }

  private val database = HashMap<RuleNameHandle, NodeSequenceToFrequencyMap>()

  override val size: Int
    get() = database.values.sumOf { it.size }

  private var updatedTimesFromLastFindingOfNewFeature = 0

  override fun getRarenessOfMostRareFeature(featureOfSparTree: FeatureOfSparTree): Double {
    return featureOfSparTree.map {
      val ruleNameHandle = it.key.antlrRule!!.ruleDef.ruleNameHandle
      val nodeSequence = it.value
      1.0 / database[ruleNameHandle]!!.getInt(nodeSequence)
    }.maxOrNull() ?: 0.0
  }

  override fun isRare(featureOfSparTree: FeatureOfSparTree): Boolean {
    return getRarenessOfMostRareFeature(featureOfSparTree) > RARE_THRESHOLD
  }

  override fun isVeryCommon(featureOfSparTree: FeatureOfSparTree): Boolean {
    return getRarenessOfMostRareFeature(featureOfSparTree) < VERY_COMMON_THRESHOLD
  }

  override fun changeStatusOfGuidance() {
    if (allowToEnableGuidance &&
      updatedTimesFromLastFindingOfNewFeature > GUIDANCE_ENABLE_THRESHOLD
    ) {
      guidanceEnabled = true
    }
  }

  @Synchronized
  override fun updateModelAndGetFeatureOfSparTree(
    tree: SparTree,
  ): FeatureOfSparTree {
    updatedTimesFromLastFindingOfNewFeature++
    changeStatusOfGuidance()
    val encodingResult = FeatureOfSparTree()
    tree.root.preOrderVisit {
      if (!it.isTokenNode && it.updateLeafTokenCount() != 0) {
        val rule = it.antlrRule!!.ruleDef
        if (rule.body is AbstractPersesQuantifiedAst || rule.body is PersesAlternativeBlockAst) {
          val ruleOfRoot = rule.ruleNameHandle
          val nodeSequence =
            TreeToSequenceConverter.convertWithBreadthFirstOrder(it, contextSizeLimit)
          assert(!encodingResult.containsKey(it))
          encodingResult[it as ParserRuleSparTreeNode] = nodeSequence
          database.computeIfAbsent(ruleOfRoot) {
            NodeSequenceToFrequencyMap()
          }.addTo(nodeSequence, 1)
          if (database[ruleOfRoot]!!.getInt(nodeSequence) == 1) {
            updatedTimesFromLastFindingOfNewFeature = 0
          }
          numberOfFeatureNodesExtracted++
        }
      }
      return@preOrderVisit it.immutableChildView
    }
    numberOfTreesSeen++
    return encodingResult
  }

  @Synchronized
  override fun getValueWithLowestProbability(
    rule: RuleNameHandle,
    context: IGenerationGuide.GenerationContext,
    candidates: List<Int>,
    random: Random,
  ): Int {
    assert(candidates.isNotEmpty())
    if (!guidanceEnabled) {
      return candidates[random.nextInt(candidates.size)]
    }
    // Find the one with the lowest frequency
    val frequencies = candidates.map { choice ->
      context.getAncestorNodesForCurrentNode().map {
        val ruleOfAncestor = it.antlrRule!!.ruleDef.ruleNameHandle
        val prefix = context.content[it]!!
        database[ruleOfAncestor]?.filterKeys { key ->
          if (key.size <= prefix.size) {
            return@filterKeys false
          } else {
            prefix.forEachWithIndex { index, representation ->
              if (representation != key[index]) {
                return@filterKeys false
              }
            }
            if (key[prefix.size] != NodeRepresentation.create(rule.id, choice)) {
              return@filterKeys false
            }
          }
          return@filterKeys true
        }?.map { entry ->
          entry.value
        }?.sum() ?: 0
      }.reduceOrNull { acc, i -> acc * i } ?: 0
    }
    // If the model does not have the information to guide, return a random choice
    if (frequencies.all { it == 0 }) {
      return candidates[random.nextInt(candidates.size)]
    }
    return candidates[frequencies.indexOf(frequencies.minOrNull())]
  }

  @Synchronized
  private fun selectIndicesWithGuidance(
    nodeList: List<AbstractSparTreeNode>,
    random: Random,
  ): IntArray? {
    if (nodeList.isEmpty()) {
      return null
    }
    return if (!guidanceEnabled) {
      intArrayOf(random.nextInt(nodeList.size))
    } else {
      sampleElementsFromList(nodeList, random)
    }
  }

  @Synchronized
  override fun selectIndexOfNodeToBeReplaced(
    nodeList: List<AbstractSparTreeNode>,
    featureOfSparTree: FeatureOfSparTree?,
    random: Random,
  ): Int? {
    val sampledIndices = selectIndicesWithGuidance(nodeList, random) ?: return null
    return sampledIndices.maxByOrNull {
      return@maxByOrNull getPrevalence(nodeList[it], featureOfSparTree!!)
    }
  }

  @Synchronized
  override fun selectReplacingNode(
    nodeList: List<AbstractSparTreeNode>,
    featureOfSparTree: FeatureOfSparTree?,
    random: Random,
  ): AbstractSparTreeNode? {
    val sampledIndices = selectIndicesWithGuidance(nodeList, random) ?: return null
    val selectedNode = sampledIndices.map {
      nodeList[it]
    }.minByOrNull {
      return@minByOrNull getPrevalence(it, featureOfSparTree!!)
    }
    return selectedNode?.recursiveDeepCopy(ReuseNodeIdStrategy)
  }

  private fun getPrevalence(
    node: AbstractSparTreeNode,
    featureOfSparTree: FeatureOfSparTree,
  ): Double {
    return if (node.isTokenNode) {
      Double.MAX_VALUE
    } else if (featureOfSparTree.containsKey(node)) {
      val ruleNameHandle = node.antlrRule!!.ruleDef.ruleNameHandle
      val nodeSequence = featureOfSparTree[node]
      database[ruleNameHandle]!!.getInt(nodeSequence).toDouble()
    } else {
      node.childCount / node.immutableChildView.sumOf {
        1.0 / getPrevalence(it, featureOfSparTree)
      }
    }
  }

  override fun printDatabase(): String {
    val builder = StringBuilder()
    database.forEach {
      val ruleName = it.key.ruleName
      for (entry in it.value.object2IntEntrySet()) {
        builder.append("$ruleName => ${entry.key}: ${entry.intValue}\n")
      }
    }
    return builder.toString()
  }

  companion object {
    const val RARE_THRESHOLD = 0.3
    const val VERY_COMMON_THRESHOLD = 0.05
    const val GUIDANCE_ENABLE_THRESHOLD = 1000
    private const val SAMPLE_FRACTION = 3 // sample 1/3 elements

    private fun sampleElementsFromList(
      list: List<AbstractSparTreeNode>,
      random: Random,
    ): IntArray {
      val sampleSize = list.size / SAMPLE_FRACTION
      if (sampleSize == 0) {
        return intArrayOf(random.nextInt(list.size))
      }
      var numOfRestElements = list.size
      assert(sampleSize <= numOfRestElements)
      var numOfElementsSampled = 0
      val sampledIndices = IntArray(sampleSize)
      list.withIndex().forEach {
        if (random.nextInt(numOfRestElements) < sampleSize - numOfElementsSampled) {
          sampledIndices[numOfElementsSampled] = it.index
          numOfElementsSampled++
        }
        numOfRestElements--
        if (numOfElementsSampled == sampleSize) {
          return sampledIndices
        }
      }
      error("unreachable")
    }
  }
}
