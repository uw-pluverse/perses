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
package org.perses.reduction.crossfile

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.LanguageC
import org.perses.program.AbstractReductionFile
import org.perses.reduction.AbstractReducerNameAndDesc
import org.perses.reduction.io.SourceSpec

@RunWith(JUnit4::class)
class CrossFileFileDeletionReducerTest {
  @After
  fun teardown() {
    fixtures.forEach { it.close() }
  }

  private val fixtures = mutableListOf<CrossFileReductionTestData>()

  private fun newFixture(
    scriptBody: String,
    vararg sources: SourceSpec,
  ): CrossFileReductionTestData =
    CrossFileReductionTestData(javaClass, scriptBody, *sources).also { fixtures.add(it) }

  private fun CrossFileReductionTestData.newState(program: CrossFileProgram): CrossFileReductionState =
    CrossFileReductionState(program) {
      ioManager.saveBestProgram(outputManagerFactory.createManagerFor(it))
    }

  private fun CrossFileReductionTestData.deletionReducer(): CrossFileFileDeletionReducer =
    CrossFileFileDeletionReducer(
      NAME_AND_DESC,
      ioManager,
      executorService,
      outputManagerFactory,
    )

  @Test
  fun testDropsUnnecessaryFiles() {
    // The property needs only a.c; b.c and c.c are unnecessary (here, also empty).
    val fixture =
      newFixture(
        scriptBody = "grep -q KEEP a.c",
        SourceSpec("a.c", "KEEP", LanguageC),
        SourceSpec("b.c", "  ", LanguageC),
        SourceSpec("c.c", "\n", LanguageC),
      )
    val fileA = fixture.mutableFile("a.c")
    val fileB = fixture.mutableFile("b.c")
    val fileC = fixture.mutableFile("c.c")
    val state =
      fixture.newState(fixture.programOf(fileA to "KEEP", fileB to "  ", fileC to "\n"))

    fixture.deletionReducer().reduce(state)

    // Both unnecessary files are dropped from the live set and physically gone from the result
    // folder; the bug file survives untouched.
    assertThat(state.bestProgram.fileContents.keys).containsExactly(fileA)
    assertThat(fixture.ioManager.resultFolder.checkFileExistence("b.c")).isFalse()
    assertThat(fixture.ioManager.resultFolder.checkFileExistence("c.c")).isFalse()
    assertThat(fixture.ioManager.resultFolder.readFileContent(fileA)).isEqualTo("KEEP")
  }

  @Test
  fun testDropsANonEmptyButUnnecessaryFile() {
    // b.c is non-empty but entirely unnecessary -- the empty-only predicate would never have removed
    // it; whole-file deletion does, in one test.
    val fixture =
      newFixture(
        scriptBody = "grep -q KEEP a.c",
        SourceSpec("a.c", "KEEP", LanguageC),
        SourceSpec("b.c", "lots\nof\ncontent\nbut\nunused", LanguageC),
      )
    val fileA = fixture.mutableFile("a.c")
    val fileB = fixture.mutableFile("b.c")
    val state =
      fixture.newState(
        fixture.programOf(fileA to "KEEP", fileB to "lots\nof\ncontent\nbut\nunused"),
      )

    fixture.deletionReducer().reduce(state)

    assertThat(state.bestProgram.fileContents.keys).containsExactly(fileA)
    assertThat(fixture.ioManager.resultFolder.checkFileExistence("b.c")).isFalse()
    assertThat(fixture.ioManager.resultFolder.readFileContent(fileA)).isEqualTo("KEEP")
  }

  @Test
  fun testGreedyKeepsAnEmptyFileTheTestStillNeeds() {
    // The property needs a.c AND the mere presence of c.c (even though empty); b.c is unnecessary.
    val fixture =
      newFixture(
        scriptBody = "grep -q KEEP a.c && test -f c.c",
        SourceSpec("a.c", "KEEP", LanguageC),
        SourceSpec("b.c", "  ", LanguageC),
        SourceSpec("c.c", "\n", LanguageC),
      )
    val fileA = fixture.mutableFile("a.c")
    val fileB = fixture.mutableFile("b.c")
    val fileC = fixture.mutableFile("c.c")
    val state =
      fixture.newState(fixture.programOf(fileA to "KEEP", fileB to "  ", fileC to "\n"))

    fixture.deletionReducer().reduce(state)

    // The batch (drop both) fails because c.c must stay, so the greedy pass drops only b.c.
    assertThat(state.bestProgram.fileContents.keys).containsExactly(fileA, fileC)
    assertThat(fixture.ioManager.resultFolder.checkFileExistence("b.c")).isFalse()
    assertThat(fixture.ioManager.resultFolder.checkFileExistence("c.c")).isTrue()
  }

  @Test
  fun testDropsEveryFileWhenTheTestNeedsNoInput() {
    // The script requires no input files at all, so even the file being reduced is dropped -- the
    // live set is driven all the way to empty.
    val fixture =
      newFixture(
        scriptBody = "true",
        SourceSpec("a.c", "", LanguageC),
        SourceSpec("b.c", "", LanguageC),
      )
    val fileA = fixture.mutableFile("a.c")
    val fileB = fixture.mutableFile("b.c")
    val state = fixture.newState(fixture.programOf(fileA to "", fileB to ""))

    fixture.deletionReducer().reduce(state)

    assertThat(state.bestProgram.fileContents).isEmpty()
    assertThat(fixture.ioManager.resultFolder.checkFileExistence("a.c")).isFalse()
    assertThat(fixture.ioManager.resultFolder.checkFileExistence("b.c")).isFalse()
  }

  @Test
  fun testDriverEmptiesThenDropsDependencyFiles() {
    // End-to-end (cf-3020 shape): the content pass empties the two dependency files, then the
    // deletion pass removes them -- 3 files in, 1 file out.
    val fixture =
      newFixture(
        scriptBody = "grep -q KEEP a.c",
        SourceSpec("a.c", "KEEP\nDROP", LanguageC),
        SourceSpec("b.c", "DROP", LanguageC),
        SourceSpec("c.c", "DROP", LanguageC),
      )
    val fileA = fixture.mutableFile("a.c")
    val driver = fixture.createDriver(ImmutableList.of(DropLinesTransformation))

    driver.reduce()

    assertThat(fixture.ioManager.resultFolder.checkFileExistence("a.c")).isTrue()
    assertThat(fixture.ioManager.resultFolder.checkFileExistence("b.c")).isFalse()
    assertThat(fixture.ioManager.resultFolder.checkFileExistence("c.c")).isFalse()
    assertThat(fixture.ioManager.resultFolder.readFileContent(fileA)).isEqualTo("KEEP")
  }

  @Test
  fun testSeparateTerminalDeletionDriverDropsEmptiedFiles() {
    // Mirrors Main: a content-only driver first, then a *separate* deletion-only driver (its own IO
    // manager, reading the result folder afresh after the content driver closed). This is the wiring
    // that keeps deletion strictly last even when the content phase grows a big fixpoint.
    val fixture =
      newFixture(
        scriptBody = "grep -q KEEP a.c",
        SourceSpec("a.c", "KEEP\nDROP", LanguageC),
        SourceSpec("b.c", "DROP", LanguageC),
        SourceSpec("c.c", "DROP", LanguageC),
      )
    val fileA = fixture.mutableFile("a.c")

    fixture
      .createReducerDriver(
        ImmutableList.of(
          CrossFileReductionDriver.transformationReducerFactory(
            ImmutableList.of(DropLinesTransformation),
          ),
        ),
      ).reduce()
    // The content driver only empties the dependency files; it never removes them.
    assertThat(fixture.ioManager.resultFolder.checkFileExistence("b.c")).isTrue()
    assertThat(fixture.ioManager.resultFolder.checkFileExistence("c.c")).isTrue()

    fixture
      .createReducerDriver(
        ImmutableList.of(CrossFileReductionDriver.FILE_DELETION_REDUCER_FACTORY),
      ).reduce()

    assertThat(fixture.ioManager.resultFolder.checkFileExistence("a.c")).isTrue()
    assertThat(fixture.ioManager.resultFolder.checkFileExistence("b.c")).isFalse()
    assertThat(fixture.ioManager.resultFolder.checkFileExistence("c.c")).isFalse()
    assertThat(fixture.ioManager.resultFolder.readFileContent(fileA)).isEqualTo("KEEP")
  }

  /** Removes every line containing "DROP" from every file -- a whole-set cross-file edit. */
  private object DropLinesTransformation : CrossFileProgramTransformation {
    override fun transform(
      fileContents: ImmutableMap<AbstractReductionFile<*, *>, String>,
    ): ImmutableList<ImmutableMap<AbstractReductionFile<*, *>, String>> {
      val stripped =
        fileContents.entries.associate { (file, content) ->
          file to content.lines().filterNot { it.contains("DROP") }.joinToString("\n")
        }
      return if (stripped == fileContents) {
        ImmutableList.of()
      } else {
        ImmutableList.of(ImmutableMap.copyOf(stripped))
      }
    }
  }

  private companion object {
    private val NAME_AND_DESC =
      object : AbstractReducerNameAndDesc(
        shortName = "test-empty-file-deletion",
        description = "test",
      ) {}
  }
}
