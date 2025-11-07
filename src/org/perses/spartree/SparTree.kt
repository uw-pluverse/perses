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
package org.perses.spartree

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ArrayListMultimap
import com.google.common.collect.ImmutableList
import it.unimi.dsi.fastutil.ints.Int2ObjectMap
import it.unimi.dsi.fastutil.ints.Int2ObjectOpenHashMap
import org.perses.antlr.GrammarHierarchy
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram
import org.perses.program.TokenizedProgramFactory
import org.perses.spartree.AbstractTreeNode.NodeIdCopyStrategy
import org.perses.util.Util
import org.perses.util.Util.lazyAssert
import org.perses.util.toImmutableList
import org.perses.util.transformToImmutableList
import java.lang.ref.WeakReference

/** A spar-tree, the primary data structure for the Perses program reduction.  */
class SparTree internal constructor(
  realRoot: AbstractSparTreeNode?,
  val sparTreeNodeFactory: SparTreeNodeFactory,
  specifiedSentinelRoot: SparTreeSentinelRootNode? = null,
) : AbstractUnmodifiableSparTree() {
  init {
    require(realRoot == null || !realRoot.isPermanentlyDeleted) {
      """The realRoot cannot be marked as deleted. 
        |realRoot = ${realRoot!!.printTreeStructure()}
        |
      """.trimMargin()
    }
    require(realRoot == null || realRoot !is SparTreeSentinelRootNode) { realRoot!!::class }
    require(specifiedSentinelRoot == null || specifiedSentinelRoot.childCount == 0) {
      "Sentinel root must have no child."
    }
  }

  private val sentinelRoot =
    (specifiedSentinelRoot ?: sparTreeNodeFactory.createSentinelRootNode()).also {
      if (realRoot != null) {
        it.addChild(
          realRoot,
          AbstractNodePayload.SinglePayload(expectedAntlrRuleType = realRoot.antlrRule),
        )
      }
    }

  val treeId: Int = ++globalTreeIdGenerator

  val grammarHierarchy: GrammarHierarchy
    get() = sparTreeNodeFactory.grammarHierarchy

  val tokenizedProgramFactory: TokenizedProgramFactory
    get() = sparTreeNodeFactory.tokenizedProgramFactory

  internal var version = 0
    private set

  var dirty = false
    private set

  override fun hasRealRoot(): Boolean {
    check(sentinelRoot.childCount.let { it == 0 || it == 1 }) {
      "Invalid child count for sentinelRoot. ${sentinelRoot.childCount}"
    }
    return sentinelRoot.childCount > 0
  }

  override val realRoot: AbstractSparTreeNode
    get() {
      check(hasRealRoot()) {
        """This tree is empty and does not have a root.
          |
          |The sentinel root: ${sentinelRoot.printTreeStructure()}
          |
        """.trimMargin()
      }
      return sentinelRoot.getChild(0)
    }

  fun detachRootFromTree(): AbstractSparTreeNode {
    val root = this.realRoot
    sentinelRoot.removeChild(root)
    root.resetPayload()
    dummyTokenHead.next = dummyTokenTail
    dummyTokenTail.prev = dummyTokenHead
    return root
  }

  @PublishedApi
  internal val dummyTokenHead =
    LexerRuleSparTreeNode(
      Int.MIN_VALUE,
      PersesTokenFactory.InvalidToken,
      antlrRule = null,
    )

  @PublishedApi
  internal val dummyTokenTail =
    LexerRuleSparTreeNode(
      Int.MIN_VALUE,
      PersesTokenFactory.InvalidToken,
      antlrRule = null,
    )
  private var program: TokenizedProgram
  private val editListeners = ArrayList<AbstractSparTreeEditListener>()

  fun isDummyNode(node: LexerRuleSparTreeNode): Boolean =
    node === dummyTokenHead || node === dummyTokenTail

  fun hasTheSameEditListeners(listeners: Iterable<AbstractSparTreeEditListener>): Boolean {
    val copy =
      ArrayList<AbstractSparTreeEditListener>().apply {
        addAll(listeners)
      }
    editListeners.forEach {
      copy.removeIf { c -> c === it }
    }
    return copy.isEmpty()
  }

  private class Id2NodeMap(
    var lastRoot: WeakReference<AbstractSparTreeNode>,
    var treeVersion: Int,
  ) {
    val map: Int2ObjectMap<AbstractSparTreeNode> = Int2ObjectOpenHashMap()
  }

  private val id2NodeMap by lazy {
    // Note that we need to use the "this.realRoot" to refer to the field, but not the argument.
    Id2NodeMap(
      lastRoot = WeakReference(this.realRoot),
      treeVersion = version,
    ).also {
      val map = it.map
      this.realRoot.postOrderVisit { node ->
        check(!map.containsKey(node.nodeId)) {
          "Duplicate node ids: ${map[node.nodeId]}, $node"
        }
        map.put(node.nodeId, node)
      }
    }
  }

  // TODO(cnsun): needs tests
  @Synchronized
  fun getNodeId2NodeMap(): Int2ObjectMap<AbstractSparTreeNode> {
    val map = id2NodeMap.map
    if (version == id2NodeMap.treeVersion) {
      return map
    }
    // TODO(cnsun): code duplication here.
    if (id2NodeMap.lastRoot.get() == realRoot) {
      // The same root, means the tree has not been completely changed.
      map.clear()
      realRoot.postOrderVisit { node ->
        check(!map.containsKey(node.nodeId)) {
          "Duplicate node ids: ${map[node.nodeId]}, $node"
        }
        map.put(node.nodeId, node)
      }
    } else {
      // The tree has been completely changed, so need to rebuild the map
      val map = id2NodeMap.map
      map.clear()
      realRoot.postOrderVisit { node ->
        check(!map.containsKey(node.nodeId)) {
          "Duplicate node ids: ${map[node.nodeId]}, $node"
        }
        map.put(node.nodeId, node)
      }
    }
    return map
  }

  /**
   * Create an edit of this spar-tree. Any modification to the edit is not materialized on this
   * tree.
   */
  fun createNodeDeletionEdit(actionSet: NodeDeletionActionSet): NodeDeletionTreeEdit {
    lazyAssert { !actionSet.isEmpty }
    return AbstractSparTreeEdit.createDeletionSparTreeEdit(this, actionSet)
  }

  fun createNodeReplacementEdit(actionSet: NodeReplacementActionSet): DescendantHoistingTreeEdit =
    AbstractSparTreeEdit.createReplacementSparTreeEdit(this, actionSet)

  fun createRootReplacementEdit(
    newRoot: AbstractSparTreeNode,
    actionsDescription: String,
  ): AnyNodeReplacementTreeEdit {
    require(newRoot.parent == null) { "New root node must have no parent" }
    return createAnyNodeReplacementEdit(
      NodeReplacementActionSet.createByReplacingSingleNode(
        targetNode = realRoot,
        replacingNode = newRoot,
        actionsDescription = actionsDescription,
      ),
    )
  }

  fun createAnyNodeReplacementEdit(
    actionSet: NodeReplacementActionSet,
  ): AnyNodeReplacementTreeEdit =
    AbstractSparTreeEdit.createAnyNodeReplacementTreeEdit(this, actionSet)

  fun createLatraGeneralEdit(actionSet: LatraGeneralActionSet): LatraGeneralTreeEdit =
    AbstractSparTreeEdit.createLatraGeneralTreeEdit(this, actionSet)

  @Synchronized
  fun applyEdit(treeEdit: AbstractSparTreeEdit<*>) {
    val programSizeBefore = program.tokenCount
    treeEdit.applyToTree()
    updateLeafTokenCount()
    val event =
      AbstractSparTreeEditListener.SparTreeEditEvent(
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
    dirty = true
    lazyAssert({ validateTreeIntegrity() }) {
      "Invalid spartree after applying edit ${treeEdit::class}"
    }
  }

  fun registerSparTreeEditListeners(listeners: List<AbstractSparTreeEditListener>) {
    listeners.forEach { registerSparTreeEditListener(it) }
  }

  fun copyListenersFrom(other: SparTree) {
    check(editListeners.isEmpty()) { "Can only copy listeners for tress without listeners." }
    registerSparTreeEditListeners(other.editListeners)
  }

  fun registerSparTreeEditListener(listener: AbstractSparTreeEditListener) {
    require(!editListeners.contains(listener))
    editListeners.add(listener)
  }

  fun removeSparTreeEditListener(listener: AbstractSparTreeEditListener) {
    require(editListeners.contains(listener))
    check(editListeners.remove(listener))
    check(!editListeners.contains(listener))
  }

  fun leafNodeSequence(): Sequence<LexerRuleSparTreeNode> {
    val seed = dummyTokenHead.next
    if (seed === dummyTokenTail) {
      return emptySequence()
    }
    return generateSequence(seed) {
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
  fun getLatestNthLeafNodeCostly(index: Int): LexerRuleSparTreeNode =
    leafNodeSequence().elementAt(index)

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
  fun getNodeByTreeScanForId(id: Int): AbstractSparTreeNode? {
    val result = ArrayList<AbstractSparTreeNode>(1)
    realRoot.preOrderVisit {
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

  fun getTokenNodeForText(text: String): ImmutableList<LexerRuleSparTreeNode> =
    leafNodeSequence()
      .filter {
        it.token.lexemeText == text
      }.toImmutableList()

  /** The returned program might be stale if this tree is modified later.  */
  override val programSnapshot: TokenizedProgram
    get() {
      lazyAssert { validateTreeIntegrity() }
      lazyAssert({ program.tokens == computeTokenizedProgram().tokens }) {
        val snapshot = program.tokens
        val computed = computeTokenizedProgram().tokens
        """
          |
          |program:  $snapshot
          |
          |computed: $computed
        """.trimMargin()
      }
      return program
    }

  fun customizeProgram(customizer: AbstractTokenizedProgramCustomizer): TokenizedProgram {
    realRoot.preOrderVisit { customizer.visit(it) }
    return TokenizedProgram(customizer.result, tokenizedProgramFactory)
  }

  fun updateLeafTokenCount(): Int =
    if (hasRealRoot()) {
      realRoot.updateLeafTokenCount()
    } else {
      0
    }

  fun printTreeStructureToStdout() {
    println(printTreeStructure())
  }

  override fun printTreeStructure(): String = realRoot.printTreeStructure()

  fun deepCopy(
    nodeIdCopyStrategy: NodeIdCopyStrategy,
  ): DeepCopyResult<SparTree, AbstractSparTreeNode> {
    val realRootNodeCopy = realRoot.recursiveDeepCopy(nodeIdCopyStrategy)
    val sentinelRootCopy =
      SparTreeSentinelRootNode(
        nodeId = sentinelRoot.nodeId,
      )
    return realRootNodeCopy.transform {
      SparTree(
        realRoot = it,
        sparTreeNodeFactory = sparTreeNodeFactory,
        specifiedSentinelRoot = sentinelRootCopy,
      )
    }
  }

  private fun computeTokenizedProgram(): TokenizedProgram =
    tokenizedProgramFactory.createFromLeaves(
      leafNodeSequence().transformToImmutableList { it.token },
    )

  fun validateTreeIntegrity(): Boolean {
    if (!hasRealRoot()) {
      return true
    }
    val leafNodes =
      ImmutableList.builder<LexerRuleSparTreeNode>().let { builder ->
        realRoot.postOrderVisit {
          if (it is LexerRuleSparTreeNode) {
            builder.add(it)
          }
        }
        builder.build()
      }
    val leafNodesFromLinkedList = leafNodeSequence().toImmutableList()
    lazyAssert({ leafNodes == leafNodesFromLinkedList }) {
      """Different leaves detected.
       |leaf nodes via root: ${leafNodes.map { it.token.lexemeText }}
       |leaf nodes via link: ${leafNodesFromLinkedList.map { it.token.lexemeText }}
       |
       |node hash via root: ${leafNodes.map { System.identityHashCode(it) }}
       |node hash via link: ${leafNodesFromLinkedList.map { System.identityHashCode(it) }}
      """.trimMargin()
    }
    return leafNodes == leafNodesFromLinkedList
  }

  fun lazyAssertTreeNodeIdsAreUnique() {
    if (Util.ASSERTION_ENABLED) {
      val nodeIds = ArrayListMultimap.create<Int, AbstractSparTreeNode>()
      realRoot.postOrderVisit { node ->
        nodeIds.put(node.nodeId, node)
      }
      val nodesWithDuplicateNodeIds = nodeIds.asMap().filter { it.value.size > 1 }
      if (nodesWithDuplicateNodeIds.isNotEmpty()) {
        error(
          buildString {
            appendLine("The following nodes have duplicate ids")
            nodesWithDuplicateNodeIds.forEach { (nodeId, nodes) ->
              appendLine("node id: $nodeId")
              nodes.forEach { node ->
                appendLine("    ${node.printTreeStructure()}")
              }
            }
          },
        )
      }
    }
  }

  companion object {
    private var globalTreeIdGenerator = 0

    internal fun updateTokenIntervalUpToRoot(startNode: AbstractSparTreeNode): Boolean {
      var nodeInfo: AbstractSparTreeNode? = startNode
      var globalChanged = false
      while (nodeInfo != null && nodeInfo.isParserRuleNode()) {
        val node = nodeInfo.asParserRule()
        var changed = false
        val leftmostToken = node.computeLeftmostTokenBasedOnChildren()
        if (node.beginToken !== leftmostToken) {
          node.beginToken = leftmostToken
          changed = true
        }
        val rightmostToken = node.computeRightmostTokenBasedOnChildren()
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

  fun fixLinkIntegrityAndUpdateProgram() {
    fixLinkIntegrity()
    program = computeTokenizedProgram()
  }

  private fun fixLinkIntegrity() {
    sentinelRoot.fixLinkIntegrity()
    dummyTokenHead.next = sentinelRoot.beginToken
    sentinelRoot.beginToken?.prev = dummyTokenHead
    dummyTokenTail.prev = sentinelRoot.endToken
    sentinelRoot.endToken?.next = dummyTokenTail
  }

  init {
    updateLeafTokenCount()
    fixLinkIntegrity()
    program = computeTokenizedProgram()
  }
}
