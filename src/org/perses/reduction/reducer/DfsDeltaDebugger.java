package org.perses.reduction.reducer;

import org.perses.reduction.ReductionListenerManager;
import org.perses.reduction.TreeEditWithItsProgram;
import org.perses.reduction.partition.Partition;
import org.perses.tree.spar.AbstractNodeActionSetCache;
import org.perses.tree.spar.AbstractSparTreeEdit;

import java.util.ArrayDeque;
import java.util.Optional;
import java.util.function.Function;

public final class DfsDeltaDebugger extends AbstractSpecialDeltaDebugger {

  public DfsDeltaDebugger(
      ReductionListenerManager listenerManager,
      AbstractNodeActionSetCache nodeActionSetCache,
      Function<AbstractSparTreeEdit, Optional<TreeEditWithItsProgram>> treeEditTester) {
    super(listenerManager, nodeActionSetCache, treeEditTester);
  }

  @Override
  protected Partition pollFromWorklist(ArrayDeque<Partition> worklist) {
    return worklist.pollLast();
  }

  @Override
  protected void addToWorklist(ArrayDeque<Partition> worklist, Partition[] partitions) {
    assert partitions != null;
    for (Partition partition : partitions) {
      worklist.addLast(partition);
    }
  }
}
