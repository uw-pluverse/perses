package org.perses.reduction

import org.perses.tree.spar.AbstractNodeActionSetCache

class ReducerContext(
    val configuration: ReductionConfiguration,
    val executorService: TestScriptExecutorService,
    val listenerManager: ReductionListenerManager,
    val queryCache: AbstractTestScriptExecutionCache,
    val nodeActionSetCache: AbstractNodeActionSetCache,
    val actionSetProfiler: AbstractActionSetProfiler)