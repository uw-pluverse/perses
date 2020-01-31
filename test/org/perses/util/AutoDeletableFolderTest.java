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
