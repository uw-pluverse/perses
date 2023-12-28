/*
 * Copyright (C) 2018-2024 University of Waterloo.
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

import com.google.common.collect.ImmutableList
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.grammar.adhoc.AdhocParserFacadeFactoryUtil.createParserFacadeFactory
import org.perses.reduction.IReductionDriver
import org.perses.reduction.ReducerFactory.defaultReductionAlgName
import org.perses.reduction.ReducerFactory.isValidReducerName
import org.perses.reduction.ReducerFactory.printAllReductionAlgorithms
import org.perses.reduction.RegularProgramReductionDriver

class Main(args: Array<String>) : AbstractMain<CommandOptions>(args) {
  override fun createCommandOptions(): CommandOptions {
    return CommandOptions(defaultReductionAlgName)
  }

  override fun createExtFacadeFactory(): AbstractParserFacadeFactory {
    // Cannot close this file, as the file has class loader to load the parser facade classes.
    return createParserFacadeFactory(
      cmd.languageControlFlags.languageJarFiles,
    )
  }

  override fun validateCommandOptions() {
    super.validateCommandOptions()
    check(isValidReducerName(cmd.algorithmControlFlags.getReductionAlgorithmName())) {
      "Invalid reduction algorithm " +
        cmd.algorithmControlFlags.getReductionAlgorithmName()
    }
  }

  override fun processHelpRequests(): HelpRequestProcessingDecision {
    if (cmd.algorithmControlFlags.listAllReductionAlgorithms) {
      println("All available reduction algorithms: ")
      println(printAllReductionAlgorithms())
      return HelpRequestProcessingDecision.EXIT
    }
    if (cmd.languageControlFlags.listParserFacades) {
      TODO("Need to implement this.")
    }
    if (cmd.languageControlFlags.listLangs) {
      TODO("Need to implement this.")
    }
    return HelpRequestProcessingDecision.NO_EXIT
  }

  override fun createReductionDriver(facadeFactory: AbstractParserFacadeFactory): IReductionDriver {
    return RegularProgramReductionDriver.create(cmd, facadeFactory, ImmutableList.of())
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      Main(args).run()
    }
  }
}
