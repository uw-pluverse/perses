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
package org.perses.fuzzer.rust

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compilers.DefaultCompilationConfigurationFacade
import org.perses.fuzzer.compilers.rust.RustcCrashDetector
import org.perses.fuzzer.config.CmdFlags
import org.perses.fuzzer.config.ProgramUnderTest
import org.perses.fuzzer.config.SeedFolder
import org.perses.fuzzer.config.TestingConfiguration
import org.perses.grammar.SingleParserFacadeFactory
import org.perses.util.shell.CmdOutput
import org.perses.util.shell.ExitCode
import org.perses.util.shell.ShellOutputLines
import java.io.File
import java.nio.file.Files
import java.nio.file.Paths
import kotlin.io.path.readLines

@RunWith(JUnit4::class)
class RustcCrashDetectorTest {

  private val detector = RustcCrashDetector()
  private val parserFacadeFactory = SingleParserFacadeFactory.builderWithBuiltinLanguages().build()
  private var workingDir: File? = null

  private val packagePath = "kitten/test/" +
    this::class.java.`package`.name.replace('.', '/') + "/"

  @Before
  fun setup() {
    workingDir = Files.createTempDirectory(javaClass.simpleName).toFile()
  }

  @After
  fun teardown() {
    workingDir!!.deleteRecursively()
    workingDir = null
  }

  @Test
  fun testWith_rustc_mock_1() {
    val rustc = File("$packagePath/rustc_mock_1.sh").absolutePath
    testWithMockRustc(rustc, 3)
  }

  @Test
  fun testWith_rustc_mock_2() {
    val rustc = File("$packagePath/rustc_mock_2.sh").absolutePath
    testWithMockRustc(rustc, 6)
  }

  private fun testWithMockRustc(rustc: String, numOfLinesInCrashSignature: Int) {
    val testingConfiguration = TestingConfiguration(
      language = "RUST",
      seedFolders = listOf(
        SeedFolder(
          path = File(workingDir, "seed_folder").apply {
            check(mkdirs())
          }.absolutePath,
          fileExtentions = listOf(".rs"),
        ),
      ),
      programsUnderTest = listOf(
        ProgramUnderTest(
          command = rustc,
          flagsToTest = listOf(CmdFlags.EMPTY),
          versionFlags = CmdFlags(listOf("--version", "--verbose")),
          crashDetectorClassName = RustcCrashDetector::class.java.canonicalName,
        ),
      ),
    )
    val facade = DefaultCompilationConfigurationFacade(
      languageKind = parserFacadeFactory.computeLanguageKindWithLanguageNameIgnoreCase(
        testingConfiguration.language,
      )!!,
      programUnderTest = testingConfiguration.programsUnderTest[0],
    )
    val action = facade.compilationActions[0]
    val sourceFile = File(workingDir, "t.rs").apply { check(createNewFile()) }
    val actionOutput = action.compile(sourceFile)
    val detectCrash = detector.detectCrash(actionOutput.cmdOutput)
    assertThat(detectCrash.isCrashDetected()).isTrue()
    assertThat(detectCrash.asCrash().signature.elements).hasSize(numOfLinesInCrashSignature)
  }

  @Test
  fun testNoCrashForExitCodeZero() {
    val cmdOutput = CmdOutput(
      exitCode = ExitCode.ZERO,
      stdout = ShellOutputLines.EMPTY,
      stderr = ShellOutputLines.EMPTY,
    )
    val result = detector.detectCrash(cmdOutput)
    assertThat(result.isCrashDetected()).isFalse()
  }

  @Test
  fun testNoCrashForExitCodeNonzero() {
    val cmdOutput = CmdOutput(
      exitCode = ExitCode.ONE,
      stdout = ShellOutputLines.EMPTY,
      stderr = ShellOutputLines.EMPTY,
    )
    val result = detector.detectCrash(cmdOutput)
    assertThat(result.isCrashDetected()).isFalse()
  }

  @Test
  fun test_detectCrashForPanic() {
    val msg = "thread 'rustc' panicked "
    val cmdout = CmdOutput(
      exitCode = ExitCode.ONE,
      stdout = ShellOutputLines.EMPTY,
      // TODO(gaosen): a real crash message from rustc.
      stderr = ShellOutputLines(ImmutableList.of(msg)),
    )
    assertThat(msg.matches(RustcCrashDetector.GENERAL_PANIC_PATTERN)).isTrue()
    val result = detector.detectCrash(cmdout)
    assertThat(result.isCrashDetected()).isTrue()
    assertThat(result.asCrash().signature.elements).containsExactly("thread 'rustc' panicked")
  }

  @Test
  fun testDetectCrashForSegmentationFault() {
    val cmdOut = CmdOutput(
      exitCode = ExitCode.ONE,
      stdout = ShellOutputLines.EMPTY,
      stderr = ShellOutputLines(ImmutableList.of("internal compiler error:")),
    )
    val result = detector.detectCrash(cmdOut)
    assertThat(result.isCrashDetected()).isTrue()
    assertThat(result.asCrash().signature.elements)
      .containsExactly("internal compiler error:")
  }

  @Test
  fun testDetectCrashForKeywordCrash() {
    val cmdOut = CmdOutput(

      exitCode = ExitCode.ONE,
      stdout = ShellOutputLines.EMPTY,
      stderr = ShellOutputLines(
        ImmutableList.of("the compiler unexpectedly panicked. this is a bug."),
      ),

    )
    val result = detector.detectCrash(cmdOut)
    assertThat(result.isCrashDetected()).isTrue()
    assertThat(result.asCrash().signature.elements)
      .containsExactly("the compiler unexpectedly panicked. this is a bug.")
  }

  @Test
  fun testDetectRealCrashOutput2() {
    val cmdOut = CmdOutput(
      exitCode = ExitCode(100),
      stdout = ShellOutputLines.EMPTY,
      stderr = ShellOutputLines(
        ImmutableList.copyOf(
          File("$packagePath/crashoutput/crash_output_2.txt")
            .readLines(),
        ),
      ),
    )
    val result = detector.detectCrash(cmdOut)
    assertThat(result.isCrashDetected()).isTrue()
    assertThat(result.asCrash().signature.elements).containsExactly(
      "thread 'rustc' panicked at 'cannot use the `#[rustc_if_this_changed]` " +
        "or `#[rustc_then_this_would_need]` annotations " +
        "without supplying `-Z query-dep-graph`'",
      "error: internal compiler error: unexpected panic",
      "note: the compiler unexpectedly panicked. this is a bug.",
      "thread '<unnamed>' panicked at 'assertion failed: `(left == right)`",
      "left: `LLVMing`",
      "right: `Codegenning`'",
    ).inOrder()
  }

  @Test
  fun testNonCrashOutput() {
    val stderr = File(
      "$packagePath/crashoutput/non_crash_output.txt",
    ).readText()
    val result = detector.detectCrash(stderr, 1)
    assertThat(result.isCrashDetected()).isFalse()
  }

  @Test
  fun testICEMessageWithFilePath() {
    (
      "error: internal compiler error: " +
        "compiler/rustc_typeck/src/collect/type_of.rs:115:26: " +
        "unexpected anon const res PrimTy(Uint(Usize)) in path: " +
        "Path { span: mutant.rs:7:9: 7:23 (#0), " +
        "res: PrimTy(Uint(Usize)), " +
        "segments: [PathSegment " +
        "{ ident: usize#0, hir_id: " +
        "Some(HirId { owner: DefId(0:3 ~ mutant[8787]::main), local_id: 57 }), " +
        "res: Some(Err), args: Some(GenericArgs { args: [Const(ConstArg { value: " +
        "AnonConst { hir_id: HirId { owner: DefId(0:3 ~ mutant[8787]::main), local_id: 54 }, " +
        "body: BodyId { hir_id: HirId { owner: DefId(0:3 ~ mutant[8787]::main), " +
        "local_id: 56 } } }, span: mutant.rs:7:17: 7:21 (#0) })], bindings: [], " +
        "parenthesized: false }), infer_args: false }] }"
      ).let {
      val result = detector.detectCrash(it, 1)
      assertThat(result.isCrashDetected()).isTrue()
      val signature = result.asCrash().signature.elements
      assertThat(signature).hasSize(1)
      assertThat(signature[0])
        .isEqualTo("error: internal compiler error: compiler/rustc_typeck/src/collect/type_of.rs")
    }
    ("error: internal compiler error: unexpected panic").let {
      val result = detector.detectCrash(it, 1)
      assertThat(result.isCrashDetected()).isTrue()
      val signature = result.asCrash().signature.elements
      assertThat(signature).hasSize(1)
      assertThat(signature[0])
        .isEqualTo("error: internal compiler error: unexpected panic")
    }
  }

  @Test
  fun testPanicMessageWithFilePath() {
    (
      "thread 'rustc' panicked at 'Box<Any>', " +
        "/rustc/e160e5cb80652bc2afe74cb3affbe35b74243ea9/compiler/rustc_errors/src/lib.rs:891:9"
      ).let {
      val result = detector.detectCrash(it, 1)
      assertThat(result.isCrashDetected()).isTrue()
      val signature = result.asCrash().signature.elements
      assertThat(signature).contains("thread 'rustc' panicked at 'Box<Any>'")
    }
    (
      "thread 'rustc' panicked at 'assertion failed: !bounds.has_escaping_bound_vars()', " +
        "compiler/rustc_typeck/src/check/method/mod.rs:388:9"
      ).let {
      val result = detector.detectCrash(it, 1)
      assertThat(result.isCrashDetected()).isTrue()
      val signature = result.asCrash().signature.elements
      assertThat(signature).hasSize(1)
      assertThat(signature[0])
        .isEqualTo(
          "thread 'rustc' panicked at 'assertion failed: " +
            "!bounds.has_escaping_bound_vars()'",
        )
    }
    (
      "thread 'rustc' panicked at 'index out of bounds: the len is 0 but the index is 0', " +
        "compiler/rustc_middle/src/ty/mod.rs:908:14"
      ).let {
      val result = detector.detectCrash(it, 1)
      assertThat(result.isCrashDetected()).isTrue()
      val signature = result.asCrash().signature.elements
      assertThat(signature).hasSize(1)
      assertThat(signature[0])
        .isEqualTo(
          "thread 'rustc' panicked at 'index out of bounds: " +
            "the len is 0 but the index is 0'",
        )
    }
    (
      "thread 'rustc' panicked at 'called `Result::unwrap()` on an `Err` value: " +
        "Custom { kind: Other, error: \"No such file or directory\" }', " +
        "/rustc/a9cd294cf2775441e713c7ee2918b728733b99f5/compiler/" +
        "rustc_codegen_ssa/src/back/link.rs:434:10"
      ).let {
      val result = detector.detectCrash(it, 1)
      assertThat(result.isCrashDetected()).isTrue()
      val signature = result.asCrash().signature.elements
      assertThat(signature).hasSize(1)
      assertThat(signature[0])
        .isEqualTo(
          "thread 'rustc' panicked at 'called `Result::unwrap()` " +
            "on an `Err` value: Custom { kind: Other",
        )
    }
  }

  @Test
  fun testDetectRealCrashOutput3() {
    val result = detector.detectCrash(
      File(
        "$packagePath/crashoutput/crash_output_3.txt",
      )
        .readText(),
    )
    assertThat(result.isCrashDetected()).isTrue()
    val signature = result.asCrash().signature.elements
    assertThat(signature).hasSize(5)
    assertThat(signature[0]).isEqualTo(
      "thread '<unnamed>' panicked at 'assertion failed: `(left == right)`",
    )
    assertThat(signature[1]).isEqualTo("left: `LLVMing`")
    assertThat(signature[2]).isEqualTo("right: `Codegenning`'")
    assertThat(signature[3]).isEqualTo("error: internal compiler error: unexpected panic")
    assertThat(signature[4]).isEqualTo("note: the compiler unexpectedly panicked. this is a bug.")
  }

  @Test
  fun testDetectRealCrashOutput1() {
    val cmdOut = CmdOutput(
      exitCode = ExitCode(100),
      stdout = ShellOutputLines.EMPTY,
      stderr = ShellOutputLines(
        ImmutableList.copyOf(
          File("$packagePath/crashoutput/crash_output_1.txt")
            .readLines(),
        ),
      ),
    )
    val result = detector.detectCrash(cmdOut)
    assertThat(result.isCrashDetected()).isTrue()
    assertThat(result.asCrash().signature.elements).containsExactly(
      "thread 'rustc' panicked at 'cannot use the `#[rustc_if_this_changed]` " +
        "or `#[rustc_then_this_would_need]` annotations without supplying " +
        "`-Z query-dep-graph`'",
      "error: internal compiler error: unexpected panic",
      "note: the compiler unexpectedly panicked. this is a bug.",
    ).inOrder()
  }

  @Test
  fun testDetectRealCrashOutput5() {
    val cmdOut = CmdOutput(
      exitCode = ExitCode(100),
      stdout = ShellOutputLines.EMPTY,
      stderr = ShellOutputLines(
        ImmutableList.copyOf(
          Paths.get("$packagePath/crashoutput/crash_output_5.txt").readLines(),
        ),
      ),
    )
    val result = detector.detectCrash(cmdOut)
    assertThat(result.isCrashDetected()).isTrue()
    assertThat(result.asCrash().signature.elements).contains("fatal runtime error: stack overflow")
  }
}
