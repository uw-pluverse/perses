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
package org.perses.analyzer.differential

import com.google.common.collect.ImmutableList
import org.perses.antlr.RuleType
import org.perses.listener.DifferentialEvents
import org.perses.reduction.TestScriptVerdict
import org.perses.util.cmd.AbstractMain
import org.perses.util.cmd.CommandLineProcessor
import org.perses.util.cmd.OutputOnlyCommandOptions
import org.perses.util.shell.ExitCode

class EventDiffTestDataGenerator(
  cmd: OutputOnlyCommandOptions,
) : AbstractMain<OutputOnlyCommandOptions>(cmd) {
  override fun internalRun() {
    val edits =
      ImmutableList.of(
        DifferentialEvents.Edit(
          contextualDescription = "Delete function f1",
          structureDescription = "Function -> Empty",
          propertyTestResult = TestScriptVerdict(ExitCode.ZERO, 50),
          successfullyDeletedCode = "void f1() {}",
          deletedTokenCount = 2,
          startPersesTimeSeconds = 12,
        ),
      )
    val event1 =
      DifferentialEvents.NodeReductionEvent(
        fixpointIteration = 1,
        startPersesTimeSeconds = 10,
        endPersesTimeSeconds = 15,
        nodeId = 1,
        ruleName = "DeleteFunction",
        ruleType = null,
        childrenBeforeReduction = ImmutableList.of(2, 3, 4),
        deletedTokenCount = 100,
        childrenAfterReduction = ImmutableList.of(2, 4),
        editsTested = edits,
      )

    val edits2 =
      ImmutableList.of(
        DifferentialEvents.Edit(
          contextualDescription = "Delete variable x",
          structureDescription = "Variable -> Empty",
          propertyTestResult = TestScriptVerdict(ExitCode.ONE, 30),
          successfullyDeletedCode = "int x = 0;",
          deletedTokenCount = 0,
          startPersesTimeSeconds = 22,
        ),
      )
    val event2 =
      DifferentialEvents.NodeReductionEvent(
        fixpointIteration = 2,
        startPersesTimeSeconds = 20,
        endPersesTimeSeconds = 25,
        nodeId = 5,
        ruleName = "DeleteVariable",
        ruleType = RuleType.KLEENE_STAR,
        childrenBeforeReduction = ImmutableList.of(6, 7),
        deletedTokenCount = 0,
        childrenAfterReduction = ImmutableList.of(6, 7),
        editsTested = edits2,
      )

    val events = ImmutableList.of(event1, event2)
    DifferentialEvents.writeToYamlFile(events, cmd.flags.outputFile!!)
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      val processor =
        CommandLineProcessor(
          cmdCreator = { OutputOnlyCommandOptions() },
          programName = EventDiffTestDataGenerator::class.qualifiedName!!,
          args = args,
        )
      if (processor.process() == CommandLineProcessor.HelpRequestProcessingDecision.EXIT) {
        return
      }
      EventDiffTestDataGenerator(processor.cmd).run()
    }
  }
}
