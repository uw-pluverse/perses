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
package org.perses.fuzzer.compilers

import com.google.common.collect.ImmutableList
import org.perses.program.LanguageKind
import org.perses.util.shell.ShellCommandOnPath

class CommonCompilationAction(
  compilerCmd: ShellCommandOnPath,
  compilerFlags: ImmutableList<String>,
  versionPrintFlags: ImmutableList<String>,
  private val language: LanguageKind,
) : AbstractCompilationAction(
  compilerCmd,
  compilerFlags,
  versionPrintFlags,
  timeoutSeconds = ICompilationAction.DEFAULT_COMPILATION_TIMEOUT_SECONDS,
) {
  override fun getLanguage() = language
}
