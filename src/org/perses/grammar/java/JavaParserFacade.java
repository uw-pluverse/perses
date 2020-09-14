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
package org.perses.grammar.java;

import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTree;
import org.perses.antlr.ParseTreeWithParser;
import org.perses.grammar.AbstractDefaultParserFacade;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

/** This is the facade for Java parsers */
public class JavaParserFacade extends AbstractDefaultParserFacade<OptJava8Lexer, OptJava8Parser> {

  public JavaParserFacade() {
    super(LanguageJava.INSTANCE, createCombinedAntlrGrammar("OptJava8.g4", JavaParserFacade.class));
  }

  @Override
  protected OptJava8Lexer createLexer(ANTLRInputStream inputStream) {
    return new OptJava8Lexer(inputStream);
  }

  @Override
  protected OptJava8Parser createParser(CommonTokenStream tokens) {
    return new OptJava8Parser(tokens);
  }

  @Override
  protected ParseTree startParsing(OptJava8Parser parser) {
    return parser.compilationUnit();
  }

  public ParseTreeWithParser parseFileWithOrigJavaParser(File file) throws IOException {
    try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
      return parseReader(
          file.getPath(),
          reader,
          antlrInputStream -> new OrigJava8Lexer(antlrInputStream),
          commonTokenStream -> new OrigJava8Parser(commonTokenStream),
          OrigJava8Parser::compilationUnit);
    }
  }
}
