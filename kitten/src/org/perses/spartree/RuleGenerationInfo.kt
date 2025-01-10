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

import com.google.common.annotations.VisibleForTesting
import org.perses.antlr.AbstractAntlrGrammar
import org.perses.antlr.ast.AbstractPersesQuantifiedAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AbstractPersesTerminalAst
import org.perses.antlr.ast.PersesActionAst
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesEpsilonAst
import org.perses.antlr.ast.PersesLexerCommandAst
import org.perses.antlr.ast.PersesNotAst
import org.perses.antlr.ast.PersesPlusAst
import org.perses.antlr.ast.PersesRangeAst
import org.perses.antlr.ast.PersesRuleElementLabel
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.PersesTokenSetAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle

class RuleGenerationInfo(
  val antlrGrammar: AbstractAntlrGrammar,
) {
  private val parserGrammar = if (antlrGrammar.isCombined) {
    antlrGrammar.asCombined().grammar
  } else {
    antlrGrammar.asSeparate().parserGrammar
  }
  private val lexerGrammar = if (antlrGrammar.isCombined) {
    null
  } else {
    antlrGrammar.asSeparate().lexerGrammar
  }

  @VisibleForTesting
  val ruleToDepthMap = mutableMapOf<RuleNameHandle, Int>()

  val startSymbol = computeStartSymbol()

  init {
    for (rule in antlrGrammar.getCombinedRules()) {
      ruleToDepthMap[rule.ruleNameHandle] = Int.MAX_VALUE / 2
    }
    // Calculate and store the minDepth for each rule so that we do not need
    // to re-calculate whenever we query the minDepth of a reference rule element
    while (true) {
      if (!computeRuleToDepthMap()) break
    }
  }

  private fun computeStartSymbol(): RuleNameHandle {
    val ruleNameSet = antlrGrammar.getCombinedRules()
      .filter { it.isParserRule }
      .map {
        it.ruleNameHandle
      }.toSet()
    val referredRuleNameSet = antlrGrammar.getCombinedRules().map {
      findAllReferredRuleName(it.body)
    }.reduce { acc, i -> acc + i }
    assert(ruleNameSet.size - referredRuleNameSet.size == 1)
    val leftRuleName = ruleNameSet - referredRuleNameSet
    assert(leftRuleName.size == 1)
    return leftRuleName.toList().first()
  }

  private fun findAllReferredRuleName(rule: AbstractPersesRuleElement): Set<RuleNameHandle> {
    val result = mutableSetOf<RuleNameHandle>()
    when (rule) {
      is PersesAlternativeBlockAst -> {
        rule.alternatives.forEach {
          result.addAll(findAllReferredRuleName(it))
        }
      }
      is AbstractPersesQuantifiedAst -> {
        result.addAll(findAllReferredRuleName(rule.body))
      }
      is PersesSequenceAst -> {
        rule.foreachChildRuleElement {
          result.addAll(findAllReferredRuleName(it))
        }
      }
      is PersesRuleReferenceAst -> {
        result.add(rule.ruleNameHandle)
      }
      else -> return emptySet()
    }
    return result
  }

  private fun computeRuleToDepthMap(): Boolean {
    var isChanged = false
    antlrGrammar.getCombinedRules().forEach {
      val minDepth = getMinDepth(it.body)
      if (minDepth < ruleToDepthMap[it.ruleNameHandle]!!) {
        isChanged = true
      }
      ruleToDepthMap[it.ruleNameHandle] = getMinDepth(it.body)
    }
    return isChanged
  }

  fun getMinDepth(ruleBody: AbstractPersesRuleElement): Int {
    return when (ruleBody) {
      is PersesAlternativeBlockAst -> {
        val alternatives = ruleBody.alternatives
        if (
          alternatives.any {
            canBeTerminal(it)
          }
        ) {
          0
        } else {
          alternatives.minOf { getMinDepth(it) }
        }
      }
      is AbstractPersesQuantifiedAst -> {
        if (ruleBody is PersesPlusAst) {
          getMinDepth(ruleBody.body)
        } else {
          0
        }
      }
      is PersesSequenceAst -> {
        ruleBody.children.maxOf { child ->
          getMinDepth(child)
        }
      }
      is PersesRuleReferenceAst -> {
        val ruleNameHandle = ruleBody.ruleNameHandle
        if (ruleToDepthMap.containsKey(ruleNameHandle)) {
          return ruleToDepthMap[ruleNameHandle]!! + 1
        }
        val rule = if (antlrGrammar.isCombined) {
          parserGrammar.getRuleDefinition(ruleNameHandle.ruleName)!!
        } else {
          parserGrammar.getRuleDefinition(ruleNameHandle.ruleName)
            ?: lexerGrammar!!.getRuleDefinition(ruleNameHandle.ruleName)!!
        }
        getMinDepth(rule.body) + 1
      }
      is PersesRuleElementLabel -> {
        getMinDepth(ruleBody.getChild(0))
      }
      else -> {
        if (canBeTerminal(ruleBody)) {
          return 0
        }
        throw AssertionError("Cannot compute depth for the given ruleBody.")
      }
    }
  }
  companion object {
    fun canBeTerminal(ruleBody: AbstractPersesRuleElement): Boolean {
      return ruleBody is PersesTokenSetAst ||
        ruleBody is AbstractPersesTerminalAst ||
        ruleBody is PersesLexerCommandAst ||
        ruleBody is PersesEpsilonAst ||
        ruleBody is PersesActionAst ||
        ruleBody is PersesNotAst ||
        ruleBody is PersesRangeAst
    }
  }
}
