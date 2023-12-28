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
import org.perses.program.TokenizedProgramFactory.Companion.createFactory
import java.io.IOException
import java.io.StringWriter
import java.io.Writer

/** Utility class to process Antlr grammars.  */
object AntlrGrammarUtil {

  fun <T : Lexer> getAtnFromLexer(lexerClass: Class<T>): ATN {
    return lexerClass.getField("_ATN").get(null) as ATN
  }

  fun printAstTree(grammar: Grammar) {
    printAstTree(grammar.ast)
  }

  /** Print the AST structure of the given grammar.  */
  fun printAstTree(ast: GrammarAST) {
    println(ast.toTokenString())
    printAstTree(ast, 0)
  }

  private fun printAstTree(ast: GrammarAST, indent: Int) {
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
    return createFactory(tokens, languageKind).create(tokens)
  }

  private fun convertParseTreeToProgram(
    node: ParseTree,
    builder: ImmutableList.Builder<Token>,
  ) {
    if (node is TerminalNode) {
      val symbol = node.symbol
      builder.add(symbol)
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

  fun printParseTree(root: ParseTree, writer: Writer) {
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

  private fun printParseTree(root: ParseTree, writer: Writer, prefix: ArrayList<String>) {
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
