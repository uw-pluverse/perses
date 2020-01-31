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
package org.perses.tree.spar;

import com.google.common.collect.ImmutableList;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;
import org.perses.program.TokenizedProgram;

import java.io.File;
import java.io.IOException;

import static com.google.common.truth.Truth.assertThat;

/** Test for {@link SparTree} */
@RunWith(JUnit4.class)
public class SparTreeTest {

  private SparTree tree;
  private TestUtility.NodeToTokensMap nodeToTokensMap;

  @Before
  public void setup() throws IOException {
    tree = TestUtility.createSparTreeFromFile(new File("test_data/parentheses/t.c"));
    nodeToTokensMap = TestUtility.createNodeToTokensMap(tree);
  }

  @Test
  public void testChildHoisting() {
    //    final AbstractSparTreeEdit.NodeReplacementTreeEdit treeEdit =
    // tree.createNodeReplacementEdit();
    final ImmutableList<String> node1Key =
        ImmutableList.of(
            "{",
            "{",
            "{",
            "{",
            "{",
            "printf",
            "(",
            "(",
            "\"hello world\\n\"",
            ")",
            ")",
            ";",
            "}",
            "}",
            "}",
            "}",
            "}");
    final AbstractSparTreeNode node1 = nodeToTokensMap.getNode(node1Key, "compoundStatement");

    final ImmutableList<String> node2Key =
        ImmutableList.of("{", "printf", "(", "(", "\"hello world\\n\"", ")", ")", ";", "}");
    AbstractSparTreeNode node2 = nodeToTokensMap.getNode(node2Key, "compoundStatement");

    final NodeReplacementTreeEdit edit =
        tree.createNodeReplacementEdit(
            ChildHoistingActionSet.createByReplacingSingleNode(node1, node2, "[test]replacement"));

    TokenizedProgram programByEdit = edit.getProgram();
    assertThat(programByEdit.getSourceCodeInOrigFormat().replaceAll("\\s+", ""))
        .isEqualTo("intmain(){printf((\"helloworld\\n\"));}");
    tree.applyEdit(edit);
    TokenizedProgram programByTree = tree.getProgramSnapshot();
    assertThat(programByEdit.getTokens())
        .containsExactlyElementsIn(programByTree.getTokens())
        .inOrder();
  }

  @Test
  public void testSingleUntypesArgInCFunction() throws IOException {
    SparTree tree =
        TestUtility.createSparTreeFromFile(new File("test_data/misc/main_with_1_arg.c"));
    tree.printTreeStructureToStdout();
  }
}
