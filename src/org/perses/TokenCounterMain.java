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
package org.perses;

import com.google.common.collect.ImmutableList;
import org.antlr.v4.runtime.Token;
import org.perses.antlr.ParseTreeWithParser;
import org.perses.grammar.AbstractParserFacade;
import org.perses.grammar.ParserFacadeFactory;
import org.perses.program.SourceFile;

import java.io.File;
import java.io.IOException;

import static com.google.common.base.Preconditions.checkArgument;

public class TokenCounterMain {

  public static void main(String[] args) throws IOException {
    checkArgument(args.length == 1, "Usage: <main> <source file>");
    final File file = new File(args[0]);
    checkArgument(file.exists(), "The source file does not exist. %s", file);
    checkArgument(file.isFile(), "The source file is not a regular file. %s", file);
    final SourceFile sourceFile = new SourceFile(file);
    final AbstractParserFacade parserFacade =
        ParserFacadeFactory.createForPnfC().createParserFacade(sourceFile.getLanguageKind());
    final ImmutableList<Token> tokens = parserFacade.parseIntoTokens(sourceFile.getFile());
    int count = 0;
    for (Token token: tokens) {
      if (token.getChannel() == Token.DEFAULT_CHANNEL) {
        ++count;
      }
    }
    System.out.println();
    System.out.printf("The number of tokens in file '%s' is:\n", file);
    System.out.println(count);
  }
}
