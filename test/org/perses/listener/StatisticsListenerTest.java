/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import static com.google.common.truth.Truth.assertThat;

import java.io.BufferedReader;
import java.io.IOException;
import java.lang.ref.WeakReference;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Properties;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.reduction.ReducerAnnotation;
import org.perses.reduction.event.FixpointIterationEndEvent;
import org.perses.reduction.event.FixpointIterationStartEvent;
import org.perses.reduction.event.ReductionEndEvent;
import org.perses.reduction.event.ReductionStartEvent;
import org.perses.reduction.reducer.PersesNodePrioritizedDfsReducer;
import org.perses.spartree.AbstractUnmodifiableSparTree;

@RunWith(JUnit4.class)
public class StatisticsListenerTest {

  private StatisticsListener listener;
  private Path resultFile;

  @Before
  public void setup() throws IOException {
    resultFile = Files.createTempFile("reduction-statistics", ".txt");
    listener = new StatisticsListener(resultFile);
  }

  @Test
  public void test() throws IOException {
    final ReducerAnnotation reducer = PersesNodePrioritizedDfsReducer.META;

    final ReductionStartEvent startEvent =
        new ReductionStartEvent(300, new WeakReference<AbstractUnmodifiableSparTree>(null), 100);
    FixpointIterationStartEvent event =
        new FixpointIterationStartEvent(startEvent, 300, 100, 1, reducer);
    FixpointIterationStartEvent firstIterationStart =
        new FixpointIterationStartEvent(startEvent, 300, 100, 1, reducer);
    listener.onFixpointIterationStart(firstIterationStart);

    final int firstTestExecutions = 100;
    listener.onFixpointIterationEnd(
        new FixpointIterationEndEvent(firstIterationStart, 500, 50, firstTestExecutions));

    FixpointIterationStartEvent secondIterationStart =
        new FixpointIterationStartEvent(startEvent, 500, 50, 2, reducer);
    listener.onFixpointIterationStart(secondIterationStart);

    final int secondTestExecutions = 150;
    listener.onFixpointIterationEnd(
        new FixpointIterationEndEvent(secondIterationStart, 700, 25, secondTestExecutions));

    final ReductionEndEvent endEvent =
        new ReductionEndEvent(startEvent, 1000, 25, firstTestExecutions + secondTestExecutions);
    listener.onReductionEnd(endEvent);

    try (BufferedReader reader = Files.newBufferedReader(resultFile, StandardCharsets.UTF_8)) {
      Properties p = new Properties();
      p.load(reader);
      assertThat(p.getProperty("iterations")).isEqualTo("2");

      assertThat(p.getProperty("program_size_before.1")).isEqualTo("100");
      assertThat(p.getProperty("program_size_after.1")).isEqualTo("50");
      assertThat(p.getProperty("count_test_script_executions.1")).isEqualTo("100");
      assertThat(p.getProperty("elapsed_time_millis.1")).isEqualTo("200");

      assertThat(p.getProperty("program_size_before.2")).isEqualTo("50");
      assertThat(p.getProperty("program_size_after.2")).isEqualTo("25");
      assertThat(p.getProperty("count_test_script_executions.2")).isEqualTo("150");
      assertThat(p.getProperty("elapsed_time_millis.2")).isEqualTo("200");
    }
    final String testFileContent =
        com.google.common.io.Files.asCharSource(resultFile.toFile(), StandardCharsets.UTF_8)
            .read()
            .trim();
    final String goldenFileContent =
        com.google.common.io.Files.asCharSource(
                Paths.get("test/org/perses/listener/golden_statistics_listener_test.properties")
                    .toFile(),
                StandardCharsets.UTF_8)
            .read()
            .trim();
    assertThat(testFileContent).isEqualTo(goldenFileContent);
  }

  @Test
  public void testOnlyIllegalArgumentIsThrownInConstructor() {
    Path file = Paths.get("___this_fold_should_not_exit____");
    try {
      new StatisticsListener(file);
    } catch (NullPointerException e) {
      Assert.fail();
    } catch (IllegalArgumentException e) {
      // Swallow the exception.
    }
  }
}
