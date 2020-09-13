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

import com.google.common.collect.ImmutableMap
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
class ParserFacadeFactory private constructor(
  private val language2FacadeMap: ImmutableMap<LanguageKind, () -> AbstractParserFacade>
) {

  class Builder {
    private val language2FacadeMap =
      ImmutableMap.builder<LanguageKind, () -> AbstractParserFacade>()

    fun add(language: LanguageKind, facadeCreator: () -> AbstractParserFacade): Builder {
      language2FacadeMap.put(language, facadeCreator)
      return this
    }

    fun build() = ParserFacadeFactory(language2FacadeMap.build())
  }

  fun createParserFacade(languageKind: LanguageKind): AbstractParserFacade {
    require(language2FacadeMap.contains(languageKind)) {
      "Unrecognized language kind $languageKind"
    }
    return language2FacadeMap[languageKind]!!.invoke().also {
      check(it.language == languageKind) {
        "${it.language} != $languageKind"
      }
    }
  }

  companion object {

    @JvmStatic
    fun builderWithBuiltinLanguages(): Builder {
      val builder = Builder()
      builder.add(LanguageGo) { PnfGoParserFacade() }
      builder.add(LanguageRust) { PnfRustParserFacade() }
      builder.add(LanguageScala) { PnfScalaParserFacade() }
      builder.add(LanguageJava) { JavaParserFacade() }
      builder.add(LanguageC) { PnfCParserFacade() }
      return builder
    }
  }
}
