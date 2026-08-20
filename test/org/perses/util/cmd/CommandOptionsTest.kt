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
package org.perses.util.cmd

import com.google.common.truth.Truth.assertThat
import org.junit.Assert.assertThrows
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.PersesCommandOptions
import org.perses.cmd.EnumListMinimizerMicrobenchmarkingMode
import org.perses.cmd.EnumPassMode
import org.perses.program.EnumFormatControl
import java.nio.file.Paths

@RunWith(JUnit4::class)
class CommandOptionsTest {
  /** Exposes [PersesCommandOptions.validateExtra] so the cross-flag-group check can be tested. */
  private class ExposedPersesCommandOptions : PersesCommandOptions() {
    public override fun validateExtra() = super.validateExtra()
  }

  private fun createOptions(
    lineSlicer: EnumPassMode,
    codeFormat: EnumFormatControl?,
  ) = ExposedPersesCommandOptions().apply {
    algorithmControlFlags.lineSlicer = lineSlicer
    reductionControlFlags.codeFormat = codeFormat
  }

  @Test
  fun testLineSlicerOnWithSingleTokenPerLineFormatIsRejected() {
    val options = createOptions(EnumPassMode.ON, EnumFormatControl.SINGLE_TOKEN_PER_LINE)
    val e = assertThrows(IllegalArgumentException::class.java) { options.validateExtra() }
    assertThat(e).hasMessageThat().contains("line slicer")
    assertThat(e).hasMessageThat().contains("SINGLE_TOKEN_PER_LINE")
  }

  @Test
  fun testLineSlicerAutoWithSingleTokenPerLineFormatIsAllowed() {
    // auto is per-file, so it is not a hard error here; the driver soft-disables it for this format.
    createOptions(EnumPassMode.AUTO, EnumFormatControl.SINGLE_TOKEN_PER_LINE).validateExtra()
  }

  @Test
  fun testLineSlicerWithCompactOrigFormatIsAllowed() {
    createOptions(EnumPassMode.ON, EnumFormatControl.COMPACT_ORIG_FORMAT).validateExtra()
  }

  @Test
  fun testLineSlicerWithDefaultFormatIsAllowed() {
    createOptions(EnumPassMode.ON, codeFormat = null).validateExtra()
  }

  @Test
  fun testSingleTokenPerLineFormatWithoutLineSlicerIsAllowed() {
    createOptions(EnumPassMode.OFF, EnumFormatControl.SINGLE_TOKEN_PER_LINE).validateExtra()
  }

  private fun createOptions(
    mode: EnumListMinimizerMicrobenchmarkingMode?,
    globalFixpoint: Boolean,
  ) = ExposedPersesCommandOptions().apply {
    listMinimizerMicrobenchmarkingFlags.mode = mode
    reductionControlFlags.globalFixpoint = globalFixpoint
  }

  @Test
  fun testGlobalFixpointIsForcedOffUnderEvaluation() {
    val options =
      createOptions(EnumListMinimizerMicrobenchmarkingMode.EVALUATE, globalFixpoint = true)
    options.validateExtra()
    assertThat(options.reductionControlFlags.globalFixpoint).isFalse()
  }

  @Test
  fun testGlobalFixpointStaysOffUnderEvaluationWhenNotRequested() {
    val options =
      createOptions(EnumListMinimizerMicrobenchmarkingMode.EVALUATE, globalFixpoint = false)
    options.validateExtra()
    assertThat(options.reductionControlFlags.globalFixpoint).isFalse()
  }

  @Test
  fun testGlobalFixpointIsKeptUnderRecord() {
    // RECORD is an ordinary reduction, which the recording only observes, so its flags stand.
    val options =
      createOptions(EnumListMinimizerMicrobenchmarkingMode.RECORD, globalFixpoint = true)
    options.validateExtra()
    assertThat(options.reductionControlFlags.globalFixpoint).isTrue()
  }

  @Test
  fun testGlobalFixpointIsKeptWhenMicrobenchmarkingIsOff() {
    val options = createOptions(mode = null, globalFixpoint = true)
    options.validateExtra()
    assertThat(options.reductionControlFlags.globalFixpoint).isTrue()
  }

  @Test
  fun testCopyParameterValuesFrom() {
    val filled = PersesCommandOptions()
    val empty = PersesCommandOptions()

    // Fill up the 'filled' object
    filled.inputFlags.setInputFiles(listOf(Paths.get("input.c")))
    filled.inputFlags.testScript = Paths.get("test.sh")
    filled.resultOutputFlags.outputDir = Paths.get("output_dir")
    filled.verbosityFlags.verbosity = "DEBUG"

    // Copy to 'empty'
    empty.copyParameterValuesFrom(filled)

    // Assert both have same values
    assertThat(
      empty.inputFlags.computeInputFiles(),
    ).isEqualTo(filled.inputFlags.computeInputFiles())
    assertThat(empty.inputFlags.testScript).isEqualTo(filled.inputFlags.testScript)
    assertThat(empty.resultOutputFlags.outputDir).isEqualTo(filled.resultOutputFlags.outputDir)
    assertThat(empty.verbosityFlags.verbosity).isEqualTo(filled.verbosityFlags.verbosity)

    // Check that they are actually same
    assertThat(empty.inputFlags.computeInputFiles()).containsExactly(Paths.get("input.c"))
  }
}
