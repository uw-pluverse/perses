/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.reduction.scheduler

import com.google.common.collect.ImmutableList
import org.perses.util.TableForTextPrinting
import org.perses.util.padBothEnds

class ReducerHistoryAndStatistics(
  val history: ImmutableList<AbstractSchedulerEvent>,
) {
  init {
    if (history.isEmpty()) {
      require(history.isNotEmpty()) { "History must not be empty" }
      require(history.first() is AbstractSchedulerEvent.StatsSnapshotEvent) {
        "The first event must be stats snapshot"
      }
      require(history.last() is AbstractSchedulerEvent.StatsSnapshotEvent) {
        "The last event must be stats snapshot"
      }
    }
  }

  val reducerTriples: ImmutableList<Triple> by lazy {
    val result = ImmutableList.builder<Triple>()
    val size = history.size
    var reducerIndex = 1
    while (reducerIndex < size) {
      val before = history[reducerIndex - 1]
      check(reducerIndex + 1 < size) {
        "There should a next element that is a stats snapshot"
      }
      val after = history[reducerIndex + 1]
      val reducer = history[reducerIndex]
      check(before is AbstractSchedulerEvent.StatsSnapshotEvent) { before }
      check(after is AbstractSchedulerEvent.StatsSnapshotEvent) { after }
      check(reducer is AbstractSchedulerEvent.ReducerCallEvent) { reducer }
      result.add(Triple(reducerEvent = reducer, statsBefore = before, statsAfter = after))
      reducerIndex += 2
    }
    result.build()
  }

  fun printHistoryAndStatistics(): String {
    val textWidth = 80
    val padChar = '-'
    return buildString {
      val exceptions =
        reducerTriples.filter {
          it.reducerEvent.exceptionStackTrace != null
        }
      if (exceptions.isNotEmpty()) {
        appendLine(
          " Reducers with exceptions ".padBothEnds(desiredLength = textWidth, padChar = padChar),
        )
        exceptions.forEach { reducer ->
          appendLine(reducer.reducerEvent.reducer.shortName)
          reducer.reducerEvent.exceptionStackTrace!!.lines().forEach { line ->
            appendLine("  $line")
          }
        }
        appendLine()
      }
      appendLine(
        " Reduction History and Statistics ".padBothEnds(
          desiredLength = textWidth,
          padChar = padChar,
        ),
      )
      appendLine(" History ".padBothEnds(desiredLength = textWidth, padChar = padChar))
      appendLine(TableForTextPrinting(constructHistoryTable()).print())
      appendLine()
      appendLine(" Summary ".padBothEnds(desiredLength = textWidth, padChar = padChar))
      appendLine(TableForTextPrinting(constructSummaryTable()).print())
      appendLine(" End ".padBothEnds(desiredLength = textWidth, padChar = padChar))
    }
  }

  private fun constructSummaryTable(): List<List<String>> {
    val table = mutableListOf<List<String>>()
    table.add(listOf("Reducer", "Times", "#Tokens", "#Chars"))
    reducerTriples
      .groupBy { it.reducerEvent.reducer }
      .forEach { (reducer, stats) ->
        val times = stats.size
        val reducerName = reducer.shortName
        val tokenCount =
          stats.sumOf {
            it.statsAfter.stats.tokenCount - it.statsBefore.stats.tokenCount
          }
        val charCount =
          stats.sumOf {
            it.statsAfter.stats.characterCount - it.statsBefore.stats.characterCount
          }
        table.add(
          listOf(reducerName, times.toString(), tokenCount.toString(), charCount.toString()),
        )
      }
    return table
  }

  private fun constructHistoryTable(): List<List<String>> {
    val historyTable = mutableListOf<List<String>>()
    historyTable.add(listOf("ID", "Reducer", "#Tokens", "#Chars", "#NonDeletions"))
    reducerTriples.withIndex().forEach { (index, triple) ->
      val indexString = index.toString()
      val reducer = triple.reducerEvent
      val reducerName = reducer.reducer.shortName
      val statsBefore = triple.statsBefore.stats
      val statsAfter = triple.statsAfter.stats
      val tokenDifferences = statsAfter.tokenCount - statsBefore.tokenCount
      val charDifferences = statsAfter.characterCount - statsBefore.characterCount

      historyTable.add(
        listOf(
          indexString,
          reducerName,
          tokenDifferences.toString(),
          charDifferences.toString(),
          triple.statsAfter.numberOfNonDeletionIterations.toString(),
        ),
      )
    }
    return historyTable
  }

  class Triple(
    val reducerEvent: AbstractSchedulerEvent.ReducerCallEvent,
    val statsBefore: AbstractSchedulerEvent.StatsSnapshotEvent,
    val statsAfter: AbstractSchedulerEvent.StatsSnapshotEvent,
  )
}
