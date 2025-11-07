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
package org.perses.reduction.reducer.latra

import com.google.common.collect.ImmutableMap
import org.perses.grammar.AbstractParserFacade
import org.perses.program.AbstractDataKind
import org.perses.reduction.AbstractNonDeletionBasedReducer
import org.perses.reduction.FixpointReductionState
import org.perses.reduction.ReducerAnnotation
import org.perses.reduction.ReducerContext
import org.perses.spartree.SparTree
import org.perses.util.Util
import org.perses.util.ktFine

class DefaultLatraReducer(
  reducerAnnotation: ReducerAnnotation,
  reducerContext: ReducerContext,
  protected val language2transformationListMap:
    ImmutableMap<AbstractDataKind, AbstractLatraTransformationList>,
  val enforceStrictlyMonotonicSizeDecrease: Boolean,
) : AbstractNonDeletionBasedReducer(reducerAnnotation, reducerContext) {
  protected val facade: AbstractParserFacade
    get() = reducerContext.configuration.parserFacade

  protected val listenerManager = reducerContext.listenerManager

  override fun internalReduce(fixpointReductionState: FixpointReductionState) {
    val fixpointIterationStartEvent = fixpointReductionState.fixpointIterationStartEvent
    val reductionStartEvent = fixpointIterationStartEvent.reductionStartEvent
    val transformationList = language2transformationListMap[facade.language]
    if (transformationList == null) {
      listenerManager.onAdHocMessageEvent(
        fixpointReductionState.createAdHocMessageEvent {
          "Latra does not support ${facade.language} langauge yet."
        },
      )
      return
    }

    val bestTree = fixpointReductionState.sparTree.getTreeRegardlessOfParsability()
    val programPrinter =
      IProgramPrinter { program ->
        ioManager.outputManagerFactory
          .createManagerFor(program)
          .tryToGetMainFileContentOrThrow()
          .content
          .asTextFileContent
          .printableContentIfPossible
      }
    val generalLatraArgs =
      LatraArguments(
        parserFacade = facade,
        sparTreeNodeFactory = bestTree.sparTreeNodeFactory,
        programPrinter = programPrinter,
        prefixLabelFromRootToHere = fixpointIterationStartEvent.prefixLabelFromRootToHere,
        logger = { prefixLabelFromRootToHere, messageCreator ->
          listenerManager.onAdHocMessageEvent(
            reductionStartEvent.createAdHocMessageEvent(
              programSize = bestTree.programSnapshot.tokenCount,
              prefixLabelFromRootToHere = prefixLabelFromRootToHere,
              messageComputer = messageCreator,
            ),
          )
        },
      )

    val transformations = transformationList.createLatraTransformations(generalLatraArgs)
    generalLatraArgs.log {
      "For ${facade.language.name}, there are ${transformations.size} transformations."
    }

    var firstTime = true
    Util.fixpoint(
      initial = bestTree.tokenCount,
      stopCriterion = { tokenCountBefore, tokenCountAfter ->
        Util.EnumStopCriterion.stopIfTrue(tokenCountBefore <= tokenCountAfter)
      },
    ) {
      if (firstTime || bestTree.dirty) {
        firstTime = false
        try {
          val message = "Reparsing the best spartree to faithfully reflect the syntactic structure."
          generalLatraArgs.log { message }
          val rebuiltTree = generalLatraArgs.rebuildSparTree(bestTree)
          bestTree.applyEdit(
            bestTree.createRootReplacementEdit(
              newRoot = rebuiltTree.detachRootFromTree(),
              actionsDescription = message,
            ),
          )
        } catch (e: Exception) {
          generalLatraArgs.log {
            "Failed to re-parse the input within Latra. " +
              "${e::class.simpleName}: ${e.message}"
          }
          logger.ktFine { e.toString() }
        }
      }
      for (transformation in transformations) {
        reduceWithOneTransformation(
          generalLatraArgs,
          bestTree,
          transformation,
          fixpointReductionState,
        )
      }
      return@fixpoint bestTree.tokenCount
    }
  }

  private fun reduceWithOneTransformation(
    generalLatraArgs: LatraArguments,
    bestTree: SparTree,
    transformation: LatraTransformation,
    fixpointReductionState: FixpointReductionState,
  ) {
    transformation.reduce(
      bestTree,
      listMinimizerType = reducerContext.configuration.latraConfig.listMinimizerForTransformations,
      systemDeltaDebuggerListener = reducerContext.listMinimizerListener,
      testProperty = { edit ->
        if (enforceStrictlyMonotonicSizeDecrease &&
          edit.program.tokenCount >= bestTree.tokenCount
        ) {
          return@reduce false
        }
        ignoreCachedEditsThenFindBestWrtProperty(
          listOf(edit),
          fixpointReductionState,
        ) != null
      },
    )
  }
}
