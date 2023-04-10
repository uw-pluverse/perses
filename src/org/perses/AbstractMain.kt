/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses

import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.grammar.CompositeParserFacadeFactory
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.grammar.SingleParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.reduction.IReductionDriver
import org.perses.util.cmd.AbstractCommandOptions

abstract class AbstractMain<Cmd : AbstractCommandOptions>(args: Array<String>) :
  org.perses.util.cmd.AbstractMain<Cmd>(args) {

  lateinit var parserFacadeFactory: AbstractParserFacadeFactory

  override fun internalRun() {
    initializeParserFacadeFactory()
    createReductionDriver(parserFacadeFactory).use { driver -> driver.reduce() }
  }

  private fun initializeParserFacadeFactory() {
    val builtinFacadeFactory = createBuiltinParserFacadeFactory()
    val extFacadeFactory = createExtFacadeFactory()
    parserFacadeFactory = CompositeParserFacadeFactory(
      builtinFactory = builtinFacadeFactory,
      extFactory = extFacadeFactory,
    )
  }

  protected abstract fun createReductionDriver(
    facadeFactory: AbstractParserFacadeFactory,
  ): IReductionDriver

  private fun createBuiltinParserFacadeFactory(): AbstractParserFacadeFactory {
    val customizer = createCustomizer()
    val builder = builderWithBuiltinLanguages(customizer)
    return builder.build()
  }

  protected open fun createCustomizer(): SingleParserFacadeFactory.ParserFacadeFactoryCustomizer {
    return SingleParserFacadeFactory.IDENTITY_CUSTOMIZER
  }

  protected open fun createExtFacadeFactory(): AbstractParserFacadeFactory {
    return SingleParserFacadeFactory.createEmptyFactory()
  }
}
