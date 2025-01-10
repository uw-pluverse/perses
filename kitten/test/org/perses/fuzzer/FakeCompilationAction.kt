/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.fuzzer

import com.google.common.annotations.VisibleForTesting
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import org.perses.fuzzer.compilers.ActionResult
import org.perses.fuzzer.compilers.ICompilationAction
import org.perses.grammar.rust.LanguageRust
import org.perses.util.shell.CmdOutput
import org.perses.util.shell.ExitCode
import org.perses.util.shell.ShellOutputLines
import java.io.File

object FakeCompilationAction : ICompilationAction {

  override fun compileWithExtraEnvironment(
    file: File,
    extraEnv: ImmutableMap<String, String>,
  ): ActionResult {
    return compile(file)
  }

  override fun compile(file: File) = ActionResult(
    CmdOutput(
      exitCode = ExitCode.ONE,
      stdout = ShellOutputLines(ImmutableList.of("stdout")),
      stderr = ShellOutputLines(ImmutableList.of("internal compiler error", "this is a bug")),
    ),
    cmd = "( echo -e 'internal compiler error\\nthis is a bug' ; false )",
  )

  override fun getLanguage() = LanguageRust

  override fun getVersion() = "fake rustc"

  @VisibleForTesting
  override fun constructCompileCmd(file: File) = "fake rustc"
}
