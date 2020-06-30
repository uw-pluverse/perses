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

import com.google.common.collect.ImmutableList;

import java.util.Comparator;
import java.util.LinkedHashSet;

import static com.google.common.base.Preconditions.checkState;

public final class NodeDeletionActionSet extends AbstractActionSet<NodeDeletionAction> {

  public static final class Builder {
    private final LinkedHashSet<AbstractSparTreeNode> nodesToDelete = new LinkedHashSet<>();
    private final String actionsDescription;

    public Builder(String actionsDescription) {
      this.actionsDescription = actionsDescription;
    }

    public void deleteNode(AbstractSparTreeNode node) {
      checkState(nodesToDelete.add(node));
    }

    public NodeDeletionActionSet build() {
      return new NodeDeletionActionSet(
          nodesToDelete.stream()
              .sorted(Comparator.comparing(AbstractSparTreeNode::getNodeId))
              .map(NodeDeletionAction::new)
              .collect(ImmutableList.toImmutableList()),
          actionsDescription);
    }

    public final int size() {
      return nodesToDelete.size();
    }
  }

  public static NodeDeletionActionSet createByDeleteSingleNode(
      AbstractSparTreeNode node, String actionsDescription) {
    return new NodeDeletionActionSet(
        ImmutableList.of(new NodeDeletionAction(node)), actionsDescription);
  }

  private NodeDeletionActionSet(
      ImmutableList<NodeDeletionAction> actions, String actionsDescription) {
    super(actions, actionsDescription);
  }
}
