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

import com.github.gumtreediff.actions.SimplifiedChawatheScriptGenerator
import com.github.gumtreediff.matchers.ConfigurationOptions
import com.github.gumtreediff.matchers.GumtreeProperties
import com.github.gumtreediff.matchers.Matchers
import com.github.gumtreediff.tree.Tree
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import com.google.common.truth.Truth.assertThat
import org.antlr.v4.runtime.Token
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.spartree.AbstractSparTreeNode
import org.perses.util.ListAlignment
import org.perses.util.SimpleQueue

@RunWith(JUnit4::class)
class PPRDiffUtilsTest {

  @Test
  fun testEqualizerToken() {
    val seedStr = "int a = 1;"
    val variantStr = "int a = 1 + 2;"
    val seedProgram = TestUtility.createTokenizedProgramFromString(
      seedStr,
      LanguageC,
    )
    val variantProgram = TestUtility.createTokenizedProgramFromString(
      variantStr,
      LanguageC,
    )
    val listAlignment = ListAlignment.create(
      seedProgram.tokens,
      variantProgram.tokens,
      PPRDiffUtils.EQUALIZER_TOKEN,
    )
    assertThat(listAlignment.alignment).hasSize(7)
    assertThat(listAlignment.onlyInserts[0].revision!!.text).isEqualTo("+")
    assertThat(listAlignment.onlyInserts[1].revision!!.text).isEqualTo("2")
    assertThat(listAlignment.onlyKeeps[0].base!!.text).isEqualTo("int")
    assertThat(listAlignment.onlyKeeps[1].base!!.text).isEqualTo("a")
    assertThat(listAlignment.onlyKeeps[2].base!!.text).isEqualTo("=")
    assertThat(listAlignment.onlyKeeps[3].base!!.text).isEqualTo("1")
    assertThat(listAlignment.onlyKeeps[4].base!!.text).isEqualTo(";")
  }

  @Test
  fun testEqualizerLine() {
    val seedStr =
      """func() {
      int a = 1;
      a++;
      }"""

    val seedProgram = TestUtility.createTokenizedProgramFromString(
      seedStr,
      LanguageC,
    )

    val variantStr = """func() {
                     int a = 1;
                     int b = 2;
                     b++;
                     } """

    val variantProgram = TestUtility.createTokenizedProgramFromString(
      variantStr,
      LanguageC,
    )
    val seedTokenLine = listOf(
      seedProgram.tokens.subList(0, 4),
      seedProgram.tokens.subList(4, 9),
      seedProgram.tokens.subList(9, 12),
      seedProgram.tokens.subList(12, 13),
    )
    val variantTokenLine = listOf(
      variantProgram.tokens.subList(0, 4),
      variantProgram.tokens.subList(4, 9),
      variantProgram.tokens.subList(9, 14),
      variantProgram.tokens.subList(14, 17),
      variantProgram.tokens.subList(17, 18),
    )
    val listAlignment = ListAlignment.create(
      seedTokenLine,
      variantTokenLine,
      PPRDiffUtils.EQUALIZER_LINE,
    )
    assertThat(listAlignment.alignment).hasSize(6)
    assertThat(listAlignment.onlyInserts[0].revision!![0].text).isEqualTo("int")
    assertThat(listAlignment.onlyInserts[0].revision!![1].text).isEqualTo("b")
    assertThat(listAlignment.onlyInserts[0].revision!![2].text).isEqualTo("=")
    assertThat(listAlignment.onlyInserts[0].revision!![3].text).isEqualTo("2")
    assertThat(listAlignment.onlyInserts[0].revision!![4].text).isEqualTo(";")
    assertThat(listAlignment.onlyInserts[1].revision!![0].text).isEqualTo("b")
    assertThat(listAlignment.onlyInserts[1].revision!![1].text).isEqualTo("++")
    assertThat(listAlignment.onlyInserts[1].revision!![2].text).isEqualTo(";")
    assertThat(listAlignment.onlyKeeps[0].base!![0].text).isEqualTo("func")
    assertThat(listAlignment.onlyKeeps[0].base!![1].text).isEqualTo("(")
    assertThat(listAlignment.onlyKeeps[0].base!![2].text).isEqualTo(")")
    assertThat(listAlignment.onlyKeeps[0].base!![3].text).isEqualTo("{")
    assertThat(listAlignment.onlyKeeps[1].base!![0].text).isEqualTo("int")
    assertThat(listAlignment.onlyKeeps[1].base!![1].text).isEqualTo("a")
    assertThat(listAlignment.onlyKeeps[1].base!![2].text).isEqualTo("=")
    assertThat(listAlignment.onlyKeeps[1].base!![3].text).isEqualTo("1")
    assertThat(listAlignment.onlyKeeps[1].base!![4].text).isEqualTo(";")
    assertThat(listAlignment.onlyDeletes[0].base!![0].text).isEqualTo("a")
    assertThat(listAlignment.onlyDeletes[0].base!![1].text).isEqualTo("++")
    assertThat(listAlignment.onlyDeletes[0].base!![2].text).isEqualTo(";")
    assertThat(listAlignment.onlyKeeps[2].base!![0].text).isEqualTo("}")
  }

  @Test
  fun testSparTreeNode2TreeContext() {
    val seedStr =
      """func() {
      int a = 1;
      a++;
      }"""
    val sparTree = TestUtility.createSparTreeFromString(
      seedStr,
      LanguageC,
    )
    val treeContext = PPRDiffUtils.sparTreeNode2TreeContext(sparTree.root).treeContext

    val mappingQueue = SimpleQueue<Pair<AbstractSparTreeNode, Tree>>()
    mappingQueue.add(Pair(sparTree.root, treeContext.root))

    while (mappingQueue.isNotEmpty()) {
      val mapping = mappingQueue.remove()
      val sparTreeNode = mapping.first
      val treeContextNode = mapping.second
      assertThat(sparTreeNode.childCount).isEqualTo(treeContextNode.children.size)

      var ruleName = sparTreeNode.ruleName
      if (sparTreeNode.childCount == 0) {
        ruleName += sparTreeNode.beginToken!!.token.text
      }
      assertThat(ruleName).isEqualTo(treeContextNode.type.name)

      var idx = 0
      while (idx < sparTreeNode.childCount) {
        mappingQueue.add(Pair(sparTreeNode.getChild(idx), treeContextNode.getChild(idx)))
        idx++
      }
    }
  }

  @Test
  fun testTreeContext2SparTreeNode() {
    val seedStr =
      """func() {
      int a = 1;
      a++;
      }"""
    val sparTree = TestUtility.createSparTreeFromString(
      seedStr,
      LanguageC,
    )
    val treeContextInfo = PPRDiffUtils.sparTreeNode2TreeContext(sparTree.root)
    val treeContext = treeContextInfo.treeContext
    val nodeMapping = treeContextInfo.nodeMapping

    val mappingQueue = SimpleQueue<Pair<AbstractSparTreeNode, Tree>>()
    mappingQueue.add(Pair(sparTree.root, treeContext.root))

    while (mappingQueue.isNotEmpty()) {
      val mapping = mappingQueue.remove()
      val sparTreeNode = mapping.first
      val treeContextNode = mapping.second

      assertThat(sparTreeNode).isEqualTo(
        PPRDiffUtils.treeContext2SparTreeNode(treeContextNode, nodeMapping),
      )

      var idx = 0
      while (idx < sparTreeNode.childCount) {
        mappingQueue.add(Pair(sparTreeNode.getChild(idx), treeContextNode.getChild(idx)))
        idx++
      }
    }
  }

  @Test
  fun testDifference() {
    val seedStr = "int a;"
    val sparTreeSeed = TestUtility.createSparTreeFromString(
      seedStr,
      LanguageC,
    )
    val treeContextSeed = PPRDiffUtils.sparTreeNode2TreeContext(sparTreeSeed.root).treeContext

    val variantStr = "int b;"
    val sparTreeVariant = TestUtility.createSparTreeFromString(
      variantStr,
      LanguageC,
    )
    val treeContextVariant = PPRDiffUtils.sparTreeNode2TreeContext(sparTreeVariant.root).treeContext

    val commonStr = "int func();"
    val sparTreeCommon = TestUtility.createSparTreeFromString(
      commonStr,
      LanguageC,
    )
    val treeContextCommon = PPRDiffUtils.sparTreeNode2TreeContext(sparTreeCommon.root).treeContext

    val seedNodesList = ImmutableList.Builder<Tree>()
    seedNodesList.add(treeContextSeed.root)
    seedNodesList.add(treeContextCommon.root)
    val variantNodesList = ImmutableList.Builder<Tree>()
    variantNodesList.add(treeContextVariant.root)
    variantNodesList.add(treeContextCommon.root)

    val deduplicatedSeedList = PPRDiffUtils.difference(
      seedNodesList.build(),
      variantNodesList.build(),
    )
    assertThat(deduplicatedSeedList).hasSize(1)
    assertThat(deduplicatedSeedList.single().metrics.hash).isEqualTo(
      treeContextSeed.root.metrics.hash,
    )
  }

  @Test
  fun testExtractUnmappedNodes() {
    val seedStr =
      """int main () {
      int a = 1;
      return a;
      }"""
    val sparTreeSeed = TestUtility.createSparTreeFromString(
      seedStr,
      LanguageC,
    )
    val treeContextSeedInfo = PPRDiffUtils.sparTreeNode2TreeContext(sparTreeSeed.root)
    val treeContextSeed = treeContextSeedInfo.treeContext
    val nodeMapping = treeContextSeedInfo.nodeMapping

    val variantStr =
      """int main () {
      return a;
      }"""
    val sparTreeVariant = TestUtility.createSparTreeFromString(
      variantStr,
      LanguageC,
    )
    val treeContextVariant = PPRDiffUtils.sparTreeNode2TreeContext(sparTreeVariant.root).treeContext

    // create and initialize matcher
    val matcher = Matchers.getInstance().getMatcherWithFallback(null)
    val config = GumtreeProperties()
    config.tryConfigure(ConfigurationOptions.st_minprio, 3)
    config.tryConfigure(ConfigurationOptions.bu_minsim, 0.1)
    matcher.configure(config)

    // match two TreeContext
    val mappingStore = matcher.match(treeContextSeed.root, treeContextVariant.root)

    // deduce edit script
    val editScript = SimplifiedChawatheScriptGenerator().computeActions(mappingStore)

    val seedUnmappedNodes = PPRDiffUtils.extractUnmappedNodes(
      treeContextSeed.root,
      mappingStore,
      editScript,
    )
    assertThat(seedUnmappedNodes).hasSize(1)
    val seedUnmappedSparTreeNode = PPRDiffUtils.treeContext2SparTreeNode(
      seedUnmappedNodes.single(),
      nodeMapping,
    )
    assertThat(seedUnmappedSparTreeNode.updateLeafTokenCount()).isEqualTo(5)
  }

  @Test
  fun testSparTreeNode2Diff() {
    val tokensStr = "int a = 1;"
    val sparTree = TestUtility.createSparTreeFromString(
      tokensStr,
      LanguageC,
    )
    val tokenList = sparTree.programSnapshot.tokens

    // let's assume "int" is classified as diff
    val tokenDiffSetBuilder = ImmutableSet.builder<Token>()
    tokenDiffSetBuilder.add(tokenList[0])

    // build the map
    val node2Diff = mutableMapOf<AbstractSparTreeNode, Boolean>()
    PPRDiffUtils.sparTreeNode2Diff(sparTree.root, tokenDiffSetBuilder.build(), node2Diff)

    // check diff flag of each node
    node2Diff.forEach { (node, isDiff) ->
      if (node.updateLeafTokenCount() == 1 &&
        node.beginToken?.token?.text.equals("int")
      ) {
        assertThat(isDiff).isEqualTo(true)
      } else {
        assertThat(isDiff).isEqualTo(false)
      }
    }
  }

  @Test
  fun testComputeRealDiffNodes() {
    val tokensStr =
      """int main () {
      int a = 1;
      double b = 2;
      return a;
      }"""
    val sparTree = TestUtility.createSparTreeFromString(
      tokensStr,
      LanguageC,
    )
    val tokenList = sparTree.programSnapshot.tokens

    // let's assume "a = 1" and "b" are classified as diff by line-diff
    val tokenDiffSetBuilder = ImmutableSet.builder<Token>()
    tokenDiffSetBuilder.add(tokenList[6])
    tokenDiffSetBuilder.add(tokenList[7])
    tokenDiffSetBuilder.add(tokenList[8])
    tokenDiffSetBuilder.add(tokenList[11])

    val realDiffNodes = PPRDiffUtils.computeRealDiffNodes(
      ImmutableList.of(sparTree.root),
      tokenDiffSetBuilder.build(),
    )

    assertThat(realDiffNodes).hasSize(2)
    assertThat(realDiffNodes[0].updateLeafTokenCount()).isEqualTo(3)
    assertThat(realDiffNodes[1].updateLeafTokenCount()).isEqualTo(1)
  }

  @Test
  fun testComputeTokenDiffSetByLine() {
    val seedStr = """func() {
                 int a = 1;
                 a++;
                 } """
    val seedProgram = TestUtility.createTokenizedProgramFromString(
      seedStr,
      LanguageC,
    )

    val variantStr = """func() {
                     int a = 1;
                     int b = 2;
                     b++;
                     } """
    val variantProgram = TestUtility.createTokenizedProgramFromString(
      variantStr,
      LanguageC,
    )

    val seedTokens = seedProgram.tokens
    val variantTokens = variantProgram.tokens
    val tokenDiffSet = PPRDiffUtils.computeTokenDiffSetByLine(seedTokens, variantTokens)

    var idx = 0
    // check seed tokens
    while (idx < seedTokens.size) {
      if (idx in 9..11) {
        assertThat(tokenDiffSet.contains(seedTokens[idx])).isTrue()
      } else {
        assertThat(tokenDiffSet.contains(seedTokens[idx])).isFalse()
      }
      idx++
    }

    idx = 0
    // check variant tokens
    while (idx < seedTokens.size) {
      if (idx in 9..16) {
        assertThat(tokenDiffSet.contains(variantTokens[idx])).isTrue()
      } else {
        assertThat(tokenDiffSet.contains(variantTokens[idx])).isFalse()
      }
      idx++
    }
  }

  @Test
  fun testComputeRealDiffNodesOnBothTrees() {
    val seedSparTree = TestUtility.createSparTreeFromString(
      """func() {
       int a = 1;
       add(1, 2);
       a++;
       } """,
      LanguageC,
    )

    val variantSparTree = TestUtility.createSparTreeFromString(
      """func() {
       int a = 1;
       int b = 2;
       a++;
       } """,
      LanguageC,
    )

    val realDiffNodesOnBothTrees = PPRDiffUtils.computeRealDiffNodesOnBothTrees(
      seedSparTree,
      variantSparTree,
    )
    val realDiffNodesOnSeed = realDiffNodesOnBothTrees.diffNodesOnSeed
    val realDiffNodesOnVariant = realDiffNodesOnBothTrees.diffNodesOnVariant
    assertThat(realDiffNodesOnSeed).hasSize(1)
    assertThat(realDiffNodesOnVariant).hasSize(1)

    val diffNodeOnSeed = realDiffNodesOnSeed.single()
    assertThat(diffNodeOnSeed.updateLeafTokenCount()).isEqualTo(7)

    val diffNodeOnVariant = realDiffNodesOnVariant.single()
    assertThat(diffNodeOnVariant.updateLeafTokenCount()).isEqualTo(5)

    val resultListOnSeed = mutableListOf<String>()
    diffNodeOnSeed.postOrderVisit {
        node ->
      if (node.isTokenNode) {
        resultListOnSeed.add(node.asLexerRule().token.text)
      }
    }
    assertThat(resultListOnSeed)
      .containsExactly("add", "(", "1", ",", "2", ")", ";").inOrder()

    val resultListOnVariant = mutableListOf<String>()
    diffNodeOnVariant.postOrderVisit {
        node ->
      if (node.isTokenNode) {
        resultListOnVariant.add(node.asLexerRule().token.text)
      }
    }
    assertThat(resultListOnVariant)
      .containsExactly("int", "b", "=", "2", ";").inOrder()
  }
}
