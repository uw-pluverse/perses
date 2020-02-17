package org.perses.reduction.reducer

import java.util.ArrayDeque
import java.util.Optional
import java.util.function.Function
import org.perses.reduction.ReductionListenerManager
import org.perses.reduction.TreeEditWithItsResult
import org.perses.reduction.partition.Partition
import org.perses.tree.spar.AbstractNodeActionSetCache
import org.perses.tree.spar.AbstractSparTreeEdit

class BfsDeltaDebugger constructor(
  listenerManager: ReductionListenerManager,
  nodeActionSetCache: AbstractNodeActionSetCache,
  treeEditTester: Function<AbstractSparTreeEdit, Optional<TreeEditWithItsResult>>
) :
  AbstractSpecialDeltaDebugger(listenerManager, nodeActionSetCache, treeEditTester) {

  override fun pollFromWorklist(worklist: ArrayDeque<Partition>): Partition {
    return worklist.pollFirst()
  }

  override fun addToWorklist(worklist: ArrayDeque<Partition>, partitions: Array<out Partition>) {
    for (i in partitions.indices.reversed()) {
      worklist.addLast(partitions[i])
    }
  }
}
