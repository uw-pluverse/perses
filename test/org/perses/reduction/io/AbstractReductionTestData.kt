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
package org.perses.reduction.io

import com.google.common.collect.ImmutableList
import org.perses.program.LanguageKind
import org.perses.program.ScriptFile
import org.perses.program.SourceFile
import org.perses.reduction.AbstractGlobalExecutionCache.NullCache
import org.perses.reduction.TestScriptExecutorService
import org.perses.util.AutoDeletableFolder
import org.perses.util.Util
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.shell.Shells
import java.nio.file.Files
import java.nio.file.Path

/** A mutable file to materialize in a test: its base name, initial content, and language. */
class SourceSpec(
  val baseName: String,
  val content: String,
  val language: LanguageKind,
)

/**
 * The shared scaffolding for reduction tests that need a populated result folder. Under one temp
 * directory it materializes an interestingness script and a set of mutable source files, then builds
 * the [DefaultLanguageOriginalReductionInputs], the output/working/result folders, and a lazy
 * [TestScriptExecutorService] -- everything a reduction-IO test needs. The one thing that differs per
 * reduction flavor, the [ioManager] (token vs cross-file ...), is left abstract; [close] (which shuts
 * the executor and deletes the temp directory) and the rest are provided here.
 *
 * Concrete subclasses: [CommonReductionIOManagerData] (single-file, token IO manager) and the
 * cross-file `CrossFileReductionTestData`.
 */
abstract class AbstractReductionTestData(
  testClass: Class<*>,
  scriptBody: String,
  sources: List<SourceSpec>,
) : AutoCloseable {
  protected val shaAlgorithm = EnumShaAlgorithm.SHA512
  private val tempFolder =
    AutoDeletableFolder(Files.createTempDirectory(testClass.simpleName + "_data"))
  val tempDir: Path get() = tempFolder.file
  private val closeActions = ArrayList<() -> Unit>()

  val script =
    ScriptFile(
      Util
        .createDirsAndWriteText(tempDir.resolve("r.sh"), "${Shells.SHEBANG_BASH}\n$scriptBody\n")
        .also { Util.setExecutable(it) },
    )
  private val sourceFilesByBaseName: Map<String, SourceFile> =
    sources.associate { spec ->
      spec.baseName to
        SourceFile(
          Util.createDirsAndWriteText(tempDir.resolve(spec.baseName), spec.content),
          spec.language,
        )
    }
  val inputs =
    DefaultLanguageOriginalReductionInputs(
      testScript = script,
      mutableFiles = ImmutableList.copyOf(sourceFilesByBaseName.values),
      immutableDependencyFiles = ImmutableList.of(),
    )
  val outputDir: Path = Util.ensureDirExists(tempDir.resolve("output_dir"))
  val workingDir: Path = Util.ensureDirExists(tempDir.resolve("working_dir"))

  /** The IO manager under test -- the only piece that differs between reduction flavors. */
  abstract val ioManager: AbstractReductionIOManager<*, *>

  /** The materialized mutable file with the given [baseName] (e.g. `"a.c"`). */
  fun mutableFile(baseName: String): SourceFile =
    requireNotNull(sourceFilesByBaseName[baseName]) { "No mutable file named '$baseName'." }

  /** A result folder populated with the original inputs -- the start state for a reduction. */
  protected fun createPopulatedResultFolder(): ReductionFolder =
    AbstractReductionIOManager.createPopulatedResultFolder(inputs, shaAlgorithm, outputDir)

  /** Registers [action] to run first during [close] (e.g. to close a driver this data created). */
  protected fun onClose(action: () -> Unit) {
    closeActions.add(action)
  }

  // The reduction folder manager is no longer owned by the IO manager (AbstractMain owns the shared
  // one in production); build a throwaway one over a fresh temp root for tests that need one.
  fun newReductionFolderManager(): ReductionFolderManager =
    ReductionFolderManager(inputs, Files.createTempDirectory(workingDir, "PersesTempRoot_"))

  // Lazy because constructing the executor has side effects (it creates files under the working
  // folder); a test that does not use it pays nothing.
  private val executorServiceDelegate =
    lazy {
      TestScriptExecutorService(
        newReductionFolderManager(),
        specifiedNumOfThreads = 1,
        scriptExecutionTimeoutInSeconds = 600L,
        globalExecutionCache = NullCache(),
      )
    }
  val executorService: TestScriptExecutorService by executorServiceDelegate

  override fun close() {
    closeActions.forEach { it() }
    if (executorServiceDelegate.isInitialized()) {
      executorService.close()
    }
    tempFolder.close()
  }
}
