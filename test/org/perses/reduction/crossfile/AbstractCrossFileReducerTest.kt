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
import org.perses.reduction.AbstractReducerNameAndDesc
import org.perses.reduction.TestScriptExecutorService
import org.perses.reduction.io.AbstractOutputManagerFactory
import org.perses.reduction.io.SourceSpec

@RunWith(JUnit4::class)
class AbstractCrossFileReducerTest {
  // The property holds iff BOTH files contain KEEP -- so an interesting result proves the test saw
  // the whole set, not just the first file.
  private val fixture =
    CrossFileReductionTestData(
      javaClass,
      scriptBody = "grep -q KEEP a.c && grep -q KEEP b.c",
      SourceSpec("a.c", "KEEP", LanguageC),
      SourceSpec("b.c", "KEEP", LanguageC),
    )
  private val fileA: SourceFile = fixture.mutableFile("a.c")
  private val fileB: SourceFile = fixture.mutableFile("b.c")
  private val reducer =
    ProbeReducer(fixture.ioManager, fixture.executorService, fixture.outputManagerFactory)

  @After
  fun teardown() {
    fixture.close()
  }

  @Test
  fun testWholeSetSatisfyingTheConditionIsInteresting() {
    assertThat(reducer.probe(fixture.programOf(fileA to "KEEP a", fileB to "KEEP b"))).isTrue()
  }

  @Test
  fun testCandidateChangingASiblingIsSeenByTheTest() {
    // a.c still has KEEP, but b.c does not -- the test must see b.c and report uninteresting, which
    // proves the candidate's whole set (not just the file under reduction) is written and tested.
    assertThat(reducer.probe(fixture.programOf(fileA to "KEEP a", fileB to "dropped"))).isFalse()
  }

  private class ProbeReducer(
    ioManager: CrossFileReductionIOManager,
    executorService: TestScriptExecutorService,
    outputManagerFactory: AbstractOutputManagerFactory<CrossFileProgram>,
  ) : AbstractCrossFileReducer(NAME_AND_DESC, ioManager, executorService, outputManagerFactory) {
    override fun reduce(state: CrossFileReductionState) = error("not used in this test")

    fun probe(program: CrossFileProgram): Boolean = testProgram(program)

    companion object {
      private val NAME_AND_DESC =
        object : AbstractReducerNameAndDesc(
          shortName = "probe",
          description = "Test-only multi-file reducer that just exposes testProgram.",
        ) {}
    }
  }
}
