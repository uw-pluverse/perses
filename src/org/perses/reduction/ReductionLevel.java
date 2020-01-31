/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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

package org.perses.reduction;

import com.google.common.base.MoreObjects;
import org.perses.tree.spar.AbstractSparTreeNode;
import org.perses.util.Util;

import java.util.ArrayList;
import java.util.function.Consumer;

/** Represents a level in a spar-tree. */
public final class ReductionLevel {

  private final ArrayList<AbstractSparTreeNode> nodes = new ArrayList<>();
  private final int level;

  public ReductionLevel(int level) {
    this.level = level;
  }

  public ReductionLevel(int level, AbstractSparTreeNode node) {
    this(level);
    this.addNode(node);
  }

  public static boolean isNullOrEmpty(ReductionLevel level) {
    return level == null || level.isEmpty();
  }

  public void addNode(AbstractSparTreeNode node) {
    assert !node.isPermanentlyDeleted() : "The node to add is already permanently deleted.";
    this.nodes.add(node);
  }

  public void replaceNode(AbstractSparTreeNode origNode, AbstractSparTreeNode replacement) {
    final int index = nodes.indexOf(origNode);
    assert index >= 0 : nodes;
    nodes.set(index, replacement);
  }

  public boolean containsNode(AbstractSparTreeNode node) {
    return nodes.contains(node);
  }

  public int getNodeCount() {
    return this.nodes.size();
  }

  public boolean isEmpty() {
    return this.getNodeCount() == 0;
  }

  public AbstractSparTreeNode getNode(int index) {
    return this.nodes.get(index);
  }

  public void forEachNode(Consumer<AbstractSparTreeNode> consumer) {
    this.nodes.forEach(consumer);
  }

  public void cleanDeletedNodes() {
    Util.removeElementsFromList(this.nodes, AbstractSparTreeNode::isPermanentlyDeleted);
  }

  public int getLevel() {
    return level;
  }

  @Override
  public String toString() {
    return MoreObjects.toStringHelper(this).add("level", level).add("nodes", nodes).toString();
  }
}
