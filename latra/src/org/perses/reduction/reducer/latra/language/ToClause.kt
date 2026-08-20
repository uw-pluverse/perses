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
package org.perses.reduction.reducer.latra.language

import com.google.common.collect.ArrayListMultimap
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import org.perses.grammar.AbstractParserFacade
import org.perses.reduction.reducer.latra.LatraEmptyHoleBindingException
import org.perses.reduction.reducer.latra.language.AbstractPatternElement.Hole.HoleName
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTreeNodeFactory
import org.perses.util.toImmutableList
import org.perses.util.toImmutableMap

class ToClause(
  pattern: AbstractLatraPattern.RewritingLatraPattern,
) : AbstractPatternClause(pattern) {
  init {
    pattern.holes.forEach {
      require(!it.greedyKleenePlusMatching) {
        "Holes in the to-clause cannot be Kleene Plus. Only hole names are allowed. " +
          pattern.originalSourceCode
      }
    }
  }

  data class RewriteResult(
    val result: AbstractSparTreeNode,
    /*
     *
     * TODO(cnsun): the key should be based on identity, not content. So it should be a list.
     * Note that this has to be a multimap, as we can use the hole in multiple places in the
     * to-clause. For example,
     *
     * from = :[return_type] f() {}
     * to = :[return_type] f() {
     *   :[return_type] a=0;
     *   :[return_type] b = a;
     *   return b;
     * }
     */
    val newHoleBindings: ImmutableMap<HoleName, ImmutableList<AbstractSparTreeNode>>,
  )

  fun performRewrite(
    sparTreeNodeFactory: SparTreeNodeFactory,
    bindings: AbstractPatternElementBindings,
  ): RewriteResult {
    val newHoleBindings = ArrayListMultimap.create<HoleName, AbstractSparTreeNode>()
    val leafNodes = mutableListOf<AbstractSparTreeNode>()
    for (element in pattern.elements) {
      when (element) {
        is AbstractPatternElement.Hole -> {
          val matchedNodes =
            bindings.getHoleBindingOrThrow(element.holeName).map { matchedNode ->
              matchedNode.recursiveDeepCopy(sparTreeNodeFactory).result
            }
          val transformedNode: AbstractSparTreeNode =
            when (matchedNodes.size) {
              0 -> throw LatraEmptyHoleBindingException("No binding for the hole $element")
              1 -> matchedNodes.single()
              else -> sparTreeNodeFactory.createGroupingSparTreeNode(matchedNodes)
            }.also { newBinding ->
              newHoleBindings.put(element.holeName, newBinding)
            }
          leafNodes.add(transformedNode)
        }

        is AbstractPatternElement.ConcreteToken -> {
          val boundNode = bindings.getConcreteTokenBinding(element)
          leafNodes.add(
            boundNode?.copyCurrentNode(sparTreeNodeFactory)
              ?: sparTreeNodeFactory.createLexerRuleSparTreeNodeForAntlrToken(
                element.token,
                overridingPosition = null,
              ),
          )
        }

        is AbstractPatternElement.Trivia -> {
          leafNodes.add(
            sparTreeNodeFactory.createLexerRuleSparTreeNodeForText(
              text = element.originalSourceCode,
            ),
          )
        }
      }
    }
    return RewriteResult(
      result =
        when (leafNodes.size) {
          0 -> sparTreeNodeFactory.createGroupingSparTreeNode(ImmutableList.of())
          1 -> leafNodes.single()
          else -> sparTreeNodeFactory.createGroupingSparTreeNode(leafNodes)
        },
      newHoleBindings =
        newHoleBindings
          .asMap()
          .entries
          .map { it.key to it.value.toImmutableList() }
          .toImmutableMap(),
    ).also { it.result.fixLinkIntegrity() }
  }

  companion object {
    fun parse(
      string: String,
      parserFacade: AbstractParserFacade,
    ): ToClause = ToClause(AbstractLatraPattern.parseRewritingPattern(string, parserFacade))

    val EMPTY = ToClause(AbstractLatraPattern.EMPTY_REWRITING)
  }
}
