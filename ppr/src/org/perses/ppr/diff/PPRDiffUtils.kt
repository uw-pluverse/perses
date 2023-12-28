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
package org.perses.ppr.diff

import com.github.gumtreediff.actions.EditScript
import com.github.gumtreediff.actions.SimplifiedChawatheScriptGenerator
import com.github.gumtreediff.matchers.ConfigurationOptions
import com.github.gumtreediff.matchers.GumtreeProperties
import com.github.gumtreediff.matchers.MappingStore
import com.github.gumtreediff.matchers.Matchers
import com.github.gumtreediff.tree.Tree
import com.github.gumtreediff.tree.TreeContext
import com.github.gumtreediff.tree.TypeSet
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import com.google.common.collect.ImmutableSet
import it.unimi.dsi.fastutil.ints.IntOpenHashSet
import org.antlr.v4.runtime.Token
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.SparTree
import org.perses.util.ListAlignment
import org.perses.util.SimpleQueue
import org.perses.util.Util
import org.perses.util.toImmutableList

object PPRDiffUtils {
  val EQUALIZER_LINE: (List<Token>, List<Token>) -> Boolean = { line1, line2 ->
    val size = line1.size
    if (size != line2.size) {
      false
    } else {
      var idx = 0
      var match = true
      while (idx < size) {
        if (line1[idx].text != line2[idx].text) {
          match = false
          break
        }
        ++idx
      }
      match
    }
  }

  val EQUALIZER_TOKEN: (Token, Token) -> Boolean = { t1, t2 ->
    t1.text == t2.text
  }

  data class TreeContextInfo(
    val treeContext: TreeContext,
    val nodeMapping: ImmutableMap<Tree, AbstractSparTreeNode>,
  )

  fun sparTreeNode2TreeContext(
    sparTreeNode: AbstractSparTreeNode,
  ): TreeContextInfo {
    val treeContext = TreeContext()
    val mapBuilder = ImmutableMap.builder<Tree, AbstractSparTreeNode>()
    treeContext.root = buildTreeContext(sparTreeNode, parent = null, treeContext, mapBuilder)
    return TreeContextInfo(treeContext, mapBuilder.build())
  }

  fun treeContext2SparTreeNode(
    tree: Tree,
    nodeMapping: ImmutableMap<Tree, AbstractSparTreeNode>,
  ): AbstractSparTreeNode {
    return nodeMapping[tree]!!
  }

  private fun buildTreeContext(
    node: AbstractSparTreeNode,
    parent: Tree?,
    treeContext: TreeContext,
    mapBuilder: ImmutableMap.Builder<Tree, AbstractSparTreeNode>,
  ): Tree {
    val ruleName = if (node.antlrRule != null) {
      node.ruleName
    } else {
      "null"
    }
    val tree = treeContext.createTree(TypeSet.type(ruleName), "")
    tree.pos = node.beginToken!!.token.startIndex
    tree.length = node.endToken!!.token.stopIndex - node.beginToken!!.token.startIndex + 1
    tree.parent = parent

    for (i in 0 until node.childCount) {
      val child = buildTreeContext(node.getChild(i), tree!!, treeContext, mapBuilder)
      tree.addChild(child)
    }

    if (node.childCount == 0) {
      tree.type = TypeSet.type(ruleName + node.beginToken!!.token.text)
    }
    mapBuilder.put(tree, node)
    return tree
  }

  fun difference(
    seedNodesList: ImmutableList<Tree>,
    variantNodesList: ImmutableList<Tree>,
  ): ImmutableList<Tree> {
    val variantNodesSet = IntOpenHashSet()
    for (node in variantNodesList) {
      variantNodesSet.add(node.metrics.hash)
    }

    return seedNodesList.filter {
      !variantNodesSet.contains(it.metrics.hash)
    }.toImmutableList()
  }

  fun extractUnmappedNodes(
    tree: Tree,
    diffMapping: MappingStore,
    editScript: EditScript,
  ): ImmutableList<Tree> {
    val unmappedNodes = ImmutableList.builder<Tree>()
    for (child in tree.children) {
      if ((diffMapping.isSrcMapped(child) || diffMapping.isDstMapped(child))) {
        unmappedNodes.addAll(extractUnmappedNodes(child, diffMapping, editScript))
      } else {
        unmappedNodes.add(child)
      }
    }
    return unmappedNodes.build()
  }

  fun sparTreeNode2Diff(
    node: AbstractSparTreeNode,
    tokenDiffSet: ImmutableSet<Token>,
    node2DiffMap: MutableMap<AbstractSparTreeNode, Boolean>,
  ) {
    node.postOrderVisit(
      successorsFunction = {
        if (node2DiffMap.containsKey(it)) {
          emptyList<AbstractSparTreeNode>()
        } else {
          it.immutableChildView
        }
      },
      visitor = {
        val isDiff: Boolean = if (it.isTokenNode) {
          tokenDiffSet.contains(it.asLexerRule().token)
        } else {
          check(it.hasChildren()) { "The node $it does not have children." }
          it.immutableChildView.all { node2DiffMap[it] == true }
        }
        node2DiffMap[it] = isDiff
      },
    )
  }

  // A real diff node is a node that all its descendants are unmatched nodes
  // w.r.t. both tree-based diff algorithm and list-based diff algorithm (line-diff)
  fun computeRealDiffNodes(
    nodesFromTreeDiffAlgo: ImmutableList<AbstractSparTreeNode>,
    tokenDiffSet: ImmutableSet<Token>,
  ): ImmutableList<AbstractSparTreeNode> {
    val realDiffNodes = ImmutableList.builder<AbstractSparTreeNode>()
    val node2DiffMap = mutableMapOf<AbstractSparTreeNode, Boolean>()
    for (diffNode in nodesFromTreeDiffAlgo) {
      sparTreeNode2Diff(diffNode, tokenDiffSet, node2DiffMap)
      val worklist = SimpleQueue<AbstractSparTreeNode>()
      worklist.add(diffNode)
      while (!worklist.isEmpty()) {
        val node = worklist.remove()
        // Only collect nodes that are considered as diff
        if (node2DiffMap[node] == true) {
          realDiffNodes.add(node)
        } else {
          worklist.addAll(node.immutableChildView)
        }
      }
    }
    return realDiffNodes.build()
  }

  // Compute line-diff, and return the tokens in line-diff
  fun computeTokenDiffSetByLine(
    seedTokens: ImmutableList<PersesToken>,
    variantTokens: ImmutableList<PersesToken>,
  ): ImmutableSet<Token> {
    val seedLines = Util.mergeContinuousElementsIntoRegions(seedTokens) { a, b ->
      a.position.line == b.position.line
    }
    val variantLines = Util.mergeContinuousElementsIntoRegions(variantTokens) { a, b ->
      a.position.line == b.position.line
    }

    val lineListAlignment = ListAlignment.create(
      seedLines,
      variantLines,
      EQUALIZER_LINE,
    )
    val tokenDiffSet = ImmutableSet.builder<Token>()

    val insertedLines = lineListAlignment.onlyInserts
    for (editsList in insertedLines) {
      tokenDiffSet.addAll(editsList.revision!!)
    }

    val deleteLines = lineListAlignment.onlyDeletes
    for (editsList in deleteLines) {
      tokenDiffSet.addAll(editsList.base!!)
    }

    return tokenDiffSet.build()
  }

  // the main workflow to compute real diff nodes on seed
  fun computeRealDiffNodesOnBothTrees(
    seedSparTree: SparTree,
    variantSparTree: SparTree,
  ): DiffNodes {
    val seedTreeContextInfo = sparTreeNode2TreeContext(seedSparTree.root)
    val variantTreeContextInfo = sparTreeNode2TreeContext(variantSparTree.root)

    val seedTree = seedTreeContextInfo.treeContext
    val variantTree = variantTreeContextInfo.treeContext

    // create and initialize matcher
    val matcher = Matchers.getInstance().getMatcherWithFallback(null)
    val config = GumtreeProperties()
    // minimum matching height: 3, minimum similarity: 0.1
    config.tryConfigure(ConfigurationOptions.st_minprio, 3)
    config.tryConfigure(ConfigurationOptions.bu_minsim, 0.1)
    matcher.configure(config)

    // match two Tree
    val nodeMapping = matcher.match(seedTree.root, variantTree.root)

    // deduce edit script
    val editScript = SimplifiedChawatheScriptGenerator().computeActions(nodeMapping)

    val seedTreeDiff = extractUnmappedNodes(seedTree.root, nodeMapping, editScript)
    val variantTreeDiff = extractUnmappedNodes(variantTree.root, nodeMapping, editScript)

    val readSeedDiffNodes = postProcess(
      seedTreeDiff,
      variantTreeDiff,
      seedTreeContextInfo,
      seedSparTree,
      variantSparTree,
    )

    val readVariantDiffNodes = postProcess(
      variantTreeDiff,
      seedTreeDiff,
      variantTreeContextInfo,
      variantSparTree,
      seedSparTree,
    )

    return DiffNodes(readSeedDiffNodes, readVariantDiffNodes)
  }

  private fun postProcess(
    seedTreeDiff: ImmutableList<Tree>,
    variantTreeDiff: ImmutableList<Tree>,
    seedTreeContextInfo: TreeContextInfo,
    seedSparTree: SparTree,
    variantSparTree: SparTree,
  ): ImmutableList<AbstractSparTreeNode> {
    // delete matched nodes missed by tree differencing algorithm
    val seedTreeDiffDeduplicated = difference(seedTreeDiff, variantTreeDiff)

    // map Tree to AbstractSparTreeNode
    val seedNodeMapping = seedTreeContextInfo.nodeMapping

    val seedAbstractNodeDiff = seedTreeDiffDeduplicated.map {
      treeContext2SparTreeNode(it, seedNodeMapping)
    }.toImmutableList()

    // compute tokens from line diff
    val tokenDiffSetByLine = computeTokenDiffSetByLine(
      seedSparTree.programSnapshot.tokens,
      variantSparTree.programSnapshot.tokens,
    )

    // further filter nodes by line difference
    return computeRealDiffNodes(seedAbstractNodeDiff, tokenDiffSetByLine)
  }

  data class DiffNodes(
    val diffNodesOnSeed: ImmutableList<AbstractSparTreeNode>,
    val diffNodesOnVariant: ImmutableList<AbstractSparTreeNode>,
  )
}
