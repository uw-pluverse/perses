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

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import org.perses.program.EnumFormatControl
import org.perses.program.SerializableLanguageKind

class LanguageAdhoc {

  companion object {
    @JvmField
    val INSTANCE = SerializableLanguageKind.LanguageKindData(
      name = "adhoc",
      extensions = ImmutableSet.of("c", "h"),
      defaultCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
      origCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
      allowedCodeFormatControl = ImmutableSet.copyOf(EnumFormatControl.values()),
      defaultFormatterCommands = ImmutableList.of(
        SerializableLanguageKind.ShellCommandData(
          "clang-format",
          ImmutableList.of("-i"),
        ),
      ),
    ).toLanguageKind()
  }
}
