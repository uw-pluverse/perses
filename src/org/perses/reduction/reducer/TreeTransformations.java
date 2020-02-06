/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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
package org.perses.reduction.reducer;

import com.google.common.collect.ImmutableList;
import org.perses.antlr.RuleHierarchyInfo;
import org.perses.reduction.partition.Partition;
import org.perses.tree.spar.AbstractSparTreeNode;
import org.perses.tree.spar.ChildHoistingAction;
import org.perses.tree.spar.NodeDeletionActionSet;

import java.util.ArrayList;
import java.util.Optional;

/** Various tree transformations. */
public final class TreeTransformations {

  /**
   * Replace the current node with one of its children that has compatible rule type.
   *
   * @return all possible replacements.
   */
  public static ImmutableList<ChildHoistingAction> replaceNodeWithNearestCompatibleChildren(
      final AbstractSparTreeNode currentNode, int maxBfsDepth) {
    assert maxBfsDepth > 0 : "The max BFS depth must be positive: " + maxBfsDepth;

    final AbstractSparTreeNode.ParentInfo parentInfo = currentNode.getParentInfo();
    assert parentInfo != null : "This is a root node: " + currentNode.printTreeStructure();
    Optional<RuleHierarchyInfo> antlrRuleForTheChild = parentInfo.getAntlrRuleForTheChild();
    assert antlrRuleForTheChild.isPresent() : currentNode.printTreeStructure();
    final RuleHierarchyInfo expectedSuperRuleType = antlrRuleForTheChild.get();

    final ArrayList<AbstractSparTreeNode> replacements =
        currentNode.boundedBreadthFirstSearchForFirstQualifiedNodes(
            node -> {
              final Optional<RuleHierarchyInfo> nodeRule = node.getAntlrRule();
              if (!nodeRule.isPresent()) {
                return false;
              }
              return expectedSuperRuleType.isEqualToOrSuperOf(nodeRule.get());
            },
            maxBfsDepth);
    return replacements.stream()
        .map(node -> new ChildHoistingAction(currentNode, node))
        .collect(ImmutableList.toImmutableList());
  }

  /**
   * Replace the current node (which should be Kleene-qualified) with one of its children (which
   * should be Kleene-qualified too).
   *
   * @return all possible replacements
   */
  public static ImmutableList<ChildHoistingAction>
      replaceKleeneQualifiedNodeWithKleeneQualifiedChildren(
          AbstractSparTreeNode currentNode, int maxBfsDepth) {
    assert maxBfsDepth > 0 : "The max BFS depth must be positive: " + maxBfsDepth;
    final AbstractSparTreeNode.ParentInfo parentInfo = currentNode.getParentInfo();
    assert parentInfo != null
        : "The current node is a root node: " + currentNode.printTreeStructure();
    final AbstractSparTreeNode parent = parentInfo.getNode();
    if (!parent.isKleeneStarRuleNode() && !parent.isKleenePlusRuleNode()) {
      return ImmutableList.of();
    }

    assert parent.isKleeneStarRuleNode() || parent.isKleenePlusRuleNode()
        : "The current node must be Kleene-qualified." + currentNode.printTreeStructure();
    final RuleHierarchyInfo kleeneElementRule = parent.getKleeneElementRule();
    assert kleeneElementRule.equals(currentNode.getParentInfo().getAntlrRuleForTheChild().get())
        : currentNode
            + ": "
            + kleeneElementRule
            + " vs "
            + currentNode.getParentInfo().getAntlrRuleForTheChild();

    final ArrayList<AbstractSparTreeNode> replacementList =
        currentNode.boundedBreadthFirstSearchForFirstQualifiedNodes(
            node -> {
              if (!node.isKleeneStarRuleNode() && !node.isKleenePlusRuleNode()) {
                return false;
              }
              final RuleHierarchyInfo childRule = node.getKleeneElementRule();
              return kleeneElementRule.isEqualToOrSuperOf(childRule);
            },
            maxBfsDepth);
    if (replacementList.isEmpty()) {
      return ImmutableList.of();
    }
    return replacementList.stream()
        .map(node -> new ChildHoistingAction(currentNode, node))
        .collect(ImmutableList.toImmutableList());
  }

  //  /** Delete all the children of the given node from the tree */
  //  public static SparTreeEdit deleteChildrenFromTree(AbstractSparTreeNode parent, SparTree tree)
  // {
  //    final SparTreeEdit edit = tree.createEdit();
  //    parent.forEachChild(child -> edit.edit(new
  // AbstractTreeEditAction.NodeDeletionAction(child)));
  //    return edit;
  //  }

  /** Delete a partition of nodes from the given tree. */
  //  public static NodeActionSetCacheResult<NodeDeletionActionSet, NodeDeletionTreeEdit>
  //      deletePartitionFromTree(Partition partition, SparTree tree) {
  //    final NodeDeletionActionSet.Builder actionSet = new NodeDeletionActionSet.Builder();
  //    partition.forEach(actionSet::deleteNode);
  //    return tree.createNodeDeletionEdit(actionSet.build());
  //  }
  public static NodeDeletionActionSet createNodeDeletionActionSetFor(
      Partition partition, String actionsDescription) {
    final NodeDeletionActionSet.Builder actionSet =
        new NodeDeletionActionSet.Builder(actionsDescription);
    partition.forEach(actionSet::deleteNode);
    return actionSet.build();
  }
}
