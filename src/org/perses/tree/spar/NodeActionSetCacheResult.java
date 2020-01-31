package org.perses.tree.spar;

import com.google.common.base.Preconditions;
import org.checkerframework.checker.nullness.qual.Nullable;

public final class NodeActionSetCacheResult<
    QUERY extends AbstractActionSet, VALUE extends AbstractSparTreeEdit> {

  public static <QUERY extends AbstractActionSet, VALUE extends AbstractSparTreeEdit>
      NodeActionSetCacheResult<QUERY, VALUE> emptyResult(QUERY query) {
    return new NodeActionSetCacheResult(query, null);
  }

  public static <QUERY extends AbstractActionSet, VALUE extends AbstractSparTreeEdit>
      NodeActionSetCacheResult<QUERY, VALUE> of(QUERY actionSet, VALUE deletionSparTreeEdit) {
    return new NodeActionSetCacheResult(actionSet, deletionSparTreeEdit);
  }

  private final QUERY cacheQuery;
  @Nullable final VALUE result;

  private NodeActionSetCacheResult(QUERY cacheQuery, @Nullable VALUE result) {
    this.cacheQuery = cacheQuery;
    this.result = result;
  }

  public QUERY getCacheQuery() {
    return cacheQuery;
  }

  public boolean isPresent() {
    return result != null;
  }

  public VALUE get() {
    return Preconditions.checkNotNull(result);
  }
}
