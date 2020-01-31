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
public class NodeReplacementActionSetTest {

  private SparTree tree;
  private AbstractSparTreeNode node5;
  private AbstractSparTreeNode node10;
  private AbstractSparTreeNode node46;
  private AbstractSparTreeNode node72;

  private ChildHoistingActionSet actionSet;
  private ChildHoistingActionSet actionSet2;

  @Before
  public void setup() throws IOException {
    tree = TestUtility.createSparTreeFromFile(new File("test_data/parentheses/t.c"));

    node5 = tree.getNodeByTreeScanForId(5).get();
    node10 = tree.getNodeByTreeScanForId(10).get();
    node46 = tree.getNodeByTreeScanForId(46).get();
    node72 = tree.getNodeByTreeScanForId(72).get();

    {
      ChildHoistingActionSet.Builder builder = new ChildHoistingActionSet.Builder("test 1");
      builder.replaceNode(node5, node10);
      builder.replaceNode(node46, node72);
      actionSet = builder.build();
      assertThat(actionSet.getActionsDescription()).isEqualTo("test 1");
    }
    {
      ChildHoistingActionSet.Builder builder = new ChildHoistingActionSet.Builder("test 2");
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
                .map(ChildHoistingAction::getTargetNode)
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

    final HashSet<ChildHoistingActionSet> set = new HashSet<>();
    set.add(actionSet);
    assertThat(set).containsExactly(actionSet2);
  }

  @Test
  public void testActionSetNotEqual() {
    final ChildHoistingActionSet other =
        ChildHoistingActionSet.createByReplacingSingleNode(node72, node5, "test desc");
    assertThat(actionSet).isNotEqualTo(other);
    assertThat(actionSet.hashCode()).isNotEqualTo(other.hashCode());
    assertThat(other.getActionsDescription()).isEqualTo("test desc");
  }
}
