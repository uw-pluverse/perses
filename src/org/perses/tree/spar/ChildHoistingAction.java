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

import com.google.common.base.MoreObjects;
import com.google.common.collect.ComparisonChain;

import static com.google.common.base.Preconditions.checkArgument;

public final class ChildHoistingAction extends AbstractTreeEditAction {

  private final AbstractSparTreeNode replacingChild;

  public ChildHoistingAction(AbstractSparTreeNode targetNode, AbstractSparTreeNode replacingChild) {
    super(targetNode);
    this.replacingChild = replacingChild;
  }

  public AbstractSparTreeNode getReplacingChild() {
    return replacingChild;
  }

  @Override
  protected int internalCompareTo(AbstractTreeEditAction o) {
    checkArgument(o instanceof ChildHoistingAction);
    final ChildHoistingAction other = (ChildHoistingAction) o;
    return ComparisonChain.start()
        .compare(targetNode.getNodeId(), other.targetNode.getNodeId())
        .compare(replacingChild.getNodeId(), other.replacingChild.getNodeId())
        .result();
  }

  @Override
  public String getDescription() {
    return MoreObjects.toStringHelper(this)
        .add("target_node", targetNode.getNodeId())
        .add("replacement", replacingChild.getNodeId())
        .toString();
  }

  @Override
  protected boolean specificEquals(AbstractTreeEditAction other) {
    if (!(other instanceof ChildHoistingAction)) {
      return false;
    }
    ChildHoistingAction action = (ChildHoistingAction) other;
    return action.replacingChild == replacingChild;
  }

  @Override
  protected int specificHashCode() {
    return replacingChild.getNodeId();
  }
}
