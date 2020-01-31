package org.perses.util;

import com.google.common.base.Preconditions;
import com.google.common.io.MoreFiles;
import com.google.common.io.RecursiveDeleteOption;

import java.io.Closeable;
import java.io.File;
import java.io.IOException;

public class AutoDeletableFolder implements Closeable {

  private final File folder;

  public AutoDeletableFolder(File folder) {
    this.folder = folder;
    if (!folder.exists()) {
      folder.mkdirs();
    }
    Preconditions.checkArgument(folder.isDirectory());
  }

  public File toFile() {
    return folder;
  }

  @Override
  public void close() throws IOException {
    if (folder.exists()) {
      MoreFiles.deleteRecursively(folder.toPath(), RecursiveDeleteOption.ALLOW_INSECURE);
    }
  }
}
