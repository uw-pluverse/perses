/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.antlr.reducer.setup

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.AbstractAntlrrdcTest

@RunWith(JUnit4::class)
class SetupTest : AbstractAntlrrdcTest() {

  val setup = Setup(
    tempDir,
    parserGrammarPath,
    lexerGrammarPath,
    startRuleName = "start",
    testPrograms = ImmutableList.of(
      valid1,
      valid2,
      invalid1,
      invalid2,
    ),
  )

  @After
  fun teardown() {
    close()
  }

  @Test
  fun testParseablePrograms() {
    assertThat(setup.parseableTestPrograms).containsExactly(
      valid1,
      valid2,
    ).inOrder()
  }

  @Test
  fun testJarFile() {
    val jarFile = setup.jarFile

    assertThat(jarFile.expensiveTestParsable(valid1)).isTrue()

    assertThat(jarFile.expensiveTestParsable(invalid1)).isFalse()
  }

  @Test
  fun testReductionScriptFile() {
    val script = setup.testScript.fileContent
    assertThat(script).doesNotContain(valid1.toString())
    assertThat(script).doesNotContain(valid2.toString())
  }
}
