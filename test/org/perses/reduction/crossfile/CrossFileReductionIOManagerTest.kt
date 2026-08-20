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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.c.LanguageC
import org.perses.program.SourceFile
import org.perses.reduction.io.SourceSpec

@RunWith(JUnit4::class)
class CrossFileReductionIOManagerTest {
  // This test never runs the script (it exercises the IO manager directly), so the body is a no-op.
  private val fixture =
    CrossFileReductionTestData(
      javaClass,
      scriptBody = "true",
      SourceSpec("a.c", "int a;", LanguageC),
      SourceSpec("b.c", "int b;", LanguageC),
    )
  private val fileA: SourceFile = fixture.mutableFile("a.c")
  private val fileB: SourceFile = fixture.mutableFile("b.c")

  @After
  fun teardown() {
    fixture.close()
  }

  @Test
  fun testSaveBestProgramWritesEveryMutableFile() {
    fixture.ioManager.saveBestProgram(
      fixture.outputManagerFactory.createManagerFor(
        fixture.programOf(fileA to "int newA;", fileB to "int newB;"),
      ),
    )
    assertThat(fixture.ioManager.resultFolder.readFileContent(fileA)).isEqualTo("int newA;")
    assertThat(fixture.ioManager.resultFolder.readFileContent(fileB)).isEqualTo("int newB;")
  }

  @Test
  fun testCreateOutputManagerRendersTheWholeSet() {
    val outputManager =
      fixture.outputManagerFactory.createManagerFor(
        fixture.programOf(
          fileA to "x",
          fileB to "y",
        ),
      )
    val byName =
      outputManager.fileContentList.pairs.associate {
        it.fileName.baseName to it.content.asTextFileContent.text
      }
    assertThat(byName).containsExactly("a.c", "x", "b.c", "y")
  }

  @Test
  fun testProgramOmittingAFileRendersOnlyTheLiveFiles() {
    // The live set shrinks when the empty-file-deletion reducer drops a file, so a program may omit
    // a mutable file. The output manager then renders only the files the program still holds -- the
    // dropped file is absent, not written as an empty file.
    val outputManager =
      fixture.outputManagerFactory.createManagerFor(fixture.programOf(fileA to "only a"))
    val byName =
      outputManager.fileContentList.pairs.associate {
        it.fileName.baseName to it.content.asTextFileContent.text
      }
    assertThat(byName).containsExactly("a.c", "only a")
  }

  @Test
  fun testEmptyProgramRendersNoFilesAndHashesWithoutThrowing() {
    // A test (shell script) can require no input files, so the live set may be driven empty. Such a
    // program renders no files, and its SHA hash is well-defined (the hash of nothing) -- not an
    // error -- so the query cache can key on it. All empty sets share one identity.
    val outputManager = fixture.outputManagerFactory.createManagerFor(fixture.programOf())
    assertThat(outputManager.fileContentList.pairs).isEmpty()
    assertThat(outputManager.shaHashCode)
      .isEqualTo(fixture.outputManagerFactory.createManagerFor(fixture.programOf()).shaHashCode)
  }
}
