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

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;

import java.io.File;
import java.io.IOException;
import java.util.HashSet;
import java.util.stream.Collectors;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class NodeDeletionActionSetTest {

  private SparTree tree;
  private AbstractSparTreeNode node5;
  private AbstractSparTreeNode node10;
  private AbstractSparTreeNode node46;
  private NodeDeletionActionSet actionSet;
  private NodeDeletionActionSet actionSet2;

  @Before
  public void setup() throws IOException {
    tree = TestUtility.createSparTreeFromFile(new File("test_data/parentheses/t.c"));

    node5 = tree.getNodeByTreeScanForId(5).get();
    node10 = tree.getNodeByTreeScanForId(10).get();
    node46 = tree.getNodeByTreeScanForId(46).get();
    {
      NodeDeletionActionSet.Builder builder = new NodeDeletionActionSet.Builder("edit 1");
      builder.deleteNode(node5);
      builder.deleteNode(node10);
      actionSet = builder.build();
      assertThat(actionSet.getActionsDescription()).isEqualTo("edit 1");
    }
    {
      NodeDeletionActionSet.Builder builder = new NodeDeletionActionSet.Builder("test 2");
      builder.deleteNode(node10);
      builder.deleteNode(node5);
      actionSet2 = builder.build();
      assertThat(actionSet2.getActionsDescription()).isEqualTo("test 2");
    }
  }

  @Test
  public void testContainsNodeAsTarget() {
    assertThat(actionSet.containsNodeAsTarget(node5)).isTrue();
    assertThat(actionSet.containsNodeAsTarget(node10)).isTrue();
    assertThat(actionSet.containsNodeAsTarget(node46)).isFalse();
  }

  @Test
  public void testActionsAreSortedAndDistinct() {
    assertThat(
            actionSet.getActions().stream()
                .map(NodeDeletionAction::getTargetNode)
                .collect(Collectors.toList()))
        .containsExactly(node5, node10)
        .inOrder();
    assertThat(
            actionSet2.getActions().stream()
                .map(NodeDeletionAction::getTargetNode)
                .collect(Collectors.toList()))
        .containsExactly(node5, node10)
        .inOrder();
  }

  @Test
  public void testActionSetEqualsAndHashcode() {
    assertThat(actionSet.getActions()).hasSize(2);
    assertThat(actionSet.getActions().get(0)).isEqualTo(actionSet2.getActions().get(0));
    assertThat(actionSet.getActions().get(1)).isEqualTo(actionSet2.getActions().get(1));

    assertThat(actionSet.equals(actionSet2)).isTrue();
    assertThat(actionSet.hashCode()).isEqualTo(actionSet2.hashCode());

    final HashSet<NodeDeletionActionSet> set = new HashSet<>();
    set.add(actionSet);
    assertThat(set).containsExactly(actionSet2);
  }

  @Test
  public void testActionSetNotEqual() {
    final NodeDeletionActionSet other =
        NodeDeletionActionSet.createByDeleteSingleNode(node5, "test");
    assertThat(actionSet).isNotEqualTo(other);
    assertThat(actionSet.hashCode()).isNotEqualTo(other.hashCode());
    assertThat(other.getActionsDescription()).isEqualTo("test");
  }
}
