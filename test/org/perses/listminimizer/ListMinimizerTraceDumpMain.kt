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
package org.perses.listminimizer

import com.google.common.collect.ImmutableList
import org.perses.reduction.CandidateOutcome
import org.perses.reduction.TestScriptVerdict.Companion.INTERESTING
import org.perses.reduction.TestScriptVerdict.Companion.NON_INTERESTING
import org.perses.util.FileSystemUtil
import java.nio.file.Paths
import kotlin.io.path.absolute
import kotlin.io.path.bufferedWriter

/**
 * Runs one list minimizer on every [scenarios] entry and writes each property test it performs, in
 * order, followed by its result. Backs the `golden_test_list_minimizer_trace_*` golden tests, one
 * per minimizer over the same scenarios, so that diffing two goldens shows how two minimizers
 * differ; regenerate a golden with its `..._update` target.
 */
object ListMinimizerTraceDumpMain {
  private class Scenario(
    val name: String,
    val input: List<String>,
    val description: String,
    val weight: (String) -> Int = { 1 },
    val isInteresting: (List<String>) -> Boolean,
  )

  private fun containing(required: List<String>): (List<String>) -> Boolean =
    { candidate -> candidate.containsAll(required) }

  private val scenarios =
    listOf(
      Scenario(
        name = "five_elements",
        input = "abcde".map { it.toString() },
        description = "interesting iff it contains a and e",
        isInteresting = containing(listOf("a", "e")),
      ),
      Scenario(
        name = "eight_elements",
        input = "abcdefgh".map { it.toString() },
        description = "interesting iff it contains a and e",
        isInteresting = containing(listOf("a", "e")),
      ),
      Scenario(
        // 7 elements do not split evenly, so balanced and fixed-stride blocks differ.
        name = "seven_elements",
        input = "abcdefg".map { it.toString() },
        description = "interesting iff it contains a",
        isInteresting = containing(listOf("a")),
      ),
      Scenario(
        name = "sixteen_elements_sparse",
        input = "abcdefghijklmnop".map { it.toString() },
        description = "interesting iff it contains c and l",
        isInteresting = containing(listOf("c", "l")),
      ),
      Scenario(
        name = "weighted",
        input = listOf("1", "2", "3", "5", "10"),
        description = "each element weighs its value; interesting iff it contains 2, 5 and 10",
        weight = { it.toInt() },
        isInteresting = containing(listOf("2", "5", "10")),
      ),
      Scenario(
        name = "causal_chain",
        input = listOf("x", "1", "2", "3", "4"),
        description =
          "interesting iff it contains x and its digits are exactly 1..k, so digit k is " +
            "removable only once digit k+1 is gone",
        isInteresting = { candidate ->
          val digits = candidate.filter { it != "x" }.map { it.toInt() }
          "x" in candidate && digits == (1..digits.size).toList()
        },
      ),
    )

  private fun format(elements: List<String>): String =
    if (elements.isEmpty()) "(empty)" else elements.joinToString(separator = " ")

  private fun dump(
    type: EnumListMinimizerType,
    scenario: Scenario,
  ): String =
    buildString {
      appendLine("== ${scenario.name}")
      appendLine("input: ${format(scenario.input)}")
      appendLine("property: ${scenario.description}")
      var countOfTests = 0
      val minimizer =
        ListMinimizerFactory.create(
          type,
          ListMinimizerArguments<String, String>(
            needToTestEmpty = true,
            input = ImmutableList.copyOf(scenario.input),
            isElementDeletedElsewhere = { false },
            propertyTester = { configuration ->
              val candidate = configuration.getCandidateOrFail()
              val interesting = scenario.isInteresting(candidate)
              ++countOfTests
              appendLine(
                "%3d %s %s".format(
                  countOfTests,
                  if (interesting) "PASS" else "FAIL",
                  format(candidate),
                ),
              )
              ImmediatePropertyTestHandle(
                if (interesting) {
                  CandidateOutcome.Interesting("", INTERESTING)
                } else {
                  CandidateOutcome.Uninteresting.Rejected(NON_INTERESTING)
                },
              )
            },
            onBestUpdateHandler = { _, _ -> },
            descriptionPrefix = scenario.name,
            weightProvider = { scenario.weight(it) },
          ),
        )
      appendLine("result: ${format(minimizer.reduce())}")
    }

  @JvmStatic
  fun main(args: Array<String>) {
    require(args.size == 2) {
      "Expected two arguments (list minimizer type, output file), got: ${args.toList()}"
    }
    val type = EnumListMinimizerType.valueOf(args[0])
    val outputFile = Paths.get(args[1]).absolute()
    FileSystemUtil.ensureDirExists(outputFile.parent)
    outputFile.bufferedWriter().use { writer ->
      writer.append(scenarios.joinToString(separator = "\n") { dump(type, it) })
    }
  }
}
