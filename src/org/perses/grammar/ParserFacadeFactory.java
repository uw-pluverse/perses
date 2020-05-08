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

import org.perses.program.LanguageKind;
import org.perses.grammar.c.CParserFacade;
import org.perses.grammar.c.PnfCParserFacade;
import org.perses.grammar.go.PnfGoParserFacade;
import org.perses.grammar.java.JavaParserFacade;
import org.perses.grammar.scala.PnfScalaParserFacade;
import org.perses.grammar.rust.PnfRustParserFacade;

/** Creates a parser facade, based on the type of language kind. */
public final class ParserFacadeFactory {

  public static ParserFacadeFactory createForPnfC() {
    return new ParserFacadeFactory(false);
  }

  public static ParserFacadeFactory createForOptC() {
    return new ParserFacadeFactory(true);
  }

  private final boolean useOptCParser;

  private ParserFacadeFactory(boolean useOptCParser) {
    this.useOptCParser = useOptCParser;
  }

  public AbstractParserFacade createParserFacade(LanguageKind languageKind) {
    switch (languageKind) {
      case C:
        return useOptCParser ? new CParserFacade() : new PnfCParserFacade();
      case JAVA:
        return new JavaParserFacade();
      case GO:
        return new PnfGoParserFacade();
      case SCALA:
        return new PnfScalaParserFacade();
      case RUST:
        return new PnfRustParserFacade();
      default:
        throw new RuntimeException("The language " + languageKind + " is not supported.");
    }
  }
}
