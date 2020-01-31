/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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

package org.perses.antlr;

import com.google.common.base.Charsets;
import com.google.common.base.Preconditions;
import com.google.common.io.CharStreams;
import org.antlr.runtime.*;
import org.antlr.v4.Tool;
import org.antlr.v4.parse.ANTLRLexer;
import org.antlr.v4.parse.ANTLRParser;
import org.antlr.v4.parse.GrammarASTAdaptor;
import org.antlr.v4.tool.Grammar;
import org.antlr.v4.tool.ast.GrammarAST;
import org.antlr.v4.tool.ast.GrammarRootAST;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

/** A parser for grammars written in Antlr. It parses a grammar file into an AST. */
public class AntlrGrammarParser extends Tool {

  public static Grammar loadAntlrGrammarFromFile(File file) {
    return new AntlrGrammarParser().loadGrammar(file.getAbsolutePath());
  }

  public static Grammar loadAntlrGrammarFromInputStream(InputStream inputStream)
      throws IOException {
    return new AntlrGrammarParser().loadGrammarFromInputStream(inputStream);
  }

  public static Grammar loadAntlrGrammarFromString(String content) {
    return new AntlrGrammarParser().loadGrammarFromString(content);
  }

  public static GrammarRootAST parseRawGrammarASTFromString(String grammar)
      throws RecognitionException {
    return parseRawGrammarAST(new ANTLRStringStream(grammar));
  }

  public static GrammarRootAST parseRawGrammarAST(InputStream grammar)
      throws IOException, RecognitionException {
    return parseRawGrammarAST(
        new ANTLRStringStream(
            CharStreams.toString(new InputStreamReader(grammar, Charsets.UTF_8))));
  }

  public static GrammarRootAST parseRawGrammarAST(CharStream in) throws RecognitionException {
    GrammarASTAdaptor adaptor = new GrammarASTAdaptor(in);
    ANTLRLexer lexer = new ANTLRLexer(in);
    CommonTokenStream tokens = new CommonTokenStream(lexer);
    lexer.tokens = tokens;
    ANTLRParser p = new ANTLRParser(tokens);
    p.setTreeAdaptor(adaptor);
    ParserRuleReturnScope r = p.grammarSpec();
    GrammarAST root = (GrammarAST) r.getTree();
    if (root instanceof GrammarRootAST) {
      GrammarRootAST grammarRootAST = (GrammarRootAST) root;
      grammarRootAST.hasErrors =
          lexer.getNumberOfSyntaxErrors() > 0 || p.getNumberOfSyntaxErrors() > 0;
      Preconditions.checkState(grammarRootAST.tokenStream == tokens);
      return grammarRootAST;
    }
    throw new AssertionError("Cannot reach here. The root is " + root);
  }

  public Grammar loadGrammarFromString(String string) {
    GrammarRootAST grammarRootAST = parse("<empty>", new ANTLRStringStream(string));
    return createGrammarFromRootAst(grammarRootAST);
  }

  public Grammar loadGrammarFromInputStream(InputStream inputStream) throws IOException {
    GrammarRootAST grammarRootAST =
        parse(
            "<empty>",
            new ANTLRStringStream(
                CharStreams.toString(new InputStreamReader(inputStream, Charsets.UTF_8))));
    return createGrammarFromRootAst(grammarRootAST);
  }

  private Grammar createGrammarFromRootAst(GrammarRootAST grammarRootAST) {
    final Grammar g = createGrammar(grammarRootAST);
    g.fileName = "<empty>";
    process(g, false);
    return g;
  }
}
