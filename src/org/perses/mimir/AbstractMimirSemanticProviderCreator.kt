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
package org.perses.mimir

import com.google.common.flogger.FluentLogger
import org.jgrapht.graph.DefaultEdge
import org.jgrapht.graph.DirectedAcyclicGraph
import org.perses.mimir.lsp.LspSemanticToken
import org.perses.reduction.semantics.ISemanticsProvider
import org.perses.reduction.semantics.ISemanticsProviderCreator
import org.perses.reduction.semantics.SemanticTokenType
import org.perses.spartree.LexerRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.util.ktWarning
import java.nio.file.Path

/**
 * Base class for [ISemanticsProviderCreator] that builds a [MimirSemanticsProvider]
 * by coordinate with a dependency analyzer (Javac or LSP based).
 */
abstract class AbstractMimirSemanticProviderCreator : ISemanticsProviderCreator {
  override fun computeSemanticsForSparTree(
    sourceFilePath: Path,
    sparTree: SparTree,
  ): ISemanticsProvider {
    val defUseMap = computeDefUseMap(sourceFilePath)

    val position2lexNodeMap =
      sparTree
        .leafNodeSequence()
        .associateBy { leafNode -> leafNode.token.asAntlrToken().position }

    val defs = mutableListOf<LexerRuleSparTreeNode>()
    val graph =
      DirectedAcyclicGraph<LexerRuleSparTreeNode, DefaultEdge>(DefaultEdge::class.java)
    val semanticTokenTypeMap = mutableMapOf<LexerRuleSparTreeNode, SemanticTokenType>()

    defUseMap.entries.forEach { entry ->
      val defSemanticToken: LspSemanticToken = entry.key
      val defLexNode: LexerRuleSparTreeNode =
        position2lexNodeMap[defSemanticToken.antlrTokenPosition]
          ?: run {
            logger.ktWarning {
              "Cannot find a lexer node for the position ${defSemanticToken.antlrTokenPosition} (lexeme=${defSemanticToken.lexeme})"
            }
            return@forEach
          }

      semanticTokenTypeMap.put(defLexNode, defSemanticToken.type).let { oldValueType ->
        check(oldValueType == null || oldValueType === defSemanticToken.type)
      }
      if (!graph.containsVertex(defLexNode)) {
        graph.addVertex(defLexNode)
      }
      defs.add(defLexNode)

      val useSemanticTokens = entry.value
      useSemanticTokens.forEach { useSemanticToken ->
        val useLexNode =
          position2lexNodeMap[useSemanticToken.antlrTokenPosition]
            ?: run {
              logger.ktWarning {
                "Cannot find a lexer node for the position ${useSemanticToken.antlrTokenPosition} (lexeme=${useSemanticToken.lexeme})"
              }
              return@forEach
            }

        semanticTokenTypeMap.put(useLexNode, useSemanticToken.type).let { oldValueType ->
          if (oldValueType != null && oldValueType !== useSemanticToken.type) {
            logger.ktWarning {
              "Semantic type mismatch for node $useLexNode (id=${useLexNode.nodeId}) " +
                "at ${useLexNode.token.asAntlrToken().position}: " +
                "oldType=$oldValueType, newType=${useSemanticToken.type}, " +
                "lexeme=${useSemanticToken.lexeme}"
            }
          }
          check(oldValueType == null || oldValueType === useSemanticToken.type)
        }
        if (!graph.containsVertex(useLexNode)) {
          graph.addVertex(useLexNode)
        }

        try {
          if (!graph.containsEdge(defLexNode, useLexNode)) {
            graph.addEdge(defLexNode, useLexNode)
          }
        } catch (e: IllegalArgumentException) {
          val message = e.message
          if (message != null &&
            message.contains("cycle") &&
            graph.containsEdge(useLexNode, defLexNode)
          ) {
            // cycle detected, but reverse edge exists, so it's a mutual dependency
          } else {
            logger.ktWarning {
              "Failed to create edge from $defLexNode " +
                "(id=${defLexNode.nodeId}) to $useLexNode (id=${useLexNode.nodeId}). " +
                "def in graph: ${graph.containsVertex(defLexNode)}, " +
                "use in graph: ${graph.containsVertex(useLexNode)}"
            }
          }
        }
      }
    }

    return MimirSemanticsProvider(
      sparTree = sparTree,
      semanticTokenTypeMap = semanticTokenTypeMap,
      defs = defs,
      defUseGraph = graph,
    )
  }

  protected abstract fun computeDefUseMap(
    sourceFilePath: Path,
  ): Map<LspSemanticToken, List<LspSemanticToken>>

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
