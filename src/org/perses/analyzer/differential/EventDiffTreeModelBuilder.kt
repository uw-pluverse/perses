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
package org.perses.analyzer.differential

import org.perses.listener.DifferentialEvents
import javax.swing.tree.DefaultMutableTreeNode
import javax.swing.tree.DefaultTreeModel
import kotlin.math.roundToInt

data class NodeId(
  val nodeId: Int,
  val fixpointIteration: Int,
  val sequence: Int,
)

data class TreeNodeData(
  val label: String,
  val nodeId: NodeId? = null,
) {
  override fun toString(): String = label
}

object EventDiffTreeModelBuilder {
  fun createEventTreeModel(
    title: String,
    events: List<DifferentialEvents.NodeReductionEvent>,
  ): Pair<DefaultTreeModel, Map<NodeId, DefaultMutableTreeNode>> {
    val nodeMap = mutableMapOf<NodeId, DefaultMutableTreeNode>()
    val root = DefaultMutableTreeNode(TreeNodeData(title))
    val nodeIdSequenceMap = mutableMapOf<Pair<Int, Int>, Int>()

    var nodeCounter = 0
    var globalEditCounter = 0

    val iterations = events.groupBy { it.fixpointIteration }

    for ((iteration, iterationEvents) in iterations) {
      val iterationNode =
        DefaultMutableTreeNode(
          TreeNodeData(
            computeIterationTreeNodeLabel(iteration, iterationEvents),
          ),
        )
      root.add(iterationNode)

      for (event in iterationEvents) {
        nodeCounter++
        val sequenceKey = event.nodeId to event.fixpointIteration
        val sequence = nodeIdSequenceMap.getOrDefault(sequenceKey, 0)
        nodeIdSequenceMap[sequenceKey] = sequence + 1
        val nodeId = NodeId(event.nodeId, event.fixpointIteration, sequence)
        // Event Header Node
        val deletedTokens = event.deletedTokenCount
        val nodeLabel =
          buildString {
            append("[#$nodeCounter] ")
            append("Node ").append(event.nodeId).append(":")
            if (deletedTokens > 0) {
              append("[-$deletedTokens tokens]:")
            }
            append(" ${event.ruleType ?: "<unknown_rule>"}")
            append(" [Time: ${event.startPersesTimeSeconds}->${event.endPersesTimeSeconds}s]")
            append(" [Edits: ${event.editsTested.size}]")
          }
        val eventNode =
          DefaultMutableTreeNode(
            TreeNodeData(
              if (deletedTokens > 0) {
                highlightTextInGreen(nodeLabel)
              } else {
                nodeLabel
              },
              nodeId,
            ),
          )
        nodeMap[nodeId] = eventNode

        eventNode.add(
          DefaultMutableTreeNode(
            TreeNodeData("Rule: ${event.ruleName}"),
          ),
        )
        // Basic Stats
        eventNode.add(
          DefaultMutableTreeNode(
            TreeNodeData(
              "Children Before: ${event.childrenBeforeReduction.size}#${event.childrenBeforeReduction}",
            ),
          ),
        )
        eventNode.add(
          DefaultMutableTreeNode(
            TreeNodeData(
              "Children After: ${event.childrenAfterReduction.size}#${event.childrenAfterReduction}",
            ),
          ),
        )
        val childrenDeleted =
          event.childrenBeforeReduction
            .minus(
              event.childrenAfterReduction,
            ).sorted()
        val childrenDeletedNode =
          DefaultMutableTreeNode(
            TreeNodeData(
              "Children Deleted: ${childrenDeleted.size}#$childrenDeleted",
            ),
          )
        for (child in childrenDeleted) {
          childrenDeletedNode.add(
            DefaultMutableTreeNode(
              TreeNodeData("Child $child"),
            ),
          )
        }
        eventNode.add(childrenDeletedNode)

        // Edits Subtree
        if (event.editsTested.isNotEmpty()) {
          val timeList = event.editsTested.map { it.propertyTestResult.elapsedMillis }
          val maxTime = timeList.maxOrNull()
          val minTime = timeList.minOrNull()
          val totalTime = "%.2f".format(timeList.sum() / 1000.0)
          val averageTime = timeList.average().roundToInt()
          val stats =
            buildString {
              append(
                "[min=${minTime}ms,max=${maxTime}ms,average=${averageTime}ms,total=${totalTime}s]",
              )
              append(
                " [${event.editsTested.count { it.propertyTestResult.isInteresting }} interesting]",
              )
            }
          val editsRoot =
            DefaultMutableTreeNode(
              TreeNodeData(
                "EditsTested:[${event.editsTested.size}] $stats",
              ),
            )
          for (edit in event.editsTested) {
            globalEditCounter++
            val propertyTestResult = edit.propertyTestResult
            val text =
              "[#$globalEditCounter]" +
                " [-${edit.deletedTokenCount} tokens]" +
                " [Time: ${edit.startPersesTimeSeconds}s]" +
                if (propertyTestResult.isInteresting) {
                  " ✅"
                } else {
                  ""
                } +
                " ${edit.structureDescription}"
            val editNode =
              DefaultMutableTreeNode(
                TreeNodeData(
                  if (propertyTestResult.isInteresting) {
                    highlightTextInGreen(text)
                  } else {
                    text
                  },
                ),
              )
            editNode.add(
              DefaultMutableTreeNode(TreeNodeData("Context: ${edit.contextualDescription}")),
            )
            editNode.add(
              DefaultMutableTreeNode(TreeNodeData("Time: ${propertyTestResult.elapsedMillis} ms")),
            )

            // Show a snippet of the code
            val rawCode = edit.successfullyDeletedCode
            if (rawCode.contains("\n")) {
              val deletedCodeRoot = DefaultMutableTreeNode(TreeNodeData("Deleted Code:"))
              rawCode.lines().forEach { line ->
                if (line.isNotBlank()) {
                  deletedCodeRoot.add(DefaultMutableTreeNode(TreeNodeData(line)))
                }
              }
              editNode.add(deletedCodeRoot)
            } else {
              val codeSnippet =
                if (rawCode.length > 60) {
                  rawCode.take(60) + "..."
                } else {
                  rawCode
                }
              editNode.add(DefaultMutableTreeNode(TreeNodeData("Deleted Code: $codeSnippet")))
            }

            editsRoot.add(editNode)
          }
          eventNode.add(editsRoot)
        }

        iterationNode.add(eventNode)
      }
    }
    return DefaultTreeModel(root) to nodeMap
  }

  private fun computeIterationTreeNodeLabel(
    iteration: Int,
    iterationEvents: List<DifferentialEvents.NodeReductionEvent>,
  ): String =
    buildString {
      append("Iteration $iteration")

      append(" [${iterationEvents.size} nodes]")
      val tokenDeleted =
        if (iterationEvents.isEmpty()) {
          0
        } else {
          iterationEvents.sumOf { it.deletedTokenCount }
        }
      val (startTime, endTime) =
        if (iterationEvents.isEmpty()) {
          0 to 0
        } else {
          iterationEvents.first().startPersesTimeSeconds to
            iterationEvents.last().endPersesTimeSeconds
        }
      append(" [-$tokenDeleted tokens]")
      val (interestingEdits, uninterestingEdits) =
        iterationEvents.flatMap { it.editsTested }.partition {
          it.propertyTestResult.isInteresting
        }
      val totalEdits = interestingEdits.size + uninterestingEdits.size
      append(" [#edits=$totalEdits=${interestingEdits.size}-I/${uninterestingEdits.size}-U]")
      append(" [${endTime - startTime}s=$startTime-$endTime]")
    }

  fun findCorrespondingNode(
    sourceNode: DefaultMutableTreeNode,
    targetNodeMap: Map<NodeId, DefaultMutableTreeNode>,
  ): DefaultMutableTreeNode? {
    if (sourceNode.isRoot) {
      return targetNodeMap.values.firstOrNull()?.root as? DefaultMutableTreeNode
    }

    // Case 1: The node itself has a nodeId (it's an EventNode)
    val data = sourceNode.userObject as? TreeNodeData
    if (data?.nodeId != null) {
      return targetNodeMap[data.nodeId]
    }

    // Case 2: Recursively check (works for any level of nesting)
    val parent = sourceNode.parent as? DefaultMutableTreeNode ?: return null
    val targetParent = findCorrespondingNode(parent, targetNodeMap) ?: return null
    val index = parent.getIndex(sourceNode)
    if (index >= 0 && index < targetParent.childCount) {
      return targetParent.getChildAt(index) as? DefaultMutableTreeNode
    }

    return null
  }

  fun highlightTextInGreen(text: String): String =
    "<html><font color='#008000'><b>$text</b></font></html>"
}
