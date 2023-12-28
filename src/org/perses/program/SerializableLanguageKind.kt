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
package org.perses.program

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import org.perses.util.YamlUtil
import org.perses.util.shell.ShellCommandOnPath
import org.perses.util.shell.ShellCommandOnPath.IShellCommandOnPathCreator
import org.perses.util.toImmutableList

class SerializableLanguageKind internal constructor(
  data: LanguageKindData,
) : LanguageKind(
  data.name,
  data.extensions,
  data.defaultCodeFormatControl,
  data.origCodeFormatControl,
  data.allowedCodeFormatControl,
  data.defaultFormatterCommands.asSequence()
    .map { IShellCommandOnPathCreator { ShellCommandOnPath(it.command, it.defaultFlags) } }
    .toImmutableList(),
) {

  fun toYamlString(): String {
    return LanguageKindData.from(this).toYamlString()
  }

  data class ShellCommandData(
    val command: String,
    val defaultFlags: ImmutableList<String>,
  )

  data class LanguageKindData(
    val name: String,
    val extensions: ImmutableSet<String>,
    val defaultCodeFormatControl: EnumFormatControl,
    val origCodeFormatControl: EnumFormatControl,
    val allowedCodeFormatControl: ImmutableSet<EnumFormatControl>,
    val defaultFormatterCommands: ImmutableList<ShellCommandData> = ImmutableList.of(),
  ) {

    fun toYamlString(): String {
      return YamlUtil.toYamlString(this)
    }

    fun toLanguageKind(): SerializableLanguageKind = SerializableLanguageKind(this)

    companion object {
      fun from(language: LanguageKind): LanguageKindData {
        return LanguageKindData(
          name = language.name,
          extensions = language.extensions,
          defaultCodeFormatControl = language.defaultCodeFormatControl,
          origCodeFormatControl = language.origCodeFormatControl,
          allowedCodeFormatControl = language.allowedCodeFormatControl,
          defaultFormatterCommands = language.defaultFormatterCommandCreators
            .mapNotNull { it.tryCreate() }
            .map { ShellCommandData(it.originalCommand, it.defaultFlags) }
            .toImmutableList(),
        )
      }
    }
  }

  companion object {
    @JvmStatic
    fun fromYamlString(yaml: String): SerializableLanguageKind {
      return SerializableLanguageKind(YamlUtil.fromYamlString(yaml, LanguageKindData::class.java))
    }
  }
}
