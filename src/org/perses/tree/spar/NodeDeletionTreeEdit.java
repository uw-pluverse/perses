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
