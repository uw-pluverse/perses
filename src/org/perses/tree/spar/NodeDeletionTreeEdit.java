package org.perses.tree.spar;

import com.google.common.collect.ImmutableList;
import org.perses.program.TokenizedProgram;

import java.util.Collections;
import java.util.List;

public final class NodeDeletionTreeEdit extends AbstractSparTreeEdit {

  private final NodeDeletionActionSet actionSet;

  NodeDeletionTreeEdit(SparTree tree, NodeDeletionActionSet actionSet) {
    super(actionSet, computeProgram(tree, actionSet));
    this.actionSet = actionSet;
  }

  @Override
  public ImmutableList<NodeDeletionAction> getActions() {
    return actionSet.getActions();
  }

  private static TokenizedProgram computeProgram(
      final SparTree tree, final NodeDeletionActionSet actionSet) {
    return tree.customizeProgram(new TokenizedProgramConstructor(actionSet));
  }

  private static class TokenizedProgramConstructor extends AbstractTokenizedProgramCustomizer {

    private TokenizedProgramConstructor(NodeDeletionActionSet actionSet) {
      super(actionSet);
    }

    @Override
    public List<AbstractSparTreeNode> visit(AbstractSparTreeNode node) {
      assert !node.isPermanentlyDeleted();
      if (node.isPermanentlyDeleted()) {
        return Collections.emptyList();
      }
      if (targets.contains(node)) {
        return Collections.emptyList();
      }
      if (pathsToRootExcludingTargets.contains(node)) {
        return node.getImmutableChildView();
      }
      addTokenIntervalToResult(node);
      return Collections.emptyList();
    }
  }
}
