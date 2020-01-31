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
package org.perses.grammar;

import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import com.google.common.flogger.FluentLogger;
import com.google.common.io.ByteStreams;
import org.antlr.runtime.RecognitionException;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.TerminalNode;
import org.antlr.v4.tool.ast.GrammarRootAST;
import org.perses.antlr.AntlrGrammarParser;
import org.perses.antlr.GrammarHierarchy;
import org.perses.antlr.ParseTreeWithParser;
import org.perses.antlr.ast.PersesAstBuilder;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.program.TokenizedProgram;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayDeque;

/** The base class for parser faceds */
public abstract class AbstractParserFacade {

  private final String antlrGrammarContent;
  private final PersesGrammar persesGrammar;
  private final GrammarHierarchy hierarchy;

  protected AbstractParserFacade(String antlrGrammarFileName) {
    try {
      antlrGrammarContent = readAntlrGrammarContent(antlrGrammarFileName);
      persesGrammar = createPersesGrammar(antlrGrammarContent);
      hierarchy = GrammarHierarchy.createFromPersesGrammar(persesGrammar);
    } catch (IOException | RecognitionException e) {
      logger.atSevere().withCause(e).log(
          "Cannot create facade for grammar %s", antlrGrammarFileName);
      throw new AssertionError(e);
    }
  }

  public final PersesGrammar getPersesGrammar() {
    return persesGrammar;
  }

  public String getAntlrGrammarContent() {
    return antlrGrammarContent;
  }

  private static PersesGrammar createPersesGrammar(String antlrGrammarContent)
      throws RecognitionException {
    GrammarRootAST grammarRootAST =
        AntlrGrammarParser.parseRawGrammarASTFromString(antlrGrammarContent);
    return new PersesAstBuilder().buildFromAntlrRootAst(grammarRootAST);
  }

  /** Parse the given file into a ParseTree. */
  public final ParseTreeWithParser parseFile(File file) throws IOException {
    try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
      return parseReader(file.getPath(), reader);
    }
  }

  public static ImmutableList<Token> getTokens(ParseTree tree) {
    ImmutableList.Builder<Token> builder = ImmutableList.builderWithExpectedSize(500);
    final ArrayDeque<ParseTree> stack = new ArrayDeque<>();
    stack.push(tree);
    while (stack.size() > 0) {
      final ParseTree current = stack.pop();
      if (current instanceof TerminalNode) {
        builder.add(((TerminalNode) current).getSymbol());
        continue;
      }
      for (int i = current.getChildCount() - 1; i >= 0; --i) {
        stack.push(current.getChild(i));
      }
    }
    return builder.build();
  }

  /**
   * Parse the given string into a ParseTree
   *
   * <p>TODO: parse with the given token list of the tokenized program.
   */
  public final ParseTreeWithParser parseString(String string) throws IOException {
    final StringReader reader = new StringReader(string);
    return parseReader("<in memory>", reader);
  }

  /** Return the Antlr rule hierarchy. */
  public final GrammarHierarchy getRuleHierarchy() {
    return hierarchy;
  }

  /**
   * Test whether the {@code sourceCode} is parsable by the parser.
   *
   * <p>FIXME: The performance can be better, if we pass in a token stream.
   */
  public final boolean isSourceCodeParsable(String sourceCode) {
    try {
      parseString(sourceCode);
      return true;
    } catch (Exception e) {
      logger.atFine().withCause(e).log("The input source is not parsable.");
      return false;
    }
  }

  public final boolean isSourceCodeParsable(TokenizedProgram program) {
    try {
      parseTokenizedProgram(program);
      return true;
    } catch (Exception e) {
      logger.atFine().withCause(e).log("The input source is not parsable.");
      return false;
    }
  }

  public abstract ParseTreeWithParser parseTokenizedProgram(TokenizedProgram program);

  public String readAntlrGrammarContent(String antlrGrammarFileName) throws IOException {
    try (InputStream stream = openStreamOfParserAntlrGrammar(antlrGrammarFileName)) {
      return new String(ByteStreams.toByteArray(stream), StandardCharsets.UTF_8);
    }
  }

  /**
   * Open an input stream to the Antlr grammar file.
   *
   * <p>This method assumes that the grammar file is loaded in the same package of the current
   * parser facade.
   *
   * <p>Note that this method has to be an instance method, as we need the concrete parser facade
   * class to open the stream.
   */
  protected final InputStream openStreamOfParserAntlrGrammar(String antlrGrammarFileName) {
    final Class<?> klass = getClass();
    final String grammarFileName =
        '/' + klass.getPackage().getName().replace('.', '/') + '/' + antlrGrammarFileName;
    InputStream result = klass.getResourceAsStream(grammarFileName);
    return Preconditions.checkNotNull(result, "Failed to open stream to %s", grammarFileName);
  }

  protected abstract ParseTreeWithParser parseReader(String fileName, Reader reader)
      throws IOException;

  private static final FluentLogger logger = FluentLogger.forEnclosingClass();
}
