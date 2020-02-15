package org.perses.reduction.reducer;

import org.perses.reduction.ReductionListenerManager;
import org.perses.reduction.TreeEditWithItsResult;
import org.perses.reduction.partition.Partition;
import org.perses.tree.spar.AbstractNodeActionSetCache;
import org.perses.tree.spar.AbstractSparTreeEdit;
import org.perses.tree.spar.SparTree;

import java.util.Optional;
import java.util.function.Function;

public abstract class AbstractDeltaDebugger {

  protected final ReductionListenerManager listenerManager;
  protected final AbstractNodeActionSetCache nodeActionSetCache;
  protected final Function<AbstractSparTreeEdit, Optional<TreeEditWithItsResult>> treeEditTester;

  protected AbstractDeltaDebugger(
      ReductionListenerManager listenerManager,
      AbstractNodeActionSetCache nodeActionSetCache,
      Function<AbstractSparTreeEdit, Optional<TreeEditWithItsResult>> treeEditTester) {
    this.listenerManager = listenerManager;
    this.nodeActionSetCache = nodeActionSetCache;
    this.treeEditTester = treeEditTester;
  }

  public abstract void reduce(
      final SparTree tree, String actionsDescription, final Partition... startPartitions);
}
