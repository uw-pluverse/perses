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
package org.perses.mimir.lsp

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.Util
import org.perses.util.shell.ShellCommandOnPath
import java.nio.file.Paths
import kotlin.io.path.ExperimentalPathApi
import kotlin.io.path.deleteRecursively

@RunWith(JUnit4::class)
class ClangDLanguageServerTest {
  val tempDir = Util.createTempDirForObject(this)

  val clangdCommand = ShellCommandOnPath("clangd-18")

  @OptIn(ExperimentalPathApi::class)
  @After
  fun tearDown() {
    tempDir.deleteRecursively()
  }

  @Test
  fun testAnalyzingLargeFile() {
    MimirDependencyAnalyzer(
      clangdCommand,
      sourceFile =
        Paths.get("test/org/perses/mimir/lsp/large.c"),
    ).use { analyzer ->
      assertThat(analyzer.defUseMap).hasSize(1043)
    }
  }
}
