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
package org.perses.listener;

import com.google.common.base.Strings;
import org.perses.program.TokenizedProgram;
import org.perses.reduction.AbstractReductionEvent;
import org.perses.reduction.TestScript;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;

import static com.google.common.base.Preconditions.checkArgument;

/** Records the test script executions. */
public class TestScriptExecutionListener extends DefaultReductionListener {

  private final ArrayList<ExecutionStatistics> statisticsList = new ArrayList<>(2000);
  private final File summaryFile;

  public TestScriptExecutionListener(File summaryFile) {
    this.summaryFile = summaryFile.getAbsoluteFile();
    checkArgument(
        this.summaryFile.getParentFile().exists(),
        "The folder of the file %s does not exist.",
        summaryFile);
  }

  private static void printStatistics(PrintStream stream, Object... values) {
    boolean isFirst = true;
    for (Object value : values) {
      if (isFirst) {
        isFirst = false;
      } else {
        stream.printf(" \t ");
      }
      stream.print(Strings.padStart(value.toString(), 15, ' '));
    }
    stream.print('\n');
  }

  @Override
  public void onTestScriptExecution(AbstractReductionEvent.TestScriptExecutionEvent event) {
    final TestScript.TestResult result = event.getResult();
    final TokenizedProgram program = event.getProgram();
    statisticsList.add(
        new ExecutionStatistics(
            result.getElapsedMilliseconds(), result.isPass(), program.tokenCount()));
  }

  @Override
  public void onReductionEnd(AbstractReductionEvent.ReductionEndEvent event) {
    try {
      int passCount = 0;
      int passTime = 0;
      int failCount = 0;
      int failTime = 0;
      for (ExecutionStatistics executionStatistics : statisticsList) {
        if (executionStatistics.result) {
          ++passCount;
          passTime += executionStatistics.milliSeconds;
        } else {
          ++failCount;
          failTime += executionStatistics.milliSeconds;
        }
      }
      try (PrintStream stream = new PrintStream(summaryFile)) {
        stream.print("# summary of test script executions.\n");
        stream.printf("pass_count=%d\n", passCount);
        stream.printf("pass_total_time=%d\n", passTime);
        stream.printf("fail_count=%d\n", failCount);
        stream.printf("fail_total_time=%d\n", failTime);

        stream.print("\n\n\n===Details===\n");
        printStatistics(stream, "Time", "Result", "Size");
        statisticsList.stream()
            .filter(e -> e.result)
            .forEach(
                statistics ->
                    printStatistics(
                        stream,
                        statistics.milliSeconds,
                        statistics.result,
                        statistics.programSize));
        statisticsList.stream()
            .filter(e -> !e.result)
            .forEach(
                statistics ->
                    printStatistics(
                        stream,
                        statistics.milliSeconds,
                        statistics.result,
                        statistics.programSize));
      }
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
  }

  private static final class ExecutionStatistics {

    private final long milliSeconds;
    private final boolean result;
    private final int programSize;

    private ExecutionStatistics(long milliSeconds, boolean result, int programSize) {
      this.milliSeconds = milliSeconds;
      this.result = result;
      this.programSize = programSize;
    }
  }
}
