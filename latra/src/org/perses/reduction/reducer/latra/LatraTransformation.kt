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
package org.perses.reduction.reducer.latra

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import org.perses.grammar.AbstractParserFacade
import org.perses.listminimizer.AbstractListMinimizerListener
import org.perses.listminimizer.ElementWrapper
import org.perses.listminimizer.EnumListMinimizerType
import org.perses.listminimizer.IPropertyTester
import org.perses.listminimizer.ListMinimizerPropertyTestResult
import org.perses.listminimizer.ListMinimizerArguments
import org.perses.listminimizer.ListMinimizerFactory
import org.perses.listminimizer.ListMinimizerListenerAdaptor
import org.perses.listminimizer.OnBestUpdateHandler
import org.perses.listminimizer.PartitionComplementControl
import org.perses.reduction.PropertyTestResult
import org.perses.reduction.reducer.latra.language.LatraTransformationDefinition
import org.perses.spartree.AbstractSparTreeEdit
import org.perses.spartree.LatraGeneralTreeEdit
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeNodeFactory
import org.perses.util.toImmutableList
import org.perses.util.toImmutableMap

open class LatraTransformation(
  protected val latraArguments: LatraArguments,
  val definition: LatraTransformationDefinition,
) {
  protected val sparTreeNodeFactory: SparTreeNodeFactory
    get() = latraArguments.sparTreeNodeFactory

  protected val parserFacade: AbstractParserFacade
    get() = latraArguments.canonicalParserFacade

  val name: String
    get() = definition.name

  private fun findMatches(tree: SparTree): List<SparTreeHoleMatch> {
    val matches =
      TransformationUtility
        .looseMatch(
          pattern = definition.matchingTemplate.from.pattern,
          suchAsClause = definition.matchingTemplate.suchAs,
          rootToStartMatching = tree.realRoot,
          latraArguments = latraArguments,
        )
    latraArguments.log { "Found matches: ${matches.size} in transformation ${definition.name}" }
    return matches.sortedWith(compareByDescending { it.subtreeRoot.leafTokenCount })
  }

  // TODO(cnsun): we should allow the callers to access the matches, and allow them to
  //   use listminimizer to apply these transformations.
  fun computeEdits(tree: SparTree): Sequence<LatraGeneralTreeEdit> {
    val matches = findMatches(tree)
    return sequence {
      for (originalMatch in matches) {
        val latraGeneralEdit =
          createTreeEditFromMatches(
            listOf(originalMatch),
            tree,
          ) ?: continue
        yield(latraGeneralEdit)
      }
    }
  }

  private fun createTreeEditFromMatches(
    matches: List<SparTreeHoleMatch>,
    tree: SparTree,
  ): LatraGeneralTreeEdit? {
    val remainingMatches =
      matches.mapNotNull { originalMatch ->
        portMatchToTreeIfNecessary(originalMatch, tree)
      }
    if (remainingMatches.isEmpty()) {
      return null
    }
    val rewriterBuilder =
      AbstractLatraRewriterBuilder
        .smartCreate(
          remainingMatches,
          tree,
          definition,
          latraArguments,
        ).build() ?: return null
    val matchDesc = summarizeMatchInfo(remainingMatches)
    latraArguments.log { "Built a LatraGeneralActionSet $matchDesc in $name" }
    return tree.createLatraGeneralEdit(rewriterBuilder)
  }

  private fun portMatchToTreeIfNecessary(
    originalMatch: SparTreeHoleMatch,
    tree: SparTree,
  ): SparTreeHoleMatch? {
    if (originalMatch.isStillValid()) {
      return originalMatch
    }
    val id2NodeMap = tree.getNodeId2NodeMap()
    val portedMatch =
      originalMatch.portToTreeBasedOnNodeId(
        id2NodeMap,
      )
    if (portedMatch == null) {
      latraArguments.log {
        "The match with subroot ${originalMatch.subtreeRoot.nodeId} becomes invalid now."
      }
    }
    return portedMatch
  }

  fun reduce(
    tree: SparTree,
    listMinimizerType: EnumListMinimizerType,
    systemDeltaDebuggerListener: AbstractListMinimizerListener,
    testProperty: (AbstractSparTreeEdit<*>) -> Boolean,
  ) {
    val matches = findMatches(tree).toImmutableList()
    if (matches.isEmpty()) {
      return
    }
    // TODO(cnsun): need to make 10 a command-line argument.
    if (matches.size < 2) {
      for (match in matches) {
        val edit = createTreeEditFromMatches(listOf(match), tree) ?: continue
        if (testProperty(edit)) {
          latraArguments.log { "Found a best edit. Updating the tree." }
          tree.applyEdit(edit, canonicalTokenCount = null)
        }
      }
      return
    }
    val listMinimizerArguments =
      createListMinimizerArgumentsForMatches(
        sparTree = tree,
        input = matches,
        systemDeltaDebuggerListener = systemDeltaDebuggerListener,
        listMinimizerType = listMinimizerType,
        testProperty = testProperty,
      )
    val minimizer = ListMinimizerFactory.create(listMinimizerType, listMinimizerArguments)
    minimizer.reduce()
  }

  private fun createListMinimizerArgumentsForMatches(
    sparTree: SparTree,
    input: ImmutableList<SparTreeHoleMatch>,
    systemDeltaDebuggerListener: AbstractListMinimizerListener,
    listMinimizerType: EnumListMinimizerType,
    testProperty: (AbstractSparTreeEdit<*>) -> Boolean,
  ): ListMinimizerArguments<SparTreeHoleMatch, SparTreeHoleMatchPayload> {
    val weightProvider = input.map { it to it.subtreeRoot.leafTokenCount }.toImmutableMap()
    return ListMinimizerArguments(
      // need to keep at least one match.
      needToTestEmpty = false,
      input = input,
      // TODO(cnsun): need to double check whether the following is correct.
      isElementDeletedElsewhere = { false },
      propertyTester = createPropertyTester(sparTree, testProperty),
      onBestUpdateHandler = createOnBestUpdateHandler(),
      descriptionPrefix = "$listMinimizerType in ${this::class.simpleName}",
      weightProvider = { weightProvider[it] ?: error("No weight found for $it") },
      listener = createListMinimizerListener(systemDeltaDebuggerListener, listMinimizerType),
      partitionComplementControl =
        PartitionComplementControl(
          enableReducingPartitions = false,
          /* The elements being reduced are matches, so we only consider using complements.
           * That is, given a complement, the deleted partition is the matches we need to apply.
           */
          enableReducingComplements = true,
        ),
    )
  }

  private fun createOnBestUpdateHandler() =
    OnBestUpdateHandler<SparTreeHoleMatch, SparTreeHoleMatchPayload> {
      _,
      payload: SparTreeHoleMatchPayload,
      ->
      // TODO(gemini): we might need to compute canonical token count.
      payload.tree.applyEdit(payload.edit, canonicalTokenCount = null)
    }

  private fun createPropertyTester(
    tree: SparTree,
    testProperty: (AbstractSparTreeEdit<*>) -> Boolean,
  ) = IPropertyTester<SparTreeHoleMatch, SparTreeHoleMatchPayload> { configuration ->
    val invalidMatchesBuilder = ImmutableList.builder<ElementWrapper<SparTreeHoleMatch>>()
    val matches =
      configuration.deletedWrappers.mapNotNull { originalMatch ->
        val portedMatch = portMatchToTreeIfNecessary(originalMatch.element, tree)
        if (portedMatch == null) {
          invalidMatchesBuilder.add(originalMatch)
        }
        portedMatch
      }

    val staleElementsToRemove = invalidMatchesBuilder.build()
    if (matches.isEmpty()) {
      latraArguments.log { "The matches in the candidate are invalid. " }
      return@IPropertyTester ListMinimizerPropertyTestResult.Skipped(
        result = "all matches are invalid.",
        staleElementsToRemove = staleElementsToRemove,
      )
    }

    latraArguments.log {
      val matchInfo = summarizeMatchInfo(matches)
      "Try to apply transformations for matches $matchInfo"
    }
    val edit =
      createTreeEditFromMatches(matches, tree)
        ?: return@IPropertyTester ListMinimizerPropertyTestResult.Skipped(
          result = "null edit",
          staleElementsToRemove = staleElementsToRemove,
        )
    ListMinimizerPropertyTestResult.Completed(
      result =
        if (testProperty(edit)) {
          PropertyTestResult.INTERESTING_RESULT
        } else {
          PropertyTestResult.NON_INTERESTING_RESULT
        },
      payload =
        SparTreeHoleMatchPayload(
          tree = tree,
          edit = edit,
        ),
      staleElementsToRemove = staleElementsToRemove,
    )
  }

  private fun createListMinimizerListener(
    systemDeltaDebuggerListener: AbstractListMinimizerListener,
    listMinimizer: EnumListMinimizerType,
  ): AbstractListMinimizerListener {
    val customizedLatraArguments =
      latraArguments.createWithNewExtraSuffixOfPrefix(
        extraSuffixOfPrefix = "[$listMinimizer]",
      )
    val adaptor =
      ListMinimizerListenerAdaptor { message ->
        customizedLatraArguments.log { message }
      }
    return AbstractListMinimizerListener.smartCombine(systemDeltaDebuggerListener, adaptor)
  }

  override fun toString(): String =
    MoreObjects.toStringHelper(this).addValue(definition.name).toString()

  companion object {
    private fun summarizeMatchInfo(matches: List<SparTreeHoleMatch>): String {
      val size = matches.size
      return when {
        size == 0 -> {
          error("Unreachable")
        }

        size == 1 -> {
          matches.single().printMatchInfo()
        }

        size <= 5 -> {
          matches.map { it.printMatchInfo() }.toString()
        }

        else -> {
          val firstMatchInfo = matches.first().printMatchInfo()
          val lastMatchInfo = matches.last().printMatchInfo()
          "$firstMatchInfo...$lastMatchInfo (${matches.size} matches)"
        }
      }
    }
  }
}
