/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.spartree

import com.google.common.io.Files
import com.google.common.truth.Truth.assertThat
import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility.createSparTreeFromFile
import java.nio.charset.StandardCharsets
import java.nio.file.Paths

/** Test for building spar-tree from Java source files.  */
@RunWith(JUnit4::class)
class JavaSparTreeBuildTest {
  @Ignore("This is a golden test, which is difficult to maintain. We should have real unit tests.")
  @Test
  fun testBuildHelloWorldTree() {
    val tree = createSparTreeFromFile(FOLDER.resolve("t.java"))
    val treeStructure = tree.printTreeStructure().trim { it <= ' ' }
    val goldenContent = Files.asCharSource(
      FOLDER.resolve("t_java.spart_tree.golden.txt").toFile(),
      StandardCharsets.UTF_8,
    )
      .read()
      .trim { it <= ' ' }
    assertThat(treeStructure).isEqualTo(goldenContent)
  }

  companion object {
    private val FOLDER = Paths.get("test_data/java_helloworld/")
  }
}
