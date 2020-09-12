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
package org.perses.grammar

import org.perses.grammar.c.CParserFacade
import org.perses.grammar.c.PnfCParserFacade
import org.perses.grammar.go.PnfGoParserFacade
import org.perses.grammar.java.JavaParserFacade
import org.perses.grammar.rust.PnfRustParserFacade
import org.perses.grammar.scala.PnfScalaParserFacade
import org.perses.program.LanguageC
import org.perses.program.LanguageGo
import org.perses.program.LanguageJava
import org.perses.program.LanguageKind
import org.perses.program.LanguageRust
import org.perses.program.LanguageScala

/** Creates a parser facade, based on the type of language kind.  */
class ParserFacadeFactory private constructor(private val useOptCParser: Boolean) {

  fun createParserFacade(languageKind: LanguageKind): AbstractParserFacade {
    val facade = when (languageKind) {
      LanguageC -> if (useOptCParser) CParserFacade() else PnfCParserFacade()
      LanguageJava -> JavaParserFacade()
      LanguageGo -> PnfGoParserFacade()
      LanguageScala -> PnfScalaParserFacade()
      LanguageRust -> PnfRustParserFacade()
      else -> throw RuntimeException("The language $languageKind is not supported.")
    }
    check(facade.language == languageKind)
    return facade
  }

  companion object {
    @JvmStatic
    fun createForPnfC(): ParserFacadeFactory {
      return ParserFacadeFactory(false)
    }

    @JvmStatic
    fun createForOptC(): ParserFacadeFactory {
      return ParserFacadeFactory(true)
    }
  }
}
