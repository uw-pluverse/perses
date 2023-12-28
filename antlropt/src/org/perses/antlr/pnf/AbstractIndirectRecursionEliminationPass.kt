/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.antlr.pnf

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.util.toImmutableList

abstract class AbstractIndirectRecursionEliminationPass : AbstractPnfPass() {

  override fun processGrammar(
    grammar: GrammarPair,
  ): GrammarPair {
    val parserGrammar = grammar.parserGrammar ?: return grammar
    val ruleTransitionGraph = createRuleTransitionGraph(parserGrammar)
    val sccs: List<Set<RuleNameHandle>> = ruleTransitionGraph.computeSccSet()
      .asSequence()
      .map { it.vertexSet() }
      .map { ImmutableSet.copyOf(it) }
      .toImmutableList()
    val ruleMap = MutableGrammar.createParserRulesFrom(parserGrammar)
    for (scc in sccs) {
      ruleMap.validate()
      transformForScc(ProjectedHashMultimap(ruleMap, scc))
      ruleMap.validate()
    }
    return grammar.withNewParserGrammar(
      parserGrammar.copyWithNewParserRuleDefs(ruleMap.toParserRuleAstList()),
    )
  }

  @VisibleForTesting
  fun transformForScc(grammar: ProjectedHashMultimap) {
    var changed = true
    while (changed) {
      changed = false
      for (ruleName in grammar.ketSet()) {
        for (def in grammar[ruleName]!!) {
          val target = getRuleRefToInline(def) ?: continue
          if (!grammar.containsKey(target)) {
            continue
          }
          if (ruleName.id <= target.id) {
            continue
          }
          check(grammar.remove(ruleName, def)) { "key=$ruleName, value=$def" }
          val altBlock = grammar[target]
          check(altBlock != null)
          check(altBlock.size() > 0)
          for (toInline in altBlock.asIterable()) {
            val inlined = inlineRuleRef(def, toInline)
            grammar.put(ruleName, inlined)
          }
          changed = true
          break
        }
      }
    }
  }

  protected abstract fun getRuleRefToInline(
    def: AbstractPersesRuleElement,
  ): RuleNameHandle?

  fun inlineRuleRef(
    def: AbstractPersesRuleElement,
    toInline: AbstractPersesRuleElement,
  ): AbstractPersesRuleElement {
    return when (def.tag) {
      AstTag.RULE_REF -> toInline
      AstTag.SEQUENCE -> {
        val seq = def as PersesSequenceAst
        check(seq.childCount > 1)
        val newDef = ImmutableList
          .builderWithExpectedSize<AbstractPersesRuleElement>(
            seq.childCount + toInline.childCount,
          )
        inlineRuleRefIntoSequence(seq, toInline, newDef)
        val children = newDef.build()
        check(children.size > 0)
        if (children.size == 1) {
          children.single()
        } else {
          PersesSequenceAst(children)
        }
      }
      else -> throw RuntimeException("Unhandled tag " + def.tag)
    }
  }

  protected abstract fun inlineRuleRefIntoSequence(
    originalSequence: PersesSequenceAst,
    toInline: AbstractPersesRuleElement,
    newSeqBuilder: ImmutableList.Builder<AbstractPersesRuleElement>,
  )

  protected abstract fun createRuleTransitionGraph(
    grammar: PersesGrammar,
  ): RuleTransitionGraph

  companion object {
    @JvmStatic
    fun getFirstOrLastRuleRef(
      def: AbstractPersesRuleElement,
      seekingFirst: Boolean,
    ): RuleNameHandle? {
      return when (def.tag) {
        AstTag.RULE_REF -> (def as PersesRuleReferenceAst).ruleNameHandle
        AstTag.SEQUENCE -> {
          val seq = def as PersesSequenceAst
          if (seekingFirst) {
            getFirstOrLastRuleRef(seq.firstChild, seekingFirst)
          } else {
            getFirstOrLastRuleRef(seq.lastChild, seekingFirst)
          }
        }
        else -> null
      }
    }
  }
}
