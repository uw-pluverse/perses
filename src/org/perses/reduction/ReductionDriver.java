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
import com.google.common.base.Strings;
import com.google.common.collect.ImmutableList;
import com.google.common.flogger.FluentLogger;
import com.google.common.io.MoreFiles;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.tree.ParseTree;
import org.checkerframework.checker.nullness.qual.Nullable;
import org.perses.CommandOptions;
import org.perses.antlr.GrammarHierarchy;
import org.perses.grammar.AbstractParserFacade;
import org.perses.listener.*;
import org.perses.program.PersesTokenFactory;
import org.perses.program.SourceFile;
import org.perses.program.TokenizedProgram;
import org.perses.program.TokenizedProgramFactory;
import org.perses.reduction.AbstractActionSetProfiler.ActionSetProfiler;
import org.perses.tree.spar.*;
import org.perses.util.Shell;
import org.perses.util.TimeSpan;
import org.perses.util.Util;

import java.io.Closeable;
import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Objects;
import java.util.concurrent.ExecutionException;

import static com.google.common.base.Preconditions.checkState;

/**
 * This is the main entry to invoke Perses reducer. It does not have a main, but is the main entry
 * as a reduction library.
 */
public final class ReductionDriver implements Closeable {

  private static final FluentLogger logger = FluentLogger.forEnclosingClass();

  private final CommandOptions cmd;
  private final ReductionConfiguration configuration;
  private final TestScriptExecutorService executorService;
  private final ReductionListenerManager listenerManager;
  private SparTree tree;
  private final AbstractTestScriptExecutionCache queryCache;
  private final AbstractNodeActionSetCache nodeActionSetCache;
  private final AbstractActionSetProfiler actionSetProfiler;

  public ReductionDriver(CommandOptions cmd, AbstractReductionListener... extraListeners)
      throws IOException {
    this.cmd = cmd;
    configuration = createConfiguration(cmd);
    listenerManager =
        new ReductionListenerManager(
            createListeners(cmd.isProfiling(), configuration, extraListeners));
    executorService =
        new TestScriptExecutorService(
            configuration.getTempRootFolder(),
            configuration.getNumOfReductionThreads(),
            configuration.getTestScript(),
            configuration.getFileToReduce().getBaseName());
    tree = createSparTree(configuration.getFileToReduce());
    final AbstractTestScriptExecutionCacheProfiler cacheProfiler =
        Strings.isNullOrEmpty(cmd.profileTestExecutionCache)
            ? AbstractTestScriptExecutionCacheProfiler.NULL_PROFILER
            : new AbstractTestScriptExecutionCacheProfiler.TestScriptExecutionCacheProfiler(
                new File(cmd.profileTestExecutionCache));
    queryCache =
        configuration.isEnableTestScriptExecutionCaching()
            ? new TestScriptExecutionCache(tree.getProgramSnapshot(), cacheProfiler, false)
            : new NullTestScriptExecutionCache();
    nodeActionSetCache =
        cmd.nodeActionSetCaching ? new NodeActionSetCache() : new NullNodeActionSetCache();
    actionSetProfiler =
        Strings.isNullOrEmpty(cmd.actionSetProfiler)
            ? AbstractActionSetProfiler.NULL_PROFILER
            : new ActionSetProfiler();
  }

  public void reduce() throws IOException, ExecutionException, InterruptedException {
    logger.atInfo().log(
        "The reduction process started at %s",
        Util.formatDateForDisplay(System.currentTimeMillis()));
    backupFile(configuration);

    final AbstractReducer worker = createReducer();
    final ImmutableList<AbstractSparTreeEditListener> sparTreeEditListeners =
        createSparTreeEditListeners(configuration);
    tree.registerSparTreeEditListeners(sparTreeEditListeners);
    sanityCheck(tree);

    final TokenizedProgramFactory tokenizedProgramFactory = tree.getTokenizedProgramFactory();
    final PersesTokenFactory persesTokenFactory = tokenizedProgramFactory.getTokenFactory();
    logger.atInfo().log(
        "The number of lexemes in the token factory is is %s", persesTokenFactory.numOfLexemes());
    {
      final SourceFile fileToReduce = configuration.getFileToReduce();
      final File bestFile = configuration.getBestResultFile();
      if (!fileToReduce.getFile().getCanonicalPath().equals(bestFile.getCanonicalPath())) {
        MoreFiles.asCharSink(bestFile.toPath(), StandardCharsets.UTF_8)
            .write(fileToReduce.getFileContent());
      }
    }

    listenerManager.onReductionStart(tree, tree.getOriginalTokenCount());
    for (int fixpointIteration = 1; true; ++fixpointIteration) {
      final int currentFixpointIteration = fixpointIteration;
      if (currentFixpointIteration > 1) {
        logger.atInfo().log(
            "The fixpoint mode is enabled. This is iteration %s", fixpointIteration);
        if (cmd.rebuildParseTreeEachIteration) {
          logger.atInfo().log("Rebuilding spar-tree.");
          // Rebuilding is necessary, to hop over different production rules.
          tree = reparseAndCreateSparTree(tree);
          tree.registerSparTreeEditListeners(sparTreeEditListeners);
        }
        assert tree.getTokenizedProgramFactory() == tokenizedProgramFactory
            : "The tokenized program factory should be unchanged during a reduction process.";
        assert tree.getTokenizedProgramFactory().getTokenFactory() == persesTokenFactory
            : "The perses token factory should be unchanged duing a reduction process.";
      }
      tree.updateLeafTokenCount();
      final int preSize = tree.getTokenCount();
      final int currentCountOfTestScriptExecutions = executorService.getExecutionCounter();
      listenerManager.onFixpointIterationStart(
          currentFixpointIteration, preSize, worker.getRedcucerAnnotation());
      final ReductionState reductionState = new ReductionState(tree);
      assert reductionState.getSparTree() == tree;
      worker.reduce(reductionState);
      final TokenizedProgram programAfterIteration = tree.getProgramSnapshot();
      final int postSize = programAfterIteration.tokenCount();
      final int countOfTestScriptExecutionsInThisIteration =
          executorService.getExecutionCounter() - currentCountOfTestScriptExecutions;
      listenerManager.onFixpointIterationEnd(
          currentFixpointIteration, postSize, countOfTestScriptExecutionsInThisIteration);
      {
        // Save the best result after a fixpoint iteration.
        File fixpointIterationResultFile =
            configuration.getFixpointIterationResultFile(currentFixpointIteration);
        logger.atFinest().log(
            "Saved result after fixpoint %s to %s",
            currentFixpointIteration, fixpointIterationResultFile);
        programAfterIteration.writeToFile(
            fixpointIterationResultFile, configuration.isKeepOriginalCodeFormat());
      }
      if (!configuration.isFixpointReduction() || preSize <= postSize) {
        break;
      }
    }
    {
      final int countOfTestScriptExecutions = executorService.getExecutionCounter();
      final int finalTokenCount = tree.getTokenCount();
      listenerManager.onReductionEnd(finalTokenCount, countOfTestScriptExecutions);
    }
    formatBestFile(cmd.getFormatCmd(), configuration.getBestResultFile());
  }

  @VisibleForTesting
  static ReductionConfiguration createConfiguration(CommandOptions cmd) {
    final File sourceFile = cmd.getSourceFile().getAbsoluteFile();
    final File testScript = cmd.getTestScript().getAbsoluteFile();
    checkState(
        Objects.equals(
            sourceFile.getParentFile().getAbsolutePath(),
            testScript.getParentFile().getAbsolutePath()),
        "The source file and the test script should reside in the same folder. sourceFile:%s, testScript:%s",
        sourceFile,
        testScript);
    final File workingDirectory = sourceFile.getParentFile();

    final File bestFile = getOutputFile(cmd);
    @Nullable
    final File statisticsFile =
        Strings.isNullOrEmpty(cmd.statDumpFile) ? null : new File(cmd.statDumpFile);
    @Nullable
    final File progressDumpFile =
        Strings.isNullOrEmpty(cmd.progressDumpFile) ? null : new File(cmd.progressDumpFile);

    return new ReductionConfiguration(
        workingDirectory,
        testScript,
        sourceFile,
        bestFile,
        statisticsFile,
        progressDumpFile,
        cmd.keepOrigFormat,
        cmd.fixpoint,
        cmd.queryCaching,
        cmd.useRealDeltaDebugger,
        cmd.refreshQueryCache,
        cmd.getMaxReductionLevel(),
        cmd.numOfThreads,
        getMultiNodePartitionReductionPolicy(cmd),
        getSingleNodePartitionReductionPolicy(cmd));
  }

  public static IPartitionReductionPolicy.SingleNodePartitionReductionPolicy
      getSingleNodePartitionReductionPolicy(CommandOptions cmd) {
    return new IPartitionReductionPolicy.SingleNodePartitionReductionPolicy.Builder()
        .delete(cmd.singleNodePartitionPolicyDelete)
        .deleteChildrenOfCurrentNode(cmd.singleNodePartitionPolicyDeleteChildrenOfNode)
        .deleteCurrentNodeAsAQualifiedNode(cmd.singleNodePartitionPolicyDeleteNodeAsQualifiedNode)
        .replaceCurrentNodeAsAQualifiedNode(cmd.singleNodePartitionPolicyReplaceNodeAsQualifiedNode)
        .build();
  }

  public static IPartitionReductionPolicy.MultiNodePartitionReductionPolicy
      getMultiNodePartitionReductionPolicy(CommandOptions cmd) {
    return new IPartitionReductionPolicy.MultiNodePartitionReductionPolicy.Builder()
        .delete(cmd.multiNodePartitionPolicyDelete)
        .sparDeletion(cmd.multiNodePartitionPolicySparDelete)
        .build();
  }

  protected final void sanityCheck(SparTree tree) throws InterruptedException, ExecutionException {
    logger.atFinest().log("sanity checking...");
    // TODO: need two steps of sanity check:
    //  (1) use the original source program and test scrip. This ensures the test script is correct.
    //  (2) use the spar-tree. This ensures the Antlr parser works correctly.
    final TokenizedProgram program = tree.getProgramSnapshot();
    final TestScriptExecutorService.FutureTestScriptExecutionTask future =
        executorService.testProgram(program, configuration.isKeepOriginalCodeFormat());
    checkState(
        future.get().isPass(),
        "The initial sanity check failed. Folder: ",
        future.getWorkingDirectory());
  }

  public ReductionConfiguration getConfiguration() {
    return configuration;
  }

  private final void formatBestFile(String formatCmd, File bestFile) {
    if (Strings.isNullOrEmpty(formatCmd)) {
      return;
    }
    final String cmd = formatCmd + " " + bestFile.getName();
    try {
      Shell.run(cmd, bestFile.getAbsoluteFile().getParentFile(), true);
    } catch (Throwable e) {
      logger.atSevere().withCause(e).log("failed to execute the format command '%s'", cmd);
    }
  }

  public SparTree reparseAndCreateSparTree(SparTree originalTree) {
    final TokenizedProgram program = originalTree.getProgramSnapshot();
    final AbstractParserFacade parserFacade = configuration.getParserFacade();
    final ParseTree parseTree = parserFacade.parseTokenizedProgram(program).getTree();
    return new SparTreeBuilder(
            parserFacade.getRuleHierarchy(), originalTree.getTokenizedProgramFactory())
        .build(parseTree);
  }

  public final SparTree createSparTree(SourceFile fileToReduce) throws IOException {
    final TimeSpan.Builder timeSpanBuilder = TimeSpan.Builder.start(System.currentTimeMillis());

    logger.atInfo().log("Tree Building: Start building spar-tree from input file %s", fileToReduce);
    final AbstractParserFacade parserFacade = configuration.getParserFacade();
    final GrammarHierarchy hierarchy = parserFacade.getRuleHierarchy();

    logger.atInfo().log("Tree Building: Step 1: Antlr parsing.");
    final ParseTree parseTree = parserFacade.parseString(fileToReduce.getFileContent()).getTree();

    final TokenizedProgramFactory tokenizedProgramFactory =
        createTokenizedProgramFactory(parseTree);

    logger.atInfo().log("Tree Building: Step 2: Converting parse tree to spar-tree");
    final SparTree sparTree =
        new SparTreeBuilder(hierarchy, tokenizedProgramFactory).build(parseTree);

    logger.atInfo().log("Tree Building: Step 3: Simplifying spar-tree");

    final TimeSpan time = timeSpanBuilder.end(System.currentTimeMillis());
    logger.atInfo().log("Tree Building: Finished in %s", time);

    return sparTree;
  }

  @Override
  public void close() throws IOException {
    executorService.shutdown();
  }

  private ImmutableList<AbstractSparTreeEditListener> createSparTreeEditListeners(
      final ReductionConfiguration configuration) {
    ImmutableList.Builder<AbstractSparTreeEditListener> builder = ImmutableList.builder();
    builder.add(
        new AbstractSparTreeEditListener() {
          @Override
          public void onAfterSparTreeEditApplied(SparTreeEditEvent event) {
            try {
              event
                  .getProgram()
                  .writeToFile(
                      configuration.getBestResultFile(), configuration.isKeepOriginalCodeFormat());
            } catch (IOException e) {
              throw new RuntimeException(e);
            }
          }
        });
    builder.add(
        new AbstractSparTreeEditListener() {
          @Override
          public void onAfterSparTreeEditApplied(SparTreeEditEvent event) {
            final AbstractTestScriptExecutionCache cache = queryCache;
            final int sizeBefore = cache.size();
            cache.evictEntriesLargerThan(event.getProgram());
            final int sizeAfter = cache.size();
            listenerManager.onTestScriptExecutionCacheEntryEviction(sizeBefore, sizeAfter);
          }
        });
    builder.add(
        new AbstractSparTreeEditListener() {
          @Override
          public void onAfterSparTreeEditApplied(SparTreeEditEvent event) {
            final int originalSize = nodeActionSetCache.size();
            nodeActionSetCache.clear();
            listenerManager.onNodeActionSetClearance(originalSize);
          }
        });
    return builder.build();
  }

  final AbstractReducer createReducer() {
    logger.atInfo().log(
        "Reduction algorithm is %s",
        ReducerFactory.getReductionAlgorithm(cmd.getReductionAlgorithmName()));
    return ReducerFactory.getReductionAlgorithm(cmd.getReductionAlgorithmName())
        .create(
            new ReducerContext(
                configuration,
                executorService,
                listenerManager,
                queryCache,
                nodeActionSetCache,
                actionSetProfiler));
  }

  private static TokenizedProgramFactory createTokenizedProgramFactory(ParseTree originalTree) {
    final ImmutableList<Token> tokens = AbstractParserFacade.getTokens(originalTree);
    return TokenizedProgramFactory.createFactory(tokens);
  }

  private static ImmutableList<AbstractReductionListener> createListeners(
      final boolean enableProfiling,
      final ReductionConfiguration configuration,
      final AbstractReductionListener[] extraListeners) {
    ImmutableList.Builder<AbstractReductionListener> builder = ImmutableList.builder();
    builder.add(new LoggingListener());
    configuration.getStatisticsFile().map(file -> builder.add(new StatisticsListener(file)));
    configuration
        .getProgressDumpFile()
        .map(file -> builder.add(ProgressMonitorForNodeReducer.createForFile(file)));
    configuration
        .getTestScriptStatisticsFile()
        .map(file -> builder.add(new TestScriptExecutionListener(file)));
    for (AbstractReductionListener extraListener : extraListeners) {
      builder.add(extraListener);
    }
    if (enableProfiling) {
      final File profileFile =
          new File(
              configuration.getWorkingFolder(),
              configuration.getFileToReduce().getBaseName() + ".profile.txt");
      final ReductionProfileListener profile = new ReductionProfileListener(profileFile);
      profile.addComment("reduction config", configuration.dumpConfiguration());
      builder.add(profile);
    }
    return builder.build();
  }

  private static File getOutputFile(CommandOptions cmd) {
    final File sourceFile = cmd.getSourceFile();
    if (cmd.inPlaceReduction) {
      return sourceFile;
    }
    if (Strings.isNullOrEmpty(cmd.outputFile)) {
      final String reductionAlgorithm = cmd.getReductionAlgorithmName();
      return new File(
          sourceFile.getParent(), reductionAlgorithm + "_reduced_" + sourceFile.getName());
    } else {
      return new File(cmd.outputFile);
    }
  }

  private void backupFile(ReductionConfiguration configuration) throws IOException {
    final SourceFile fileToReduce = configuration.getFileToReduce();
    final String baseName = fileToReduce.getBaseName();
    final String fileContent = fileToReduce.getFileContent();
    File backupFile =
        new File(
            configuration.getWorkingFolder(),
            baseName + "." + Util.formatDateForFileName(System.currentTimeMillis()) + ".orig");
    MoreFiles.asCharSink(backupFile.toPath(), StandardCharsets.UTF_8).write(fileContent);
  }
}
