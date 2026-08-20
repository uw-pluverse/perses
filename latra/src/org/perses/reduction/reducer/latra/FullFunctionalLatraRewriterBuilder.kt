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

import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.Token
import org.perses.reduction.reducer.latra.language.AbstractPatternElementBindings.ScopedPatternElementBindings
import org.perses.reduction.reducer.latra.language.LatraTransformationDefinition
import org.perses.reduction.reducer.latra.language.LatraTransformationDefinition.InsertClause.InsertPosition.INSERT_AFTER_MATCH
import org.perses.reduction.reducer.latra.language.LatraTransformationDefinition.InsertClause.InsertPosition.INSERT_AT_BOTTOM
import org.perses.reduction.reducer.latra.language.LatraTransformationDefinition.InsertClause.InsertPosition.INSERT_AT_TOP
import org.perses.reduction.reducer.latra.language.LatraTransformationDefinition.InsertClause.InsertPosition.INSERT_BEFORE_MATCH
import org.perses.spartree.AbstractNodePayload
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy
import org.perses.spartree.DeepCopyResult
import org.perses.spartree.LatraGeneralActionSet
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.util.ktFine
import org.perses.util.transformToImmutableList

// TODO(cnsun): need to test this with the simple from-to patterns.
class FullFunctionalLatraRewriterBuilder internal constructor(
  matches: List<SparTreeHoleMatch>,
  origSparTree: SparTree,
  definition: LatraTransformationDefinition,
  latraArguments: LatraArguments,
) : AbstractLatraRewriterBuilder(matches, origSparTree, definition, latraArguments) {
  internal val treeCopy = origSparTree.deepCopy(ReuseNodeIdStrategy)

  private val tokensInOrigSparTree: ImmutableList<Token> by lazy {
    latraArguments.reTokenizeProgram(origSparTree)
  }

  private fun isSparTreeModified(sparTreeCopy: SparTree): Boolean {
    if (doLeafSequencesHaveSameNonBlankLexemes(
        origSparTree.leafNodeSequence(),
        sparTreeCopy.leafNodeSequence(),
      )
    ) {
      return false
    }
    // Note that we need to convert the token sequence to a string and then re-tokenize the string
    // so that inserted whitespaces can be deleted.
    val origTokens = tokensInOrigSparTree
    val copyTokens = latraArguments.reTokenizeProgram(sparTreeCopy)
    val size = origTokens.size
    if (size != copyTokens.size) {
      return true
    }
    var i = 0
    while (i < size) {
      val orig = origTokens[i]
      val copy = copyTokens[i]
      if (orig.text != copy.text) {
        return true
      }
      ++i
    }
    return false
  }

  override fun build(): LatraGeneralActionSet? {
    try {
      createSingleMatchLatraRewriterBuilder().forEach {
        it.performTransformation()
        it.treeCopy.result.lazyAssertTreeNodeIdsAreUnique()
      }
      val sparTreeCopy = treeCopy.result
      sparTreeCopy.fixLinkIntegrityAndUpdateProgram()
      if (!isSparTreeModified(sparTreeCopy)) {
        // Need to test this condition after the link integrity is fixed.
        return null
      }
      return LatraGeneralActionSet
        .Builder(
          contextDescription = contextDescription,
          transformationName = definition.name,
        ).also { builder ->
          builder.replaceNode(
            targetNode = origSparTree.realRoot,
            replacingNode = sparTreeCopy.detachRootFromTree(),
          )
        }.buildOrNull()
    } catch (e: LatraException) {
      latraArguments.log { "Exception: ${e.message}" }
      return null
    }
  }

  internal fun createSingleMatchLatraRewriterBuilder() =
    matches.transformToImmutableList {
      SingleMatchLatraRewriterBuilder(
        definition = definition,
        latraArguments = latraArguments,
        originalMatch = it,
        treeCopy = treeCopy,
      )
    }

  class SingleMatchLatraRewriterBuilder(
    val definition: LatraTransformationDefinition,
    val latraArguments: LatraArguments,
    originalMatch: SparTreeHoleMatch,
    internal val treeCopy: DeepCopyResult<SparTree, AbstractSparTreeNode>,
  ) {
    private val matchOnSparTreeCopy = originalMatch.portToTreeCopy(treeCopy)

    private val tokenBeforeMatch =
      normalizeTokenNode(
        matchOnSparTreeCopy.subtreeRoot.beginToken!!.prevLexerRuleTreeNode!!,
      )

    private val tokenAfterMatch =
      normalizeTokenNode(
        matchOnSparTreeCopy.subtreeRoot.endToken!!.nextLexerRuleTreeNode!!,
      )

    private val rewriteTreeResultOfTheToClause =
      definition.rewritingTemplate.to.performRewrite(
        latraArguments.sparTreeNodeFactory,
        matchOnSparTreeCopy.holeBindings,
      )

    private fun normalizeTokenNode(tokenNode: LexerRuleSparTreeNode): LexerRuleSparTreeNode? =
      if (treeCopy.result.isDummyNode(tokenNode)) {
        null
      } else {
        tokenNode
      }

    fun performTransformation() {
      val holeBindings = createInitialHoleBindings()
      processToClauseOnSparTreeCopy(holeBindings)
      processGlobalReplaceClauseOnSparTreeCopy(holeBindings)
      processInsertClausesOnSparTreeCopy(holeBindings)
    }

    internal fun createInitialHoleBindings() =
      ScopedPatternElementBindings(
        outerScopedHoleBindings = matchOnSparTreeCopy.holeBindings,
      )

    internal fun processToClauseOnSparTreeCopy(holeBindings: ScopedPatternElementBindings) {
      holeBindings.createNewBindings(rewriteTreeResultOfTheToClause.newHoleBindings)
      if (matchOnSparTreeCopy.subtreeRoot.isPermanentlyDeleted) {
        throw LatraException(
          "The subtree ${matchOnSparTreeCopy.printMatchInfo()} has been permanently deleted.",
        )
      }
      val parent =
        matchOnSparTreeCopy.subtreeRoot.parent
          ?: throw LatraException(
            "The subtree ${matchOnSparTreeCopy.printMatchInfo()} has been detached from the tree.",
          )
      parent.replaceChild(
        oldChild = matchOnSparTreeCopy.subtreeRoot,
        newChild = rewriteTreeResultOfTheToClause.result,
        payload = matchOnSparTreeCopy.subtreeRoot.payload!!,
      )
    }

    private fun performOneGlobalReplace(
      match: SparTreeHoleMatch,
      globalReplace: LatraTransformationDefinition.GlobalReplaceClause,
      patternElementBindings: ScopedPatternElementBindings,
    ) {
      patternElementBindings.createNewBindings(match.holeBindings.holeBindings)

      val rewriteResult =
        globalReplace.with.performRewrite(
          latraArguments.sparTreeNodeFactory,
          patternElementBindings,
        )

      patternElementBindings.createNewBindings(rewriteResult.newHoleBindings)

      val parent = match.subtreeRoot.parent
      check(parent != null) { "$match is not in a spar tree." }
      parent.replaceChild(
        oldChild = match.subtreeRoot,
        newChild = rewriteResult.result,
        payload = match.subtreeRoot.payload!!,
      )
    }

    // TODO(cnsun): simplify this method.
    internal fun processGlobalReplaceClauseOnSparTreeCopy(
      holeBindings: ScopedPatternElementBindings,
    ) {
      val operations = definition.rewritingTemplate.globalReplace
      for ((index, replaceClause) in operations.withIndex()) {
        val patternToReplace =
          try {
            replaceClause.from.resolveHolesIfPossible { holeName ->
              holeBindings.getHoleBinding(holeName)
            }
          } catch (e: LatraEmptyHoleBindingException) {
            logger.ktFine { e.toString() }
            continue
          }

        val matches =
          TransformationUtility.looseMatch(
            pattern = patternToReplace.pattern,
            suchAsClause = replaceClause.suchAs,
            rootToStartMatching = getTargetSubTreeForGlobalReplacement(replaceClause, holeBindings),
            latraArguments,
          )
        if (matches.isEmpty()) {
          if (replaceClause.mustMatch) {
            throw LatraException(
              "There must be at least one match for this transformation ${definition.name}",
            )
          } else {
            patternToReplace.pattern.holes.forEach { hole ->
              holeBindings.createEmptyBinding(hole.holeName)
            }
            continue
          }
        }

        for (match in matches) {
          performOneGlobalReplace(match, replaceClause, holeBindings)

          /*
           * When multiple global-replace clauses exist, later clauses may depend on earlier ones.
           * To avoid accumulating redundant hole mappings (e.g., multiple :[name]),
           * apply only one match per clause, except for the last clause or specified.
           *
           * TODO(cnsun): this needs to have a better solution.
           */
          if (index < operations.lastIndex && !replaceClause.matchAll) {
            break
          }
        }
      }
    }

    private fun getTargetSubTreeForGlobalReplacement(
      globalReplaceClause: LatraTransformationDefinition.GlobalReplaceClause,
      holeBindings: ScopedPatternElementBindings,
    ): AbstractSparTreeNode {
      val insideHoleName = globalReplaceClause.inside
      return if (insideHoleName == null) {
        treeCopy.result.realRoot
      } else {
        holeBindings.getHoleBinding(insideHoleName)!!.single()
      }
    }

    internal fun processInsertClausesOnSparTreeCopy(holeBindings: ScopedPatternElementBindings) {
      for (insertClause in definition.rewritingTemplate.insert) {
        val nodeToInsert =
          insertClause.contentToInsert
            .performRewrite(
              latraArguments.sparTreeNodeFactory,
              holeBindings,
            ).result

        val root = treeCopy.result.realRoot
        val payload = AbstractNodePayload.SinglePayload(expectedAntlrRuleType = null)
        when (insertClause.location) {
          INSERT_AT_TOP -> {
            root.addChildAtIndex(
              // insert as the first child
              index = 0,
              child = nodeToInsert,
              payload = payload,
            )
          }

          INSERT_AT_BOTTOM -> {
            root.addChild(child = nodeToInsert, payload = payload)
          }

          INSERT_BEFORE_MATCH -> {
            tokenBeforeMatch.let { token ->
              if (token == null) {
                root.addChildAtIndex(index = 0, child = nodeToInsert, payload = payload)
              } else {
                token.parent!!.addChildAfterExistingChild(
                  existingChild = token,
                  newChild = nodeToInsert,
                  payload = payload,
                )
              }
            }
          }

          INSERT_AFTER_MATCH -> {
            tokenAfterMatch.let { token ->
              if (token == null) {
                root.addChild(child = nodeToInsert, payload = payload)
              } else {
                token.parent!!.addChildBeforeExistingChild(
                  existingChild = token,
                  newChild = nodeToInsert,
                  payload = payload,
                )
              }
            }
          }
        }

        treeCopy.result.realRoot.fixLinkIntegrity()
      }
    }
  }
}
