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
package org.perses.reduction.reducer

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.jgrapht.graph.DefaultDirectedGraph
import org.jgrapht.graph.DefaultEdge
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.semantics.SccGraph
import org.perses.reduction.semantics.ScopedDependencyGraph
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.PlaceholderSparTreeNode

@RunWith(JUnit4::class)
class MimirStrategyFinerDagAsListTest {
  private fun createNode(id: Int): AbstractSparTreeNode =
    PlaceholderSparTreeNode(
      nodeId = id,
      source = "mock-$id",
      predicateForCompatibility = { false },
    )

  private fun createScc(vararg nodes: AbstractSparTreeNode): SccGraph {
    val graph =
      DefaultDirectedGraph<AbstractSparTreeNode, ScopedDependencyGraph.DefUseTokenEdge>(
        ScopedDependencyGraph.DefUseTokenEdge::class.java,
      )
    nodes.forEach { graph.addVertex(it) }
    return graph
  }

  @Test
  fun testSweepZeroedSccs_LastLayerDeletedScc() {
    val strategy = MimirStrategyFinerDagAsList()

    val node1 = createNode(1).apply { delete() }
    val scc1 = createScc(node1)

    val condensationGraph = DefaultDirectedGraph<SccGraph, DefaultEdge>(DefaultEdge::class.java)
    condensationGraph.addVertex(scc1)

    val layers = ImmutableList.of(ImmutableList.of(scc1))

    strategy.sweepZeroedSccs(layers, condensationGraph) {
      AbstractSparTreeReducer.EditApplicationResult.NO
    }

    // scc1 should be removed because all its nodes are deleted
    assertThat(condensationGraph.vertexSet()).isEmpty()
  }

  @Test
  fun testSweepZeroedSccs_SweepingZeroOutDegreeSccs() {
    val strategy = MimirStrategyFinerDagAsList()

    val node1 = createNode(1)
    val node2 = createNode(2)
    val node3 = createNode(3)

    val scc1 = createScc(node1)
    val scc2 = createScc(node2)
    val scc3 = createScc(node3)

    val condensationGraph = DefaultDirectedGraph<SccGraph, DefaultEdge>(DefaultEdge::class.java)
    condensationGraph.addVertex(scc1)
    condensationGraph.addVertex(scc2)
    condensationGraph.addVertex(scc3)

    // scc1 -> scc2
    condensationGraph.addEdge(scc1, scc2)

    val layers =
      ImmutableList.of(
        ImmutableList.of(scc1),
        ImmutableList.of(scc2, scc3),
      )

    val deletedSccs = mutableSetOf<SccGraph>()

    strategy.sweepZeroedSccs(layers, condensationGraph) { nodes ->
      val scc = layers.flatten().find { it.vertexSet() == nodes.toSet() }!!
      deletedSccs.add(scc)
      AbstractSparTreeReducer.EditApplicationResult.APPLIED
    }

    // Nothing is removed because scc2 and scc3 are not deleted in the last layer.
    // scc1 has out-degree 1.
    assertThat(deletedSccs).isEmpty()
    assertThat(condensationGraph.vertexSet()).containsExactly(scc1, scc2, scc3)

    // Now if we mock that scc2 was deleted by some other means (or was empty)
    condensationGraph.removeVertex(scc2)

    strategy.sweepZeroedSccs(layers, condensationGraph) { nodes ->
      val scc = layers.flatten().find { it.vertexSet() == nodes.toSet() }!!
      deletedSccs.add(scc)
      AbstractSparTreeReducer.EditApplicationResult.APPLIED
    }

    // Now scc1 has out-degree 0. It should be swept.
    assertThat(deletedSccs).contains(scc1)
    assertThat(condensationGraph.vertexSet()).doesNotContain(scc1)
    assertThat(condensationGraph.vertexSet()).containsExactly(scc3)
  }

  @Test
  fun testSweepZeroedSccs_CascadeSweeping() {
    val strategy = MimirStrategyFinerDagAsList()

    val scc1 = createScc(createNode(1))
    val scc2 = createScc(createNode(2))
    val scc3 = createScc(createNode(3))

    val condensationGraph = DefaultDirectedGraph<SccGraph, DefaultEdge>(DefaultEdge::class.java)
    condensationGraph.addVertex(scc1)
    condensationGraph.addVertex(scc2)
    condensationGraph.addVertex(scc3)

    // scc1 -> scc2 -> scc3
    condensationGraph.addEdge(scc1, scc2)
    condensationGraph.addEdge(scc2, scc3)

    val layers =
      ImmutableList.of(
        ImmutableList.of(scc1),
        ImmutableList.of(scc2),
        ImmutableList.of(scc3),
      )

    // Mark scc3 node as deleted
    val scc3node = scc3.vertexSet().first()
    scc3node.delete()

    strategy.sweepZeroedSccs(layers, condensationGraph) {
      AbstractSparTreeReducer.EditApplicationResult.APPLIED
    }

    // Last layer pass: removes scc3.
    // Layer 1 pass: scc2 now has out-degree 0, so it's deleted and removed from graph.
    // Layer 0 pass: scc1 now has out-degree 0, so it's deleted and removed from graph.

    assertThat(condensationGraph.vertexSet()).isEmpty()
  }

  @Test
  fun testSweepZeroedSccs_AlreadyDeletedMidLayerScc() {
    val strategy = MimirStrategyFinerDagAsList()

    val node1 = createNode(1)
    val node2 = createNode(2).apply { delete() } // Already deleted
    val node3 = createNode(3).apply { delete() } // Already deleted

    val scc1 = createScc(node1)
    val scc2 = createScc(node2)
    val scc3 = createScc(node3)

    val condensationGraph = DefaultDirectedGraph<SccGraph, DefaultEdge>(DefaultEdge::class.java)
    condensationGraph.addVertex(scc1)
    condensationGraph.addVertex(scc2)
    condensationGraph.addVertex(scc3)

    // scc1 -> scc2 -> scc3
    condensationGraph.addEdge(scc1, scc2)
    condensationGraph.addEdge(scc2, scc3)

    val layers =
      ImmutableList.of(
        ImmutableList.of(scc1),
        ImmutableList.of(scc2),
        ImmutableList.of(scc3),
      )

    // This should NOT throw IllegalStateException.
    // We call createByDeletingNodes inside the lambda to simulate production behavior.
    strategy.sweepZeroedSccs(layers, condensationGraph) { nodes ->
      NodeDeletionActionSet.createByDeletingNodes(nodes, "test")
      AbstractSparTreeReducer.EditApplicationResult.APPLIED
    }

    assertThat(condensationGraph.vertexSet()).isEmpty()
  }
}
