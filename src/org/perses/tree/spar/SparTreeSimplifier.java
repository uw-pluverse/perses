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

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import static com.google.common.base.Preconditions.*;

/**
 * A utility class to simplify a spar-tree, e.g., removing empty rule node path, shrink
 * single-entry-single-exit path
 */
public class SparTreeSimplifier {

  public static void simplify(SparTree tree) {
    simplify(tree.getRoot());
  }

  static void simplify(AbstractSparTreeNode root) {
    removeEmptyAndDeletedRuleNodes(root);
    simplifySingleEntrySingleExitPath(root);
  }

  /** Remove empty rule nodes and deleted sub-trees from the given tree. */
  static void removeEmptyAndDeletedRuleNodes(AbstractSparTreeNode root) {
    checkNotNull(root);
    final ArrayList<AbstractSparTreeNode> preorderNodeList = new ArrayList<>();
    root.preOrderVisit(
        node -> {
          if (node.isPermanentlyDeleted()) {
            assert assertAllChildrenAreDeleted(node);
            node.delete();
            return Collections.emptyList();
          }
          preorderNodeList.add(node);
          return node.getImmutableChildView();
        });
    for (int i = preorderNodeList.size() - 1; i >= 0; --i) {
      final AbstractSparTreeNode node = preorderNodeList.get(i);
      if (node.isPermanentlyDeleted()) {
        continue;
      }
      if (node.isTokenNode()) {
        continue;
      }
      node.cleanDeletedImmediateChildren();
      if (node.getChildCount() == 0) {
        node.delete();
      }
    }
    root.cleanDeletedImmediateChildren();
  }

  static void simplifySingleEntrySingleExitPath(SparTree tree) {
    simplifySingleEntrySingleExitPath(tree.getRoot());
  }

  /**
   * For a single-entry-single-exit path in a spar-tree, we do the following.
   * <li>Keep all meta-nodes, (Kleene Star, Kleene Plus, Optional)
   * <li>Keep the end node of the path (i.e., the fork node with in-degree=1 and out-degree>1
   * <li>Delete all the rest nodes.
   *
   *     <p>The simplification is performed in the tree.
   */
  static void simplifySingleEntrySingleExitPath(AbstractSparTreeNode root) {
    final ArrayDeque<AbstractSparTreeNode> worklist = new ArrayDeque<>();
    // We always keep the root, so push the immediate children to the stack.
    root.forEachChild(worklist::push);
    while (!worklist.isEmpty()) {
      final AbstractSparTreeNode node = worklist.pop();
      final int childCount = node.getChildCount();
      if (childCount == 0) {
        if (node.isTokenNode()) {
          continue;
        } else {
          node.getParentInfo().getNode().removeChild(node);
        }
      }
      if (node.isQuantifierNode()) {
        // Accept meta-node, and move to its children.
        node.forEachChild(worklist::push);
        continue;
      }
      if (childCount > 1) {
        // A fork node, the end node of the SESE path. Keep it and move on to its children.
        node.forEachChild(worklist::push);
        continue;
      }
      if (childCount == 1) {
        final AbstractSparTreeNode child = node.getChild(0);
        child.resetParentToNull();
        node.getParentInfo().getNode().replaceChild(node, child);
        worklist.push(child); // The child becomes the frontier.
        continue;
      }
      throw new AssertionError("Cannot reach here: " + childCount);
    }
    assert assertSingleEntrySingleExitPathProperty(root) : root.printTreeStructure();
  }

  public static boolean assertSingleEntrySingleExitPathProperty(AbstractSparTreeNode root) {
    root.forEachChild(
        immediateChild ->
            immediateChild.preOrderVisit(
                node -> {
                  final List<AbstractSparTreeNode> result = node.getImmutableChildView();
                  if (node.isQuantifierNode()) {
                    return result;
                  }
                  if (node.getChildCount() == 0) {
                    checkState(node.isTokenNode());
                  }
                  assert node.getChildCount() != 1
                      : "count="
                          + node.getChildCount()
                          + ", node="
                          + node.toString()
                          + ", immediateChild: \n"
                          + immediateChild.printTreeStructure();
                  return result;
                }));
    return true;
  }

  public static boolean assertAllChildrenAreDeleted(AbstractSparTreeNode node) {
    checkArgument(node.isPermanentlyDeleted());
    node.preOrderVisit(
        child -> {
          checkState(child.isPermanentlyDeleted());
          return child.getImmutableChildView();
        });
    return true;
  }
}
