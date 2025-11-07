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
package org.perses.antlr

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import com.google.common.graph.GraphBuilder
import com.google.common.graph.ImmutableGraph
import org.perses.antlr.pnf.UsedRuleNameCollector
import org.perses.util.SimpleQueue

class RuleReachabilityGraph(
  val startRule: RuleHierarchyEntry,
  ruleList: ImmutableList<RuleHierarchyEntry>,
  nameToRuleMap: ImmutableMap<String, RuleHierarchyEntry>,
) {
  val graph: ImmutableGraph<RuleHierarchyEntry> = buildReachabilityGraph(ruleList, nameToRuleMap)

  val numOfIncomingPathsPerNode: ImmutableMap<RuleHierarchyEntry, Int> by lazy {
    buildNumOfIncomingPathsPerNodeMap()
  }

  // TODO(Yiran): need to ignore all back edges including self loops.
  private fun buildNumOfIncomingPathsPerNodeMap(): ImmutableMap<RuleHierarchyEntry, Int> {
    val queue = SimpleQueue<RuleHierarchyEntry>()
    val visitedEdges = mutableSetOf<Pair<RuleHierarchyEntry, RuleHierarchyEntry>>()
    val visitedNodes = mutableSetOf<RuleHierarchyEntry>()
    val initialSources = mutableSetOf<RuleHierarchyEntry>()
    val pathCounts = mutableMapOf<RuleHierarchyEntry, Int>().withDefault { 0 }

    for (node in graph.nodes()) {
      val predecessors = graph.predecessors(node)
      if (predecessors.isEmpty()) {
        queue.add(node)
        initialSources.add(node)
        pathCounts[node] = 1
      }
    }

    while (queue.isNotEmpty()) {
      val current = queue.remove()
      visitedNodes.add(current)

      val successors: Set<RuleHierarchyEntry> = graph.successors(current)
      if (successors.contains(current)) {
        pathCounts[current] = pathCounts.getOrDefault(current, 0) + 1
      }

      for (successor in successors) {
        val prevPaths = pathCounts.getOrDefault(current, 0)
        val edge = current to successor
        if (edge in visitedEdges || current == successor) {
          continue
        } else {
          pathCounts[successor] = prevPaths + pathCounts.getOrDefault(successor, 0)
        }
        visitedEdges.add(edge)
        queue.add(successor)
      }
    }

    for (node in graph.nodes()) {
      if (node !in visitedNodes) {
        pathCounts[node] = computeNumOfPaths(node, mutableSetOf())
      }
    }

    for (node in initialSources) {
      pathCounts[node] = 0
    }
    return ImmutableMap.copyOf(pathCounts)
  }

  private fun computeNumOfPaths(
    rule: RuleHierarchyEntry,
    visited: MutableSet<RuleHierarchyEntry>,
  ): Int {
    val predecessors = graph.predecessors(rule)
    if (visited.isEmpty() && predecessors.isEmpty()) {
      return 0
    }
    if (rule in visited || predecessors.isEmpty()) {
      return 1
    }

    visited.add(rule)
    val paths =
      predecessors.sumOf {
        computeNumOfPaths(it, visited)
      }
    visited.remove(rule)
    return paths
  }

  companion object {
    internal fun buildReachabilityGraph(
      ruleList: ImmutableList<RuleHierarchyEntry>,
      nameToRuleMap: ImmutableMap<String, RuleHierarchyEntry>,
    ): ImmutableGraph<RuleHierarchyEntry> {
      val graph = GraphBuilder.directed().allowsSelfLoops(true).immutable<RuleHierarchyEntry>()

      for (fromRule in ruleList) {
        if (fromRule.ruleDef.isLexerRule) {
          continue
        }
        val ruleRefCollector = UsedRuleNameCollector()
        ruleRefCollector.preorder(fromRule.ruleDef.body)
        ruleRefCollector.ruleReferences.forEach { toRule ->
          graph.putEdge(
            fromRule,
            nameToRuleMap[toRule.ruleName]!!,
          )
        }
      }
      return graph.build()
    }
  }
}
