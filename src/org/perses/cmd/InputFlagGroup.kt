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
package org.perses.cmd

import com.beust.jcommander.Parameter
import com.fasterxml.jackson.annotation.JsonAutoDetect
import com.google.common.collect.ImmutableList
import org.perses.util.FileSystemUtil
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths

// Serialize by field only (the config dump records the raw --input/--deps args), in declaration
// order, exactly as the former public @JvmField fields did. fieldVisibility = ANY picks up the
// `internal` inputFiles/deps backing fields; getterVisibility = NONE keeps Kotlin's mangled
// `internal` getters (e.g. getInputFiles$...) out of the output.
@JsonAutoDetect(
  fieldVisibility = JsonAutoDetect.Visibility.ANY,
  getterVisibility = JsonAutoDetect.Visibility.NONE,
)
open class InputFlagGroup : AbstractCommandLineFlagGroup(groupName = "Inputs") {
  @JvmField
  @Parameter(
    names = ["--test-script", "--test", "-t"],
    required = true,
    description = "The test script to specify the property the reducer needs to preserve.",
    order = 0,
  )
  var testScript: Path? = null

  /**
   * The raw `--input` arguments, each of which may be a regular file or a directory. Production
   * code must read [computeInputFiles] instead, which expands directories and excludes the test
   * script and dependency files. `internal` so no production reader outside this module bypasses
   * that expansion.
   */
  @field:Parameter(
    names = ["--input-file", "--input", "-i"],
    required = true,
    description =
      "The input file(s) or directory(ies) to reduce. Repeat the flag to pass multiple, " +
        "e.g. --input a.c --input b.c, or --input src_dir. A directory is expanded " +
        "recursively to all regular files under it (the test script and any --deps files " +
        "are excluded).",
    order = 1,
  )
  internal var inputFiles: List<Path> = mutableListOf()

  /**
   * The raw `--deps` arguments, each of which may be a regular file or a directory. Production code
   * must read [computeDeps], which expands directories. `internal` for the same reason as
   * [inputFiles].
   */
  @field:Parameter(
    names = ["--deps"],
    required = false,
    description =
      "The dependency file(s) or directory(ies) required for running the property test. A " +
        "directory is expanded recursively to all regular files under it.",
    order = 2,
  )
  internal var deps: List<Path> = mutableListOf()

  fun getTestScript(): Path = checkNotNull(testScript)

  /**
   * Expands every raw `--deps` argument: a directory becomes all regular files under it
   * (recursively); a file stays as-is. The result is sorted and deduplicated.
   */
  fun computeDeps(): ImmutableList<Path> = expandPaths(deps)

  /**
   * Expands every raw `--input` argument the same way as [computeDeps], then excludes the test
   * script and every dependency file (so a directory containing them can be passed directly). The
   * result is sorted and deduplicated.
   */
  fun computeInputFiles(): ImmutableList<Path> {
    val excluded =
      buildSet {
        add(canonicalize(getTestScript()))
        computeDeps().forEach { add(canonicalize(it)) }
      }
    return expandPaths(inputFiles)
      .filter { canonicalize(it) !in excluded }
      .let { ImmutableList.copyOf(it) }
  }

  override fun validate() {
    val testScript = getTestScript()
    val workingDirectory = Paths.get(".").toAbsolutePath()
    check(Files.isRegularFile(testScript)) {
      "The test script $testScript is not a file. The current directory is $workingDirectory."
    }
    check(Files.isExecutable(testScript)) {
      "The test script $testScript is not executable."
    }

    check(inputFiles.isNotEmpty()) {
      "At least one input file or directory must be specified."
    }
    for (input in inputFiles) {
      check(Files.isRegularFile(input) || Files.isDirectory(input)) {
        "The input $input is neither a file nor a directory. " +
          "The current directory is $workingDirectory."
      }
    }
    for (dep in deps) {
      check(Files.isRegularFile(dep) || Files.isDirectory(dep)) {
        "The dependency $dep is neither a file nor a directory."
      }
      check(!Files.isSameFile(dep, testScript)) {
        "The test script file $testScript cannot be a dep."
      }
    }

    check(computeInputFiles().isNotEmpty()) {
      "No input files were found under the specified --input path(s): $inputFiles. " +
        "The current directory is $workingDirectory."
    }
  }

  /**
   * Expands [paths] in order: each explicit file is kept where it appears (preserving the
   * command-line order the user gave), and each directory is replaced in place by all regular files
   * under it, sorted deterministically (by [FileSystemUtil.globWithFilter]). Duplicates are dropped, keeping
   * the first occurrence.
   */
  private fun expandPaths(paths: List<Path>): ImmutableList<Path> {
    val expanded = LinkedHashSet<Path>()
    for (path in paths) {
      if (Files.isDirectory(path)) {
        expanded.addAll(FileSystemUtil.globWithFilter(path) { true })
      } else {
        expanded.add(path)
      }
    }
    return ImmutableList.copyOf(expanded)
  }

  /** Canonical absolute path for set membership; robust to symlinks and `./` noise. */
  private fun canonicalize(path: Path): Path =
    if (Files.exists(path)) path.toRealPath() else path.toAbsolutePath().normalize()

  /**
   * Sets the raw `--input` arguments programmatically. Public because production code generating
   * flags internally needs it (e.g. ppr's `FlagGenerator`, which lives in a separate module). Code
   * within this module (and associated tests) can assign [inputFiles]/[deps] directly instead.
   */
  fun setInputFiles(paths: List<Path>) {
    inputFiles = paths.toList()
  }
}
