package org.perses.reduction;

import com.google.common.collect.ImmutableList;
import org.perses.program.TokenizedProgram;
import org.perses.reduction.AbstractReductionEvent.NodeEditActionSetCacheClearanceEvent;
import org.perses.reduction.AbstractReductionEvent.ReductionStartEvent;
import org.perses.tree.spar.AbstractActionSet;
import org.perses.tree.spar.AbstractSparTreeEdit;
import org.perses.tree.spar.AbstractSparTreeNode;
import org.perses.tree.spar.AbstractUnmodifiableSparTree;

public final class ReductionListenerManager {

  private final ImmutableList<AbstractReductionListener> listeners;

  public ReductionListenerManager(ImmutableList<AbstractReductionListener> listeners) {
    this.listeners = listeners;
  }

  public void onReductionStart(AbstractUnmodifiableSparTree tree, int programSize) {
    final ReductionStartEvent event =
        new ReductionStartEvent(System.currentTimeMillis(), tree, programSize);

    for (AbstractReductionListener listener : listeners) {
      listener.onReductionStart(event);
    }
  }

  public void onReductionEnd(int programSize, int countOfTestScriptExecutions) {
    final AbstractReductionEvent.ReductionEndEvent event =
        new AbstractReductionEvent.ReductionEndEvent(
            System.currentTimeMillis(), programSize, countOfTestScriptExecutions);

    for (AbstractReductionListener listener : listeners) {
      listener.onReductionEnd(event);
    }
  }

  public void onFixpointIterationStart(
      int iteration, int programSize, ReducerAnnotation reducerClass) {
    final AbstractReductionEvent.FixpointIterationStartEvent event =
        new AbstractReductionEvent.FixpointIterationStartEvent(
            System.currentTimeMillis(), programSize, iteration, reducerClass);
    for (AbstractReductionListener listener : listeners) {
      listener.onFixpointIterationStart(event);
    }
  }

  public void onFixpointIterationEnd(
      int iteration, int programSize, int countOfTestScriptExecutions) {
    final AbstractReductionEvent.FixpointIterationEndEvent event =
        new AbstractReductionEvent.FixpointIterationEndEvent(
            System.currentTimeMillis(), programSize, iteration, countOfTestScriptExecutions);
    for (AbstractReductionListener listener : listeners) {
      listener.onFixpointIterationEnd(event);
    }
  }

  public void onLevelReductionStart(int level, int nodeCountOnLevel, int programSize) {
    final AbstractReductionEvent.LevelReductionStartEvent event =
        new AbstractReductionEvent.LevelReductionStartEvent(
            System.currentTimeMillis(), programSize, level, nodeCountOnLevel);
    for (AbstractReductionListener listener : listeners) {
      listener.onLevelReductionStart(event);
    }
  }

  public void onLevelReductionEnd(int level, int programSize) {
    final AbstractReductionEvent.LevelReductionEndEvent event =
        new AbstractReductionEvent.LevelReductionEndEvent(
            System.currentTimeMillis(), programSize, level);
    for (AbstractReductionListener listener : listeners) {
      listener.onLevelReductionEnd(event);
    }
  }

  public void onLevelGranularityReductionStart(int maxNumOfNodesPerPartition, int programSize) {
    final AbstractReductionEvent.LevelGranularityReductionStartEvent event =
        new AbstractReductionEvent.LevelGranularityReductionStartEvent(
            System.currentTimeMillis(), programSize, maxNumOfNodesPerPartition);
    for (AbstractReductionListener listener : listeners) {
      listener.onLevelGranularityReductionStart(event);
    }
  }

  public void onLevelGranularityReductionEnd(int maxNumOfNodesPerPartition, int programSize) {
    final AbstractReductionEvent.LevelGranularityReductionEndEvent event =
        new AbstractReductionEvent.LevelGranularityReductionEndEvent(
            System.currentTimeMillis(), programSize, maxNumOfNodesPerPartition);
    for (AbstractReductionListener listener : listeners) {
      listener.onLevelGranularityReductionEnd(event);
    }
  }

  public void onNodeReductionStart(
      AbstractUnmodifiableSparTree tree, AbstractSparTreeNode node, int programSize) {
    final AbstractReductionEvent.NodeReductionStartEvent event =
        new AbstractReductionEvent.NodeReductionStartEvent(
            System.currentTimeMillis(), programSize, tree, node);
    for (AbstractReductionListener listener : listeners) {
      listener.onNodeReductionStart(event);
    }
  }

  public void onNodeReductionEnd(
      AbstractUnmodifiableSparTree tree,
      AbstractSparTreeNode node,
      int remainingQueueSize,
      int programSize) {
    final AbstractReductionEvent.NodeReductionEndEvent event =
        new AbstractReductionEvent.NodeReductionEndEvent(
            System.currentTimeMillis(), programSize, tree, node, remainingQueueSize);
    for (AbstractReductionListener listener : listeners) {
      listener.onNodeReductionEnd(event);
    }
  }

  public void onTestScriptExecution(
      TestScript.TestResult result, TokenizedProgram program, AbstractSparTreeEdit edit) {
    final AbstractReductionEvent.TestScriptExecutionEvent event =
        new AbstractReductionEvent.TestScriptExecutionEvent(
            System.currentTimeMillis(), result, program, edit);
    for (AbstractReductionListener listener : listeners) {
      listener.onTestScriptExecution(event);
    }
  }

  public void onTestScriptExecutionCancelled(
      TokenizedProgram program, AbstractSparTreeEdit edit, int millisToCancelTheTask) {
    final AbstractReductionEvent.TestScriptExecutionCanceledEvent event =
        new AbstractReductionEvent.TestScriptExecutionCanceledEvent(
            System.currentTimeMillis(), millisToCancelTheTask, program, edit);
    for (AbstractReductionListener listener : listeners) {
      listener.onTestScriptExecutionCancelled(event);
    }
  }

  public void onTestResultCacheHit(
      TestScript.TestResult result, TokenizedProgram program, AbstractSparTreeEdit edit) {
    final AbstractReductionEvent.TestResultCacheHitEvent event =
        new AbstractReductionEvent.TestResultCacheHitEvent(
            System.currentTimeMillis(), result, program, edit);
    for (AbstractReductionListener listener : listeners) {
      listener.onTestResultCacheHit(event);
    }
  }

  public void onNodeEditActionSetCacheHit(AbstractActionSet<?> query) {
    final AbstractReductionEvent.NodeEditActionSetCacheHitEvent event =
        new AbstractReductionEvent.NodeEditActionSetCacheHitEvent(
            System.currentTimeMillis(), query);
    for (AbstractReductionListener listener : listeners) {
      listener.onNodeEditActionSetCacheHit(event);
    }
  }

  public void onTestScriptExecutionCacheEntryEviction(int sizeBefore, int sizeAfter) {

    AbstractReductionEvent.TestScriptExecutionCacheEntryEvictionEvent event =
        new AbstractReductionEvent.TestScriptExecutionCacheEntryEvictionEvent(
            System.currentTimeMillis(), sizeBefore, sizeAfter);
    for (AbstractReductionListener listener : listeners) {
      listener.onTestScriptExecutionCacheEntryEviction(event);
    }
  }

  public void onNodeActionSetClearance(int cacheSizeBefore) {
    NodeEditActionSetCacheClearanceEvent event =
        new NodeEditActionSetCacheClearanceEvent(System.currentTimeMillis(), cacheSizeBefore);
    for (AbstractReductionListener listener : listeners) {
      listener.onNodeActionSetCacheClearance(event);
    }
  }
}
