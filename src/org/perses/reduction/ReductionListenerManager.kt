package org.perses.reduction

import com.google.common.collect.ImmutableList
import org.perses.program.TokenizedProgram
import org.perses.reduction.AbstractReductionEvent.*
import org.perses.tree.spar.AbstractActionSet
import org.perses.tree.spar.AbstractSparTreeEdit
import org.perses.tree.spar.AbstractSparTreeNode
import org.perses.tree.spar.AbstractUnmodifiableSparTree

class ReductionListenerManager(private val listeners: ImmutableList<AbstractReductionListener>) {
  fun onReductionStart(tree: AbstractUnmodifiableSparTree?, programSize: Int) {
    val event = ReductionStartEvent(System.currentTimeMillis(), tree!!, programSize)
    for (listener in listeners) {
      listener.onReductionStart(event)
    }
  }

  fun onReductionEnd(programSize: Int, countOfTestScriptExecutions: Int) {
    val event = ReductionEndEvent(
        System.currentTimeMillis(), programSize, countOfTestScriptExecutions)
    for (listener in listeners) {
      listener.onReductionEnd(event)
    }
  }

  fun onFixpointIterationStart(
      iteration: Int, programSize: Int, reducerClass: ReducerAnnotation?) {
    val event = FixpointIterationStartEvent(
        System.currentTimeMillis(), programSize, iteration, reducerClass!!)
    for (listener in listeners) {
      listener.onFixpointIterationStart(event)
    }
  }

  fun onFixpointIterationEnd(
      iteration: Int, programSize: Int, countOfTestScriptExecutions: Int) {
    val event = FixpointIterationEndEvent(
        System.currentTimeMillis(), programSize, iteration, countOfTestScriptExecutions)
    for (listener in listeners) {
      listener.onFixpointIterationEnd(event)
    }
  }

  fun onLevelReductionStart(level: Int, nodeCountOnLevel: Int, programSize: Int) {
    val event = LevelReductionStartEvent(
        System.currentTimeMillis(), programSize, level, nodeCountOnLevel)
    for (listener in listeners) {
      listener.onLevelReductionStart(event)
    }
  }

  fun onLevelReductionEnd(level: Int, programSize: Int) {
    val event = LevelReductionEndEvent(
        System.currentTimeMillis(), programSize, level)
    for (listener in listeners) {
      listener.onLevelReductionEnd(event)
    }
  }

  fun onLevelGranularityReductionStart(maxNumOfNodesPerPartition: Int, programSize: Int) {
    val event = LevelGranularityReductionStartEvent(
        System.currentTimeMillis(), programSize, maxNumOfNodesPerPartition)
    for (listener in listeners) {
      listener.onLevelGranularityReductionStart(event)
    }
  }

  fun onLevelGranularityReductionEnd(maxNumOfNodesPerPartition: Int, programSize: Int) {
    val event = LevelGranularityReductionEndEvent(
        System.currentTimeMillis(), programSize, maxNumOfNodesPerPartition)
    for (listener in listeners) {
      listener.onLevelGranularityReductionEnd(event)
    }
  }

  fun onNodeReductionStart(
      tree: AbstractUnmodifiableSparTree?, node: AbstractSparTreeNode?, programSize: Int) {
    val event = NodeReductionStartEvent(
        System.currentTimeMillis(), programSize, tree!!, node!!)
    for (listener in listeners) {
      listener.onNodeReductionStart(event)
    }
  }

  fun onNodeReductionEnd(
      tree: AbstractUnmodifiableSparTree?,
      node: AbstractSparTreeNode?,
      remainingQueueSize: Int,
      programSize: Int) {
    val event = NodeReductionEndEvent(
        System.currentTimeMillis(), programSize, tree!!, node!!, remainingQueueSize)
    for (listener in listeners) {
      listener.onNodeReductionEnd(event)
    }
  }

  fun onTestScriptExecution(
      result: TestScript.TestResult?, program: TokenizedProgram?, edit: AbstractSparTreeEdit?) {
    val event = TestScriptExecutionEvent(
        System.currentTimeMillis(), result!!, program!!, edit!!)
    for (listener in listeners) {
      listener.onTestScriptExecution(event)
    }
  }

  fun onTestScriptExecutionCancelled(
      program: TokenizedProgram?, edit: AbstractSparTreeEdit?, millisToCancelTheTask: Int) {
    val event = TestScriptExecutionCanceledEvent(
        System.currentTimeMillis(), millisToCancelTheTask, program!!, edit!!)
    for (listener in listeners) {
      listener.onTestScriptExecutionCancelled(event)
    }
  }

  fun onTestResultCacheHit(
      result: TestScript.TestResult?, program: TokenizedProgram?, edit: AbstractSparTreeEdit?) {
    val event = TestResultCacheHitEvent(
        System.currentTimeMillis(), result!!, program!!, edit!!)
    for (listener in listeners) {
      listener.onTestResultCacheHit(event)
    }
  }

  fun onNodeEditActionSetCacheHit(query: AbstractActionSet<*>?) {
    val event = NodeEditActionSetCacheHitEvent(
        System.currentTimeMillis(), query!!)
    for (listener in listeners) {
      listener.onNodeEditActionSetCacheHit(event)
    }
  }

  fun onTestScriptExecutionCacheEntryEviction(sizeBefore: Int, sizeAfter: Int) {
    val event = TestScriptExecutionCacheEntryEvictionEvent(
        System.currentTimeMillis(), sizeBefore, sizeAfter)
    for (listener in listeners) {
      listener.onTestScriptExecutionCacheEntryEviction(event)
    }
  }

  fun onNodeActionSetClearance(cacheSizeBefore: Int) {
    val event = NodeEditActionSetCacheClearanceEvent(System.currentTimeMillis(), cacheSizeBefore)
    for (listener in listeners) {
      listener.onNodeActionSetCacheClearance(event)
    }
  }

}