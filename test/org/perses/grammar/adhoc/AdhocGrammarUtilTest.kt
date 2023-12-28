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
package org.perses.grammar.adhoc

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.nio.file.Files
import kotlin.io.path.writeText

@RunWith(JUnit4::class)
class AdhocGrammarUtilTest {

  val workDir = Files.createTempDirectory("AdhocGrammarUtilTest_")

  @After
  fun teardown() {
    workDir.toFile().deleteRecursively()
  }

  @Test
  fun test() {
    val file = workDir.resolve("a.txt")
    file.writeText("")
    val hash = AdhocGrammarUtil.computeHash(file)
    assertThat(hash).isEqualTo(
      "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
    )
  }
}
