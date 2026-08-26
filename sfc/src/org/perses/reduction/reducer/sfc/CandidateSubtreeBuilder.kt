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
import org.perses.antlr.RuleHierarchyEntry
import org.perses.grammar.AbstractParserFacade
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenPosition
import org.perses.spartree.AbstractNodePayload
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTreeNodeFactory

/**
 * Builds the subtree that a rule alternative template spells once its holes are filled: the
 * constants become fresh tokens, and a hole becomes copies of the subtrees filling it.
 *
 * Copies, not the subtrees themselves: those belong to the tree being reduced and stay there,
 * since a candidate is only a proposal until the property test accepts it. Reusing a subtree
 * therefore means spelling its content again, never moving or sharing the nodes.
 */
class CandidateSubtreeBuilder(
  private val parserFacade: AbstractParserFacade,
  private val sparTreeNodeFactory: SparTreeNodeFactory,
) {
  /**
   * The subtree of [template] with its holes filled as [filling] says, or null when the
   * template spells nothing at all, which a rule that can derive to epsilon allows.
   *
   * [positionOfConvertedSubtree] is where the converted subtree started, and the fresh tokens
   * are put there, so that the candidate reads as part of the program rather than as text
   * appended to it.
   */
  fun build(
    template: RuleAlternativeTemplate,
    filling: TemplateFilling,
    positionOfConvertedSubtree: TokenPosition?,
  ): AbstractSparTreeNode? {
    val root =
      buildNodeOfRule(template.rule, template.elements, filling, positionOfConvertedSubtree)
        ?: return null
    // Links the leaves and recomputes the token counts, which a candidate needs before anyone
    // reads its tokens along those links or asks for its size.
    root.fixLinkIntegrity()
    return root
  }

  private fun buildNodeOfRule(
    rule: RuleHierarchyEntry,
    elements: ImmutableList<TemplateElement>,
    filling: TemplateFilling,
    positionOfConvertedSubtree: TokenPosition?,
  ): AbstractSparTreeNode? {
    val node = sparTreeNodeFactory.createParserRuleSparTreeNode(rule.ruleName)
    for (element in elements) {
      when (element) {
        is TemplateElement.Constant -> {
          val token = createTokenFor(element.lexeme, positionOfConvertedSubtree)
          node.addChild(token, AbstractNodePayload.SinglePayload(token.antlrRule))
        }
        is TemplateElement.Hole ->
          filling.findFilledHole(element).forEach { reusedSubtreeRoot ->
            val copy = reusedSubtreeRoot.recursiveDeepCopy(sparTreeNodeFactory).result
            node.addChild(copy, payloadFromSymbolDownTo(element.symbol, copy))
          }
        is TemplateElement.InlinedRule -> {
          val child =
            buildNodeOfRule(
              element.rule,
              element.immediateNestedElements,
              filling,
              positionOfConvertedSubtree,
            ) ?: continue
          node.addChild(child, AbstractNodePayload.SinglePayload(element.rule))
        }
      }
    }
    return if (node.childCount == 0) null else node
  }

  private fun createTokenFor(
    lexeme: String,
    positionOfConvertedSubtree: TokenPosition?,
  ): LexerRuleSparTreeNode =
    sparTreeNodeFactory.createLexerRuleSparTreeNode(
      PersesTokenFactory.createPersesToken(
        parserFacade.transformLiteralIntoSingleToken(lexeme),
        overridingPosition = positionOfConvertedSubtree,
      ),
    )

  /**
   * The payload of a reused subtree in its new place: the chain of rules from the hole's symbol
   * down to the rule the subtree was parsed as, which is what a spar-tree node records when a
   * single-child rule chain has been collapsed into one node.
   */
  private fun payloadFromSymbolDownTo(
    symbol: RuleHierarchyEntry,
    reusedSubtreeRoot: AbstractSparTreeNode,
  ): AbstractNodePayload {
    val chain =
      reusedSubtreeRoot.payload?.asSinglePayloadList?.mapNotNull { it.expectedAntlrRuleType }
        ?: listOfNotNull(reusedSubtreeRoot.antlrRule)
    val chainFromSymbol =
      when {
        chain.firstOrNull() == symbol -> chain
        symbol in chain -> chain.subList(chain.indexOf(symbol), chain.size)
        chain.isNotEmpty() && symbol.isSuperOf(chain.first()) -> listOf(symbol) + chain
        else -> listOf(symbol, reusedSubtreeRoot.antlrRule!!).distinct()
      }
    return AbstractNodePayload.create(
      ImmutableList.copyOf(chainFromSymbol.map { AbstractNodePayload.SinglePayload(it) }),
    )
  }
}
