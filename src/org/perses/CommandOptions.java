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

import com.beust.jcommander.Parameter;
import com.google.common.base.Preconditions;
import com.google.common.base.Strings;

import java.io.File;

import static com.google.common.base.Preconditions.checkNotNull;
import static com.google.common.base.Preconditions.checkState;

/** Parser for command line arguments. */
public class CommandOptions {

  private final String defaultReductionAlgorithm;

  @Parameter(
      names = "--single-node-partition-policy-delete",
      description = "Single-node partition reduction policy: delete",
      arity = 1)
  public boolean singleNodePartitionPolicyDelete = true;

  @Parameter(
      names = "--single-node-partition-policy-delete-node-as-qualified-node",
      description = "Single-node partition reduction policy: delete node as qualified node",
      arity = 1)
  public boolean singleNodePartitionPolicyDeleteNodeAsQualifiedNode = true;

  @Parameter(
      names = "--single-node-partition-policy-replace-node-as-qualified-node",
      description = "Single-node partition reduction policy: replace node as qualified node",
      arity = 1)
  public boolean singleNodePartitionPolicyReplaceNodeAsQualifiedNode = true;

  @Parameter(
      names = "--single-node-partition-policy--delete-children-of-node",
      description = "Single-node partition reduction policy: delete children of the node",
      arity = 1)
  public boolean singleNodePartitionPolicyDeleteChildrenOfNode = true;

  @Parameter(
      names = "--multi-node-partition-policy-delete",
      description = "Multi-node partition reduction policy: delete",
      arity = 1)
  public boolean multiNodePartitionPolicyDelete = true;

  @Parameter(
      names = "--multi-node-partition-policy-spar-delete",
      description = "Multi-node partition reduction policy: syntax-guided deletion.",
      arity = 1)
  public boolean multiNodePartitionPolicySparDelete = true;

  @Parameter(names = "--in-place", description = "perform in-place reduction", arity = 1)
  public boolean inPlaceReduction = false;

  @Parameter(names = "--help", description = "print help message", help = true)
  public boolean help;

  @Parameter(names = "--count-tokens", description = "Count tokens in the input file")
  public boolean countTokens;

  @Parameter(names = "--fixpoint", description = "iterative reduction till fixpoint", arity = 1)
  public boolean fixpoint = false;

  @Parameter(
      names = "--keep-orig-format",
      description = "keep the original code format during reduction. May slow down if enabled.",
      arity = 1)
  public boolean keepOrigFormat = false;

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
  private String reductionAlgorithm = null;

  @Parameter(names = "--list-algs", description = "list all the reduction algorithms.", help = true)
  public boolean listAllReductionAlgorithms;

  @Parameter(names = "--format-cmd", description = "the command to format the reduced source file")
  public String formatCmd = "";

  @Parameter(names = "--max-level", description = "the max levels in the tree for reduction")
  public int maxReductionLevel = Integer.MAX_VALUE;

  @Parameter(names = "--threads", description = "Number of reduction threads.")
  public int numOfThreads = Runtime.getRuntime().availableProcessors();

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
      names = "--test-script",
      required = true,
      description = "The test script to specify the property the reducer needs to preserve.")
  public String testScript;

  @Parameter(names = "--input-file", required = true, description = "The input file to reduce")
  public String inputFile;

  @Parameter(names = "--output-file", description = "The output file to save the reduced result.")
  public String outputFile;

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
      description = "The file to save information of all the created edit action sets."
  )
  public String actionSetProfiler = null;

  @Parameter(
      names = "--use-real-ddmin",
      description = "Whether to use the real delta debugging algorithm to reduce kleene nodes.",
      arity = 1)
  public boolean useRealDeltaDebugger = false;

  @Parameter(names = "--refresh-query-cache", description = "Whether to refresh query cache.")
  public boolean refreshQueryCache = false;

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

  public void setReductionAlgorithm(String reductionAlgorithm) {
    this.reductionAlgorithm = reductionAlgorithm;
  }

  public void setInPlaceReduction(boolean inPlaceReduction) {
    this.inPlaceReduction = inPlaceReduction;
  }

  public int getMaxReductionLevel() {
    return maxReductionLevel;
  }

  public void setDebugGranularity(boolean debugGranularity) {
    this.debugGranularity = debugGranularity;
  }

  public boolean isHelp() {
    return help;
  }

  public boolean isProfiling() {
    return profile;
  }

  public boolean isListAllReductionAlgorithms() {
    return listAllReductionAlgorithms;
  }

  public void validate() {
    final File testScript = this.getTestScript();
    checkState(testScript.isFile(), "The test script %s is not a file.", testScript);
    checkState(testScript.canExecute(), "The test script %s is not executable.", testScript);

    final File sourceFile = this.getSourceFile();
    checkState(sourceFile.isFile(), "The source program %s is not a file.", sourceFile);

    if (inPlaceReduction) {
      checkState(
          outputFile == null || outputFile.trim().isEmpty(),
          "--in-place and --output-file cannot be specified together.");
    }
  }

  public File getTestScript() {
    return new File(checkNotNull(testScript));
  }

  public void setTestScript(String path) {
    this.testScript = path;
  }

  public File getSourceFile() {
    return new File(Preconditions.checkNotNull(inputFile));
  }

  public void setSourceFile(String path) {
    this.inputFile = path;
  }

  public void setFixpoint(boolean fixpoint) {
    this.fixpoint = fixpoint;
  }

  public void setMultiNodePartitionPolicyDelete(boolean multiNodePartitionPolicyDelete) {
    this.multiNodePartitionPolicyDelete = multiNodePartitionPolicyDelete;
  }

  public void setSingleNodePartitionPolicyDelete(boolean singleNodePartitionPolicyDelete) {
    this.singleNodePartitionPolicyDelete = singleNodePartitionPolicyDelete;
  }
}
