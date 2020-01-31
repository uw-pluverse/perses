package org.perses.tree.spar;

public class NullNodeActionSetCache extends AbstractNodeActionSetCache {
  @Override
  public boolean isCachedOrCacheIt(NodeDeletionActionSet actionSet) {
    return false;
  }

  @Override
  public boolean isCachedOrCacheIt(ChildHoistingActionSet actionSet) {
    return false;
  }

  @Override
  public void clear() {}

  @Override
  public int size() {
    return 0;
  }
}
