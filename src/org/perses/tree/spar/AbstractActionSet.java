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
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;

import java.util.function.Function;

public abstract class AbstractActionSet<ACTION extends AbstractTreeEditAction> {

  private final ImmutableMap<AbstractSparTreeNode, ACTION> targets;
  private final ImmutableList<ACTION> actions;
  private final String actionsDescription;

  protected AbstractActionSet(ImmutableList<ACTION> actions, String actionsDescription) {
    this.actionsDescription = actionsDescription;
    checkSortedAndDistinct(actions);

    this.actions = actions;
    this.targets =
        actions.stream()
            .collect(
                ImmutableMap.toImmutableMap(
                    AbstractTreeEditAction::getTargetNode, Function.identity()));
    assert actions.size() == this.targets.size();
    assert actions.size() > 0;
  }

  public final ImmutableList<ACTION> getActions() {
    return actions;
  }

  public final ImmutableSet<AbstractSparTreeNode> getTargets() {
    return targets.keySet();
  }

  public final boolean containsNodeAsTarget(AbstractSparTreeNode node) {
    return targets.containsKey(node);
  }

  public final ACTION getActionForTarget(AbstractSparTreeNode targetNode) {
    final ACTION result = targets.get(targetNode);
    assert result != null;
    return result;
  }

  public final int size() {
    return actions.size();
  }

  public final boolean isEmpty() {
    return actions.isEmpty();
  }

  @Override
  public final boolean equals(Object obj) {
    if (obj == null) {
      return false;
    }
    if (obj == this) {
      return true;
    }
    if (!(obj instanceof AbstractActionSet)) {
      return false;
    }
    final AbstractActionSet other = (AbstractActionSet) obj;
    return actions.equals(other.actions);
  }

  @Override
  public final int hashCode() {
    return actions.hashCode();
  }

  public String getActionsDescription() {
    return actionsDescription;
  }

  private void checkSortedAndDistinct(ImmutableList<ACTION> actions) {
    final int size = actions.size();
    if (size <= 1) {
      return;
    }
    for (int i = 1; i < size; ++i) {
      final int cmp = actions.get(i - 1).compareTo(actions.get(i));
      Preconditions.checkState(cmp < 0);
    }
    return;
  }
}
