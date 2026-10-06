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
package org.perses.listminimizer.microbenchmark

import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.antlr.v4.runtime.Lexer
import org.perses.program.AbstractPersesToken
import org.perses.program.printer.AbstractTokenPlacementListener
import org.perses.program.printer.TokenPlacementRecorder
import org.perses.util.AtomicSequenceGenerator
import org.perses.util.CollectionUtil
import org.perses.util.FileSystemUtil
import org.perses.util.Interval
import org.perses.util.transformToImmutableList
import java.nio.file.Files
import java.nio.file.Path
import java.util.IdentityHashMap
import kotlin.io.path.readText

/**
 * Writes recorded problems, one folder each, under a root directory.
 *
 * The layout puts `microbenchmark.yaml` *beside* `input/` rather than inside it, which is what keeps
 * `input/` a valid Perses input on its own: `--input` expands a directory recursively and excludes
 * only the test script and dependency files, so metadata sitting inside would be picked up as a file
 * to reduce.
 *
 * ```
 * <root>/0000-token_slicer-WINDOWED_SLICER/
 *   microbenchmark.yaml
 *   input/
 *     r.sh, small.c, ...
 * ```
 *
 * The reduction inputs are a parameter of [writeProblem] rather than of the constructor, because
 * they belong to the caller's driver rather than to the reduction.
 */
class ListMinimizationMicrobenchmarkWriter(
  private val rootDirectory: Path,
  /** The file under reduction's own lexer, used to re-read the program that was written. */
  private val underlyingLexerClass: Class<out Lexer>,
  private val minListSizeToRecord: Int,
  private val maxMicrobenchmarksToRecord: Int?,
  /**
   * Issues problem ids. Injected, and the only state that has to be shared: a multi-file reduction
   * runs a driver per file, so a generator each would restart the sequence, collide folder names,
   * and turn the cap into a per-file limit. Everything else here is configuration that any number of
   * instances can hold identically.
   */
  private val microbenchmarkIdGenerator: AtomicSequenceGenerator,
  /**
   * The invocation every problem this writer records came from. Held here rather than passed per
   * problem because one writer belongs to one reduction, so it cannot differ between them.
   */
  val commandLineOptions: String,
) {
  init {
    require(minListSizeToRecord >= 1) { minListSizeToRecord }
    require(maxMicrobenchmarksToRecord == null || maxMicrobenchmarksToRecord > 0) {
      "$maxMicrobenchmarksToRecord"
    }
  }

  val recordedProblemCount: Int
    get() = microbenchmarkIdGenerator.issuedCount

  /**
   * Records one problem, or explains why it was not.
   *
   * Skipping is deliberately not an error: this runs inside a live reduction, and one odd call site
   * must not abort a run that is otherwise producing a useful corpus. But a silent skip leaves an
   * empty corpus with nothing to say whether the threshold, the cap, or a failure was responsible,
   * which is why every outcome carries an explanation.
   *
   * @param elementTokenGroups the leaf tokens of each element, in the order the minimizer sees them
   * @param writeProgramFilesTo populates the given directory with the program files, telling the
   *   given listener where the target file's rendering puts every token. The caller supplies it
   *   because rendering, and knowing which files a reduction has, belong to the reducer rather than
   *   here -- this only decides where they go and reads the ranges off the one rendering written
   */
  fun writeProblem(
    baseProgramTokens: List<AbstractPersesToken>,
    elementTokenGroups: List<List<AbstractPersesToken>>,
    targetFilePath: String,
    recordingContext: RecordingContext,
    writeProgramFilesTo: (Path, AbstractTokenPlacementListener) -> Unit,
  ): Result {
    if (elementTokenGroups.size < minListSizeToRecord) {
      return Result(
        microbenchmarkDirectory = null,
        explanation =
          "The list has ${elementTokenGroups.size} element(s), fewer than the " +
            "$minListSizeToRecord required to record.",
      )
    }
    if (maxMicrobenchmarksToRecord != null &&
      microbenchmarkIdGenerator.issuedCount >= maxMicrobenchmarksToRecord
    ) {
      return Result(
        microbenchmarkDirectory = null,
        explanation =
          "The cap of $maxMicrobenchmarksToRecord recorded microbenchmark(s) has been reached.",
      )
    }
    val microbenchmarkId = microbenchmarkIdGenerator.next()
    // Written here and renamed into place only once complete, so that whatever fails in between --
    // a range that does not resolve, a yaml that cannot be written -- leaves no folder that looks
    // like a problem but is not one.
    val stagingDirectory = rootDirectory.resolve(microbenchmarkId + STAGING_SUFFIX)
    return try {
      writeProblemFolder(
        microbenchmarkId = microbenchmarkId,
        stagingDirectory = stagingDirectory,
        baseProgramTokens = baseProgramTokens,
        elementTokenGroups = elementTokenGroups,
        targetFilePath = targetFilePath,
        recordingContext = recordingContext,
        writeProgramFilesTo = writeProgramFilesTo,
      )
    } catch (failure: Exception) {
      // Exception, not Throwable: a problem this cannot express should be skipped, but an Error --
      // out of memory, a stack overflow -- must not be reported as a skipped recording while the
      // reduction limps on in whatever state produced it.
      if (Files.exists(stagingDirectory)) {
        FileSystemUtil.deleteRecursively(stagingDirectory)
      }
      logger.atWarning().withCause(failure).log("Skipped recording problem %s.", microbenchmarkId)
      Result(
        microbenchmarkDirectory = null,
        explanation = "Problem $microbenchmarkId could not be recorded: $failure",
      )
    }
  }

  /**
   * Where a problem was written, or null when it was not, and a sentence saying why either way.
   *
   * Named [Result] rather than reusing a nullable path so that a caller -- and a test -- can tell a
   * threshold skip from a cap skip from a failure, which all look identical as a null.
   */
  data class Result(
    val microbenchmarkDirectory: Path?,
    val explanation: String,
  )

  private fun writeProblemFolder(
    microbenchmarkId: String,
    stagingDirectory: Path,
    baseProgramTokens: List<AbstractPersesToken>,
    elementTokenGroups: List<List<AbstractPersesToken>>,
    targetFilePath: String,
    recordingContext: RecordingContext,
    writeProgramFilesTo: (Path, AbstractTokenPlacementListener) -> Unit,
  ): Result {
    val inputDirectory =
      FileSystemUtil.ensureDirExists(
        FileSystemUtil
          .ensureDirExists(stagingDirectory)
          .resolve(ListMinimizationMicrobenchmark.INPUT_FOLDER_NAME),
      )
    // The ranges come from where the printer put each token while rendering the file that is
    // written, read back here so they index the bytes on disk. The alternative, re-lexing the
    // written file to locate the tokens, only works when the tokens are the language's own: a
    // reducer running on a surrogate tree -- the line slicer's, where a token is a line -- hands
    // over tokens the real lexer cannot reproduce.
    val placements = TokenPlacementRecorder()
    writeProgramFilesTo(inputDirectory, placements)
    val renderedProgram = inputDirectory.resolve(targetFilePath).readText()
    val elements =
      computeRecordedElements(
        elementTokenGroups = elementTokenGroups,
        tokenLocationMap = locateTokens(renderedProgram, placements, baseProgramTokens),
      )
    // What a recording promises is that the evaluator can resolve its ranges, and the evaluator
    // resolves them against the real lexer's tokens of the written file. Checked here with the
    // evaluator's own resolution, so a range that starts or ends inside a real token -- a line
    // through a block comment -- is refused now rather than failing every measurement later.
    RecordedProgramTokenizer.resolveElements(
      tree = RecordedProgramTokenizer.buildFlatTokenListTree(renderedProgram, underlyingLexerClass),
      rangesPerElement = elements.map { element -> element.ranges.map { it.toInterval() } },
    )

    ListMinimizationMicrobenchmark(
      microbenchmarkId = microbenchmarkId,
      targetFilePath = targetFilePath,
      wholeProgramTokenCount = baseProgramTokens.size,
      inputList = RecordedInputList(elements),
      recordingContext = recordingContext,
    ).writeTo(
      stagingDirectory.resolve(ListMinimizationMicrobenchmark.MICROBENCHMARK_FILE_NAME),
    )
    // Just the id. The originating reducer is already in microbenchmark.yaml, under its qualified name;
    // repeating a simple-name copy here would be a second place to keep in step, and one that goes
    // quietly stale when a reducer is renamed. A directory name only has to be unique and to sort
    // in issue order, which the zero-padded id already does.
    val microbenchmarkDirectory = rootDirectory.resolve(microbenchmarkId)
    if (Files.exists(microbenchmarkDirectory)) {
      // A build system that declares the problem's files as outputs creates their directories
      // beforehand, down to input/; anything that already holds a file is a problem recorded under
      // this id, which must not be overwritten.
      check(
        Files.walk(microbenchmarkDirectory).use { paths ->
          paths.noneMatch { Files.isRegularFile(it) }
        },
      ) {
        "A problem is already recorded at $microbenchmarkDirectory."
      }
      FileSystemUtil.deleteRecursively(microbenchmarkDirectory)
    }
    Files.move(stagingDirectory, microbenchmarkDirectory)
    return Result(
      microbenchmarkDirectory = microbenchmarkDirectory,
      explanation = "Recorded ${elementTokenGroups.size} element(s) as problem $microbenchmarkId.",
    )
  }

  /**
   * Where each of [tokens] is: its index in that list, and its range in [renderedProgram] from
   * where the printer placed it.
   *
   * Offsets are in code points, because that is what the evaluator's lexer counts
   * (`CharStreams.fromString`); the printer reports columns in UTF-16 units. [tokens] is in program
   * order, so the conversion walks the text once with a cursor instead of recounting from the start
   * for every token.
   */
  internal fun locateTokens(
    renderedProgram: String,
    placements: TokenPlacementRecorder,
    tokens: List<AbstractPersesToken>,
  ): IdentityHashMap<AbstractPersesToken, TokenLocation> {
    val lineStartOffsets =
      ArrayList<Int>().apply {
        add(0)
        renderedProgram.forEachIndexed { index, char -> if (char == '\n') add(index + 1) }
      }
    val tokenLocationMap = IdentityHashMap<AbstractPersesToken, TokenLocation>(tokens.size)
    var cursor = 0
    var cursorInCodePoints = 0
    tokens.forEachIndexed { index, token ->
      val position =
        checkNotNull(placements.getPositionOrNull(token)) {
          "The printer did not place the token '${token.lexemeText}'."
        }
      val start = lineStartOffsets[position.line - 1] + position.charPositionInLine
      val end = start + token.lexemeText.length
      check(start >= cursor) {
        "The token '${token.lexemeText}' at $start precedes the previous token, which ends at $cursor."
      }
      check(renderedProgram.regionMatches(start, token.lexemeText, 0, token.lexemeText.length)) {
        "The printer placed '${token.lexemeText}' at $start, but the rendered program has " +
          "'${renderedProgram.substring(start, minOf(end, renderedProgram.length))}' there."
      }
      val startInCodePoints = cursorInCodePoints + renderedProgram.codePointCount(cursor, start)
      val endInCodePoints = startInCodePoints + renderedProgram.codePointCount(start, end)
      tokenLocationMap[token] =
        TokenLocation(
          indexInBaseProgram = index,
          rangeInRenderedProgram = Interval(startInCodePoints, endInCodePoints),
        )
      cursor = end
      cursorInCodePoints = endInCodePoints
    }
    return tokenLocationMap
  }

  /** Where a token of the base program is, in two coordinates. */
  data class TokenLocation(
    /** The token's position in the base program's token sequence, 0-based. */
    val indexInBaseProgram: Int,
    /** The token's character range in the rendered program, in code points. */
    val rangeInRenderedProgram: Interval,
  )

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    /** A problem folder being written; renamed to the bare id once complete. */
    const val STAGING_SUFFIX = ".incomplete"

    /**
     * Expresses each list element as character ranges into the recorded program.
     *
     * An element's tokens are grouped by their index in the base program: a run of consecutive
     * indices is one range, so an element's size on disk follows its shape, not its token count. A
     * range may span whitespace because the evaluator resolves it to the tokens it contains; it may
     * not span a token outside the element -- of another element, or of none, as with a kleene
     * node's siblings that are not in the list -- which it would swallow, and an index gap is
     * exactly such a token. The order the elements arrive in, and of the tokens within one, is
     * irrelevant to the ranges; the element order is kept, being part of the problem recorded.
     *
     * Ranges come from [tokenLocationMap] (see [locateTokens]), not from the tokens themselves: a
     * base program is the *edited* token list of a reduction in progress, so its tokens still carry
     * `startIndex`/`stopIndex` pointing into the pre-edit file.
     *
     * @param elementTokenGroups the tokens of each element, in element order. Tokens rather than
     *   tree nodes: the correspondence is between text and tokens, and taking nodes here would pull
     *   the spar tree into a computation that does not need it.
     * @param tokenLocationMap where each token of the recorded program is, keyed by identity
     */
    fun computeRecordedElements(
      elementTokenGroups: List<List<AbstractPersesToken>>,
      tokenLocationMap: IdentityHashMap<AbstractPersesToken, TokenLocation>,
    ): ImmutableList<RecordedElement> =
      elementTokenGroups.transformToImmutableList { tokens ->
        RecordedElement(ranges = computeRangesOfElement(tokens, tokenLocationMap))
      }

    private fun computeRangesOfElement(
      tokens: List<AbstractPersesToken>,
      tokenLocationMap: IdentityHashMap<AbstractPersesToken, TokenLocation>,
    ): ImmutableList<RecordedRange> {
      require(tokens.isNotEmpty()) { "An element must own at least one token." }
      val locations =
        tokens
          .map { token ->
            checkNotNull(tokenLocationMap[token]) {
              "The token '${token.lexemeText}' is not one of the recorded program's tokens."
            }
          }.sortedBy { it.indexInBaseProgram }
      return CollectionUtil
        .mergeContinuousElementsIntoRegions(locations) { previous, current ->
          current.indexInBaseProgram == previous.indexInBaseProgram + 1
        }.transformToImmutableList { run ->
          RecordedRange(
            leftInclusive = run.first().rangeInRenderedProgram.leftInclusive,
            rightExclusive = run.last().rangeInRenderedProgram.rightExclusive,
            tokenCount = run.size,
          )
        }
    }
  }
}
