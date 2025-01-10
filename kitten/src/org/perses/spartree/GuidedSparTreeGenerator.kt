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

import org.perses.antlr.ast.AbstractPersesQuantifiedAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AbstractPersesTerminalAst
import org.perses.antlr.ast.PersesActionAst
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesEpsilonAst
import org.perses.antlr.ast.PersesLexerCommandAst
import org.perses.antlr.ast.PersesNotAst
import org.perses.antlr.ast.PersesOptionalAst
import org.perses.antlr.ast.PersesRangeAst
import org.perses.antlr.ast.PersesRuleElementLabel
import org.perses.antlr.ast.PersesRuleElementOption
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.PersesStarAst
import org.perses.antlr.ast.PersesTokenSetAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.fuzzer.languagemodel.IGenerationGuide
import org.perses.grammar.AbstractParserFacade
import java.lang.Exception
import java.util.LinkedList
import java.util.Queue
import java.util.Random

class GuidedSparTreeGenerator(
  parserFacade: AbstractParserFacade,
  random: Random,
  val languageModel: IGenerationGuide,
) : AbstractSparTreeGenerator(parserFacade, random) {

  override fun internalGenerateParserRuleSparTreeNodeWithMaxDepth(
    ruleNameHandle: RuleNameHandle,
    maxDepth: Int,
  ): ParserRuleSparTreeNode {
    var depth = maxDepth
    val context = IGenerationGuide.GenerationContext(languageModel.contextSizeLimit)
    val antlrRule = grammarHierarchy.getRuleHierarchyEntryWithNameOrThrow(ruleNameHandle.ruleName)
    val generatedNode = ParserRuleSparTreeNode(startNodeId++, antlrRule)
    // generate children in a breadth first way
    val queue: Queue<ParserRuleSparTreeNode> = LinkedList()
    queue.add(generatedNode)
    while (queue.isNotEmpty()) {
      depth -= 1
      var levelSize = queue.size
      while (levelSize-- > 0) {
        val node = queue.poll()
        val ruleBody = node.antlrRule!!.ruleDef.body
        addChildrenAndUpdateQueue(node, ruleBody, queue, depth, context)
      }
    }
    return generatedNode
  }

  private fun addChildrenAndUpdateQueue(
    node: ParserRuleSparTreeNode,
    ruleBody: AbstractPersesRuleElement,
    queue: Queue<ParserRuleSparTreeNode>,
    depth: Int,
    context: IGenerationGuide.GenerationContext,
  ) {
    when (ruleBody) {
      is PersesTokenSetAst,
      is PersesRangeAst,
      is PersesNotAst,
      is AbstractPersesTerminalAst,
      -> {
        val child = generateLexerRuleSparTreeNode(ruleBody)
        node.addChild(child, AbstractNodePayload.SinglePayload(child.antlrRule))
      }
      is PersesAlternativeBlockAst -> {
        val alternative = chooseAlternative(
          node,
          ruleBody,
          depth,
          context,
        )
        addChildrenAndUpdateQueue(node, alternative, queue, depth, context)
      }
      is PersesRuleElementOption, // Do nothing as this only affect parsing.
      is PersesEpsilonAst,
      is PersesActionAst,
      -> {} // Too complicated to consider Actions
      is PersesLexerCommandAst -> {
        // if commands contains "skip", the generator should ignore it
        for (command in ruleBody.commands) {
          if (command.toSourceCode() == "skip") {
            return
          }
        }
        addChildrenAndUpdateQueue(node, ruleBody.body, queue, depth, context)
      }
      is AbstractPersesQuantifiedAst -> {
        val times = chooseTimesToRepeat(ruleBody, depth)
        for (i in 0 until times) {
          addChildrenAndUpdateQueue(node, ruleBody.body, queue, depth, context)
        }
      }
      is PersesRuleElementLabel -> {
        addChildrenAndUpdateQueue(node, ruleBody.getChild(0), queue, depth, context)
      }
      is PersesSequenceAst -> {
        ruleBody.foreachChildRuleElement {
          addChildrenAndUpdateQueue(node, it, queue, depth, context)
        }
      }
      is PersesRuleReferenceAst -> {
        val ruleNameHandle = ruleBody.ruleNameHandle
        val antlrRule = grammarHierarchy.getRuleHierarchyEntryWithNameOrThrow(
          ruleNameHandle.ruleName,
        )
        val generatedNode = ParserRuleSparTreeNode(startNodeId++, antlrRule)
        node.addChild(generatedNode, AbstractNodePayload.SinglePayload(generatedNode.antlrRule))
        queue.add(generatedNode)
      }
      else -> {
        throw AssertionError("Cannot generate node with the given ruleBody.")
      }
    }
  }

  private fun chooseAlternative(
    node: ParserRuleSparTreeNode,
    ruleBody: PersesAlternativeBlockAst,
    maxDepth: Int,
    context: IGenerationGuide.GenerationContext,
  ): AbstractPersesRuleElement {
    val rule = node.antlrRule!!.ruleDef.ruleNameHandle
    val candidates = ruleBody.alternatives.withIndex()
      .filter {
        ruleGenerationInfo.getMinDepth(it.value) <= maxDepth
      }.map { it.index }
    if (candidates.isEmpty()) {
      throw Exception("The maxDepth is set too small")
    }
    context.setAncestorsForGuidance(node)
    val choice = languageModel.getValueWithLowestProbability(rule, context, candidates, random)
    context.update(node, choice)
    return ruleBody.alternatives[choice]
  }

  private fun chooseTimesToRepeat(
    ruleBody: AbstractPersesQuantifiedAst,
    maxDepth: Int,
  ): Int {
    // For Star and Optional, if the minDepth of ruleBody.body is larger than the maxDepth
    // zero should be returned
    return when (ruleBody) {
      is PersesStarAst -> {
        if (ruleGenerationInfo.getMinDepth(ruleBody.body) > maxDepth) {
          0
        } else {
          random.nextInt(10)
        }
      }
      is PersesOptionalAst -> {
        if (ruleGenerationInfo.getMinDepth(ruleBody.body) > maxDepth) {
          0
        } else {
          random.nextInt(2)
        }
      }
      else -> random.nextInt(9) + 1
    }
  }
}
