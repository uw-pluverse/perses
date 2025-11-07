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

import org.perses.reduction.reducer.latra.language.LatraTransformationDefinition
import org.perses.spartree.LatraGeneralActionSet
import org.perses.spartree.SparTree

// TODO(cnsun): needs tests.
class LatraRewriterBuilderForSimpleFromToPattern(
  matches: List<SparTreeHoleMatch>,
  origSparTree: SparTree,
  definition: LatraTransformationDefinition,
  latraArguments: LatraArguments,
) : AbstractLatraRewriterBuilder(matches, origSparTree, definition, latraArguments) {
  init {
    definition.rewritingTemplate.let {
      require(it.globalReplace.isEmpty()) {
        "${this::class} does not support definitions with global replace."
      }
      require(it.insert.isEmpty()) {
        "${this::class} does not support insertions."
      }
    }
  }

  override fun build(): LatraGeneralActionSet? {
    try {
      val builder = LatraGeneralActionSet.Builder(actionDescription)
      for (match in matches) {
        if (match.subtreeRoot.isPermanentlyDeleted) {
          throw LatraException(
            "The subtree ${match.printMatchInfo()} has been permanently deleted.",
          )
        }
        if (match.subtreeRoot.parent == null) {
          throw LatraException(
            "The subtree ${match.printMatchInfo()} has been detached from the tree.",
          )
        }
        val rewriteTreeResultOfTheToClause =
          definition.rewritingTemplate.to.performRewrite(
            latraArguments.sparTreeNodeFactory,
            match.holeBindings,
          )
        if (doLeafSequencesHaveSameNonBlankLexemes(
            match.subtreeRoot.leafNodeSequence(),
            rewriteTreeResultOfTheToClause.result.leafNodeSequence(),
          )
        ) {
          latraArguments.log {
            "The proposed transformation for the match ${match.printMatchInfo()} " +
              "has the same non-blank token sequence as the target node."
          }
          continue
        }
        builder.replaceNode(match.subtreeRoot, rewriteTreeResultOfTheToClause.result)
      }
      return builder.buildOrNull()
    } catch (e: LatraException) {
      latraArguments.log { "Exception: ${e.message}" }
      return null
    }
  }
}
