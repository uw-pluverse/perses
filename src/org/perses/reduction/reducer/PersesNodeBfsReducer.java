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
import org.perses.reduction.partition.Partition;
import org.perses.tree.spar.AbstractSparTreeNode;
import org.perses.tree.spar.SparTree;

import java.util.ArrayDeque;
import java.util.Queue;

/** Perses node reducer, with bfs delta debugging */
public class PersesNodeBfsReducer extends AbstractPersesNodeReducer {

  public static final String NAME = "perses_node_with_bfs_delta";

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
          return new PersesNodeBfsReducer(this, reducerContext);
        }
      };

  private final BfsDeltaDebugger deltaDebugger;

  protected PersesNodeBfsReducer(
      ReducerAnnotation reducerAnnotation, ReducerContext reducerContext) {
    super(reducerAnnotation, reducerContext);
    deltaDebugger =
        new BfsDeltaDebugger(
            reducerContext.getListenerManager(),
            reducerContext.getNodeActionSetCache(),
            this::testSparTreeEdit);
  }

  @Override
  protected Queue<AbstractSparTreeNode> createReductionQueue() {
    return new ArrayDeque<>(DEFAULT_INITIAL_QUEUE_CAPACITY);
  }

  @Override
  protected void performDelta(
      SparTree tree, String actionsDescription, Partition... startPartitions) {
    assert startPartitions.length > 0;
    deltaDebugger.reduce(tree, actionsDescription, startPartitions);
  }
}
