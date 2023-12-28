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
package org.perses.spartree

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import org.perses.antlr.GrammarHierarchy
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgram
import org.perses.program.TokenizedProgramFactory
import org.perses.spartree.AbstractTreeNode.NodeIdCopyStrategy
import org.perses.util.Util.lazyAssert
import org.perses.util.toImmutableList

/** A spar-tree, the primary data structure for the Perses program reduction.  */
class SparTree internal constructor(
  override val root: AbstractSparTreeNode,
  val sparTreeNodeFactory: SparTreeNodeFactory,
) : AbstractUnmodifiableSparTree() {

  val treeId: Int = ++globalTreeIdGenerator

  val grammarHierarchy: GrammarHierarchy
    get() = sparTreeNodeFactory.grammarHierarchy

  val tokenizedProgramFactory: TokenizedProgramFactory
    get() = sparTreeNodeFactory.tokenizedProgramFactory

  internal var version = 0
    private set

  @PublishedApi
  internal val dummyTokenHead = LexerRuleSparTreeNode(
    Int.MIN_VALUE,
    PersesToken.INVALID_TOKEN,
    antlrRule = null,
  )

  @PublishedApi
  internal val dummyTokenTail = LexerRuleSparTreeNode(
    Int.MIN_VALUE,
    PersesToken.INVALID_TOKEN,
    antlrRule = null,
  )
  private var program: TokenizedProgram
  private val editListeners = ArrayList<AbstractSparTreeEditListener>()

  init {
    root.linkLeafNodes()
    root.buildTokenIntervalInfoRecursive()
    dummyTokenHead.next = root.beginToken
    root.beginToken?.prev = dummyTokenHead
    dummyTokenTail.prev = root.endToken
    root.endToken?.next = dummyTokenTail

    program = computeTokenizedProgram()
  }

  fun hasTheSameEditListeners(listeners: Iterable<AbstractSparTreeEditListener>): Boolean {
    val copy = ArrayList<AbstractSparTreeEditListener>().apply {
      addAll(listeners)
    }
    editListeners.forEach {
      copy.removeIf { c -> c === it }
    }
    return copy.isEmpty()
  }

  /**
   * Create an edit of this spar-tree. Any modification to the edit is not materialized on this
   * tree.
   */
  fun createNodeDeletionEdit(
    actionSet: NodeDeletionActionSet,
  ): NodeDeletionTreeEdit {
    lazyAssert { !actionSet.isEmpty }
    return AbstractSparTreeEdit.createDeletionSparTreeEdit(this, actionSet)
  }

  fun createNodeReplacementEdit(
    actionSet: ChildHoistingActionSet,
  ): NodeReplacementTreeEdit {
    return AbstractSparTreeEdit.createReplacementSparTreeEdit(this, actionSet)
  }

  fun createAnyNodeReplacementEdit(
    actionSet: ChildHoistingActionSet,
  ): AnyNodeReplacementTreeEdit {
    return AbstractSparTreeEdit.createAnyNodeReplacementTreeEdit(this, actionSet)
  }

  fun createLatraGeneralEdit(
    actionSet: LatraGeneralActionSet,
  ): LatraGeneralTreeEdit {
    return AbstractSparTreeEdit.createLatraGeneralTreeEdit(this, actionSet)
  }

  @Synchronized
  fun applyEdit(treeEdit: AbstractSparTreeEdit<*>) {
    val programSizeBefore = program.tokenCount()
    treeEdit.applyToTree()
    val event = AbstractSparTreeEditListener.SparTreeEditEvent(
      programSizeBefore,
      treeEdit,
    )
    program = event.program
    lazyAssert({ program.tokens == computeTokenizedProgram().tokens }) {
      """|passed-in program: ${program.tokens}
         |computed program:  ${computeTokenizedProgram().tokens}
         |
      """.trimMargin()
    }
    editListeners.forEach { it.onAfterSparTreeEditApplied(event) }
    ++version
  }

  fun registerSparTreeEditListeners(
    listeners: List<AbstractSparTreeEditListener>,
  ) {
    listeners.forEach { registerSparTreeEditListener(it) }
  }

  fun copyListenersFrom(other: SparTree) {
    check(editListeners.isEmpty()) { "Can only copy listeners for tress without listeners." }
    registerSparTreeEditListeners(other.editListeners)
  }

  fun registerSparTreeEditListener(
    listener: AbstractSparTreeEditListener,
  ) {
    require(!editListeners.contains(listener))
    editListeners.add(listener)
  }

  fun removeSparTreeEditListener(listener: AbstractSparTreeEditListener) {
    require(editListeners.contains(listener))
    check(editListeners.remove(listener))
    check(!editListeners.contains(listener))
  }

  fun leafNodeSequence(): Sequence<LexerRuleSparTreeNode> {
    return generateSequence(seed = dummyTokenHead.next) {
      val next = it.next
      if (next === dummyTokenTail) {
        null
      } else {
        next
      }
    }
  }

  /**
   * This method is expensive, because each time it scans all the leaf nodes
   * until the i-th one is found.
   */
  fun getLatestNthLeafNodeCostly(index: Int): LexerRuleSparTreeNode {
    return leafNodeSequence().elementAt(index)
  }

  // TODO: test
  val remainingLexerRuleNodes: ImmutableList<LexerRuleSparTreeNode>
    get() = leafNodeSequence().toImmutableList()

  /**
   * This operation is expensive. It scans the entire tree to find the node. Be careful when you
   * call this API.
   *
   *
   * This API should be only used in testing, and should be replaced with [ ][org.perses.TestUtility.getNodeWithTokens]
   */
  @VisibleForTesting
  fun getNodeByTreeScanForId(
    id: Int,
  ): AbstractSparTreeNode? {
    val result = ArrayList<AbstractSparTreeNode>(1)
    root.preOrderVisit {
      if (it.nodeId == id) {
        result.add(it)
        ImmutableList.of()
      } else {
        it.immutableChildView
      }
    }
    check(result.size < 2)
    return if (result.isEmpty()) null else result.single()
  }

  fun getTokenNodeForText(text: String): ImmutableList<LexerRuleSparTreeNode> {
    return leafNodeSequence().filter {
      it.token.text == text
    }.toImmutableList()
  }

  /** The returned program might be stale if this tree is modified later.  */
  override val programSnapshot: TokenizedProgram
    get() {
      lazyAssert { program.tokens == computeTokenizedProgram().tokens }
      return program
    }

  fun customizeProgram(customizer: AbstractTokenizedProgramCustomizer): TokenizedProgram {
    root.preOrderVisit { customizer.visit(it) }
    return TokenizedProgram(customizer.result, tokenizedProgramFactory)
  }

  fun updateLeafTokenCount() {
    root.updateLeafTokenCount()
  }

  fun printTreeStructureToStdout() {
    println(printTreeStructure())
  }

  override fun printTreeStructure(): String {
    return root.printTreeStructure()
  }

  fun deepCopy(nodeIdCopyStrategy: NodeIdCopyStrategy): SparTree {
    return SparTree(root.recursiveDeepCopy(nodeIdCopyStrategy), sparTreeNodeFactory)
  }

  private fun computeTokenizedProgram(): TokenizedProgram {
    return TokenizedProgram(
      leafNodeSequence().map { it.token }.toImmutableList(),
      tokenizedProgramFactory,
    )
  }

  private fun validateTreeIntegrity(): Boolean {
    val leafNodes = ArrayList<LexerRuleSparTreeNode>()
    root.postOrderVisit {
      if (it is LexerRuleSparTreeNode) {
        leafNodes.add(it)
      }
    }
    val leafNodesFromLinkedList = leafNodeSequence().toImmutableList()
    lazyAssert({ leafNodes == leafNodesFromLinkedList }) {
      """
        leaf nodes from the root: $leafNodes
        leaf nodes from the linked leaves: $leafNodesFromLinkedList
      """.trimIndent()
    }
    return leafNodes == leafNodesFromLinkedList
  }

  companion object {
    private var globalTreeIdGenerator = 0

    internal fun updateTokenIntervalUpToRoot(
      startNode: AbstractSparTreeNode,
    ): Boolean {
      var nodeInfo: AbstractSparTreeNode? = startNode
      var globalChanged = false
      while (nodeInfo != null) {
        val node = nodeInfo.asParserRule()
        var changed = false
        val leftmostToken = node.leftmostToken
        if (node.beginToken !== leftmostToken) {
          node.beginToken = leftmostToken
          changed = true
        }
        val rightmostToken = node.rightmostToken
        if (node.endToken !== rightmostToken) {
          node.endToken = rightmostToken
          changed = true
        }
        if (!changed) {
          break
        }
        globalChanged = true
        nodeInfo = node.parent
      }
      return globalChanged
    }

    internal fun fixLeafLinkByDeleting(
      leftInclusive: LexerRuleSparTreeNode,
      rightExclusive: LexerRuleSparTreeNode,
    ) {
      if (leftInclusive === rightExclusive) {
        return
      }
      val prevLeftInclusive = leftInclusive.prev!!
      prevLeftInclusive.next = rightExclusive
      rightExclusive.prev = prevLeftInclusive
    }
  }
}
