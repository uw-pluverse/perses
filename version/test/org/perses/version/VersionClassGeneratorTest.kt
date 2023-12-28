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
package org.perses.version

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class VersionClassGeneratorTest {

  val data = """
    BUILD_TIMESTAMP 1699246047
    FORMATTED_DATE 2023 Nov 06 04 47 27 Mon 
    PERSES_GIT_BRANCH master
    PERSES_GIT_COMMIT_HASH 9bbb8ec95f27e76292a4ba6bce5fdeb21828dcaf
    PERSES_GIT_STATUS Modified
  """.lines()

  @Test
  fun testParser() {
    val result = VersionClassGenerator.parse(data)
    assertThat(result).hasSize(5)
    assertThat(result.get("BUILD_TIMESTAMP").single()).isEqualTo("1699246047")
    assertThat(result.get("FORMATTED_DATE").single()).isEqualTo("2023 Nov 06 04 47 27 Mon")
    assertThat(result.get("PERSES_GIT_BRANCH").single()).isEqualTo("master")
  }
}
