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
import com.google.common.collect.Iterables;
import org.perses.program.TokenizedProgram;

import java.util.Collections;
import java.util.List;

public final class NodeReplacementTreeEdit extends AbstractSparTreeEdit {

  private final ChildHoistingActionSet actionSet;

  NodeReplacementTreeEdit(SparTree tree, ChildHoistingActionSet actionSet) {
    super(actionSet, computeProgram(tree, actionSet));
    this.actionSet = actionSet;
  }

  @Override
  public ImmutableList<ChildHoistingAction> getActions() {
    return actionSet.getActions();
  }

  public AbstractSparTreeNode getOnlyReplacementNode() {
    return Iterables.getOnlyElement(actionSet.getActions()).getReplacingChild();
  }

  private static TokenizedProgram computeProgram(SparTree tree, ChildHoistingActionSet actionSet) {
    return tree.customizeProgram(new TokenizedProgramConstructor(actionSet));
  }

  private static class TokenizedProgramConstructor extends AbstractTokenizedProgramCustomizer {
    private final ChildHoistingActionSet actionSet;

    private TokenizedProgramConstructor(ChildHoistingActionSet actionSet) {
      super(actionSet);
      this.actionSet = actionSet;
    }

    @Override
    public List<AbstractSparTreeNode> visit(AbstractSparTreeNode node) {
      assert !node.isPermanentlyDeleted();

      if (node.isPermanentlyDeleted()) {
        return Collections.emptyList();
      }
      if (targets.contains(node)) {
        final AbstractSparTreeNode replacingChild =
            actionSet.getActionForTarget(node).getReplacingChild();
        addTokenIntervalToResult(replacingChild);
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
