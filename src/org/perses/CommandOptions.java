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

package org.perses;

import com.beust.jcommander.JCommander;
import com.beust.jcommander.Parameter;
import com.google.common.base.Preconditions;
import com.google.common.base.Strings;
import org.perses.util.Fraction;

import java.io.File;

import static com.google.common.base.Preconditions.checkNotNull;
import static com.google.common.base.Preconditions.checkState;

/** Parser for command line arguments. */
public class CommandOptions {

  private final String defaultReductionAlgorithm;
  public final CompulsoryFlags compulsoryFlags = new CompulsoryFlags();
  public final ResultOutputFlags resultOutputFlags = new ResultOutputFlags();
  public final ReductionControlFlags reductionControlFlags = new ReductionControlFlags();

  @Parameter(names = "--help", description = "print help message", help = true)
  public boolean help;

  @Parameter(names = "--count-tokens", description = "Count tokens in the input file")
  public boolean countTokens;

  @Parameter(
      names = "--profile",
      description = "profile the reduction process for analysis",
      arity = 1)
  public boolean profile = false;

  @Parameter(names = "--debug-granularity", description = "debug granularity", arity = 1)
  public boolean debugGranularity = false;

  @Parameter(
      names = "--alg",
      description = "reduction algorithm: use --list-algs to list all available algorithms")
  public String reductionAlgorithm = null;

  @Parameter(names = "--list-algs", description = "list all the reduction algorithms.", help = true)
  public boolean listAllReductionAlgorithms;

  @Parameter(names = "--format-cmd", description = "the command to format the reduced source file")
  public String formatCmd = "";

  @Parameter(names = "--max-level", description = "the max levels in the tree for reduction")
  public int maxReductionLevel = Integer.MAX_VALUE;

  @Parameter(
      names = "--query-caching",
      description = "Enable query caching for test script executions.",
      arity = 1)
  public boolean queryCaching = false;

  @Parameter(
      names = "--edit-caching",
      description = "Enable caching for edits performed between two successful reductions.",
      arity = 1)
  public boolean nodeActionSetCaching = true;

  @Parameter(
      names = "--progress-dump-file",
      description = "The file to record the reduction process. The dump file can be large..")
  public String progressDumpFile;

  @Parameter(
      names = "--stat-dump-file",
      description = "The file to save the statistics collected during reduction.")
  public String statDumpFile;

  @Parameter(
      names = "--reparse-each-iteration",
      description = "Reparse the program before the start of each fixpoint iteration.")
  public boolean rebuildParseTreeEachIteration = true;

  @Parameter(
      names = "--profile-query-cache",
      description = "The file to save the profiling data of the query cache.")
  public String profileTestExecutionCache = null;

  @Parameter(
      names = "--profile-actionset",
      description = "The file to save information of all the created edit action sets.")
  public String actionSetProfiler = null;

  @Parameter(
      names = "--use-real-ddmin",
      description = "Whether to use the real delta debugging algorithm to reduce kleene nodes.",
      arity = 1)
  public boolean useRealDeltaDebugger = false;

  @Parameter(
      names = "--query-cache-refresh-threshold",
      description =
          "When to trigger a refresh of the query cache. "
              + "The value is is a fraction in the format x/y. "
              + "Assume the original token count is t. "
              + "Since last refresh where the best program has t' tokens, if the latest best program has b tokens, "
              + "and (t' - b) >= t *x/y, then a refresh is triggered.")
  public String queryCacheRefreshThreshold = "100/1";

  @Parameter(
      names = "--use-optc-parser",
      description = "Use the OptC parser to construct the spar-tree.",
      arity = 1)
  public boolean useOptCParser = false;

  public CommandOptions(String defaultReductionAlgorithm) {
    this.defaultReductionAlgorithm = defaultReductionAlgorithm;
  }

  public String getFormatCmd() {
    return formatCmd;
  }

  public String getReductionAlgorithmName() {
    if (Strings.isNullOrEmpty(reductionAlgorithm)) {
      reductionAlgorithm = defaultReductionAlgorithm;
    }
    return this.reductionAlgorithm;
  }

  public Fraction getQueryCacheRefreshThreshold() {
    return Fraction.parse(queryCacheRefreshThreshold);
  }

  public int getMaxReductionLevel() {
    return maxReductionLevel;
  }

  public void setDebugGranularity(boolean debugGranularity) {
    this.debugGranularity = debugGranularity;
  }

  public JCommander createJCommander(Class<?> mainClass) {
    final JCommander commander =
        JCommander.newBuilder()
            .programName(mainClass.getCanonicalName())
            .addObject(this)
            .addObject(compulsoryFlags)
            .addObject(resultOutputFlags)
            .addObject(reductionControlFlags)
            .build();
    return commander;
  }

  public void validate() {
    compulsoryFlags.validate();
    resultOutputFlags.validate();
    reductionControlFlags.validate();
    if (queryCacheRefreshThreshold != null) {
      Fraction.parse(queryCacheRefreshThreshold); // Should not throw exceptions.
    }
  }

  public static final class ResultOutputFlags {
    @Parameter(
        names = "--in-place",
        description = "perform in-place reduction",
        arity = 1,
        order = FlagOrder.RESULT_OUTPUT)
    public boolean inPlaceReduction = false;

    @Parameter(
        names = "--output-file",
        description = "The output file to save the reduced result.",
        order = FlagOrder.RESULT_OUTPUT)
    public String outputFile;

    public void validate() {
      if (inPlaceReduction) {
        checkState(
            outputFile == null || outputFile.trim().isEmpty(),
            "--in-place and --output-file cannot be specified together.");
      }
    }
  }

  public static final class ReductionControlFlags {
    @Parameter(
        names = "--fixpoint",
        description = "iterative reduction till fixpoint",
        arity = 1,
        order = FlagOrder.REDUCTION_CONTROL)
    public boolean fixpoint = true;

    @Parameter(
        names = "--keep-orig-format",
        description = "keep the original code format during reduction. May slow down if enabled.",
        arity = 1,
        order = FlagOrder.REDUCTION_CONTROL)
    public boolean keepOrigFormat = true;

    @Parameter(
        names = "--threads",
        description = "Number of reduction threads: a positive integer, or 'auto'.",
        order = FlagOrder.REDUCTION_CONTROL)
    private String numOfThreads = "auto";

    public void validate() {
      if (!"auto".equals(numOfThreads)) {
        checkState(Integer.parseInt(numOfThreads) > 0, numOfThreads);
      }
    }

    public int getNumOfThreads() {
      if ("auto".equals(numOfThreads)) {
        return Runtime.getRuntime().availableProcessors();
      }
      return Integer.parseInt(numOfThreads);
    }
  }

  public static final class CompulsoryFlags {

    @Parameter(
        names = "--test-script",
        required = true,
        description = "The test script to specify the property the reducer needs to preserve.",
        order = FlagOrder.COMPULSORY)
    public String testScript;

    @Parameter(
        names = "--input-file",
        required = true,
        description = "The input file to reduce",
        order = FlagOrder.COMPULSORY)
    public String inputFile;

    public File getTestScript() {
      return new File(checkNotNull(testScript));
    }

    public File getSourceFile() {
      return new File(Preconditions.checkNotNull(inputFile));
    }

    public void validate() {
      final File testScript = this.getTestScript();
      checkState(testScript.isFile(), "The test script %s is not a file.", testScript);
      checkState(testScript.canExecute(), "The test script %s is not executable.", testScript);

      final File sourceFile = this.getSourceFile();
      checkState(sourceFile.isFile(), "The source program %s is not a file.", sourceFile);
    }
  }

  private static class FlagOrder {
    public static final int COMPULSORY = 0;
    public static final int RESULT_OUTPUT = 100;
    public static final int REDUCTION_CONTROL = 200;
  }
}
