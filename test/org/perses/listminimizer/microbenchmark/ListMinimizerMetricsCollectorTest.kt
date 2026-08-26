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
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
package org.perses.listminimizer.microbenchmark

import com.fasterxml.jackson.core.type.TypeReference
import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.listminimizer.AbstractListMinimizerTest
import org.perses.listminimizer.Candidate
import org.perses.listminimizer.ElementWrapper
import org.perses.listminimizer.IWeightProvider
import org.perses.listminimizer.ListMinimizerArguments
import org.perses.listminimizer.PristineDeltaDebugger
import org.perses.reduction.CandidateOutcome
import org.perses.reduction.TestScriptVerdict
import org.perses.util.FileSystemUtil
import org.perses.util.Serialization
import org.perses.util.shell.ExitCode
import java.nio.file.Path
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readLines

@RunWith(JUnit4::class)
class ListMinimizerMetricsCollectorTest : AbstractListMinimizerTest<String>() {
  private val workDir = FileSystemUtil.createTempDirForObject(this)

  private val queryJsonlFile = workDir.resolve(ListMinimizerMetricsCollector.QUERY_JSONL_FILE_NAME)

  private val summaryJsonlFile =
    workDir.resolve(
      ListMinimizerMetricsCollector.SUMMARY_JSONL_FILE_NAME,
    )

  private val wrappers =
    ImmutableList.copyOf(
      (0 until 6).map { ElementWrapper(index = it, element = "e$it", elementPayload = Unit) },
    )

  @After
  fun teardown() {
    workDir.deleteRecursively()
  }

  private fun createCollector(
    weightProvider: IWeightProvider<Any> = IWeightProvider { 1 },
    hideTimings: Boolean = false,
    // The executor's cumulative total, which the collector brackets across the minimizer's run.
    scriptExecutionCounter: () -> Int = { 0 },
  ) = ListMinimizerMetricsCollector(
    microbenchmarkId = "000042",
    weightProvider = weightProvider,
    hideTimings = hideTimings,
    minimizerTypeName = "PRISTINE_DDMIN",
    scriptExecutionCountSupplier = scriptExecutionCounter,
    queryJsonlFile = queryJsonlFile,
    summaryJsonlFile = summaryJsonlFile,
  )

  private fun candidateDeleting(vararg indices: Int) =
    Candidate.DeletionsFromOriginal(
      original = wrappers,
      deleted_ = ImmutableList.copyOf(indices.map { wrappers[it] }),
    )

  /** A query whose oracle actually ran: interesting on [ExitCode.ZERO], rejected otherwise. */
  private fun tested(
    exitCode: ExitCode,
    elapsedMillis: Int = 0,
  ): CandidateOutcome<String> {
    val testScriptVerdict =
      TestScriptVerdict(exitCode = exitCode, elapsedMillis = elapsedMillis)
    return if (testScriptVerdict.isInteresting) {
      CandidateOutcome.Interesting("", testScriptVerdict)
    } else {
      CandidateOutcome.Uninteresting.Rejected(testScriptVerdict)
    }
  }

  /** Every record of a JSON Lines file, in order, each as a field name to value map. */
  private fun recordsOf(file: Path): List<Map<String, Any?>> =
    file
      .readLines()
      .filter { it.isNotBlank() }
      .map {
        Serialization.fromJsonString(it, object : TypeReference<Map<String, Any?>>() {})
      }

  private fun fieldNamesOf(file: Path) = recordsOf(file = file).first().keys.toList()

  /**
   * One field across every record, rendered as a string. Kept string-valued so the assertions read
   * as they did over CSV; an absent field fails rather than silently yielding an empty column.
   */
  private fun valuesOf(
    file: Path,
    fieldName: String,
  ): List<String> =
    recordsOf(file = file).map { record ->
      assertThat(record).containsKey(fieldName)
      record[fieldName]?.toString() ?: ""
    }

  private fun startAndEnd(body: ListMinimizerMetricsCollector.() -> Unit) {
    createCollector().use { collector ->
      collector.startReduction(
        originalInput = wrappers,
        listMinimizerClass = PristineDeltaDebugger::class,
        descriptionPrefix = "prefix",
      )
      collector.body()
      collector.endReduction(
        minimizationResult = wrappers,
        listMinimizerClass = PristineDeltaDebugger::class,
        sizeOfOriginalInput = wrappers.size,
      )
    }
  }

  @Test
  fun testEveryQueryOfARealMinimizerBecomesExactlyOneRow() {
    val testHistory = mutableListOf<String>()
    val input = ImmutableList.copyOf(wrappers.map { it.element })
    createCollector().use { collector ->
      val minimizer =
        PristineDeltaDebugger(
          arguments =
            ListMinimizerArguments(
              needToTestEmpty = true,
              input = input,
              isElementDeletedElsewhere = { false },
              propertyTester =
                createPropertyTester(property = listOf("e2"), testHistory = testHistory),
              onBestUpdateHandler = dummyHandler,
              descriptionPrefix = "prefix",
              listener = collector,
            ),
        )
      assertThat(minimizer.reduce()).containsExactly("e2")
    }
    assertThat(recordsOf(file = queryJsonlFile)).hasSize(testHistory.size)
    assertThat(valuesOf(file = queryJsonlFile, fieldName = "querySeq").map { it.toInt() })
      .isEqualTo((1..testHistory.size).toList())

    val summaryRecord = recordsOf(file = summaryJsonlFile).single()

    fun summary(fieldName: String) = summaryRecord[fieldName]?.toString() ?: ""
    assertThat(summary("microbenchmarkId")).isEqualTo("000042")
    assertThat(summary("minimizer")).isEqualTo(PristineDeltaDebugger::class.qualifiedName)
    assertThat(summary("originalElementCount")).isEqualTo("6")
    assertThat(summary("resultElementCount")).isEqualTo("1")
    assertThat(summary("totalQueries")).isEqualTo(testHistory.size.toString())
    assertThat(summary("interestingCount").toInt() + summary("uninterestingCount").toInt())
      .isEqualTo(testHistory.size)
  }

  @Test
  fun testDeletedRunCountCountsMaximalContiguousRuns() {
    startAndEnd {
      onPropertyTest(
        configuration = candidateDeleting(0, 1, 2),
        result = tested(exitCode = ExitCode.ONE),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
      onPropertyTest(
        configuration = candidateDeleting(0, 2, 4),
        result = tested(exitCode = ExitCode.ONE),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
      onPropertyTest(
        configuration = candidateDeleting(0, 1, 4, 5),
        result = tested(exitCode = ExitCode.ONE),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
    }
    assertThat(
      valuesOf(file = queryJsonlFile, fieldName = "deletedRunCount"),
    ).containsExactly("1", "3", "2").inOrder()
    assertThat(
      valuesOf(file = queryJsonlFile, fieldName = "deletedCount"),
    ).containsExactly("3", "3", "4").inOrder()
    assertThat(
      valuesOf(file = queryJsonlFile, fieldName = "minElementIndex"),
    ).containsExactly("0", "0", "0").inOrder()
    assertThat(
      valuesOf(file = queryJsonlFile, fieldName = "maxElementIndex"),
    ).containsExactly("2", "4", "5").inOrder()
  }

  @Test
  fun testOutcomeAndElapsedTimeComeFromTheTestScriptVerdict() {
    startAndEnd {
      onPropertyTest(
        configuration = candidateDeleting(0),
        result = tested(exitCode = ExitCode.ZERO, elapsedMillis = 11),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
      onPropertyTest(
        configuration = candidateDeleting(1),
        result = tested(exitCode = ExitCode.ONE, elapsedMillis = 22),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 5,
      )
    }
    assertThat(
      valuesOf(file = queryJsonlFile, fieldName = "outcome"),
    ).containsExactly("interesting", "uninteresting").inOrder()
    assertThat(
      valuesOf(file = queryJsonlFile, fieldName = "elapsedMillis"),
    ).containsExactly("11", "22").inOrder()
    assertThat(
      valuesOf(file = queryJsonlFile, fieldName = "bestSizeBefore"),
    ).containsExactly("6", "5").inOrder()
    assertThat(
      valuesOf(file = summaryJsonlFile, fieldName = "totalOracleMillis"),
    ).containsExactly("33")
    assertThat(
      valuesOf(file = summaryJsonlFile, fieldName = "interestingCount"),
    ).containsExactly("1")
    assertThat(
      valuesOf(file = summaryJsonlFile, fieldName = "uninterestingCount"),
    ).containsExactly("1")
  }

  @Test
  fun testAnUntestedQueryIsCountedAsUninterestingAndContributesNoOracleTime() {
    startAndEnd {
      onPropertyTest(
        configuration = candidateDeleting(0),
        result = tested(exitCode = ExitCode.ZERO, elapsedMillis = 11),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
      onPropertyTest(
        configuration = candidateDeleting(1),
        result = CandidateOutcome.Uninteresting.NotTested("Cached"),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
    }
    // A cache hit is an uninteresting outcome: the deletion did not survive, which is all a
    // minimizer acts on and all the outcome field claims to say.
    assertThat(
      valuesOf(file = queryJsonlFile, fieldName = "outcome"),
    ).containsExactly("interesting", "uninteresting").inOrder()
    // Blank, not zero: no script ran, and a zero would be averaged in as an instantaneous
    // execution.
    assertThat(
      valuesOf(file = queryJsonlFile, fieldName = "elapsedMillis"),
    ).containsExactly("11", "").inOrder()
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "uninterestingCount"))
      .containsExactly("1")
    assertThat(
      valuesOf(file = summaryJsonlFile, fieldName = "totalOracleMillis"),
    ).containsExactly("11")
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "totalQueries")).containsExactly("2")
  }

  @Test
  fun testARejectedCandidateReportsItsOracleTimeButAnUntestedOneDoesNot() {
    startAndEnd {
      onPropertyTest(
        configuration = candidateDeleting(0),
        result = tested(exitCode = ExitCode.ONE, elapsedMillis = 40),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
      onPropertyTest(
        configuration = candidateDeleting(1),
        result = CandidateOutcome.Uninteresting.NotTested("Cached"),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
      onPropertyTest(
        configuration = candidateDeleting(2),
        result =
          CandidateOutcome.Uninteresting.NotTested("NoEdit"),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
    }
    // All three did not survive, so all three are uninteresting -- but only the first spent a
    // script. Reporting a rejected candidate as free is what made totalOracleMillis a lower bound
    // over the interesting queries, which is the opposite of the queries a comparison is about.
    assertThat(
      valuesOf(file = queryJsonlFile, fieldName = "outcome"),
    ).containsExactly("uninteresting", "uninteresting", "uninteresting")
    assertThat(
      valuesOf(file = queryJsonlFile, fieldName = "elapsedMillis"),
    ).containsExactly("40", "", "").inOrder()
    assertThat(
      valuesOf(file = summaryJsonlFile, fieldName = "totalOracleMillis"),
    ).containsExactly("40")
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "interestingCount"))
      .containsExactly("0")
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "uninterestingCount"))
      .containsExactly("3")
  }

  @Test
  fun testWeightColumnsUseTheProviderRatherThanElementCount() {
    createCollector(weightProvider = IWeightProvider { (it as String).length }).use { collector ->
      val longWrappers =
        ImmutableList.copyOf(
          listOf("a", "bb", "ccc").mapIndexed { i, e ->
            ElementWrapper(index = i, element = e, elementPayload = Unit)
          },
        )
      collector.startReduction(
        originalInput = longWrappers,
        listMinimizerClass = PristineDeltaDebugger::class,
        descriptionPrefix = "prefix",
      )
      collector.onPropertyTest(
        configuration =
          Candidate.DeletionsFromOriginal(
            original = longWrappers,
            deleted_ = ImmutableList.of(longWrappers[1], longWrappers[2]),
          ),
        result = tested(exitCode = ExitCode.ONE),
        sizeOfOriginalList = 3,
        sizeOfCurrentMinimizationResult = 3,
      )
      collector.endReduction(
        minimizationResult = ImmutableList.of(longWrappers[0]),
        listMinimizerClass = PristineDeltaDebugger::class,
        sizeOfOriginalInput = longWrappers.size,
      )
    }
    assertThat(valuesOf(file = queryJsonlFile, fieldName = "deletedCount")).containsExactly("2")
    assertThat(valuesOf(file = queryJsonlFile, fieldName = "deletedWeight")).containsExactly("5")
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "originalWeight")).containsExactly("6")
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "resultWeight")).containsExactly("1")
  }

  @Test
  fun testQuerySeqOfLastBestUpdateSeparatesProgressFromConfirmation() {
    startAndEnd {
      onPropertyTest(
        configuration = candidateDeleting(0),
        result = tested(exitCode = ExitCode.ZERO),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
      onBestUpdate(wrappers.drop(1))
      onPropertyTest(
        configuration = candidateDeleting(1),
        result = tested(exitCode = ExitCode.ONE),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 5,
      )
      onPropertyTest(
        configuration = candidateDeleting(2),
        result = tested(exitCode = ExitCode.ONE),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 5,
      )
    }
    assertThat(
      valuesOf(file = summaryJsonlFile, fieldName = "querySeqOfLastBestUpdate"),
    ).containsExactly("1")
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "totalQueries")).containsExactly("3")
  }

  @Test
  fun testAValueContainingDelimitersStaysOnOneLineAndRoundTrips() {
    // The whole reason this is not a CSV. A comma or a quote silently corrupted a hand-joined row;
    // a raw newline would break JSON Lines' one-record-per-line invariant just as badly, so this
    // pins that JSON escaping -- not luck about which fields happen to be well behaved -- is what
    // keeps the format intact.
    val hostile = "a,b\"c\nd\re\tf\\g"
    ListMinimizerMetricsCollector(
      microbenchmarkId = hostile,
      weightProvider = IWeightProvider { 1 },
      hideTimings = false,
      minimizerTypeName = "PRISTINE_DDMIN",
      scriptExecutionCountSupplier = { 0 },
      queryJsonlFile = queryJsonlFile,
      summaryJsonlFile = summaryJsonlFile,
    ).use { collector ->
      collector.startReduction(wrappers, PristineDeltaDebugger::class, "prefix")
      collector.onPropertyTest(
        configuration = candidateDeleting(0),
        result = tested(exitCode = ExitCode.ZERO),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
      collector.endReduction(wrappers, PristineDeltaDebugger::class, wrappers.size)
    }
    assertThat(queryJsonlFile.readLines().filter { it.isNotBlank() }).hasSize(1)
    assertThat(summaryJsonlFile.readLines().filter { it.isNotBlank() }).hasSize(1)
    assertThat(valuesOf(file = queryJsonlFile, fieldName = "microbenchmarkId"))
      .containsExactly(hostile)
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "microbenchmarkId"))
      .containsExactly(hostile)
  }

  @Test
  fun testHidingTimingsNullsEveryDurationAndNothingElse() {
    createCollector(hideTimings = true).use { collector ->
      collector.startReduction(wrappers, PristineDeltaDebugger::class, "prefix")
      collector.onPropertyTest(
        configuration = candidateDeleting(0),
        result = tested(exitCode = ExitCode.ZERO, elapsedMillis = 37),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
      collector.endReduction(wrappers, PristineDeltaDebugger::class, wrappers.size)
    }
    // The three duration fields, and only those, become null.
    assertThat(valuesOf(file = queryJsonlFile, fieldName = "elapsedMillis")).containsExactly("")
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "totalOracleMillis"))
      .containsExactly("")
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "wallClockMillis")).containsExactly("")
    // Everything a golden actually pins is still reported.
    assertThat(
      valuesOf(file = queryJsonlFile, fieldName = "outcome"),
    ).containsExactly("interesting")
    assertThat(valuesOf(file = queryJsonlFile, fieldName = "deletedCount")).containsExactly("1")
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "totalQueries")).containsExactly("1")
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "interestingCount"))
      .containsExactly("1")
  }

  @Test
  fun testTimingsAreReportedWhenNotHidden() {
    createCollector(hideTimings = false).use { collector ->
      collector.startReduction(wrappers, PristineDeltaDebugger::class, "prefix")
      collector.onPropertyTest(
        configuration = candidateDeleting(0),
        result = tested(exitCode = ExitCode.ZERO, elapsedMillis = 37),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
      collector.endReduction(wrappers, PristineDeltaDebugger::class, wrappers.size)
    }
    assertThat(valuesOf(file = queryJsonlFile, fieldName = "elapsedMillis")).containsExactly("37")
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "totalOracleMillis"))
      .containsExactly("37")
  }

  @Test
  fun testSummaryCarriesBothMinimizerNamesAndTheScriptExecutionCount() {
    // These three fields are what evaluation.jsonl used to hold; they now live on the one record
    // per run, so nothing has to be joined back together.
    var executions = 0
    createCollector(scriptExecutionCounter = { executions }).use { collector ->
      collector.startReduction(wrappers, PristineDeltaDebugger::class, "prefix")
      executions += 6
      collector.endReduction(wrappers, PristineDeltaDebugger::class, wrappers.size)
    }
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "minimizerType"))
      .containsExactly("PRISTINE_DDMIN")
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "minimizer"))
      .containsExactly(PristineDeltaDebugger::class.qualifiedName)
    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "scriptExecutionCount"))
      .containsExactly("6")
  }

  /**
   * The executor is shared with the reduction driver, which runs scripts of its own before the
   * minimizer is ever invoked -- the Layer-2 code-format check in
   * AbstractProgramReductionDriver.ensureInterestingCodeFormatOrThrow is one, and it bypasses the
   * listener entirely. Those must not land in this run's count: comparing scriptExecutionCount with
   * the observed queries is how a query that never reached the listener is detected, and a constant
   * offset would make a lost query look like agreement.
   */
  @Test
  fun testScriptExecutionCountExcludesWhateverRanBeforeTheMinimizerStarted() {
    var executions = 11
    createCollector(scriptExecutionCounter = { executions }).use { collector ->
      collector.startReduction(wrappers, PristineDeltaDebugger::class, "prefix")
      executions += 3
      collector.endReduction(wrappers, PristineDeltaDebugger::class, wrappers.size)
    }

    assertThat(valuesOf(file = summaryJsonlFile, fieldName = "scriptExecutionCount"))
      .containsExactly("3")
  }

  @Test
  fun testQueriesJoinToTheSummaryOnTheMinimizerClassName() {
    createCollector().use { collector ->
      collector.startReduction(wrappers, PristineDeltaDebugger::class, "prefix")
      collector.onPropertyTest(
        configuration = candidateDeleting(0),
        result = tested(exitCode = ExitCode.ZERO),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
      collector.endReduction(wrappers, PristineDeltaDebugger::class, wrappers.size)
    }
    assertThat(valuesOf(file = queryJsonlFile, fieldName = "minimizer"))
      .isEqualTo(valuesOf(file = summaryJsonlFile, fieldName = "minimizer"))
  }

  @Test
  fun testInterestingAndUninterestingPartitionEveryQuery() {
    startAndEnd {
      onPropertyTest(
        configuration = candidateDeleting(0),
        result = tested(exitCode = ExitCode.ZERO),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
      onPropertyTest(
        configuration = candidateDeleting(1),
        result = tested(exitCode = ExitCode.ONE),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
      onPropertyTest(
        configuration = candidateDeleting(2),
        result = CandidateOutcome.Uninteresting.NotTested("Cached"),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
    }
    // No third bucket: every query lands in exactly one of the two, so the counts sum to the
    // total. That was not true while every non-Completed result was reported as a third outcome.
    assertThat(valuesOf(file = queryJsonlFile, fieldName = "outcome"))
      .containsExactly("interesting", "uninteresting", "uninteresting")
      .inOrder()
    val interesting =
      valuesOf(file = summaryJsonlFile, fieldName = "interestingCount").single().toInt()
    val uninteresting =
      valuesOf(file = summaryJsonlFile, fieldName = "uninterestingCount").single().toInt()
    val total = valuesOf(file = summaryJsonlFile, fieldName = "totalQueries").single().toInt()
    assertThat(interesting).isEqualTo(1)
    assertThat(uninteresting).isEqualTo(2)
    assertThat(interesting + uninteresting).isEqualTo(total)
  }

  @Test
  fun testCompletedReductionCountIsOneAfterASingleRun() {
    createCollector().use { collector ->
      assertThat(collector.completedReductionCount).isEqualTo(0)
      collector.startReduction(wrappers, PristineDeltaDebugger::class, "prefix")
      // Still zero mid-run: the evaluation driver asserts on this after the plan has finished, so
      // it must count completed runs rather than started ones.
      assertThat(collector.completedReductionCount).isEqualTo(0)
      collector.endReduction(wrappers, PristineDeltaDebugger::class, wrappers.size)
      assertThat(collector.completedReductionCount).isEqualTo(1)
    }
  }

  @Test
  fun testCompletedReductionCountSeesEveryRun() {
    createCollector().use { collector ->
      repeat(3) {
        collector.startReduction(wrappers, PristineDeltaDebugger::class, "prefix")
        collector.endReduction(wrappers, PristineDeltaDebugger::class, wrappers.size)
      }
      // What a reinstated fixpoint would look like: three well-formed summary rows, no failure.
      assertThat(collector.completedReductionCount).isEqualTo(3)
    }
    assertThat(recordsOf(file = summaryJsonlFile)).hasSize(3)
  }

  @Test
  fun testCountersDoNotLeakAcrossTwoReductions() {
    createCollector().use { collector ->
      repeat(2) {
        collector.startReduction(wrappers, PristineDeltaDebugger::class, "prefix")
        collector.onPropertyTest(
          configuration = candidateDeleting(0),
          result = tested(exitCode = ExitCode.ZERO),
          sizeOfOriginalList = 6,
          sizeOfCurrentMinimizationResult = 6,
        )
        collector.endReduction(wrappers, PristineDeltaDebugger::class, wrappers.size)
      }
    }
    assertThat(
      valuesOf(file = queryJsonlFile, fieldName = "querySeq"),
    ).containsExactly("1", "1").inOrder()
    assertThat(
      valuesOf(file = summaryJsonlFile, fieldName = "totalQueries"),
    ).containsExactly("1", "1").inOrder()
  }

  @Test
  fun testTheLogCallbackDoesNotCorruptEitherStream() {
    startAndEnd {
      log { "a message, with a comma\nand a newline" }
      onPropertyTest(
        configuration = candidateDeleting(0),
        result = tested(exitCode = ExitCode.ZERO),
        sizeOfOriginalList = 6,
        sizeOfCurrentMinimizationResult = 6,
      )
    }
    // Every record carries its own field names, so a value can no longer land under the wrong one.
    assertThat(recordsOf(file = queryJsonlFile).single().keys)
      .containsExactlyElementsIn(fieldNamesOf(file = queryJsonlFile))
    assertThat(recordsOf(file = summaryJsonlFile)).hasSize(1)
  }
}
