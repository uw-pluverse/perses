package org.perses.tree.spar;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import org.perses.program.PersesToken;

import java.util.HashSet;

public abstract class AbstractTokenizedProgramCustomizer implements ISparTreeNodeVisitor {

  protected final ImmutableSet<AbstractSparTreeNode> targets;
  protected final HashSet<AbstractSparTreeNode> pathsToRootExcludingTargets;
  protected final ImmutableList.Builder<PersesToken> builder =
      ImmutableList.builderWithExpectedSize(1000);

  protected AbstractTokenizedProgramCustomizer(AbstractActionSet<?> actionSet) {
    this.targets = actionSet.getTargets();
    pathsToRootExcludingTargets = computePathsToRootExcludingTargets(targets);
  }

  public final ImmutableList<PersesToken> getResult() {
    return builder.build();
  }

  protected void addTokenIntervalToResult(AbstractSparTreeNode node) {
    final LexerRuleSparTreeNode beginToken = node.beginToken();
    final LexerRuleSparTreeNode endToken = node.endToken();
    if (beginToken == null) {
      assert endToken == null;
    } else {
      assert endToken != null;
      final LexerRuleSparTreeNode sentinel = endToken.getNext();
      for (LexerRuleSparTreeNode i = beginToken; i != sentinel; i = i.getNext()) {
        builder.add(i.getToken());
      }
    }
  }

  private final HashSet<AbstractSparTreeNode> computePathsToRootExcludingTargets(
      ImmutableSet<AbstractSparTreeNode> targets) {
    final HashSet<AbstractSparTreeNode> result = new HashSet<>();
    for (AbstractSparTreeNode target : targets) {
      AbstractSparTreeNode.ParentInfo parent = target.getParentInfo();
      while (parent != null) {
        final ParserRuleSparTreeNode node = parent.getNode();
        if (result.add(node)) {
          parent = node.getParentInfo();
        } else {
          break;
        }
      }
    }
    return result;
  }
}
