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

import org.perses.PersesCommandOptions
import org.perses.grammar.AbstractParserFacadeFactory
import org.perses.program.EnumFormatControl
import org.perses.program.LanguageKind
import org.perses.reduction.cache.AbstractQueryCache
import org.perses.reduction.event.ReductionStartEvent
import org.perses.reduction.io.DefaultLanguageOriginalReductionInputs
import org.perses.reduction.io.ReductionFolder
import org.perses.util.hashing.EnumShaAlgorithm
import java.nio.file.Path

/**
 * The inputs that configure one reduction, independent of which file is being reduced. The
 * orchestrator [PerFileReductionDriver] takes this directly; each per-file driver factory
 * takes it plus the main file (see [RegularProgramReductionDriver.create]). The orchestrator builds
 * it once and reuses it for every per-file driver of both sweeps.
 */
class ReductionDriverParams(
  val globalContext: GlobalContext,
  val cmd: PersesCommandOptions,
  val workingDirectory: Path,
  val resultFolder: ReductionFolder,
  val originalReductionInputs: DefaultLanguageOriginalReductionInputs,
  // Resolved per file from that file's own language, so a multi-file set whose files differ in
  // language gives each file its own facade candidates and code format. For a single-language set
  // every file resolves the same way.
  val parserFacadeCandidatesFor: (LanguageKind) -> AbstractParserFacadeFactory.ParserFacadeList,
  val codeFormatFor: (LanguageKind) -> EnumFormatControl,
  val listenerManager: AsyncReductionListenerManager,
  val shaAlgorithm: EnumShaAlgorithm,
  val languageProfile: LanguageProfile,
  val reducerFactory: ReducerFactory,
  // One query cache shared by every per-file driver: an uninteresting whole-set state recorded while
  // reducing one file is reused when a later file reaches the same state. Owned and closed by the
  // entry point (see AbstractMain.queryCacheManager), not by any driver.
  val queryCache: AbstractQueryCache,
  // The single whole-reduction start event, created once by AbstractMain and shared by every driver
  // of the reduction (see AbstractMain.internalRun). Drivers use it for their fixpoint-iteration and
  // ad-hoc messages instead of each creating their own, so the reported initial size and the
  // fixpoint-iteration numbering are continuous across the whole reduction.
  val reductionStartEvent: ReductionStartEvent,
  // The test-script executor, created once by AbstractMain and shared by every per-file driver, so its
  // thread pools are reused across sweeps and its statistics are the whole-reduction total.
  val executorService: TestScriptExecutorService,
)
