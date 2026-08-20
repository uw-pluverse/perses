/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.reduction

import com.google.common.collect.ImmutableMap
import org.perses.PersesCommandOptions
import org.perses.antlr.atn.LexerAtnWrapper
import org.perses.grammar.AbstractParserFacade
import org.perses.program.AbstractReductionFile
import org.perses.program.EnumFormatControl
import org.perses.reduction.cache.AbstractQueryCache
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.io.DefaultLanguageOriginalReductionInputs
import org.perses.reduction.io.ReductionFolder
import org.perses.reduction.io.token.AbstractTokenOutputManagerFactory
import org.perses.reduction.io.token.RegularOutputManagerFactory
import org.perses.reduction.io.token.TokenReductionIOManager
import org.perses.util.hashing.EnumShaAlgorithm
import java.nio.file.Path

/**
 * This is the main entry to invoke Perses reducer. It does not have a main, but is the main entry
 * as a reduction library.
 */
open class RegularProgramReductionDriver protected constructor(
  globalContext: GlobalContext,
  cmd: PersesCommandOptions,
  ioManager: TokenReductionIOManager,
  mainFile: AbstractReductionFile<*, *>,
  configuration: ReductionConfiguration,
  listenerManager: AsyncReductionListenerManager,
  languageProfile: LanguageProfile,
  reducerFactory: ReducerFactory,
  queryCache: AbstractQueryCache,
  outputManagerFactory: AbstractTokenOutputManagerFactory,
  reductionStartEvent: ReductionStartEvent,
  executorService: TestScriptExecutorService,
  /** The fixed current-best content of every mutable file other than [mainFile], read once and
   * shared with the output-manager factory; see [buildComponents]. */
  otherMutableFileContents: ImmutableMap<AbstractReductionFile<*, *>, String>,
) : AbstractProgramReductionDriver(
    globalContext = globalContext,
    cmd = cmd,
    ioManager = ioManager,
    mainFile = mainFile,
    configuration = configuration,
    listenerManager = listenerManager,
    languageProfile = languageProfile,
    reducerFactory = reducerFactory,
    queryCache = queryCache,
    outputManagerFactory = outputManagerFactory,
    reductionStartEvent = reductionStartEvent,
    executorService = executorService,
  ) {
  override var inputRepresentation: InputRepresentation =
    run {
      createInputRepresentation(
        // Read the active file and its siblings from the result folder (the latest best), which the
        // entry point seeded with the original inputs before constructing this driver.
        sourceFile = ioManager.resultFolder.computeAbsPathForOrigFile(mainFile),
        fileRepresentedByTree = mainFile,
        otherMutableFileContents = otherMutableFileContents,
        surrogateParserFacade = configuration.canonicalParserFacade,
        canonicalParserFacade = configuration.canonicalParserFacade,
        specifiedSparTreeNodeFactory = null,
        semanticsProviderCreator = configuration.mimirConfig.semanticsProviderCreator,
        enableNodeActionSetCache = cmd.cacheControlFlags.nodeActionSetCaching,
        originalReductionInputs = ioManager.originalReductionInputs,
      )
    }

  companion object {
    fun createIOManager(
      workingDirectory: Path,
      originalReductionInputs: DefaultLanguageOriginalReductionInputs,
      resultFolder: ReductionFolder,
    ): TokenReductionIOManager =
      TokenReductionIOManager(
        workingDirectory,
        originalReductionInputs,
        // The result folder is already populated with the original inputs by the caller (the main
        // class); the manager reads the program (and siblings) from there.
        resultFolder = resultFolder,
      )

    /** The output-manager factory (the renderer) the driver owns. [mainFile] is the file under
     * reduction; its siblings are fixed for the driver's lifetime, so [otherMutableFileContents] is
     * bound into the factory (with [mainFile] as the represented file) and the factory renders the
     * whole set from just a program. */
    fun createOutputManagerFactory(
      originalReductionInputs: DefaultLanguageOriginalReductionInputs,
      codeFormatControl: EnumFormatControl,
      lexerAtnWrapper: LexerAtnWrapper,
      shaAlgorithm: EnumShaAlgorithm,
      mainFile: AbstractReductionFile<*, *>,
      otherMutableFileContents: ImmutableMap<AbstractReductionFile<*, *>, String>,
    ): RegularOutputManagerFactory =
      RegularOutputManagerFactory(
        originalReductionInputs,
        codeFormatControl,
        lexerAtnWrapper,
        shaAlgorithm = shaAlgorithm,
        fileRepresentedByProgram = mainFile,
        // The siblings' current best, read once from the result folder; the manager renders the
        // represented file plus exactly these siblings.
        otherMutableFileContents = otherMutableFileContents,
      )

    fun create(
      params: ReductionDriverParams,
      mainFile: AbstractReductionFile<*, *>,
      resolvedParserFacade: AbstractParserFacade,
    ): RegularProgramReductionDriver {
      val components = buildComponents(params, mainFile, resolvedParserFacade)
      return RegularProgramReductionDriver(
        globalContext = params.globalContext,
        cmd = params.cmd,
        ioManager = components.ioManager,
        mainFile = mainFile,
        configuration = components.configuration,
        listenerManager = params.listenerManager,
        languageProfile = params.languageProfile,
        reducerFactory = params.reducerFactory,
        queryCache = params.queryCache,
        outputManagerFactory = components.outputManagerFactory,
        reductionStartEvent = params.reductionStartEvent,
        executorService = params.executorService,
        otherMutableFileContents = components.otherMutableFileContents,
      )
    }

    /** The per-driver IO manager, output-manager factory, reduction configuration, and the once-read
     * sibling content the driver shares between its factory and its initial spar-tree; see
     * [buildComponents]. */
    internal class DriverComponents(
      val ioManager: TokenReductionIOManager,
      val outputManagerFactory: RegularOutputManagerFactory,
      val configuration: ReductionConfiguration,
      val otherMutableFileContents: ImmutableMap<AbstractReductionFile<*, *>, String>,
    )

    /**
     * Builds the IO manager and reduction configuration shared by every single-file driver. A
     * subclass's `create` calls this and then invokes its own constructor with the result, so it
     * reuses all of this wiring and differs only in how the reducer plan is generated (see
     * [MainReducerOnlyOnceProgramReductionDriver]).
     */
    internal fun buildComponents(
      params: ReductionDriverParams,
      mainFile: AbstractReductionFile<*, *>,
      resolvedParserFacade: AbstractParserFacade,
    ): DriverComponents {
      // [mainFile]'s siblings are fixed for the driver's lifetime, so read their current best from
      // the (already populated) result folder exactly once here and share it between the
      // output-manager factory and the driver's initial spar-tree (the InputRepresentation).
      val otherMutableFileContents =
        params.resultFolder.readLiveMutableFileContents(
          excluding = mainFile,
        )
      val ioManager =
        createIOManager(
          params.workingDirectory,
          params.originalReductionInputs,
          resultFolder = params.resultFolder,
        )
      val outputManagerFactory =
        createOutputManagerFactory(
          params.originalReductionInputs,
          // The active file's own code format, resolved from its language (siblings render verbatim).
          params.codeFormatFor(resolvedParserFacade.language),
          resolvedParserFacade.lexerAtnWrapper,
          params.shaAlgorithm,
          mainFile = mainFile,
          otherMutableFileContents = otherMutableFileContents,
        )
      val configuration =
        createConfiguration(
          params.cmd,
          resolvedParserFacade,
          outputManagerFactory.defaultCodeFormatControl,
          reducerFactory = params.reducerFactory,
        )
      return DriverComponents(
        ioManager,
        outputManagerFactory,
        configuration,
        otherMutableFileContents,
      )
    }
  }
}
