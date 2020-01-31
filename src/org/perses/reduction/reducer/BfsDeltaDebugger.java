package org.perses.reduction.reducer;

import org.perses.reduction.ReductionListenerManager;
import org.perses.reduction.TreeEditWithItsProgram;
import org.perses.reduction.partition.Partition;
import org.perses.tree.spar.AbstractNodeActionSetCache;
import org.perses.tree.spar.AbstractSparTreeEdit;

import java.util.ArrayDeque;
import java.util.Optional;
import java.util.function.Function;

public final class BfsDeltaDebugger extends AbstractSpecialDeltaDebugger {

  protected BfsDeltaDebugger(
      ReductionListenerManager listenerManager,
      AbstractNodeActionSetCache nodeActionSetCache,
      Function<AbstractSparTreeEdit, Optional<TreeEditWithItsProgram>> treeEditTester) {
    super(listenerManager, nodeActionSetCache, treeEditTester);
  }

  @Override
  protected Partition pollFromWorklist(ArrayDeque<Partition> worklist) {
    return worklist.pollFirst();
  }

  @Override
  protected void addToWorklist(ArrayDeque<Partition> worklist, Partition[] partitions) {
    assert partitions != null;
    for (int i = partitions.length - 1; i >= 0; --i) {
      worklist.addLast(partitions[i]);
    }
  }
}
