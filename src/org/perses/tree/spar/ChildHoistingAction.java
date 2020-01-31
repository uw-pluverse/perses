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
