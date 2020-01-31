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
