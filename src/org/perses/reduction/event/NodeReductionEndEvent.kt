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

import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.ParserRuleSparTreeNode
import org.perses.util.transformToImmutableList

class NodeReductionEndEvent internal constructor(
  startEvent: NodeReductionStartEvent,
  currentTimeMillis: Long,
  perFileSizeMetrics: PerFileSizeMetrics,
  // Do not make the node a property, as the event is usually used asynchronously.
  node: AbstractSparTreeNode,
  val remainingQueueSize: Int,
) : AbstractEndEvent<NodeReductionStartEvent>(startEvent, currentTimeMillis, perFileSizeMetrics) {
  val iteration = startEvent.iteration

  val nodeInfo =
    NodeReductionStartEvent.NodeInfo(
      nodeId = node.nodeId,
      antlrRuleName = node.ruleName,
      ruleType =
        if (node is ParserRuleSparTreeNode) {
          node.ruleType
        } else {
          null
        },
      childNodeIds = node.immutableChildView.transformToImmutableList { it.nodeId },
      tokenCount =
        if (node.isPermanentlyDeleted) {
          0
        } else {
          node.leafTokenCount
        },
    )

  override fun initialPerFileSizeMetrics(): PerFileSizeMetrics =
    startEvent.initialPerFileSizeMetrics()
}
