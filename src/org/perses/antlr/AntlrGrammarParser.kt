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

import com.google.common.base.Charsets
import com.google.common.base.Preconditions
import com.google.common.io.CharStreams
import org.antlr.runtime.ANTLRStringStream
import org.antlr.runtime.CharStream
import org.antlr.runtime.CommonTokenStream
import org.antlr.runtime.ParserRuleReturnScope
import org.antlr.v4.Tool
import org.antlr.v4.parse.ANTLRLexer
import org.antlr.v4.parse.ANTLRParser
import org.antlr.v4.parse.GrammarASTAdaptor
import org.antlr.v4.tool.Grammar
import org.antlr.v4.tool.ast.GrammarAST
import org.antlr.v4.tool.ast.GrammarRootAST
import java.io.IOException
import java.io.InputStream
import java.io.InputStreamReader
import java.nio.file.Path

/** A parser for grammars written in Antlr. It parses a grammar file into an AST.  */
class AntlrGrammarParser : Tool() {

  fun loadGrammarFromString(string: String?): Grammar {
    val grammarRootAST = parse("<empty>", ANTLRStringStream(string))
    return createGrammarFromRootAst(grammarRootAST)
  }

  fun loadGrammarFromInputStream(inputStream: InputStream?): Grammar {
    val grammarRootAST = parse(
      "<empty>",
      ANTLRStringStream(
        CharStreams.toString(InputStreamReader(inputStream, Charsets.UTF_8)),
      ),
    )
    return createGrammarFromRootAst(grammarRootAST)
  }

  private fun createGrammarFromRootAst(grammarRootAST: GrammarRootAST): Grammar {
    val g = createGrammar(grammarRootAST)
    g.fileName = "<empty>"
    process(g, false)
    return g
  }

  companion object {
    fun loadAntlrGrammarFromFile(file: Path): Grammar {
      return AntlrGrammarParser().loadGrammar(file.toAbsolutePath().toString())
    }

    @Throws(IOException::class)
    fun loadAntlrGrammarFromInputStream(inputStream: InputStream?): Grammar {
      return AntlrGrammarParser().loadGrammarFromInputStream(inputStream)
    }

    fun loadAntlrGrammarFromString(content: String?): Grammar {
      return AntlrGrammarParser().loadGrammarFromString(content)
    }

    fun parseRawGrammarASTFromString(grammar: String?): GrammarRootAST {
      return parseRawGrammarAST(ANTLRStringStream(grammar))
    }

    fun parseRawGrammarAST(grammar: InputStream?): GrammarRootAST {
      return parseRawGrammarAST(
        ANTLRStringStream(
          CharStreams.toString(InputStreamReader(grammar, Charsets.UTF_8)),
        ),
      )
    }

    fun parseRawGrammarAST(`in`: CharStream?): GrammarRootAST {
      val adaptor = GrammarASTAdaptor(`in`)
      val lexer = ANTLRLexer(`in`)
      val tokens = CommonTokenStream(lexer)
      lexer.tokens = tokens
      val p = ANTLRParser(tokens)
      p.treeAdaptor = adaptor
      val r: ParserRuleReturnScope
      r = try {
        p.grammarSpec()
      } catch (e: Exception) {
        throw RuntimeException("Fail to parse the char stream.", e)
      }
      val root = r.tree as GrammarAST
      if (root is GrammarRootAST) {
        val grammarRootAST = root
        grammarRootAST.hasErrors = lexer.numberOfSyntaxErrors > 0 || p.numberOfSyntaxErrors > 0
        Preconditions.checkState(grammarRootAST.tokenStream === tokens)
        return grammarRootAST
      }
      throw AssertionError("Cannot reach here. The root is $root")
    }
  }
}
