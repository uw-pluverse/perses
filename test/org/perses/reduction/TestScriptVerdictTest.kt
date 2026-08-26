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
package org.perses.reduction

import com.fasterxml.jackson.core.type.TypeReference
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.Serialization
import org.perses.util.shell.ExitCode

@RunWith(JUnit4::class)
class TestScriptVerdictTest {
  @Test
  fun testSerialization() {
    val result = TestScriptVerdict(ExitCode.ZERO, elapsedMillis = 100)
    val yaml = Serialization.toYamlString(result)
    val deserialized =
      Serialization.fromYamlString(
        yaml,
        object : TypeReference<TestScriptVerdict>() {},
      )
    assertThat(deserialized).isEqualTo(result)
    assertThat(yaml as String?).contains("exitCode")
    assertThat(yaml as String?).contains("elapsedMillis")
    assertThat(yaml as String?).doesNotContain("isInteresting")
    assertThat(yaml as String?).doesNotContain("isNotInteresting")
  }
}
