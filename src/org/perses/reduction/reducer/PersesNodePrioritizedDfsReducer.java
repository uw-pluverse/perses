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

import org.perses.reduction.AbstractReducer;
import org.perses.reduction.ReducerAnnotation;
import org.perses.reduction.ReducerContext;
import org.perses.tree.spar.AbstractSparTreeNode;

import java.util.PriorityQueue;
import java.util.Queue;

/** Perses node reducer, with dfs delta debugging */
public final class PersesNodePrioritizedDfsReducer extends PersesNodeDfsReducer {

  public static final String NAME = "perses_node_priority_with_dfs_delta";
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
          return new PersesNodePrioritizedDfsReducer(reducerContext);
        }
      };

  public PersesNodePrioritizedDfsReducer(ReducerContext reducerContext) {
    super(META, reducerContext);
  }

  @Override
  protected Queue<AbstractSparTreeNode> createReductionQueue() {
    return new PriorityQueue<>(
        DEFAULT_INITIAL_QUEUE_CAPACITY, TreeNodeComparatorInLeafTokenCount.SINGLETON);
  }
}
