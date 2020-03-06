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

import com.google.common.collect.ImmutableMap;
import org.perses.LanguageKind;
import org.perses.grammar.c.PnfCParserFacade;
import org.perses.grammar.go.PnfGoParserFacade;
import org.perses.grammar.java.JavaParserFacade;

import static com.google.common.base.Preconditions.checkArgument;

/** Creates a parser facade, based on the type of language kind. */
public enum ParserFacadeFactory {
  SINGLETON;

  private static final ImmutableMap<LanguageKind, Class<? extends AbstractParserFacade>> MAPPING =
      ImmutableMap.<LanguageKind, Class<? extends AbstractParserFacade>>builder()
          .put(LanguageKind.C, PnfCParserFacade.class)
          .put(LanguageKind.JAVA, JavaParserFacade.class)
          .put(LanguageKind.GO, PnfGoParserFacade.class)
          .build();

  public AbstractParserFacade createParserFacade(LanguageKind languageKind) {
    checkArgument(
        MAPPING.containsKey(languageKind),
        "The language %s is not supported: %s",
        languageKind,
        MAPPING);
    final Class<? extends AbstractParserFacade> klass = MAPPING.get(languageKind);
    try {
      return klass.newInstance();
    } catch (InstantiationException | IllegalAccessException e) {
      throw new AssertionError("Cannot create instance of class " + klass, e);
    }
  }
}
