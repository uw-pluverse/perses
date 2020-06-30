/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.TerminalNode;
import org.antlr.v4.tool.Grammar;
import org.antlr.v4.tool.ast.*;
import org.perses.program.TokenizedProgram;
import org.perses.program.TokenizedProgramFactory;

import java.io.IOException;
import java.io.StringWriter;
import java.io.Writer;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.function.Function;

import static com.google.common.base.Preconditions.checkState;

/** Utility class to process Antlr grammars. */
public final class AntlrGrammarUtil {

  private static final int INDENT_STEP = 4;

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

  /**
   * Pre-order traversal of an Antlr grammar AST.
   *
   * @param visitor: processes a node, and returns a boolean to indicate whether to process its
   *     children.
   */
  public static void preOrderVisitAntlrGrammarAST(
      GrammarRootAST ast, Function<GrammarAST, Boolean> visitor) {
    final ArrayDeque<GrammarAST> stack = new ArrayDeque<>();
    stack.add(ast);
    while (stack.size() > 0) {
      final GrammarAST node = stack.pop();
      final boolean proceed = visitor.apply(node);
      if (!proceed) {
        continue;
      }
      final int childCount = node.getChildCount();
      for (int i = childCount - 1; i >= 0; --i) {
        stack.push((GrammarAST) node.getChild(i));
      }
    }
  }

  public static ImmutableList<RuleAST> getLexerAndParserRuleASTList(GrammarRootAST grammar) {
    assert grammar != null;
    ImmutableList.Builder<RuleAST> builder = ImmutableList.builder();
    preOrderVisitAntlrGrammarAST(
        grammar,
        node -> {
          if (node instanceof RuleAST) {
            builder.add(((RuleAST) node));
            return false;
          } else {
            return true;
          }
        });
    return builder.build();
  }

  public static ImmutableList<String> getParserRuleNameList(GrammarRootAST grammar) {
    assert grammar != null;
    ImmutableList.Builder<String> builder = ImmutableList.builder();
    preOrderVisitAntlrGrammarAST(
        grammar,
        node -> {
          if (node instanceof RuleAST) {
            RuleAST ruleAST = (RuleAST) node;
            if (ruleAST.isLexerRule()) {
              return false;
            } else {
              builder.add(ruleAST.getChild(0).toString());
              return false;
            }
          } else {
            return true;
          }
        });
    return builder.build();
  }

  /**
   * Verify whether the given Antlr grammar has the Spar-tree properties, that is,
   * <li>The name of the parent rule of '?' starts with "optiona__"
   * <li>The name of the parent rule of '*' starts with "kleene_star__"
   * <li>The name of the parent rule of '+' starts with 'kleene_plus__"
   * <li>The children of any '?', '*' or '+' must be of size 1
   */
  public static void verifySparTreeProperties(GrammarRootAST ast) {
    preOrderVisitAntlrGrammarAST(
        ast,
        node -> {
          final int childCount = node.getChildCount();

          if (node instanceof OptionalBlockAST
              || node instanceof StarBlockAST
              || node instanceof PlusBlockAST) {
            checkState(node.getParent() instanceof AltAST);
            checkState(node.getParent().getParent() instanceof BlockAST);
            checkState(
                node.getParent().getParent().getParent() instanceof RuleAST,
                "%s",
                node.getParent().getParent().getParent().toStringTree());
            final RuleAST rule = (RuleAST) node.getParent().getParent().getParent();
            final String ruleName = rule.getChild(0).toString();
            checkState(
                !(node instanceof OptionalBlockAST) || RuleType.isOptional(ruleName),
                "%s",
                ruleName);
            checkState(
                !(node instanceof StarBlockAST) || RuleType.isKleeneStar(ruleName),
                "%s: %s",
                ruleName,
                rule.toStringTree());
            checkState(
                !(node instanceof PlusBlockAST) || RuleType.isKleenePlus(ruleName), "%s", ruleName);
            checkState(childCount == 1);
          }
          if (isLexerRule(node)) {
            return false;
          }
          return true;
        });
  }

  public static boolean isLexerRule(GrammarAST node) {
    return node instanceof RuleAST && ((RuleAST) node).isLexerRule();
  }

  private static GrammarAST getParentRule(OptionalBlockAST ast) {
    checkState(ast.getParent() instanceof AltAST);
    final AltAST parent = (AltAST) ast.getParent();
    checkState(parent.getParent() instanceof BlockAST);
    return null;
  }

  /** TODO: can be optimzied by converting to an iterative algorithm. */
  public static TokenizedProgram convertParseTreeToProgram(ParseTree root) {
    final ImmutableList.Builder<Token> builder = ImmutableList.builder();
    convertParseTreeToProgram(root, builder);
    final ImmutableList<Token> tokens = builder.build();
    return TokenizedProgramFactory.createFactory(tokens).create(tokens);
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
