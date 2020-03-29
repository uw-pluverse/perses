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

import com.google.common.base.Charsets;
import com.google.common.io.Files;
import com.google.common.truth.Truth;
import org.antlr.runtime.RecognitionException;
import org.perses.CommandOptions;
import org.perses.listener.ProgressMonitorForNodeReducer;
import org.perses.util.AutoDeletableFolder;

import java.io.File;
import java.io.IOException;
import java.util.concurrent.ExecutionException;

/** The base class for testing the functionality of reducers. */
public abstract class AbstractReducerFunctionalTest {

  protected void test(
      String reductionFolder,
      String testScript,
      String sourceFile,
      ReducerAnnotation algorithmType,
      String expected) {
    try (AutoDeletableFolder folder = new AutoDeletableFolder(Files.createTempDir())) {
      CommandOptions cmd = new CommandOptions("");
      File tempSourceFile = new File(folder.toFile(), sourceFile);
      Files.copy(new File(reductionFolder, sourceFile), tempSourceFile);
      File tempTestScript = new File(folder.toFile(), testScript);
      Files.copy(new File(reductionFolder, testScript), tempTestScript);
      cmd.compulsoryFlags.inputFile = tempSourceFile.getAbsolutePath();
      cmd.compulsoryFlags.testScript = tempTestScript.getAbsolutePath();
      cmd.reductionControlFlags.fixpoint = true;
      cmd.reductionAlgorithm = algorithmType.shortName();
      cmd.resultOutputFlags.inPlaceReduction = false;

      ProgressMonitorForNodeReducer progressMonitor =
          ProgressMonitorForNodeReducer.createForSystemOut();
      try (ReductionDriver driver = new ReductionDriver(cmd, progressMonitor)) {
        final File bestFile = driver.getConfiguration().getBestResultFile();
        if (bestFile.isFile()) {
          bestFile.delete();
        }
        driver.reduce();
        Truth.assertWithMessage("reduction folder=%s, algorith=%s", reductionFolder, algorithmType)
            .that(Files.asCharSource(bestFile, Charsets.UTF_8).read().replaceAll("\\s+", ""))
            .isEqualTo(expected.replaceAll("\\s+", ""));
      }
    } catch (RuntimeException | Error e) {
      throw e;
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  protected void runBenchmarkSubject(
      String reductionFolder, ReducerAnnotation algorithmType, String expected)
      throws InterruptedException, ExecutionException, RecognitionException, IOException {
    test(reductionFolder, "r.sh", "small.c", algorithmType, expected);
  }

  protected void runCTestSubject(
      String reductionFolder, ReducerAnnotation algorithmType, String expected) {
    test(reductionFolder, "r.sh", "t.c", algorithmType, expected);
  }

  protected void runJavaTestSubject(
      String reductionFolder, ReducerAnnotation algorithmType, String expected)
      throws IOException, RecognitionException, ExecutionException, InterruptedException {
    test(reductionFolder, "r.sh", "t.java", algorithmType, expected);
  }
}
