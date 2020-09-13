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
package org.perses.reduction;

import com.google.common.base.Charsets;
import com.google.common.io.Files;
import com.google.common.truth.Truth;
import org.perses.CommandOptions;
import org.perses.grammar.ParserFacadeFactory;
import org.perses.listener.ProgressMonitorForNodeReducer;
import org.perses.util.AutoDeletableFolder;

import java.io.File;
import java.util.function.Consumer;

/** The base class for testing the functionality of reducers. */
public abstract class AbstractReducerFunctionalTest {

  protected void test(
      String reductionFolder,
      String testScript,
      String sourceFile,
      ReducerAnnotation algorithmType,
      Consumer<CommandOptions> cmdCustomizer,
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
      cmd.algorithmControlFlags.reductionAlgorithm = algorithmType.shortName();
      cmd.resultOutputFlags.inPlaceReduction = false;

      cmdCustomizer.accept(cmd);

      ProgressMonitorForNodeReducer progressMonitor =
          ProgressMonitorForNodeReducer.createForSystemOut();
      try (ReductionDriver driver =
          new ReductionDriver(
              cmd, ParserFacadeFactory.builderWithBuiltinLanguages().build(), progressMonitor)) {
        final File bestFile = driver.getConfiguration().getBestResultFile();
        if (bestFile.isFile()) {
          bestFile.delete();
        }
        driver.reduce();
        Truth.assertWithMessage("reduction folder=%s, algorith=%s", reductionFolder, algorithmType)
            .that(Files.asCharSource(bestFile, Charsets.UTF_8).read().replaceAll("\\s+", ""))
            .isEqualTo(expected.replaceAll("\\s+", ""));
      }
    } catch (Throwable e) {
      throw new RuntimeException(e);
    }
  }

  protected void runBenchmarkSubject(
      String reductionFolder,
      ReducerAnnotation algorithmType,
      Consumer<CommandOptions> cmdCustomizer,
      String expected) {
    test(reductionFolder, "r.sh", "small.c", algorithmType, cmdCustomizer, expected);
  }

  protected void runCTestSubject(
      String reductionFolder, ReducerAnnotation algorithmType, String expected) {
    runCTestSubject(reductionFolder, algorithmType, t -> {}, expected);
  }

  protected void runCTestSubject(
      String reductionFolder,
      ReducerAnnotation algorithmType,
      Consumer<CommandOptions> cmdCustomizer,
      String expected) {
    test(reductionFolder, "r.sh", "t.c", algorithmType, cmdCustomizer, expected);
  }

  protected void runJavaTestSubject(
      String reductionFolder, ReducerAnnotation algorithmType, String expected) {
    test(reductionFolder, "r.sh", "t.java", algorithmType, t -> {}, expected);
  }

  protected void runScalaTestSubject(
      String reductionFolder, ReducerAnnotation algorithmType, String expected) {
    test(reductionFolder, "r.sh", "t.sc", algorithmType, t -> {}, expected);
  }
}
