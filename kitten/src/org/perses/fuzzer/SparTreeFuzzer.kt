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
import com.google.common.primitives.ImmutableIntArray
import org.perses.antlr.RuleType
import org.perses.antlr.TokenType
import org.perses.fuzzer.languagemodel.AbstractLanguageModel
import org.perses.fuzzer.languagemodel.FeatureOfSparTree
import org.perses.grammar.AbstractParserFacade
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgram
import org.perses.program.TokenizedProgramFactory
import org.perses.spartree.AbstractSparTreeGenerator
import org.perses.spartree.AbstractSparTreeNode
import org.perses.spartree.AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy
import org.perses.spartree.ChildHoistingActionSet
import org.perses.spartree.NodeDeletionActionSet
import org.perses.spartree.ParserRuleSparTreeNode
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeBuilder
import org.perses.spartree.SparTreeNodeFactory
import org.perses.util.toImmutableIntArray
import org.perses.util.toImmutableList
import java.io.File
import java.nio.file.Files
import java.nio.file.StandardCopyOption
import java.util.Random
import java.util.Stack

// NOTE: this class should be thread-safe.
class SparTreeFuzzer private constructor(
  private val parserFacade: AbstractParserFacade,
  var seedFile: File,
  tree: SparTree?,
  val isInitial: Boolean,
) {

  private val identifierTokenType = parserFacade.identifierTokenTypes
  val sparTree: SparTree = tree ?: run {
    val parseTree = parserFacade.parseFile(seedFile.toPath())
    val tokens = AbstractParserFacade.getTokens(parseTree.tree)
    val tokenizedProgramFactory = TokenizedProgramFactory.createFactory(
      tokens,
      parserFacade.language,
    )
    val sparTreeNodeFactory = SparTreeNodeFactory(
      parserFacade.metaTokenInfoDb,
      tokenizedProgramFactory,
      parserFacade.ruleHierarchy,
    )
    SparTreeBuilder(
      sparTreeNodeFactory,
      parseTree,
    ).result
  }
  private val identifierIndex: ImmutableIntArray

  // cache the result of encoding
  var featureOfTheSparTree: FeatureOfSparTree? = null
    set(value) {
      if (field == null) {
        field = value
      } else {
        error("featureOfTheSparTree shouldn't be set more than once")
      }
    }
  val flattenedTree: ImmutableList<AbstractSparTreeNode>

  val seedProgram: TokenizedProgram
  var numOfTokenLevelMutationApplied = 0
    private set
  var numOfTreeLevelMutationApplied = 0
    private set

  init {
    flattenedTree = flatSparTree(sparTree)
    seedProgram = sparTree.programSnapshot
    identifierIndex = buildIdentifierIndex(seedProgram.tokens)
  }

  fun createMutant(random: Random): TokenizedProgram {
    // random pop element from treeList
    // TODO: Use a hashSet mark deleted element to avoid deleting a node multiple times
    val index = random.nextInt(flattenedTree.size)
    val nodeToBeDeleted = flattenedTree[index]
    val builder = NodeDeletionActionSet.Builder("edit 1")
    builder.deleteNode(nodeToBeDeleted)
    val actionSet = builder.build()
    val edit = sparTree.createNodeDeletionEdit(actionSet)
    return edit.program
  }

  private fun flatSparTree(tree: SparTree): ImmutableList<AbstractSparTreeNode> {
    val root = tree.root
    val currentList = ImmutableList.builder<AbstractSparTreeNode>()
    val bufferStack = Stack<AbstractSparTreeNode>()
    bufferStack.push(root)
    while (!bufferStack.empty()) {
      val currentNode = bufferStack.pop() ?: break
      currentList.add(currentNode)
      currentNode.forEachChild { item: AbstractSparTreeNode -> bufferStack.push(item) }
    }
    return currentList.build()
  }

  // Token level, syntactically valid
  fun createMutantByReplacingIdentifier(random: Random): MutatedProgram? {
    if (identifierIndex.isEmpty) {
      return null
    }
    val randomIndex1 = identifierIndex[random.nextInt(identifierIndex.length())]
    val randomIndex2 = identifierIndex[random.nextInt(identifierIndex.length())]
    check(seedProgram.tokens[randomIndex1].type in identifierTokenType)
    check(seedProgram.tokens[randomIndex2].type in identifierTokenType)
    numOfTokenLevelMutationApplied++
    return MutatedProgram.replaceToken(
      seedProgram.tokens,
      randomIndex2,
      seedProgram.tokens[randomIndex1],
    )
  }

  // Token level, syntactically valid
  fun createMutantByReplacingSameToken(random: Random): MutatedProgram? {
    val randomIndex = random.nextInt(seedProgram.tokens.size)
    val tokenType = seedProgram.tokens[randomIndex].type
    val tokenIndex = buildTokenIndex(seedProgram.tokens, tokenType)
    if (tokenIndex.length() == 1) {
      return null
    }
    val randomTokenIndex = tokenIndex[random.nextInt(tokenIndex.length())]
    assert(seedProgram.tokens[randomIndex].type == tokenType)
    assert(seedProgram.tokens[randomTokenIndex].type == tokenType)
    if (seedProgram.tokens[randomIndex].text == seedProgram.tokens[randomTokenIndex].text) {
      return null
    }
    numOfTokenLevelMutationApplied++
    return MutatedProgram.replaceToken(
      seedProgram.tokens,
      randomTokenIndex,
      seedProgram.tokens[randomIndex],
    )
  }

  // Node level, syntactically valid
  @Deprecated("Should use tree-level mutation version instead (not implemented yet)")
  fun createMutantByRepeatingRecursion(random: Random, maxRepeatingTimes: Int): MutatedProgram? {
    val recursiveNodesToCorrespondingChildrenMap =
      hashMapOf<AbstractSparTreeNode, List<AbstractSparTreeNode>>()
    val recursiveNodes = sparTree.root.boundedBreadthFirstSearchForFirstQualifiedNodes(
      { node -> findAllRecursiveChildren(node, recursiveNodesToCorrespondingChildrenMap, random) },
      maxBfsDepth = 10,
    ).toImmutableList()
    if (recursiveNodes.isEmpty()) {
      return null
    }
    val pickedNode = recursiveNodes[random.nextInt(recursiveNodes.size)]
    val pickedChild = recursiveNodesToCorrespondingChildrenMap[pickedNode]!![
      random.nextInt(
        recursiveNodesToCorrespondingChildrenMap[pickedNode]!!.size,
      ),
    ]
    return MutatedProgram.repeatRecursion(
      seedProgram.tokens,
      pickedNode,
      pickedChild,
      random.nextInt(maxRepeatingTimes),
    )
  }

  // Node level, syntactically valid
  @Deprecated("Should use tree-level mutation version instead")
  fun createMutantBySplicing(another: SparTreeFuzzer, random: Random): MutatedProgram? {
    val nodeList = flattenedTree.filter { !it.isTokenNode && it.payload != null }
    if (nodeList.isEmpty()) {
      return null
    }
    val nodeToBeReplaced = nodeList[random.nextInt(nodeList.size)]
    val expectedSuperRuleType = nodeToBeReplaced
      ?.payload?.expectedAntlrRuleType ?: return null
    val anotherNodeList = another.flattenedTree.filter { node ->
      !node.isTokenNode && expectedSuperRuleType.isEqualToOrSuperOf(
        node.antlrRule!!,
      )
    }
    if (anotherNodeList.isEmpty()) {
      return null
    }
    val replacementNode = anotherNodeList[random.nextInt(anotherNodeList.size)]
    val anotherTokenList = another.seedProgram.tokens
    val replacement = anotherTokenList.subList(
      anotherTokenList.indexOf(replacementNode.beginToken!!.token),
      anotherTokenList.indexOf(replacementNode.endToken!!.token) + 1,
    )
    return MutatedProgram.replaceNode(seedProgram.tokens, nodeToBeReplaced, replacement)
  }

  // Node level, syntactically valid
  fun createMutatedTreeBySplicing(
    another: SparTreeFuzzer,
    random: Random,
    model: AbstractLanguageModel,
  ): SparTree? {
    val nodeList = flattenedTree.filter { !it.isTokenNode && it.payload != null }
    val selectedIndex = model.selectIndexOfNodeToBeReplaced(nodeList, featureOfTheSparTree, random)
      ?: return null
    val copiedSparTree = sparTree.deepCopy(ReuseNodeIdStrategy)
    val copiedNodeList = flatSparTree(copiedSparTree).filter {
      !it.isTokenNode && it.payload != null
    }
    val nodeToBeReplaced = copiedNodeList[selectedIndex]
    val expectedSuperRuleType = nodeToBeReplaced
      ?.payload?.expectedAntlrRuleType ?: return null
    val anotherNodeList = another.flattenedTree.filter { node ->
      !node.isTokenNode && expectedSuperRuleType.isEqualToOrSuperOf(
        node.antlrRule!!,
      )
    }
    val replacingNode = model.selectReplacingNode(
      anotherNodeList,
      featureOfTheSparTree,
      random,
    ) ?: return null
    numOfTreeLevelMutationApplied++
    return editTreeByReplacingNode(copiedSparTree, nodeToBeReplaced, replacingNode)
  }

  // Node level, syntactically valid
  @Deprecated("Should use tree-level mutation version instead")
  fun createMutantByReplacingWithGeneratedNode(
    random: Random,
    generator: AbstractSparTreeGenerator,
  ): MutatedProgram? {
    val nodesWithAntlrRule = flattenedTree.filter {
      it.parent != null && it.antlrRule != null && it.antlrRule!!.ruleDef.isParserRule
    }
    if (nodesWithAntlrRule.isEmpty()) {
      return null
    }
    val nodeToBeReplaced = nodesWithAntlrRule[random.nextInt(nodesWithAntlrRule.size)]
    val ruleToStart = nodeToBeReplaced.antlrRule!!.ruleDef.ruleNameHandle
    val generatedNode = generator.generateParserRuleSparTreeNode(ruleToStart)
    val replacement = AbstractSparTreeGenerator.getTokenList(generatedNode)
    if (replacement.isEmpty()) {
      return null
    }
    return MutatedProgram.replaceNode(seedProgram.tokens, nodeToBeReplaced, replacement)
  }

  // Node level, syntactically valid
  fun createMutatedTreeByReplacingWithGeneratedNode(
    random: Random,
    generator: AbstractSparTreeGenerator,
    model: AbstractLanguageModel,
  ): SparTree? {
    val nodeList =
      flattenedTree.filter {
        it.parent != null && it.antlrRule != null && it.antlrRule!!.ruleDef.isParserRule
      }
    val selectedIndex = model.selectIndexOfNodeToBeReplaced(
      nodeList,
      featureOfTheSparTree,
      random,
    ) ?: return null
    val copiedSparTree = sparTree.deepCopy(ReuseNodeIdStrategy)
    val nodesWithAntlrRule = flatSparTree(copiedSparTree).filter {
      it.parent != null && it.antlrRule != null && it.antlrRule!!.ruleDef.isParserRule
    }
    assert(nodesWithAntlrRule.size == nodeList.size)
    val nodeToBeReplaced = nodesWithAntlrRule[selectedIndex]
    val ruleToStart = nodeToBeReplaced.antlrRule!!.ruleDef.ruleNameHandle
    val generatedNode = generator.generateParserRuleSparTreeNode(ruleToStart) ?: return null
    numOfTreeLevelMutationApplied++
    return editTreeByReplacingNode(copiedSparTree, nodeToBeReplaced, generatedNode)
  }

  // Node level, syntactically valid
  fun createMutatedTreeByDeletingChildrenOfKleeneStarOrPlusNode(random: Random): SparTree? {
    // adjust this parameter to change the repeating times
    val repeatingTimes = 3
    val builder = NodeDeletionActionSet.Builder(
      "randomly deleting child of kleene node for mutation",
    )
    val nodesToBeDeleted = HashSet<AbstractSparTreeNode>()
    val removedTokens = HashSet<PersesToken>()
    val copiedTree = sparTree.deepCopy(ReuseNodeIdStrategy)
    val kleeneNodes = flatSparTree(copiedTree).filterIsInstance<ParserRuleSparTreeNode>()
      .filter { it.ruleType == RuleType.KLEENE_STAR || it.ruleType == RuleType.KLEENE_PLUS }
    if (kleeneNodes.isEmpty()) {
      return null
    }
    for (i in 1..repeatingTimes) {
      val targetKleeneNode = kleeneNodes[random.nextInt(kleeneNodes.size)]
      assert(targetKleeneNode.childCount > 0)
      if (targetKleeneNode.ruleType == RuleType.KLEENE_PLUS && targetKleeneNode.childCount == 1) {
        continue
      }
      val nodeToBeDeleted = targetKleeneNode.getChild(random.nextInt(targetKleeneNode.childCount))
      val beginToken = nodeToBeDeleted.beginToken!!.token
      val endToken = nodeToBeDeleted.endToken!!.token
      var inRange = false
      for (token in copiedTree.programSnapshot.tokens) {
        if (token == beginToken) {
          inRange = true
        }
        if (inRange) {
          removedTokens.add(token)
        }
        if (token == endToken) {
          assert(inRange)
          inRange = false
        }
      }
      nodesToBeDeleted.add(nodeToBeDeleted)
    }
    if (removedTokens.size == copiedTree.tokenCount) {
      return null
    }
    builder.deleteNodes(nodesToBeDeleted)
    val actionSet = builder.build()
    if (actionSet.isEmpty) {
      return null
    }
    val edit = copiedTree.createNodeDeletionEdit(actionSet)
    copiedTree.applyEdit(edit)
    numOfTreeLevelMutationApplied++
    return copiedTree
  }

  // Node level, syntactically valid
  fun createMutantByInsertingChildrenToKleeneStarOrPlusNode(
    random: Random,
    generator: AbstractSparTreeGenerator,
  ): MutatedProgram? {
    // adjust this parameter to change the repeating times
    val repeatingTimes = 3
    val kleeneNodes = flattenedTree.filterIsInstance<ParserRuleSparTreeNode>()
      .filter { it.ruleType == RuleType.KLEENE_STAR || it.ruleType == RuleType.KLEENE_PLUS }
    if (kleeneNodes.isEmpty()) {
      return null
    }
    val tokenListsBuilder = ImmutableList.builder<ImmutableList<PersesToken>>()
    val insertPositionsBuilder = ImmutableList.builder<PersesToken>()
    for (i in 1..repeatingTimes) {
      val targetKleeneNode = kleeneNodes[random.nextInt(kleeneNodes.size)]
      assert(targetKleeneNode.childCount > 0)
      val targetRule = targetKleeneNode.getChild(0)
        .payload!!.expectedAntlrRuleType ?: continue
      // generate from scratch
      val generatedNode =
        generator.generateParserRuleSparTreeNode(targetRule.ruleDef.ruleNameHandle) ?: continue
      val generatedTokenList = AbstractSparTreeGenerator.getTokenList(generatedNode)
      val insertPosition =
        targetKleeneNode.getChild(random.nextInt(targetKleeneNode.childCount)).endToken!!
      tokenListsBuilder.add(generatedTokenList)
      insertPositionsBuilder.add(insertPosition.token)
    }
    val tokenLists = tokenListsBuilder.build()
    val insertPositions = insertPositionsBuilder.build()
    if (tokenLists.isEmpty()) {
      return null
    }
    return MutatedProgram.insertNodes(seedProgram.tokens, tokenLists, insertPositions)
  }

  // Token level, cannot promise syntactical correctness
  fun createMutantByInsertingTokensOnRandomPositions(random: Random): MutatedProgram? {
    return createMutantByInsertingTokens(
      random = random,
      continuousPositions = false,
    )
  }

  // Token level, cannot promise syntactical correctness
  fun createMutantByDeletingTokensOnRandomPositions(random: Random): MutatedProgram? {
    return createMutantByDeletingTokens(
      random = random,
      continuousPositions = false,
    )
  }

  fun createMutantByReplacingTokensOnRandomPositions(random: Random): MutatedProgram? {
    return createMutantByReplacingTokens(
      random = random,
      continuousPositions = false,
    )
  }

  // Token level, cannot promise syntactical correctness
  fun createMutantByInsertingARangeOfTokens(random: Random): MutatedProgram? {
    return createMutantByInsertingTokens(
      random = random,
      continuousPositions = true,
    )
  }

  // Token level, cannot promise syntactical correctness
  fun createMutantByDeletingARangeOfTokens(random: Random): MutatedProgram? {
    return createMutantByDeletingTokens(
      random = random,
      continuousPositions = true,
    )
  }

  fun createMutantByReplacingARangeOfTokens(random: Random): MutatedProgram? {
    return createMutantByReplacingTokens(
      random = random,
      continuousPositions = true,
    )
  }

  private fun createMutantByInsertingTokens(
    random: Random,
    continuousPositions: Boolean,
  ): MutatedProgram? {
    val tokenList = seedProgram.tokens
    if (tokenList.size == 0) {
      return null
    }
    val indicesToInsert = ImmutableIntArray.builder()
    val tokensToInsert = ImmutableList.builder<PersesToken>()
    // adjust this parameter to change the number of inserting tokens
    val numberOfTokensToInsert = 2
    for (i in 0..numberOfTokensToInsert) {
      tokensToInsert.add(tokenList[random.nextInt(tokenList.size)])
    }

    if (!continuousPositions) {
      for (i in 0..numberOfTokensToInsert) {
        indicesToInsert.add(random.nextInt(tokenList.size))
      }
    } else {
      val index = random.nextInt(tokenList.size)
      for (i in 0..numberOfTokensToInsert) {
        indicesToInsert.add(index)
      }
    }
    numOfTokenLevelMutationApplied++
    return MutatedProgram.insertTokens(tokenList, indicesToInsert.build(), tokensToInsert.build())
  }

  private fun createMutantByDeletingTokens(
    random: Random,
    continuousPositions: Boolean,
  ): MutatedProgram? {
    val tokenList = seedProgram.tokens
    val numberOfTokensToDelete = 2
    if (tokenList.size <= 2) {
      return null
    }
    val indicesToDelete = ImmutableIntArray.builder()
    if (!continuousPositions) {
      for (i in 0..numberOfTokensToDelete) {
        indicesToDelete.add(random.nextInt(tokenList.size))
      }
    } else {
      val startIndex = random.nextInt(tokenList.size - numberOfTokensToDelete)
      for (i in 0..numberOfTokensToDelete) {
        indicesToDelete.add(startIndex + i)
      }
    }
    numOfTokenLevelMutationApplied++
    return MutatedProgram.deleteTokens(tokenList, indicesToDelete.build())
  }

  private fun createMutantByReplacingTokens(
    random: Random,
    continuousPositions: Boolean,
  ): MutatedProgram? {
    val tokenList = seedProgram.tokens
    val numberOfTokensToReplace = 2
    if (tokenList.size <= 2) {
      return null
    }
    val indicesToReplace = ImmutableIntArray.builder()
    val tokensToReplace = ImmutableList.Builder<PersesToken>()
    for (i in 0..numberOfTokensToReplace) {
      tokensToReplace.add(tokenList[random.nextInt(tokenList.size)])
    }
    if (!continuousPositions) {
      val shuffledIndices = (0 until tokenList.size).toList().shuffled(random)
      for (i in 0..numberOfTokensToReplace) {
        indicesToReplace.add(shuffledIndices[i])
      }
    } else {
      val startIndex = random.nextInt(tokenList.size - numberOfTokensToReplace)
      for (i in 0..numberOfTokensToReplace) {
        indicesToReplace.add(startIndex + i)
      }
    }
    numOfTokenLevelMutationApplied++
    return MutatedProgram
      .replaceTokens(tokenList, indicesToReplace.build(), tokensToReplace.build())
  }

  private fun buildIdentifierIndex(tokens: ImmutableList<PersesToken>) =
    tokens.withIndex()
      .asSequence()
      .filter { it.value.type in identifierTokenType }
      .map { it.index }
      .toImmutableIntArray()

  private fun buildTokenIndex(tokens: ImmutableList<PersesToken>, tokenType: TokenType) =
    tokens.withIndex()
      .asSequence()
      .filter { it.value.type == tokenType }
      .map { it.index }
      .toImmutableIntArray()

  private fun haveSameTokens(node1: AbstractSparTreeNode, node2: AbstractSparTreeNode): Boolean {
    if (node1.isTokenNode || node2.isTokenNode) {
      return node1 === node2
    }
    return node1.beginToken === node2.beginToken && node1.endToken === node2.endToken
  }

  private fun findAllRecursiveChildren(
    node: AbstractSparTreeNode,
    recursiveChildren: HashMap<AbstractSparTreeNode, List<AbstractSparTreeNode>>,
    random: Random,
  ): Boolean {
    if (node.isTokenNode) {
      return false
    }
    // Use a random number so that BFS has a chance to find deeper recursive nodes
    if (random.nextInt(100) >= 30) {
      return false
    }
    val children =
      node.boundedBreadthFirstSearchForFirstQualifiedNodes(
        { child: AbstractSparTreeNode ->
          val expectedSuperRuleType = child
            .payload!!.expectedAntlrRuleType
            ?: return@boundedBreadthFirstSearchForFirstQualifiedNodes false
          if (haveSameTokens(child, node)) {
            return@boundedBreadthFirstSearchForFirstQualifiedNodes false
          }
          expectedSuperRuleType.isEqualToOrSuperOf(node.antlrRule!!)
        },
        5,
      ).toImmutableList()
    if (children.isNotEmpty()) {
      recursiveChildren[node] = children
      return true
    }
    return false
  }

  fun moveSeedFile(newFile: File) {
    Files.move(
      seedFile.toPath(),
      newFile.toPath(),
      StandardCopyOption.REPLACE_EXISTING,
    )
    seedFile = newFile
  }

  fun printFeatureOfSparTree(): String {
    return StringBuilder().apply {
      featureOfTheSparTree?.forEach {
        val ruleName = it.key.antlrRule!!.ruleName
        val sequence = it.value
        this.append("$ruleName : $sequence\n")
      } ?: return ""
    }.toString()
  }

  companion object {
    fun fromFile(
      parserFacade: AbstractParserFacade,
      seedFile: File,
      isInitial: Boolean = false,
    ): SparTreeFuzzer {
      return SparTreeFuzzer(
        parserFacade,
        seedFile,
        tree = null,
        isInitial,
      )
    }

    fun fromSparTree(
      parserFacade: AbstractParserFacade,
      seedFile: File,
      sparTree: SparTree,
    ): SparTreeFuzzer {
      return SparTreeFuzzer(
        parserFacade,
        seedFile,
        sparTree,
        isInitial = false,
      )
    }

    private fun editTreeByReplacingNode(
      sparTree: SparTree,
      targetNode: AbstractSparTreeNode,
      replacingNode: AbstractSparTreeNode,
    ): SparTree {
      val edit = sparTree.createAnyNodeReplacementEdit(
        ChildHoistingActionSet.createByReplacingSingleNode(
          targetNode,
          replacingNode,
          actionsDescription = "Replacing for generative mutation",
        ),
      )
      sparTree.applyEdit(edit)
      return sparTree
    }
  }
}
