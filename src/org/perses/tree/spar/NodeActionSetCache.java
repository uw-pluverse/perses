package org.perses.tree.spar;

import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentHashMap.KeySetView;

public final class NodeActionSetCache extends AbstractNodeActionSetCache {

  private final KeySetView<NodeDeletionActionSet, Boolean> delectionCache =
      ConcurrentHashMap.newKeySet();
  private final KeySetView<ChildHoistingActionSet, Boolean> replacementCache =
      ConcurrentHashMap.newKeySet();

  @Override
  public boolean isCachedOrCacheIt(NodeDeletionActionSet actionSet) {
    return !delectionCache.add(actionSet);
  }

  @Override
  public boolean isCachedOrCacheIt(ChildHoistingActionSet actionSet) {
    return !replacementCache.add(actionSet);
  }

  @Override
  public void clear() {
    delectionCache.clear();
    replacementCache.clear();
  }

  @Override
  public int size() {
    return delectionCache.size() + replacementCache.size();
  }
}
