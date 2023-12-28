/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.reduction.reducer.vulcan

import org.perses.spartree.AnyNodeReplacementTreeEdit
import org.perses.spartree.ChildHoistingActionSet
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.util.Util.lazyAssert

object TokenEditUtility {

  fun createEditToReplaceAllLexerNodesHavingSameLexeme(
    tree: SparTree,
    oldLexeme: String,
    newLexeme: String,
  ): AnyNodeReplacementTreeEdit {
    lazyAssert { oldLexeme != newLexeme }
    return createEditToReplaceMultiNodes(
      tree = tree,
      newLexeme = newLexeme,
      nodesToBeReplaced = tree.leafNodeSequence().filter {
        it.token.text == oldLexeme
      }.toList(),
    )
  }

  fun createEditToReplaceSingleLexerNode(
    tree: SparTree,
    newLexeme: String,
    nodeToBeReplaced: LexerRuleSparTreeNode,
  ) = createEditToReplaceMultiNodes(
    tree,
    newLexeme,
    listOf(nodeToBeReplaced),
  )

  fun createEditToReplaceMultiNodes(
    tree: SparTree,
    newLexeme: String,
    nodesToBeReplaced: List<LexerRuleSparTreeNode>,
  ): AnyNodeReplacementTreeEdit {
    check(nodesToBeReplaced.isNotEmpty())
    val sparTreeNodeFactory = tree.sparTreeNodeFactory
    val builder = ChildHoistingActionSet
      .Builder("replace ${nodesToBeReplaced.size} lexer nodes with new lexeme '$newLexeme'")
    val tokenFactory = tree.tokenizedProgramFactory.tokenFactory
    nodesToBeReplaced.forEach { targetNode ->
      check(!targetNode.isPermanentlyDeleted)
      lazyAssert { newLexeme != targetNode.token.text }
      val replacement = sparTreeNodeFactory.copyWithNewToken(
        targetNode,
        tokenFactory.copyPersesTokenWithNewText(newLexeme, targetNode.token),
      )
      builder.replaceNode(targetNode = targetNode, replacement = replacement)
    }
    return tree.createAnyNodeReplacementEdit(builder.build())
  }
}
