/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
import org.perses.util.toImmutableList

/** A spar-tree, the primary data structure for the Perses program reduction.  */
class SparTree internal constructor(
  override val root: AbstractSparTreeNode,
  val grammarHierarchy: GrammarHierarchy,
  val tokenizedProgramFactory: TokenizedProgramFactory
) : AbstractUnmodifiableSparTree() {

  val treeId: Int = ++globalTreeIdGenerator

  @PublishedApi
  internal val dummyTokenHead = LexerRuleSparTreeNode(
    Int.MIN_VALUE, PersesToken.INVALID_TOKEN, antlrRule = null
  )

  @PublishedApi
  internal val dummyTokenTail = LexerRuleSparTreeNode(
    Int.MIN_VALUE, PersesToken.INVALID_TOKEN, antlrRule = null
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
    registerSparTreeEditListener(
      object : AbstractSparTreeEditListener() {
        override fun onAfterSparTreeEditApplied(event: SparTreeEditEvent) {
          program = event.program
          assert(program.tokens == computeTokenizedProgram().tokens) {
            """
              passed-in program: ${program.tokens}
              computed program:  ${computeTokenizedProgram().tokens}
            """.trimIndent()
          }
        }
      })
  }

  /**
   * Create an edit of this spar-tree. Any modification to the edit is not materialized on this
   * tree.
   */
  fun createNodeDeletionEdit(
    actionSet: NodeDeletionActionSet
  ): NodeDeletionTreeEdit {
    assert(!actionSet.isEmpty)
    return AbstractSparTreeEdit.createDeletionSparTreeEdit(this, actionSet)
  }

  fun createNodeReplacementEdit(
    actionSet: ChildHoistingActionSet
  ): NodeReplacementTreeEdit {
    return AbstractSparTreeEdit.createReplacementSparTreeEdit(this, actionSet)
  }

  fun createAnyNodeReplacementEdit(
    actionSet: ChildHoistingActionSet
  ): AnyNodeReplacementTreeEdit {
    return AbstractSparTreeEdit.createAnyNodeReplacementTreeEdit(this, actionSet)
  }

  @Synchronized
  fun applyEdit(treeEdit: AbstractSparTreeEdit<*>) {
    val programSizeBefore = program.tokenCount()
    when (treeEdit) {
      is NodeReplacementTreeEdit -> {
        applyNodeReplacementTreeEdit(treeEdit.asNodeReplacementEdit())
      }
      is AnyNodeReplacementTreeEdit -> {
        applyAnyNodeReplacementTreeEdit(treeEdit)
      }
      is NodeDeletionTreeEdit -> {
        applyNodeDeletionTreeEdit(treeEdit.asNodeDeleteEdit())
      }
      else -> error("Unhandled tree edit. $treeEdit")
    }
    val event = AbstractSparTreeEditListener.SparTreeEditEvent(
      programSizeBefore, treeEdit
    )
    editListeners.forEach { it.onAfterSparTreeEditApplied(event) }
  }

  private fun applyNodeDeletionTreeEdit(deletionEdit: NodeDeletionTreeEdit) {
    val actions = deletionEdit.actionSet.actions
    val parents = HashSet<AbstractSparTreeNode>()
    for (action in actions) {
      val targetNode = action.targetNode
      targetNode.delete()
      fixLeafLinkByDeleting(targetNode.beginToken!!, targetNode.endToken!!.next!!)
      if (targetNode.parent != null) {
        parents.add(targetNode.parent!!)
      }
    }
    for (parent in parents) {
      parent.cleanDeletedImmediateChildren()
    }
    var changed: Boolean
    do {
      changed = false
      for (parent in parents) {
        if (updateTokenIntervalUpToRoot(parent)) {
          changed = true
        }
      }
    } while (changed)
  }

  private fun applyNodeReplacementTreeEdit(replacement: NodeReplacementTreeEdit) {
    val action = replacement.actionSet.actions.single()
    val targetNode = action.targetNode
    val childToHoist = action.replacingChild
    childToHoist.parent!!.removeChild(childToHoist)
    assert(childToHoist.parent == null)
    var payload = AbstractNodePayload.concatenatePaylods(
      targetNode.payload!!,
      childToHoist.payload!!
    )
    childToHoist.resetPayload()
    targetNode.parent!!.replaceChild(
      targetNode, childToHoist, payload
    )
    assert(targetNode.parent == null)
    targetNode.delete()
    fixLeafLinkByDeleting(targetNode.beginToken!!, childToHoist.beginToken!!)
    fixLeafLinkByDeleting(childToHoist.endToken!!.next!!, targetNode.endToken!!.next!!)
    childToHoist.parent?.let { updateTokenIntervalUpToRoot(it) }
  }

  private fun applyAnyNodeReplacementTreeEdit(replacement: AnyNodeReplacementTreeEdit) {
    replacement.actionSet.actions.forEach { action ->
      val targetNode = action.targetNode
      val parentNode = targetNode.parent!!
      val replacingNode = action.replacingChild
      assert(replacingNode.parent == null)
      val payload = targetNode.payload!!
      replacingNode.resetPayload()
      parentNode.replaceChild(
        targetNode, replacingNode, payload
      )
      assert(targetNode.parent == null)
      targetNode.delete()

      // maintain leaf list
      val targetNodePre = if (targetNode is LexerRuleSparTreeNode)
        targetNode.prev else targetNode.beginToken?.prev
      val targetNodeNext = if (targetNode is LexerRuleSparTreeNode)
        targetNode.next else targetNode.endToken?.next

      if (targetNodePre != null) {
        targetNodePre.next = replacingNode.beginToken
        replacingNode.beginToken?.prev = targetNodePre
      }

      if (targetNodeNext != null) {
        targetNodeNext.prev = replacingNode.endToken
        replacingNode.endToken?.next = targetNodeNext
      }
      updateTokenIntervalUpToRoot(parentNode)
    }
  }

  private fun updateTokenIntervalUpToRoot(
    startNode: AbstractSparTreeNode
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

  fun registerSparTreeEditListeners(
    listeners: List<AbstractSparTreeEditListener>
  ) {
    listeners.forEach { registerSparTreeEditListener(it) }
  }

  fun registerSparTreeEditListener(
    listener: AbstractSparTreeEditListener
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

  fun getNthLeafNode(index: Int): LexerRuleSparTreeNode {
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
    id: Int
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
    return if (result.isEmpty()) null else result.first()
  }

  fun getTokenNodeForText(text: String): ImmutableList<LexerRuleSparTreeNode> {
    return leafNodeSequence().filter {
      it.token.text == text
    }.toImmutableList()
  }

  /** The returned program might be stale if this tree is modified later.  */
  override val programSnapshot: TokenizedProgram
    get() {
      assert(program.tokens == computeTokenizedProgram().tokens)
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

  fun deepCopy(): SparTree {
    return SparTree(root.recursiveDeepCopy(), grammarHierarchy, tokenizedProgramFactory)
  }

  private fun computeTokenizedProgram(): TokenizedProgram {
    return TokenizedProgram(
      leafNodeSequence().map { it.token }.toImmutableList(),
      tokenizedProgramFactory
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
    assert(leafNodes == leafNodesFromLinkedList) {
      """
        leaf nodes from the root: $leafNodes
        leaf nodes from the linked leaves: $leafNodesFromLinkedList
      """.trimIndent()
    }
    return leafNodes == leafNodesFromLinkedList
  }

  companion object {
    private var globalTreeIdGenerator = 0

    private fun fixLeafLinkByDeleting(
      leftInclusive: LexerRuleSparTreeNode,
      rightExclusive: LexerRuleSparTreeNode
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
