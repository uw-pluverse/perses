package org.perses.tree.spar;

import com.google.common.base.MoreObjects;

import static com.google.common.base.Preconditions.checkArgument;

public final class NodeDeletionAction extends AbstractTreeEditAction {

  public NodeDeletionAction(AbstractSparTreeNode targetNode) {
    super(targetNode);
  }

  @Override
  protected int internalCompareTo(AbstractTreeEditAction o) {
    checkArgument(o instanceof NodeDeletionAction);
    final NodeDeletionAction other = (NodeDeletionAction) o;
    return Integer.compare(targetNode.getNodeId(), other.targetNode.getNodeId());
  }

  @Override
  public String getDescription() {
    return MoreObjects.toStringHelper(this).add("target_node", targetNode.getNodeId()).toString();
  }

  @Override
  protected boolean specificEquals(AbstractTreeEditAction other) {
    return other.getClass() == getClass();
  }

  @Override
  protected int specificHashCode() {
    return 0;
  }
}
