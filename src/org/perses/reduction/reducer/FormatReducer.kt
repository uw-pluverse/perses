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
package org.perses.reduction.reducer

import com.google.common.collect.ImmutableList
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.util.TimeUtil

/**
 * Formats the final reduction result with the language's default formatter and, if the formatted
 * result still passes the property test, copies it into the result folder.
 *
 * Unlike [CReduceReducer], this reducer works at the file level and does not apply a spar-tree edit.
 * Formatting only adds whitespace, so it leaves the canonical token count unchanged but grows the
 * character count; applying it as a tree edit would (a) be reverted by the driver's global-minimum
 * restoration and (b) break specialized reduction models that constrain the tree (e.g. PPR's
 * seed/variant token alignment). Operating on the files directly side-steps both problems and also
 * naturally handles multi-file reductions.
 *
 * It is therefore not woven into the reducer execution plan; the driver runs it once at the very end
 * of the reduction.
 */
class FormatReducer(
  reducerContext: ReducerContext,
) : AbstractSparTreeReducer(META, reducerContext) {
  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val listenerManager = reducerContext.listenerManager
    val language = reducerContext.configuration.canonicalParserFacade.language
    val formatCmd = language.getDefaultWorkingFormatter()
    if (formatCmd == null) {
      listenerManager.onAdHocMessageEvent(
        fixpointReductionState.createAdHocMessageEvent {
          "No working formatter is available for $language; skipping formatting. " +
            "Tried: ${language.getAllDefaultFormatterCommandStrings()}"
        },
      )
      return
    }

    val tree = fixpointReductionState.inputRepresentation.tree
    listenerManager.onAdHocMessageEvent(
      fixpointReductionState.createAdHocMessageEvent {
        "Formatting the reduction result with ${formatCmd.normalizedCommand}. " +
          "#tokens=${tree.programSnapshot}"
      },
    )

    val formatFolder =
      executorService.createReductionFolder(
        prefix = "formatter_at_the_end_",
        suffix = TimeUtil.formatDateForFileName(System.currentTimeMillis()),
      )
    reducerContext
      .createOutputManager(tree.programSnapshot.payload)
      .write(formatFolder)

    for (sourceFileRelativePath in ioManager.getExistingInputFileRelativePathsIn(formatFolder)) {
      val cmdOutput =
        formatCmd.runWith(
          ImmutableList.of(sourceFileRelativePath.toString()),
          workingDirectory = formatFolder.path,
        )
      if (cmdOutput.exitCode.isNonZero()) {
        listenerManager.onAdHocMessageEvent(
          fixpointReductionState.createAdHocMessageEvent {
            "The formatter ${formatCmd.normalizedCommand} failed on $sourceFileRelativePath in " +
              "${formatFolder.path}; keeping the original result.\n" +
              "stdout: ${cmdOutput.stdout.combinedLines}\n" +
              "stderr: ${cmdOutput.stderr.combinedLines}"
          },
        )
        return
      }
    }

    if (formatFolder.runTestScript().isNotInteresting) {
      listenerManager.onAdHocMessageEvent(
        fixpointReductionState.createAdHocMessageEvent {
          "The formatted result failed the property test; keeping the original result."
        },
      )
      return
    }

    formatFolder.copyTo(ioManager.resultFolder)
    listenerManager.onAdHocMessageEvent(
      fixpointReductionState.createAdHocMessageEvent {
        "Formatted the reduction result with ${formatCmd.normalizedCommand}."
      },
    )
  }

  object META : ReducerAnnotation(
    shortName = NAME,
    description = "Format the reduction result with the language's default formatter.",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_REMAIN,
  ) {
    override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
      ImmutableList.of(FormatReducer(reducerContext))
  }

  companion object {
    const val NAME = "format_reducer"
  }
}
