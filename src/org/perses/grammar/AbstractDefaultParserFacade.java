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

import com.google.common.collect.ImmutableList;
import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.DefaultErrorStrategy;
import org.antlr.v4.runtime.InputMismatchException;
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.Parser;
import org.antlr.v4.runtime.RecognitionException;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.atn.LexerATNSimulator;
import org.antlr.v4.runtime.atn.ParserATNSimulator;
import org.antlr.v4.runtime.atn.PredictionContextCache;
import org.antlr.v4.runtime.atn.PredictionMode;
import org.antlr.v4.runtime.misc.IntervalSet;
import org.antlr.v4.runtime.tree.ParseTree;
import org.perses.antlr.AbstractAntlrGrammar;
import org.perses.antlr.ParseTreeWithParser;
import org.perses.program.TokenizedProgram;

import java.io.IOException;
import java.io.Reader;
import java.util.function.Function;

/**
 * taken from stackoverflow: https://stackoverflow.com/questions/18132078/handling-errors-in-antlr4
 */
class ExceptionErrorStrategy extends DefaultErrorStrategy {
  @Override
  public void recover(Parser recognizer, RecognitionException e) {
    throw e;
  }

  @Override
  public void reportInputMismatch(Parser recognizer, InputMismatchException e)
      throws RecognitionException {
    String msg = "mismatched input " + getTokenErrorDisplay(e.getOffendingToken());
    msg += " expecting one of " + e.getExpectedTokens().toString(recognizer.getTokenNames());
    RecognitionException ex =
        new RecognitionException(
            msg, recognizer, recognizer.getInputStream(), recognizer.getContext());
    ex.initCause(e);
    throw ex;
  }

  @Override
  public void reportMissingToken(Parser recognizer) {
    beginErrorCondition(recognizer);
    Token t = recognizer.getCurrentToken();
    IntervalSet expecting = getExpectedTokens(recognizer);
    String msg =
        "missing "
            + expecting.toString(recognizer.getTokenNames())
            + " at "
            + getTokenErrorDisplay(t);
    throw new RecognitionException(
        msg, recognizer, recognizer.getInputStream(), recognizer.getContext());
  }
}
/** */
public abstract class AbstractDefaultParserFacade<LEXER extends Lexer, PARSER extends Parser>
    extends AbstractParserFacade {

  private static final boolean DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY =
      true;

  protected AbstractDefaultParserFacade(AbstractAntlrGrammar grammar) {
    super(grammar);
  }

  protected abstract LEXER createLexer(ANTLRInputStream inputStream);

  protected LEXER createLexerWithoutCache(ANTLRInputStream inputStream) {
    final LEXER lexer = createLexer(inputStream);
    if (DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY) {
      lexer.setInterpreter(
          new LexerATNSimulator(
              lexer,
              lexer.getATN(),
              lexer.getInterpreter().decisionToDFA,
              new PredictionContextCache()));
    }
    return lexer;
  }

  protected abstract PARSER createParser(CommonTokenStream tokens);

  protected PARSER createParserWithoutCache(CommonTokenStream tokens) {
    final PARSER parser = createParser(tokens);
    if (DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY) {
      // The following code is from.
      // https://github.com/antlr/antlr4/issues/499#issuecomment-38159752
      parser.setInterpreter(
          new ParserATNSimulator(
              parser,
              parser.getATN(),
              parser.getInterpreter().decisionToDFA,
              new PredictionContextCache()));
      parser.getInterpreter().setPredictionMode(PredictionMode.LL);
    }
    return parser;
  }

  protected abstract ParseTree startParsing(PARSER parser);

  protected final ParseTreeWithParser parseReader(String fileName, Reader reader)
      throws IOException {
    return parseReader(
        fileName,
        reader,
        this::createLexerWithoutCache,
        this::createParserWithoutCache,
        this::startParsing);
  }

  @Override
  protected ImmutableList<Token> tokenize(String fileName, Reader reader) throws IOException {
    final Lexer lexer = createLexerWithoutCache(new ANTLRInputStream(reader));
    return ImmutableList.copyOf(lexer.getAllTokens());
  }

  public final ParseTreeWithParser parseTokenizedProgram(TokenizedProgram program) {
    final CommonTokenStream tokens = new CommonTokenStream(program.createTokenSource());
    final PARSER parser = createParserWithoutCache(tokens);
    parser.removeErrorListeners();
    parser.setErrorHandler(new ExceptionErrorStrategy());
    parser.addErrorListener(new FailOnErrorAntlrErrorListener("<from tokenized program>"));
    final ParseTree tree = startParsing(parser);

    parser.getInterpreter().reset();
    parser.getInterpreter().clearDFA();

    return new ParseTreeWithParser(tree, parser);
  }

  protected static <L extends Lexer, P extends Parser> ParseTreeWithParser parseReader(
      String fileName,
      Reader reader,
      Function<ANTLRInputStream, L> lexerCreator,
      Function<CommonTokenStream, P> parserCreator,
      Function<P, ParseTree> parseFunction)
      throws IOException {
    final FailOnErrorAntlrErrorListener listener = new FailOnErrorAntlrErrorListener(fileName);
    final L lexer = lexerCreator.apply(new ANTLRInputStream(reader));
    lexer.removeErrorListeners();
    lexer.addErrorListener(listener);
    final CommonTokenStream tokens = new CommonTokenStream(lexer);
    final P parser = parserCreator.apply(tokens);
    if (DISABLE_GLOBAL_CACHING_FOR_BETTER_MEMORY_THO_AFFECT_EFFICIENCY) {
      parser.setInterpreter(
          new ParserATNSimulator(
              parser,
              parser.getATN(),
              parser.getInterpreter().decisionToDFA,
              new PredictionContextCache()));
    }
    parser.removeErrorListeners();
    parser.setErrorHandler(new DefaultErrorStrategy());
    parser.addErrorListener(listener);
    final ParseTree tree = parseFunction.apply(parser);

    lexer.getInterpreter().clearDFA();
    lexer.getInterpreter().reset();
    parser.getInterpreter().clearDFA();
    parser.getInterpreter().reset();

    return new ParseTreeWithParser(tree, parser);
  }
}
