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
import com.google.common.base.MoreObjects
import org.perses.antlr.RuleHierarchyEntry
import org.perses.antlr.RuleType
import org.perses.antlr.pnf.AstUtil.computeNodeType
import java.io.IOError
import java.io.IOException
import java.io.StringWriter
import java.io.Writer

abstract class AbstractSparTreeNode internal constructor(
  nodeId: Int,
  val antlrRule: RuleHierarchyEntry?,
) : AbstractTreeNode<AbstractSparTreeNode, AbstractNodePayload>(nodeId) {

  val nodeType: RuleType = computeNodeType(antlrRule)

  /** The count of tokens under this node.  */
  var leafTokenCount = INVALID_LEAF_TOKEN_COUNT
    protected set

  protected abstract val labelPrefix: String

  abstract val isTokenNode: Boolean

  val isKleeneStarRuleNode: Boolean
    get() = nodeType === RuleType.KLEENE_STAR

  val isKleenePlusRuleNode: Boolean
    get() = nodeType === RuleType.KLEENE_PLUS

  val isQuantifierNode: Boolean
    get() = isKleenePlusRuleNode || isKleeneStarRuleNode || isOptionalRuleNode

  val isOptionalRuleNode: Boolean
    get() = nodeType === RuleType.OPTIONAL

  val ruleName: String
    get() {
      return antlrRule.let {
        check(it != null) { this }
        it.ruleName
      }
    }

  open fun asParserRule(): ParserRuleSparTreeNode {
    TODO()
  }

  open fun asLexerRule(): LexerRuleSparTreeNode {
    TODO()
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

  override fun recursiveDeepCopy(): AbstractSparTreeNode {
    val copyNode = super.recursiveDeepCopy()
    copyNode.buildTokenIntervalInfoRecursive()
    copyNode.linkLeafNodes()
    return copyNode
  }

  internal fun linkLeafNodes() {
    // TODO: this can be improved with the 'yield' and iterator.
    val nodes = ArrayList<LexerRuleSparTreeNode>(5000)
    preOrderVisit { node: AbstractSparTreeNode ->
      if (node.isPermanentlyDeleted) {
        return@preOrderVisit emptyList()
      }
      if (node.nodeType == RuleType.TOKEN) {
        nodes.add(node as LexerRuleSparTreeNode)
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

    @VisibleForTesting
    fun computeNodeType(antlrRule: RuleHierarchyEntry?): RuleType {
      if (antlrRule == null) {
        return RuleType.TOKEN
      }
      val ruleDef = antlrRule.ruleDef
      return computeNodeType(ruleDef)
    }
  }
}
