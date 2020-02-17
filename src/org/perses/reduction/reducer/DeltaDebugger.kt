package org.perses.reduction.reducer

import java.util.LinkedList
import java.util.Optional
import java.util.function.Function
import org.perses.reduction.ReductionListenerManager
import org.perses.reduction.TreeEditWithItsResult
import org.perses.reduction.partition.Partition
import org.perses.reduction.reducer.TreeTransformations.createNodeDeletionActionSetFor
import org.perses.tree.spar.AbstractNodeActionSetCache
import org.perses.tree.spar.AbstractSparTreeEdit
import org.perses.tree.spar.SparTree

class DeltaDebugger constructor(
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

    var worklist = LinkedList<Partition>()
    for (i in startPartitions.size - 1 downTo 0) {
      worklist.add(startPartitions[i])
    }
    while (!worklist.isEmpty()) {
      var shouldContinue: Boolean
      do {
        shouldContinue = false
        val iterator = worklist.iterator()
        while (iterator.hasNext()) {
          val partition = iterator.next()
          val actionSet = createNodeDeletionActionSetFor(
            partition, actionsDescription + "@" + partition.size())
          if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
            listenerManager.onNodeEditActionSetCacheHit(actionSet)
            continue
          }
          val edit = tree.createNodeDeletionEdit(actionSet)
          val best = treeEditTester.apply(edit)
          if (best.isPresent) {
            tree.applyEdit(best.get().edit)
            iterator.remove()
            shouldContinue = true
          }
        }
      } while (shouldContinue)
      val copy = worklist
      worklist = LinkedList()
      assert(worklist !== copy)
      for (partition in copy) {
        val splits = partition.split()
        for (split in splits) {
          worklist.add(split)
        }
      }
    }
  }
}
