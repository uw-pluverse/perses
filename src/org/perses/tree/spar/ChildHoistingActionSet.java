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

import java.util.LinkedHashMap;

import static com.google.common.base.Preconditions.checkState;

public final class ChildHoistingActionSet extends AbstractActionSet<ChildHoistingAction> {

  public static final class Builder {

    private final String actionsDescription;
    private final LinkedHashMap<AbstractSparTreeNode, AbstractSparTreeNode> node2ReplacementMap =
        new LinkedHashMap<>();

    public Builder(String actionsDescription) {
      this.actionsDescription = actionsDescription;
    }

    public void replaceNode(AbstractSparTreeNode targetNode, AbstractSparTreeNode replacement) {
      checkState(node2ReplacementMap.put(targetNode, replacement) == null);
    }

    public ChildHoistingActionSet build() {
      return new ChildHoistingActionSet(
          node2ReplacementMap.entrySet().stream()
              .map(entry -> new ChildHoistingAction(entry.getKey(), entry.getValue()))
              .collect(ImmutableList.toImmutableList()),
          actionsDescription);
    }
  }

  public static final ChildHoistingActionSet createByReplacingSingleNode(
      AbstractSparTreeNode targetNode,
      AbstractSparTreeNode replacingNode,
      String actionsDescription) {
    return createByReplacingSingleNode(
        new ChildHoistingAction(targetNode, replacingNode), actionsDescription);
  }

  public static final ChildHoistingActionSet createByReplacingSingleNode(
      ChildHoistingAction action, String actionsDescription) {
    return new ChildHoistingActionSet(ImmutableList.of(action), actionsDescription);
  }

  private ChildHoistingActionSet(
      ImmutableList<ChildHoistingAction> childHoistingActions, String actionsDescription) {
    super(childHoistingActions, actionsDescription);
  }
}
