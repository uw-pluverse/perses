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

import com.google.common.base.MoreObjects;
import com.google.common.flogger.FluentLogger;
import org.apache.commons.exec.CommandLine;
import org.apache.commons.exec.DefaultExecutor;
import org.apache.commons.exec.ExecuteException;
import org.apache.commons.exec.PumpStreamHandler;

import java.io.*;

/** Shell to run external commands. */
public final class Shell {

  private static final FluentLogger logger = FluentLogger.forEnclosingClass();
  private static final File CURRENT_DIR = new File(".");
  private static final OutputStream EMPTY_OUTPUT_STREAM =
      new OutputStream() {
        @Override
        public void write(int b) {
          // Discard all the input.
        }

        @Override
        public void write(byte[] b) {
          // Discard all the input.
        }

        @Override
        public void write(byte[] b, int off, int len) {
          // Discard all the input.
        }

        @Override
        public String toString() {
          return "From a NullOutputStream.";
        }
      };

  public static CmdOutput run(String cmd, boolean captureOutput) {
    return run(cmd, CURRENT_DIR, captureOutput);
  }

  public static CmdOutput run(String cmd, File workingDirectory, boolean captureOutput) {
    final OutputStream stdout = captureOutput ? new ByteArrayOutputStream() : EMPTY_OUTPUT_STREAM;
    final OutputStream stderr = captureOutput ? new ByteArrayOutputStream() : EMPTY_OUTPUT_STREAM;

    CommandLine commandline = CommandLine.parse(cmd);
    DefaultExecutor exec = new DefaultExecutor();
    exec.setWorkingDirectory(workingDirectory);
    PumpStreamHandler streamHandler = new PumpStreamHandler(stdout, stderr);
    exec.setStreamHandler(streamHandler);
    int exitCode;
    try {
      logger.atFine().log("%s", commandline);
      exitCode = exec.execute(commandline);
    } catch (ExecuteException e) {
      logger.atFine().log("error when running cmd %s", cmd);
      logger.atFine().log("cmd stdout: %s", stdout);
      logger.atFine().log("cmd stderr: %s", stderr);
      exitCode = e.getExitValue();
    } catch (IOException e) {
      logger.atSevere().withCause(e).log(
          "Fail to run command in the working directory:'%s', dir='%s'.", cmd, workingDirectory);
      throw new IOError(e);
    }
    return new CmdOutput(exitCode, stdout.toString(), stderr.toString());
  }

  public static final class CmdOutput {

    private final int exitCode;
    private final String stdout;
    private final String stderr;

    CmdOutput(int exitCode, String stdout, String stderr) {
      super();
      this.exitCode = exitCode;
      this.stdout = stdout;
      this.stderr = stderr;
    }

    public int getExitCode() {
      return exitCode;
    }

    public String getStdout() {
      return stdout;
    }

    public String getStderr() {
      return stderr;
    }

    @Override
    public String toString() {
      return MoreObjects.toStringHelper(this)
          .add("exitCode", exitCode)
          .add("stdout", stdout)
          .add("stderr", stderr)
          .toString();
    }
  }
}
