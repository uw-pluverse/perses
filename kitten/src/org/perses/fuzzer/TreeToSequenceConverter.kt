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
package org.perses.fuzzer

import com.google.common.collect.ImmutableList
import org.perses.antlr.ast.AbstractPersesQuantifiedAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesTerminalAst
import org.perses.fuzzer.languagemodel.NodeRepresentation
import org.perses.fuzzer.languagemodel.NodeRepresentationList
import org.perses.spartree.AbstractNodePayload
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.TreeNodeFilterResult
import kotlin.math.min

object TreeToSequenceConverter {

  fun convertWithPreOrder(node: AbstractSparTreeNode): NodeRepresentationList {
    val builder = NodeRepresentationList.Builder()
    node.preOrderVisit {
      builder.addAll(encodeNode(it))
      return@preOrderVisit it.immutableChildView
    }
    return builder.build()
  }

  fun convertWithBreadthFirstOrder(
    node: AbstractSparTreeNode,
    limit: Int,
  ): NodeRepresentationList {
    val builder = NodeRepresentationList.Builder(limit)
    node.boundedBFSChildren { child, _ ->
      val childEncoding = encodeNode(child)
      val endIndexExclusive = min(childEncoding.size, limit - builder.size)
      assert(endIndexExclusive >= 0)
      builder.addSubListOf(childEncoding, startIndexInclusive = 0, endIndexExclusive)
      if (builder.size >= limit) {
        // A node with collapse payload may be encoded to more than one NodeRepresentation
        val result = builder.build()
        assert(result.size == limit)
        return result
      }
      return@boundedBFSChildren TreeNodeFilterResult.CONTINUE
    }
    return builder.build()
  }

  // return NodeRepresentation of the given node if the
  // rule of the node is altblock ast or quantified ast
  private fun encodeNode(
    node: AbstractSparTreeNode,
  ): NodeRepresentationList {
    val builder = NodeRepresentationList.Builder()
    if (node.isTokenNode) {
      builder.addAll(encodeTokenNode(node))
      return builder.build()
    }
    if (node.payload != null) {
      builder.addAll(encodePayload(node.payload!!.asSinglePayloadList))
    }
    val rule = node.antlrRule!!.ruleDef
    if (rule.body is AbstractPersesQuantifiedAst) {
      // childCount cannot be 0, because SparTreeSimplifier delete those nodes
      val featureValue = if (node.childCount > 1) {
        1
      } else {
        0
      }
      builder.add(NodeRepresentation.create(rule.ruleNameHandle.id, featureValue))
    } else if (rule.body is PersesAlternativeBlockAst) {
      builder.add(encodeAltNode(node))
    }
    return builder.build()
  }

  private fun encodeAltNode(
    node: AbstractSparTreeNode,
  ): NodeRepresentation {
    val rule = node.antlrRule!!.ruleDef
    assert(rule.body is PersesAlternativeBlockAst)
    assert(node.childCount > 0)
    if (node.childCount > 1) {
      throw AssertionError("a AltBlock should not have more than one child")
    }
    val child = if (node.getChild(0).isTokenNode) {
      "token_${node.getChild(0).asLexerRule().token.type}"
    } else {
      "rule_${
        node.getChild(0).payload!!.expectedAntlrRuleType!!.ruleDef.ruleNameHandle.id
      }"
    }
    val altNum = computeAltNum((rule.body as PersesAlternativeBlockAst).alternatives, child)
    return NodeRepresentation.create(rule.ruleNameHandle.id, altNum)
  }

  private fun encodePayload(
    payloadList: ImmutableList<AbstractNodePayload.SinglePayload>,
  ): NodeRepresentationList {
    assert(payloadList.size >= 1)
    val builder = NodeRepresentationList.Builder()
    for (i in 0 until payloadList.size - 1) {
      val rule = payloadList[i].actualAntlrRuleType!!.ruleDef
      val childRule = payloadList[i + 1].actualAntlrRuleType!!.ruleDef
      val child = "rule_${childRule.ruleNameHandle.id}"
      // QuantifiedAst will not be collapsed
      assert(rule.body !is AbstractPersesQuantifiedAst)
      if (rule.body is PersesAlternativeBlockAst) {
        val altNum = computeAltNum((rule.body as PersesAlternativeBlockAst).alternatives, child)
        val representation = NodeRepresentation.create(rule.ruleNameHandle.id, altNum)
        builder.add(representation)
      }
    }
    return builder.build()
  }

  private fun encodeTokenNode(
    node: AbstractSparTreeNode,
  ): NodeRepresentationList {
    assert(node.isTokenNode)
    val builder = NodeRepresentationList.Builder()
    val payloadList = node.payload?.asSinglePayloadList ?: return builder.build()
    if (payloadList.size > 2) {
      builder.addAll(encodePayload(payloadList.subList(0, payloadList.size - 1)))
    }
    return builder.build()
  }

  private fun computeAltNum(
    alternatives: ImmutableList<AbstractPersesRuleElement>,
    child: String,
  ): Int {
    val altNames = alternatives.map {
      when (it) {
        is PersesRuleReferenceAst -> {
          "rule_${it.ruleNameHandle.id}"
        }
        is PersesTerminalAst -> {
          "token_${it.tokenType}"
        }
        else -> {
          error("Unreachable")
        }
      }
    }
    val altNum = altNames.indexOf(child)
    if (altNum < 0) {
      throw AssertionError("cannot compute the altNum for AltBlock: $alternatives")
    }
    return altNames.indexOf(child)
  }
}
