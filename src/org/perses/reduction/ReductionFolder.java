package org.perses.reduction;

import com.google.common.base.MoreObjects;
import com.google.common.collect.ImmutableList;
import com.google.common.io.MoreFiles;
import com.google.common.io.RecursiveDeleteOption;

import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;

// TODO: save the test result in the folder.
public final class ReductionFolder {
  private final File folder;
  private final TestScript testScript;
  private final File sourceFile;

  ReductionFolder(File folder, final String testScriptName, final String sourceFileName) {
    this.folder = folder;
    this.testScript = new TestScript(new File(folder, testScriptName));
    this.sourceFile = new File(folder, sourceFileName);

    assert this.testScript.getScriptFile().isFile()
        : "The test script file " + this.testScript.getScriptFile() + "does not exist";
    assert this.testScript.getScriptFile().canExecute() : "The test script file " + this.testScript;
  }

  public File getFolder() {
    return folder;
  }

  public TestScript getTestScript() {
    return testScript;
  }

  public File getSourceFilePath() {
    return sourceFile;
  }

  public void deleteAllOtherFiles() throws IOException {
    final ImmutableList<String> fileNamesToKeep =
        ImmutableList.of(testScript.getScriptFile().getName(), sourceFile.getName());
    final File[] filesToDelete =
        folder.listFiles(
            new FilenameFilter() {
              @Override
              public boolean accept(File dir, String name) {
                return !fileNamesToKeep.contains(name);
              }
            });
    for (File fileToDelete : filesToDelete) {
      if (fileToDelete.isDirectory()) {
        MoreFiles.deleteRecursively(fileToDelete.toPath(), RecursiveDeleteOption.ALLOW_INSECURE);
      } else {
        fileToDelete.delete();
      }
    }
  }

  @Override
  public String toString() {
    return MoreObjects.toStringHelper(this).add("working directory", folder).toString();
  }
}
