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
package org.perses.reduction.reducer;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.reduction.AbstractPersesReducerTest;
import org.perses.reduction.partition.Partition;
import org.perses.tree.spar.SparTree;
import org.perses.tree.spar.AbstractSparTreeNode;

import java.io.IOException;

import static com.google.common.truth.Truth.assertThat;

/** Test for {@link AbstractPersesNodeReducer} */
@RunWith(JUnit4.class)
public class PersesNodeReducerTest extends AbstractPersesReducerTest {

  public PersesNodeReducerTest() throws IOException {}

  @Test
  public void testCreatePartition() {
    final SparTree tree = treeT1;
    {
      AbstractSparTreeNode node = tree.getNodeByTreeScanForId(2).get();
      assertThat(node.getRuleName()).isEqualTo("kleene_plus__externalDeclaration");
      {
        final Partition p1 = AbstractPersesNodeReducer.createPartition(node, 0, 1);
        assertThat(p1.size()).isEqualTo(1);
        assertThat(p1.getFirst()).isEqualTo(node.getChild(0));
      }
      {
        final Partition p2 = AbstractPersesNodeReducer.createPartition(node, 0, 2);
        assertThat(p2.size()).isEqualTo(2);
        assertThat(p2.getFirst()).isEqualTo(node.getChild(0));
        assertThat(p2.getNode(1)).isEqualTo(node.getChild(1));
      }
    }
  }
}
