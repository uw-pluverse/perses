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

package org.perses;

import com.beust.jcommander.JCommander;
import com.beust.jcommander.Parameter;
import com.google.common.base.Preconditions;
import com.google.common.base.Strings;
import com.google.common.collect.ImmutableList;
import org.perses.program.EnumFormatControl;
import org.perses.util.AbstractCommandOptions;
import org.perses.util.Fraction;
import org.perses.util.ICommandLineFlags;
import org.perses.util.Shell;

import java.io.File;

import static com.google.common.base.Preconditions.checkNotNull;
import static com.google.common.base.Preconditions.checkState;

/** Parser for command line arguments. */
public class CommandOptions extends AbstractCommandOptions {

  private final String defaultReductionAlgorithm;

  public final CompulsoryFlags compulsoryFlags = registerFlags(new CompulsoryFlags());
  public final ResultOutputFlags resultOutputFlags = registerFlags(new ResultOutputFlags());
  public final ReductionControlFlags reductionControlFlags =
      registerFlags(new ReductionControlFlags());
  public final OutputRefiningFlags outputRefiningFlags = registerFlags(new OutputRefiningFlags());
  public final ReductionAlgorithmControlFlags algorithmControlFlags =
      registerFlags(new ReductionAlgorithmControlFlags());
  public final CacheControlFlags cacheControlFlags = registerFlags(new CacheControlFlags());
  public final ProfilingFlags profilingFlags = registerFlags(new ProfilingFlags());
  public final VerbosityFlags verbosityFlags = registerFlags(new VerbosityFlags());

  private final ImmutableList<ICommandLineFlags> allFlags =
      ImmutableList.<ICommandLineFlags>builder()
          .add(compulsoryFlags)
          .add(resultOutputFlags)
          .add(reductionControlFlags)
          .add(outputRefiningFlags)
          .add(algorithmControlFlags)
          .add(cacheControlFlags)
          .add(profilingFlags)
          .add(verbosityFlags)
          .build();

  @Parameter(
      names = {"--help", "-h"},
      description = "print help message",
      help = true,
      order = FlagOrder.HELP)
  public boolean help;

  public CommandOptions(String defaultReductionAlgorithm) {
    this.defaultReductionAlgorithm = defaultReductionAlgorithm;
  }

  public JCommander createJCommander(Class<?> mainClass) {
    JCommander.Builder builder =
        JCommander.newBuilder().programName(mainClass.getCanonicalName()).addObject(this);
    allFlags.forEach(builder::addObject);
    return builder.build();
  }

  public static final class CompulsoryFlags implements ICommandLineFlags {

    @Parameter(
        names = "--test-script",
        required = true,
        description = "The test script to specify the property the reducer needs to preserve.",
        order = FlagOrder.COMPULSORY + 0)
    public String testScript;

    @Parameter(
        names = "--input-file",
        required = true,
        description = "The input file to reduce",
        order = FlagOrder.COMPULSORY + 1)
    public String inputFile;

    public File getTestScript() {
      return new File(checkNotNull(testScript));
    }

    public File getSourceFile() {
      return new File(Preconditions.checkNotNull(inputFile));
    }

    @Override
    public void validate() {
      final File testScript = this.getTestScript();
      final String workingDirectory = new File(".").getAbsolutePath();
      checkState(
          testScript.isFile(),
          "The test script %s is not a file. The current directory is %s.",
          testScript,
          workingDirectory);
      checkState(testScript.canExecute(), "The test script %s is not executable.", testScript);

      final File sourceFile = this.getSourceFile();
      checkState(
          sourceFile.isFile(),
          "The source program %s is not a file. The current directory is %s.",
          sourceFile,
          workingDirectory);
    }
  }

  public static final class ResultOutputFlags implements ICommandLineFlags {
    @Parameter(
        names = "--in-place",
        description = "perform in-place reduction",
        arity = 1,
        order = FlagOrder.RESULT_OUTPUT + 0)
    public boolean inPlaceReduction = false;

    @Parameter(
        names = "--output-file",
        description = "The output file to save the reduced result.",
        order = FlagOrder.RESULT_OUTPUT + 1)
    public String outputFile;

    @Override
    public void validate() {
      if (inPlaceReduction) {
        checkState(
            outputFile == null || outputFile.trim().isEmpty(),
            "--in-place and --output-file cannot be specified together.");
      }
    }
  }

  public static final class ReductionControlFlags implements ICommandLineFlags {

    @Parameter(
        names = "--fixpoint",
        description = "iterative reduction till fixpoint",
        arity = 1,
        order = FlagOrder.REDUCTION_CONTROL + 0)
    public boolean fixpoint = true;

    @Parameter(
        names = "--threads",
        description = "Number of reduction threads: a positive integer, or 'auto'.",
        order = FlagOrder.REDUCTION_CONTROL + 1)
    private String numOfThreads = "auto";

    @Parameter(
        names = "--code-format",
        description = "The format of the reduced program.",
        arity = 1,
        order = FlagOrder.REDUCTION_CONTROL + 2)
    public EnumFormatControl codeFormat;

    @Override
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

  public static final class OutputRefiningFlags implements ICommandLineFlags {
    @Parameter(
        names = "--format-cmd",
        description = "the command to format the reduced source file",
        order = FlagOrder.OUTPUT_REFINING + 0)
    public String formatCmd = "";

    @Parameter(
        names = "--call-creduce",
        description = "call C-Reduce when Perses is done.",
        order = FlagOrder.OUTPUT_REFINING + 10)
    public boolean callCReduce = false;

    @Parameter(
        names = "--creduce-cmd",
        description = "the C-Reduce command name or path",
        order = FlagOrder.OUTPUT_REFINING + 20)
    private String creduceCmd = "creduce";

    @Override
    public void validate() {
      if (callCReduce) {
        Shell.normalizeAndCheckExecutability(creduceCmd);
      }
    }

    public String getCreduceCmd() {
      checkState(callCReduce);
      return Shell.normalizeAndCheckExecutability(creduceCmd);
    }
  }

  public final class ReductionAlgorithmControlFlags implements ICommandLineFlags {
    @Parameter(
        names = "--alg",
        description = "reduction algorithm: use --list-algs to list all available algorithms",
        order = FlagOrder.ALG_CONTROL + 0)
    public String reductionAlgorithm = null;

    @Parameter(
        names = "--list-algs",
        description = "list all the reduction algorithms.",
        help = true,
        order = FlagOrder.ALG_CONTROL + 1)
    public boolean listAllReductionAlgorithms;

    @Parameter(
        names = "--reparse-each-iteration",
        description = "Reparse the program before the start of each fixpoint iteration.",
        arity = 1,
        order = FlagOrder.ALG_CONTROL + 2)
    public boolean rebuildParseTreeEachIteration = true;

    @Parameter(
        names = "--enable-token-slicer",
        description = "Enable token slicer after syntax-guided reduction is done. Maybe slow.",
        arity = 1,
        order = FlagOrder.ALG_CONTROL + 3)
    public boolean enableTokenSlicer = false;

    @Parameter(
        names = "--enable-tree-slicer",
        description = "Enable tree slicer after syntax-guided reduction, and before token slicer",
        arity = 1,
        order = FlagOrder.ALG_CONTROL + 4)
    public boolean enableTreeSlicer = false;

    @Parameter(
        names = "--use-real-ddmin",
        description = "Whether to use the real delta debugging algorithm to reduce kleene nodes.",
        arity = 1,
        order = FlagOrder.ALG_CONTROL + 5)
    public boolean useRealDeltaDebugger = false;

    @Parameter(
        names = "--use-optc-parser",
        description = "Use the OptC parser to construct the spar-tree.",
        arity = 1,
        order = FlagOrder.ALG_CONTROL + 6)
    public boolean useOptCParser = false;

    public String getReductionAlgorithmName() {
      if (Strings.isNullOrEmpty(reductionAlgorithm)) {
        reductionAlgorithm = defaultReductionAlgorithm;
      }
      return this.reductionAlgorithm;
    }

    @Override
    public void validate() {}
  }

  public final class CacheControlFlags implements ICommandLineFlags {

    @Parameter(
        names = "--query-caching",
        description = "Enable query caching for test script executions.",
        arity = 1,
        order = FlagOrder.CACHE_CONTROL + 0)
    public boolean queryCaching = false;

    @Parameter(
        names = "--edit-caching",
        description = "Enable caching for edits performed between two successful reductions.",
        arity = 1,
        order = FlagOrder.CACHE_CONTROL + 1)
    public boolean nodeActionSetCaching = true;

    @Parameter(
        names = "--query-cache-refresh-threshold",
        description =
            "When to trigger a refresh of the query cache. "
                + "The value is is a fraction in the format x/y. "
                + "Assume the original token count is t. "
                + "Since last refresh where the best program has t' tokens, if the latest best program has b tokens, "
                + "and (t' - b) >= t *x/y, then a refresh is triggered.",
        order = FlagOrder.CACHE_CONTROL + 2)
    public String queryCacheRefreshThreshold = "100/1";

    public Fraction getQueryCacheRefreshThreshold() {
      return Fraction.parse(queryCacheRefreshThreshold);
    }

    @Override
    public void validate() {
      if (queryCacheRefreshThreshold != null) {
        Fraction.parse(queryCacheRefreshThreshold); // Should not throw exceptions.
      }
    }
  }

  public static final class ProfilingFlags implements ICommandLineFlags {

    @Parameter(
        names = "--progress-dump-file",
        description = "The file to record the reduction process. The dump file can be large..",
        order = FlagOrder.PROFILING_CONTROL + 0)
    public String progressDumpFile;

    @Parameter(
        names = "--stat-dump-file",
        description = "The file to save the statistics collected during reduction.",
        order = FlagOrder.PROFILING_CONTROL + 1)
    public String statDumpFile;

    @Parameter(
        names = "--profile-query-cache",
        description = "The file to save the profiling data of the query cache.",
        order = FlagOrder.PROFILING_CONTROL + 2)
    public String profileTestExecutionCache = null;

    @Parameter(
        names = "--profile-actionset",
        description = "The file to save information of all the created edit action sets.",
        order = FlagOrder.PROFILING_CONTROL + 3)
    public String actionSetProfiler = null;

    @Parameter(
        names = "--profile",
        description = "profile the reduction process for analysis",
        arity = 1,
        order = FlagOrder.PROFILING_CONTROL + 4)
    public boolean profile = false;

    @Parameter(
        names = "--script-monitoring-interval-millis",
        description =
            "the interval in milliseconds to monitor the performance of test script executions",
        order = FlagOrder.PROFILING_CONTROL + 50)
    public int testScriptExecutionPerformanceMonitorIntervalMillis = 1000 * 60 * 5;

    @Override
    public void validate() {
      checkState(testScriptExecutionPerformanceMonitorIntervalMillis > 0);
    }
  }

  public static final class VerbosityFlags implements ICommandLineFlags {
    @Parameter(
        names = {"--verbosity"},
        description = "verbosity of logging",
        order = FlagOrder.VERBOSITY_CONTROL + 10)
    public String verbosity = "INFO";

    @Parameter(
        names = {"--list-verbosity-levels"},
        description = "list all verbosity levels",
        order = FlagOrder.VERBOSITY_CONTROL + 20)
    public boolean listVerbosity;

    @Override
    public void validate() {}
  }

  private static class FlagOrder {
    public static final int COMPULSORY = 0;
    public static final int RESULT_OUTPUT = 1000;
    public static final int REDUCTION_CONTROL = 2000;
    public static final int OUTPUT_REFINING = 3000;
    public static final int ALG_CONTROL = 4000;
    public static final int CACHE_CONTROL = 5000;
    public static final int PROFILING_CONTROL = 6000;
    public static final int VERBOSITY_CONTROL = 7000;
    public static final int HELP = 8000;
  }
}
