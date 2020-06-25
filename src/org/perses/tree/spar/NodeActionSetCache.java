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
