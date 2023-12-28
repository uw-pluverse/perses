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

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import com.google.common.primitives.ImmutableIntArray
import org.apache.commons.text.StringEscapeUtils
import org.perses.antlr.RuleHierarchyEntry
import org.perses.antlr.TokenType
import org.perses.antlr.ast.AbstractPersesQuantifiedAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesActionAst
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesEpsilonAst
import org.perses.antlr.ast.PersesLexerCharSet
import org.perses.antlr.ast.PersesLexerCommandAst
import org.perses.antlr.ast.PersesNotAst
import org.perses.antlr.ast.PersesOptionalAst
import org.perses.antlr.ast.PersesPlusAst
import org.perses.antlr.ast.PersesRangeAst
import org.perses.antlr.ast.PersesRuleElementLabel
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.PersesStarAst
import org.perses.antlr.ast.PersesTerminalAst
import org.perses.antlr.ast.PersesTokenSetAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.antlr.toTokenType
import org.perses.grammar.AbstractParserFacade
import org.perses.program.PersesTokenFactory
import org.perses.spartree.AbstractTreeNode.NodeIdCopyStrategy.ReuseNodeIdStrategy
import org.perses.util.toImmutableList
import java.util.Random

class MinimalSparTreeGenerator(
  val parserFacade: AbstractParserFacade,
  private val sparTreeNodeFactory: SparTreeNodeFactory,
) {

  private val random = Random(0)
  private val persesTokenFactory = sparTreeNodeFactory.tokenizedProgramFactory.tokenFactory

  internal val ruleToPreGeneratedCandidateSparTreeNodeMap =
    generateCandidateSparTreeNode(parserFacade)

  fun generateNodeFromDesignatedAlternative(
    originalLexerRuleNodeList: ImmutableList<LexerRuleSparTreeNode>,
    ruleNameHandle: RuleNameHandle,
    indexOfAlternative: Int,
  ): AbstractSparTreeNode? {
    check(originalLexerRuleNodeList.isNotEmpty())
    val preGeneratedNode =
      ruleToPreGeneratedCandidateSparTreeNodeMap[ruleNameHandle]?.getOrNull(indexOfAlternative)
        ?.recursiveDeepCopy(ReuseNodeIdStrategy) ?: return null
    var lineNumber = originalLexerRuleNodeList.first().token.position.line
    preGeneratedNode.leafNodeSequence().forEach {
      // Fail if any placeholder cannot be filled with a matched original token
      val newLexerNode = if (it.token.isPlaceholder()) {
        val matchedNode = originalLexerRuleNodeList.find { lexerNode ->
          lexerNode.token.type == it.token.type
        } ?: return null
        sparTreeNodeFactory.createLexerRuleSparTreeNode(
          matchedNode.token,
        ).also { lineNumber = matchedNode.token.position.line }
      } else {
        val tokenWithUpdatedLineNumber = it.token.copyWithNewPosition(
          PersesTokenFactory.TokenPosition(lineNumber, it.token.position.charPositionInLine),
        )
        sparTreeNodeFactory.createLexerRuleSparTreeNode(
          tokenWithUpdatedLineNumber,
        )
      }
      it.parent!!.replaceChild(
        it,
        newLexerNode,
        AbstractNodePayload.SinglePayload(newLexerNode.antlrRule),
      )
    }
    preGeneratedNode.linkLeafNodes()
    preGeneratedNode.buildTokenIntervalInfoRecursive()
    check(preGeneratedNode.leafNodeSequence().all { it.token.isPlaceholder().not() })
    return preGeneratedNode
  }

  fun getIndicesOfAlternativesWithSameSize(
    ruleNameHandle: RuleNameHandle,
    originalSize: Int,
  ): ImmutableIntArray {
    return getIndicesOfQualifiedAlternatives(ruleNameHandle, originalSize, Int::equals)
  }

  fun getIndicesOfAlternativesWithSmallerSize(
    ruleNameHandle: RuleNameHandle,
    originalSize: Int,
  ): ImmutableIntArray {
    return getIndicesOfQualifiedAlternatives(ruleNameHandle, originalSize) { a, b -> a < b }
  }

  private fun getIndicesOfQualifiedAlternatives(
    rule: RuleNameHandle,
    originalSize: Int,
    predicate: (size: Int, originalSize: Int) -> Boolean,
  ): ImmutableIntArray {
    val nodeList = ruleToPreGeneratedCandidateSparTreeNodeMap[rule] ?: return ImmutableIntArray.of()
    val indices = ImmutableIntArray.builder()
    for (i in 0 until nodeList.size) {
      if (predicate(nodeList[i].leafTokenCount, originalSize)) {
        indices.add(i)
      }
    }
    return indices.build()
  }

  private fun generateCandidateSparTreeNode(parserFacade: AbstractParserFacade):
    ImmutableMap<RuleNameHandle, ImmutableList<AbstractSparTreeNode>> {
    val mapToBuild = mutableMapOf<RuleNameHandle, ImmutableList<AbstractSparTreeNode>>()
    val rules = parserFacade.ruleHierarchy.ruleList
    val (lexerRules, parserRules) = rules.partition {
      it.ruleDef.isLexerRule
    }
    // filter out the fragment lexer rules
    lexerRules.filter { it.ruleDef.tag == AstTag.RULE_DEFINITION_LEXER }.forEach {
      preBuildLexerRuleSparTreeNode(it, mapToBuild)
    }
    var changed = true
    while (changed) {
      changed = false
      parserRules.forEach {
        changed = preBuildParserRuleSparTreeNode(it, mapToBuild) || changed
      }
    }
    return ImmutableMap.copyOf(mapToBuild)
  }

  private fun preBuildLexerRuleSparTreeNode(
    antlrRule: RuleHierarchyEntry,
    mapToBuild: MutableMap<RuleNameHandle, ImmutableList<AbstractSparTreeNode>>,
  ) {
    val preGeneratedNode = generateSkeletonLexerRuleSparTreeNode(antlrRule)
    check(
      mapToBuild
        .containsKey(antlrRule.ruleDef.ruleNameHandle).not(),
    )
    mapToBuild[antlrRule.ruleDef.ruleNameHandle] =
      ImmutableList.of(preGeneratedNode)
  }

  // Generate for explicit token definitions, used for pre-building node for lexer rule
  private fun generateSkeletonLexerRuleSparTreeNode(
    antlrRule: RuleHierarchyEntry,
  ): LexerRuleSparTreeNode {
    val tokenType = parserFacade.lexerAtnWrapper.metaTokenInfoDB
      .getTokenInfoWithName(antlrRule.ruleName)!!.tokenType
    val literal = getLiteralFromType(tokenType)
    val persesToken = if (literal == null) {
      persesTokenFactory.generatePlaceholderTokenForGivenType(tokenType)
    } else {
      val token = parserFacade.transformLiteralIntoSingleToken(literal)
      persesTokenFactory.createPersesToken(token)
    }
    return sparTreeNodeFactory.createLexerRuleSparTreeNode(persesToken)
  }

  // Generate for implicit token definitions, used when pre-building node for parser rule
  private fun generateLexerRuleSparTreeNode(
    terminal: AbstractPersesRuleElement,
  ): LexerRuleSparTreeNode? {
    val tokenText = generateTokenRec(terminal)
    if (tokenText.isEmpty()) {
      return null
    }
    // FIXME(zy): currently a workaround for deciding token type
    // if this got fixed, generateTokenRec is not needed
    val tokenType = parserFacade.transformLiteralIntoSingleToken(tokenText).type.toTokenType()
    val literal = getLiteralFromType(tokenType)
    val persesToken = if (literal == null) {
      persesTokenFactory.generatePlaceholderTokenForGivenType(tokenType)
    } else {
      val token = parserFacade.transformLiteralIntoSingleToken(literal)
      persesTokenFactory.createPersesToken(token)
    }
    return sparTreeNodeFactory.createLexerRuleSparTreeNode(persesToken)
  }

  private fun preBuildParserRuleSparTreeNode(
    antlrRule: RuleHierarchyEntry,
    mapToBuild: MutableMap<RuleNameHandle, ImmutableList<AbstractSparTreeNode>>,
  ): Boolean {
    val preGeneratedNodeList = preBuildSparTreeNodeRec(
      antlrRule.ruleDef.body,
      mapToBuild,
      antlrRule,
    ) ?: return false
    check(preGeneratedNodeList.isNotEmpty())
    if (mapToBuild.containsKey(antlrRule.ruleDef.ruleNameHandle) &&
      preGeneratedNodeList.all { newNode ->
        mapToBuild[antlrRule.ruleDef.ruleNameHandle]!!.any { originalNode ->
          areEquivalentNodes(originalNode, newNode)
        }
      }
    ) {
      return false
    }
    mapToBuild[antlrRule.ruleDef.ruleNameHandle] = preGeneratedNodeList
    return true
  }

  // return null if all the alternatives refer to other rules and none of them have a spar tree
  // built yet
  private fun preBuildSparTreeNodeRec(
    ruleBody: AbstractPersesRuleElement,
    mapToBuild: MutableMap<RuleNameHandle, ImmutableList<AbstractSparTreeNode>>,
    antlrRule: RuleHierarchyEntry? = null,
  ): ImmutableList<AbstractSparTreeNode>? {
    return when (ruleBody) {
      is PersesAlternativeBlockAst -> {
        val nodeList = mutableListOf<AbstractSparTreeNode>()
        ruleBody.foreachChildRuleElement { alternative ->
          val nodesBuiltFromAlternative = preBuildSparTreeNodeRec(
            alternative,
            mapToBuild,
          ) ?: return@foreachChildRuleElement
          val nodeForTheAlternative = generateParserNodeWithGivenRuleAndChildren(
            antlrRule!!,
            nodesBuiltFromAlternative,
          )
          if (nodeList.any { existingNode ->
              areEquivalentNodes(nodeForTheAlternative, existingNode)
            }
          ) {
            return@foreachChildRuleElement
          }
          nodeList.add(nodeForTheAlternative)
        }
        if (nodeList.isEmpty()) {
          null
        } else {
          nodeList.toImmutableList()
        }
      }
      is PersesSequenceAst -> {
        val children = mutableListOf<AbstractSparTreeNode>()
        ruleBody.foreachChildRuleElement { element ->
          val nodes = preBuildSparTreeNodeRec(element, mapToBuild)
            ?: return null
          check(nodes.size <= 1) {
            "Each element should only generate one node."
          }
          val nodeFromChildElement = nodes.firstOrNull() ?: return@foreachChildRuleElement
          children.add(nodeFromChildElement)
        }
        if (antlrRule == null) {
          children.toImmutableList()
        } else {
          ImmutableList.of(
            generateParserNodeWithGivenRuleAndChildren(antlrRule, children.toImmutableList()),
          )
        }
      }
      is AbstractPersesQuantifiedAst -> {
        val children = if (ruleBody is PersesPlusAst) {
          preBuildSparTreeNodeRec(ruleBody.body, mapToBuild) ?: return null
        } else {
          // FIXME(zy): maybe should also generate for PersesStarAst and PersesQuestionAst
          ImmutableList.of()
        }
        if (antlrRule == null) {
          children
        } else {
          ImmutableList.of(
            generateParserNodeWithGivenRuleAndChildren(antlrRule, children),
          )
        }
      }
      is PersesRuleReferenceAst -> {
        val ruleNameHandle = ruleBody.ruleNameHandle
        val nodes = mapToBuild[ruleNameHandle] ?: return null
        val nodeFromReference = if (nodes.size > 1) {
          ImmutableList.of(
            nodes.minByOrNull {
              it.updateLeafTokenCount()
            }!!.recursiveDeepCopy(ReuseNodeIdStrategy),
          )
        } else {
          nodes.map { it.recursiveDeepCopy(ReuseNodeIdStrategy) }.toImmutableList()
        }
        if (antlrRule == null) {
          nodeFromReference
        } else {
          ImmutableList.of(
            generateParserNodeWithGivenRuleAndChildren(antlrRule, nodeFromReference),
          )
        }
      }
      is PersesRuleElementLabel -> {
        TODO("Not supported yet")
      }
      else -> {
        if (!canBeTerminal(ruleBody)) {
          error("Unreachable rule element type: ${ruleBody.sourceCode}")
        }

        val lexerRuleName = extractTokenReferenceNameOrNull(ruleBody)
        val lexerNode = if (lexerRuleName != null) {
          mapToBuild[lexerRuleName]!!.first().recursiveDeepCopy(ReuseNodeIdStrategy)
        } else {
          generateLexerRuleSparTreeNode(ruleBody)
        }
        if (lexerNode == null) {
          ImmutableList.of()
        } else {
          ImmutableList.of(lexerNode)
        }
      }
    }
  }

  private fun generateParserNodeWithGivenRuleAndChildren(
    antlrRule: RuleHierarchyEntry,
    children: ImmutableList<AbstractSparTreeNode>,
  ): ParserRuleSparTreeNode {
    return sparTreeNodeFactory.createParserRuleSparTreeNode(antlrRule.ruleName).apply {
      for (child in children) {
        this.addChild(
          child.recursiveDeepCopy(ReuseNodeIdStrategy),
          AbstractNodePayload.SinglePayload(child.antlrRule),
        )
      }
      this.linkLeafNodes()
      this.buildTokenIntervalInfoRecursive()
    }
  }

  private fun generateTokenRec(
    ruleBody: AbstractPersesRuleElement,
  ): String {
    return when (ruleBody) {
      is PersesTerminalAst -> {
        if (ruleBody.text.startsWith('\'') && ruleBody.text.endsWith('\'')) {
          StringEscapeUtils.unescapeJava(
            ruleBody.text.substring(1, ruleBody.text.length - 1),
          )
        } else if (ruleBody.text == "EOF") {
          ""
        } else if (ruleBody.text == ".") {
          // Printable Characters: from 0x20 to 0x7f
          (random.nextInt(96) + 32).toChar().toString()
        } else {
          val rule = parserFacade.ruleHierarchy.getRuleHierarchyEntryOrNull(ruleBody.text)!!.ruleDef
          val subRuleBody = rule.body
          generateTokenRec(subRuleBody)
        }
      }
      is PersesLexerCharSet -> {
        // Stripe the bracket
        val charSet = getCharsetFromLexerCharset(ruleBody.text)
        val index = random.nextInt(charSet.size)
        charSet[index].toString()
      }
      is PersesTokenSetAst -> {
        val index = random.nextInt(ruleBody.childCount)
        generateTokenRec(ruleBody.getChild(index))
      }
      is PersesRangeAst -> {
        generateRandomChar(
          ruleBody.getChild(0) as PersesTerminalAst,
          ruleBody.getChild(1) as PersesTerminalAst,
        )
      }
      is PersesNotAst -> {
        when (val subRuleBody = ruleBody.getChild(0)) {
          is PersesLexerCharSet -> {
            val matchedChars = getCharsetFromLexerCharset(subRuleBody.text)
            val candidateChars = mutableListOf<Char>()
            for (i in 0..255) {
              if (i.toChar() !in matchedChars) {
                candidateChars.add(i.toChar())
              }
            }
            val index = random.nextInt(candidateChars.size)
            candidateChars[index].toString()
          }
          is PersesRuleReferenceAst -> {
            TODO("It seems that negation can also be followed by a reference")
          }
          is PersesTokenSetAst -> {
            val matchedTokens = mutableListOf<String>()
            val candidateTokens = mutableListOf<String>()
            subRuleBody.foreachChild { child ->
              matchedTokens.add(
                generateTokenRec(child as AbstractPersesRuleElement),
              )
            }
            for (literal in parserFacade.metaTokenInfoDb.allLiteralLexemes) {
              if (literal !in matchedTokens) {
                candidateTokens.add(literal)
              }
            }
            val index = random.nextInt(candidateTokens.size)
            candidateTokens[index]
          }
          is PersesTerminalAst -> {
            var text = subRuleBody.text
            if (text == "EOF") {
              (random.nextInt(96) + 32).toChar().toString()
            } else {
              if (text.startsWith('\'') && text.endsWith('\'')) {
                text = StringEscapeUtils.unescapeJava(
                  text.subSequence(1, text.length - 1).toString(),
                )
              }
              check(text.length == 1)
              val randomNum = random.nextInt(95) + 32
              if (randomNum >= subRuleBody.text[0].code) {
                (randomNum + 1).toChar().toString()
              } else {
                randomNum.toChar().toString()
              }
            }
          }
          else -> {
            throw AssertionError("Cannot generate token text with the given ruleBody.")
          }
        }
      }
      is PersesAlternativeBlockAst -> {
        val alternative = ruleBody.alternatives[random.nextInt(ruleBody.childCount)]
        return generateTokenRec(alternative)
      }
      is PersesSequenceAst -> {
        val textBuilder = StringBuilder()
        for (child in ruleBody.children) {
          textBuilder.append(generateTokenRec(child))
        }
        textBuilder.toString()
      }
      is PersesEpsilonAst -> {
        ""
      }
      is PersesLexerCommandAst -> {
        // if commands contains "skip", the generator should ignore it
        var isSkip = false
        for (command in ruleBody.commands) {
          if (command.toSourceCode() == "skip") {
            isSkip = true
          }
        }
        if (isSkip) {
          ""
        } else {
          generateTokenRec(ruleBody.body)
        }
      }
      is AbstractPersesQuantifiedAst -> {
        val times = when (ruleBody) {
          is PersesStarAst -> random.nextInt(5)
          is PersesOptionalAst -> random.nextInt(2)
          else -> random.nextInt(4) + 1
        }
        val textBuilder = StringBuilder()
        for (i in 0 until times) {
          textBuilder.append(generateTokenRec(ruleBody.body))
        }
        textBuilder.toString()
      }
      is PersesActionAst -> {
        ""
      }
      else -> {
        throw AssertionError("Cannot generate token text with the given ruleBody.")
      }
    }
  }

  private fun generateRandomChar(start: PersesTerminalAst, end: PersesTerminalAst): String {
    val sb = StringBuilder()
    sb.append('[')
    sb.append(start.text.substring(1, start.text.length - 1))
    sb.append('-')
    sb.append(end.text.substring(1, end.text.length - 1))
    sb.append(']')
    val charset = getCharsetFromLexerCharset(sb.toString())
    return charset[random.nextInt(charset.size)].toString()
  }

  internal fun getCharsetFromLexerCharset(lexerCharset: String): List<Char> {
    check(lexerCharset.length > 2) // There must be at least one char in bracket
    val ranges = mutableListOf<Pair<Char, Char>>()
    var offset = 0
    val text = lexerCharset.substring(1, lexerCharset.length - 1)
    val charset = mutableListOf<Char>()
    while (offset < text.length) {
      val startAndNewOffset = parseLexerCharset(text, offset)
      offset = startAndNewOffset.second
      // if it is not a range (not something like a-z), just add the char to the charset
      if (offset >= text.length || text[offset] != '-') {
        startAndNewOffset.first?.let { charset.add(it) }
        continue
      }
      check(text[offset] == '-')
      // if '-' is the last char, just add it to the charset
      if (offset == text.length - 1) {
        charset.add('-')
        startAndNewOffset.first?.let { charset.add(it) }
        break
      }
      ++offset
      val endAndNewOffset = parseLexerCharset(text, offset)
      offset = endAndNewOffset.second
      // \p{...} should not be in a range
      ranges.add(Pair(startAndNewOffset.first!!, endAndNewOffset.first!!))
    }
    for (pair in ranges) {
      for (char in pair.first..pair.second) {
        charset.add(char)
      }
    }
    return charset.toList()
  }

  private fun parseLexerCharset(text: String, offset: Int): Pair<Char?, Int> {
    val ANTLRLiteralEscapedCharValue = mapOf(
      'n' to '\n',
      'r' to '\r',
      't' to '\t',
      'b' to '\b',
      'f' to '\u000C',
      '\\' to '\\',
      '-' to '-',
      ']' to ']',
    )
    // This function refers to grammarinator and org/antlr/v4/misc/EscapeSequenceParsing.java
    if (text[offset] != '\\') {
      return Pair(text[offset], offset + 1)
    }
    check(offset + 1 < text.length)

    when (val escaped = text[offset + 1]) {
      'u' -> {
        val hexStartOffset: Int
        val hexEndOffset: Int
        if (text[offset + 2] == '{') {
          // if lexer charset is in the format of \u{...}
          hexStartOffset = offset + 3
          hexEndOffset = text.indexOf('}', hexStartOffset)
          check(hexEndOffset > hexStartOffset)
        } else {
          // if lexer charset is in the format of \uXXXX
          hexStartOffset = offset + 2
          hexEndOffset = offset + 6
          check(hexEndOffset <= text.length)
        }
        val codePoint = Integer.valueOf(text.substring(hexStartOffset, hexEndOffset), 16)
        return Pair(codePoint.toChar(), hexEndOffset)
      }
      'p', 'P' -> {
        var newOffset = offset
        while (text[newOffset] != '}') {
          ++newOffset
        }
        return Pair(null, newOffset + 1)
      }
      in ANTLRLiteralEscapedCharValue.keys -> {
        return Pair(ANTLRLiteralEscapedCharValue[escaped]!!, offset + 2)
      }
      else -> throw AssertionError("Invalid escaped value")
    }
  }

  private fun getLiteralFromType(ruleType: TokenType): String? {
    val tokenInfo = parserFacade.metaTokenInfoDb.getTokenInfoWithType(ruleType)!!
    return tokenInfo.literalLexeme
  }

  private fun extractTokenReferenceNameOrNull(
    ruleBody: AbstractPersesRuleElement,
  ): RuleNameHandle? {
    if (ruleBody.tag != AstTag.TERMINAL) {
      return null
    }
    return parserFacade.ruleHierarchy
      .getRuleHierarchyEntryOrNull((ruleBody as PersesTerminalAst).text)
      ?.ruleDef?.ruleNameHandle
  }

  companion object {
    private fun canBeTerminal(ruleBody: AbstractPersesRuleElement): Boolean {
      return when (ruleBody.tag) {
        AstTag.LEXER_CHAR_SET,
        AstTag.UNKNOWN_TERMINAL_WITH_UNIT_PRECEDENCE,
        AstTag.TERMINAL,
        AstTag.TOKEN_SET,
        AstTag.LEXER_COMMAND,
        AstTag.NOT,
        AstTag.ACTION,
        AstTag.EPSILON,
        AstTag.LEXER_RANGE_OPERATOR,
        -> true
        else -> false
      }
    }

    private fun areEquivalentNodes(
      node1: AbstractSparTreeNode,
      node2: AbstractSparTreeNode,
    ): Boolean {
      val lexerNodeList1 = node1.leafNodeSequence().toList()
      val lexerNodeList2 = node2.leafNodeSequence().toList()
      if (lexerNodeList1.size != lexerNodeList2.size) {
        return false
      } else {
        for (i in lexerNodeList1.indices) {
          if (lexerNodeList1[i].token.text != lexerNodeList2[i].token.text) {
            return false
          }
        }
      }
      return true
    }
  }
}
