package org.perses.tree.spar;

import java.util.HashSet;

public final class NodeActionSetCache extends AbstractNodeActionSetCache {

  private final HashSet<NodeDeletionActionSet> delectionCache = new HashSet<>();
  private final HashSet<ChildHoistingActionSet> replacementCache = new HashSet<>();

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
