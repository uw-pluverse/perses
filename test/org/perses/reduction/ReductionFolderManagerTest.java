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
package org.perses.reduction;

import com.google.common.io.Files;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.program.ScriptFile;
import org.perses.program.SourceFile;
import org.perses.util.AutoDeletableFolder;

import java.io.File;
import java.io.IOException;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class ReductionFolderManagerTest {

  private AutoDeletableFolder folder;
  private ReductionFolderManager manager;
  private ScriptFile testScript;

  @Before
  public void setup() throws IOException {
    folder = new AutoDeletableFolder(Files.createTempDir());
    testScript = new ScriptFile(new File("test_data/delta_1/r.sh"));
    manager = new ReductionFolderManager(folder.toFile(), testScript, "t.c");
  }

  @After
  public void teardown() throws IOException {
    folder.close();
  }

  @Test
  public void test() throws IOException {
    final ReductionFolder firstFolder = manager.createNextFolder();
    assertThat(firstFolder.getFolder().getName()).isEqualTo("000000");
    testFolder(firstFolder);

    final ReductionFolder secondFolder = manager.createNextFolder();
    testFolder(secondFolder);
    assertThat(secondFolder.getFolder().getName()).isEqualTo("000001");
  }

  private void testFolder(ReductionFolder folder) {
    assertThat(folder.getFolder().getAbsoluteFile().getParentFile())
        .isEqualTo(this.folder.toFile().getAbsoluteFile());

    assertThat(folder.getTestScript().getScriptFile().getAbsoluteFile().getParentFile())
        .isEqualTo(folder.getFolder().getAbsoluteFile());
    assertThat(folder.getTestScript().getScriptFile().getName()).isEqualTo("r.sh");

    assertThat(folder.getSourceFilePath().getAbsoluteFile().getParentFile())
        .isEqualTo(folder.getFolder().getAbsoluteFile());
    assertThat(folder.getSourceFilePath().getName()).isEqualTo("t.c");
  }
}
