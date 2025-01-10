/*
 * Copyright (C) 2018-2025 University of Waterloo.
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

import com.google.common.flogger.FluentLogger
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.grammar.AntlrFailureException
import org.perses.grammar.CompositeParserFacadeFactory
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.grammar.SingleParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.program.LanguageKind
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.reduction.IReductionDriver
import org.perses.reduction.SanityCheckFailedException
import org.perses.reduction.io.IReductionInputs
import org.perses.util.cmd.AbstractCommandOptions
import org.perses.util.ktSevere
import java.io.Closeable

abstract class AbstractMain<
  Cmd : AbstractCommandOptions,
  ReductionDriver : IReductionDriver,
  ReductionInputs : IReductionInputs<LanguageKind, ReductionInputs>,
  >(
  cmd: Cmd,
  protected val globalContext: GlobalContext,
) : org.perses.util.cmd.AbstractMain<Cmd>(cmd), Closeable {

  protected val parserFacadeFactory by lazy {
    initializeParserFacadeFactory()
  }

  protected val reductionInputs: ReductionInputs by lazy {
    createReductionInputs(parserFacadeFactory)
  }

  protected lateinit var listenerManager: AsyncReductionListenerManager

  final override fun internalRun() {
    listenerManager = createAsyncReductionListenerManager()
    val suppressedExceptions = mutableListOf<Exception>()
    for (driverCreator in createSequenceOfReductionDriverCreators(reductionInputs)) {
      val driver: ReductionDriver
      try {
        driver = driverCreator.creator()
      } catch (e: AntlrFailureException) {
        logger.ktSevere {
          """Failed to parse the input program with the reduction driver: 
            |${driverCreator.description}
            |
            |Perses will try to create a different reduction driver to parse the program.
          """.trimMargin()
        }
        suppressedExceptions.add(e)
        continue
      }
      val sanityCheckResult = driver.cachedSanityCheckResult
      if (sanityCheckResult is IReductionDriver.FailingSanityCheckResult) {
        suppressedExceptions.add(sanityCheckResult.exception)
        logger.ktSevere {
          """
          |The initial sanity check failed. More information is provided below.
          |
          |${sanityCheckResult.exception}
          |
          |Driver creator: ${driverCreator.description}
          |
          |Perses might automatically try difference configurations now.
          |
          |
          """.trimMargin()
        }
        continue
      }
      driver.use { it.reduce() }
      suppressedExceptions.clear()
      break
    }
    if (suppressedExceptions.isNotEmpty()) {
      val exception = SanityCheckFailedException(
        "Failed to create a reduction driver for the input program.",
      )
      suppressedExceptions.forEach { exception.addSuppressed(it) }
      throw exception
    }
  }

  protected abstract fun createAsyncReductionListenerManager(): AsyncReductionListenerManager

  protected abstract fun createReductionInputs(
    parserFacadeFactory: AbstractParserFacadeFactory,
  ): ReductionInputs

  private fun initializeParserFacadeFactory(): AbstractParserFacadeFactory {
    val builtinFacadeFactory = createBuiltinParserFacadeFactory()
    val extFacadeFactory = createExtFacadeFactory()
    return CompositeParserFacadeFactory(
      builtinFactory = builtinFacadeFactory,
      extFactory = extFacadeFactory,
    )
  }

  class ReductionDriverCreator<ReductionDriver : IReductionDriver>(
    val creator: () -> ReductionDriver,
    descriptor: () -> String,
  ) {
    val description: String by lazy {
      descriptor()
    }
  }

  protected abstract fun createSequenceOfReductionDriverCreators(
    reductionInputs: ReductionInputs,
  ): Sequence<ReductionDriverCreator<ReductionDriver>>

  private fun createBuiltinParserFacadeFactory(): AbstractParserFacadeFactory {
    return builderWithBuiltinLanguages().build()
  }

  protected open fun createExtFacadeFactory(): AbstractParserFacadeFactory {
    return SingleParserFacadeFactory.createEmptyFactory()
  }

  override fun close() {
    if (this::listenerManager.isInitialized) {
      listenerManager.close()
    }
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
