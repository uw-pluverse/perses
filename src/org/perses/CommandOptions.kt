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
package org.perses

import com.beust.jcommander.Parameter
import org.perses.program.EnumFormatControl
import org.perses.util.AbstractCommandOptions
import org.perses.util.Fraction
import org.perses.util.ICommandLineFlags
import org.perses.util.ShellCommandOnPath.Companion.normalizeAndCheckExecutability
import java.io.File

/** Parser for command line arguments.  */
class CommandOptions(defaultReductionAlgorithm: String) : AbstractCommandOptions() {
  @JvmField
  val compulsoryFlags = registerFlags(CompulsoryFlags())

  @JvmField
  val resultOutputFlags = registerFlags(ResultOutputFlags())

  @JvmField
  val reductionControlFlags = registerFlags(ReductionControlFlags())
  val outputRefiningFlags = registerFlags(OutputRefiningFlags())

  @JvmField
  val algorithmControlFlags = registerFlags(ReductionAlgorithmControlFlags(defaultReductionAlgorithm))
  val cacheControlFlags = registerFlags(CacheControlFlags())
  val profilingFlags = registerFlags(ProfilingFlags())

  @JvmField
  val verbosityFlags = registerFlags(VerbosityFlags())

  private val allFlags = listOf(
    compulsoryFlags,
    resultOutputFlags,
    reductionControlFlags,
    outputRefiningFlags,
    algorithmControlFlags,
    cacheControlFlags,
    profilingFlags,
    verbosityFlags
  )

  @JvmField
  @Parameter(
    names = ["--help", "-h"],
    description = "print help message",
    help = true,
    order = FlagOrder.HELP
  )
  var help = false

  @JvmField
  @Parameter(
    names = ["--version"],
    description = "print the version",
    help = true,
    order = FlagOrder.HELP + 1
  )
  var version = false

  class CompulsoryFlags : ICommandLineFlags {
    @JvmField
    @Parameter(
      names = ["--test-script"],
      required = true,
      description = "The test script to specify the property the reducer needs to preserve.",
      order = FlagOrder.COMPULSORY + 0
    )
    var testScript: String? = null

    @JvmField
    @Parameter(
      names = ["--input-file"],
      required = true,
      description = "The input file to reduce",
      order = FlagOrder.COMPULSORY + 1
    )
    var inputFile: String? = null

    fun getTestScript() = File(checkNotNull(testScript))

    fun getSourceFile() = File(checkNotNull(inputFile))

    override fun validate() {
      val testScript = getTestScript()
      val workingDirectory = File(".").absolutePath
      check(testScript.isFile) {
        "The test script $testScript is not a file. The current directory is $workingDirectory."
      }
      check(testScript.canExecute()) {
        "The test script $testScript is not executable."
      }

      val sourceFile = getSourceFile()
      check(sourceFile.isFile) {
        "The source program $sourceFile is not a file. The current directory is $workingDirectory."
      }
    }
  }

  class ResultOutputFlags : ICommandLineFlags {
    @JvmField
    @Parameter(
      names = ["--in-place"],
      description = "perform in-place reduction",
      arity = 1,
      order = FlagOrder.RESULT_OUTPUT + 0
    )
    var inPlaceReduction = false

    @Parameter(
      names = ["--output-file"],
      description = "The output file to save the reduced result.",
      order = FlagOrder.RESULT_OUTPUT + 1
    )
    var outputFile: String? = null

    override fun validate() {
      if (inPlaceReduction) {
        check(outputFile.isNullOrBlank()) {
          "--in-place and --output-file cannot be specified together."
        }
      }
    }
  }

  class ReductionControlFlags : ICommandLineFlags {
    @JvmField
    @Parameter(
      names = ["--fixpoint"],
      description = "iterative reduction till fixpoint",
      arity = 1,
      order = FlagOrder.REDUCTION_CONTROL + 0
    )
    var fixpoint = true

    @Parameter(
      names = ["--threads"],
      description = "Number of reduction threads: a positive integer, or 'auto'.",
      order = FlagOrder.REDUCTION_CONTROL + 1
    )
    private var numOfThreads = "auto"

    @Parameter(
      names = ["--code-format"],
      description = "The format of the reduced program.",
      arity = 1,
      order = FlagOrder.REDUCTION_CONTROL + 2
    )
    var codeFormat: EnumFormatControl? = null

    override fun validate() {
      if ("auto"!=numOfThreads) {
        check(numOfThreads.toInt() > 0) { numOfThreads }
      }
    }

    fun getNumOfThreads(): Int {
      return if ("auto"==numOfThreads) {
        Runtime.getRuntime().availableProcessors()
      } else {
        numOfThreads.toInt()
      }
    }
  }

  class OutputRefiningFlags : ICommandLineFlags {
    @Parameter(
      names = ["--call-formatter"],
      description = "call a formatter on the final result",
      arity = 1,
      order = FlagOrder.OUTPUT_REFINING + 0
    )
    var callFormatter = false

    @Parameter(
      names = ["--format-cmd"],
      description = "the command to format the reduced source file",
      order = FlagOrder.OUTPUT_REFINING + 100
    )
    var formatCmd = ""

    @Parameter(
      names = ["--call-creduce"],
      description = "call C-Reduce when Perses is done.",
      arity = 1,
      order = FlagOrder.OUTPUT_REFINING + 200
    )
    var callCReduce = false

    @Parameter(
      names = ["--creduce-cmd"],
      description = "the C-Reduce command name or path",
      order = FlagOrder.OUTPUT_REFINING + 300
    )
    private var creduceCmd = "creduce"

    override fun validate() {
      if (callCReduce) {
        normalizeAndCheckExecutability(creduceCmd)
      }
      check(formatCmd.isBlank()) {
        "Does not support customized format command yet. $formatCmd"
      }
    }

    fun getCreduceCmd(): String {
      check(callCReduce)
      return normalizeAndCheckExecutability(creduceCmd)
    }
  }

  class ReductionAlgorithmControlFlags(val defaultReductionAlgorithm: String)
    : ICommandLineFlags {
    @JvmField
    @Parameter(
      names = ["--alg"],
      description = "reduction algorithm: use --list-algs to list all available algorithms",
      order = FlagOrder.ALG_CONTROL + 0
    )
    var reductionAlgorithm: String? = null

    @JvmField
    @Parameter(
      names = ["--list-algs"],
      description = "list all the reduction algorithms.",
      help = true,
      order = FlagOrder.ALG_CONTROL + 1
    )
    var listAllReductionAlgorithms = false

    @Parameter(
      names = ["--reparse-each-iteration"],
      description = "Reparse the program before the start of each fixpoint iteration.",
      arity = 1,
      order = FlagOrder.ALG_CONTROL + 2
    )
    var rebuildParseTreeEachIteration = true

    @Parameter(
      names = ["--enable-token-slicer"],
      description = "Enable token slicer after syntax-guided reduction is done. Maybe slow.",
      arity = 1,
      order = FlagOrder.ALG_CONTROL + 3
    )
    var enableTokenSlicer = false

    @Parameter(
      names = ["--enable-tree-slicer"],
      description = "Enable tree slicer after syntax-guided reduction, and before token slicer",
      arity = 1,
      order = FlagOrder.ALG_CONTROL + 4
    )
    var enableTreeSlicer = false

    @Parameter(
      names = ["--use-real-ddmin"],
      description = "Whether to use the real delta debugging algorithm to reduce kleene nodes.",
      arity = 1,
      order = FlagOrder.ALG_CONTROL + 5
    )
    var useRealDeltaDebugger = false

    @JvmField
    @Parameter(
      names = ["--use-optc-parser"],
      description = "Use the OptC parser to construct the spar-tree.",
      arity = 1,
      order = FlagOrder.ALG_CONTROL + 6
    )
    var useOptCParser = false

    fun getReductionAlgorithmName(): String {
      if (reductionAlgorithm.isNullOrEmpty()) {
        reductionAlgorithm = defaultReductionAlgorithm
      }
      return checkNotNull(reductionAlgorithm)
    }

    override fun validate() = Unit
  }

  class CacheControlFlags : ICommandLineFlags {
    @Parameter(
      names = ["--query-caching"],
      description = "Enable query caching for test script executions.",
      arity = 1,
      order = FlagOrder.CACHE_CONTROL + 0
    )
    var queryCaching: Boolean = false

    @Parameter(
      names = ["--edit-caching"],
      description = "Enable caching for edits performed between two successful reductions.",
      arity = 1,
      order = FlagOrder.CACHE_CONTROL + 1
    )
    var nodeActionSetCaching = true

    @Parameter(
      names = ["--query-cache-refresh-threshold"],
      description = "The threshold triggers a refresh of the query cache. " +
        "The refresh follows the equation: t' - t'' >= t * threshold(%). " +
        "t 	- original tokens. " +
        "t' 	- tokens of the best program at last refresh. " +
        "t''	- tokens of the current best program. " +
        "Refresh threshold requires an integer input ranging [0, 100]. " +
        "e.g. 0 represents 0%, 85 represents 85%.",
      order = FlagOrder.CACHE_CONTROL + 2
    )
    var queryCacheRefreshThreshold = 0 // Represent 0/100 = 0%

    fun getQueryCacheRefreshThreshold(): Fraction {
      return Fraction(queryCacheRefreshThreshold, 100)
    }

    override fun validate() {
      getQueryCacheRefreshThreshold() // Should not throw exceptions.
    }
  }

  class ProfilingFlags : ICommandLineFlags {
    @Parameter(
      names = ["--progress-dump-file"],
      description = "The file to record the reduction process. The dump file can be large..",
      order = FlagOrder.PROFILING_CONTROL + 0
    )
    var progressDumpFile: String? = null

    @Parameter(
      names = ["--stat-dump-file"],
      description = "The file to save the statistics collected during reduction.",
      order = FlagOrder.PROFILING_CONTROL + 1
    )
    var statDumpFile: String? = null

    @Parameter(
      names = ["--profile-query-cache"],
      description = "The file to save the profiling data of the query cache.",
      order = FlagOrder.PROFILING_CONTROL + 2
    )
    var profileTestExecutionCache: String? = null

    @Parameter(
      names = ["--profile-actionset"],
      description = "The file to save information of all the created edit action sets.",
      order = FlagOrder.PROFILING_CONTROL + 3
    )
    var actionSetProfiler: String? = null

    @Parameter(
      names = ["--profile"],
      description = "profile the reduction process for analysis",
      arity = 1,
      order = FlagOrder.PROFILING_CONTROL + 4
    )
    var profile = false

    @Parameter(
      names = ["--script-monitoring-interval-millis"],
      description = "the interval in milliseconds to monitor " +
        "the performance of test script executions",
      order = FlagOrder.PROFILING_CONTROL + 50
    )
    var testScriptExecutionPerformanceMonitorIntervalMillis = 1000 * 60 * 5

    override fun validate() {
      check(testScriptExecutionPerformanceMonitorIntervalMillis > 0)
    }
  }

  class VerbosityFlags : ICommandLineFlags {
    @JvmField
    @Parameter(
      names = ["--verbosity"],
      description = "verbosity of logging",
      order = FlagOrder.VERBOSITY_CONTROL + 10
    )
    var verbosity = "INFO"

    @JvmField
    @Parameter(
      names = ["--list-verbosity-levels"],
      description = "list all verbosity levels",
      help = true,
      order = FlagOrder.VERBOSITY_CONTROL + 20
    )
    var listVerbosity = false

    override fun validate() = Unit
  }
}

private object FlagOrder {
  const val COMPULSORY = 0
  const val RESULT_OUTPUT = 1000
  const val REDUCTION_CONTROL = 2000
  const val OUTPUT_REFINING = 3000
  const val ALG_CONTROL = 4000
  const val CACHE_CONTROL = 5000
  const val PROFILING_CONTROL = 6000
  const val VERBOSITY_CONTROL = 7000
  const val HELP = 8000
}
