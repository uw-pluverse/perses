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
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.onetoken.OneTokenParserFacade
import org.perses.reduction.AbstractSparTreeReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.reduction.io.ReductionFolder
import org.perses.spartree.AnyNodeReplacementTreeEdit
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeParserUtility
import org.perses.util.TimeUtil
import org.perses.util.shell.Shells

/**
 * Refines the current best program by running C-Reduce on it and replacing the spar-tree with the
 * result.
 *
 * Uses [OneTokenParserFacade] as the surrogate facade, so the program is treated as a flat token
 * stream: the result produced by C-Reduce is kept verbatim and does not need to be parsable by the
 * canonical grammar.
 */
class CReduceReducer(
  annotation: CReduceReducerAnnotation,
  reducerContext: ReducerContext,
) : AbstractSparTreeReducer(annotation, reducerContext) {
  private val creduceCmd = annotation.creduceCmd

  override fun getPreferredParserFacade(): AbstractParserFacade = OneTokenParserFacade()

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val listenerManager = reducerContext.listenerManager
    val tree = fixpointReductionState.inputRepresentation.tree
    val originalSize = tree.programSnapshot
    listenerManager.onAdHocMessageEvent(
      fixpointReductionState.createAdHocMessageEvent {
        "Calling C-Reduce to further refine the result. #tokens=$originalSize"
      },
    )

    val reductionFolder =
      executorService.createReductionFolder(
        prefix = "creduce_at_the_end",
        suffix = TimeUtil.formatDateForFileName(System.currentTimeMillis()),
      )
    reducerContext
      .createOutputManager(originalSize.payload)
      .write(reductionFolder)

    val cmdOutput =
      Shells.defaultSingleton.run(
        constructFullCreduceCommand(reductionFolder),
        captureOutput = false,
        workingDirectory = reductionFolder.path,
        environment = Shells.CURRENT_ENV,
      )

    if (cmdOutput.exitCode.isNonZero()) {
      listenerManager.onAdHocMessageEvent(
        fixpointReductionState.createAdHocMessageEvent {
          "C-Reduce failed in ${reductionFolder.path}. " +
            "Testing whether its partial result is still interesting."
        },
      )
    }

    // C-Reduce edits the file in place, so even on failure it may have left a partially-reduced
    // file behind. Build an edit from whatever it produced and apply it only if it is interesting.
    val edit = createRefinementEdit(reductionFolder, tree)
    val applicationResult = testAndApplyEditIfInteresting(edit, tree)
    listenerManager.onAdHocMessageEvent(
      fixpointReductionState.createAdHocMessageEvent {
        when (applicationResult) {
          EditApplicationResult.APPLIED ->
            "C-Reduce reduced the file from $originalSize to ${tree.programSnapshot}"
          EditApplicationResult.NO ->
            "C-Reduce's result is not interesting; keeping the original result."
        }
      },
    )
  }

  /** Builds a root-replacement edit from the (possibly partial) file C-Reduce left in [folder]. */
  private fun createRefinementEdit(
    folder: ReductionFolder,
    tree: SparTree,
  ): AnyNodeReplacementTreeEdit {
    val reducedSourceCode =
      folder.readFileContent(reducerContext.fileUnderReduction)
    val newRoot =
      SparTreeParserUtility
        .buildSparTree(
          sourceCode = reducedSourceCode,
          parserFacade = tree.sparTreeNodeFactory.parserFacade,
          specifiedSparTreeNodeFactory = tree.sparTreeNodeFactory,
          simplifyTree = false,
          canonicalTokenCountComputer = { null },
          errorMode = ParseErrorHandling.STRICT,
        ).detachRootFromTree()
    return tree.createRootReplacementEdit(
      newRoot = newRoot,
      contextDescription = "Refine the reduction result with C-Reduce.",
      transformationName = "CReduce",
    )
  }

  private fun constructFullCreduceCommand(reductionFolder: ReductionFolder) =
    buildString {
      append(creduceCmd)
      append(' ')
      append(ioManager.getScriptFileBaseNameIn(reductionFolder))
      append(' ')
      append(reducerContext.fileUnderReduction.baseName)
    }

  companion object {
    const val NAME = "creduce_reducer"
  }
}

/**
 * The annotation for [CReduceReducer]. Unlike most reducer annotations it is not a singleton object,
 * because it carries the runtime C-Reduce command, which originates from a command-line flag.
 */
class CReduceReducerAnnotation(
  val creduceCmd: String,
) : ReducerAnnotation(
    shortName = CReduceReducer.NAME,
    description = "Refine the reduction result with C-Reduce.",
    deterministic = true,
    reductionResultSizeTrend = ReductionResultSizeTrend.BEST_RESULT_SIZE_DECREASE,
  ) {
  override fun create(reducerContext: ReducerContext): ImmutableList<AbstractSparTreeReducer> =
    ImmutableList.of(CReduceReducer(this, reducerContext))
}
