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
package org.perses.grammar.rust

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import org.perses.program.EnumFormatControl
import org.perses.program.LanguageKind
import org.perses.util.shell.ShellCommandOnPath
import org.perses.util.toImmutableList

object LanguageRust : LanguageKind(
  name = "rust",
  extensions = ImmutableSet.of("rs"),
  defaultCodeFormatControl = EnumFormatControl.COMPACT_ORIG_FORMAT,
  origCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
  allowedCodeFormatControl = ImmutableSet.of(
    EnumFormatControl.COMPACT_ORIG_FORMAT,
    EnumFormatControl.ORIG_FORMAT,
  ),
  defaultFormatterCommandCreators = sequence {
    val rustFmtName = "rustfmt"
    yield(
      ShellCommandOnPath.IShellCommandOnPathCreator { ShellCommandOnPath.tryCreating(rustFmtName) },
    )
    for (versionString in allStableVersionStrings) {
      yield(
        ShellCommandOnPath.IShellCommandOnPathCreator {
          ShellCommandOnPath.tryCreating(
            rustFmtName,
            "+$versionString",
          )
        },
      )
    }
  }.toImmutableList(),
) {

  val stableVersionStrings: ImmutableList<String> = allStableVersionStrings
}

private val allStableVersionStrings: ImmutableList<String> = ImmutableList.builder<String>()
  .apply {
    (57 downTo 30).forEach { major ->
      (2 downTo 0).forEach { minor ->
        add("1.$major.$minor")
      }
    }
  }.build()
