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
import org.perses.util.AtomicSequenceGenerator
import org.perses.util.Interval
import org.perses.util.Util
import org.perses.util.transformToImmutableList
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
   * @param writeProgramFilesTo populates the given directory with the program files. The caller
   *   supplies it because rendering, and knowing which files a reduction has, belong to the reducer
   *   rather than here -- this only decides where they go
   */
  fun writeProblem(
    baseProgramTokens: List<AbstractPersesToken>,
    elementTokenGroups: List<List<AbstractPersesToken>>,
    targetFilePath: String,
    recordingContext: RecordingContext,
    writeProgramFilesTo: (Path) -> Unit,
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
    return try {
      writeProblemFolder(
        microbenchmarkId = microbenchmarkId,
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
    baseProgramTokens: List<AbstractPersesToken>,
    elementTokenGroups: List<List<AbstractPersesToken>>,
    targetFilePath: String,
    recordingContext: RecordingContext,
    writeProgramFilesTo: (Path) -> Unit,
  ): Result {
    // Just the id. The originating reducer is already in microbenchmark.yaml, under its qualified name;
    // repeating a simple-name copy here would be a second place to keep in step, and one that goes
    // quietly stale when a reducer is renamed. A directory name only has to be unique and to sort
    // in issue order, which the zero-padded id already does.
    val microbenchmarkDirectory = Util.ensureDirExists(rootDirectory.resolve(microbenchmarkId))
    val inputDirectory =
      Util.ensureDirExists(
        microbenchmarkDirectory.resolve(ListMinimizationMicrobenchmark.INPUT_FOLDER_NAME),
      )
    writeProgramFilesTo(inputDirectory)

    ListMinimizationMicrobenchmark(
      microbenchmarkId = microbenchmarkId,
      targetFilePath = targetFilePath,
      inputList =
        RecordedInputList(
          computeRecordedElements(
            elementTokenGroups = elementTokenGroups,
            tokenRangeMap =
              relexWrittenFileForTokenRanges(
                inputDirectory.resolve(targetFilePath),
                baseProgramTokens,
              ),
          ),
        ),
      recordingContext = recordingContext,
    ).writeTo(
      microbenchmarkDirectory.resolve(ListMinimizationMicrobenchmark.MICROBENCHMARK_FILE_NAME),
    )
    return Result(
      microbenchmarkDirectory = microbenchmarkDirectory,
      explanation = "Recorded ${elementTokenGroups.size} element(s) as problem $microbenchmarkId.",
    )
  }

  /**
   * Each token's range in the file just written, obtained by lexing that file with the same facade
   * the evaluation uses. Reading the offsets back out of the written text, rather than asking the
   * printer where it put things, is what makes the two halves agree by construction.
   *
   * The lexeme-by-lexeme check is the lexing fixpoint, asserted where the problem is *created*: a
   * program whose re-lex disagrees with its token list cannot be evaluated later either, so it is
   * better to fail here than to leave an unusable problem in the corpus.
   */
  internal fun relexWrittenFileForTokenRanges(
    writtenFile: Path,
    expectedTokens: List<AbstractPersesToken>,
  ): IdentityHashMap<AbstractPersesToken, Interval> {
    val tree =
      RecordedProgramTokenizer.buildFlatTokenListTree(writtenFile.readText(), underlyingLexerClass)
    val lexed = tree.remainingLexerRuleNodes
    check(lexed.size == expectedTokens.size) {
      "Re-lexing the recorded program yielded ${lexed.size} token(s), but its token list has " +
        "${expectedTokens.size}."
    }
    // Keyed by the *expected* token, not the re-lexed one: an element holds the program's own token
    // objects. IdentityHashMap rather than a plain Map because two tokens with the same lexeme are
    // distinct tokens -- and returning the concrete type says so, where a Map would not.
    val tokenRangeMap = IdentityHashMap<AbstractPersesToken, Interval>(expectedTokens.size)
    lexed.forEachIndexed { index, node ->
      check(node.token.lexemeText == expectedTokens[index].lexemeText) {
        "Re-lexing disagrees at token $index: '${node.token.lexemeText}' versus " +
          "'${expectedTokens[index].lexemeText}'."
      }
      tokenRangeMap[expectedTokens[index]] =
        Interval(
          leftInclusive = RecordedProgramTokenizer.inclusiveStartOffsetOf(node),
          rightExclusive = RecordedProgramTokenizer.exclusiveEndOffsetOf(node),
        )
    }
    return tokenRangeMap
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()

    /**
     * Expresses each list element as character ranges into the recorded program, given the range of
     * each of that program's tokens.
     *
     * Those token ranges come from lexing the file that was written, which is the same source of
     * offsets the evaluation side uses -- so the two halves agree by construction rather than by two
     * conventions being kept in step. Offsets cannot be taken from the tokens themselves: a base
     * program is the *edited* token list of a reduction in progress, so its tokens still carry
     * `startIndex`/`stopIndex` pointing into the pre-edit file.
     *
     * @param elementTokenGroups the tokens of each element, in element order. Tokens rather than
     *   tree nodes: the correspondence is between text and tokens, and taking nodes here would pull
     *   the spar tree into a computation that does not need it.
     * @param tokenRangeMap the range of each of the recorded program's tokens, keyed by identity
     */
    fun computeRecordedElements(
      elementTokenGroups: List<List<AbstractPersesToken>>,
      tokenRangeMap: IdentityHashMap<AbstractPersesToken, Interval>,
    ): ImmutableList<RecordedElement> =
      elementTokenGroups.transformToImmutableList { tokens ->
        RecordedElement(computeRangesOfElement(tokens, tokenRangeMap))
      }

    private fun computeRangesOfElement(
      tokens: List<AbstractPersesToken>,
      tokenRangeMap: IdentityHashMap<AbstractPersesToken, Interval>,
    ): ImmutableList<Interval> {
      require(tokens.isNotEmpty()) { "An element must own at least one token." }
      val sorted =
        tokens
          .map { token ->
            checkNotNull(tokenRangeMap[token]) {
              "The token '${token.lexemeText}' is not one of the recorded program's tokens."
            }
          }.sortedBy { it.leftInclusive }
      return mergeTouchingRanges(sorted)
    }

    /**
     * Merges only ranges that touch, so a run of adjacent tokens becomes one range while a gap --
     * the inter-token whitespace of a non-contiguous element -- stays a boundary. Both forms
     * resolve, but merging keeps a recording readable and its range count proportional to the
     * element's shape rather than to its token count.
     */
    private fun mergeTouchingRanges(sorted: List<Interval>): ImmutableList<Interval> =
      Util
        .mergeContinuousElementsIntoRegions(sorted) { previous, current ->
          previous.rightExclusive == current.leftInclusive
        }.transformToImmutableList { run ->
          Interval(
            leftInclusive = run.first().leftInclusive,
            rightExclusive = run.last().rightExclusive,
          )
        }
  }
}
