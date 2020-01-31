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

import com.google.common.io.MoreFiles;
import com.google.common.io.RecursiveDeleteOption;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.time.LocalDateTime;

import static com.google.common.truth.Truth.assertThat;

/** Test for {@link ReductionConfiguration} */
@RunWith(JUnit4.class)
public class ReductionConfigurationTest {

  private static final String FOLDER = "test_data/delta_1/";
  private final File testScript = new File(FOLDER + "r.sh");
  private File workingDirectory;
  private File sourceFile = new File(FOLDER + "t.c");

  @Before
  public void setup() throws IOException {
    workingDirectory = TestUtility.createCleanWorkingDirectory(ReductionConfigurationTest.class);
  }

  @After
  public void teardown() throws IOException {
    MoreFiles.deleteRecursively(workingDirectory.toPath(), RecursiveDeleteOption.ALLOW_INSECURE);
  }

  @Test
  public void testConfiguration() throws IOException {
    assertThat(workingDirectory.isDirectory()).isTrue();
    final File bestFile = sourceFile;
    final int numOfReductionThreads = 2;
    final int maxReductionLevel = 100;
    final ReductionConfiguration configuration =
        new ReductionConfiguration(
            workingDirectory,
            testScript,
            sourceFile,
            bestFile,
            null,
            null,
            true,
            true,
            true,
            false,
            false,
            maxReductionLevel,
            numOfReductionThreads,
            TestUtility.PURE_PERSES_MULTI_NODE_PARTITION_REDUCTION_POLICY,
            TestUtility.PURE_PERSES_SINGLE_NODE_PARTITION_REDUCTION_POLICY);
    assertThat(configuration.getBestResultFile()).isEqualTo(bestFile);
    assertThat(configuration.getFileToReduce().getFile()).isEqualTo(sourceFile);
    assertThat(configuration.getFileToReduce().getFileContent())
        .isEqualTo(MoreFiles.asCharSource(sourceFile.toPath(), StandardCharsets.UTF_8).read());
    assertThat(configuration.getMaxReductionLevel()).isEqualTo(maxReductionLevel);
    assertThat(configuration.getNumOfReductionThreads()).isEqualTo(numOfReductionThreads);
    assertThat(configuration.getWorkingFolder()).isEqualTo(workingDirectory);
    {
      final File tempRootFolder = configuration.getTempRootFolder();
      assertThat(tempRootFolder.getParentFile()).isEqualTo(workingDirectory);
      assertThat(tempRootFolder.getName()).startsWith("PersesTempRoot_t.c_r.sh_");
    }
    assertThat(configuration.isFixpointReduction()).isTrue();
  }

  @Test
  public void testGetTempRootFolderName() {
    final LocalDateTime time = LocalDateTime.of(2000, 1, 21, 1, 2, 3);
    assertThat(ReductionConfiguration.getTempRootFolderName("t.c", "r.sh", time))
        .isEqualTo("PersesTempRoot_t.c_r.sh_20000121_010203");
  }
}
