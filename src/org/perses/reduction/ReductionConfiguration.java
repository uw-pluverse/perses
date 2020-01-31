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

import com.google.common.annotations.VisibleForTesting;
import com.google.common.base.Joiner;
import org.checkerframework.checker.nullness.qual.Nullable;
import org.perses.grammar.AbstractParserFacade;
import org.perses.grammar.ParserFacadeFactory;
import org.perses.program.SourceFile;
import org.perses.util.Util;

import java.io.File;
import java.lang.reflect.Field;
import java.time.LocalDateTime;
import java.util.Optional;

import static com.google.common.base.Preconditions.*;

/**
 * This is the internal configuration for Perses reducer.
 *
 * <p>TODO: refactor this to a AutoValue class, or use the BUILDER pattern.
 */
public final class ReductionConfiguration {

  private static final String PERSES_TEMP_ROOT_PREFIX = "PersesTempRoot";
  /** The working directory of the reduction. */
  private final File workingFolder;
  /** The test script for reduction */
  private final SourceFile testScript;
  /** The file to reduce */
  private final SourceFile fileToReduce;
  /** The parser facade. */
  private final AbstractParserFacade parserFacade;

  private final boolean keepOriginalCodeFormat;
  private final boolean fixpointReduction;
  private final boolean enableTestScriptExecutionCaching;
  private final boolean useRealDeltaDebugger;
  private final boolean refreshQueryCache;
  private final int maxReductionLevel;
  /** This file is used to store the best result of reduction. */
  private final File bestResultFile;

  private final File tempRootFolder;
  @Nullable private final File statisticsFile;
  @Nullable private final File progressDumpFile;
  private final int numberOfThreads;

  private final IPartitionReductionPolicy.MultiNodePartitionReductionPolicy
      multiNodePartitionReductionPolicy;
  private final IPartitionReductionPolicy.SingleNodePartitionReductionPolicy
      singleNodePartitionReductionPolicy;

  public ReductionConfiguration(
      final File workingFolder,
      final File testScriptFile,
      final File fileToReduce,
      final File bestResultFile,
      @Nullable final File statisticsFile,
      @Nullable final File progressDumpFile,
      final boolean keepOriginalCodeFormat,
      final boolean fixpointReduction,
      final boolean enableTestScriptExecutionCaching,
      final boolean useRealDeltaDebugger,
      final boolean refreshQueryCache,
      final int maxReductionLevel,
      final int numOfReductionThreads,
      IPartitionReductionPolicy.MultiNodePartitionReductionPolicy multiNodePartitionReductionPolicy,
      IPartitionReductionPolicy.SingleNodePartitionReductionPolicy
          singleNodePartitionReductionPolicy) {
    this.workingFolder = workingFolder;
    this.testScript = SourceFile.createFromPath(testScriptFile);
    this.fileToReduce = SourceFile.createFromPath(fileToReduce);
    this.parserFacade =
        ParserFacadeFactory.SINGLETON.createParserFacade(this.fileToReduce.getLanguageKind());

    this.bestResultFile = bestResultFile;
    this.statisticsFile = statisticsFile;

    this.keepOriginalCodeFormat = keepOriginalCodeFormat;
    this.fixpointReduction = fixpointReduction;
    this.enableTestScriptExecutionCaching = enableTestScriptExecutionCaching;
    this.useRealDeltaDebugger = useRealDeltaDebugger;
    this.refreshQueryCache = refreshQueryCache;

    this.maxReductionLevel = maxReductionLevel;
    this.multiNodePartitionReductionPolicy = checkNotNull(multiNodePartitionReductionPolicy);
    this.singleNodePartitionReductionPolicy = checkNotNull(singleNodePartitionReductionPolicy);
    checkArgument(
        this.workingFolder.isDirectory(),
        "The working folder is not a directory: %s.",
        this.workingFolder);
    checkArgument(numOfReductionThreads > 0, "The number of reduction threads must be positive.");
    this.numberOfThreads = numOfReductionThreads;
    tempRootFolder =
        new File(
            workingFolder,
            getTempRootFolderName(
                fileToReduce.getName(), testScriptFile.getName(), LocalDateTime.now()));
    this.progressDumpFile = progressDumpFile;
    validateConfiguration();
  }

  public void validateConfiguration() {
    checkState(workingFolder.exists(), "The working directory %s does not exist.", workingFolder);
    checkState(
        workingFolder.isDirectory(), "The working directory %s is not a directory", workingFolder);
    checkState(
        maxReductionLevel > 0, "The max reduction level should be positive: %s", maxReductionLevel);
    checkNotNull(multiNodePartitionReductionPolicy);
    checkNotNull(singleNodePartitionReductionPolicy);
  }

  public boolean isKeepOriginalCodeFormat() {
    return keepOriginalCodeFormat;
  }

  public IPartitionReductionPolicy.MultiNodePartitionReductionPolicy
      getMultiNodePartitionReductionPolicy() {
    return multiNodePartitionReductionPolicy;
  }

  public IPartitionReductionPolicy.SingleNodePartitionReductionPolicy
      getSingleNodePartitionReductionPolicy() {
    return singleNodePartitionReductionPolicy;
  }

  public int getNumOfReductionThreads() {
    return this.numberOfThreads;
  }

  public File getTempRootFolder() {
    return tempRootFolder;
  }

  public Optional<File> getStatisticsFile() {
    return Optional.ofNullable(statisticsFile);
  }

  public Optional<File> getProgressDumpFile() {
    return Optional.ofNullable(progressDumpFile);
  }

  public Optional<File> getTestScriptStatisticsFile() {
    if (statisticsFile == null) {
      return Optional.empty();
    }
    return Optional.of(
        new File(statisticsFile.getParentFile(), "testscript-" + statisticsFile.getName()));
  }

  public File getWorkingFolder() {
    return workingFolder;
  }

  public SourceFile getTestScript() {
    return testScript;
  }

  public SourceFile getFileToReduce() {
    return fileToReduce;
  }

  public boolean isFixpointReduction() {
    return fixpointReduction;
  }

  public int getMaxReductionLevel() {
    return maxReductionLevel;
  }

  public boolean isUseRealDeltaDebugger() {
    return useRealDeltaDebugger;
  }

  public File getFixpointIterationResultFile(int fixpointIteration) {
    final File bestResultFile = getBestResultFile();
    return new File(
        getTempRootFolder(), bestResultFile.getName() + "_fixpoint_iteration_" + fixpointIteration);
  }

  public File getBestResultFile() {
    return bestResultFile;
  }

  public boolean isRefreshQueryCache() {
    return refreshQueryCache;
  }

  public String dumpConfiguration() {
    final StringBuilder builder = new StringBuilder();
    try {
      for (Field field : ReductionConfiguration.class.getDeclaredFields()) {
        builder.append(field.getName()).append('=').append(field.get(this)).append('\n');
      }
    } catch (IllegalAccessException e) {
      throw new AssertionError(e);
    }
    return builder.toString();
  }

  public boolean isEnableTestScriptExecutionCaching() {
    return enableTestScriptExecutionCaching;
  }

  public AbstractParserFacade getParserFacade() {
    return parserFacade;
  }

  @VisibleForTesting
  static String getTempRootFolderName(
      String fileNameForReduction, String testScriptName, LocalDateTime time) {
    return Joiner.on('_')
        .join(
            PERSES_TEMP_ROOT_PREFIX,
            fileNameForReduction,
            testScriptName,
            Util.formatDateForFileName(time));
  }
}
