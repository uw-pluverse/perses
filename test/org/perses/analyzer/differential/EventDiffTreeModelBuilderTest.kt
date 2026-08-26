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

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.perses.antlr.RuleType
import org.perses.listener.DifferentialEvents
import org.perses.util.FileSystemUtil
import org.perses.util.shell.ExitCode
import javax.swing.tree.DefaultMutableTreeNode
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText

class EventDiffTreeModelBuilderTest {
  private val tempDir = FileSystemUtil.createTempDirForObject(this)

  @OptIn(ExperimentalPathApi::class)
  @After
  fun tearDown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testNodeMapPopulation() {
    val event1 =
      DifferentialEvents.NodeReductionEvent(
        fixpointIteration = 1,
        startPersesTimeSeconds = 1,
        endPersesTimeSeconds = 2,
        nodeId = 10,
        ruleName = "RuleA",
        ruleType = RuleType.KLEENE_PLUS,
        childrenBeforeReduction = ImmutableList.of(),
        deletedTokenCount = 0,
        childrenAfterReduction = ImmutableList.of(),
        editsTested =
          ImmutableList.of(
            DifferentialEvents.Edit(
              contextualDescription = "Edit1",
              structureDescription = "Struct1",
              propertyTestResult = org.perses.reduction.TestScriptVerdict(ExitCode.ZERO, 100),
              successfullyDeletedCode = "code",
              deletedTokenCount = 1,
              startPersesTimeSeconds = 10,
            ),
          ),
      )
    val event2 =
      DifferentialEvents.NodeReductionEvent(
        fixpointIteration = 2,
        startPersesTimeSeconds = 3,
        endPersesTimeSeconds = 4,
        nodeId = 10, // Same nodeId, should have different fixpointIteration
        ruleName = "RuleB",
        ruleType = RuleType.OPTIONAL,
        childrenBeforeReduction = ImmutableList.of(),
        deletedTokenCount = 0,
        childrenAfterReduction = ImmutableList.of(),
        editsTested = ImmutableList.of(),
      )

    val path = tempDir.resolve("a.yaml")
    DifferentialEvents.writeToYamlFile(ImmutableList.of(event1, event2), path)
    path.readText().let { text ->
      assertThat(text).contains(RuleType.KLEENE_PLUS.toString())
      assertThat(text).contains(RuleType.OPTIONAL.toString())
    }
    val events = DifferentialEvents.readFromYamlFile(path)
    assertThat(events.first()).isEqualTo(event1)
    assertThat(events.last()).isEqualTo(event2)
    val (_, nodeMap) = EventDiffTreeModelBuilder.createEventTreeModel("Title", events)

    assertThat(nodeMap).hasSize(2)
    assertThat(nodeMap.keys).containsExactly(NodeId(10, 1, 0), NodeId(10, 2, 0))

    val node1 = nodeMap[NodeId(10, 1, 0)]!!
    val data1 = node1.userObject as TreeNodeData
    assertThat(data1.label).contains("[#1]")
    assertThat(data1.label).contains(RuleType.KLEENE_PLUS.toString())
    assertThat(data1.nodeId).isEqualTo(NodeId(10, 1, 0))

    // Check Iteration grouping
    val iterNode1 = node1.parent as DefaultMutableTreeNode
    assertThat(iterNode1.userObject.toString()).startsWith("Iteration 1")

    // Check edit numbering
    val editsTestedNode =
      node1.children().asSequence().first {
        (it as DefaultMutableTreeNode).userObject.toString().contains("EditsTested")
      } as DefaultMutableTreeNode
    val editNode = editsTestedNode.children().asSequence().first() as DefaultMutableTreeNode
    assertThat(editNode.userObject.toString()).contains("[#1]")

    val node2 = nodeMap[NodeId(10, 2, 0)]!!
    val data2 = node2.userObject as TreeNodeData
    assertThat(data2.label).contains("[#2]")
    assertThat(data2.label).contains(RuleType.OPTIONAL.toString())
    assertThat(data2.nodeId).isEqualTo(NodeId(10, 2, 0))

    val iterNode2 = node2.parent as DefaultMutableTreeNode
    assertThat(iterNode2.userObject.toString()).startsWith("Iteration 2")
  }

  @Test
  fun testMultipleVisitsCorrespondence() {
    val eventA1 =
      DifferentialEvents.NodeReductionEvent(
        fixpointIteration = 1,
        startPersesTimeSeconds = 1,
        endPersesTimeSeconds = 2,
        nodeId = 50,
        ruleName = "Rule",
        ruleType = RuleType.KLEENE_STAR,
        childrenBeforeReduction = ImmutableList.of(),
        deletedTokenCount = 0,
        childrenAfterReduction = ImmutableList.of(),
        editsTested = ImmutableList.of(),
      )
    val eventA2 = eventA1.copy() // Second visit to same node in same iteration
    val eventA3 = eventA1.copy() // Third visit

    val eventsA = listOf(eventA1, eventA2)
    val eventsB = listOf(eventA1, eventA2, eventA3)

    val (modelA, nodeMapA) = EventDiffTreeModelBuilder.createEventTreeModel("Run A", eventsA)
    val (modelB, nodeMapB) = EventDiffTreeModelBuilder.createEventTreeModel("Run B", eventsB)

    // Verify NodeIds
    assertThat(nodeMapA).hasSize(2)
    assertThat(nodeMapA.keys).containsExactly(NodeId(50, 1, 0), NodeId(50, 1, 1))
    assertThat(nodeMapB).hasSize(3)
    assertThat(nodeMapB.keys).containsExactly(NodeId(50, 1, 0), NodeId(50, 1, 1), NodeId(50, 1, 2))

    val sourceNode0 = nodeMapA[NodeId(50, 1, 0)]!!
    val sourceNode1 = nodeMapA[NodeId(50, 1, 1)]!!

    // Verify Correspondence
    val targetNode0 =
      EventDiffTreeModelBuilder.findCorrespondingNode(
        sourceNode0,
        nodeMapB,
      )
    val targetNode1 =
      EventDiffTreeModelBuilder.findCorrespondingNode(
        sourceNode1,
        nodeMapB,
      )

    assertThat(targetNode0).isEqualTo(nodeMapB[NodeId(50, 1, 0)])
    assertThat(targetNode1).isEqualTo(nodeMapB[NodeId(50, 1, 1)])

    // Negative test: ensure sourceNode0 does NOT correspond to the extra targetNode2
    val targetNode2 = nodeMapB[NodeId(50, 1, 2)]!!
    assertThat(nodeMapA).doesNotContainKey(NodeId(50, 1, 2))
    assertThat(targetNode0).isNotEqualTo(targetNode2)
    assertThat(targetNode1).isNotEqualTo(targetNode2)
  }

  @Test
  fun testDeletedChildrenSubNodes() {
    val event =
      DifferentialEvents.NodeReductionEvent(
        fixpointIteration = 1,
        startPersesTimeSeconds = 1,
        endPersesTimeSeconds = 2,
        nodeId = 10,
        ruleName = "RuleA",
        ruleType = RuleType.KLEENE_PLUS,
        childrenBeforeReduction = ImmutableList.of(1, 2, 3, 4),
        deletedTokenCount = 0,
        childrenAfterReduction = ImmutableList.of(2, 4),
        editsTested = ImmutableList.of(),
      )

    val (model, _) = EventDiffTreeModelBuilder.createEventTreeModel("Title", listOf(event))
    val root = model.root as DefaultMutableTreeNode
    val iterationNode = root.getChildAt(0) as DefaultMutableTreeNode
    val eventNode = iterationNode.getChildAt(0) as DefaultMutableTreeNode

    val childrenDeletedNode =
      eventNode.children().asSequence().first {
        (it as DefaultMutableTreeNode).userObject.toString().contains("Children Deleted: 2")
      } as DefaultMutableTreeNode

    assertThat(childrenDeletedNode.childCount).isEqualTo(2)
    assertThat(childrenDeletedNode.getChildAt(0).toString()).isEqualTo("Child 1")
    assertThat(childrenDeletedNode.getChildAt(1).toString()).isEqualTo("Child 3")
  }
}
