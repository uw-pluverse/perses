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

import com.google.common.collect.ImmutableList
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
import java.nio.file.Path

abstract class AbstractMain<
  Cmd : AbstractCommandOptions,
  ReductionDriver : IReductionDriver,
  ReductionInputs : IReductionInputs<LanguageKind, ReductionInputs>,
>(
  cmd: Cmd,
  protected val globalContext: GlobalContext,
) : org.perses.util.cmd.AbstractMain<Cmd>(cmd),
  Closeable {
  protected val parserFacadeFactory by lazy {
    initializeParserFacadeFactory()
  }

  protected val languageAndParserConfiguration: LanguageAndParserConfiguration by lazy {
    computeLanguageAndParserConfiguration(parserFacadeFactory)
  }

  val reductionInputs: ReductionInputs by lazy {
    createReductionInputs(parserFacadeFactory)
  }

  protected val listenerManager: AsyncReductionListenerManager by lazy {
    createAsyncReductionListenerManager()
  }

  final override fun internalRun() {
    val suppressedExceptions = mutableListOf<Exception>()
    for (driverCreator in createSequenceOfReductionDriverCreators(reductionInputs)) {
      val driver: ReductionDriver
      try {
        driver = driverCreator.creator()
      } catch (e: AntlrFailureException) {
        suppressedExceptions.add(
          RuntimeException(
            """Failed to parse the input program with the reduction driver: 
            |${driverCreator.description}
            |
            |Perses will try to create a different reduction driver to parse the program.
            """.trimMargin(),
            e,
          ),
        )
        continue
      }
      val sanityCheckResult = driver.cachedSanityCheckResult
      if (sanityCheckResult is IReductionDriver.SanityCheckResult.Failing) {
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
      val exception =
        SanityCheckFailedException(
          "Failed to create a reduction driver for the input program.",
        )
      suppressedExceptions.forEach { exception.addSuppressed(it) }
      throw exception
    }
  }

  protected fun computeLanguageForFile(file: Path): LanguageKind =
    when (val configuration = languageAndParserConfiguration) {
      is LanguageAndParserConfiguration.Automatic ->
        parserFacadeFactory.computeLanguageKindOrThrow(file)

      is LanguageAndParserConfiguration.UserSpecifiedParser ->
        configuration.languageKind

      is LanguageAndParserConfiguration.UserSpecifiedLanguage ->
        configuration.languageKind
    }

  protected fun computePlausibleParserFacades(): AbstractParserFacadeFactory.ParserFacadeList {
    val configuration = languageAndParserConfiguration
    val result =
      if (configuration is LanguageAndParserConfiguration.UserSpecifiedParser) {
        AbstractParserFacadeFactory.ParserFacadeList(
          defaultParserFacade = configuration.parserFacade,
          otherParserFacades = ImmutableList.of(),
        )
      } else {
        parserFacadeFactory.getParserFacadeListForOrNull(
          reductionInputs.initiallyDeterminedMainDataKind,
        )
      }
    checkNotNull(result) {
      """
        |$reductionInputs
        |
        |$languageAndParserConfiguration
      """.trimMargin()
    }
    return result
  }

  abstract fun computeLanguageAndParserConfiguration(
    parserFacadeFactory: AbstractParserFacadeFactory,
  ): LanguageAndParserConfiguration

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

  sealed class LanguageAndParserConfiguration {
    object Automatic : LanguageAndParserConfiguration()

    class UserSpecifiedLanguage(
      val languageKind: LanguageKind,
    ) : LanguageAndParserConfiguration()

    class UserSpecifiedParser(
      val languageKind: LanguageKind,
      val parserFacade: AbstractParserFacadeFactory.ParserFacadeCreator,
    ) : LanguageAndParserConfiguration()
  }

  class ReductionDriverCreator<ReductionDriver : IReductionDriver>(
    val creator: () -> ReductionDriver,
    descriptor: () -> String,
  ) {
    val description: String by lazy {
      descriptor()
    }
  }

  abstract fun createSequenceOfReductionDriverCreators(
    reductionInputs: ReductionInputs,
  ): Sequence<ReductionDriverCreator<ReductionDriver>>

  protected open fun createExtFacadeFactory(): AbstractParserFacadeFactory =
    SingleParserFacadeFactory.createEmptyFactory()

  override fun close() {
    listenerManager.close()
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    fun createBuiltinParserFacadeFactory(): AbstractParserFacadeFactory =
      builderWithBuiltinLanguages().build()
  }
}
