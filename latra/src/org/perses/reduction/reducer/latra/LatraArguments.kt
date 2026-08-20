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
import org.perses.antlr.AntlrGrammarUtil
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.ParseErrorHandling
import org.perses.program.TokenizedProgram
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeBuilder
import org.perses.spartree.SparTreeNodeFactory
import org.perses.util.transformToImmutableList

// TODO(cnsun): needs tests.
data class LatraArguments(
  val canonicalParserFacade: AbstractParserFacade,
  val sparTreeNodeFactory: SparTreeNodeFactory,
  val programPrinter: IProgramPrinter,
  val prefixLabelFromRootToHere: String,
  private val logger: (prefixLabelFromRootToHere: String, () -> Any) -> Unit = { _, _ -> },
) {
  fun createWithNewExtraSuffixOfPrefix(extraSuffixOfPrefix: String): LatraArguments =
    LatraArguments(
      canonicalParserFacade = canonicalParserFacade,
      sparTreeNodeFactory = sparTreeNodeFactory,
      programPrinter = programPrinter,
      prefixLabelFromRootToHere = prefixLabelFromRootToHere + extraSuffixOfPrefix,
      logger = logger,
    )

  fun log(messageCreator: () -> Any) {
    logger.invoke(prefixLabelFromRootToHere, messageCreator)
  }

  fun printProgramOfSparTree(tree: SparTree): String =
    programPrinter.printToString(tree.programSnapshot.payload)

  fun reTokenizeProgram(tree: SparTree): ImmutableList<Token> =
    canonicalParserFacade.tokenizeString(printProgramOfSparTree(tree))

  fun reTokenizeProgram(program: TokenizedProgram): ImmutableList<Token> =
    canonicalParserFacade.tokenizeString(programPrinter.printToString(program))

  /**
   * convert a list of Nodes into string
   */
  fun createStringFromNodes(nodeList: List<AbstractSparTreeNode>): String {
    val tokens =
      nodeList
        .flatMap {
          it.leafNodeSequence()
        }.transformToImmutableList { it.token }
    val program = TokenizedProgram(tokens)
    return programPrinter.printToString(program)
  }

  fun createSparTree(program: String): SparTree {
    val parseTree =
      canonicalParserFacade.parseString(
        program,
        errorMode = ParseErrorHandling.STRICT,
      )
    return SparTreeBuilder(
      sparTreeNodeFactory,
      parseTree,
      simplifyTree = false,
      canonicalTokenCountComputer = { AntlrGrammarUtil.countLeafTokens(parseTree.tree) },
    ).result
  }

  fun rebuildSparTree(tree: SparTree): SparTree =
    createSparTree(programPrinter.printToString(tree.programSnapshot.payload))
}
