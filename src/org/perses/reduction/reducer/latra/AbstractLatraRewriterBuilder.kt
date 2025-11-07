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

import com.google.common.flogger.FluentLogger
import org.perses.reduction.reducer.latra.language.LatraTransformationDefinition
import org.perses.spartree.LatraGeneralActionSet
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTree

abstract class AbstractLatraRewriterBuilder(
  protected val matches: List<SparTreeHoleMatch>,
  protected val origSparTree: SparTree,
  protected val definition: LatraTransformationDefinition,
  protected val latraArguments: LatraArguments,
) {
  protected val actionDescription =
    "Latra Transformation ${definition.name} created by ${this::class.simpleName}"

  abstract fun build(): LatraGeneralActionSet?

  companion object {
    @JvmStatic
    protected val logger: FluentLogger = FluentLogger.forEnclosingClass()

    @JvmStatic
    protected fun doLeafSequencesHaveSameNonBlankLexemes(
      s1: Sequence<LexerRuleSparTreeNode>,
      s2: Sequence<LexerRuleSparTreeNode>,
    ): Boolean {
      val list1 = s1.map { it.token.lexemeText }.filter { it.isNotBlank() }.toList()
      val list2 = s2.map { it.token.lexemeText }.filter { it.isNotBlank() }.toList()
      return list1 == list2
    }

    fun smartCreate(
      matches: List<SparTreeHoleMatch>,
      origSparTree: SparTree,
      definition: LatraTransformationDefinition,
      latraArguments: LatraArguments,
    ): AbstractLatraRewriterBuilder {
      val rewritingTemplate = definition.rewritingTemplate
      return if (rewritingTemplate.insert.isEmpty() && rewritingTemplate.globalReplace.isEmpty()) {
        LatraRewriterBuilderForSimpleFromToPattern(
          matches,
          origSparTree,
          definition,
          latraArguments,
        )
      } else {
        FullFunctionalLatraRewriterBuilder(matches, origSparTree, definition, latraArguments)
      }
    }
  }
}
