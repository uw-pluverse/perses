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
package org.perses.antlr

import com.google.common.base.Strings
import com.google.common.collect.ImmutableList
import org.antlr.v4.runtime.Lexer
import org.antlr.v4.runtime.Token
import org.antlr.v4.runtime.atn.ATN
import org.antlr.v4.runtime.tree.ParseTree
import org.antlr.v4.runtime.tree.TerminalNode
import org.antlr.v4.tool.Grammar
import org.antlr.v4.tool.ast.GrammarAST
import org.perses.program.LanguageKind
import org.perses.program.TokenizedProgram
import org.perses.util.SimpleStack
import org.perses.util.Util
import java.io.IOException
import java.io.StringWriter
import java.io.Writer

/** Utility class to process Antlr grammars.  */
object AntlrGrammarUtil {
  fun countLeafTokens(tree: ParseTree): Int {
    var count = 0
    val stack = SimpleStack<ParseTree>()
    stack.add(tree)
    while (stack.isNotEmpty()) {
      val node = stack.remove()
      if (node is TerminalNode) {
        if (node.symbol.type != Token.EOF) {
          count++
        }
      } else {
        val childCount = node.getChildCount()
        for (i in 0 until childCount) {
          stack.add(node.getChild(i))
        }
      }
    }
    return count
  }

  fun <T : Lexer> getAtnFromLexer(lexerClass: Class<T>): ATN? {
    val field =
      lexerClass.fields.singleOrNull { it.name == FIELD_NAME_OF_ATN }
        ?: return null
    return field.get(null) as ATN
  }

  private const val FIELD_NAME_OF_ATN = "_ATN"

  /**
   * Feeds every token [lexer] produces on the default channel (EOF excluded) to [action], one at
   * a time, without retaining any of them. The streaming building block of
   * [countTokensInDefaultChannel] and [readAllTokensInDefaultChannel].
   */
  inline fun forEachTokenInDefaultChannel(
    lexer: Lexer,
    action: (Token) -> Unit,
  ) {
    var token: Token = lexer.nextToken()
    while (token.type != Token.EOF) {
      if (token.channel == Token.DEFAULT_CHANNEL) {
        action(token)
      }
      token = lexer.nextToken()
    }
  }

  /**
   * Counts the tokens [lexer] produces on the default channel (EOF excluded) without retaining
   * them. This is the list-free counterpart of [readAllTokensInDefaultChannel].
   */
  fun countTokensInDefaultChannel(lexer: Lexer): Int {
    var count = 0
    forEachTokenInDefaultChannel(lexer) { ++count }
    return count
  }

  fun readAllTokensInDefaultChannel(lexer: Lexer): ImmutableList<Token> {
    val builder = ImmutableList.builder<Token>()
    forEachTokenInDefaultChannel(lexer) { builder.add(it) }
    return builder.build().also { tokens ->
      Util.lazyAssert(
        test = {
          if (tokens.isEmpty()) {
            return@lazyAssert true
          }
          val distinctChannels = tokens.map { it.channel }.distinct()
          distinctChannels.size == 1 && distinctChannels.single() == Token.DEFAULT_CHANNEL
        },
        message = { tokens.joinToString(separator = "\n") },
      )
    }
  }

  fun printAstTree(grammar: Grammar) {
    printAstTree(grammar.ast)
  }

  /** Print the AST structure of the given grammar.  */
  fun printAstTree(ast: GrammarAST) {
    println(ast.toTokenString())
    printAstTree(ast, 0)
  }

  private fun printAstTree(
    ast: GrammarAST,
    indent: Int,
  ) {
    print(Strings.padStart("", indent, ' '))
    println(ast.javaClass.simpleName + ": " + ast.toString())
    for (i in 0 until ast.childCount) {
      printAstTree(ast.getChild(i) as GrammarAST, indent + 4)
    }
  }

  /** TODO: can be optimized by converting to an iterative algorithm.  */
  fun convertParseTreeToProgram(
    root: ParseTree,
    languageKind: LanguageKind,
  ): TokenizedProgram {
    val builder = ImmutableList.builder<Token>()
    convertParseTreeToProgram(root, builder)
    val tokens = builder.build()
    return TokenizedProgram.createForFreshAntlrLexemes(tokens)
  }

  private fun convertParseTreeToProgram(
    node: ParseTree,
    builder: ImmutableList.Builder<Token>,
  ) {
    if (node is TerminalNode) {
      val symbol = node.symbol
      // EOF is not a source token. It only appears when the start rule anchors to EOF (e.g. the C
      // facade's compilationUnit); SparTreeBuilder skips it for the same reason.
      if (symbol.type != Token.EOF) {
        builder.add(symbol)
      }
      return
    }
    val childCount = node.childCount
    for (i in 0 until childCount) {
      convertParseTreeToProgram(node.getChild(i), builder)
    }
  }

  fun printParseTree(root: ParseTree): String {
    val writer = StringWriter()
    try {
      printParseTree(root, writer)
    } catch (e: IOException) {
      throw AssertionError(e)
    }
    writer.flush()
    return writer.toString()
  }

  fun printParseTree(
    root: ParseTree,
    writer: Writer,
  ) {
    writer.append(getLabel(root)).append('\n')
    printParseTree(root, writer, ArrayList())
  }

  private fun getLabel(tree: ParseTree): String {
    val className = tree.javaClass.simpleName
    return if (tree is TerminalNode) {
      className + ": " + tree.getText()
    } else {
      className
    }
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

  private fun printParseTree(
    root: ParseTree,
    writer: Writer,
    prefix: ArrayList<String>,
  ) {
    val childCount = root.childCount
    if (childCount == 0) {
      return
    }
    for (i in 0 until childCount) {
      outputPrefix(writer, prefix, "|---")
      prefix.add(if (i == childCount - 1) "    " else "|   ")
      val child = root.getChild(i)
      writer.append(getLabel(child)).append('\n')
      printParseTree(child, writer, prefix)
      prefix.removeAt(prefix.size - 1)
    }
  }
}
