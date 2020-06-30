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

/** The base class for editing a tree. */
public abstract class AbstractTreeEditAction implements Comparable<AbstractTreeEditAction> {

  final AbstractSparTreeNode targetNode;

  protected AbstractTreeEditAction(AbstractSparTreeNode targetNode) {
    this.targetNode = targetNode;
  }

  public final AbstractSparTreeNode getTargetNode() {
    return targetNode;
  }

  public final NodeDeletionAction asNodeDeletionAction() {
    return (NodeDeletionAction) this;
  }

  public final ChildHoistingAction asChildHoistingAction() {
    return (ChildHoistingAction) this;
  }

  @Override
  public final int compareTo(AbstractTreeEditAction o) {
    return internalCompareTo(o);
  }

  protected abstract int internalCompareTo(AbstractTreeEditAction o);

  public abstract String getDescription();

  @Override
  public String toString() {
    return getDescription();
  }

  @Override
  public final boolean equals(Object obj) {
    if (obj == null) {
      return false;
    }
    if (obj == this) {
      return true;
    }
    if (getClass() != obj.getClass()) {
      return false;
    }
    final AbstractTreeEditAction other = (AbstractTreeEditAction) obj;
    if (targetNode != other.targetNode) {
      return false;
    }
    return specificEquals(other);
  }

  protected abstract boolean specificEquals(AbstractTreeEditAction other);

  @Override
  public final int hashCode() {
    return 31 * specificHashCode() + targetNode.getNodeId();
  }

  protected abstract int specificHashCode();
}
