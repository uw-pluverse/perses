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
package org.perses.reduction;

import org.perses.program.SourceFile;
import org.perses.program.TokenizedProgram;

import java.io.File;
import java.io.IOException;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.FutureTask;
import java.util.concurrent.atomic.AtomicInteger;

import static com.google.common.base.Preconditions.checkArgument;
import static com.google.common.base.Preconditions.checkState;

/** An execution service for test script runs. */
public class TestScriptExecutorService {

  private final AtomicInteger executionCounter = new AtomicInteger();
  private final ExecutorService executorService;
  private final int numOfThreads;
  private final ReductionFolderManager reductionFolderManager;

  public TestScriptExecutorService(
      File tempRootFolder, final int numOfThreads, SourceFile testScriptFile, String sourceFileName)
      throws IOException {
    this.numOfThreads = numOfThreads;
    checkArgument(
        this.numOfThreads > 0, "The number of threads must be positive: %s", numOfThreads);
    checkState(
        sourceFileName.indexOf('/') < 0 || sourceFileName.indexOf('\\') < 0,
        "Invalid source file name. It should be the name only: %s",
        sourceFileName);
    if (!tempRootFolder.exists()) {
      checkState(tempRootFolder.mkdir(), "Failed to create folder %s", tempRootFolder);
    }
    assert tempRootFolder.isDirectory()
        : "The temp root folder is not a directory: " + tempRootFolder;

    // TODO: create the executor outside, and pass it in as a parameter, so that others can use the
    //       executor.
    this.executorService = Executors.newFixedThreadPool(this.numOfThreads);
    reductionFolderManager =
        new ReductionFolderManager(tempRootFolder, testScriptFile, sourceFileName);
  }

  public void shutdown() throws IOException {
    executorService.shutdown();
    reductionFolderManager.deleteRootFolder();
  }

  /**
   * FIXME: make this method blocking if there is no available tasks. TODO: output the underlying
   * test script and source file for debugging.
   */
  public FutureTestScriptExecutionTask testProgram(
      TokenizedProgram program, boolean keepOrigCodeFormat) {
    executionCounter.incrementAndGet();
    try {
      final ReductionFolder workingFolder = reductionFolderManager.createNextFolder();
      FutureTestScriptExecutionTask result =
          new FutureTestScriptExecutionTask(
              new ReductionTestScriptExecutorCallback(workingFolder, program, keepOrigCodeFormat));
      executorService.submit(result);
      return result;
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
  }

  public int getExecutionCounter() {
    return executionCounter.get();
  }

  public static final class FutureTestScriptExecutionTask
      extends FutureTask<TestScript.TestResult> {

    private final ReductionTestScriptExecutorCallback callable;

    public FutureTestScriptExecutionTask(ReductionTestScriptExecutorCallback callable) {
      super(callable);
      this.callable = callable;
    }

    public File getWorkingDirectory() {
      return callable.workingDirectory.getFolder();
    }

    public TokenizedProgram getProgram() {
      return callable.program;
    }
  }

  /** The test script runner for future. */
  private static class ReductionTestScriptExecutorCallback
      implements Callable<TestScript.TestResult> {
    private final boolean keepOrigCodeFormat;
    private final TokenizedProgram program;
    private final ReductionFolder workingDirectory;

    private ReductionTestScriptExecutorCallback(
        ReductionFolder workingDirectory, TokenizedProgram program, boolean keepOrigCodeFormat) {
      this.keepOrigCodeFormat = keepOrigCodeFormat;
      this.workingDirectory = workingDirectory;
      this.program = program;
    }

    @Override
    public TestScript.TestResult call() throws Exception {
      program.writeToFile(workingDirectory.getSourceFilePath(), keepOrigCodeFormat);
      final TestScript.TestResult result = workingDirectory.getTestScript().test();
      workingDirectory.deleteAllOtherFiles();
      return result;
    }
  }
}
