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

import com.google.common.io.Files;
import com.google.common.truth.Truth;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Path;
import java.nio.file.Paths;
import org.junit.Ignore;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;

/** Test for building spar-tree from Java source files. */
@RunWith(JUnit4.class)
public class JavaSparTreeBuildTest {

  private static final Path FOLDER = Paths.get("test_data/java_helloworld/");

  @Ignore("This is a golden test, which is difficult to maintain. We should have real unit tests.")
  @Test
  public void testBuildHelloWorldTree() throws IOException {
    final SparTree tree = TestUtility.createSparTreeFromFile(FOLDER.resolve("t.java"));
    final String treeStructure = tree.printTreeStructure().trim();
    final String goldenContent =
        Files.asCharSource(
                FOLDER.resolve("t_java.spart_tree.golden.txt").toFile(), StandardCharsets.UTF_8)
            .read()
            .trim();
    Truth.assertThat(treeStructure).isEqualTo(goldenContent);
  }
}
