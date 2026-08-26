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
import org.perses.program.AbstractPersesToken
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTreeNodeFactory
import org.perses.util.toImmutableList

/**
 * Structure Form Conversion (OOPSLA'25): given a subtree, build the subtrees of the other rule
 * alternatives that the subtree's position admits, reusing the subtrees under it for the symbols
 * those alternatives spell.
 *
 * Reusing a subtree means spelling its content again: a candidate holds copies, and the tree
 * being reduced is left untouched until the property test accepts one.
 *
 * The alternatives come from [RuleAlternativeTemplateBuilder], the subtrees to reuse from
 * [StructureReuseFinder] through [TemplateHoleFiller], and the result from
 * [CandidateSubtreeBuilder]. The conversion therefore reads the rule hierarchy and the shape of
 * the rule bodies alone, and works for any grammar.
 */
class StructureFormConverter(
  private val parserFacade: AbstractParserFacade,
  private val sparTreeNodeFactory: SparTreeNodeFactory,
) {
  private val grammar = parserFacade.ruleHierarchy
  private val templateBuilder = RuleAlternativeTemplateBuilder(parserFacade)
  private val candidateBuilder = CandidateSubtreeBuilder(parserFacade, sparTreeNodeFactory)

  /**
   * One subtree that Structure Form Conversion proposes in place of the converted subtree, and
   * the rule alternative it spells, which says where the candidate came from.
   */
  class Candidate(
    val tree: AbstractSparTreeNode,
    val template: RuleAlternativeTemplate,
    val lexemes: ImmutableList<String>,
  ) {
    val leafTokenCount: Int
      get() = lexemes.size

    override fun toString() = lexemes.joinToString(separator = " ")
  }

  /**
   * The candidates for [subtreeRootToConvert]: the subtrees of the other alternatives its
   * position admits, built by reusing the subtrees under it that [isReuseAllowed] does not veto.
   *
   * A candidate spelling the same tokens as another one, or as the converted subtree itself, is
   * left out. The sequence is lazy, and a rule can have many alternatives, so a caller that does
   * not want them all should cap it.
   *
   * The leaves under [subtreeRootToConvert] have to be linked, which a spar tree maintains: the
   * tokens of a subtree are read along those links rather than by visiting every node.
   */
  fun convert(
    subtreeRootToConvert: AbstractSparTreeNode,
    isReuseAllowed: (subtreeRoot: AbstractSparTreeNode) -> Boolean = { true },
    shrinkOversizedCandidates: Boolean = false,
  ): Sequence<Candidate> {
    val expectedRule = subtreeRootToConvert.payload?.expectedAntlrRuleType ?: return emptySequence()
    if (subtreeRootToConvert.isTokenNode()) {
      return emptySequence()
    }
    val alreadySpelled =
      HashSet<ImmutableList<String>>().apply {
        add(
          subtreeRootToConvert.lexemes(),
        )
      }
    val positionOfConvertedSubtree =
      (subtreeRootToConvert.beginToken?.token as? AbstractPersesToken.AntlrToken)?.position
    return candidateRules(expectedRule)
      .asSequence()
      .flatMap { rule -> templateBuilder.templatesOf(rule).asSequence() }
      // Smallest alternative first, across every candidate rule rather than within one: a caller
      // that caps the candidates would otherwise spend its budget on whatever the rules declared
      // first happen to spell, and never reach the small alternative of a rule declared later.
      .sortedBy { it.constants.size + it.holes.size }
      .flatMap { template ->
        TemplateHoleFiller
          .findEveryFillingOfHoles(template, subtreeRootToConvert, isReuseAllowed)
          .map { filling -> template to filling }
      }.mapNotNull { (template, filling) ->
        val fillingToBuild =
          if (shrinkOversizedCandidates) {
            shrinkToFitUnder(
              filling,
              subtreeRootToConvert.leafTokenCount,
              template,
              isReuseAllowed,
            ) ?: return@mapNotNull null
          } else {
            filling
          }
        val tree =
          candidateBuilder.build(template, fillingToBuild, positionOfConvertedSubtree)
            ?: return@mapNotNull null
        val lexemes = tree.lexemes()
        if (lexemes.isEmpty() || !alreadySpelled.add(lexemes)) {
          return@mapNotNull null
        }
        Candidate(tree, template, lexemes)
      }
  }

  /**
   * A filling whose reused subtrees together spell fewer than [tokenCountCeiling] tokens, by
   * replacing reused subtrees with a smaller piece of themselves until they fit, or null when no
   * amount of shrinking gets there.
   *
   * Reusing the highest-level structures (Principle 4 of the paper) is what the search starts
   * from, but a template whose highest-level filling is too big would otherwise yield nothing at
   * all. Descending is what PR #1048 does, and it is the difference between proposing a smaller
   * structure and proposing none.
   */
  private fun shrinkToFitUnder(
    filling: TemplateFilling,
    tokenCountCeiling: Int,
    template: RuleAlternativeTemplate,
    isReuseAllowed: (subtreeRoot: AbstractSparTreeNode) -> Boolean,
  ): TemplateFilling? {
    val constantTokenCount = template.constants.size
    var filledHoles = filling.filledHoles
    // Every round either returns or replaces a subtree with a strictly shorter one, so the tokens
    // the filling reuses bound the shrinking rounds; the one extra round is the check that the
    // filling already fits, which is all a filling reusing nothing ever needs.
    val maximumRoundCount =
      1 + filledHoles.sumOf { filledHole -> filledHole.sumOf { it.leafTokenCount } }
    repeat(maximumRoundCount) {
      val reusedTokenCount =
        filledHoles.sumOf { filledHole ->
          filledHole.sumOf { it.leafTokenCount }
        }
      if (constantTokenCount + reusedTokenCount < tokenCountCeiling) {
        return TemplateFilling(filledHoles)
      }
      var shrunkAnything = false
      filledHoles =
        filledHoles
          .map { filledHole ->
            val shrunkSubtrees =
              filledHole.subtreesToCopy
                .map { subtree ->
                  val descendant =
                    StructureReuseFinder.findFirstReusableDescendantOf(
                      subtree,
                      filledHole.hole.symbol,
                      isReuseAllowed,
                    )
                  if (descendant == null) {
                    subtree
                  } else {
                    shrunkAnything = true
                    descendant
                  }
                }.toImmutableList()
            FilledHole.withSubtrees(filledHole.hole, shrunkSubtrees)
          }.toImmutableList()
      if (!shrunkAnything) {
        return null
      }
    }
    return null
  }

  /**
   * The lexemes the subtree spells, walked along the linked leaves rather than by visiting every
   * node, since this runs once per candidate. The leaves must be linked: a candidate is linked
   * by [CandidateSubtreeBuilder], and the tree being reduced keeps its own leaves linked.
   */
  private fun AbstractSparTreeNode.lexemes(): ImmutableList<String> =
    leafNodeSequence().map { it.token.lexemeText }.toImmutableList()

  /** The rules whose alternatives can stand where the converted subtree stands. */
  private fun candidateRules(expectedRule: RuleHierarchyEntry): ImmutableList<RuleHierarchyEntry> =
    grammar.ruleList
      .filter { rule -> rule.ruleDef.isParserRule && expectedRule.isEqualToOrSuperOf(rule) }
      .toImmutableList()
}
