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
package org.perses.antlr.ast

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import org.antlr.v4.parse.ANTLRParser
import org.antlr.v4.tool.ast.ActionAST
import org.antlr.v4.tool.ast.AltAST
import org.antlr.v4.tool.ast.BlockAST
import org.antlr.v4.tool.ast.GrammarAST
import org.antlr.v4.tool.ast.GrammarRootAST
import org.antlr.v4.tool.ast.NotAST
import org.antlr.v4.tool.ast.OptionalBlockAST
import org.antlr.v4.tool.ast.PlusBlockAST
import org.antlr.v4.tool.ast.RangeAST
import org.antlr.v4.tool.ast.RuleAST
import org.antlr.v4.tool.ast.RuleRefAST
import org.antlr.v4.tool.ast.SetAST
import org.antlr.v4.tool.ast.StarBlockAST
import org.antlr.v4.tool.ast.TerminalAST
import org.perses.antlr.AntlrGrammarParser
import org.perses.antlr.ast.PersesGrammar.GrammarType
import org.perses.antlr.ast.PersesParserRuleAst.ParserRuleAttributes
import org.perses.util.toImmutableList
import java.nio.file.Path
import kotlin.io.path.readText

class PersesAstBuilder(private val root: GrammarRootAST) {

  init {
    require(root.childCount >= 2) {
      "Invalid child count ${root.childCount} $root"
    }
  }

  private val symbolTable = SymbolTable()
  private val grammarName = (root.getChild(0) as GrammarAST).getToken().text
  private val rootChildren = (1 until root.childCount)
    .asSequence()
    .map { root.getChild(it) as GrammarAST }
    .toImmutableList()
  private val processedRootChildren = HashSet<GrammarAST>()

  private val grammarType = identifyGrammarType(root)
  private val namedActions = extractNamedActions()
  private val grammarOptions = extractGrammarOptions()
  private val channelDefinitions = extractChannelDefinitions()
  private val tokenSpecifications = extractTokenSpecification()

  private val rulesRootNode = selectRootChildren { isRulesNode(it) }
    .single()
    .also {
      check("RULES" == it.getToken().text && it.getToken().type == ANTLRParser.RULES) {
        it
      }
    }
  private val rulesDefList = IntRange(0, rulesRootNode.childCount - 1)
    .asSequence()
    .map { rulesRootNode.getChild(it) as RuleAST }
    .onEach {
      check(it.getToken().text == "RULE" && it.getToken().type == ANTLRParser.RULE) {
        it
      }
    }.toList()

  private val lexerModeNodes =
    selectRootChildren { isLexerMode(it) }.toImmutableList()

  private val persesLexerModeAsts = convertLexerModes(lexerModeNodes)

  private val lexerRuleDefList = rulesDefList
    .asSequence()
    .filter { it.isLexerRule }
    .toImmutableList()

  private val parserRuleDefList = rulesDefList
    .asSequence()
    .filter { !it.isLexerRule }
    .toImmutableList()

  init {
    check(
      HashSet<RuleAST>().apply {
        addAll(lexerRuleDefList)
        addAll(parserRuleDefList)
      } == HashSet<RuleAST>(rulesDefList),
    )
  }

  // Note that the order of lexerRuleDefList and parserRuleDefList can affect the order or rules.
  private val persesLexerRuleDefs = LexerRuleList(
    lexerRuleDefList
      .asSequence()
      .map { convertLexerRuleDefinition(it, symbolTable) }
      .toImmutableList(),
    persesLexerModeAsts,
  )

  private val persesParserRuleDefs = parserRuleDefList
    .asSequence()
    .map { convertParserRuleDefinition(it, symbolTable) }
    .toImmutableList()

  val grammar: PersesGrammar = PersesGrammar(
    grammarType,
    grammarName,
    channelDefinitions,
    tokenSpecifications,
    grammarOptions,
    namedActions,
    persesLexerRuleDefs,
    persesParserRuleDefs,
    symbolTable,
  )

  init {
    check(processedRootChildren.size == rootChildren.size) {
      "Unhandled nodes: ${rootChildren.minus(processedRootChildren)}"
    }
  }

  private fun convertLexerModes(
    modes: ImmutableList<GrammarAST>,
  ): ImmutableList<LexerModeWithLexerRules> {
    val result = ImmutableList.builder<LexerModeWithLexerRules>()
    for (modeAst in modes) {
      check(isLexerMode(modeAst))
      val childCount = modeAst.childCount
      check(childCount > 1) { childCount }
      val modeNameAst = modeAst.getChild(0)
      check(modeNameAst.childCount == 0)
      val modeName = modeNameAst.text

      val rules = IntRange(1, childCount - 1)
        .asSequence()
        .map { modeAst.getChild(it) as RuleAST }
        .map { convertLexerRuleDefinition(it, symbolTable) }
        .toImmutableList()
      result.add(LexerModeWithLexerRules(modeName, rules))
    }
    return result.build()
  }

  private fun extractChannelDefinitions(): PersesChannelDefinitionAst {
    val channels = selectRootChildren { isChannelDefinition(it) }
      .map { convertChannelDefinitions(it) }
      .toList()
    return when (channels.size) {
      0 -> PersesChannelDefinitionAst.EMPTY
      1 -> channels.single()
      else -> throw RuntimeException("Multiple channel definitions are found: $channels")
    }
  }

  private fun extractTokenSpecification(): PersesTokenSpecificationAst {
    val tokenSpecifications = selectRootChildren { isTokenSpecification(it) }
      .map { convertTokenSpecifications(it) }
      .toList()
    return when (tokenSpecifications.size) {
      0 -> PersesTokenSpecificationAst.EMTY
      1 -> tokenSpecifications.single()
      else ->
        throw RuntimeException("Multiple token specifications are found: $tokenSpecifications")
    }
  }

  private fun extractNamedActions(): ImmutableList<PersesNamedAction> {
    return selectRootChildren { isNamedActionNode(it) }
      .map {
        check(it.childCount >= 2)
        val name = extractNameFromNamedActionNode(it)
        val lastChild = it.getChild(it.childCount - 1) as GrammarAST
        check(lastChild is ActionAST)
        val body = lastChild.text
        PersesNamedAction(name, body)
      }.toImmutableList()
  }

  private fun extractGrammarOptions(): PersesGrammarOptionsAst {
    val optionList = selectRootChildren { isOptionsNode(it) }
      .map { convertOptions(it) }
      .toList()
    return when (optionList.size) {
      0 -> PersesGrammarOptionsAst.EMPTY
      1 -> optionList.single()
      else -> throw java.lang.RuntimeException("Multiple options. $optionList")
    }
  }

  private fun selectRootChildren(predicate: (GrammarAST) -> Boolean): Sequence<GrammarAST> {
    return rootChildren
      .asSequence()
      .filter(predicate)
      .onEach {
        check(processedRootChildren.add(it)) {
          "The root child has been selected before. $it"
        }
      }
  }

  private class RawRuleAttributes {
    var isFragment = false
    var arguments: ActionAST? = null
    var returnAst: GrammarAST? = null
    var localsAst: GrammarAST? = null
    fun convert(symbolTable: SymbolTable): ParserRuleAttributes {
      val args = if (arguments == null) {
        null
      } else {
        dispatchConversion(arguments!!, symbolTable) as PersesActionAst
      }
      val returns = if (returnAst == null) {
        null
      } else {
        dispatchConversion(returnAst!!, symbolTable) as PersesActionAst
      }
      val locals = if (localsAst == null) {
        null
      } else {
        dispatchConversion(localsAst!!, symbolTable) as PersesActionAst
      }
      return ParserRuleAttributes(args, returns, locals)
    }
  }

  companion object {

    @JvmStatic
    fun loadGrammarFromFile(file: Path): PersesGrammar {
      return loadGrammarFromString(file.readText())
    }

    @JvmStatic
    fun loadGrammarFromString(grammarContent: String): PersesGrammar {
      return PersesAstBuilder(AntlrGrammarParser.parseRawGrammarASTFromString(grammarContent))
        .grammar
    }

    private fun convertOptions(secondChild: GrammarAST): PersesGrammarOptionsAst {
      val builder = ImmutableList.builder<PersesGrammarOptionsAst.Option>()
      val childCount = secondChild.childCount
      for (i in 0 until childCount) {
        val child = secondChild.getChild(i) as GrammarAST
        check(child.text == "=")
        check(child.childCount == 2)
        builder.add(
          PersesGrammarOptionsAst.Option(
            child.getChild(0).text,
            child.getChild(1).text,
          ),
        )
      }
      return PersesGrammarOptionsAst(builder.build())
    }

    /**
     * It allows you to introduce imaginary tokens, which are token names
     * that are not associated with any particular input character(s).
     * Imaginary tokens usually become subtree root nodes that act as operators
     * for a series of operands (children).
     */
    private fun isTokenSpecification(node: GrammarAST): Boolean {
      val text = node.text ?: return false
      val segments = text.split("\\s+".toRegex()).toTypedArray()
      return if (segments.size != 2) {
        false
      } else {
        "tokens" == segments[0] && "{" == segments[1]
      }
    }

    private fun isChannelDefinition(node: GrammarAST): Boolean {
      val text = node.text ?: return false
      val segments = text.split("\\s+".toRegex()).toTypedArray()
      return if (segments.size != 2) {
        false
      } else {
        "channels" == segments[0] && "{" == segments[1]
      }
    }

    private fun convertTokenSpecifications(node: GrammarAST): PersesTokenSpecificationAst {
      require(isTokenSpecification(node))
      val builder = ImmutableList.builderWithExpectedSize<String>(node.childCount)
      for (i in 0 until node.childCount) {
        builder.add(node.getChild(i).text)
      }
      return PersesTokenSpecificationAst(builder.build())
    }

    private fun convertChannelDefinitions(node: GrammarAST): PersesChannelDefinitionAst {
      require(isChannelDefinition(node))
      val builder = ImmutableList.builderWithExpectedSize<String>(node.childCount)
      for (i in 0 until node.childCount) {
        builder.add(node.getChild(i).text)
      }
      return PersesChannelDefinitionAst(builder.build())
    }

    private fun extractNameFromNamedActionNode(node: GrammarAST): String {
      require(isNamedActionNode(node))
      val childCount = node.childCount
      val builder = StringBuilder()
      check(childCount > 1)
      val firstChild = node.getChild(0) as GrammarAST
      builder.append(firstChild.text)
      for (i in 1 until childCount - 1) {
        builder.append("::").append(node.getChild(i).text)
      }
      return builder.toString()
    }

    private fun identifyGrammarType(root: GrammarRootAST): GrammarType {
      return when (root.text) {
        "COMBINED_GRAMMAR" -> GrammarType.COMBINED
        "PARSER_GRAMMAR" -> GrammarType.PARSER
        "LEXER_GRAMMAR" -> GrammarType.LEXER
        else -> throw RuntimeException("Unsupported grammar type: " + root.text)
      }
    }

    private fun isOptionsNode(ast: GrammarAST) =
      ast.text == "OPTIONS" && ast.token.type == ANTLRParser.OPTIONS

    private fun isLexerMode(ast: GrammarAST) =
      ast.text == "mode" && ast.token.type == ANTLRParser.MODE

    private fun isRulesNode(ast: GrammarAST) =
      ast.text == "RULES" && ast.token.type == ANTLRParser.RULES

    private fun isNamedActionNode(ast: GrammarAST) =
      ast.text == "@" && ast.token.type == ANTLRParser.AT

    private fun parseRuleAttributes(ruleAST: RuleAST): RawRuleAttributes {
      val childCount = ruleAST.childCount
      val results = RawRuleAttributes()
      check(ruleAST.getChild(childCount - 1) is BlockAST)
      for (i in 1 until childCount - 1) {
        val ast = ruleAST.getChild(i) as GrammarAST
        if (isTokenFragment(ast)) {
          check(!results.isFragment)
          results.isFragment = true
        } else if (ast is ActionAST) {
          check(results.arguments == null)
          results.arguments = ast
          check(results.arguments != null)
        } else if (ast.getToken().type == ANTLRParser.RETURNS) {
          check(ast.childCount == 1)
          check(ast.getChild(0) is ActionAST)
          check(results.returnAst == null)
          results.returnAst = ast.getChild(0) as GrammarAST
          check(results.returnAst != null)
        } else if (ast.getToken().type == ANTLRParser.LOCALS) {
          check(ast.childCount == 1)
          check(ast.getChild(0) is ActionAST)
          check(results.localsAst == null)
          results.localsAst = ast.getChild(0) as GrammarAST
          check(results.localsAst != null)
        } else {
          throw RuntimeException("Unhandled child $ast")
        }
      }
      return results
    }

    private fun convertParserRuleDefinition(
      parserRuleAST: RuleAST,
      symbolTable: SymbolTable,
    ): PersesParserRuleAst {
      check(!parserRuleAST.isLexerRule)

      val childCount = parserRuleAST.childCount
      require(childCount in 2..5)
      require(parserRuleAST.getChild(0) is GrammarAST)
      require(parserRuleAST.getChild(childCount - 1) is BlockAST)
      val ruleNameAst = parserRuleAST.getChild(0) as GrammarAST
      val ruleNameHandle = symbolTable.ruleNameRegistry.getOrCreate(ruleNameAst.getToken().text)
      val ruleBody = parserRuleAST.getChild(childCount - 1) as BlockAST
      val attributes = parseRuleAttributes(parserRuleAST)

      try {
        val body = convertAlternativeBlock(ruleBody, symbolTable)
        return PersesParserRuleAst(ruleNameHandle, body, attributes.convert(symbolTable))
      } catch (e: Throwable) {
        throw java.lang.RuntimeException("Fail to parse the rule '${ruleNameHandle.ruleName}'", e)
      }
    }

    private fun convertLexerRuleDefinition(
      lexerRuleAST: RuleAST,
      symbolTable: SymbolTable,
    ): AbstractPersesLexerRuleAst {
      check(lexerRuleAST.isLexerRule)

      val childCount = lexerRuleAST.childCount
      require(childCount in 2..5)
      require(lexerRuleAST.getChild(0) is GrammarAST)
      require(lexerRuleAST.getChild(childCount - 1) is BlockAST)
      val ruleNameAst = lexerRuleAST.getChild(0) as GrammarAST
      val ruleNameHandle = symbolTable.ruleNameRegistry.getOrCreate(ruleNameAst.getToken().text)
      val ruleBody = lexerRuleAST.getChild(childCount - 1) as BlockAST
      val attributes = parseRuleAttributes(lexerRuleAST)
      if (attributes.isFragment) {
        check(childCount == 3)
        val body = convertAlternativeBlock(ruleBody, symbolTable)
        return PersesFragmentLexerRuleAst(ruleNameHandle, body)
      }
      check(childCount == 2) { "Invalid child count: $childCount" }
      check(ruleBody.childCount >= 1) {
      }
      val firstChildOfRuleBody = ruleBody.getChild(0) as GrammarAST

      if (ruleBody.childCount == 1 &&
        firstChildOfRuleBody.getToken().type == ANTLRParser.LEXER_ALT_ACTION
      ) {
        val lexerAltAction = ruleBody.getChild(0) as AltAST
        check(lexerAltAction.childCount >= 2)

        val firstChild = lexerAltAction.getChild(0) as GrammarAST
        val body = convertSingleAlternative(firstChild as AltAST, symbolTable)

        val commands = IntRange(1, lexerAltAction.childCount - 1)
          .asSequence()
          .map { lexerAltAction.getChild(it) as GrammarAST }
          .map {
            when (it.text) {
              "skip", "popMode", "more" -> AbstractLexerCommand.create(it.text)
              "LEXER_ACTION_CALL" -> {
                val lexerCommandName = it.getChild(0).text
                check(
                  lexerCommandName == "channel" ||
                    lexerCommandName == "pushMode" ||
                    lexerCommandName == "mode" ||
                    lexerCommandName == "type",
                )
                val commandArg = it.getChild(1).text
                AbstractLexerCommand.create(lexerCommandName, commandArg)
              }
              else -> TODO()
            }
          }.toImmutableList()
        return PersesLexerRuleAst(ruleNameHandle, PersesLexerCommandAst(commands, body))
      }
      if (firstChildOfRuleBody.token.type == ANTLRParser.ALT) {
        val body = convertAlternativeBlock(ruleBody, symbolTable)
        return PersesLexerRuleAst(ruleNameHandle, body)
      }
      throw RuntimeException("Unreachable.")
    }

    private fun isTokenFragment(ast: GrammarAST): Boolean {
      if (ast.getToken().type != ANTLRParser.RULEMODIFIERS) {
        return false
      }
      require(ast.childCount == 1)
      require(ast.getChild(0).text == "fragment")
      return true
    }

    private fun convertAlternativeBlock(
      block: BlockAST,
      symbolTable: SymbolTable,
    ): AbstractPersesRuleElement {
      val childNodeClasses = collectChildNodeClasses(block)
      require(childNodeClasses.size == 1) { childNodeClasses }
      require(childNodeClasses.iterator().next() == AltAST::class.java)
      val builder = ImmutableList.builder<AbstractPersesRuleElement>()
      val childCount = block.childCount
      for (i in 0 until childCount) {
        val child = block.getChild(i) as AltAST
        val convertedChild = convertSingleAlternative(child, symbolTable)
        if (convertedChild is PersesTokenSetAst ||
          convertedChild is PersesAlternativeBlockAst
        ) {
          // Inline the alternative block.
          var j = 0
          val size = convertedChild.childCount
          while (j < size) {
            builder.add(convertedChild.getChild(j))
            ++j
          }
        } else {
          builder.add(convertedChild)
        }
      }
      val alternatives = builder.build()
      check(alternatives.size > 0) { alternatives }
      return SmartAstConstructor.createForAlternatives(alternatives)
    }

    private fun convertSingleAlternative(
      ast: AltAST,
      symbolTable: SymbolTable,
    ): AbstractPersesRuleElement {
      val astTokenType = ast.getToken().type
      require(astTokenType == ANTLRParser.LEXER_ALT_ACTION || astTokenType == ANTLRParser.ALT)

      val altAst = if (astTokenType == ANTLRParser.LEXER_ALT_ACTION) {
        require(ast.childCount == 2)
        val child = ast.getChild(0) as GrammarAST
        check(
          child is AltAST && child.getToken().type == ANTLRParser.ALT,
        )
        child
      } else {
        ast
      }
      val children = ArrayList<AbstractPersesRuleElement>()
      val childCount = altAst.childCount
      for (i in 0 until childCount) {
        val convertedChild = dispatchConversion(altAst.getChild(i) as GrammarAST, symbolTable)
        children.add(convertedChild)
      }
      return combineIntoSequence(children)
    }

    @JvmStatic
    fun combineIntoSequence(
      children: List<AbstractPersesRuleElement>,
    ): AbstractPersesRuleElement {
      if (children.size == 1) {
        return children[0]
      }
      val builder = ImmutableList.builder<AbstractPersesRuleElement>()
      for (child in children) {
        val tag = child.tag
        if (tag == AstTag.EPSILON) {
          continue
        }
        if (tag == AstTag.SEQUENCE) {
          child.foreachChildRuleElement { e: AbstractPersesRuleElement -> builder.add(e) }
        } else {
          builder.add(child)
        }
      }
      val processedChildren = builder.build()
      check(processedChildren.size > 0)
      return SmartAstConstructor.createForSequence(processedChildren)
    }

    @VisibleForTesting
    fun convertRuleRefAst(
      ruleRefAst: RuleRefAST,
      symbolTable: SymbolTable,
    ): PersesRuleReferenceAst {
      val ruleNameHandle = symbolTable.ruleNameRegistry.getOrCreate(ruleRefAst.getToken().text)
      val arguments: PersesActionAst?
      if (ruleRefAst.childCount == 1) {
        val args = ruleRefAst.getChild(0) as GrammarAST
        arguments = dispatchConversion(args, symbolTable) as PersesActionAst
      } else {
        arguments = null
        check(ruleRefAst.childCount == 0)
      }
      return PersesRuleReferenceAst.createWithArgs(ruleNameHandle, arguments)
    }

    fun convertOptionalBlockAst(
      ast: OptionalBlockAST,
      symbolTable: SymbolTable,
    ): PersesOptionalAst {
      val body = checkAndConvertBodyOfQuantifiedBlock(ast, symbolTable)
      return if (ast.isGreedy) {
        PersesOptionalAst.createGreedy(body)
      } else {
        PersesOptionalAst.createNonGreedy(body)
      }
    }

    fun convertStarBlockAst(ast: StarBlockAST, symbolTable: SymbolTable): PersesStarAst {
      val body = checkAndConvertBodyOfQuantifiedBlock(ast, symbolTable)
      return if (ast.isGreedy) {
        PersesStarAst.createGreedy(body)
      } else {
        PersesStarAst.createNonGreedy(body)
      }
    }

    fun convertPlusBlockAst(ast: PlusBlockAST, symbolTable: SymbolTable): PersesPlusAst {
      val body = checkAndConvertBodyOfQuantifiedBlock(ast, symbolTable)
      return if (ast.isGreedy) {
        PersesPlusAst.createGreedy(body)
      } else {
        PersesPlusAst.createNonGreedy(body)
      }
    }

    private fun checkAndConvertBodyOfQuantifiedBlock(
      ast: GrammarAST,
      symbolTable: SymbolTable,
    ): AbstractPersesRuleElement {
      require(ast.childCount == 1)
      require(ast.getChild(0) is BlockAST)
      val block = ast.getChild(0) as BlockAST
      return dispatchConversion(block, symbolTable)
    }

    private fun convertTerminalSetAst(ast: GrammarAST): AbstractPersesRuleElement {
      require(isTerminalSetAst(ast)) { "Unhandled ast: $ast, ${ast::class.java}" }
      require(ast.getToken().text == "SET")
      val builder = ImmutableList.builder<AbstractPersesTerminalAst>()
      val childCount = ast.childCount
      for (i in 0 until childCount) {
        val child = ast.getChild(i) as GrammarAST
        if (child is TerminalAST) {
          builder.add(convertTerminalAst(child))
        } else if (PersesLexerCharSet.isLexerCharSet(child)) {
          builder.add(PersesLexerCharSet(child.text))
        } else {
          throw RuntimeException("Unreachable. $child")
        }
      }
      val terminals = builder.build()
      check(terminals.size > 0)
      return if (terminals.size == 1) {
        terminals[0]
      } else {
        PersesTokenSetAst(terminals)
      }
    }

    private fun convertNotAst(notAST: NotAST, symbolTable: SymbolTable): PersesNotAst {
      require(notAST.childCount == 1)
      val child = notAST.getChild(0) as GrammarAST
      val childAst = child
      require(isTerminalSetAst(childAst))
      val tokens = dispatchConversion(childAst, symbolTable)
      return PersesNotAst(tokens)
    }

    @VisibleForTesting
    fun dispatchConversion(ast: GrammarAST, symbolTable: SymbolTable): AbstractPersesRuleElement {
      return when {
        ast is TerminalAST -> convertTerminalAst(ast)
        ast is RuleRefAST -> convertRuleRefAst(ast, symbolTable)
        ast is OptionalBlockAST -> convertOptionalBlockAst(ast, symbolTable)
        ast is PlusBlockAST -> convertPlusBlockAst(ast, symbolTable)
        ast is StarBlockAST -> convertStarBlockAst(ast, symbolTable)
        ast is BlockAST -> convertAlternativeBlock(ast, symbolTable)
        ast is RangeAST -> convertRangeAST(ast)
        ast is ActionAST -> PersesActionAst(ast.text)
        isTerminalSetAst(ast) -> convertTerminalSetAst(ast)
        ast is NotAST -> convertNotAst(ast, symbolTable)
        PersesEpsilonAst.isEpsilonAst(ast) -> PersesEpsilonAst()
        PersesLexerCharSet.isLexerCharSet(ast) -> PersesLexerCharSet(ast.text)
        PersesRuleElementOption.isRuleElementOption(ast) -> convertRuleElementOption(ast)
        PersesRuleElementLabel.isRuleElementLabel(ast) -> convertRuleElementLabel(ast, symbolTable)
        else -> error("Unhandled ast: " + ast.text + ", " + ast.javaClass)
      }
    }

    private fun convertRuleElementLabel(
      ast: GrammarAST,
      symbolTable: SymbolTable,
    ): PersesRuleElementLabel {
      require(PersesRuleElementLabel.isRuleElementLabel(ast))
      val operator = ast.getToken().text
      require(operator == "=" || operator == "+=")
      val childCount = ast.childCount
      check(childCount == 2)
      val left = ast.getChild(0) as GrammarAST
      check(left.getToken().type == ANTLRParser.ID)
      val label = left.text
      val right = ast.getChild(1) as GrammarAST
      val child = dispatchConversion(right, symbolTable)
      return PersesRuleElementLabel(label, operator, child)
    }

    private fun convertRuleElementOption(ast: GrammarAST): PersesRuleElementOption {
      require(PersesRuleElementOption.isRuleElementOption(ast))
      require(ast.childCount == 1)
      val child = ast.getChild(0) as GrammarAST
      check(child.text == "=")
      check(child.childCount == 2)
      val left = child.getChild(0) as GrammarAST
      val right = child.getChild(1) as GrammarAST
      check(left.childCount == 0)
      check(right.childCount == 0)
      val key = left.text
      val value = right.text
      check(key == "assoc") { "The key is $key" }
      check(value == "left" || value == "right")
      return PersesRuleElementOption(key, value)
    }

    private fun convertTerminalAst(terminal: TerminalAST): PersesTerminalAst {
      return PersesTerminalAst(terminal.text, terminal.getToken().type)
    }

    private fun convertRangeAST(ast: RangeAST): AbstractPersesRuleElement {
      require(ast.childCount == 2)
      val first = ast.getChild(0) as GrammarAST
      val second = ast.getChild(1) as GrammarAST
      check(first is TerminalAST)
      check(second is TerminalAST)
      return PersesRangeAst(
        convertTerminalAst(first),
        convertTerminalAst(second),
      )
    }

    private fun isTerminalSetAst(ast: GrammarAST): Boolean {
      if (ast is SetAST) {
        return true
      }
      return ast.getToken().type == ANTLRParser.SET
    }

    private fun collectChildNodeClasses(ast: BlockAST): LinkedHashSet<Class<*>> {
      val childNodeClasses = LinkedHashSet<Class<*>>()
      val childCount = ast.childCount
      for (i in 0 until childCount) {
        childNodeClasses.add(ast.getChild(i).javaClass)
      }
      return childNodeClasses
    }
  }
}
