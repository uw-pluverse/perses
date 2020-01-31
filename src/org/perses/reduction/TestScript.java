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

import com.google.common.flogger.FluentLogger;
import org.perses.util.Shell;
import org.perses.util.TimeSpan;

import java.io.File;

/** Represents a test script, that specifies the property to preserve during reduction. */
public class TestScript {

  private static final FluentLogger logger = FluentLogger.forEnclosingClass();

  private final File scriptFile;

  public TestScript(File script) {
    this.scriptFile = script;
    this.scriptFile.setExecutable(true);
  }

  public File getScriptFile() {
    return scriptFile;
  }

  /** @return true if the test script passes. */
  public TestResult test() {
    final TimeSpan.Builder timeSpanBuilder = TimeSpan.Builder.start(System.currentTimeMillis());
    final Shell.CmdOutput output =
        Shell.run("./" + this.scriptFile.getName(), this.scriptFile.getParentFile(), false);
    logger.atFine().log("test script stdout: %s", output.getStdout());
    logger.atFine().log("test script stderr: %s", output.getStderr());
    final TimeSpan timeSpan = timeSpanBuilder.end(System.currentTimeMillis());
    return new TestResult(output.getExitCode(), timeSpan.getElapsedTimeInMillis());
  }

  /** The result of a test, including runtime information, i.e., time, exit code. */
  public static class TestResult {

    public static final int EXIT_CODE_COMPILATION_FAILURE = 95;
    public static final int EXIT_CODE_COMMON_FAILURE = 1;
    private final int exitCode;
    private final long elapsedMilliseconds;

    public TestResult(int exitCode, long elapsedMilliseconds) {
      this.exitCode = exitCode;
      this.elapsedMilliseconds = elapsedMilliseconds;
    }

    public static final TestResult createCompilationFailureResult() {
      return new TestResult(EXIT_CODE_COMPILATION_FAILURE, 0);
    }

    public long getElapsedMilliseconds() {
      return elapsedMilliseconds;
    }

    public boolean isPass() {
      return this.exitCode == 0;
    }

    public boolean isCompilationFailure() {
      return this.exitCode == EXIT_CODE_COMPILATION_FAILURE;
    }
  }
}
