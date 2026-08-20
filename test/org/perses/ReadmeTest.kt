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
package org.perses

import com.google.common.truth.Truth.assertThat
import com.google.common.truth.Truth.assertWithMessage
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.version.Version
import java.nio.file.Paths
import kotlin.io.path.readLines

@RunWith(JUnit4::class)
class ReadmeTest {
  private val readmeFile = Paths.get("README.md")

  @Test
  fun testDownloadLinkIsForLatestVersion() {
    val majorVersion = "majorVersion"
    val minorVersion = "minorVersion"
    val pattern =
      Regex(
        ".*https://github.com/uw-pluverse/perses/releases/download/" +
          "v(?<$majorVersion>\\d+).(?<$minorVersion>\\d+)" +
          "/perses_deploy.jar.*",
      )
    val matchedLines =
      readmeFile
        .readLines()
        .mapNotNull { pattern.matchEntire(it) }
        .map { matchResult ->
          matchResult.groups[majorVersion] to matchResult.groups["minorVersion"]
        }
    assertWithMessage("The $readmeFile does not have a line matching the pattern $pattern")
      .that(matchedLines)
      .hasSize(1)
    val version = matchedLines.single()
    assertThat(version.first).isNotNull()
    assertThat(version.second).isNotNull()
    assertThat(version.first!!.value).isEqualTo(Version.MAJOR_VERSION)
    assertThat(version.second!!.value).isEqualTo(Version.MINOR_VERSION)
  }
}
