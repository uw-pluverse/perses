/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
import org.perses.util.ShellCommandOnPath

object LanguageRust : LanguageKind(
  name = "rust",
  extensions = ImmutableSet.of("rs"),
  defaultCodeFormatControl = EnumFormatControl.COMPACT_ORIG_FORMAT,
  allowedCodeFormatControl = ImmutableSet.of(
    EnumFormatControl.SINGLE_TOKEN_PER_LINE,
    EnumFormatControl.COMPACT_ORIG_FORMAT,
    EnumFormatControl.ORIG_FORMAT
  ),
  defaultFormaterCommand = createPotentialCodeFormatterList(
    ShellCommandOnPath.tryCreating("rustfmt"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.47.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.46.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.45.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.44.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.43.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.42.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.41.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.40.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.39.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.38.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.37.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.36.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.35.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.34.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.33.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.32.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.31.0"),
    ShellCommandOnPath.tryCreating("rustfmt", "+1.30.0")
  )
) {

  override fun getDefaultWorkingFormatter(): ShellCommandOnPath? {
    return defaultFormaterCommand.asSequence().firstOrNull {
      it.runWith(ImmutableList.of("--help")).exitCode==0
    }
  }

}
