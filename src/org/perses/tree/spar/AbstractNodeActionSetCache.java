package org.perses.tree.spar;

public abstract class AbstractNodeActionSetCache {
  public abstract boolean isCachedOrCacheIt(NodeDeletionActionSet actionSet);

  public abstract boolean isCachedOrCacheIt(ChildHoistingActionSet actionSet);

  public abstract void clear();

  public abstract int size();
}
