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

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import org.perses.antlr.RuleHierarchyEntry
import org.perses.antlr.RuleType
import org.perses.util.Util.lazyAssert
import org.perses.util.toImmutableList
import java.io.IOError
import java.io.IOException
import java.io.StringWriter
import java.io.Writer

sealed class AbstractSparTreeNode(
  nodeId: Int,
  val antlrRule: RuleHierarchyEntry?,
) : AbstractTreeNode<AbstractSparTreeNode, AbstractNodePayload>(nodeId) {

  /** The count of tokens under this node.  */
  var leafTokenCount = INVALID_LEAF_TOKEN_COUNT
    protected set

  protected abstract val labelPrefix: String

  val isTokenNode: Boolean
    get() = this is LexerRuleSparTreeNode

  val isKleeneStarRuleNode: Boolean
    get() = this is ParserRuleSparTreeNode && this.ruleType === RuleType.KLEENE_STAR

  val isKleenePlusRuleNode: Boolean
    get() = this is ParserRuleSparTreeNode && this.ruleType === RuleType.KLEENE_PLUS

  val isQuantifierNode: Boolean
    get() = isKleenePlusRuleNode || isKleeneStarRuleNode || isOptionalRuleNode

  val isOptionalRuleNode: Boolean
    get() = this is ParserRuleSparTreeNode && this.ruleType === RuleType.OPTIONAL

  val ruleName: String
    get() {
      return antlrRule.let {
        check(it != null) { this }
        it.ruleName
      }
    }

  open fun asParserRule(): ParserRuleSparTreeNode {
    TODO("The current class is ${this::class}. $this")
  }

  open fun asLexerRule(): LexerRuleSparTreeNode {
    TODO("The current class is ${this::class}. $this")
  }

  /**
   * Update the leaf token count
   *
   * @return the number of leaf tokens.
   */
  fun updateLeafTokenCount(): Int {
    postOrderVisit { node ->
      if (node.isTokenNode) {
        node.leafTokenCount = 1
      } else {
        var countNum = 0
        val num = node.childCount
        for (i in 0 until num) {
          countNum += node.getChild(i).leafTokenCount
        }
        node.leafTokenCount = countNum
      }
    }
    return leafTokenCount
  }

  fun leafNodeSequence(): Sequence<LexerRuleSparTreeNode> {
    lazyAssert({ checkLeafLinkIntegrity() == null }) { checkLeafLinkIntegrity()!! }
    return internalLeafNodeSequence()
  }

  private fun internalLeafNodeSequence(): Sequence<LexerRuleSparTreeNode> {
    return sequence {
      var i = beginToken
      while (i != null && i !== endToken) {
        yield(i)
        i = i.next
      }
      if (i != null && i === endToken) {
        yield(i)
      }
    }
  }

  private fun checkLeafLinkIntegrity(): ErrorMessage? {
    val errors = ImmutableList.builder<String>()
    val leaves = collectLeavesWithPostorder()
    val anotherLeaves = internalLeafNodeSequence().toImmutableList()
    if (leaves.toList() != anotherLeaves.toList()) {
      errors.add("leaf node links are not updated.")
    }
    if (leaves.size != anotherLeaves.size) {
      errors.add("leaf node links are not updated.")
    }
    return errors.build().let {
      if (it.isEmpty()) {
        null
      } else {
        ErrorMessage(it)
      }
    }
  }
  override fun checkNodeIntegrity(): ErrorMessage? {
    return null
  }

  private fun collectLeavesWithPostorder(): MutableList<LexerRuleSparTreeNode> {
    val leaves = mutableListOf<LexerRuleSparTreeNode>()
    postOrderVisit { node ->
      if (node is LexerRuleSparTreeNode) {
        leaves.add(node)
      }
    }
    return leaves
  }

  fun buildTokenIntervalInfoRecursive() {
    postOrderVisit { it.buildTokenIntervalInfoForCurrentNode() }
  }

  protected abstract fun buildTokenIntervalInfoForCurrentNode()

  override fun toString(): String {
    return MoreObjects.toStringHelper(this)
      .add("id", nodeId)
      .add("parent", parent?.nodeId ?: "null")
      .toString()
  }

  abstract var beginToken: LexerRuleSparTreeNode?
    internal set

  abstract var endToken: LexerRuleSparTreeNode?
    internal set

  override fun equals(other: Any?): Boolean {
    return this === other
  }

  override fun hashCode(): Int {
    return nodeId
  }

  fun printTreeStructure(): String {
    return printTreeStructure(this)
  }

  override fun recursiveDeepCopy(nodeIdCopyStrategy: NodeIdCopyStrategy): AbstractSparTreeNode {
    val copyNode = super.recursiveDeepCopy(nodeIdCopyStrategy)
    copyNode.buildTokenIntervalInfoRecursive()
    copyNode.linkLeafNodes()
    return copyNode
  }

  fun linkLeafNodes() {
    // TODO(cnsun): this can be improved with the 'yield' and iterator.
    val nodes = ArrayList<LexerRuleSparTreeNode>(5000)
    preOrderVisit { node: AbstractSparTreeNode ->
      if (node.isPermanentlyDeleted) {
        return@preOrderVisit emptyList()
      }
      if (node is LexerRuleSparTreeNode) {
        nodes.add(node)
        return@preOrderVisit emptyList()
      }
      node.immutableChildView
    }
    for (i in 1 until nodes.size) {
      val prev = nodes[i - 1]
      val curr = nodes[i]
      prev.next = curr
      curr.prev = prev
    }
  }

  companion object {

    private const val INVALID_LEAF_TOKEN_COUNT = Int.MIN_VALUE

    fun printTreeStructure(root: AbstractSparTreeNode): String {
      val writer = StringWriter()
      try {
        printTreeStructure(root, writer)
      } catch (e: IOException) {
        throw IOError(e)
      }
      writer.flush()
      return writer.toString()
    }

    fun printTreeStructure(root: AbstractSparTreeNode, writer: Writer) {
      writer.append(getStringLabel(root)).append('\n')
      printTreeStructure(root, writer, ArrayList())
    }

    private fun outputPrefix(
      writer: Writer,
      prefix: ArrayList<String>,
      additionalPrefix: String,
    ): Writer {
      for (p in prefix) {
        writer.append(p)
      }
      writer.append(additionalPrefix)
      return writer
    }

    fun printTreeStructure(
      root: AbstractSparTreeNode,
      writer: Writer,
      prefix: ArrayList<String>,
    ) {
      val childCount = root.childCount
      if (childCount == 0) {
        return
      }
      for (i in 0 until childCount) {
        outputPrefix(writer, prefix, "|___")
        prefix.add(if (i == childCount - 1) "    " else "|   ")
        val child = root.getChild(i)
        writer.append(getStringLabel(child)).append('\n')
        printTreeStructure(child, writer, prefix)
        prefix.removeAt(prefix.size - 1)
      }
    }

    private fun getStringLabel(node: AbstractSparTreeNode): String {
      val builder = StringBuilder()
      builder.append(node.labelPrefix)
      builder.append(" {")
      builder.append("id=").append(node.nodeId)
      node.payload?.let {
        builder.append(",").append("slot_type=").append(it.label())
      }

      builder.append("}")
      return builder.toString()
    }
  }
}
