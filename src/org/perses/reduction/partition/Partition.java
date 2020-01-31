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
package org.perses.reduction.partition;

import com.google.common.base.MoreObjects;
import org.perses.tree.spar.AbstractSparTreeNode;
import org.perses.util.Util;

import java.util.ArrayList;
import java.util.function.Consumer;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * A partition contains a set of SparTreeNodes, and this set should be reduced together. A level in
 * a spar-tree may generate multiple partitions.
 */
public final class Partition {

  public static final Partition[] EMPTY_PARTITION_ARRAY = new Partition[0];
  private final ArrayList<AbstractSparTreeNode> nodes;

  public Partition(ArrayList<AbstractSparTreeNode> nodes) {
    assert nodes.size() > 0 : "A partition cannot be empty.";
    this.nodes = nodes;
  }

  public AbstractSparTreeNode getFirst() {
    return nodes.get(0);
  }

  public AbstractSparTreeNode getLast() {
    return nodes.get(nodes.size() - 1);
  }

  public boolean isEmpty() {
    return nodes.isEmpty();
  }

  public Iterable<AbstractSparTreeNode> getNodes() {
    return nodes;
  }

  public Stream<AbstractSparTreeNode> stream() {
    return nodes.stream();
  }

  public int size() {
    return nodes.size();
  }

  public AbstractSparTreeNode getNode(int index) {
    return nodes.get(index);
  }

  public void forEach(Consumer<AbstractSparTreeNode> consumer) {
    nodes.forEach(consumer);
  }

  public void removePermanentlyDeletedNodes() {
    Util.removeElementsFromList(nodes, AbstractSparTreeNode::isPermanentlyDeleted);
  }

  public Partition[] split() {
    final ArrayList<AbstractSparTreeNode> nodes = this.nodes;
    final int size = nodes.size();
    assert size > 0;
    if (size <= 1) {
      return EMPTY_PARTITION_ARRAY;
    }
    final int halfIndex = (size + 1) / 2;
    final Builder first = new Builder(halfIndex);
    for (int i = 0; i < halfIndex; ++i) {
      first.addNode(nodes.get(i));
    }
    final Builder second = new Builder(halfIndex);
    for (int i = halfIndex; i < size; ++i) {
      second.addNode(nodes.get(i));
    }
    return new Partition[] {first.build(), second.build()};
  }

  @Override
  public String toString() {
    return MoreObjects.toStringHelper(Partition.class)
        .add(
            "nodes",
            nodes.stream()
                .map(AbstractSparTreeNode::getNodeId)
                .sorted()
                .collect(Collectors.toList()))
        .toString();
  }

  /** A builder to build a Partition. */
  public static final class Builder {

    public static final int MAX_CAPACITY = 100;
    private ArrayList<AbstractSparTreeNode> nodes;

    public Builder(int capacity) {
      if (capacity > MAX_CAPACITY) {
        capacity = MAX_CAPACITY;
      }
      this.nodes = new ArrayList<>(capacity);
    }

    public final void addNode(AbstractSparTreeNode node) {
      assert nodes != null : "This builder has been used";
      nodes.add(node);
    }

    public final int size() {
      return nodes.size();
    }

    /** This method builds a partition, and the current build becomes invalid. */
    public final Partition build() {
      final Partition result = new Partition(nodes);
      nodes = null;
      return result;
    }
  }
}
