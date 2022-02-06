/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import com.google.common.base.Strings;
import com.google.common.collect.ImmutableList;
import java.io.IOException;
import java.io.StringWriter;
import java.io.Writer;
import java.util.ArrayList;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.TerminalNode;
import org.antlr.v4.tool.Grammar;
import org.antlr.v4.tool.ast.GrammarAST;
import org.perses.program.LanguageKind;
import org.perses.program.TokenizedProgram;
import org.perses.program.TokenizedProgramFactory;

/** Utility class to process Antlr grammars. */
public final class AntlrGrammarUtil {

  /** Make this class a pure utility class. */
  private AntlrGrammarUtil() {}

  public static void printAstTree(Grammar grammar) {
    printAstTree(grammar.ast);
  }

  /** Print the AST structure of the given grammar. */
  public static void printAstTree(GrammarAST ast) {
    System.out.println(ast.toTokenString());
    printAstTree(ast, 0);
  }

  private static void printAstTree(GrammarAST ast, int indent) {
    System.out.print(Strings.padStart("", indent, ' '));
    System.out.println(ast.getClass().getSimpleName() + ": " + ast.toString());
    for (int i = 0; i < ast.getChildCount(); ++i) {
      printAstTree((GrammarAST) ast.getChild(i), indent + 4);
    }
  }

  /** TODO: can be optimzied by converting to an iterative algorithm. */
  public static TokenizedProgram convertParseTreeToProgram(
      ParseTree root, LanguageKind languageKind) {
    final ImmutableList.Builder<Token> builder = ImmutableList.builder();
    convertParseTreeToProgram(root, builder);
    final ImmutableList<Token> tokens = builder.build();
    return TokenizedProgramFactory.createFactory(tokens, languageKind).create(tokens);
  }

  private static void convertParseTreeToProgram(
      ParseTree node, ImmutableList.Builder<Token> builder) {

    if (node instanceof TerminalNode) {
      final Token symbol = ((TerminalNode) node).getSymbol();
      builder.add(symbol);
      return;
    }
    final int childCount = node.getChildCount();
    for (int i = 0; i < childCount; ++i) {
      convertParseTreeToProgram(node.getChild(i), builder);
    }
  }

  public static String printParseTree(ParseTree root) {
    final StringWriter writer = new StringWriter();
    try {
      printParseTree(root, writer);
    } catch (IOException e) {
      throw new AssertionError(e);
    }
    writer.flush();
    return writer.toString();
  }

  public static void printParseTree(ParseTree root, Writer writer) throws IOException {
    writer.append(getLabel(root)).append('\n');
    printParseTree(root, writer, new ArrayList<>());
  }

  private static String getLabel(ParseTree tree) {
    String className = tree.getClass().getSimpleName();
    if (tree instanceof TerminalNode) {
      return className + ": " + tree.getText();
    }
    return className;
  }

  private static Writer outputPrefix(
      Writer writer, ArrayList<String> prefix, String additionalPrefix) throws IOException {
    for (String p : prefix) {
      writer.append(p);
    }
    writer.append(additionalPrefix);
    return writer;
  }

  private static void printParseTree(ParseTree root, Writer writer, ArrayList<String> prefix)
      throws IOException {
    final int childCount = root.getChildCount();
    if (childCount == 0) {
      return;
    }
    for (int i = 0; i < childCount; ++i) {
      outputPrefix(writer, prefix, "|---");
      prefix.add((i == childCount - 1) ? "    " : "|   ");
      final ParseTree child = root.getChild(i);
      writer.append(getLabel(child)).append('\n');
      printParseTree(child, writer, prefix);
      prefix.remove(prefix.size() - 1);
    }
  }
}
