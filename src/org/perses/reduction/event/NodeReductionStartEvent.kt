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
package org.perses.reduction.event

import com.google.common.collect.ImmutableList
import org.perses.program.TokenizedProgram
import org.perses.spartree.AbstractSparTreeNode
import org.perses.util.FileNameContentPair

class NodeReductionStartEvent internal constructor(
  val currentFixpointIteration: FixpointIterationStartEvent,
  currentTimeMillis: Long,
  val program: TokenizedProgram,
  private val node: AbstractSparTreeNode,
  outputCreator: (TokenizedProgram) -> ImmutableList<FileNameContentPair<String>>,
) : AbstractStartEvent(currentTimeMillis, programSize = program.tokenCount) {
  val textualProgram = LazyProgramOutputer(program, outputCreator)

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
      childCount = node.childCount,
      tokenCount = node.leafTokenCount,
    )

  fun getReducerName() = currentFixpointIteration.reducerClass.shortName

  fun createEndEvent(
    currentTimeMillis: Long,
    program: TokenizedProgram,
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
      program = program,
      node = node,
      remainingQueueSize = remainingQueueSize,
    )
  }

  override fun initialProgramSize(): Int = currentFixpointIteration.initialProgramSize()

  data class NodeInfo(
    val nodeId: Int,
    val antlrRuleName: String?,
    val childCount: Int,
    val tokenCount: Int,
  ) {
    override fun toString(): String =
      buildString {
        append("Node(")
        append(nodeId).append(',')
        append("antlr=").append(antlrRuleName ?: "<n.a.>").append(',')
        append("#children=").append(childCount).append(',')
        append("#tokens=").append(tokenCount)
        append(')')
      }
  }
}
