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

import com.google.common.io.Files;
import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

/** Test for {@link SparTreeSimplifier} */
@RunWith(JUnit4.class)
public class SparTreeSimplifierTest {

  @Test
  public void testSESESimplification() throws IOException {
    final SparTree tree = TestUtility.createSparTreeFromFile(new File("test_data/misc/t10.c"));
    SparTreeSimplifier.simplifySingleEntrySingleExitPath(tree);
    final String treeStructure = tree.getRoot().printTreeStructure();
    Truth.assertThat(treeStructure.trim())
        .isEqualTo(
            Files.asCharSource(
                    new File(
                        "test_data/misc/t10.c.after_sese_simplification_spartree.dump.golden.txt"),
                    StandardCharsets.UTF_8)
                .read()
                .trim());
  }
}
