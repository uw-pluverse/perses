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
package org.perses.reduction.semantics

import com.google.common.collect.HashMultimap
import com.google.common.collect.ImmutableList
import org.jgrapht.Graph
import org.jgrapht.Graphs
import org.jgrapht.alg.connectivity.KosarajuStrongConnectivityInspector
import org.jgrapht.graph.AsSubgraph
import org.jgrapht.graph.DefaultDirectedGraph
import org.jgrapht.graph.DefaultEdge
import org.jgrapht.graph.EdgeReversedGraph
import org.jgrapht.traverse.BreadthFirstIterator
import org.jgrapht.traverse.TopologicalOrderIterator
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.PlaceholderSparTreeNode
import org.perses.util.MutableInt
import org.perses.util.toImmutableList
import java.util.function.Supplier

typealias SccGraph = Graph<AbstractSparTreeNode, ScopedDependencyGraph.DefUseTokenEdge>

class ScopedDependencyGraph(
  // The graph needs to record the semantic tokens.
  // The graph cannot be a DAG, because of two recursive functions, e.g., A calls B and B calls A.
  private val graph: DefaultDirectedGraph<AbstractSparTreeNode, DefUseTokenEdge>,
  val representativeOfExternalUses: PlaceholderSparTreeNode?,
  private val defSemanticTokensUsedExternally:
    HashMultimap<AbstractSparTreeNode, LexerRuleSparTreeNode>,
) {
  private val reversedGraph = EdgeReversedGraph(graph)

  val allNodes: Set<AbstractSparTreeNode>
    get() = graph.vertexSet()

  val allNodesExcludingRepresentativeOfExternalUses: List<AbstractSparTreeNode> by lazy {
    graph.vertexSet().filter { it !== representativeOfExternalUses }
  }

  val nodesUsedExternally: List<AbstractSparTreeNode> by lazy {
    if (representativeOfExternalUses == null) {
      ImmutableList.of()
    } else {
      Graphs.predecessorListOf(graph, representativeOfExternalUses)
    }
  }

  private val inducedSubgraphOfLocallyUsedNodes by lazy {
    AsSubgraph(graph, nodesOnlyUsedLocally)
  }

  val sccCondensationGraph by lazy {
    KosarajuStrongConnectivityInspector(inducedSubgraphOfLocallyUsedNodes).condensation
  }

  fun printGraphStructure(): String {
    val builder = StringBuilder()
    builder.append("Scoped Graph.\n")
    val sortedNodes = allNodes.sortedBy { it.nodeId }
    builder
      .append(INDENT)
      .append("Nodes: ")
      .append(sortedNodes.map { it.nodeId })
      .append("\n")
    builder
      .append(INDENT)
      .append("External Use Node: ")
      .append(representativeOfExternalUses?.nodeId)
      .append("\n")
    sortedNodes.forEach { node ->
      builder
        .append(INDENT)
        .append("Targets of Node ")
        .append(node.nodeId)
        .append(": \n")
      graph
        .outgoingEdgesOf(node)
        .map { edge -> edge to graph.getEdgeTarget(edge) }
        .sortedBy { it.second.nodeId }
        .forEach { (edge, targetNode) ->
          builder.append("    -->").append(targetNode.nodeId.toString().padStart(2, ' '))
          builder
            .append("    Defs:")
            .append(
              edge.defTokens
                .map { it.token.asAntlrToken() }
                .sortedBy {
                  it.position
                }.joinToString(separator = ", ") {
                  it.text + "@" + it.position.toConcisePosition()
                },
            )
          builder
            .append("    Uses:")
            .append(
              edge.useTokens
                .map { it.token.asAntlrToken() }
                .sortedBy {
                  it.position
                }.joinToString(separator = ", ") {
                  it.text + "@" + it.position.toConcisePosition()
                },
            ).append("\n")
        }
    }
    return builder.toString()
  }

  fun areAllNodesIsolated(): Boolean = graph.edgeSet().isEmpty()

  fun areAllLocallyUsedNodesIsolated(): Boolean =
    inducedSubgraphOfLocallyUsedNodes.edgeSet().isEmpty()

  fun getDefTokensUsedExternally(ownerTreeNode: AbstractSparTreeNode): Set<LexerRuleSparTreeNode> =
    defSemanticTokensUsedExternally.get(ownerTreeNode)

  fun computeLayers(): LayerHierarchy<SccGraph> = computeLayersForDAG(sccCondensationGraph)

  internal fun <T : Any, E : DefaultEdge> computeLayersForDAG(
    inducedSubgraph: Graph<T, E>,
  ): LayerHierarchy<T> {
    val outdegreeMap = mutableMapOf<T, MutableInt>()
    if (inducedSubgraph.vertexSet().isEmpty()) {
      return LayerHierarchy.emptyHierarchy()
    }
    inducedSubgraph.vertexSet().forEach { vertex ->
      outdegreeMap[vertex] = MutableInt(inducedSubgraph.outDegreeOf(vertex))
    }
    val hierarchy = ArrayDeque<AbstractLayer<T>>()
    do {
      val newLayer =
        AbstractLayer.Layer(
          outdegreeMap
            .filter { entry ->
              entry.value.get() == 0
            }.map {
              it.key
            }.toImmutableList(),
        )
      newLayer.elements.forEach { leaf ->
        outdegreeMap.remove(leaf)
        Graphs.predecessorListOf(inducedSubgraph, leaf).forEach { predecessor ->
          outdegreeMap[predecessor]!!.incrementBy(-1)
        }
      }
      hierarchy.addFirst(newLayer)
      check(newLayer.elements.isNotEmpty()) {
        "Cycles exist in the graph, and we cannot progress.\n" +
          printGraphStructure()
      }
    } while (outdegreeMap.isNotEmpty())
    return LayerHierarchy(hierarchy.toImmutableList())
  }

  fun getPredecessorNodes(node: AbstractSparTreeNode): List<AbstractSparTreeNode> =
    Graphs.predecessorListOf(graph, node)

  fun getEdge(
    source: AbstractSparTreeNode,
    target: AbstractSparTreeNode,
  ): DefUseTokenEdge? = graph.getEdge(source, target)

  fun getOutgoingEdges(source: AbstractSparTreeNode): Set<DefUseTokenEdge> =
    graph.outgoingEdgesOf(source)

  val nodesWithZeroOutDegree: List<AbstractSparTreeNode> by lazy {
    graph.vertexSet().filter { graph.outDegreeOf(it) == 0 }
  }

  val nodesReachableFromExternalUse: ImmutableList<AbstractSparTreeNode> by lazy {
    when (val node = representativeOfExternalUses) {
      null -> ImmutableList.of()
      else -> {
        getBackwardReachableNodesFrom(listOf(node))
      }
    }
  }

  private val forwardReachableSCCsMap by lazy {
    val result =
      mutableMapOf<SccGraph, Set<SccGraph>>()
    val topoOrder = TopologicalOrderIterator(sccCondensationGraph).asSequence().toList()
    for (scc in topoOrder.asReversed()) {
      val reachable = mutableSetOf(scc)
      for (edge in sccCondensationGraph.outgoingEdgesOf(scc)) {
        val successor = sccCondensationGraph.getEdgeTarget(edge)
        reachable.addAll(result[successor]!!)
      }
      result[scc] = reachable
    }
    result
  }

  fun getForwardReachableNodesFrom(scc: SccGraph): ImmutableList<SccGraph> =
    forwardReachableSCCsMap[scc]?.toImmutableList() ?: ImmutableList.of()

  fun getBackwardReachableNodesFrom(
    startNodes: Iterable<AbstractSparTreeNode>,
  ): ImmutableList<AbstractSparTreeNode> = getReachableNodesFrom(reversedGraph, startNodes)

  private fun <E : DefaultEdge> getReachableNodesFrom(
    graph: Graph<AbstractSparTreeNode, E>,
    startNodes: Iterable<AbstractSparTreeNode>,
  ): ImmutableList<AbstractSparTreeNode> =
    BreadthFirstIterator(graph, startNodes)
      .asSequence()
      .sortedBy { it.nodeId }
      .toImmutableList()

  val nodesOnlyUsedLocally: Set<AbstractSparTreeNode> by lazy {
    if (representativeOfExternalUses == null) {
      allNodes
    } else {
      allNodes.minus(nodesReachableFromExternalUse)
    }
  }

  companion object {
    val EXTERNAL_USE_TREE_NODE =
      PlaceholderSparTreeNode(
        nodeId = Int.MAX_VALUE,
        source = "",
        predicateForCompatibility = { false },
      )

    private val INDENT = "  "
  }

  class Builder {
    private val graph =
      run {
        val vertexSupplier: Supplier<AbstractSparTreeNode>? = null
        val edgeSupplier: Supplier<DefUseTokenEdge> = Supplier { DefUseTokenEdge() }
        val weighted = false
        DefaultDirectedGraph(vertexSupplier, edgeSupplier, weighted)
      }

    private var externalUseTreeNode: PlaceholderSparTreeNode? = null

    private val defSemanticTokensUsedExternally =
      HashMultimap
        .create<AbstractSparTreeNode, LexerRuleSparTreeNode>()

    fun addExternalUseEdge(
      source: AbstractSparTreeNode,
      defSemanticToken: LexerRuleSparTreeNode,
      useSemanticToken: LexerRuleSparTreeNode,
    ) {
      externalUseTreeNode = EXTERNAL_USE_TREE_NODE
      graph.addVertex(EXTERNAL_USE_TREE_NODE)
      val edge =
        graph.addEdge(source, EXTERNAL_USE_TREE_NODE)
          ?: graph.getEdge(source, EXTERNAL_USE_TREE_NODE)
      edge.also {
        it.addDefTokenNode(defSemanticToken)
        it.addUseTokenNode(useSemanticToken)
      }
      defSemanticTokensUsedExternally.put(source, defSemanticToken)
    }

    fun addEdge(
      source: AbstractSparTreeNode,
      target: AbstractSparTreeNode,
      defSemanticToken: LexerRuleSparTreeNode,
      useSemanticToken: LexerRuleSparTreeNode,
    ) {
      try {
        val edge = graph.addEdge(source, target) ?: graph.getEdge(source, target)
        edge.also {
          it.addDefTokenNode(defSemanticToken)
          it.addUseTokenNode(useSemanticToken)
        }
      } catch (e: IllegalArgumentException) {
        val message =
          """
          |source=${source.nodeId}, 
          |target=${target.nodeId}
          |source-tokens=${source.leafNodeSequence().joinToString { it.token.asAntlrToken().text }}
          |target-tokens=${target.leafNodeSequence().joinToString { it.token.asAntlrToken().text }}
          |
          """.trimMargin()
        throw IllegalArgumentException(message, e)
      }
    }

    // TODO(cnsun): add a test to ensure the insertion order is preserved.
    fun addVertex(vertex: AbstractSparTreeNode) {
      graph.addVertex(vertex)
    }

    fun build(): ScopedDependencyGraph =
      ScopedDependencyGraph(
        graph,
        externalUseTreeNode,
        defSemanticTokensUsedExternally,
      )
  }

  class DefUseTokenEdge : DefaultEdge() {
    private val _useTokens = LinkedHashSet<LexerRuleSparTreeNode>()
    val useTokens: Set<LexerRuleSparTreeNode> get() {
      _useTokens.removeIf { it.isPermanentlyDeleted }
      return _useTokens
    }

    private val _defTokens = LinkedHashSet<LexerRuleSparTreeNode>()
    val defTokens: Set<LexerRuleSparTreeNode> get() {
      _defTokens.removeIf { it.isPermanentlyDeleted }
      return _defTokens
    }

    fun addUseTokenNode(node: LexerRuleSparTreeNode) {
      check(!node.isPermanentlyDeleted) { "The node $node has been permanently deleted" }
      _useTokens.add(node)
    }

    fun addDefTokenNode(node: LexerRuleSparTreeNode) {
      check(!node.isPermanentlyDeleted) { "The node $node has been permanently deleted" }
      _defTokens.add(node)
    }
  }
}
