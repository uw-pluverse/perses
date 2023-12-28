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
import java.io.ByteArrayOutputStream
import java.io.PrintStream

@RunWith(JUnit4::class)
class VersionTest {

  @Test
  fun test() {
    assertThat(Version.MAJOR_VERSION).isNotEmpty()
    Integer.parseInt(Version.MAJOR_VERSION)

    assertThat(Version.MINOR_VERSION).isNotEmpty()
    Integer.parseInt(Version.MINOR_VERSION)

    assertThat(Version.STATUS.lowercase()).isAnyOf("clean", "modified")

    assertThat(Version.BUILD_TIME).isNotEmpty()
  }

  @Test
  fun testPrint() {
    val bos = ByteArrayOutputStream()
    PrintStream(
      bos,
      true, // autoFlush
      Charsets.UTF_8.name(),
    ).use {
      VersionHelper.printVersionInfo("perses", it)
    }
    val string = bos.toString(Charsets.UTF_8.name())
    assertThat(string).startsWith("perses")
    if (string.contains("Git Version")) {
      assertThat(string).contains("Git Branch")
      assertThat(string).contains("Git Status")
    }
    assertThat(string).contains("Built on")
  }
}
