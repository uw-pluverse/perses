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

import com.google.common.annotations.VisibleForTesting
import org.perses.antlr.ParseTreeWithParser
import org.perses.grammar.AbstractParserFacade
import org.perses.grammar.AbstractParserFacadeFactory.ResolvedParserFacade
import org.perses.grammar.AntlrFailureException
import org.perses.grammar.ParseErrorHandling
import org.perses.grammar.TolerantFallbackParserFacades
import org.perses.program.SourceFile

/**
 * Reduces a *set* of source files against a single interestingness test by reducing one file at a
 * time with the single-file [RegularProgramReductionDriver]. Within a sweep, files are reduced from
 * largest to smallest by non-blank character count, so the smaller files reduced later can exploit
 * the already-reduced larger siblings.
 *
 * Reduction of a multi-file set proceeds in two phases (two-phase, main-reducer-first scheduling):
 *  1. a quick warm-up sweep with [MainReducerOnlyOnceProgramReductionDriver], running only the main
 *     reducer once on each file -- stripping the bulk from every file and publishing each reduction
 *     to the result folder; then
 *  2. an outer global fixpoint that repeats a full sweep -- [RegularProgramReductionDriver] running
 *     the default reducer setup (main reducer + fixpoint and the remaining stages) on each file --
 *     until a whole sweep removes nothing more.
 * Because the warm-up has already shrunk every file, the first full sweep reduces each file against
 * siblings that are themselves already smaller. A file reduced early in a sweep does not see the
 * reductions later made to its siblings, so the sweep is repeated: each repetition picks up those
 * cross-file opportunities, and the loop stops once the set -- measured by total canonical token
 * count, which only decreases -- stops shrinking. A single input file has no siblings, so it skips
 * both the warm-up and the fixpoint and runs the full pass once, identical to the previous
 * single-file path.
 *
 * Each per-file driver stands up a single-file driver from the shared [ReductionDriverParams] (only
 * the main file differs); it reads the file being reduced and its siblings' current best from the
 * result folder and writes its result back in place, so files reduced later already see the earlier
 * reductions. Every per-file driver of the two sweeps is built fresh so that it re-reads the
 * siblings' latest reduced state.
 *
 * Each file's parser facade is resolved up front by probing that file's own content against the
 * candidates for that file's own language; a parse failure surfaces there. Every per-file driver is
 * then built with its own file's facade and code format, so a set whose files differ in language
 * reduces each file with the facade and format that fit it (a single-language set resolves every
 * file the same way, matching the previous whole-set behavior). The single-file case builds one full
 * driver and reduces; the multi-file case builds fresh per-file drivers across the two sweeps.
 * See internal_doc/multifile_reduction_design.md.
 */
class PerFileReductionDriver(
  // All the inputs needed to build a per-file driver except which file it reduces; reused for every
  // driver of both sweeps.
  private val params: ReductionDriverParams,
) : IReductionDriver {
  // Reduce the largest files first: a big file usually has the most to delete, and shrinking it
  // early lets the smaller files that follow see (and exploit) the already-reduced siblings via
  // resultFolder. Size is the count of non-blank characters, computed once per file here (a sort
  // selector would rescan the whole content on every comparison). Ties keep their original order
  // (sortedByDescending is stable).
  private val mutableFiles: List<SourceFile> =
    params.originalReductionInputs.mutableFiles
      .map { it as SourceFile }
      .map { file -> file to file.textualFileContent.count { !Character.isWhitespace(it) } }
      .sortedByDescending { (_, nonBlankCharacterCount) -> nonBlankCharacterCount }
      .map { (file, _) -> file }

  init {
    require(mutableFiles.isNotEmpty()) {
      "PerFileReductionDriver expects at least one source file: $mutableFiles"
    }
    // Record each file's original-content facade up front. The facade is re-resolved against the
    // file's current content at every driver build (see resolveCurrentFacade), so this record is kept
    // only for: (a) reusing the probe's parse tree on the first spar-tree build -- retained only for
    // the first file built (largest, reduced first), whose first build consumes it right away; and (b)
    // a stable facade for computeTotalCanonicalTokenCount's convergence metric.
    mutableFiles.forEachIndexed { index, file ->
      resolveAndRecordParserFacadeFor(file, retainParseTree = index == 0)
    }
  }

  private fun resolveAndRecordParserFacadeFor(
    file: SourceFile,
    retainParseTree: Boolean,
  ) {
    if (params.originalReductionInputs.hasCanonicalParserFacade(file)) {
      // Recorded in an earlier content round: this driver is rebuilt each round of
      // AbstractMain.runContentReductionToFixpoint, and the facade cache is shared across rounds. This
      // record is the *original-content* facade, used only for the stable sizing metric and first-build
      // parse-tree reuse; promotion to a different grammar happens via per-build re-resolution, not
      // here. Reuse it rather than re-recording, which the cache forbids.
      return
    }
    val resolution = resolveCurrentFacade(file, file.textualFileContent)
    params.originalReductionInputs.recordCanonicalParserFacade(
      file = file,
      parserFacade = resolution.facade,
      sourceCode = file.textualFileContent,
      parseTree = if (retainParseTree) resolution.parseTree else null,
    )
  }

  /**
   * Resolves the parser facade for [file] against [sourceCode] (its current content): the file's
   * real-grammar facades first, then -- if none parse -- the tolerant fallback ladder obtained by
   * walking [TolerantFallbackParserFacades.nextTolerantFallbackOrNull] from the real default facade
   * (a single rung, the adaptive Dyck grammar). Returns the first facade that actually parses; every
   * candidate is parsed (unlike [AbstractParserFacadeFactory.ParserFacadeList]'s single-candidate
   * fast path), so a real grammar that does not fit is detected and skipped. The adaptive Dyck rung
   * accepts any input, so this never throws for a real file; reduction continues on a tolerant
   * grammar instead of bailing out. Re-resolving here (rather than reusing a once-resolved facade)
   * lets a file climb back to its real grammar once reduction makes it parse again. See
   * internal_doc/tolerant_grammar_fallback_design.md.
   *
   * With `--enable-error-tolerant-grammar`, a most-specific rung is inserted above Dyck: an
   * error-tolerant parse of the file's own real grammar, which keeps structure the grammar-agnostic
   * ladder discards.
   */
  @VisibleForTesting
  internal fun resolveCurrentFacade(
    file: SourceFile,
    sourceCode: String,
  ): ResolvedParserFacade {
    val fileName = file.file.fileName.toString()
    val realFacades =
      params
        .parserFacadeCandidatesFor(
          file.dataKind,
        ).sequenceOfCreators()
        .map { it.create() }
        .toList()
    for (facade in realFacades) {
      parseOrNull(facade, sourceCode, fileName)?.let { return ResolvedParserFacade(facade, it) }
    }
    // Most-specific tolerant rung, above Dyck: an error-tolerant parse of the file's own real grammar.
    // It recovers structure the Dyck/Line grammars discard (unparseable fragments become leaf tokens),
    // so it is preferred when enabled. Opt-in because it is newer than the grammar-agnostic ladder.
    if (params.cmd.experimentFlags.enableErrorTolerantGrammar) {
      for (facade in realFacades) {
        parseTolerantOrNull(facade, sourceCode, fileName)?.let { parseTree ->
          params.listenerManager.onAdHocMessageEvent(
            params.reductionStartEvent.createAdHocMessageEvent(
              perFileSizeMetrics = params.reductionStartEvent.initialPerFileSizeMetrics(),
              prefixLabelFromRootToHere = "",
              messageComputer = {
                "WARNING: ${file.baseName} does not parse under its ${file.dataKind.name} " +
                  "grammar; reducing an error-tolerant parse of that grammar. The reduced output " +
                  "may not be valid ${file.dataKind.name}."
              },
            ),
          )
          return ResolvedParserFacade(facade, parseTree)
        }
      }
    }
    // This ladder is the *spine* selector: it picks one grammar for the file's main reduction. Running
    // a coarser grammar as an extra reduction pass -- rather than descending the ladder -- is done
    // separately, as flag-gated passes, so a coarser grammar can still permit deletions a finer one's
    // rules forbid. See internal_doc/error_tolerant_multi_grammar_passes.md.
    var fallback = TolerantFallbackParserFacades.nextTolerantFallbackOrNull(realFacades.first())
    while (fallback != null) {
      val facade = fallback
      parseOrNull(facade, sourceCode, fileName)?.let { parseTree ->
        // Routed through the listener manager's ad-hoc message stream (as the adaptive
        // code-format switch in AbstractProgramReductionDriver does) so it surfaces in the
        // reduction output, not just the log.
        params.listenerManager.onAdHocMessageEvent(
          params.reductionStartEvent.createAdHocMessageEvent(
            perFileSizeMetrics = params.reductionStartEvent.initialPerFileSizeMetrics(),
            prefixLabelFromRootToHere = "",
            messageComputer = {
              "WARNING: ${file.baseName} is not parseable by its ${file.dataKind.name} grammar; " +
                "falling back to the tolerant '${facade.language.name}' grammar " +
                "to keep reducing. The reduced output may not be valid ${file.dataKind.name}."
            },
          ),
        )
        return ResolvedParserFacade(facade, parseTree)
      }
      fallback = TolerantFallbackParserFacades.nextTolerantFallbackOrNull(facade)
    }
    // The adaptive Dyck rung parses any input, so the ladder always succeeds for a real file;
    // reaching here means even that failed (e.g. a tolerant language was misconfigured), which is a
    // genuine error -- surface it rather than silently dropping the file.
    throw AntlrFailureException(
      cause = null,
      file = fileName,
      details =
        "Neither the ${file.dataKind.name} grammar nor any tolerant fallback grammar " +
          "(Dyck/Line) could parse $fileName.",
    )
  }

  // parseString retries a deeply nested input on a large stack and reports an unparsable one as an
  // AntlrFailureException, so an overflow arrives here as an ordinary parse failure; the ladder just
  // descends to the next fallback grammar.
  private fun parseOrNull(
    facade: AbstractParserFacade,
    sourceCode: String,
    fileName: String,
  ): ParseTreeWithParser? =
    try {
      facade.parseString(sourceCode, fileName, errorMode = ParseErrorHandling.STRICT)
    } catch (_: Exception) {
      null
    }

  private fun parseTolerantOrNull(
    facade: AbstractParserFacade,
    sourceCode: String,
    fileName: String,
  ): ParseTreeWithParser? =
    try {
      facade.parseString(sourceCode, fileName, errorMode = ParseErrorHandling.TOLERANT)
    } catch (_: Exception) {
      null
    }

  private fun parserFacadeFor(file: SourceFile): AbstractParserFacade =
    params.originalReductionInputs.getCanonicalParserFacade(file)

  override fun reduce() {
    if (mutableFiles.size == 1) {
      // A single file has no siblings to publish reductions for, so the warm-up sweep and the outer
      // fixpoint would only repeat work the per-file driver already does. Run the full default plan
      // once, exactly as the previous single-file path did.
      createReductionDriverFor(mutableFiles.single()).use { it.reduce() }
      return
    }
    mainReducerOnlyWarmUpSweep()
    // Outer global fixpoint over the whole set: a file reduced early in a sweep never sees the
    // reductions later made to its siblings, so a single sweep leaves cross-file opportunities on
    // the table. Repeat the full sweep until one removes nothing more. The set shrinks monotonically
    // (total canonical token count, bounded below by 0), so the loop terminates.
    var sizeBefore = computeTotalCanonicalTokenCount()
    do {
      fullSweep()
      val sizeAfter = computeTotalCanonicalTokenCount()
      val progressed = sizeAfter < sizeBefore
      sizeBefore = sizeAfter
    } while (progressed)
  }

  // The warm-up sweep (largest file first): run only the main reducer once on each file, publishing
  // each reduction to resultFolder so later files -- and the full sweeps -- see the shrunk siblings.
  private fun mainReducerOnlyWarmUpSweep() {
    reduceEachMutableFile { buildMainReducerOnlyOnceDriverFor(it) }
  }

  // One full sweep (largest file first): run the full default plan on each file. Each driver is
  // freshly built so it re-reads the siblings' latest reduced state from resultFolder.
  private fun fullSweep() {
    reduceEachMutableFile { createReductionDriverFor(it) }
  }

  // Build a fresh driver for each mutable file (via [buildDriver]) and run it, skipping any file whose
  // current best no longer parses. A sibling may have reduced a file to content its grammar rejects --
  // e.g. a C file emptied to zero declarations, which C's translationUnit (one-or-more) cannot parse.
  // Such a file has no reducible tree this sweep, so skip it; the terminal file-deletion phase can
  // still drop it. This makes driver *construction* as tolerant as [AbstractProgramReductionDriver]'s
  // rebuildSparTreeIfDirty already is: that path catches the same failure and keeps reducing instead
  // of aborting -- only construction lacked the symmetry, turning an emptied sibling into a crash.
  //
  // TODO: a blank/unparsable file is detected reactively, by attempting to build its driver and
  //  catching the parse failure. First-class "fully reduced / deleted" state on the reduction inputs
  //  (a flag per mutable file in OriginalReductionInputs/ReductionFolder, set once a file reaches blank or is
  //  dropped) would let both the sweeps and the file-deletion phase skip it up front, without the
  //  speculative build, and let a file emptied mid-sweep be retired immediately.
  private fun reduceEachMutableFile(buildDriver: (SourceFile) -> IReductionDriver) {
    mutableFiles.forEach { file ->
      val driver =
        try {
          buildDriver(file)
        } catch (_: AntlrFailureException) {
          return@forEach
        }
      driver.use { it.reduce() }
    }
  }

  // The whole set's size, read from its current best in resultFolder. Used only to detect outer-loop
  // convergence, so the per-sweep cost of one parse per file is negligible next to a reduction sweep.
  private fun computeTotalCanonicalTokenCount(): Int =
    params.resultFolder
      .sequenceOfLiveMutableFiles()
      .sumOf { (origFile, absPath) ->
        parserFacadeFor(origFile as SourceFile).computeProgramSizeOf(absPath).canonicalTokenCount
      }

  override fun close() {
    // Each per-file driver is closed by reduce() via use{}. The query cache is owned and closed by
    // the entry point (AbstractMain), not here.
  }

  /**
   * Returns a full single-file [RegularProgramReductionDriver] that reduces [activeFile] against the
   * rest of the set: it reads [activeFile] and its siblings' current best from the result folder and
   * writes the reduction back in place. Built fresh each call so it re-reads the latest sibling state.
   */
  fun createReductionDriverFor(activeFile: SourceFile): RegularProgramReductionDriver =
    RegularProgramReductionDriver.create(
      params,
      activeFile,
      resolveFacadeForCurrentContent(activeFile),
    )

  private fun buildMainReducerOnlyOnceDriverFor(
    mainFile: SourceFile,
  ): MainReducerOnlyOnceProgramReductionDriver =
    MainReducerOnlyOnceProgramReductionDriver.create(
      params,
      mainFile,
      resolveFacadeForCurrentContent(mainFile),
    )

  // Re-resolve the facade against the file's current best each build (not the once-recorded canonical
  // facade), so a file reduced under a tolerant grammar is promoted back to its real grammar as soon
  // as it parses again, and a file emptied below its real grammar falls back instead of crashing.
  private fun resolveFacadeForCurrentContent(file: SourceFile): AbstractParserFacade =
    resolveCurrentFacade(file, params.resultFolder.readFileContent(file)).facade
}
