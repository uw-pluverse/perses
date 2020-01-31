package org.perses.reduction;

import com.google.common.base.Preconditions;
import com.google.common.base.Strings;
import org.perses.program.SourceFile;

import java.io.File;
import java.io.IOException;
import java.util.concurrent.atomic.AtomicInteger;

public final class ReductionFolderManager {

  public static final int FOLDER_NAME_MIN_LENGTH = 6;

  private final File rootFolder;
  private final SourceFile testScript;
  private final String sourceFileName;

  private final AtomicInteger sequenceGenerator = new AtomicInteger();

  public ReductionFolderManager(File rootFolder, SourceFile testScript, String sourceFileName) {
    Preconditions.checkArgument(
        rootFolder.exists(), "The root folder does not exist: %s", rootFolder);
    Preconditions.checkArgument(
        rootFolder.isDirectory(), "The root folder is not a directory: %s", rootFolder);
    this.rootFolder = rootFolder;
    this.testScript = testScript;
    this.sourceFileName = sourceFileName;
  }

  public ReductionFolder createNextFolder() throws IOException {
    final int folderId = sequenceGenerator.getAndIncrement();
    final String folderName =
        Strings.padStart(Integer.toString(folderId), FOLDER_NAME_MIN_LENGTH, '0');
    File folder = new File(rootFolder, folderName);
    assert !folder.exists() : "The folder already exists. " + folder;
    Preconditions.checkState(folder.mkdir(), "Failed to create folder %s", folder);

    final String scriptFileName = testScript.getBaseName();
    testScript.writeTo(new File(folder, scriptFileName));
    return new ReductionFolder(folder, scriptFileName, sourceFileName);
  }
}
