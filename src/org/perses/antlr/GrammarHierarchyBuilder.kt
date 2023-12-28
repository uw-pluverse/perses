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
import com.google.common.collect.ImmutableSet
import com.google.common.graph.EndpointPair
import com.google.common.graph.GraphBuilder
import org.perses.antlr.ast.AbstractPersesQuantifiedAst
import org.perses.antlr.ast.AbstractPersesRuleDefAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.EpsilonInfo
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.PersesTerminalAst
import org.perses.antlr.ast.RuleEpsilonComputer.Companion.computeEpsilonableRules
import org.perses.util.toImmutableList
import java.util.ArrayDeque

class GrammarHierarchyBuilder(grammar: AbstractAntlrGrammar) {
  private val combinedRules = grammar.getCombinedRules()
  private val epsilonInfo: EpsilonInfo = computeEpsilonableRules(combinedRules)
  private val indexToRuleMap = combinedRules.asSequence()
    .map { extractRuleHierarchyInfo(it) }
    .toImmutableList()
  private val nameToRuleMap: ImmutableMap<String, RuleHierarchyEntry> =
    buildNameToRuleMap(indexToRuleMap)

  private fun extractRuleHierarchyInfo(
    ruleDefinition: AbstractPersesRuleDefAst,
  ): RuleHierarchyEntry {
    val immediateSubRules = extractImmediateSubRules(ruleDefinition)
    return RuleHierarchyEntry(
      ruleDefinition,
      immediateSubRules.ruleNames,
      immediateSubRules.literals,
      epsilonInfo.canBeEpsilon(ruleDefinition),
    )
  }

  private fun printCombinedRules() {
    combinedRules.joinToString(separator = "\n") { it.sourceCode }.let {
      println("The rules are:")
      println(it)
    }
  }

  private data class RulesAndLiterals(
    val ruleNames: ImmutableSet<String>,
    val literals: ImmutableSet<String>,
  )

  private fun extractImmediateSubRules(rule: AbstractPersesRuleDefAst): RulesAndLiterals {
    if (rule.isLexerRule) {
      val body = rule.body
      val literals: ImmutableSet<String> =
        if (body is PersesTerminalAst && body.isStringLiteral()) {
          ImmutableSet.of(body.getStringLiteralOrThrow())
        } else {
          ImmutableSet.of()
        }
      return RulesAndLiterals(
        ruleNames = ImmutableSet.of(),
        literals,
      )
    } else {
      val ruleNameCollector = HashSet<String>()
      val literalCollector = HashSet<String>()
      extractImmediateSubrulesFromBlockAST(rule.body, ruleNameCollector, literalCollector)
      return RulesAndLiterals(
        ruleNames = ImmutableSet.copyOf(ruleNameCollector),
        literals = ImmutableSet.copyOf(literalCollector),
      )
    }
  }

  // FIXME: need to support lex rules.
  private fun extractImmediateSubrulesFromBlockAST(
    ruleBody: AbstractPersesRuleElement,
    ruleNameCollector: HashSet<String>,
    literalCollector: HashSet<String>,
  ) {
    when (ruleBody.tag) {
      AstTag.ALTERNATIVE_BLOCK ->
        (ruleBody as PersesAlternativeBlockAst).foreachChildRuleElement {
          extractImmediateSubrulesFromBlockAST(it, ruleNameCollector, literalCollector)
        }

      AstTag.TERMINAL -> {
        val terminal = ruleBody as PersesTerminalAst
        when {
          terminal.isEOF() -> Unit
          terminal.isStringLiteral() -> literalCollector.add(terminal.getStringLiteralOrThrow())
          terminal.isWildcardDot() -> Unit
          else -> ruleNameCollector.add(terminal.text)
        }
      }

      AstTag.RULE_REF -> {
        ruleNameCollector.add((ruleBody as PersesRuleReferenceAst).ruleNameHandle.ruleName)
      }

      AstTag.STAR, AstTag.PLUS, AstTag.OPTIONAL -> {
        extractImmediateSubrulesFromBlockAST(
          (ruleBody as AbstractPersesQuantifiedAst).body,
          ruleNameCollector,
          literalCollector,
        )
      }

      AstTag.SEQUENCE -> {
        val seq = ruleBody as PersesSequenceAst
        val unremovableChildren = seq
          .childSequence().filter { !epsilonInfo.canBeEpsilon(it) }.toImmutableList()
        when (unremovableChildren.size) {
          0 -> seq.foreachChildRuleElement {
            extractImmediateSubrulesFromBlockAST(
              it,
              ruleNameCollector,
              literalCollector,
            )
          }

          1 -> extractImmediateSubrulesFromBlockAST(
            unremovableChildren.single(),
            ruleNameCollector,
            literalCollector,
          )

          else -> {}
        }
      }

      else -> {}
    }
  }

  fun build(): GrammarHierarchy {
    buildTransitiveSubtypingRule()
    return GrammarHierarchy(indexToRuleMap, nameToRuleMap)
  }

  private fun buildTransitiveSubtypingRule() {
    val graph = GraphBuilder.directed().allowsSelfLoops(false).build<RuleHierarchyEntry?>()
    indexToRuleMap.forEach { node: RuleHierarchyEntry ->
      graph.addNode(node) // This is necessary, as it can have no immediate subrules.
      for (subruleName in node.immediateSubRuleNames) {
        val subrule = nameToRuleMap[subruleName]
        requireNotNull(subrule) {
          "No subrule for node '$subruleName', Node='${node.ruleName}'. " +
            "Check if there is a definition for '$subruleName'\n\n" +
            combinedRules.joinToString(separator = "\n") { it.sourceCode }
        }
        graph.putEdge(node, subrule)
      }
    }

    val worklist = ArrayDeque<RuleHierarchyEntry?>(indexToRuleMap.size * 2)
    for (rule in indexToRuleMap) {
      if (graph.outDegree(rule) == 0) {
        worklist.addFirst(rule) // Put leaves at the head.
      } else {
        worklist.addLast(rule) // Put non-leaves at the tail.
      }
    }
    while (!worklist.isEmpty()) {
      val workitem = worklist.pollFirst()!! // Always prefer the leaves.
      val subrules = graph.successors(workitem)
      val prevSize = subrules.size
      val newEdges = ArrayList<EndpointPair<RuleHierarchyEntry>>()
      for (subrule in subrules) {
        for (subsubrule in graph.successors(subrule)) {
          if (!graph.hasEdgeConnecting(workitem, subsubrule)) {
            newEdges.add(EndpointPair.ordered(workitem, subsubrule))
          }
        }
      }
      for (edge in newEdges) {
        if (graph.hasEdgeConnecting(edge.source(), edge.target())) {
          continue
        }
        graph.putEdge(edge.source(), edge.target())
      }
      if (prevSize != graph.outDegree(workitem)) {
        graph.predecessors(workitem).forEach { worklist.addFirst(it) }
      }
    }
    graph
      .nodes()
      .forEach {
        it.transitiveSubRules = ImmutableSet.copyOf(graph.successors(it))
      }
  }

  companion object {
    private fun buildNameToRuleMap(
      rules: ImmutableList<RuleHierarchyEntry>,
    ): ImmutableMap<String, RuleHierarchyEntry> {
      val builder = ImmutableMap.builder<String?, RuleHierarchyEntry?>()
      rules.forEach { builder.put(it.ruleName, it) }
      return builder.build()
    }
  }
}
