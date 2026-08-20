/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
 */
package org.perses.ui

import com.fasterxml.jackson.databind.ObjectMapper
import com.google.common.flogger.FluentLogger
import org.perses.reduction.AbstractReductionListener
import org.perses.reduction.event.AbstractTestScriptExecutionEvent
import org.perses.reduction.event.AdHocMessageEvent
import org.perses.reduction.event.BestProgramUpdateEvent
import org.perses.reduction.event.FixpointIterationEndEvent
import org.perses.reduction.event.FixpointIterationStartEvent
import org.perses.reduction.event.ReductionEndEvent
import org.perses.reduction.event.ReductionSkippedEvent
import org.perses.reduction.event.ReductionStartEvent
import org.perses.util.ktInfo
import java.util.IdentityHashMap
import java.util.concurrent.atomic.AtomicLong

/**
 * A reduction listener that renders live progress as a local web dashboard.
 *
 * Optional and side-effect-free with respect to the reduction itself: it only reads event
 * payloads and pushes them to connected browsers over SSE (see [SseServer]). It is wired in
 * exactly like [org.perses.listener.LoggingListener] and enabled by a command-line flag.
 *
 * The per-reducer-invocation counting mirrors
 * [org.perses.listener.ReducerStatisticsSummaryListener] so the live tables show the same
 * numbers that listener prints at the end of the run; see that class for the rationale behind
 * each column (Worked/#NonDeletions/Queries counting). The per-reducer Summary and per-
 * transformation tables are aggregated in the browser from the streamed invocation and commit
 * records, so only the raw per-event data is sent here.
 *
 * Threading: every `on*` callback runs on the single dispatch thread of
 * [org.perses.reduction.AsyncReductionListenerManager], so the counters below are only ever
 * touched from that one thread; the [AtomicLong]s exist purely so values published in frames
 * are read consistently. Test-script executions are the highest-frequency event, so their
 * per-execution frame is throttled instead of emitted one-for-one.
 */
class WebUiListener(
  private val sink: ReductionEventSink,
) : AbstractReductionListener() {
  private val json = ObjectMapper()

  private val executions = AtomicLong(0)
  private val cacheHits = AtomicLong(0)
  private val lastProgressMillis = AtomicLong(0)

  private class InFlightCounts {
    var committedEdits = 0L
    var nonDeletionEdits = 0L
    var completedTestExecutions = 0L
  }

  private val countsByStartEvent = IdentityHashMap<FixpointIterationStartEvent, InFlightCounts>()
  private var currentInFlight: FixpointIterationStartEvent? = null
  private var invocationId = 0

  override fun onReductionStart(event: ReductionStartEvent) {
    send(
      "reduction-start",
      mapOf(
        "timeMillis" to event.currentTimeMillis,
        "initialTokens" to event.perFileSizeMetrics.totalCanonicalTokenCount,
        "initialChars" to event.perFileSizeMetrics.totalCharacterCount,
      ),
    )
  }

  override fun onFixpointIterationStart(event: FixpointIterationStartEvent) {
    countsByStartEvent[event] = InFlightCounts()
    currentInFlight = event
    send(
      "fixpoint",
      mapOf(
        "timeMillis" to event.currentTimeMillis,
        "iteration" to event.iteration,
        "reducer" to event.reducerClass.shortName,
        "tokens" to event.perFileSizeMetrics.totalCanonicalTokenCount,
      ),
    )
  }

  override fun onBestProgramUpdated(event: BestProgramUpdateEvent) {
    val isNonDeletion =
      event.programSizeAfter.canonicalTokenCount >= event.programSizeBefore.canonicalTokenCount
    val counts = countsByStartEvent.getOrPut(event.currentFixpointIteration) { InFlightCounts() }
    counts.committedEdits += 1
    if (isNonDeletion) {
      counts.nonDeletionEdits += 1
    }
    send(
      "best-update",
      mapOf(
        "timeMillis" to event.currentTimeMillis,
        "tokens" to event.perFileSizeMetrics.totalCanonicalTokenCount,
        "chars" to event.perFileSizeMetrics.totalCharacterCount,
        "deleted" to
          (event.programSizeBefore.canonicalTokenCount - event.programSizeAfter.canonicalTokenCount),
        "nonBlankDelta" to
          (
            event.programSizeAfter.nonBlankCharacterCount -
              event.programSizeBefore.nonBlankCharacterCount
          ),
        "transformation" to event.appliedEdit.actionSet.transformationName,
        "iteration" to event.currentFixpointIteration.iteration,
        "reducer" to event.currentFixpointIteration.reducerClass.shortName,
      ),
    )
  }

  override fun onFixpointIterationEnd(event: FixpointIterationEndEvent) {
    val startEvent = event.startEvent
    val sizeBefore = startEvent.perFileSizeMetrics
    val sizeAfter = event.perFileSizeMetrics
    val counts = countsByStartEvent.remove(startEvent) ?: InFlightCounts()
    currentInFlight = null
    send(
      "reducer-invocation",
      mapOf(
        "id" to invocationId++,
        "timeMillis" to event.currentTimeMillis,
        "reducer" to startEvent.reducerClass.shortName,
        "worked" to counts.committedEdits,
        "nonDeletions" to counts.nonDeletionEdits,
        "tokens" to (sizeAfter.totalCanonicalTokenCount - sizeBefore.totalCanonicalTokenCount),
        "nonBlankChars" to
          (sizeAfter.totalNonBlankCharacterCount - sizeBefore.totalNonBlankCharacterCount),
        "queries" to counts.completedTestExecutions,
        "durationMillis" to (event.currentTimeMillis - startEvent.currentTimeMillis),
      ),
    )
  }

  override fun onTestScriptExecution(
    event: AbstractTestScriptExecutionEvent.TestScriptExecutionEvent,
  ) {
    executions.incrementAndGet()
    currentInFlight?.let { countsByStartEvent.getValue(it).completedTestExecutions += 1 }
    maybeSendProgress(event.currentTimeMillis)
  }

  override fun onTestResultCacheHit(
    event: AbstractTestScriptExecutionEvent.TestResultCacheHitEvent,
  ) {
    cacheHits.incrementAndGet()
    maybeSendProgress(event.currentTimeMillis)
  }

  override fun onAdHocMessageEvent(event: AdHocMessageEvent) {
    val prefix = event.prefixLabelFromRootToHere
    val text = if (prefix.isBlank()) event.message else "$prefix ${event.message}"
    send("log", mapOf("message" to text))
  }

  override fun onReductionSkipped(event: ReductionSkippedEvent) {
    send("log", mapOf("message" to "${event.prefixLabelFromRootToHere} skipped: ${event.message}"))
  }

  override fun onReductionEnd(event: ReductionEndEvent) {
    send(
      "reduction-end",
      mapOf(
        "timeMillis" to event.currentTimeMillis,
        "finalTokens" to event.perFileSizeMetrics.totalCanonicalTokenCount,
        "initialTokens" to event.startEvent.perFileSizeMetrics.totalCanonicalTokenCount,
        "elapsedMillis" to (event.currentTimeMillis - event.startEvent.currentTimeMillis),
        "executions" to event.testScriptExecutorServiceStatistics.scriptExecutionNumber,
      ),
    )
  }

  private fun maybeSendProgress(nowMillis: Long) {
    val previous = lastProgressMillis.get()
    if (nowMillis - previous < PROGRESS_THROTTLE_MILLIS) {
      return
    }
    if (!lastProgressMillis.compareAndSet(previous, nowMillis)) {
      return
    }
    send(
      "progress",
      mapOf(
        "timeMillis" to nowMillis,
        "executions" to executions.get(),
        "cacheHits" to cacheHits.get(),
      ),
    )
  }

  private fun send(eventName: String, payload: Map<String, Any?>) {
    sink.broadcast(eventName, json.writeValueAsString(payload))
  }

  override fun close() {
    sink.close()
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
    private const val PROGRESS_THROTTLE_MILLIS = 250L

    /** Wires the listener to a live [SseServer] on the given port and announces the URL. */
    fun create(requestedPort: Int): WebUiListener {
      val server = SseServer(requestedPort, DashboardHtml.PAGE)
      val url = "http://127.0.0.1:${server.port}"
      logger.ktInfo { "Reduction UI available at $url" }
      println("Perses reduction UI: $url")
      return WebUiListener(server)
    }
  }
}
