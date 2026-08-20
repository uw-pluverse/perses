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
package org.perses.reduction.event

import com.google.common.collect.ImmutableList
import org.perses.antlr.RuleType
import org.perses.program.ProgramSize
import org.perses.program.TokenizedProgram
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.ParserRuleSparTreeNode
import org.perses.util.FileNameContentPair
import org.perses.util.transformToImmutableList

class NodeReductionStartEvent internal constructor(
  val currentFixpointIteration: FixpointIterationStartEvent,
  currentTimeMillis: Long,
  perFileSizeMetrics: PerFileSizeMetrics,
  val program: ProgramSize<TokenizedProgram>,
  private val node: AbstractSparTreeNode,
  outputCreator: (TokenizedProgram) -> ImmutableList<FileNameContentPair<String>>,
) : AbstractStartEvent(currentTimeMillis, perFileSizeMetrics) {
  val textualProgram = LazyProgramOutputer(program.payload, outputCreator)

  val iteration = currentFixpointIteration.iteration

  override val prefixLabelFromRootToHere: String
    get() = currentFixpointIteration.prefixLabelFromRootToHere

  // Needs to store the information at the creation of this event, due to the aysnc nature of the
  // listeners. It is possible that when the listeners are processing the event, the node might
  // have been deleted already.
  val nodeInfo =
    NodeInfo(
      nodeId = node.nodeId,
      antlrRuleName = node.ruleName,
      ruleType =
        if (node is ParserRuleSparTreeNode) {
          node.ruleType
        } else {
          null
        },
      childNodeIds = node.immutableChildView.transformToImmutableList { it.nodeId },
      tokenCount = node.leafTokenCount,
    )

  fun getReducerName() = currentFixpointIteration.reducerClass.shortName

  fun createEndEvent(
    currentTimeMillis: Long,
    perFileSizeMetrics: PerFileSizeMetrics,
    remainingQueueSize: Int,
  ): NodeReductionEndEvent {
    check(!ended) {
      "An end event has been created."
    }
    ended = true
    check(node.nodeId == nodeInfo.nodeId)
    return NodeReductionEndEvent(
      startEvent = this,
      currentTimeMillis = currentTimeMillis,
      perFileSizeMetrics = perFileSizeMetrics,
      node = node,
      remainingQueueSize = remainingQueueSize,
    )
  }

  override fun initialPerFileSizeMetrics(): PerFileSizeMetrics =
    currentFixpointIteration.initialPerFileSizeMetrics()

  data class NodeInfo(
    val nodeId: Int,
    val antlrRuleName: String?,
    val ruleType: RuleType?,
    val childNodeIds: ImmutableList<Int>,
    val tokenCount: Int,
  ) {
    val childCount: Int get() = childNodeIds.size

    override fun toString(): String =
      buildString {
        append("Node(")
        append(nodeId).append(',')
        append("antlr=").append(antlrRuleName ?: "<n.a.>").append(',')
        append("rule_type=").append(ruleType?.name ?: "<n.a.>").append(',')
        append("#children=").append(childCount).append(',')
        append("#tokens=").append(tokenCount)
        append(')')
      }
  }
}
