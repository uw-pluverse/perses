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
import org.perses.antlr.RuleType
import org.perses.antlr.ast.AbstractPersesQuantifiedAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesEpsilonAst
import org.perses.antlr.ast.PersesRuleElementLabel
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.PersesTerminalAst
import org.perses.grammar.AbstractParserFacade
import org.perses.util.toImmutableList

/**
 * Builds the [RuleAlternativeTemplate]s of a rule from the shape of its body alone. No rule name
 * is ever hard-coded, so this works for any grammar.
 *
 * Perses grammars are in PNF, where one alternative of the original grammar is split over
 * several generated rules (`aux_rule__`, `alt_block__`, `kleene_star__`, ...). References to
 * those rules are inlined, so that one template spells one alternative of the *original*
 * grammar rather than a fragment of it.
 */
class RuleAlternativeTemplateBuilder(
  private val parserFacade: AbstractParserFacade,
) {
  private val grammar = parserFacade.ruleHierarchy
  private val templateCache = HashMap<RuleHierarchyEntry, ImmutableList<RuleAlternativeTemplate>>()
  private val constantOnlyRuleCache = HashMap<RuleHierarchyEntry, Boolean>()

  /**
   * The templates of every alternative of [rule]. A rule whose body is not an alternative block
   * has a single alternative, at index 0; PNF leaves many rules in that shape.
   */
  fun templatesOf(rule: RuleHierarchyEntry): ImmutableList<RuleAlternativeTemplate> =
    templateCache.getOrPut(rule) {
      val body = rule.ruleDef.body
      val activeRules = hashSetOf(rule)
      if (body is PersesAlternativeBlockAst) {
        body.alternatives
          .flatMapIndexed { index, alternative ->
            expandElement(alternative, activeRules).map { RuleAlternativeTemplate(rule, index, it) }
          }.toImmutableList()
      } else {
        // A body that is not an alternative block is the rule's single alternative.
        expandElement(body, activeRules)
          .map { RuleAlternativeTemplate(rule, 0, it) }
          .toImmutableList()
      }
    }

  /** Every way to spell the rule element as a sequence of template elements. */
  private fun expandElement(
    element: AbstractPersesRuleElement,
    activeRules: MutableSet<RuleHierarchyEntry>,
  ): ImmutableList<ImmutableList<TemplateElement>> =
    when (element) {
      is PersesSequenceAst ->
        element.children
          .fold(ImmutableList.of(ImmutableList.of<TemplateElement>())) { prefixes, child ->
            val suffixes = expandElement(child, activeRules)
            prefixes
              .flatMap { prefix -> suffixes.map { (prefix + it).toImmutableList() } }
              .take(MAX_VARIANT_COUNT)
              .toImmutableList()
          }
      // Capping each alternative separately, rather than the union, keeps every alternative
      // of the rule represented no matter how many variants the earlier ones produce.
      is PersesAlternativeBlockAst ->
        element.alternatives
          .flatMap { expandElement(it, activeRules).take(MAX_VARIANT_COUNT_PER_ALTERNATIVE) }
          .toImmutableList()
      is PersesRuleElementLabel -> expandElement(element.child, activeRules)
      is PersesEpsilonAst -> ImmutableList.of(ImmutableList.of())
      is AbstractPersesQuantifiedAst -> expandQuantified(element, activeRules)
      is PersesRuleReferenceAst -> expandSymbol(referencedRule(element), activeRules)
      is PersesTerminalAst -> expandTerminal(element, activeRules)
      else -> ImmutableList.of()
    }

  private fun expandQuantified(
    element: AbstractPersesQuantifiedAst,
    activeRules: MutableSet<RuleHierarchyEntry>,
  ): ImmutableList<ImmutableList<TemplateElement>> {
    val quantifier =
      when (element.tag) {
        AstTag.STAR -> Quantifier.STAR
        AstTag.PLUS -> Quantifier.PLUS
        AstTag.OPTIONAL -> Quantifier.OPTIONAL
        else -> return ImmutableList.of()
      }
    val body = element.body
    val symbol = symbolOf(body)
    val result = ImmutableList.builder<ImmutableList<TemplateElement>>()
    if (symbol != null) {
      result.add(ImmutableList.of(TemplateElement.Hole(symbol, quantifier)))
      if (isPnfGeneratedRule(symbol)) {
        result.addAll(expandSymbol(symbol, activeRules).filter { it.isNotEmpty() })
      }
    } else {
      if (quantifier != Quantifier.PLUS) {
        result.add(ImmutableList.of())
      }
      result.addAll(expandElement(body, activeRules))
    }
    return result.build()
  }

  private fun expandSymbol(
    symbol: RuleHierarchyEntry,
    activeRules: MutableSet<RuleHierarchyEntry>,
  ): ImmutableList<ImmutableList<TemplateElement>> {
    if (symbol.ruleDef.isLexerRule) {
      return ImmutableList.of(ImmutableList.of(elementForToken(symbol)))
    }
    val result = ImmutableList.builder<ImmutableList<TemplateElement>>()
    result.add(ImmutableList.of(TemplateElement.Hole(symbol, Quantifier.EXACTLY_ONE)))
    // A generated rule is a fragment of an original alternative, so it is inlined. A rule that
    // derives constants only (an operator rule spelling punctuation, say) is inlined too: no
    // piece of the input can ever fill a hole of such a rule.
    val generated = isPnfGeneratedRule(symbol)
    if ((generated || derivesConstantsOnly(symbol)) && activeRules.add(symbol)) {
      val body = symbol.ruleDef.body
      val expansions =
        if (body is AbstractPersesQuantifiedAst) {
          expandQuantified(body, activeRules)
        } else {
          expandElement(body, activeRules)
        }
      expansions
        .filter { elements -> generated || elements.none { it.containsHole } }
        .forEach { result.add(ImmutableList.of(TemplateElement.InlinedRule(symbol, it))) }
      activeRules.remove(symbol)
    }
    return result.build()
  }

  private fun expandTerminal(
    terminal: PersesTerminalAst,
    activeRules: MutableSet<RuleHierarchyEntry>,
  ): ImmutableList<ImmutableList<TemplateElement>> {
    if (terminal.isEOF()) {
      return ImmutableList.of(ImmutableList.of())
    }
    if (terminal.isStringLiteral()) {
      return ImmutableList.of(
        ImmutableList.of(TemplateElement.Constant(terminal.getStringLiteralOrThrow())),
      )
    }
    if (terminal.isWildcardDot()) {
      return ImmutableList.of()
    }
    val rule = grammar.getRuleHierarchyEntryOrNull(terminal.text) ?: return ImmutableList.of()
    return expandSymbol(rule, activeRules)
  }

  /** A rule is constant-derivable when no piece of an input could ever fill a hole of it. */
  private fun derivesConstantsOnly(symbol: RuleHierarchyEntry): Boolean =
    constantOnlyRuleCache.getOrPut(symbol) {
      symbol.ruleDef.isParserRule &&
        symbol.transitiveSubRules.none { subRule ->
          subRule.ruleDef.isLexerRule && lexemeOfConstantToken(subRule) == null
        }
    }

  private fun elementForToken(tokenRule: RuleHierarchyEntry): TemplateElement {
    val lexeme = lexemeOfConstantToken(tokenRule)
    return if (lexeme ==
      null
    ) {
      TemplateElement.Hole(tokenRule, Quantifier.EXACTLY_ONE)
    } else {
      TemplateElement.Constant(lexeme)
    }
  }

  private fun lexemeOfConstantToken(tokenRule: RuleHierarchyEntry): String? =
    parserFacade.metaTokenInfoDb
      .getTokenInfoWithName(
        tokenRule.ruleName,
      )?.literalLexeme

  /** The single symbol the element denotes, or null if it is a constant or a larger element. */
  private fun symbolOf(element: AbstractPersesRuleElement): RuleHierarchyEntry? =
    when (element) {
      is PersesRuleReferenceAst -> referencedRule(element)
      is PersesTerminalAst ->
        if (isConstantTerminal(element)) {
          null
        } else {
          grammar.getRuleHierarchyEntryOrNull(element.text)
        }
      is PersesRuleElementLabel -> symbolOf(element.child)
      else -> null
    }

  private fun isConstantTerminal(terminal: PersesTerminalAst): Boolean =
    terminal.isStringLiteral() ||
      terminal.isEOF() ||
      terminal.isWildcardDot() ||
      grammar.getRuleHierarchyEntryOrNull(terminal.text)?.let { lexemeOfConstantToken(it) } != null

  private fun referencedRule(reference: PersesRuleReferenceAst): RuleHierarchyEntry =
    grammar.getRuleHierarchyEntryWithNameOrThrow(reference.ruleNameHandle.ruleName)

  companion object {
    /** The number of templates a rule body yields is exponential in its size; cap it. */
    private const val MAX_VARIANT_COUNT = 4096
    private const val MAX_VARIANT_COUNT_PER_ALTERNATIVE = 512

    fun isPnfGeneratedRule(rule: RuleHierarchyEntry): Boolean =
      rule.ruleDef.isParserRule &&
        RuleType.VALUES.any { it.isParserRule && rule.ruleName.startsWith(it.signaturePrefix) }
  }
}
