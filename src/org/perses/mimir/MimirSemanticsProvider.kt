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
package org.perses.mimir

import com.google.common.base.MoreObjects
import com.google.common.collect.HashMultimap
import com.google.common.collect.ImmutableList
import org.jgrapht.graph.DefaultEdge
import org.jgrapht.graph.DirectedAcyclicGraph
import org.perses.reduction.semantics.ISemanticsProvider
import org.perses.reduction.semantics.ScopedDependencyGraph
import org.perses.reduction.semantics.SemanticTokenType
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.util.CollectionUtil

// TODO(cnsun): this class needs thorough testing.
class MimirSemanticsProvider internal constructor(
  private val sparTree: SparTree,
  private val semanticTokenTypeMap: MutableMap<LexerRuleSparTreeNode, SemanticTokenType>,
  private val defs: MutableList<LexerRuleSparTreeNode>,
  private val defUseGraph: DirectedAcyclicGraph<LexerRuleSparTreeNode, DefaultEdge>,
) : ISemanticsProvider {
  private val treeNodeToSemanticTokenMap by lazy {
    createTreeNodeToSemanticTokenMap(sparTree)
  }

  private val originalOutDegreeMap: MutableMap<LexerRuleSparTreeNode, Int> =
    defUseGraph
      .vertexSet()
      .associateWith { defUseGraph.outDegreeOf(it) }
      .toMutableMap()

  override fun toString(): String =
    MoreObjects
      .toStringHelper(this)
      .add("semanticTokenTypeMap", semanticTokenTypeMap.size)
      .add("defs", defs.size)
      .add("deUseGraphVertices", defUseGraph.vertexSet().size)
      .add("defUseGraphEdges", defUseGraph.edgeSet().size)
      .toString()

  override fun computedAffectedDefinitionNodes(): ISemanticsProvider.AffectedNodes {
    removeDeletedNodes()
    val outDegreeReduced = ImmutableList.builder<LexerRuleSparTreeNode>()
    val outDegreeZeroed = ImmutableList.builder<LexerRuleSparTreeNode>()
    var numOfNodesWithUnchangedOutDegree = 0
    defUseGraph.vertexSet().forEach { vertex ->
      val newOutDegree = defUseGraph.outDegreeOf(vertex)
      val oldOutDegree =
        originalOutDegreeMap[vertex]
          ?: error("No information for vertex $vertex")
      check(newOutDegree <= oldOutDegree) {
        "The new out degree cannot exceed the old out degree. $newOutDegree, $oldOutDegree"
      }
      if (newOutDegree == 0 && oldOutDegree != 0) {
        outDegreeZeroed.add(vertex)
      } else if (newOutDegree < oldOutDegree) {
        outDegreeReduced.add(vertex)
      } else {
        ++numOfNodesWithUnchangedOutDegree
      }
    }
    return ISemanticsProvider.AffectedNodes(
      numOfNodesWithUnchangedOutDegree = numOfNodesWithUnchangedOutDegree,
      nodesOutDegreeReduced = outDegreeReduced.build(),
      nodesOutDegreeZeroed = outDegreeZeroed.build(),
    )
  }

  private fun createTreeNodeToSemanticTokenMap(
    sparTree: SparTree,
  ): HashMultimap<AbstractSparTreeNode, LexerRuleSparTreeNode> {
    val result = HashMultimap.create<AbstractSparTreeNode, LexerRuleSparTreeNode>()
    defUseGraph.vertexSet().forEach { vertex ->
      result.put(vertex, vertex)
    }
    sparTree.realRoot.postOrderVisit { node ->
      if (node is LexerRuleSparTreeNode) {
        // We have added all semantic tokens into the multimap. All other non-semantic tokens are
        // not added to the multimap.
        return@postOrderVisit
      } else {
        node.childSequence().forEach { child ->
          result.putAll(node, result.get(child))
        }
      }
    }
    return result
  }

  override fun getSemanticTokenTypeFor(lexNode: LexerRuleSparTreeNode): SemanticTokenType? =
    semanticTokenTypeMap[lexNode]

  override fun getSemanticTokensUnderTreeNode(
    treeNode: AbstractSparTreeNode,
  ): Set<LexerRuleSparTreeNode> = treeNodeToSemanticTokenMap.get(treeNode)

  override fun removeDeletedNodes() {
    CollectionUtil.removeElementsFromList(
      list = defs,
      criterionToKeep = { index, element ->
        element.isPermanentlyDeleted.not()
      },
    )
    val deleted = defUseGraph.vertexSet().filter { it.isPermanentlyDeleted }
    deleted.forEach {
      defUseGraph.removeVertex(it)
      originalOutDegreeMap.remove(it)
      semanticTokenTypeMap.remove(it)
    }
  }

  override fun buildScopedDependencyGraph(
    nodes: List<AbstractSparTreeNode>,
  ): ScopedDependencyGraph {
    val semanticToken2SelectedNodeMap =
      HashMultimap
        .create<LexerRuleSparTreeNode, AbstractSparTreeNode>()
    nodes.forEach { selectedNode ->
      val semanticTokens = treeNodeToSemanticTokenMap.get(selectedNode)
      val toBeDeleted = mutableListOf<LexerRuleSparTreeNode>()
      semanticTokens.forEach { semanticToken ->
        if (semanticToken.isPermanentlyDeleted) {
          toBeDeleted.add(semanticToken)
        } else {
          semanticToken2SelectedNodeMap.put(semanticToken, selectedNode)
        }
      }
      toBeDeleted.forEach { treeNodeToSemanticTokenMap.remove(selectedNode, it) }
    }
    val scopedDependencyGraph = ScopedDependencyGraph.Builder()

    // Need to add the vertices first, so that we can add edges.
    nodes.forEach { scopedDependencyGraph.addVertex(it) }
    semanticToken2SelectedNodeMap.asMap().entries.forEach { (defSemanticToken, sourceTreeNodes) ->
      check(!defSemanticToken.isPermanentlyDeleted) {
        "The node ${defSemanticToken.nodeId} has been deleted."
      }
      val toBeDeleted = mutableListOf<LexerRuleSparTreeNode>()
      defUseGraph.outgoingEdgesOf(defSemanticToken).forEach { useEdge ->
        val useSemanticToken = defUseGraph.getEdgeTarget(useEdge)
        if (useSemanticToken.isPermanentlyDeleted) {
          toBeDeleted.add(useSemanticToken)
          return@forEach
        }
        check(useSemanticToken.isPermanentlyDeleted.not()) {
          "The node ${useSemanticToken.nodeId} has been deleted."
        }
        val targetTreeNodes = semanticToken2SelectedNodeMap[useSemanticToken]
        if (targetTreeNodes.isEmpty()) {
          // The useSemanticToken is not in the semanticToken2SelectedNodeMap.
          sourceTreeNodes.forEach { sourceNode ->
            scopedDependencyGraph.addExternalUseEdge(
              source = sourceNode,
              defSemanticToken = defSemanticToken,
              useSemanticToken = useSemanticToken,
            )
          }
        } else {
          sourceTreeNodes.forEach { source ->
            targetTreeNodes.forEach { target ->
              if (source !== target) {
                scopedDependencyGraph.addEdge(
                  source = source,
                  target = target,
                  defSemanticToken = defSemanticToken,
                  useSemanticToken = useSemanticToken,
                )
              }
            }
          }
        }
      }
      toBeDeleted.forEach { defUseGraph.removeVertex(it) }
    }
    return scopedDependencyGraph.build()
  }

  fun dumpGraph(): String {
    val comparator =
      compareBy<LexerRuleSparTreeNode> {
        it.token
          .asAntlrToken()
          .position.line
      }.thenComparing {
        it.token
          .asAntlrToken()
          .position.charPositionInLine
      }
    val result = StringBuilder()
    defs.forEach { def ->
      val defToken = def.token.asAntlrToken()
      val semanticTokenType = getSemanticTokenTypeFor(def)!!
      result.append(
        "def:${defToken.lexemeText}@${defToken.position.line}:${semanticTokenType.typeName}\n",
      )
      defUseGraph
        .outgoingEdgesOf(def)
        .map {
          defUseGraph.getEdgeTarget(it)
        }.sortedWith(comparator)
        .forEach { use ->
          val useToken = use.token.asAntlrToken()
          result.append(useToken.lexemeText).append("@${useToken.position.line}").append('\n')
        }
    }
    return result.toString()
  }
}
