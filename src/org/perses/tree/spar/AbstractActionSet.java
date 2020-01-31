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

  AbstractActionSet(ImmutableList<ACTION> actions, String actionsDescription) {
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
