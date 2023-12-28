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
package org.perses.antlr

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import org.perses.antlr.ast.PersesAstBuilder
import org.perses.antlr.protobuf.GrammarHierarchyOuterClass

/** This is the rule hierarchy, which can be used as an approximation of the class hierarchy.  */
class GrammarHierarchy internal constructor(
  val ruleList: ImmutableList<RuleHierarchyEntry>,
  private val nameToRuleMap: ImmutableMap<String, RuleHierarchyEntry>,
) {

  fun getRuleHierarchyEntryOrNull(tokenRuleName: String): RuleHierarchyEntry? {
    return nameToRuleMap[tokenRuleName]
  }

  fun getRuleHierarchyEntryWithNameOrThrow(ruleName: String): RuleHierarchyEntry {
    return nameToRuleMap[ruleName] ?: error("Does not exist a rule for the name $ruleName")
  }

  fun toProtoMessage(): GrammarHierarchyOuterClass.GrammarHierarchy {
    return ruleList.fold(
      GrammarHierarchyOuterClass.GrammarHierarchy.newBuilder(),
    ) { acc, ele ->
      acc.addEntries(ele.toProtoRuleHierarchyEntry())
    }.build()
  }

  companion object {
    @JvmStatic
    fun createFromString(content: String): GrammarHierarchy {
      val rawAst = AntlrGrammarParser.parseRawGrammarASTFromString(content)
      val persesGrammar = PersesAstBuilder(rawAst).grammar
      return createFromCombinedAntlrGrammar(
        AbstractAntlrGrammar.CombinedAntlrGrammar(persesGrammar),
      )
    }

    @JvmStatic
    fun createFromAntlrGrammar(grammar: AbstractAntlrGrammar): GrammarHierarchy {
      return if (grammar.isCombined) {
        createFromCombinedAntlrGrammar(grammar.asCombined())
      } else {
        createFromSeparateAntlrGrammar(grammar.asSeparate())
      }
    }

    private fun createFromCombinedAntlrGrammar(
      grammar: AbstractAntlrGrammar.CombinedAntlrGrammar,
    ): GrammarHierarchy {
      return GrammarHierarchyBuilder(grammar).build()
    }

    private fun createFromSeparateAntlrGrammar(
      grammar: AbstractAntlrGrammar.SeparateAntlrGrammar,
    ): GrammarHierarchy {
      return GrammarHierarchyBuilder(grammar).build()
    }
  }
}
