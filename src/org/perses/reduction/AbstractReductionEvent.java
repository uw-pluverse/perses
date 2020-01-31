package org.perses.reduction;

import org.perses.program.TokenizedProgram;
import org.perses.tree.spar.AbstractActionSet;
import org.perses.tree.spar.AbstractSparTreeEdit;
import org.perses.tree.spar.AbstractSparTreeNode;
import org.perses.tree.spar.AbstractUnmodifiableSparTree;

public abstract class AbstractReductionEvent {

  private final long currentTimeMillis;

  public AbstractReductionEvent(long currentTimeMillis) {
    this.currentTimeMillis = currentTimeMillis;
  }

  public final long getCurrentTimeMillis() {
    return currentTimeMillis;
  }

  public abstract static class AbstractReductionEventWithProgramSize
      extends AbstractReductionEvent {

    private final int programSize;

    public AbstractReductionEventWithProgramSize(long currentTimeMillis, int programSize) {
      super(currentTimeMillis);
      this.programSize = programSize;
    }

    public final int getProgramSize() {
      return programSize;
    }
  }

  public static final class ReductionStartEvent extends AbstractReductionEventWithProgramSize {

    private final AbstractUnmodifiableSparTree tree;

    public ReductionStartEvent(
        long currentTimeMillis, AbstractUnmodifiableSparTree tree, int programSize) {
      super(currentTimeMillis, programSize);
      this.tree = tree;
    }

    public AbstractUnmodifiableSparTree getTree() {
      return tree;
    }
  }

  public static final class ReductionEndEvent extends AbstractReductionEventWithProgramSize {

    private final int countOfTestScriptExecutions;

    public ReductionEndEvent(
        long currentTimeMillis, int programSize, int countOfTestScriptExecutions) {
      super(currentTimeMillis, programSize);
      this.countOfTestScriptExecutions = countOfTestScriptExecutions;
    }

    public int getCountOfTestScriptExecutions() {
      return countOfTestScriptExecutions;
    }
  }

  public static final class FixpointIterationStartEvent
      extends AbstractReductionEventWithProgramSize {

    private final int iteration;
    private final ReducerAnnotation reducerClass;

    public FixpointIterationStartEvent(
        long currentTimeMillis, int programSize, int iteration, ReducerAnnotation reducerClass) {
      super(currentTimeMillis, programSize);
      this.iteration = iteration;
      this.reducerClass = reducerClass;
    }

    public int getIteration() {
      return iteration;
    }

    public ReducerAnnotation getReducerClass() {
      return reducerClass;
    }
  }

  public static final class FixpointIterationEndEvent
      extends AbstractReductionEventWithProgramSize {

    private final int iteration;
    private final int countOfTestScriptExecutions;

    public FixpointIterationEndEvent(
        long currentTimeMillis, int programSize, int iteration, int countOfTestScriptExecutions) {
      super(currentTimeMillis, programSize);
      this.iteration = iteration;
      this.countOfTestScriptExecutions = countOfTestScriptExecutions;
    }

    public int getIteration() {
      return iteration;
    }

    public int getCountOfTestScriptExecutions() {
      return countOfTestScriptExecutions;
    }
  }

  public static final class LevelReductionStartEvent extends AbstractReductionEventWithProgramSize {
    private final int level;
    private final int nodeCountOnLevel;

    public LevelReductionStartEvent(
        long currentTimeMillis, int programSize, int level, int nodeCountOnLevel) {
      super(currentTimeMillis, programSize);
      this.level = level;
      this.nodeCountOnLevel = nodeCountOnLevel;
    }

    public int getLevel() {
      return level;
    }

    public int getNodeCountOnLevel() {
      return nodeCountOnLevel;
    }
  }

  public static final class LevelReductionEndEvent extends AbstractReductionEventWithProgramSize {

    private final int level;

    public LevelReductionEndEvent(long currentTimeMillis, int programSize, int level) {
      super(currentTimeMillis, programSize);
      this.level = level;
    }

    public int getLevel() {
      return level;
    }
  }

  public static final class LevelGranularityReductionStartEvent
      extends AbstractReductionEventWithProgramSize {

    private final int maxNumOfNodesPerPartition;

    public LevelGranularityReductionStartEvent(
        long currentTimeMillis, int programSize, int maxNumOfNodesPerPartition) {
      super(currentTimeMillis, programSize);
      this.maxNumOfNodesPerPartition = maxNumOfNodesPerPartition;
    }

    public int getMaxNumOfNodesPerPartition() {
      return maxNumOfNodesPerPartition;
    }
  }

  public static final class LevelGranularityReductionEndEvent
      extends AbstractReductionEventWithProgramSize {

    private final int maxNumOfNodesPerPartition;

    public LevelGranularityReductionEndEvent(
        long currentTimeMillis, int programSize, int maxNumOfNodesPerPartition) {
      super(currentTimeMillis, programSize);
      this.maxNumOfNodesPerPartition = maxNumOfNodesPerPartition;
    }

    public int getMaxNumOfNodesPerPartition() {
      return maxNumOfNodesPerPartition;
    }
  }

  public static final class NodeReductionStartEvent extends AbstractReductionEventWithProgramSize {

    private final AbstractUnmodifiableSparTree tree;
    private final AbstractSparTreeNode node;

    public NodeReductionStartEvent(
        long currentTimeMillis,
        int programSize,
        AbstractUnmodifiableSparTree tree,
        AbstractSparTreeNode node) {
      super(currentTimeMillis, programSize);
      this.tree = tree;
      this.node = node;
    }

    public AbstractUnmodifiableSparTree getTree() {
      return tree;
    }

    public AbstractSparTreeNode getNode() {
      return node;
    }
  }

  public static final class NodeReductionEndEvent extends AbstractReductionEventWithProgramSize {

    private final AbstractUnmodifiableSparTree tree;
    private final AbstractSparTreeNode node;
    private final int remainingQueueSize;

    public NodeReductionEndEvent(
        long currentTimeMillis,
        int programSize,
        AbstractUnmodifiableSparTree tree,
        AbstractSparTreeNode node,
        int remainingQueueSize) {
      super(currentTimeMillis, programSize);
      this.tree = tree;
      this.node = node;
      this.remainingQueueSize = remainingQueueSize;
    }

    public AbstractUnmodifiableSparTree getTree() {
      return tree;
    }

    public AbstractSparTreeNode getNode() {
      return node;
    }

    public int getRemainingQueueSize() {
      return remainingQueueSize;
    }
  }

  public static final class TestScriptExecutionCacheEntryEvictionEvent
      extends AbstractReductionEvent {

    private final int sizeBefore;
    private final int sizeAfter;

    public TestScriptExecutionCacheEntryEvictionEvent(
        long currentTimeMillis, int sizeBefore, int sizeAfter) {
      super(currentTimeMillis);
      this.sizeBefore = sizeBefore;
      this.sizeAfter = sizeAfter;
    }

    public int getSizeAfter() {
      return sizeAfter;
    }

    public int getSizeBefore() {
      return sizeBefore;
    }
  }

  public static final class TestScriptExecutionEvent extends AbstractReductionEvent {

    private final TestScript.TestResult result;
    private final TokenizedProgram program;
    private final AbstractSparTreeEdit edit;

    public TestScriptExecutionEvent(
        long currentTimeMillis,
        TestScript.TestResult result,
        TokenizedProgram program,
        AbstractSparTreeEdit edit) {
      super(currentTimeMillis);
      this.result = result;
      this.program = program;
      this.edit = edit;
    }

    public TestScript.TestResult getResult() {
      return result;
    }

    public TokenizedProgram getProgram() {
      return program;
    }

    public AbstractSparTreeEdit getEdit() {
      return edit;
    }
  }

  public static final class TestScriptExecutionCanceledEvent extends AbstractReductionEvent {

    private final int millisToCancelTheTask;
    private final TokenizedProgram program;
    private final AbstractSparTreeEdit edit;

    public TestScriptExecutionCanceledEvent(
        long currentTimeMillis,
        int millisToCancelTheTask,
        TokenizedProgram program,
        AbstractSparTreeEdit edit) {
      super(currentTimeMillis);
      this.millisToCancelTheTask = millisToCancelTheTask;
      this.program = program;
      this.edit = edit;
    }

    public int getMillisToCancelTheTask() {
      return millisToCancelTheTask;
    }

    public TokenizedProgram getProgram() {
      return program;
    }

    public AbstractSparTreeEdit getEdit() {
      return edit;
    }
  }

  public static final class TestResultCacheHitEvent extends AbstractReductionEvent {

    private final TestScript.TestResult result;
    private final TokenizedProgram program;
    private final AbstractSparTreeEdit edit;

    public TestResultCacheHitEvent(
        long currentTimeMillis,
        TestScript.TestResult result,
        TokenizedProgram program,
        AbstractSparTreeEdit edit) {
      super(currentTimeMillis);
      this.result = result;
      this.program = program;
      this.edit = edit;
    }

    public TestScript.TestResult getResult() {
      return result;
    }

    public TokenizedProgram getProgram() {
      return program;
    }

    public AbstractSparTreeEdit getEdit() {
      return edit;
    }
  }

  public static final class NodeEditActionSetCacheHitEvent extends AbstractReductionEvent {

    private final AbstractActionSet<?> query;

    public NodeEditActionSetCacheHitEvent(long currentTimeMillis, AbstractActionSet<?> query) {
      super(currentTimeMillis);
      this.query = query;
    }

    public AbstractActionSet<?> getQuery() {
      return query;
    }
  }

  public static final class NodeEditActionSetCacheClearanceEvent extends AbstractReductionEvent {

    private final int originalEntrySize;

    public NodeEditActionSetCacheClearanceEvent(long currentTimeMillis, int originalEntrySize) {
      super(currentTimeMillis);
      this.originalEntrySize = originalEntrySize;
    }

    public int getOriginalEntrySize() {
      return originalEntrySize;
    }
  }
}
