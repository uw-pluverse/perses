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

import org.perses.program.TokenizedProgram;
import org.perses.reduction.TestScript.TestResult;
import org.perses.reduction.TestScriptExecutorService.FutureTestScriptExecutionTask;
import org.perses.tree.spar.*;

import java.io.IOException;
import java.util.*;
import java.util.concurrent.ExecutionException;

/** The base class for reducer. Both hdd and perses algorithms extend this class. */
public abstract class AbstractReducer {

  protected final ReducerAnnotation reducerAnnotation;

  protected final ReductionConfiguration configuration;
  protected final TestScriptExecutorService executorService;
  protected final AbstractTestScriptExecutionCache queryCache;
  protected final ReductionListenerManager listenerManager;
  protected final AbstractNodeActionSetCache nodeActionSetCache;
  protected final AbstractActionSetProfiler actionSetProfiler;

  protected AbstractReducer(ReducerAnnotation reducerAnnotation, ReducerContext reducerContext) {
    this.reducerAnnotation = reducerAnnotation;
    this.configuration = reducerContext.configuration;
    this.executorService = reducerContext.executorService;
    this.queryCache = reducerContext.queryCache;
    this.listenerManager = reducerContext.listenerManager;
    this.nodeActionSetCache = reducerContext.nodeActionSetCache;
    this.actionSetProfiler = reducerContext.actionSetProfiler;
  }

  private static void removePermanentlyDeletedNodes(LinkedList<AbstractSparTreeNode> partition) {
    for (Iterator<AbstractSparTreeNode> iter = partition.iterator(); iter.hasNext(); ) {
      final AbstractSparTreeNode node = iter.next();
      if (node.isPermanentlyDeleted()) {
        iter.remove();
      }
    }
  }

  public final ReducerAnnotation getRedcucerAnnotation() {
    return reducerAnnotation;
  }

  protected FutureTestScriptExecutionTask testProgramAsynchronously(TokenizedProgram program) {
    return executorService.testProgram(program, configuration.isKeepOriginalCodeFormat());
  }

  private static class FutureExecutionResultInfo {
    final AbstractSparTreeEdit edit;
    final TokenizedProgram program;
    final FutureTestScriptExecutionTask future;

    private FutureExecutionResultInfo(
        AbstractSparTreeEdit edit, TokenizedProgram program, FutureTestScriptExecutionTask future) {
      this.edit = edit;
      this.program = program;
      this.future = future;
    }

    public TestResult getResult() {
      try {
        return future.get();
      } catch (Exception e) {
        throw new RuntimeException(e);
      }
    }

    public void cancel() {
      future.cancel(true);
    }
  }

  protected final Optional<TreeEditWithItsProgram> testAllTreeEditsAndReturnTheBest(
      final List<? extends AbstractSparTreeEdit> editList) {
    if (editList.isEmpty()) {
      return Optional.empty();
    }
    final ArrayList<FutureExecutionResultInfo> futureList =
        asyncApplyEditsInOrderOfProgramSizeFromLeast(editList);
    Optional<FutureExecutionResultInfo> best = analyzeResultsAndGetBest(futureList);
    assert !best.isPresent()
        || configuration.getParserFacade().isSourceCodeParsable(best.get().edit.getProgram());
    return best.map(b -> new TreeEditWithItsProgram(b.edit, b.getResult()));
  }

  private boolean isFutureListSortedFromLeastProgramSizeToGreatest(
      ArrayList<FutureExecutionResultInfo> futureList) {
    final int size = futureList.size();
    if (size < 2) {
      return true;
    }
    for (int i = 1; i < size; ++i) {
      final FutureExecutionResultInfo prev = futureList.get(i - 1);
      final FutureExecutionResultInfo current = futureList.get(i);
      if (prev.program.tokenCount() > current.program.tokenCount()) {
        return false;
      }
    }
    return true;
  }

  private Optional<FutureExecutionResultInfo> analyzeResultsAndGetBest(
      ArrayList<FutureExecutionResultInfo> futureList) {
    assert isFutureListSortedFromLeastProgramSizeToGreatest(futureList) : futureList;

    FutureExecutionResultInfo best = null;

    for (FutureExecutionResultInfo executionResultInfo : futureList) {
      if (best != null) {
        // The best is already found, then it is safe to cancel all the remaining testing tasks, as
        // none of these tasks will beat the current best one. Moreover, the tasks are not useful
        // for future cache testing, as all future programs will be smaller than the programs
        // represented by these tasks.
        final long start = System.currentTimeMillis();
        executionResultInfo.cancel();
        final int duration = (int) (System.currentTimeMillis() - start);
        listenerManager.onTestScriptExecutionCancelled(
            executionResultInfo.program, executionResultInfo.edit, duration);
        continue;
      }
      final TestResult testResult = executionResultInfo.getResult();

      queryCache.addResult(executionResultInfo.program, executionResultInfo.getResult());
      listenerManager.onTestScriptExecution(
          testResult, executionResultInfo.program, executionResultInfo.edit);
      if (testResult.isPass()) {
        best = executionResultInfo;
      }
    }
    return Optional.ofNullable(best);
  }

  private final ArrayList<FutureExecutionResultInfo> asyncApplyEditsInOrderOfProgramSizeFromLeast(
      List<? extends AbstractSparTreeEdit> editList) {
    final ArrayList<FutureExecutionResultInfo> futureList = new ArrayList<>(editList.size());
    editList.stream()
        .sorted()
        .filter(
            edit -> {
              assert !edit.isEmpty() : "Edit cannot be empty.";
              final TokenizedProgram program = edit.getProgram();
              final Optional<TestResult> cachedResult = queryCache.getCachedResult(program);
              if (cachedResult.isPresent()) {
                assert !cachedResult.get().isPass() : "It should be failure all the time.";
                listenerManager.onTestResultCacheHit(cachedResult.get(), program, edit);
                return false;
              } else {
                return true;
              }
            })
        .forEach(
            edit -> {
              assert !edit.isEmpty() : "Edit cannot be empty.";
              final TokenizedProgram program = edit.getProgram();
              final FutureTestScriptExecutionTask future = testProgramAsynchronously(program);
              futureList.add(new FutureExecutionResultInfo(edit, program, future));
            });
    return futureList;
  }

  public final void reduce(ReductionState state)
      throws IOException, ExecutionException, InterruptedException {
    final SparTree tree = state.getSparTree();
    assert SparTreeSimplifier.assertSingleEntrySingleExitPathProperty(tree.getRoot());
    internalReduce(tree);
  }

  protected abstract void internalReduce(SparTree tree)
      throws IOException, ExecutionException, InterruptedException;
}
