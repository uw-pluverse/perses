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
import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.CommonTokenFactory
import org.antlr.v4.tool.Grammar
import org.apache.commons.text.StringEscapeUtils
import org.perses.antlr.AbstractAntlrGrammar
import org.perses.antlr.AntlrGrammarParser
import org.perses.antlr.GrammarHierarchy
import org.perses.antlr.TokenType
import org.perses.antlr.ast.AbstractPersesQuantifiedAst
import org.perses.antlr.ast.AbstractPersesRuleDefAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesActionAst
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesEpsilonAst
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesLexerCharSet
import org.perses.antlr.ast.PersesLexerCommandAst
import org.perses.antlr.ast.PersesNotAst
import org.perses.antlr.ast.PersesOptionalAst
import org.perses.antlr.ast.PersesRangeAst
import org.perses.antlr.ast.PersesRuleReferenceAst
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.PersesStarAst
import org.perses.antlr.ast.PersesTerminalAst
import org.perses.antlr.ast.PersesTokenSetAst
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.grammar.AbstractParserFacade
import org.perses.program.PersesTokenFactory
import org.perses.program.PersesTokenFactory.PersesToken
import org.perses.program.TokenizedProgramFactory
import org.perses.util.Util
import org.perses.util.sample
import java.util.Random
import java.util.concurrent.ConcurrentHashMap

abstract class AbstractSparTreeGenerator(
  val parserFacade: AbstractParserFacade,
  val random: Random,
) {
  val antlrGrammar: AbstractAntlrGrammar = parserFacade.antlrGrammar
  val grammarHierarchy: GrammarHierarchy = parserFacade.ruleHierarchy
  val language = parserFacade.language
  private val identifierTokenType = parserFacade.identifierTokenTypes

  private val parserGrammar: PersesGrammar
  private val persesTokenFactory = PersesTokenFactory()
  private val lexerGrammar: PersesGrammar?

  protected var startNodeId = 0

  @VisibleForTesting
  val ruleGenerationInfo: RuleGenerationInfo

  private val corpus: ConcurrentHashMap<TokenType, MutableSet<String>> = ConcurrentHashMap()

  init {
    parserGrammar = if (antlrGrammar.isCombined) {
      antlrGrammar.asCombined().grammar
    } else {
      antlrGrammar.asSeparate().parserGrammar
    }
    lexerGrammar = if (antlrGrammar.isCombined) {
      null
    } else {
      antlrGrammar.asSeparate().lexerGrammar
    }
    ruleGenerationInfo = RuleGenerationInfo(antlrGrammar)
  }

  fun generateFromStartSymbol(): SparTree? {
    val maxDepth = STANDARD_DEVIATION_OF_DEPTH * random.nextGaussian() + MEAN_OF_DEPTH
    if (
      maxDepth < ruleGenerationInfo
        .getMinDepth(
          grammarHierarchy.getRuleHierarchyEntryWithNameOrThrow(
            ruleGenerationInfo.startSymbol.ruleName,
          )
            .ruleDef.body,
        )
    ) {
      return null
    }
    val generatedNode = generateParserRuleSparTreeNode(ruleGenerationInfo.startSymbol)
      ?: return null
    val tokenList = mutableListOf<PersesToken>()
    generatedNode.preOrderVisit {
      if (it.isTokenNode) {
        tokenList.add((it as LexerRuleSparTreeNode).token)
      }
      it.immutableChildView
    }
    // TODO(zhenyang): need to factory this
    val sparTreeNodeFactory = SparTreeNodeFactory(
      parserFacade.metaTokenInfoDb,
      // FIXME: this static factory method takes List<Token> as its first parameter and will
      // convert it to List<PersesToken> but here the token list is already List<PersesToken>
      // add a static method or think of another way to build a SparTree from SparTreeNode
      TokenizedProgramFactory.createFactory(tokenList, language),
      grammarHierarchy,
    )
    return SparTree(
      generatedNode,
      sparTreeNodeFactory,
    )
  }

  fun generateParserRuleSparTreeNode(ruleNameHandle: RuleNameHandle): ParserRuleSparTreeNode? {
    val ruleDef = grammarHierarchy
      .getRuleHierarchyEntryWithNameOrThrow(ruleNameHandle.ruleName).ruleDef
    assert(ruleDef.isParserRule)
    val ruleBody = ruleDef.body
    val maxDepth = ruleGenerationInfo.getMinDepth(ruleBody) + 5
    return generateParserRuleSparTreeNodeWithMaxDepth(ruleNameHandle, maxDepth)
  }

  private fun generateParserRuleSparTreeNodeWithMaxDepth(
    ruleNameHandle: RuleNameHandle,
    maxDepth: Int,
  ): ParserRuleSparTreeNode? {
    val generatedNode =
      internalGenerateParserRuleSparTreeNodeWithMaxDepth(ruleNameHandle, maxDepth)
    SparTreeSimplifier.simplify(generatedNode)
    generatedNode.linkLeafNodes()
    generatedNode.buildTokenIntervalInfoRecursive()
    if (generatedNode.childCount == 0) {
      return null
    }
    return generatedNode
  }

  protected abstract fun internalGenerateParserRuleSparTreeNodeWithMaxDepth(
    ruleNameHandle: RuleNameHandle,
    maxDepth: Int,
  ): ParserRuleSparTreeNode

  protected fun generateLexerRuleSparTreeNode(
    terminal: AbstractPersesRuleElement,
  ): LexerRuleSparTreeNode {
    val token = generatePersesToken(terminal)
    return LexerRuleSparTreeNode(startNodeId++, token, null)
  }

  // TODO: Try to generate PersesToken with more information (e.g. Line Information)
  fun generatePersesToken(
    ruleBody: AbstractPersesRuleElement,
  ): PersesToken {
    var antlrToken = generateAntlrToken(ruleBody)
    if (antlrToken.type == INVALID_TOKEN_TYPE.antlrTokenType) {
      antlrToken = parserFacade.transformLiteralIntoSingleToken(antlrToken.text)
    }
    return persesTokenFactory.createPersesToken(antlrToken)
  }

  // TODO: Refactor this function
  @Synchronized
  private fun generateAntlrToken(
    ruleBody: AbstractPersesRuleElement,
  ): org.antlr.v4.runtime.Token {
    var tokenType = INVALID_TOKEN_TYPE
    val tokenText: String = when (ruleBody) {
      is PersesTerminalAst -> {
        val tokenInfo =
          parserFacade.lexerAtnWrapper.metaTokenInfoDB.getTokenInfoWithName(ruleBody.text)
        if (tokenInfo != null) {
          tokenType = tokenInfo.tokenType
        }
        if (tokenType in identifierTokenType) {
          val newId: String = if (
            random.nextInt((1 / RATE_TO_CREATE_UNIQUE_ID).toInt()) == 0 ||
            corpus[tokenType] == null
          ) {
            "identifier_${corpus[tokenType]?.size ?: 0}"
          } else {
            corpus[tokenType]!!.elementAt(random.nextInt(corpus[tokenType]!!.size))
          }
          newId
        } else if (ruleBody.text.startsWith('\'') && ruleBody.text.endsWith('\'')) {
          StringEscapeUtils.unescapeJava(
            ruleBody.text.subSequence(1, ruleBody.text.length - 1).toString(),
          )
        } else if (ruleBody.text == "EOF") {
          ""
        } else if (ruleBody.text == ".") {
          // Printable Characters: from 0x20 to 0x7f
          (random.nextInt(96) + 32).toChar().toString()
        } else {
          // Text of PersesTerminalAst can be the name of fragment rule
          if (
            random.nextInt((1 / RATE_TO_CREATE_UNIQUE_TOKEN).toInt()) == 0 ||
            corpus[tokenType] == null
          ) {
            var rule: AbstractPersesRuleDefAst?
            if (antlrGrammar.isCombined) {
              rule = parserGrammar.getRuleDefinition(ruleBody.text)!!
              checkNotNull(rule)
            } else {
              rule = parserGrammar.getRuleDefinition(ruleBody.text)
              if (rule == null) rule = lexerGrammar!!.getRuleDefinition(ruleBody.text)
              checkNotNull(rule)
            }
            val subRuleBody = rule.body
            generateAntlrToken(subRuleBody).text
          } else {
            corpus[tokenType]!!.elementAt(random.nextInt(corpus[tokenType]!!.size))
          }
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
        generateAntlrToken(ruleBody.getChild(index)).text
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
            ruleBody.foreachChild { child ->
              matchedTokens.add(
                generateAntlrToken(child as AbstractPersesRuleElement).text,
              )
            }
            for (token in parserFacade.lexerAtnWrapper.metaTokenInfoDB.allLiteralLexemes) {
              if (token !in matchedTokens) {
                candidateTokens.add(token)
              }
            }
            check(candidateTokens.isNotEmpty()) {
              """|
                 |subRuleBody = ${subRuleBody.sourceCode}
                 |
                 |matched tokens = $matchedTokens
                 |
              """.trimMargin()
            }
            random.sample(candidateTokens)
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
              assert(text.length == 1)
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
        return generateAntlrToken(alternative)
      }
      is PersesSequenceAst -> {
        val textBuilder = StringBuilder()
        for (child in ruleBody.children) {
          textBuilder.append(generateAntlrToken(child).text)
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
          generateAntlrToken(ruleBody.body).text
        }
      }
      is AbstractPersesQuantifiedAst -> {
        val times = when (ruleBody) {
          is PersesStarAst -> random.nextInt(10)
          is PersesOptionalAst -> random.nextInt(2)
          else -> random.nextInt(9) + 1
        }
        val textBuilder = StringBuilder()
        for (i in 0 until times) {
          textBuilder.append(generateAntlrToken(ruleBody.body).text)
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
    return CommonTokenFactory().create(tokenType.antlrTokenType, tokenText)
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

  private fun getAntlrToolGrammar(grammar: AbstractAntlrGrammar): Grammar {
    return if (grammar.isCombined) {
      getAntlrToolGrammarFromCombinedAntlrGrammar(grammar.asCombined())
    } else {
      getAntlrToolGrammarFromSeparateAntlrGrammar(grammar.asSeparate())
    }
  }

  private fun getAntlrToolGrammarFromCombinedAntlrGrammar(
    grammar: AbstractAntlrGrammar.CombinedAntlrGrammar,
  ): Grammar {
    val lexerGrammar: PersesGrammar = grammar.grammar
    val antlrGrammarContent: String = lexerGrammar.sourceCode
    return AntlrGrammarParser.loadAntlrGrammarFromString(antlrGrammarContent)
  }

  private fun getAntlrToolGrammarFromSeparateAntlrGrammar(
    grammar: AbstractAntlrGrammar.SeparateAntlrGrammar,
  ): Grammar {
    val lexerGrammar: PersesGrammar = grammar.lexerGrammar
    val antlrGrammarContent: String = lexerGrammar.sourceCode
    return AntlrGrammarParser.loadAntlrGrammarFromString(antlrGrammarContent)
  }

  private fun getCharsetFromLexerCharset(lexerCharset: String): List<Char> {
    assert(lexerCharset.length > 2) // There must be at least one char in bracket
    val ranges = mutableListOf<Pair<Char, Char>>()
    var offset = 0
    val text = lexerCharset.substring(1, lexerCharset.length - 1)
    while (offset < text.length) {
      val inRange = text[offset] == '-' && offset != 0 && offset != text.length - 1
      if (inRange) offset += 1
      val result = parseLexerCharset(text, offset)
      offset = result.second
      if (inRange) {
        ranges.add(Pair(ranges[ranges.size - 1].first, result.first))
      } else {
        ranges.add(Pair(result.first, result.first + 1))
      }
    }
    val charset = mutableListOf<Char>()
    for (pair in ranges) {
      for (char in pair.first until pair.second) {
        charset.add(char)
      }
    }
    return charset.toList()
  }

  private fun parseLexerCharset(text: String, offset: Int): Pair<Char, Int> {
    val ANTLRLiteralEscapedCharValue = mapOf<Char, Char>(
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
    if (text[offset] != '\\') return Pair(text[offset], offset + 1)
    assert(offset + 1 < text.length)

    when (val escaped = text[offset + 1]) {
      'u' -> {
        val hexStartOffset: Int
        val hexEndOffset: Int
        if (text[offset + 2] == '{') {
          // if lexer charset is in the format of \u{...}
          hexStartOffset = offset + 3
          hexEndOffset = text.indexOf('}', hexStartOffset)
          assert(hexEndOffset > hexStartOffset)
        } else {
          // if lexer charset is in the format of \uXXXX
          hexStartOffset = offset + 2
          hexEndOffset = offset + 6
          assert(hexEndOffset <= text.length)
        }
        val codePoint = Integer.valueOf(text.substring(hexStartOffset, hexEndOffset), 16)
        return Pair(codePoint.toChar(), hexEndOffset + 1)
      }
      'p', 'P' -> {
        TODO("\\p{...} is not supported for now")
      }
      in ANTLRLiteralEscapedCharValue.keys -> {
        return Pair(ANTLRLiteralEscapedCharValue[escaped]!!, offset + 2)
      }
      else -> throw AssertionError("Invalid escaped value")
    }
  }

  fun updateCorpus(tree: SparTree) {
    for (lexerNode in tree.remainingLexerRuleNodes) {
      val tokenType = lexerNode.token.type
      if (corpus.containsKey(tokenType)) {
        corpus[tokenType]!!.add(lexerNode.token.text)
      } else {
        val newSet = Util.createConcurrentSet<String>()
        newSet.add(lexerNode.token.text)
        corpus[tokenType] = newSet
      }
    }
  }

  companion object {
    val INVALID_TOKEN_TYPE = TokenType(Integer.MIN_VALUE)
    const val RATE_TO_CREATE_UNIQUE_TOKEN = 0.01
    const val RATE_TO_CREATE_UNIQUE_ID = 0.5

    // When generate from start symbol, make the maxDepth follow the gaussian distribution
    // so that some time it can have the possibility to generate relatively large program
    // while keep the most generation efficient.
    const val MEAN_OF_DEPTH = 20
    const val STANDARD_DEVIATION_OF_DEPTH = 5
    fun getTokenList(node: AbstractSparTreeNode?): ImmutableList<PersesToken> {
      if (node == null) {
        return ImmutableList.of()
      }
      val builder = ImmutableList.builder<PersesToken>()
      node.preOrderVisit {
        if (it.isTokenNode) {
          builder.add((it as LexerRuleSparTreeNode).token)
        }
        return@preOrderVisit it.immutableChildView
      }
      return builder.build()
    }
  }
}
