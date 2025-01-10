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

import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.grammar.adhoc.AdhocParserFacadeFactoryUtil.createParserFacadeFactory
import org.perses.program.EnumFormatControl
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.reduction.GlobalContext
import org.perses.reduction.ReducerFactory.isValidReducerName
import org.perses.reduction.ReducerFactory.printAllReductionAlgorithms
import org.perses.reduction.RegularProgramReductionDriver
import org.perses.reduction.io.RegularReductionInputs
import org.perses.util.Util
import org.perses.util.cmd.CommandLineProcessor
import org.perses.util.cmd.CommandLineProcessor.HelpRequestProcessingDecision
import org.perses.util.toImmutableList

class Main(
  cmd: CommandOptions,
  globalContext: GlobalContext,
) : AbstractMain<CommandOptions, RegularProgramReductionDriver, RegularReductionInputs>(
  cmd,
  globalContext,
) {
  override fun createExtFacadeFactory(): AbstractParserFacadeFactory {
    // Cannot close this file, as the file has class loader to load the parser facade classes.
    return createParserFacadeFactory(
      cmd.languageControlFlags.languageJarFiles,
    )
  }

  override fun validateCommandOptions() {
    super.validateCommandOptions()
    cmd.algorithmControlFlags.reductionAlgorithm?.let {
      check(isValidReducerName(it)) { "Invalid reduction algorithm $it" }
    }
    cmd.languageControlFlags.languageName.trim().let { lang ->
      check(
        lang.isBlank() ||
          parserFacadeFactory.computeLanguageKindWithLanguageNameIgnoreCase(lang) != null,
      ) {
        "Invalid language name $lang"
      }
    }
  }

  override fun processOtherHelpRequests(): HelpRequestProcessingDecision {
    if (cmd.algorithmControlFlags.listAllReductionAlgorithms) {
      println("All available reduction algorithms: ")
      println(printAllReductionAlgorithms())
      return HelpRequestProcessingDecision.EXIT
    }
    if (cmd.languageControlFlags.listParserFacades) {
      println("All currently supported parser facade classes:\n")
      parserFacadeFactory.languageSequence().sortedBy { it.name }.forEach { lang ->
        val parserFacadeList = parserFacadeFactory.getParserFacadeListForOrNull(lang)!!
        println("$lang (${parserFacadeList.numberOfParserFacades()} parser facades):")
        val prefix = "    default: "
        println("$prefix${parserFacadeList.defaultParserFacade.klass.qualifiedName}")

        if (parserFacadeList.otherParserFacades.isNotEmpty()) {
          println("    Alternatives: ")
          parserFacadeList.otherParserFacades.forEach {
            println("          " + it.klass.qualifiedName)
          }
        }
      }
      return HelpRequestProcessingDecision.EXIT
    }
    if (cmd.languageControlFlags.listLangs) {
      println("All currently supported languages:")
      val maxLength = computeMaxLengthOfLanguageNames(parserFacadeFactory)
      parserFacadeFactory.languageSequence().sortedBy { it.name }.forEach {
        println("    ${it.name.padEnd(maxLength, padChar = ' ')}: $it")
      }
      return HelpRequestProcessingDecision.EXIT
    }
    return HelpRequestProcessingDecision.NO_EXIT
  }

  private fun computeMaxLengthOfLanguageNames(parserFacadeFactory: AbstractParserFacadeFactory) =
    parserFacadeFactory.languageSequence().maxOfOrNull { it.name.length } ?: 0

  override fun createSequenceOfReductionDriverCreators(
    reductionInputs: RegularReductionInputs,
  ): Sequence<ReductionDriverCreator<RegularProgramReductionDriver>> {
    val parserFacadeCreatorList = parserFacadeFactory.getParserFacadeListForOrNull(
      reductionInputs.initiallyDeterminedMainDataKind,
    )
    checkNotNull(parserFacadeCreatorList) {
      reductionInputs.initiallyDeterminedMainDataKind
    }
    val allowedCodeFormatList = mutableListOf(getSpecifiedCodeFormatControl())
    for (
    allowedFormat in
    reductionInputs.initiallyDeterminedMainDataKind.allowedCodeFormatControl
    ) {
      if (allowedCodeFormatList.contains(allowedFormat)) {
        continue
      }
      allowedCodeFormatList.add(allowedFormat)
    }
    return parserFacadeCreatorList.sequenceOfCreators()
      .flatMap { creator ->
        allowedCodeFormatList.asSequence().map { format -> creator to format }
      }.map { (facadeCreator, codeFormat) ->
        ReductionDriverCreator(
          creator = {
            val parserFacade = facadeCreator.create()
            RegularProgramReductionDriver.create(
              globalContext,
              cmd,
              reductionInputs,
              parserFacade,
              codeFormat,
              listenerManager = listenerManager,
            )
          },
          descriptor = {
            """
            $codeFormat
            ${facadeCreator.klass}
            """.trimIndent()
          },
        )
      }
  }

  private fun getSpecifiedCodeFormatControl(): EnumFormatControl {
    val languageKind = reductionInputs.initiallyDeterminedMainDataKind
    return cmd.reductionControlFlags.codeFormat.let { codeFormat ->
      if (codeFormat != null) {
        check(languageKind.isCodeFormatAllowed(codeFormat)) {
          "$codeFormat is not allowed for language $languageKind"
        }
        codeFormat
      } else {
        languageKind.defaultCodeFormatControl
      }
    }
  }

  override fun createReductionInputs(
    parserFacadeFactory: AbstractParserFacadeFactory,
  ): RegularReductionInputs {
    val inputFlags = cmd.inputFlags
    return RegularReductionInputs.create(
      testScriptPath = inputFlags.getTestScript(),
      mainFilePath = inputFlags.getSourceFile(),
      dependencyFiles = inputFlags.deps.toImmutableList(),
      languageKindComputer = { sourceFileAbsPath ->
        parserFacadeFactory.computeLanguage(
          cmd.languageControlFlags.languageName,
          sourceFileAbsPath,
        )
      },
    )
  }

  override fun createAsyncReductionListenerManager(): AsyncReductionListenerManager {
    return PersesListenerManagerCreator.createAsyncReductionListenerManager(
      cmd,
      globalContext.fileStreamPool,
    )
  }

  companion object {
    @JvmStatic
    fun main(args: Array<String>) {
      val processor = CommandLineProcessor(
        cmdCreator = { CommandOptions() },
        programName = Main::class.qualifiedName!!,
        args = args,
      )
      if (processor.process() == HelpRequestProcessingDecision.EXIT) {
        return
      }
      Util.useResources(
        { GlobalContext() },
        { globalContext -> Main(processor.cmd, globalContext) },
      ) { _, main ->
        main.run()
      }
    }
  }
}
