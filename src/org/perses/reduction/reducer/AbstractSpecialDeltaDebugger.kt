package org.perses.reduction.reducer

import java.util.ArrayDeque
import java.util.Optional
import java.util.function.Function
import org.perses.reduction.ReductionListenerManager
import org.perses.reduction.TreeEditWithItsResult
import org.perses.reduction.partition.Partition
import org.perses.reduction.reducer.TreeTransformations.createNodeDeletionActionSetFor
import org.perses.tree.spar.AbstractNodeActionSetCache
import org.perses.tree.spar.AbstractSparTreeEdit
import org.perses.tree.spar.SparTree

abstract class AbstractSpecialDeltaDebugger protected constructor(
  listenerManager: ReductionListenerManager,
  nodeActionSetCache: AbstractNodeActionSetCache,
  treeEditTester: Function<AbstractSparTreeEdit, Optional<TreeEditWithItsResult>>
) :
  AbstractDeltaDebugger(listenerManager, nodeActionSetCache, treeEditTester) {

  override fun reduce(
    tree: SparTree,
    actionsDescription: String,
    vararg startPartitions: Partition
  ) {
    assert(startPartitions.isNotEmpty())
    val worklist = ArrayDeque<Partition>()
    addToWorklist(worklist, startPartitions)
    assert(!worklist.isEmpty())
    while (!worklist.isEmpty()) {
      val partition = pollFromWorklist(worklist)
      val actionSet = createNodeDeletionActionSetFor(
        partition, actionsDescription + "@" + partition.size())
      if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
        listenerManager.onNodeEditActionSetCacheHit(actionSet)
        continue
      }
      val edit = tree.createNodeDeletionEdit(actionSet)
      val best = treeEditTester.apply(edit)
      if (!best.isPresent) {
        addToWorklist(worklist, partition.split())
        continue
      }
      val (edit1) = best.get()
      tree.applyEdit(edit1)
    }
  }

  protected abstract fun pollFromWorklist(
    worklist: ArrayDeque<Partition>
  ): Partition

  protected abstract fun addToWorklist(
    worklist: ArrayDeque<Partition>,
    partitions: Array<out Partition>
  )
}
