/*
 * Copyright (C) 2018-2020 University of Waterloo.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
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
