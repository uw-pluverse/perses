/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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
package org.perses.reduction.reducer;

import com.google.common.collect.ImmutableList;
import org.perses.reduction.AbstractReducer;
import org.perses.reduction.ReducerAnnotation;
import org.perses.reduction.ReducerContext;
import org.perses.reduction.partition.Partition;
import org.perses.tree.spar.AbstractSparTreeEdit;
import org.perses.tree.spar.NodeDeletionActionSet;
import org.perses.tree.spar.SparTree;

import java.util.Collections;
import java.util.List;

/** Implementation of the original HDD algorithm. */
public class HDDReducer extends AbstractLevelBasedReducer {

  public static final String NAME = "hdd";

  public static final ReducerAnnotation META =
      new ReducerAnnotation() {
        @Override
        public String shortName() {
          return NAME;
        }

        @Override
        public String description() {
          return "";
        }

        @Override
        public AbstractReducer create(ReducerContext reducerContext) {
          return new HDDReducer(reducerContext);
        }
      };

  public HDDReducer(ReducerContext reducerContext) {
    super(META, reducerContext);
  }

  @Override
  protected List<AbstractSparTreeEdit> createTreeEditListByDisablingPartition(
      Partition partition, SparTree tree) {
    final NodeDeletionActionSet actionSet =
        TreeTransformations.createNodeDeletionActionSetFor(partition, "HDD");
    if (nodeActionSetCache.isCachedOrCacheIt(actionSet)) {
      listenerManager.onNodeEditActionSetCacheHit(actionSet);
      return Collections.emptyList();
    }
    return ImmutableList.of(tree.createNodeDeletionEdit(actionSet));
  }
}
