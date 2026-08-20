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
import org.perses.program.SourceFile
import org.perses.reduction.AbstractReducerNameAndDesc
import org.perses.reduction.io.SourceSpec

@RunWith(JUnit4::class)
class CrossFileTransformationReducerTest {
  // The property holds iff BOTH files still contain KEEP.
  private val fixture =
    CrossFileReductionTestData(
      javaClass,
      scriptBody = "grep -q KEEP a.c && grep -q KEEP b.c",
      SourceSpec("a.c", "seed", LanguageC),
      SourceSpec("b.c", "seed", LanguageC),
    )
  private val fileA: SourceFile = fixture.mutableFile("a.c")
  private val fileB: SourceFile = fixture.mutableFile("b.c")
  private val executorService = fixture.executorService

  @After
  fun teardown() {
    fixture.close()
  }

  @Test
  fun testDrivesACrossFileTransformationToFixpoint() {
    val reducer =
      CrossFileTransformationReducer(
        NAME_AND_DESC,
        fixture.ioManager,
        executorService,
        fixture.outputManagerFactory,
        ImmutableList.of(DropLinesTransformation),
      )
    val state =
      CrossFileReductionState(
        fixture.programOf(fileA to "KEEP\nDROP\nKEEP2", fileB to "DROP\nKEEP\nDROP"),
      ) { fixture.ioManager.saveBestProgram(fixture.outputManagerFactory.createManagerFor(it)) }

    reducer.reduce(state)

    // Every DROP line is gone from both files; KEEP lines (the property) survive.
    assertThat(state.bestProgram.fileContents[fileA]).isEqualTo("KEEP\nKEEP2")
    assertThat(state.bestProgram.fileContents[fileB]).isEqualTo("KEEP")
    // The result folder mirrors the best program (saved through the state's listener).
    assertThat(fixture.ioManager.resultFolder.readFileContent(fileA)).isEqualTo("KEEP\nKEEP2")
    assertThat(fixture.ioManager.resultFolder.readFileContent(fileB)).isEqualTo("KEEP")
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

  companion object {
    private val NAME_AND_DESC =
      object : AbstractReducerNameAndDesc(
        shortName = "drop-lines",
        description = "Test transformation reducer that strips DROP lines from every file.",
      ) {}
  }
}
