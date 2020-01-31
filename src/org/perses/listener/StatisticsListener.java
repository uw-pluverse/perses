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

import com.google.common.annotations.VisibleForTesting;
import com.google.common.collect.ImmutableList;
import org.perses.reduction.AbstractReductionEvent;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Optional;

import static com.google.common.base.Preconditions.checkArgument;

/** Collects the statistics of reduction. */
public class StatisticsListener extends DefaultReductionListener {

  private final ArrayList<ReductionIterationStatistics> iterations = new ArrayList<>();
  private final File resultFile;

  public StatisticsListener(File resultFile) {
    this.resultFile = resultFile.getAbsoluteFile();

    checkArgument(
        this.resultFile.getParentFile().exists(),
        "The folder of the result file does not exist. %s",
        this.resultFile.getParentFile());
  }

  @Override
  public void onFixpointIterationStart(AbstractReductionEvent.FixpointIterationStartEvent event) {
    final ReductionIterationStatistics newStat =
        new ReductionIterationStatistics(
            String.valueOf(event.getIteration()),
            event.getProgramSize(),
            event.getCurrentTimeMillis());
    iterations.add(newStat);
  }

  @Override
  public void onFixpointIterationEnd(AbstractReductionEvent.FixpointIterationEndEvent event) {
    assert !iterations.isEmpty() : "The iterations list is empty.";
    final ReductionIterationStatistics currrentStat = iterations.get(iterations.size() - 1);

    assert currrentStat.iteration.equals(String.valueOf(event.getIteration()))
        : "The current iteration statistics does not match the current iteration: iteration in stat="
            + currrentStat.iteration
            + ", current iteration="
            + event.getIteration();
    currrentStat.endTimeMillis = event.getCurrentTimeMillis();
    currrentStat.setAfterProgramSize(event.getProgramSize());
    currrentStat.setCountOfTestScriptExecutions(event.getCountOfTestScriptExecutions());
  }

  @Override
  public void onReductionEnd(AbstractReductionEvent.ReductionEndEvent event) {
    try (PrintWriter writer = new PrintWriter(resultFile, StandardCharsets.UTF_8.name())) {
      printHumanReadableResult(writer);
      writer.println();

      writer.printf("iterations=%d\n", iterations.size());
      for (ReductionIterationStatistics iteration : iterations) {
        writeProperty(
            writer, "program_size_before", iteration.iteration, iteration.beforeProgramSize);
        writeProperty(
            writer, "program_size_after", iteration.iteration, iteration.afterProgramSize);

        writeProperty(
            writer, "elapsed_time_millis", iteration.iteration, iteration.elapsedTimeMillis());
        writeProperty(
            writer,
            "count_test_script_executions",
            iteration.iteration,
            iteration.countOfTestScriptExecutions);
        writer.println();
      }
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
  }

  @VisibleForTesting
  File getResultFile() {
    return resultFile;
  }

  private static final ImmutableList<String> COLUMN_NAMES =
      ImmutableList.of(
          "iteration", "before_size", "after_size", "removed_tokens", "time(ms)", "queries");
  private static final String COLUMN_FORMAT =
      buildColumnFormat(
          COLUMN_NAMES.stream().mapToInt(String::length).max().getAsInt(), COLUMN_NAMES.size());

  private static void writeProperty(
      PrintWriter writer, String name, String iterationName, long value) {
    writer.printf("%s.%s=%d\n", name, iterationName, value);
  }

  private void printHumanReadableResult(PrintWriter writer) {
    printHeader(writer);
    for (ReductionIterationStatistics iteration : iterations) {
      printRow(
          writer,
          iteration.iteration,
          iteration.beforeProgramSize,
          iteration.afterProgramSize,
          iteration.elapsedTimeMillis(),
          iteration.countOfTestScriptExecutions);
    }
    final Optional<ReductionIterationStatistics> totalStatistics = computeTotal();
    totalStatistics.ifPresent(
        i ->
            printRow(
                writer,
                "total",
                i.beforeProgramSize,
                i.afterProgramSize,
                i.elapsedTimeMillis(),
                i.countOfTestScriptExecutions));
  }

  private Optional<ReductionIterationStatistics> computeTotal() {
    if (iterations.isEmpty()) {
      return Optional.empty();
    }
    final ReductionIterationStatistics first = iterations.get(0);
    final ReductionIterationStatistics last = iterations.get(iterations.size() - 1);
    final ReductionIterationStatistics result =
        new ReductionIterationStatistics("total", first.beforeProgramSize, first.startTimeMillis);
    result.setAfterProgramSize(last.afterProgramSize);
    result.setCountOfTestScriptExecutions(
        iterations.stream().mapToInt(stat -> stat.countOfTestScriptExecutions).sum());
    result.endTimeMillis = last.endTimeMillis;
    return Optional.of(result);
  }

  @VisibleForTesting
  Iterable<ReductionIterationStatistics> getIterations() {
    return iterations;
  }

  private static void printHeader(PrintWriter writer) {
    writer.printf(
        COLUMN_FORMAT,
        COLUMN_NAMES.get(0),
        COLUMN_NAMES.get(1),
        COLUMN_NAMES.get(2),
        COLUMN_NAMES.get(3),
        COLUMN_NAMES.get(4),
        COLUMN_NAMES.get(5));
  }

  private static void printRow(
      PrintWriter writer,
      String iteration,
      int beforeSize,
      int afterSize,
      long timeMillis,
      int queries) {
    writer.printf(
        COLUMN_FORMAT,
        iteration,
        Integer.toString(beforeSize),
        Integer.toString(afterSize),
        Integer.toString(beforeSize - afterSize),
        Long.toString(timeMillis),
        Integer.toString(queries));
  }

  private static String buildColumnFormat(int columnWidth, int columnCount) {
    assert columnWidth > 0;
    assert columnCount > 0;

    final StringBuilder builder = new StringBuilder();
    builder.append("# ");
    boolean isFirst = true;
    for (int i = 0; i < columnCount; ++i) {
      if (!isFirst) {
        builder.append("   ");
      } else {
        isFirst = false;
      }
      builder.append("%" + columnWidth + "s");
    }
    builder.append("\n");
    return builder.toString();
  }

  @VisibleForTesting
  static final class ReductionIterationStatistics {
    private final String iteration;
    private final int beforeProgramSize;
    private final long startTimeMillis;
    private long endTimeMillis;

    private int afterProgramSize = Integer.MIN_VALUE;
    private int countOfTestScriptExecutions = Integer.MIN_VALUE;

    private ReductionIterationStatistics(
        String iterationName, int beforeProgramSize, long startTime) {
      this.iteration = iterationName;
      this.beforeProgramSize = beforeProgramSize;
      this.startTimeMillis = startTime;
    }

    public final void setCountOfTestScriptExecutions(int countOfTestScriptExecutions) {
      assert this.countOfTestScriptExecutions == Integer.MIN_VALUE : "can only set once.";
      this.countOfTestScriptExecutions = countOfTestScriptExecutions;
    }

    public final void setAfterProgramSize(int afterProgramSize) {
      assert this.afterProgramSize == Integer.MIN_VALUE : "can only set once";
      this.afterProgramSize = afterProgramSize;
    }

    public final long elapsedTimeMillis() {
      return endTimeMillis - startTimeMillis;
    }
  }
}
