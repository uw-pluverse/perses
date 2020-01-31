package org.perses.listener;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.reduction.AbstractReductionEvent.FixpointIterationEndEvent;
import org.perses.reduction.AbstractReductionEvent.FixpointIterationStartEvent;
import org.perses.reduction.AbstractReductionEvent.ReductionEndEvent;
import org.perses.reduction.ReducerAnnotation;
import org.perses.reduction.reducer.PersesNodePrioritizedDfsReducer;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.Properties;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class StatisticsListenerTest {

  private StatisticsListener listener;
  private File resultFile;

  @Before
  public void setup() throws IOException {
    resultFile = File.createTempFile("reduction-statistics", ".txt");
    listener = new StatisticsListener(resultFile);
  }

  @Test
  public void test() throws IOException {
    final ReducerAnnotation reducer = PersesNodePrioritizedDfsReducer.META;

    listener.onFixpointIterationStart(new FixpointIterationStartEvent(300, 100, 1, reducer));

    final int firstTestExecutions = 100;
    listener.onFixpointIterationEnd(new FixpointIterationEndEvent(500, 50, 1, firstTestExecutions));

    listener.onFixpointIterationStart(new FixpointIterationStartEvent(500, 50, 2, reducer));

    final int secondTestExecutions = 150;
    listener.onFixpointIterationEnd(
        new FixpointIterationEndEvent(700, 25, 2, secondTestExecutions));

    final ReductionEndEvent endEvent =
        new ReductionEndEvent(1000, 25, firstTestExecutions + secondTestExecutions);
    listener.onReductionEnd(endEvent);

    try (BufferedReader reader =
        Files.newBufferedReader(resultFile.toPath(), StandardCharsets.UTF_8)) {
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
        com.google.common.io.Files.asCharSource(resultFile, StandardCharsets.UTF_8).read().trim();
    final String goldenFileContent =
        com.google.common.io.Files.asCharSource(
                new File("test/org/perses/listener/golden_statistics_listener_test.properties"),
                StandardCharsets.UTF_8)
            .read()
            .trim();
    assertThat(testFileContent).isEqualTo(goldenFileContent);
  }

  @Test
  public void testOnlyIllegalArgumentIsThrownInConstructor() {
    File file = new File("___this_fold_should_not_exit____");
    try {
      new StatisticsListener(file);
    } catch (NullPointerException e) {
      Assert.fail();
    } catch (IllegalArgumentException e) {
      // Swallow the exception.
    }
  }
}
