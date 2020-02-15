package org.perses.reduction.reducer;

import org.perses.reduction.ReductionListenerManager;
import org.perses.reduction.TreeEditWithItsResult;
import org.perses.reduction.partition.Partition;
import org.perses.tree.spar.*;

import java.util.ArrayDeque;
import java.util.Optional;
import java.util.function.Function;

public abstract class AbstractSpecialDeltaDebugger extends AbstractDeltaDebugger {

  protected AbstractSpecialDeltaDebugger(
      ReductionListenerManager listenerManager,
      AbstractNodeActionSetCache nodeActionSetCache,
      Function<AbstractSparTreeEdit, Optional<TreeEditWithItsResult>> treeEditTester) {
    super(listenerManager, nodeActionSetCache, treeEditTester);
  }

  public void reduce(
      final SparTree tree, String actionsDescription, final Partition... startPartitions) {
    assert startPartitions.length > 0;
    final ArrayDeque<Partition> worklist = new ArrayDeque<>();
    addToWorklist(worklist, startPartitions);
    assert !worklist.isEmpty();
    while (!worklist.isEmpty()) {
      final Partition partition = pollFromWorklist(worklist);
      final NodeDeletionActionSet actionSet =
          TreeTransformations.createNodeDeletionActionSetFor(
              partition, actionsDescription + "@" + partition.size());
      if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
        listenerManager.onNodeEditActionSetCacheHit(actionSet);
        continue;
      }
      NodeDeletionTreeEdit edit = tree.createNodeDeletionEdit(actionSet);
      final Optional<TreeEditWithItsResult> best = treeEditTester.apply(edit);
      if (!best.isPresent()) {
        addToWorklist(worklist, partition.split());
        continue;
      }
      final TreeEditWithItsResult bestEditWithItsProgram = best.get();
      tree.applyEdit(bestEditWithItsProgram.getEdit());
    }
  }

  protected abstract Partition pollFromWorklist(ArrayDeque<Partition> worklist);

  protected abstract void addToWorklist(ArrayDeque<Partition> worklist, Partition[] partitions);
}
