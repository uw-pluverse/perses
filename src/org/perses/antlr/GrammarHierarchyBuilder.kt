/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import com.google.common.collect.HashMultimap
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import com.google.common.collect.ImmutableSet
import com.google.common.collect.Multimap
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
import org.perses.util.exhaustive
import org.perses.util.toImmutableList
import java.util.ArrayDeque
import java.util.function.Consumer

class GrammarHierarchyBuilder(private val grammar: AbstractAntlrGrammar) {
  private val epsilonInfo: EpsilonInfo
  private val indexToRuleMap: ImmutableList<RuleHierarchyInfo>
  private val nameToRuleMap: ImmutableMap<String, RuleHierarchyInfo>

  private fun extractRuleHierarchyInfo(
    ruleDefinition: AbstractPersesRuleDefAst
  ): RuleHierarchyInfo {
    val immediateSubRules = extractImmediateSubRules(ruleDefinition)
    return RuleHierarchyInfo(
      ruleDefinition, immediateSubRules, epsilonInfo.canBeEpsilon(ruleDefinition)
    )
  }

  private fun extractImmediateSubRules(rule: AbstractPersesRuleDefAst): ImmutableSet<String> {
    if (rule.isLexerRule) {
      return ImmutableSet.of()
    }
    val result = HashSet<String>()
    extractImmediateSubrulesFromBlockAST(rule.body, result)
    return ImmutableSet.copyOf(result)
  }

  // FIXME: need to support lex rules.
  private fun extractImmediateSubrulesFromBlockAST(
    ruleBody: AbstractPersesRuleElement,
    result: HashSet<String>
  ) {
    when (ruleBody.tag) {
      AstTag.ALTERNATIVE_BLOCK ->
        (ruleBody as PersesAlternativeBlockAst).foreachChildRuleElement {
          extractImmediateSubrulesFromBlockAST(it, result)
        }
      AstTag.TERMINAL -> {
        val terminal = ruleBody as PersesTerminalAst
        if (terminal.isEOF() || terminal.isStringLiteral()) {
          return
        }
        result.add(terminal.text)
      }
      AstTag.RULE_REF -> {
        result.add((ruleBody as PersesRuleReferenceAst).ruleNameHandle.ruleName)
      }
      AstTag.STAR, AstTag.PLUS, AstTag.OPTIONAL -> {
        extractImmediateSubrulesFromBlockAST((ruleBody as AbstractPersesQuantifiedAst).body, result)
      }
      AstTag.SEQUENCE -> {
        val seq = ruleBody as PersesSequenceAst
        val unremovableChildren = seq
          .childSequence().filter { !epsilonInfo.canBeEpsilon(it) }.toImmutableList()
        when (unremovableChildren.size) {
          0 -> {
            seq.foreachChildRuleElement { extractImmediateSubrulesFromBlockAST(it, result) }
          }
          1 -> {
            extractImmediateSubrulesFromBlockAST(unremovableChildren.first(), result)
          }
        }
        return
      }
      else -> Unit
    }.exhaustive
  }

  fun build(): GrammarHierarchy {
    buildTransitiveSubtypingRule()
    return GrammarHierarchy(indexToRuleMap, nameToRuleMap)
  }

  private fun buildTransitiveSubtypingRule() {
    val graph = GraphBuilder.directed().allowsSelfLoops(false).build<RuleHierarchyInfo?>()
    indexToRuleMap.forEach { node: RuleHierarchyInfo ->
      graph.addNode(node) // This is necessary, as it can have no immediate subrules.
      for (subruleName in node.immediateSubRuleNames) {
        val subrule = nameToRuleMap[subruleName]
        requireNotNull(subrule) {
          "No subrule for node '$subruleName'. " +
            "Node='${node.ruleName}'. " +
            "Check if there is a definition for '$subruleName'"
        }
        graph.putEdge(node, subrule)
      }
    }

    val worklist = ArrayDeque<RuleHierarchyInfo?>(indexToRuleMap.size * 2)
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
      val newEdges = ArrayList<EndpointPair<RuleHierarchyInfo>>()
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
      .forEach { it.transitiveSubRules = ImmutableSet.copyOf(graph.successors(it)) }
  }

  private fun reverseMultiMap(
    map: Multimap<RuleHierarchyInfo, RuleHierarchyInfo>
  ): Multimap<RuleHierarchyInfo, RuleHierarchyInfo> {
    val inverseDependencies: Multimap<RuleHierarchyInfo, RuleHierarchyInfo> = HashMultimap.create()
    map.entries().forEach {
      inverseDependencies.put(it.value, it.key)
    }
    return inverseDependencies
  }

  private fun buildInitialSubruleGraph(): Multimap<RuleHierarchyInfo, RuleHierarchyInfo> {
    val initialSubruleGraph: Multimap<RuleHierarchyInfo, RuleHierarchyInfo> = HashMultimap.create()
    for (rule in indexToRuleMap) {
      for (subrule in rule.immediateSubRuleNames) {
        assert(nameToRuleMap[subrule] != null) { subrule!! }
        initialSubruleGraph.put(rule, nameToRuleMap[subrule])
      }
    }
    return initialSubruleGraph
  }

  companion object {
    private fun buildNameToRuleMap(
      rules: ImmutableList<RuleHierarchyInfo>
    ): ImmutableMap<String, RuleHierarchyInfo> {
      val builder = ImmutableMap.builder<String?, RuleHierarchyInfo?>()
      rules.forEach(Consumer { rule: RuleHierarchyInfo -> builder.put(rule.ruleName, rule) })
      return builder.build()
    }
  }

  init {
    val combinedRules = grammar.getCombinedRules()
    epsilonInfo = computeEpsilonableRules(combinedRules)
    indexToRuleMap = combinedRules.stream()
      .map { ruleDefinition: AbstractPersesRuleDefAst -> extractRuleHierarchyInfo(ruleDefinition) }
      .collect(ImmutableList.toImmutableList())
    nameToRuleMap = buildNameToRuleMap(indexToRuleMap)
  }
}
