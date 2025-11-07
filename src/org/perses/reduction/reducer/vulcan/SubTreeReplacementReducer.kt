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
package org.perses.reduction.reducer.vulcan

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMultimap
import com.google.common.primitives.ImmutableIntArray
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.reduction.AbstractNonDeletionBasedReducer
import org.perses.reduction.AbstractTokenReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerContext
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.AnyNodeReplacementTreeEdit
import org.perses.spartree.MinimalSparTreeGenerator
import org.perses.spartree.NodeReplacementActionSet
import org.perses.spartree.SparTree
import org.perses.spartree.TreeNodeFilterResult
import org.perses.util.Util
import org.perses.util.toImmutableList

class SubTreeReplacementReducer(
  reducerContext: ReducerContext,
) : AbstractNonDeletionBasedReducer(META, reducerContext) {
  private val generator: MinimalSparTreeGenerator by lazy {
    // Make generator global to avoid instantiating it multiple times
    // It is costly to create a new generator.
    reducerContext.computePiggybackPayloadIfAbsent(
      PiggybackPayloadKey(
        owningClass = this::class.java,
        payloadName = "minimal_spar_tree_generator",
        extraData = ImmutableList.of(reducerContext.configuration.parserFacade),
      ),
    ) {
      MinimalSparTreeGenerator(
        reducerContext.configuration.parserFacade,
        sparTreeNodeFactory = reducerContext.sparTreeNodeFactory,
      )
    } as MinimalSparTreeGenerator
  }

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val tree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
    mutationHistory.add(tree.programSnapshot)
    var prevTokenCount: Int
    do {
      prevTokenCount = tree.tokenCount
      sequenceOfCandidates(tree)
        .firstNotNullOfOrNull { candidate ->
          ignoreCachedEditsThenFindBestWrtProperty(
            listOf(candidate),
            fixpointReductionState,
          )
        }?.let { bestEdit ->
          check(bestEdit.program.tokenCount <= tree.tokenCount) {
            """Best edit:
              |  token count: ${bestEdit.program.tokenCount}
              |
              |  edit description: ${bestEdit.actionSet.actionsDescription}
              |Current tree:
              |  token count: ${tree.tokenCount}
            """.trimMargin()
          }
          tree.applyEdit(bestEdit)
        }
    } while (tree.tokenCount < prevTokenCount)
  }

  internal fun sequenceOfCandidates(tree: SparTree): Sequence<AnyNodeReplacementTreeEdit> =
    sequence {
      val nodesWithTheirAlternativeRules = computeCandidateNodesWithAlternativeRules(tree)
      for (entry in nodesWithTheirAlternativeRules.entries()) {
        val node = entry.key
        val ruleName = entry.value
        val originalLexerRuleNodeList = node.leafNodeSequence().toImmutableList()
        val originalTokenCount = originalLexerRuleNodeList.size
        val indicesOfSmallerOrEqualAlternatives =
          ImmutableIntArray
            .builder()
            .addAll(
              generator.getIndicesOfAlternativesWithSmallerSize(ruleName, originalTokenCount),
            ).addAll(
              generator.getIndicesOfAlternativesWithSameSize(ruleName, originalTokenCount),
            ).build()
        for (index in indicesOfSmallerOrEqualAlternatives.toArray()) {
          val replacement =
            generator.generateNodeFromDesignatedAlternative(
              originalLexerRuleNodeList,
              ruleName,
              index,
            ) ?: continue
          Util.lazyAssert(
            { replacement.leafNodeSequence().count() <= originalTokenCount },
          ) {
            """
            |node: ${node.nodeId}
            |index: $index. indices: $indicesOfSmallerOrEqualAlternatives
            |ruleName: $ruleName
            |${replacement.leafNodeSequence().toList().map { it.token.lexemeText }}
            |
            |${originalLexerRuleNodeList.map { it.token.lexemeText }}
            |
            """.trimMargin()
          }
          val edit =
            tree.createAnyNodeReplacementEdit(
              NodeReplacementActionSet.createByReplacingSingleNode(
                targetNode = node,
                replacingNode = replacement,
                actionsDescription =
                  "replace a node ${node.ruleName} " +
                    "with a node generated by another alternative rule ${replacement.ruleName}",
              ),
            )
          yield(edit)
        }
      }
    }

  object META : NonDeletionBasedReducerAnnotation(
    shortName = NAME,
    description =
      "Randomly pick up a subtree, " +
        "and replace it with another subtree of the same type.",
    // TODO(cnsun): This triggers a bug in wasmedge-3018
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_REMAIN,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractTokenReducer> =
      ImmutableList.of(SubTreeReplacementReducer(reducerContext))
  }

  companion object {
    const val NAME = "subtree_replacer"

    fun computeCandidateNodesWithAlternativeRules(
      tree: SparTree,
    ): ImmutableMultimap<AbstractSparTreeNode, RuleNameHandle> {
      val builder = ImmutableMultimap.builder<AbstractSparTreeNode, RuleNameHandle>()

      tree.realRoot.boundedBFSChildren { node, _ ->
        val rules = findAllAlternativeRulesInPayload(node)
        if (rules.isNotEmpty()) {
          builder.putAll(node, rules)
        }
        TreeNodeFilterResult.CONTINUE
      }
      return builder.build()
    }

    fun findAllAlternativeRulesInPayload(
      node: AbstractSparTreeNode,
    ): ImmutableList<RuleNameHandle> {
      val rules =
        node.payload?.asSinglePayloadList?.mapNotNull {
          it.expectedAntlrRuleType
        } ?: return ImmutableList.of()
      return rules
        .filter {
          it.ruleDef.body is PersesAlternativeBlockAst
        }.map { it.ruleDef.ruleNameHandle }
        .distinct()
        .toImmutableList()
    }
  }
}
