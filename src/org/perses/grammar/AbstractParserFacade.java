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
package org.perses.grammar;

import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import com.google.common.flogger.FluentLogger;
import com.google.common.io.ByteStreams;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.tree.ParseTree;
import org.antlr.v4.runtime.tree.TerminalNode;
import org.perses.antlr.AbstractAntlrGrammar;
import org.perses.antlr.AbstractAntlrGrammar.CombinedAntlrGrammar;
import org.perses.antlr.AbstractAntlrGrammar.SeparateAntlrGrammar;
import org.perses.antlr.GrammarHierarchy;
import org.perses.antlr.ParseTreeWithParser;
import org.perses.antlr.ast.PersesAstBuilder;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.program.TokenizedProgram;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayDeque;

/** The base class for parser faceds */
public abstract class AbstractParserFacade {

  private final AbstractAntlrGrammar grammar;
  private final GrammarHierarchy hierarchy;

  protected AbstractParserFacade(AbstractAntlrGrammar grammar) {
    this.grammar = grammar;
    hierarchy = GrammarHierarchy.createFromAntlrGrammar(grammar);
  }

  public final AbstractAntlrGrammar getAntlrGrammar() {
    return grammar;
  }

  /** Parse the given file into a ParseTree. */
  public final ParseTreeWithParser parseFile(File file) throws IOException {
    try (BufferedReader reader = Files.newBufferedReader(file.toPath(), StandardCharsets.UTF_8)) {
      return parseReader(file.getPath(), reader);
    }
  }

  public final ImmutableList<Token> parseIntoTokens(File file) throws IOException {
    try (BufferedReader reader = Files.newBufferedReader(file.toPath(), StandardCharsets.UTF_8)) {
      return tokenize(file.getPath(), reader);
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
    return parseString(string, "<in memory>");
  }

  /**
   * Parse the given string into a ParseTree
   *
   * <p>TODO: parse with the given token list of the tokenized program.
   */
  public final ParseTreeWithParser parseString(String string, String filename) throws IOException {
    final StringReader reader = new StringReader(string);
    return parseReader(filename, reader);
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

  @Deprecated
  public final boolean isSourceCodeParsable(TokenizedProgram program) {
    try {
      // FIXME: bug here, as go program cannot use tokenized program for parsing.
      parseTokenizedProgram(program);
      return true;
    } catch (Exception e) {
      logger.atFine().withCause(e).log("The input source is not parsable.");
      return false;
    }
  }

  @Deprecated
  public abstract ParseTreeWithParser parseTokenizedProgram(TokenizedProgram program);

  public static String readAntlrGrammarContent(
      String antlrGrammarFileName, Class<?> classUnderSamePkg) throws IOException {
    try (InputStream stream =
        openStreamOfParserAntlrGrammar(antlrGrammarFileName, classUnderSamePkg)) {
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
  protected static InputStream openStreamOfParserAntlrGrammar(
      String antlrGrammarFileName, Class<?> classUnderSamePkg) {
    final String grammarFileName =
        '/'
            + classUnderSamePkg.getPackage().getName().replace('.', '/')
            + '/'
            + antlrGrammarFileName;
    InputStream result = classUnderSamePkg.getResourceAsStream(grammarFileName);
    return Preconditions.checkNotNull(result, "Failed to open stream to %s", grammarFileName);
  }

  protected static SeparateAntlrGrammar createSeparateAntlrGrammar(
      String antlrParserGrammarFileName,
      String antlrLexerGrammarFileName,
      Class<?> classUnderSamePkg) {
    try {
      final PersesGrammar persesGrammar =
          PersesAstBuilder.loadGrammarFromString(
              readAntlrGrammarContent(antlrParserGrammarFileName, classUnderSamePkg));
      final PersesGrammar lexerGrammar =
          PersesAstBuilder.loadGrammarFromString(
              readAntlrGrammarContent(antlrLexerGrammarFileName, classUnderSamePkg));

      return new SeparateAntlrGrammar(persesGrammar, lexerGrammar);
    } catch (IOException e) {
      throw new UncheckedIOException(e);
    }
  }

  protected static CombinedAntlrGrammar createCombinedAntlrGrammar(
      String antlrGrammarFileName, Class<?> classUnderSamePkg) {
    try {
      final String content = readAntlrGrammarContent(antlrGrammarFileName, classUnderSamePkg);
      final PersesGrammar persesGrammar = PersesAstBuilder.loadGrammarFromString(content);
      return new CombinedAntlrGrammar(persesGrammar);
    } catch (IOException e) {
      throw new UncheckedIOException(e);
    }
  }

  protected abstract ParseTreeWithParser parseReader(String fileName, Reader reader)
      throws IOException;

  protected abstract ImmutableList<Token> tokenize(String fileName, Reader reader)
      throws IOException;

  private static final FluentLogger logger = FluentLogger.forEnclosingClass();
}
