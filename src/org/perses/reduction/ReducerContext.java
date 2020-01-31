package org.perses.reduction;

import org.perses.tree.spar.AbstractNodeActionSetCache;

public final class ReducerContext {

  public final ReductionConfiguration configuration;
  public final TestScriptExecutorService executorService;
  public final ReductionListenerManager listenerManager;

  public final AbstractTestScriptExecutionCache queryCache;
  public final AbstractNodeActionSetCache nodeActionSetCache;
  public final AbstractActionSetProfiler actionSetProfiler;

  public ReducerContext(
      ReductionConfiguration configuration,
      TestScriptExecutorService executorService,
      ReductionListenerManager listenerManager,
      AbstractTestScriptExecutionCache queryCache,
      AbstractNodeActionSetCache nodeActionSetCache,
      AbstractActionSetProfiler actionSetProfiler) {
    this.configuration = configuration;
    this.executorService = executorService;
    this.listenerManager = listenerManager;
    this.queryCache = queryCache;
    this.nodeActionSetCache = nodeActionSetCache;
    this.actionSetProfiler = actionSetProfiler;
  }
}
