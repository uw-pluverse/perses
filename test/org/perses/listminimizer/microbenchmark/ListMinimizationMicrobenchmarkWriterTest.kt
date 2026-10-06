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
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.SingleParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.grammar.c.LanguageC
import org.perses.grammar.c.PnfCLexer
import org.perses.grammar.line.LineParserFacade
import org.perses.listminimizer.microbenchmark.ListMinimizationMicrobenchmarkWriter.TokenLocation
import org.perses.program.AbstractPersesToken
import org.perses.program.EnumFormatControl
import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
import org.perses.program.printer.TokenPlacementRecorder
import org.perses.reduction.io.DefaultLanguageOriginalReductionInputs
import org.perses.reduction.io.ReductionFolder
import org.perses.util.AtomicSequenceGenerator
import org.perses.util.FileSystemUtil
import org.perses.util.Interval
import org.perses.util.shell.Shells
import java.nio.file.Files
import java.util.IdentityHashMap
import kotlin.io.path.createFile
import kotlin.io.path.deleteRecursively
import kotlin.io.path.readText
import kotlin.io.path.writeText

/** As AbstractMain renders it onto the reduction start event: the options as YAML. */
private const val COMMAND_LINE_OPTIONS = "alg: \"token_slicer\"\nthreads: \"1\"\n"

@RunWith(JUnit4::class)
class ListMinimizationMicrobenchmarkWriterTest {
  private val workDir = FileSystemUtil.createTempDirForObject(this)

  private val inputDir = FileSystemUtil.ensureDirExists(workDir.resolve("input_dir"))

  private val sourceFile =
    inputDir.resolve("small.c").apply {
      createFile()
      writeText("int aaa; int bbb;")
    }

  private val scriptFile =
    inputDir.resolve("r.sh").apply {
      createFile()
      FileSystemUtil.setExecutable(this)
      writeText(
        """
        |${Shells.SHEBANG_BASH}
        |grep "aaa" small.c
        |
        """.trimMargin(),
      )
    }

  private val facadeFactory = builderWithBuiltinLanguages().build()

  private val inputs =
    DefaultLanguageOriginalReductionInputs.create(
      testScriptPath = scriptFile,
      sourceFilePaths = ImmutableList.of(sourceFile),
      dependencyFiles = ImmutableList.of(),
    ) {
      facadeFactory.computeLanguageKindOrThrow(it)
    }

  private val printer = PrinterRegistry.getPrinter(EnumFormatControl.ORIG_FORMAT)

  private val recordingContext =
    RecordingContext(
      languageName = "c",
      parserFacadeClassName = "org.perses.grammar.c.CParserFacade",
      reducerClassName = "TokenSlicer",
      minimizerType = "WINDOWED_SLICER",
      contextDescription = "ReducingAllTokens",
      fixpointIteration = 1,
      commandLineOptions = COMMAND_LINE_OPTIONS,
    )

  @After
  fun teardown() {
    workDir.deleteRecursively()
  }

  private fun writer(
    minListSizeToRecord: Int = 1,
    maxMicrobenchmarksToRecord: Int? = null,
  ) = ListMinimizationMicrobenchmarkWriter(
    rootDirectory = FileSystemUtil.ensureDirExists(workDir.resolve("microbenchmarks")),
    underlyingLexerClass = PnfCLexer::class.java,
    minListSizeToRecord = minListSizeToRecord,
    maxMicrobenchmarksToRecord = maxMicrobenchmarksToRecord,
    microbenchmarkIdGenerator = AtomicSequenceGenerator(start = 0, minLengthForPadding = 6),
    commandLineOptions = COMMAND_LINE_OPTIONS,
  )

  private fun program(): TokenizedProgram =
    TestUtility.createTokenizedProgramFromString(sourceFile.readText(), LanguageC)

  /** The program as the line slicer's tree holds it: one token per line. */
  private fun lineProgram(sourceCode: String): TokenizedProgram =
    RecordedProgramTokenizer
      .buildFlatTokenListTree(sourceCode, LineParserFacade().lexerClass)
      .programSnapshot
      .payload

  private fun write(
    writer: ListMinimizationMicrobenchmarkWriter,
    program: TokenizedProgram = program(),
    elementTokenGroups: List<List<AbstractPersesToken>> = program.tokens.map { listOf(it) },
  ): ListMinimizationMicrobenchmarkWriter.Result =
    writer.writeProblem(
      baseProgramTokens = program.tokens,
      elementTokenGroups = elementTokenGroups,
      targetFilePath = sourceFile.fileName.toString(),
      recordingContext = recordingContext,
    ) { inputDirectory, listener ->
      ReductionFolder(inputs, inputDirectory)
        .computeAbsPathForOrigFile(inputs.mutableFiles.single())
        .writeText(printer.print(program, listener).sourceCode)
    }

  @Test
  fun testWritesProblemYamlBesideARunnableInputFolder() {
    val microbenchmarkDirectory = checkNotNull(write(writer()).microbenchmarkDirectory)

    val inputFolder =
      microbenchmarkDirectory.resolve(
        ListMinimizationMicrobenchmark.INPUT_FOLDER_NAME,
      )
    assertThat(Files.isDirectory(inputFolder)).isTrue()
    assertThat(Files.isRegularFile(inputFolder.resolve("r.sh"))).isTrue()
    assertThat(Files.isRegularFile(inputFolder.resolve("small.c"))).isTrue()

    // Metadata must sit outside input/, or --input would treat it as a file to reduce.
    val microbenchmarkFile =
      microbenchmarkDirectory.resolve(
        ListMinimizationMicrobenchmark.MICROBENCHMARK_FILE_NAME,
      )
    assertThat(Files.isRegularFile(microbenchmarkFile)).isTrue()
    assertThat(
      Files.exists(inputFolder.resolve(ListMinimizationMicrobenchmark.MICROBENCHMARK_FILE_NAME)),
    ).isFalse()
  }

  /** The recorded test script must still accept the recorded program, or the microbenchmark is unusable. */
  @Test
  fun testTheRecordedInputFolderPassesItsOwnTestScript() {
    val microbenchmarkDirectory = checkNotNull(write(writer()).microbenchmarkDirectory)
    val inputFolder =
      microbenchmarkDirectory.resolve(
        ListMinimizationMicrobenchmark.INPUT_FOLDER_NAME,
      )

    val result =
      Shells.defaultSingleton.run(
        cmd = "${Shells.SHEBANG_BASH.removePrefix("#!")} r.sh",
        workingDirectory = inputFolder,
        captureOutput = false,
      )

    assertThat(result.exitCode.isZero()).isTrue()
  }

  /**
   * The gate for recording: the ranges written must resolve, against the program that was written
   * beside them, back to the tokens they describe. A recording that fails this is silently useless.
   */
  @Test
  fun testRecordedRangesResolveAgainstTheRecordedProgram() {
    val microbenchmarkDirectory = checkNotNull(write(writer()).microbenchmarkDirectory)
    val microbenchmark =
      ListMinimizationMicrobenchmark.readFrom(
        microbenchmarkDirectory.resolve(ListMinimizationMicrobenchmark.MICROBENCHMARK_FILE_NAME),
      )
    val recordedProgramText =
      microbenchmarkDirectory
        .resolve(ListMinimizationMicrobenchmark.INPUT_FOLDER_NAME)
        .resolve(microbenchmark.targetFilePath)
        .readText()

    val tree =
      RecordedProgramTokenizer.buildFlatTokenListTree(recordedProgramText, PnfCLexer::class.java)
    val resolved =
      RecordedProgramTokenizer.resolveElements(
        tree,
        microbenchmark.inputList.elements.map { it.ranges },
      )

    assertThat(resolved).hasSize(microbenchmark.inputList.elementCount)
    assertThat(resolved.flatten().joinToString(separator = " ") { it.token.lexemeText })
      .isEqualTo("int aaa ; int bbb ;")
  }

  /** The explanation is what distinguishes this skip from a cap skip or a failure. */
  @Test
  fun testAListShorterThanTheThresholdIsSkipped() {
    val result = write(writer(minListSizeToRecord = 100))

    assertThat(result.microbenchmarkDirectory).isNull()
    assertThat(result.explanation).contains("fewer than the 100 required")
    assertThat(writer(minListSizeToRecord = 100).recordedProblemCount).isEqualTo(0)
  }

  @Test
  fun testRecordingStopsAtTheCap() {
    val writer = writer(maxMicrobenchmarksToRecord = 2)

    assertThat(write(writer).microbenchmarkDirectory).isNotNull()
    assertThat(write(writer).microbenchmarkDirectory).isNotNull()

    val refused = write(writer)
    assertThat(refused.microbenchmarkDirectory).isNull()
    assertThat(refused.explanation).contains("cap of 2")
    assertThat(writer.recordedProblemCount).isEqualTo(2)
  }

  /** Drivers share one generator, so a second writer continues the sequence rather than restarting. */
  @Test
  fun testWritersSharingAGeneratorDoNotCollide() {
    val shared = AtomicSequenceGenerator(start = 0, minLengthForPadding = 6)
    val rootDirectory = FileSystemUtil.ensureDirExists(workDir.resolve("microbenchmarks"))

    fun writerSharing() =
      ListMinimizationMicrobenchmarkWriter(
        rootDirectory = rootDirectory,
        underlyingLexerClass = PnfCLexer::class.java,
        minListSizeToRecord = 1,
        maxMicrobenchmarksToRecord = null,
        microbenchmarkIdGenerator = shared,
        commandLineOptions = COMMAND_LINE_OPTIONS,
      )

    val first = checkNotNull(write(writerSharing()).microbenchmarkDirectory)
    val second = checkNotNull(write(writerSharing()).microbenchmarkDirectory)

    assertThat(first.fileName.toString()).isNotEqualTo(second.fileName.toString())
    assertThat(shared.issuedCount).isEqualTo(2)
  }

  @Test
  fun testProblemIdsAreDistinctAndSortChronologically() {
    val writer = writer()
    val first = checkNotNull(write(writer).microbenchmarkDirectory)
    val second = checkNotNull(write(writer).microbenchmarkDirectory)

    assertThat(first.fileName.toString()).isLessThan(second.fileName.toString())
    // Zero-padded, so a lexical sort of a corpus is also the order the problems were issued in.
    assertThat(first.fileName.toString()).isEqualTo("000000")
    assertThat(second.fileName.toString()).isEqualTo("000001")
  }

  /**
   * Recording runs inside a live reduction, so a problem it cannot express must be dropped rather
   * than allowed to abort a run that is otherwise producing a useful corpus.
   *
   * Paired with [testAnErrorIsNotTreatedAsAnUnrecordableProblem]: the two together pin *where* the
   * boundary sits, which the skip case alone does not.
   */
  @Test
  fun testAProblemThatCannotBeRecordedIsSkippedRatherThanThrowing() {
    val writer = writer()
    val program = program()

    // An element owning no tokens cannot be expressed as ranges.
    val recorded =
      write(
        writer,
        program,
        elementTokenGroups = program.tokens.map { listOf(it) } + listOf(emptyList()),
      )

    assertThat(recorded.microbenchmarkDirectory).isNull()
    assertThat(recorded.explanation).contains("could not be recorded")
    assertThat(Files.list(workDir.resolve("microbenchmarks")).use { it.toList() }).isEmpty()
  }

  /**
   * A reducer on a surrogate tree hands over tokens the language's lexer cannot reproduce -- the
   * line slicer's are whole lines -- so their ranges come from where the printer placed them, and
   * a line is recorded as one range that the evaluator resolves to the real tokens inside it.
   */
  @Test
  fun testLineTokensAreRecordedAsLineRanges() {
    sourceFile.writeText("int aaa;\nint bbb;\n")
    val lines = lineProgram(sourceFile.readText())
    assertThat(lines.tokens.map { it.lexemeText }).containsExactly("int aaa;", "int bbb;").inOrder()

    val microbenchmarkDirectory =
      checkNotNull(write(writer(), lines, lines.tokens.map { listOf(it) }).microbenchmarkDirectory)

    val microbenchmark =
      ListMinimizationMicrobenchmark.readFrom(
        microbenchmarkDirectory.resolve(ListMinimizationMicrobenchmark.MICROBENCHMARK_FILE_NAME),
      )
    assertThat(microbenchmark.inputList.elements.map { it.ranges.single() })
      .containsExactly(Interval(0, 8), Interval(9, 17))
      .inOrder()
    // Counted as the reducer tokenized the program: one line is one token.
    assertThat(microbenchmark.wholeProgramTokenCount).isEqualTo(2)
    assertThat(microbenchmark.inputList.elements.map { it.tokenCount }).containsExactly(1, 1)
    val recordedProgramText =
      microbenchmarkDirectory
        .resolve(ListMinimizationMicrobenchmark.INPUT_FOLDER_NAME)
        .resolve(microbenchmark.targetFilePath)
        .readText()
    val resolved =
      RecordedProgramTokenizer.resolveElements(
        RecordedProgramTokenizer.buildFlatTokenListTree(recordedProgramText, PnfCLexer::class.java),
        microbenchmark.inputList.elements.map { it.ranges },
      )
    assertThat(resolved.map { element -> element.joinToString(" ") { it.token.lexemeText } })
      .containsExactly("int aaa ;", "int bbb ;")
      .inOrder()
  }

  @Test
  fun testALineCuttingThroughARealTokenIsSkippedAndLeavesNothing() {
    // The first line ends inside a block comment, so its range ends inside a token of the C lexer.
    sourceFile.writeText("int aaa; /* x\n y */ int bbb;\n")
    val lines = lineProgram(sourceFile.readText())
    assertThat(lines.tokens).hasSize(2)

    val recorded = write(writer(), lines, lines.tokens.map { listOf(it) })

    assertThat(recorded.microbenchmarkDirectory).isNull()
    assertThat(recorded.explanation).contains("does not end at a token boundary")
    assertThat(Files.list(workDir.resolve("microbenchmarks")).use { it.toList() }).isEmpty()
  }

  /**
   * An Error means the JVM is in trouble, not that this problem is unrecordable. Reporting it as a
   * skipped recording would let the reduction carry on in whatever state produced it.
   */
  @Test
  fun testAnErrorIsNotTreatedAsAnUnrecordableProblem() {
    val program = program()

    val thrown =
      assertThrows(OutOfMemoryError::class.java) {
        writer().writeProblem(
          baseProgramTokens = program.tokens,
          elementTokenGroups = program.tokens.map { listOf(it) },
          targetFilePath = sourceFile.fileName.toString(),
          recordingContext = recordingContext,
        ) { _, _ -> throw OutOfMemoryError("simulated") }
      }

    assertThat(thrown).hasMessageThat().isEqualTo("simulated")
  }

  // ---- computeRecordedElements: the range mapping, exercised without touching the filesystem ----

  private fun programFrom(sourceCode: String) =
    TestUtility.createTokenizedProgramFromString(sourceCode, LanguageC)

  /** Each token as its own element, which is the shape the token slicer produces. */
  private fun eachTokenSeparately(program: TokenizedProgram) = program.tokens.map { listOf(it) }

  private class Recorded(
    val sourceCode: String,
    val elements: List<RecordedElement>,
  )

  /**
   * Prints the program, lexes the printed text back, and records against those token ranges -- the
   * same write-then-lex order production uses, so both sides read offsets from the same text.
   */
  private fun record(
    program: TokenizedProgram,
    elementTokenGroups: List<List<AbstractPersesToken>>,
  ): Recorded {
    val sourceCode = printer.print(program).sourceCode
    val tree = RecordedProgramTokenizer.buildFlatTokenListTree(sourceCode, PnfCLexer::class.java)
    val tokenLocationMap = IdentityHashMap<AbstractPersesToken, TokenLocation>()
    program.tokens.forEachIndexed { index, token ->
      val node = tree.remainingLexerRuleNodes[index]
      tokenLocationMap[token] =
        TokenLocation(
          indexInBaseProgram = index,
          rangeInRenderedProgram =
            Interval(
              leftInclusive = RecordedProgramTokenizer.inclusiveStartOffsetOf(node),
              rightExclusive = RecordedProgramTokenizer.exclusiveEndOffsetOf(node),
            ),
        )
    }
    return Recorded(
      sourceCode,
      ListMinimizationMicrobenchmarkWriter.computeRecordedElements(
        elementTokenGroups = elementTokenGroups,
        tokenLocationMap = tokenLocationMap,
      ),
    )
  }

  private fun textOf(
    recorded: Recorded,
    elementIndex: Int,
  ) = recorded.elements[elementIndex]
    .ranges
    .joinToString(separator = "") {
      recorded.sourceCode.substring(it.leftInclusive, it.rightExclusive)
    }

  @Test
  fun testRangesCoverExactlyTheElementText() {
    val program = programFrom("int x = 1;")
    val recorded = record(program, eachTokenSeparately(program))

    // The recorded source is the printer's output, which terminates the final line.
    assertThat(recorded.sourceCode).isEqualTo("int x = 1;\n")
    assertThat(recorded.elements).hasSize(5)
    assertThat((0 until 5).map { textOf(recorded, it) })
      .containsExactly("int", "x", "=", "1", ";")
      .inOrder()
  }

  @Test
  fun testOffsetsAreCorrectAcrossLines() {
    val sourceCode =
      """
      |int main(void) {
      |  return 0;
      |}
      |
      """.trimMargin()
    val program = programFrom(sourceCode)
    val recorded = record(program, eachTokenSeparately(program))

    // "return" sits on the second line; a mishandled line base would shift it.
    val returnIndex = program.tokens.indexOfFirst { it.lexemeText == "return" }
    assertThat(textOf(recorded, returnIndex)).isEqualTo("return")
    assertThat(
      recorded.elements[returnIndex]
        .ranges
        .single()
        .leftInclusive,
    ).isEqualTo(sourceCode.indexOf("return"))
  }

  /**
   * Consecutive tokens collapse to one range, spaced or not. A token between them that is not the
   * element's -- here one in no element at all -- splits it: a range spanning it would resolve to
   * it too.
   */
  @Test
  fun testConsecutiveTokensMergeAcrossWhitespaceButNotAcrossTokensOutsideTheElement() {
    val program = programFrom("int x = 1;")
    val tokens = program.tokens

    val touching = record(program, listOf(listOf(tokens[3], tokens[4])))
    assertThat(touching.elements.single().ranges).hasSize(1)
    assertThat(textOf(touching, 0)).isEqualTo("1;")

    val spaced = record(program, listOf(listOf(tokens[0], tokens[1], tokens[2])))
    assertThat(spaced.elements.single().ranges).hasSize(1)
    assertThat(textOf(spaced, 0)).isEqualTo("int x =")
    assertThat(spaced.elements.single().tokenCount).isEqualTo(3)

    val interrupted = record(program, listOf(listOf(tokens[0], tokens[4])))
    assertThat(interrupted.elements.single().ranges).hasSize(2)
    assertThat(textOf(interrupted, 0)).isEqualTo("int;")
  }

  /**
   * A minimizer such as ProbDD hands the elements over shuffled. Adjacency is a property of the
   * program, so each element's tokens still merge, and the elements keep the order the list had.
   */
  @Test
  fun testShuffledElementsStillMergeTheirAdjacentTokensAndKeepListOrder() {
    val program = programFrom("int x = 1;")
    val tokens = program.tokens

    val recorded =
      record(program, listOf(listOf(tokens[4], tokens[3]), listOf(tokens[1], tokens[0])))

    assertThat(recorded.elements.map { it.ranges.size }).containsExactly(1, 1).inOrder()
    assertThat((0 until 2).map { textOf(recorded, it) }).containsExactly("1;", "int x").inOrder()
  }

  @Test
  fun testRangesAreSortedRegardlessOfTokenOrderGiven() {
    val program = programFrom("int x = 1;")
    val tokens = program.tokens

    val recorded = record(program, listOf(listOf(tokens[4], tokens[0])))

    assertThat(
      recorded.elements
        .single()
        .ranges
        .map { it.leftInclusive },
    ).isInOrder()
  }

  @Test
  fun testAnElementWithNoTokensIsRejected() {
    val program = programFrom("int x = 1;")

    assertThrows(IllegalArgumentException::class.java) {
      record(program, listOf(emptyList()))
    }
  }

  /**
   * The gate for this step: ranges produced by the recorder must resolve, through the evaluation's
   * own tokenizer, back to the very tokens they were derived from. The two halves are checked
   * against each other rather than each against its own convention, so a shared misunderstanding of
   * offsets cannot pass.
   */
  @Test
  fun testRecordedRangesResolveBackToTheSameTokens() {
    assertRoundTrip("int x = 1; int y = 2;")
    assertRoundTrip(
      """
      |int main(void) {
      |  int x = 1;
      |
      |  return x;
      |}
      |
      """.trimMargin(),
    )
  }

  /** The same round trip over real programs, where the awkward cases actually occur. */
  @Test
  fun testRoundTripOverRealCPrograms() {
    val files = TestUtility.gccTestFiles.take(REAL_PROGRAM_SAMPLE_SIZE)
    assertThat(files).isNotEmpty()

    files.forEach { assertRoundTrip(it.readText()) }
  }

  private fun assertRoundTrip(rawSourceCode: String) {
    val program = programFrom(rawSourceCode)
    val recorded = record(program, eachTokenSeparately(program))

    val tree =
      RecordedProgramTokenizer.buildFlatTokenListTree(recorded.sourceCode, PnfCLexer::class.java)
    val resolved =
      RecordedProgramTokenizer.resolveElements(tree, recorded.elements.map { it.ranges })

    assertThat(resolved).hasSize(program.tokenCount)
    resolved.forEachIndexed { index, nodes ->
      assertThat(nodes.joinToString(separator = "") { it.token.lexemeText })
        .isEqualTo(program.tokens[index].lexemeText)
    }
  }

  private companion object {
    const val REAL_PROGRAM_SAMPLE_SIZE = 25
  }

  // ---- locateTokens: each token's range in the rendered program, from the printer ----

  private fun locate(
    sourceCode: String,
  ): Pair<TokenizedProgram, IdentityHashMap<AbstractPersesToken, TokenLocation>> {
    val program = programFrom(sourceCode)
    val placements = TokenPlacementRecorder()
    val text = printer.print(program, placements).sourceCode
    return program to writer().locateTokens(text, placements, program.tokens)
  }

  @Test
  fun testEachComputedRangeSpansItsTokenInTheRenderedProgram() {
    val sourceCode = "int x = 1; int yy = 22;"
    val (program, tokenLocationMap) = locate(sourceCode)

    assertThat(tokenLocationMap).hasSize(program.tokenCount)
    val text = printer.print(program).sourceCode
    // Keyed by the program's own tokens, so the assertion needs no parallel indexing.
    program.tokens.forEach { token ->
      val range = checkNotNull(tokenLocationMap[token]).rangeInRenderedProgram
      assertThat(text.substring(range.leftInclusive, range.rightExclusive))
        .isEqualTo(token.lexemeText)
    }
  }

  /** Distinct tokens with the same lexeme must not collide, which identity keying is what ensures. */
  @Test
  fun testTokensSharingALexemeGetTheirOwnRanges() {
    val (program, tokenLocationMap) = locate("int x = 1; int y = 2;")
    val intTokens = program.tokens.filter { it.lexemeText == "int" }
    assertThat(intTokens).hasSize(2)

    assertThat(tokenLocationMap[intTokens[0]]).isNotEqualTo(tokenLocationMap[intTokens[1]])
  }

  @Test
  fun testRangesAreCountedInCodePointsLikeTheLexer() {
    // The lexer indexes code points; a non-BMP character before a token must not shift its range.
    val sourceCode = "int x = 1; /* \uD83D\uDE00 */ int y = 2;"
    val (program, tokenLocationMap) = locate(sourceCode)
    val text = printer.print(program).sourceCode
    val yToken = program.tokens.single { it.lexemeText == "y" }
    val range = checkNotNull(tokenLocationMap[yToken]).rangeInRenderedProgram

    assertThat(text.codePointCount(0, text.indexOf(" y ") + 1)).isEqualTo(range.leftInclusive)
    assertThat(range.rightExclusive - range.leftInclusive).isEqualTo(1)
  }

  @Test
  fun testATokenThePrinterDidNotPlaceIsRejected() {
    val program = programFrom("int x = 1;")
    val placements = TokenPlacementRecorder()
    val text = printer.print(program, placements).sourceCode
    val longerProgram = programFrom("int x = 1; int y = 2;")

    val failure =
      assertThrows(IllegalStateException::class.java) {
        writer().locateTokens(text, placements, longerProgram.tokens)
      }

    assertThat(failure).hasMessageThat().contains("did not place the token")
  }
}
