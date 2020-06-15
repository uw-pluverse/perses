package org.perses.reduction.reducer

import org.perses.reduction.ReductionListenerManager
import org.perses.reduction.TreeEditWithItsResult
import org.perses.reduction.partition.Partition
import org.perses.tree.spar.AbstractNodeActionSetCache
import org.perses.tree.spar.AbstractSparTreeEdit
import org.perses.tree.spar.SparTree
import java.util.Optional
import java.util.function.Function

abstract class AbstractDeltaDebugger protected constructor(
  protected val listenerManager: ReductionListenerManager,
  protected val nodeActionSetCache: AbstractNodeActionSetCache,
  protected val treeEditTester: Function<AbstractSparTreeEdit, Optional<TreeEditWithItsResult>>
) {

  abstract fun reduce(
    tree: SparTree,
    actionsDescription: String,
    vararg startPartitions: Partition
  )
}
