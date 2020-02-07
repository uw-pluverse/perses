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

import com.google.common.base.Stopwatch;
import com.google.common.io.MoreFiles;
import com.google.common.io.RecursiveDeleteOption;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.LanguageKind;
import org.perses.TestUtility;
import org.perses.grammar.AbstractParserFacade;
import org.perses.grammar.ParserFacadeFactory;
import org.perses.program.SourceFile;
import org.perses.program.TokenizedProgram;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

import static com.google.common.truth.Truth.assertThat;

/** Test for {@link TestScriptExecutorService} */
@RunWith(JUnit4.class)
public class TestScriptExecutorServiceTest {

  private static final String FOLDER = "test_data/delta_1/";
  private File sourceFile;
  private File invalidSourceFile;
  private File testScript;
  private TokenizedProgram program;
  private File workingDirectory;

  @Before
  public void setup() throws IOException {
    workingDirectory = TestUtility.createCleanWorkingDirectory(TestScriptExecutorServiceTest.class);
    sourceFile = new File(FOLDER + "t.c");
    testScript = new File(FOLDER + "r.sh");
    invalidSourceFile = new File("test_data/misc/t1.c");
    program = TestUtility.createSparTreeFromFile(sourceFile).getProgramSnapshot();
  }

  @After
  public void teardown() throws IOException {
    MoreFiles.deleteRecursively(workingDirectory.toPath(), RecursiveDeleteOption.ALLOW_INSECURE);
  }

  @Test
  public void testThreadCount_1() throws InterruptedException, ExecutionException, IOException {
    testTestScriptExecutor(1);
  }

  @Test
  public void testThreadCount_4() throws InterruptedException, ExecutionException, IOException {
    testTestScriptExecutor(4);
  }

  @Test
  public void testThreadCount_10() throws InterruptedException, ExecutionException, IOException {
    testTestScriptExecutor(10);
  }

  private ReductionConfiguration createConfiguration(int threadCount) {
    return new ReductionConfiguration(
        workingDirectory,
        testScript,
        sourceFile,
        sourceFile,
        null,
        null,
        true,
        true,
        true,
        false,
        100,
        threadCount,
        TestUtility.PURE_PERSES_MULTI_NODE_PARTITION_REDUCTION_POLICY,
        TestUtility.PURE_PERSES_SINGLE_NODE_PARTITION_REDUCTION_POLICY);
  }

  private void testTestScriptExecutor(int threadCount) throws IOException {
    final AbstractParserFacade facade =
        ParserFacadeFactory.SINGLETON.createParserFacade(LanguageKind.C);
    Stopwatch stopwatch = Stopwatch.createStarted();
    final ReductionConfiguration configuration = createConfiguration(threadCount);
    final TestScriptExecutorService service =
        new TestScriptExecutorService(
            configuration.getTempRootFolder(),
            configuration.getNumOfReductionThreads(),
            SourceFile.createFromPath(testScript),
            sourceFile.getName());
    assertThat(configuration.getNumOfReductionThreads()).isEqualTo(threadCount);
    // TODO: refine this test.
    {
      final List<Future<TestScript.TestResult>> futureList = new ArrayList<>();
      for (int i = 0; i < 50; ++i) {
        futureList.add(service.testProgram(program, true));
      }
      futureList.forEach(
          future -> {
            try {
              assertThat(future.get().isPass()).isTrue();
            } catch (Throwable e) {
              throw new AssertionError(e);
            }
          });
    }
    {
      final TokenizedProgram invalidProgram =
          TestUtility.createSparTreeFromFile(invalidSourceFile).getProgramSnapshot();
      final List<Future<TestScript.TestResult>> futureList = new ArrayList<>();
      for (int i = 0; i < 50; ++i) {
        futureList.add(service.testProgram(invalidProgram, true));
      }
      futureList.forEach(
          future -> {
            try {
              assertThat(future.get().isPass()).isFalse();
            } catch (Throwable e) {
              throw new AssertionError(e);
            }
          });
    }
    stopwatch.stop();
    System.out.println(
        "#threads=" + threadCount + ": time=" + stopwatch.elapsed(TimeUnit.SECONDS) + " seconds");
  }
}
