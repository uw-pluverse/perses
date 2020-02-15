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

import com.google.common.annotations.VisibleForTesting;
import com.google.common.collect.ImmutableList;
import org.perses.antlr.RuleType;
import org.perses.reduction.AbstractReducer;
import org.perses.reduction.ReducerAnnotation;
import org.perses.reduction.ReducerContext;
import org.perses.reduction.TreeEditWithItsResult;
import org.perses.reduction.partition.Partition;
import org.perses.tree.spar.*;

import java.io.IOException;
import java.util.*;
import java.util.concurrent.ExecutionException;

/** Perses reducer. The granularity is parse tree nodes, but not level-based. */
public abstract class AbstractPersesNodeReducer extends AbstractReducer {

  protected static final int DEFAULT_INITIAL_QUEUE_CAPACITY = 600;

  protected AbstractPersesNodeReducer(
      ReducerAnnotation reducerAnnotation, ReducerContext reducerContext) {
    super(reducerAnnotation, reducerContext);
  }

  /**
   * Create a partition from the tree node, by including the children in the range [childIndexFrom,
   * childIndexTo)
   */
  @VisibleForTesting
  static Partition createPartition(
      AbstractSparTreeNode node, int childIndexFrom, int childIndexTo) {
    assert childIndexFrom >= 0 : childIndexFrom;
    assert childIndexFrom < childIndexTo : childIndexFrom + ", " + childIndexTo;
    assert childIndexTo <= node.getChildCount() : childIndexTo + ", " + node.getChildCount();
    final Partition.Builder builder = new Partition.Builder(childIndexTo - childIndexFrom);
    for (int i = childIndexFrom; i < childIndexTo; ++i) {
      builder.addNode(node.getChild(i));
    }
    return builder.build();
  }

  @Override
  protected void internalReduce(SparTree tree)
      throws IOException, ExecutionException, InterruptedException {
    final AbstractSparTreeNode root = tree.getRoot();
    assert SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(root);

    final Queue<AbstractSparTreeNode> queue = createReductionQueue();
    queue.addAll(root.getImmutableChildView());
    while (!queue.isEmpty()) {
      final AbstractSparTreeNode node = queue.poll();
      final int oldTokenCount = tree.getTokenCount();
      listenerManager.onNodeReductionStart(tree, node, oldTokenCount);
      final ImmutableList<AbstractSparTreeNode> pendingNodes = reduceOneNode(tree, node);
      assert pendingNodes != null : "The returned new node cannot be null";

      final int newTokenCount = tree.getTokenCount();
      listenerManager.onNodeReductionEnd(tree, node, queue.size(), newTokenCount);

      queue.addAll(pendingNodes);
    }
  }

  protected abstract Queue<AbstractSparTreeNode> createReductionQueue();

  private ImmutableList<AbstractSparTreeNode> reduceOneNode(
      SparTree tree, AbstractSparTreeNode node)
      throws InterruptedException, ExecutionException, IOException {
    switch (node.getNodeType()) {
      case KLEENE_PLUS:
        return reduceKleenePlus(tree, node);
      case KLEENE_STAR:
      case OPTIONAL:
        return reduceKleenStar(tree, node);
      case OTHER_RULE:
        return reduceRegularRule(tree, node);
      case TOKEN:
        // TODO: Do nothing.
        return ImmutableList.of();
      default:
        throw new AssertionError("Unhandled node type: " + node);
    }
  }

  protected Optional<TreeEditWithItsResult> testSparTreeEdit(AbstractSparTreeEdit edit) {
    try {
      return testAllTreeEditsAndReturnTheBest(ImmutableList.of(edit));
    } catch (Exception e) {
      throw new AssertionError(e);
    }
  }

  private ImmutableList<AbstractSparTreeNode> reduceRegularRule(
      SparTree tree, AbstractSparTreeNode regularRuleNode) {
    final List<AbstractSparTreeEdit> editList =
        createEditListForRegularRuleNode(tree, regularRuleNode);
    Optional<TreeEditWithItsResult> best = testAllTreeEditsAndReturnTheBest(editList);
    if (!best.isPresent()) {
      return ImmutableList.copyOf(regularRuleNode.getImmutableChildView());
    }
    final TreeEditWithItsResult bestEditWithItsProgram = best.get();
    tree.applyEdit(bestEditWithItsProgram.getEdit());
    return computePendingNodes(tree, regularRuleNode, bestEditWithItsProgram.getEdit());
  }

  private List<AbstractSparTreeEdit> createEditListForRegularRuleNode(
      SparTree tree, AbstractSparTreeNode regularRuleNode) {
    assert regularRuleNode.getAntlrRule().get().getRuleDef().isParserRule();

    final int childCount = regularRuleNode.getChildCount();
    if (childCount == 0) {
      return Collections.emptyList();
    }

    final int maxEditCount = 100;
    final ArrayList<AbstractSparTreeEdit> editList = new ArrayList<>(maxEditCount);
    if (canBeEpsilon(regularRuleNode)) {
      addDeletionEditToEditListAndLog(
          NodeDeletionActionSet.createByDeleteSingleNode(
              regularRuleNode, "[regular_node]can be epsilon"),
          editList,
          tree);
    }

    final ImmutableList<ChildHoistingAction> kleeneReplacements =
        TreeTransformations.replaceKleeneQualifiedNodeWithKleeneQualifiedChildren(
            regularRuleNode, 3);
    actionSetProfiler.onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren(kleeneReplacements);

    for (ChildHoistingAction action : kleeneReplacements) {
      addEditToEditListAndLog(
          ChildHoistingActionSet.createByReplacingSingleNode(
              action, "[regular_node]kleene replacement"),
          editList,
          tree);
    }

    final ImmutableList<ChildHoistingAction> compatibleReplacements =
        TreeTransformations.replaceNodeWithNearestCompatibleChildren(regularRuleNode, 5);
    actionSetProfiler.onReplaceNodeWithNearestCompatibleChildren(compatibleReplacements);
    final int remainingQuota = maxEditCount - editList.size();
    if (remainingQuota > 0) {
      compatibleReplacements.stream()
          .limit(remainingQuota)
          .forEach(
              action -> {
                addEditToEditListAndLog(
                    ChildHoistingActionSet.createByReplacingSingleNode(
                        action, "[regular node]compatible replacement"),
                    editList,
                    tree);
              });
    }
    return editList;
  }

  private boolean canBeEpsilon(AbstractSparTreeNode node) {
    while (node != null) {
      if (node.getAntlrRule().get().canRuleBeEpsilon()) {
        // If the rule of the current node can be epsilon.
        return true;
      }
      final AbstractSparTreeNode.ParentInfo parent = node.getParentInfo();
      if (parent == null) {
        return false;
      }
      if (parent.getAntlrRuleForTheChild().get().canRuleBeEpsilon()) {
        // If the EXPECTED rule of the current node can be epsilon.
        return true;
      }
      final AbstractSparTreeNode parentNode = parent.getNode();
      final int childCount = parentNode.getChildCount();
      if (childCount == 1) {
        // Only the current node, then check whether the parent node rule can be epsilon.
        node = parentNode;
        continue;
      } else if (childCount > 1) {
        final RuleType parentNodeType = parentNode.getNodeType();
        switch (parentNodeType) {
          case KLEENE_PLUS:
          case KLEENE_STAR:
            return true;
          case OPTIONAL:
            throw new RuntimeException(
                "Optional should have a single child. " + node.printTreeStructure());
          default:
            return false;
        }
      } else {
        throw new RuntimeException("Unreachable. " + node.printTreeStructure());
      }
    }
    return false;
  }

  /** Perform delta debugging. */
  private ImmutableList<AbstractSparTreeNode> reduceKleenStar(
      SparTree tree, AbstractSparTreeNode kleeneStar)
      throws InterruptedException, ExecutionException, IOException {
    final int childCount = kleeneStar.getChildCount();
    if (childCount == 0) {
      return ImmutableList.of();
    }
    // FIXME: the best program is not saved.
    performDelta(tree, "[kleene_star]dd", createPartition(kleeneStar, 0, childCount));
    if (kleeneStar.isPermanentlyDeleted()) {
      return ImmutableList.of();
    } else {
      return ImmutableList.copyOf(kleeneStar.getImmutableChildView());
    }
  }

  protected abstract void performDelta(
      final SparTree tree, String actionsDescription, final Partition... startPartitions)
      throws InterruptedException, ExecutionException, IOException;

  private ImmutableList<AbstractSparTreeNode> reduceKleenePlus(
      SparTree tree, AbstractSparTreeNode kleenePlus)
      throws InterruptedException, ExecutionException, IOException {
    final int childCount = kleenePlus.getChildCount();
    if (childCount == 0) {
      return ImmutableList.of();
    }
    ArrayList<AbstractSparTreeEdit> editList = new ArrayList<>();
    if (canBeEpsilon(kleenePlus)) {
      addDeletionEditToEditListAndLog(
          NodeDeletionActionSet.createByDeleteSingleNode(kleenePlus, "[kleene_plus]can be epsilon"),
          editList,
          tree);
    }
    if (childCount > 1) {
      final Partition wholePartition =
          createPartition(kleenePlus, 1, childCount); // Skip the first.
      addDeletionEditToEditListAndLog(
          TreeTransformations.createNodeDeletionActionSetFor(
              wholePartition, "[kleene_plus]remove whole except first"),
          editList,
          tree);
    }
    final Optional<TreeEditWithItsResult> best = testAllTreeEditsAndReturnTheBest(editList);
    if (best.isPresent()) {
      final TreeEditWithItsResult bestEditWithItsProgram = best.get();
      tree.applyEdit(bestEditWithItsProgram.getEdit());
      return computePendingNodes(tree, kleenePlus, bestEditWithItsProgram.getEdit());
    }

    if (childCount > 1) {
      final int halfIndex = (childCount + 1) / 2;
      performDelta(
          tree,
          "[kleene_plus]dd",
          createPartition(kleenePlus, 0, halfIndex),
          createPartition(kleenePlus, halfIndex, childCount));
    }
    return ImmutableList.copyOf(kleenePlus.getImmutableChildView());
  }

  private ImmutableList<AbstractSparTreeNode> computePendingNodes(
      final SparTree tree, final AbstractSparTreeNode currentNode, AbstractSparTreeEdit bestEdit) {
    if (!currentNode.isPermanentlyDeleted()) {
      // Children are changed, so work on the children later.
      return ImmutableList.copyOf(currentNode.getImmutableChildView());
    }
    if (bestEdit instanceof NodeDeletionTreeEdit) {
      final NodeDeletionTreeEdit nodeDeletionTreeEdit = bestEdit.asNodeDeleteEdit();
      assert nodeDeletionTreeEdit.isNodeATarget(currentNode);
      assert nodeDeletionTreeEdit.getNumberOfActions() == 1;
      return ImmutableList.of();
    } else if (bestEdit instanceof NodeReplacementTreeEdit) {
      final NodeReplacementTreeEdit nodeReplacementTreeEdit = bestEdit.asNodeReplacementEdit();

      if (nodeReplacementTreeEdit.isNodeATarget(currentNode)) {
        assert nodeReplacementTreeEdit.getNumberOfActions() == 1;
        final AbstractSparTreeNode onlyReplacementNode =
            nodeReplacementTreeEdit.getOnlyReplacementNode();
        assert !onlyReplacementNode.isPermanentlyDeleted()
            : onlyReplacementNode.printTreeStructure();
        return ImmutableList.of(onlyReplacementNode);
      } else {
        return ImmutableList.copyOf(currentNode.getImmutableChildView());
      }
    } else {
      throw new RuntimeException("Unreachable.");
    }
  }

  private final void addDeletionEditToEditListAndLog(
      NodeDeletionActionSet actionSet, List<? super AbstractSparTreeEdit> editList, SparTree tree) {
    if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
      listenerManager.onNodeEditActionSetCacheHit(actionSet);
    } else {
      editList.add(tree.createNodeDeletionEdit(actionSet));
    }
  }

  private final void addEditToEditListAndLog(
      ChildHoistingActionSet actionSet,
      List<? super AbstractSparTreeEdit> editList,
      SparTree tree) {
    if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
      listenerManager.onNodeEditActionSetCacheHit(actionSet);
    } else {
      editList.add(tree.createNodeReplacementEdit(actionSet));
    }
  }

  protected enum TreeNodeComparatorInLeafTokenCount implements Comparator<AbstractSparTreeNode> {
    SINGLETON;

    @Override
    public int compare(AbstractSparTreeNode o1, AbstractSparTreeNode o2) {
      final int tokenCountCmpResult =
          Integer.compare(o2.getLeafTokenCount(), o1.getLeafTokenCount());
      if (tokenCountCmpResult != 0) {
        return tokenCountCmpResult;
      }
      // For determinism.
      final int result = Integer.compare(o2.getNodeId(), o1.getNodeId());
      assert result != 0 : "Cannot guarantee determinism.";
      return result;
    }
  }
}
