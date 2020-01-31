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
