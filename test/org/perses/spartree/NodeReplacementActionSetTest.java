/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.spartree;

import static com.google.common.truth.Truth.assertThat;

import java.io.IOException;
import java.nio.file.Paths;
import java.util.HashSet;
import java.util.stream.Collectors;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;

@RunWith(JUnit4.class)
public class NodeReplacementActionSetTest {

  private SparTree tree;
  private org.perses.spartree.AbstractSparTreeNode node5;
  private org.perses.spartree.AbstractSparTreeNode node10;
  private org.perses.spartree.AbstractSparTreeNode node46;
  private AbstractSparTreeNode node72;

  private org.perses.spartree.ChildHoistingActionSet actionSet;
  private org.perses.spartree.ChildHoistingActionSet actionSet2;

  @Before
  public void setup() throws IOException {
    tree = TestUtility.createSparTreeFromFile(Paths.get("test_data/parentheses/t.c"));

    node5 = tree.getNodeByTreeScanForId(5);
    node10 = tree.getNodeByTreeScanForId(10);
    node46 = tree.getNodeByTreeScanForId(46);
    node72 = tree.getNodeByTreeScanForId(72);

    {
      org.perses.spartree.ChildHoistingActionSet.Builder builder =
          new org.perses.spartree.ChildHoistingActionSet.Builder("test 1");
      builder.replaceNode(node5, node10);
      builder.replaceNode(node46, node72);
      actionSet = builder.build();
      assertThat(actionSet.getActionsDescription()).isEqualTo("test 1");
    }
    {
      org.perses.spartree.ChildHoistingActionSet.Builder builder =
          new org.perses.spartree.ChildHoistingActionSet.Builder("test 2");
      builder.replaceNode(node5, node10);
      builder.replaceNode(node46, node72);
      actionSet2 = builder.build();
      assertThat(actionSet2.getActionsDescription()).isEqualTo("test 2");
    }
  }

  @Test
  public void testContainsNodeAsTarget() {
    assertThat(actionSet.containsNodeAsTarget(node5)).isTrue();
    assertThat(actionSet.containsNodeAsTarget(node46)).isTrue();
    assertThat(actionSet.containsNodeAsTarget(node10)).isFalse();
    assertThat(actionSet.containsNodeAsTarget(node72)).isFalse();
  }

  @Test
  public void testActionsAreSortedAndDistinct() {
    assertThat(
            actionSet.getActions().stream()
                .map(org.perses.spartree.ChildHoistingAction::getTargetNode)
                .collect(Collectors.toList()))
        .containsExactly(node5, node46)
        .inOrder();
    assertThat(
            actionSet2.getActions().stream()
                .map(ChildHoistingAction::getTargetNode)
                .collect(Collectors.toList()))
        .containsExactly(node5, node46)
        .inOrder();
  }

  @Test
  public void testActionSetEqualsAndHashcode() {
    assertThat(actionSet.getActions()).hasSize(2);
    assertThat(actionSet.getActions().get(0)).isEqualTo(actionSet2.getActions().get(0));
    assertThat(actionSet.getActions().get(1)).isEqualTo(actionSet2.getActions().get(1));

    assertThat(actionSet.equals(actionSet2)).isTrue();
    assertThat(actionSet.hashCode()).isEqualTo(actionSet2.hashCode());

    final HashSet<org.perses.spartree.ChildHoistingActionSet> set = new HashSet<>();
    set.add(actionSet);
    assertThat(set).containsExactly(actionSet2);
  }

  @Test
  public void testActionSetNotEqual() {
    final org.perses.spartree.ChildHoistingActionSet other =
        ChildHoistingActionSet.createByReplacingSingleNode(node72, node5, "test desc");
    assertThat(actionSet).isNotEqualTo(other);
    assertThat(actionSet.hashCode()).isNotEqualTo(other.hashCode());
    assertThat(other.getActionsDescription()).isEqualTo("test desc");
  }
}
