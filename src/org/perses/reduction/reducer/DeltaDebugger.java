package org.perses.reduction.reducer;

import org.perses.reduction.ReductionListenerManager;
import org.perses.reduction.TreeEditWithItsProgram;
import org.perses.reduction.partition.Partition;
import org.perses.tree.spar.*;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Optional;
import java.util.function.Function;

public class DeltaDebugger extends AbstractDeltaDebugger {
  protected DeltaDebugger(
      ReductionListenerManager listenerManager,
      AbstractNodeActionSetCache nodeActionSetCache,
      Function<AbstractSparTreeEdit, Optional<TreeEditWithItsProgram>> treeEditTester) {
    super(listenerManager, nodeActionSetCache, treeEditTester);
  }

  @Override
  public void reduce(SparTree tree, String actionsDescription, Partition... startPartitions) {
    LinkedList<Partition> worklist = new LinkedList<>();
    for (int i = startPartitions.length - 1; i >= 0; --i) {
      worklist.add(startPartitions[i]);
    }
    while (!worklist.isEmpty()) {
      boolean shouldContinue;
      do {
        shouldContinue = false;
        for (Iterator<Partition> iterator = worklist.iterator(); iterator.hasNext(); ) {
          final Partition partition = iterator.next();
          final NodeDeletionActionSet actionSet =
              TreeTransformations.createNodeDeletionActionSetFor(
                  partition, actionsDescription + "@" + partition.size());
          if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
            listenerManager.onNodeEditActionSetCacheHit(actionSet);
            continue;
          }
          final NodeDeletionTreeEdit edit = tree.createNodeDeletionEdit(actionSet);
          final Optional<TreeEditWithItsProgram> best = treeEditTester.apply(edit);
          if (best.isPresent()) {
            tree.applyEdit(best.get().getEdit());
            iterator.remove();
            shouldContinue = true;
          }
        }
      } while (shouldContinue);
      final LinkedList<Partition> copy = worklist;
      worklist = new LinkedList<>();
      assert worklist != copy;
      for (Partition partition : copy) {
        final Partition[] splits = partition.split();
        for (Partition split : splits) {
          worklist.add(split);
        }
      }
    }
  }
}
