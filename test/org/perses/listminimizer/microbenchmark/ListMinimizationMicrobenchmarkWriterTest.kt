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
import org.perses.program.AbstractPersesToken
import org.perses.program.EnumFormatControl
import org.perses.program.TokenizedProgram
import org.perses.program.printer.PrinterRegistry
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
    ) { inputDirectory ->
      ReductionFolder(inputs, inputDirectory)
        .computeAbsPathForOrigFile(inputs.mutableFiles.single())
        .writeText(printer.print(program).sourceCode)
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
        ) { throw OutOfMemoryError("simulated") }
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
    val tokenRangeMap = IdentityHashMap<AbstractPersesToken, Interval>()
    program.tokens.forEachIndexed { index, token ->
      val node = tree.remainingLexerRuleNodes[index]
      tokenRangeMap[token] =
        Interval(
          leftInclusive = RecordedProgramTokenizer.inclusiveStartOffsetOf(node),
          rightExclusive = RecordedProgramTokenizer.exclusiveEndOffsetOf(node),
        )
    }
    return Recorded(
      sourceCode,
      ListMinimizationMicrobenchmarkWriter.computeRecordedElements(
        elementTokenGroups = elementTokenGroups,
        tokenRangeMap = tokenRangeMap,
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

  /** Adjacent tokens collapse to one range; a gap stays a boundary. */
  @Test
  fun testTouchingTokensMergeAndGapsDoNot() {
    val program = programFrom("int x = 1;")
    val tokens = program.tokens

    val adjacent = record(program, listOf(listOf(tokens[3], tokens[4])))
    assertThat(
      adjacent.elements
        .single()
        .ranges,
    ).hasSize(1)
    assertThat(textOf(adjacent, 0)).isEqualTo("1;")

    val separated = record(program, listOf(listOf(tokens[0], tokens[4])))
    assertThat(
      separated.elements
        .single()
        .ranges,
    ).hasSize(2)
    assertThat(textOf(separated, 0)).isEqualTo("int;")
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

  // ---- relexWrittenFileForTokenRanges: the lexing fixpoint, asserted where a problem is created ----

  private fun writeProgramFile(sourceCode: String) =
    FileSystemUtil.ensureDirExists(workDir.resolve("lexed")).resolve("program.c").apply {
      writeText(printer.print(programFrom(sourceCode)).sourceCode)
    }

  @Test
  fun testEachComputedRangeSpansItsTokenInTheWrittenFile() {
    val sourceCode = "int x = 1; int yy = 22;"
    val file = writeProgramFile(sourceCode)
    val program = programFrom(sourceCode)

    val tokenRangeMap = writer().relexWrittenFileForTokenRanges(file, program.tokens)

    assertThat(tokenRangeMap).hasSize(program.tokenCount)
    val text = file.readText()
    // Keyed by the program's own tokens, so the assertion needs no parallel indexing.
    program.tokens.forEach { token ->
      val range = checkNotNull(tokenRangeMap[token])
      assertThat(text.substring(range.leftInclusive, range.rightExclusive))
        .isEqualTo(token.lexemeText)
    }
  }

  /** Distinct tokens with the same lexeme must not collide, which identity keying is what ensures. */
  @Test
  fun testTokensSharingALexemeGetTheirOwnRanges() {
    val sourceCode = "int x = 1; int y = 2;"
    val file = writeProgramFile(sourceCode)
    val program = programFrom(sourceCode)
    val intTokens = program.tokens.filter { it.lexemeText == "int" }
    assertThat(intTokens).hasSize(2)

    val tokenRangeMap = writer().relexWrittenFileForTokenRanges(file, program.tokens)

    assertThat(tokenRangeMap[intTokens[0]]).isNotEqualTo(tokenRangeMap[intTokens[1]])
  }

  /**
   * The fixpoint check. A token list that disagrees with the file cannot be evaluated later either,
   * so recording must fail here rather than leave an unusable problem in the corpus.
   */
  @Test
  fun testATokenCountDisagreeingWithTheFileIsRejected() {
    val file = writeProgramFile("int x = 1;")
    val longerProgram = programFrom("int x = 1; int y = 2;")

    val failure =
      assertThrows(IllegalStateException::class.java) {
        writer().relexWrittenFileForTokenRanges(file, longerProgram.tokens)
      }

    assertThat(failure).hasMessageThat().contains("Re-lexing the recorded program yielded")
  }

  /** Same token count, different lexemes -- the case a count comparison alone would let through. */
  @Test
  fun testALexemeDisagreeingWithTheFileIsRejected() {
    val file = writeProgramFile("int x = 1;")
    val differentProgram = programFrom("int y = 1;")

    val failure =
      assertThrows(IllegalStateException::class.java) {
        writer().relexWrittenFileForTokenRanges(file, differentProgram.tokens)
      }

    assertThat(failure).hasMessageThat().contains("Re-lexing disagrees at token 1")
  }
}
