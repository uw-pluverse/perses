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

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.Token
import org.perses.grammar.AbstractParserFacade
import org.perses.program.TokenizedProgram
import org.perses.program.TokenizedProgramFactory
import org.perses.spartree.SparTreeNodeFactory
import org.perses.util.ktFine
import org.perses.util.toImmutableList
import org.perses.util.transformToImmutableList

abstract class AbstractTransformationTest<T : AbstractLatraTransformationList>(
  facadeList: ImmutableList<AbstractParserFacade>,
  val transformationList: T,
) {
  val latraArgsList =
    facadeList.transformToImmutableList {
      LatraArguments(
        parserFacade = it,
        sparTreeNodeFactory =
          SparTreeNodeFactory(
            it.metaTokenInfoDb,
            TokenizedProgramFactory.createEmptyFactory(it.language),
            it.ruleHierarchy,
          ),
        programPrinter = IProgramPrinter.create(it),
        prefixLabelFromRootToHere = "[test]",
      )
    }

  init {
    require(facadeList.isNotEmpty())
    require(latraArgsList.isNotEmpty())
  }

  protected fun testTransformation(
    transformationCreator: (LatraArguments) -> LatraTransformation,
    source: String,
    expectOutput1: String? = null,
    expectOutput2: String? = null,
    expectOutput3: String? = null,
  ) {
    latraArgsList.forEach { args ->
      val facade = args.parserFacade
      logger.ktFine { "The parser facade is ${facade::class.java}" }

      val transformation = transformationCreator(args)

      val expectOutputs = listOfNotNull(expectOutput1, expectOutput2, expectOutput3)
      val origTree = args.createSparTree(source)
      val edits =
        transformation
          .computeEdits(
            origTree,
          ).map { edit ->
            val reLexingToDeleteWhitespaces = args.reTokenizeProgram(edit.program)
            val result = joinAntlrTokensToString(reLexingToDeleteWhitespaces)
            result
          }.toImmutableList()
      val expectedContentList =
        expectOutputs.map { expectedProgram ->
          val tokens = facade.tokenizeString(expectedProgram)
          joinAntlrTokensToString(tokens)
        }
      assertThat(edits).containsExactlyElementsIn(expectedContentList)
      assertThat(edits).hasSize(expectedContentList.size)
    }
  }

  protected fun testTransformation(
    transformation: AbstractLatraTransformationList.Transformation,
    source: String,
    expectOutput1: String? = null,
    expectOutput2: String? = null,
    expectOutput3: String? = null,
  ) {
    testTransformation(
      transformationCreator = { transformation.create(it) },
      source = source,
      expectOutput1 = expectOutput1,
      expectOutput2 = expectOutput2,
      expectOutput3 = expectOutput3,
    )
  }

  private fun printProgramToString(program: TokenizedProgram): String =
    latraArgsList.first().programPrinter.printToString(program)

  private fun joinAntlrTokensToString(tokens: List<Token>): String =
    tokens.joinToString(separator = " ") { it.text }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
