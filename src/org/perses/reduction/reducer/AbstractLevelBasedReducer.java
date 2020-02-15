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
import org.perses.reduction.*;
import org.perses.reduction.partition.AbstractLevelPartitionPolicy;
import org.perses.reduction.partition.Partition;
import org.perses.reduction.partition.SimpleLevelPartitionPolicy;
import org.perses.tree.spar.AbstractSparTreeEdit;
import org.perses.tree.spar.ChildHoistingAction;
import org.perses.tree.spar.SparTree;

import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.List;
import java.util.Optional;
import java.util.concurrent.ExecutionException;

import static com.google.common.base.Preconditions.checkState;

/** The base class for reducers that perform level-based reduction. */
public abstract class AbstractLevelBasedReducer extends AbstractReducer {

  private final AbstractLevelPartitionPolicy partitionPolicy = new SimpleLevelPartitionPolicy();

  protected AbstractLevelBasedReducer(
      ReducerAnnotation reducerAnnotation, ReducerContext reducerContext) {
    super(reducerAnnotation, reducerContext);
  }

  protected Optional<ReductionLevel> getInitialRegion(SparTree tree) {
    final ReductionLevel level = new ReductionLevel(1);
    tree.getRoot().forEachChild(level::addNode);
    return Optional.of(level);
  }

  /**
   * TODO: if a node and all its children are irreducible, then avoid adding it to the next level.
   *
   * @param tree
   * @param level
   * @return
   */
  protected Optional<ReductionLevel> moveToNextLevel(SparTree tree, ReductionLevel level) {
    final ReductionLevel next = new ReductionLevel(level.getLevel() + 1);
    // FIXME: need to make sure that single path cannot contain more than two nodes.
    // Otherwise this algorithm will be very slow.
    level.forEachNode(t -> t.forEachChild(next::addNode));
    return next.isEmpty() ? Optional.empty() : Optional.of(next);
  }

  protected void reduceOneLevel(SparTree tree, ReductionLevel level)
      throws IOException, ExecutionException, InterruptedException {
    int maxNodesPerPartition = getInitialMaxNodesPerPartition(level);
    while (maxNodesPerPartition > 0) {
      partitionLevelAndReduce(tree, level, maxNodesPerPartition);
      if (maxNodesPerPartition == 1) {
        break;
      }
      maxNodesPerPartition = (maxNodesPerPartition + 1) / 2;
    }
  }

  protected int getInitialMaxNodesPerPartition(ReductionLevel level) {
    // Usually reducing the whole level does not help, so use halves.
    return (level.getNodeCount() + 1) / 2;
  }

  /**
   * Create a set of tree edits, by deleting the ndoes in the partition, or deleteing some child
   * nodes.
   */
  protected abstract List<AbstractSparTreeEdit> createTreeEditListByDisablingPartition(
      Partition partition, SparTree tree);

  private void partitionLevelAndReduce(
      final SparTree tree, final ReductionLevel reductionLevel, int maxNodesPerPartition)
      throws IOException {
    assert maxNodesPerPartition > 0;
    final int oldTokenCount = tree.getTokenCount();
    listenerManager.onLevelGranularityReductionStart(maxNodesPerPartition, oldTokenCount);

    final ImmutableList<Partition> partitions =
        partitionPolicy.partition(reductionLevel, maxNodesPerPartition);

    for (Partition partition : partitions) {
      partition.removePermanentlyDeletedNodes();
      if (partition.isEmpty()) {
        continue;
      }

      final List<AbstractSparTreeEdit> editList =
          createTreeEditListByDisablingPartition(partition, tree);
      if (editList.isEmpty()) {
        logEmptyEdits(partition);
      }
      final Optional<TreeEditWithItsResult> bestEdit = testAllTreeEditsAndReturnTheBest(editList);
      if (!bestEdit.isPresent()) {
        continue;
      }
      final TreeEditWithItsResult bestEditWithItsProgram = bestEdit.get();

      final AbstractSparTreeEdit treeEdit = bestEditWithItsProgram.getEdit();
      tree.applyEdit(treeEdit);
      treeEdit.getActions().stream()
          .filter(action -> action instanceof ChildHoistingAction)
          .map(action -> ((ChildHoistingAction) action))
          .filter(action -> isReplacingNodeAtTheLevel(reductionLevel, action))
          .forEach(
              action ->
                  reductionLevel.replaceNode(action.getTargetNode(), action.getReplacingChild()));
    }

    final int newTokenCount = tree.getTokenCount();
    listenerManager.onLevelGranularityReductionEnd(maxNodesPerPartition, newTokenCount);

    reductionLevel.cleanDeletedNodes();
  }

  private static boolean isReplacingNodeAtTheLevel(
      ReductionLevel level, ChildHoistingAction action) {
    return level.containsNode(action.getTargetNode());
  }

  private void logEmptyEdits(Partition partition) throws IOException {
    try (BufferedWriter sink =
        java.nio.file.Files.newBufferedWriter(
            Paths.get("temp_empty_edits_dump.txt"),
            StandardCharsets.UTF_8,
            StandardOpenOption.APPEND,
            StandardOpenOption.CREATE)) {
      sink.write("Empty partition: ");
      sink.write(partition.toString());
      sink.write("\n");
      sink.write("Tree:\n");
      partition.forEach(
          child -> {
            try {
              sink.write(child.getParentInfo().getNode().printTreeStructure() + "\n");
            } catch (IOException e) {
              throw new AssertionError(e);
            }
          });
    }
  }

  protected final void internalReduce(SparTree tree)
      throws IOException, ExecutionException, InterruptedException {
    Optional<ReductionLevel> currentLevel = getInitialRegion(tree);
    checkState(currentLevel.isPresent(), "No qualified initial level for the tree");

    while (currentLevel.isPresent()) {
      final ReductionLevel level = currentLevel.get();
      assert (level.getNodeCount() > 0) : "The level cannot be empty.";

      final int preSize = tree.getTokenCount();
      listenerManager.onLevelReductionStart(level.getLevel(), level.getNodeCount(), preSize);
      assert (!ReductionLevel.isNullOrEmpty(level));
      reduceOneLevel(tree, level);
      final int postSize = tree.getTokenCount();
      listenerManager.onLevelReductionEnd(level.getLevel(), postSize);

      if (level.getLevel() >= configuration.getMaxReductionLevel()) {
        continue; // has reached the maximum level, thus skipping the next levels.
      }

      currentLevel = moveToNextLevel(tree, level);
      assert !currentLevel.isPresent() || !ReductionLevel.isNullOrEmpty(currentLevel.get());
    }
  }
}
