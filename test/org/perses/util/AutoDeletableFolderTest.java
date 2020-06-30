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
package org.perses.util;

import com.google.common.io.Files;
import com.google.common.io.MoreFiles;
import com.google.common.io.RecursiveDeleteOption;
import com.google.common.truth.Truth;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.io.File;
import java.io.IOException;

@RunWith(JUnit4.class)
public class AutoDeletableFolderTest {

  private File workingDir;

  @Before
  public void setup() {
    workingDir = Files.createTempDir();
  }

  @After
  public void teardown() throws IOException {
    MoreFiles.deleteRecursively(workingDir.toPath(), RecursiveDeleteOption.ALLOW_INSECURE);
  }

  @Test
  public void testFolderIsDeletedAfterBeingClosed() {
    File folderFile = new File(workingDir, "test");
    try (AutoDeletableFolder folder = new AutoDeletableFolder(folderFile)) {
      Truth.assertThat(folder.toFile().isDirectory()).isTrue();
    } catch (Exception e) {
      Assert.fail();
    }
    Truth.assertThat(folderFile.exists()).isFalse();
  }
}
