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

package org.perses.tree.spar;

import com.google.common.collect.ComparisonChain;
import com.google.common.collect.ImmutableList;
import org.perses.program.TokenizedProgram;

import java.util.concurrent.atomic.AtomicInteger;

public abstract class AbstractSparTreeEdit implements Comparable<AbstractSparTreeEdit> {

  public static NodeDeletionTreeEdit createDeletionSparTreeEdit(
      SparTree tree, NodeDeletionActionSet actionSet) {
    return new NodeDeletionTreeEdit(tree, actionSet);
  }

  public static NodeReplacementTreeEdit createReplacementSparTreeEdit(
      SparTree tree, ChildHoistingActionSet actionSet) {
    return new NodeReplacementTreeEdit(tree, actionSet);
  }

  private static final AtomicInteger idGenerator = new AtomicInteger();

  private final int id;
  private final AbstractActionSet<?> simpleActionSet;
  private final TokenizedProgram program;

  AbstractSparTreeEdit(AbstractActionSet<?> actionSet, TokenizedProgram program) {
    id = idGenerator.getAndIncrement();
    this.simpleActionSet = actionSet;
    this.program = program;
  }

  public TokenizedProgram getProgram() {
    return program;
  }

  public NodeDeletionTreeEdit asNodeDeleteEdit() {
    return (NodeDeletionTreeEdit) this;
  }

  public NodeReplacementTreeEdit asNodeReplacementEdit() {
    return (NodeReplacementTreeEdit) this;
  }

  public abstract ImmutableList<? extends AbstractTreeEditAction> getActions();

  public final int getNumberOfActions() {
    return simpleActionSet.size();
  }

  public final AbstractActionSet<?> getActionSet() {
    return simpleActionSet;
  }

  public final boolean isNodeATarget(AbstractSparTreeNode node) {
    return simpleActionSet.containsNodeAsTarget(node);
  }

  public boolean isEmpty() {
    // TODO: implement this one.
    return false;
  }

  @Override
  public int compareTo(AbstractSparTreeEdit o) {
    return ComparisonChain.start()
        .compare(program.tokenCount(), o.program.tokenCount())
        .compare(id, o.id)
        .result();
  }
}
