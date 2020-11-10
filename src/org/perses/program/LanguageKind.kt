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
package org.perses.program

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import org.perses.util.ShellCommandOnPath

abstract class LanguageKind(
  val name: String,
  val extensions: ImmutableSet<String>,
  val defaultCodeFormatControl: EnumFormatControl,
  val allowedCodeFormatControl: ImmutableSet<EnumFormatControl>,
  protected val defaultFormaterCommand: ImmutableList<ShellCommandOnPath> = ImmutableList.of()
) {

  init {
    check(defaultCodeFormatControl in allowedCodeFormatControl) {
      "The default code format $defaultFormaterCommand is not in $allowedCodeFormatControl"
    }
  }


  open fun getDefaultWorkingFormatter(): ShellCommandOnPath? {
    return if (defaultFormaterCommand.isEmpty()) {
      null
    } else {
      defaultFormaterCommand[0]
    }
  }

  fun getAllDefaultFormatterCommandStrings() = defaultFormaterCommand
    .fold(
      StringBuilder(), { builder, shellCmd ->
      builder.append("'$shellCmd'").append(", ")
    }).toString()

  fun isCodeFormatAllowed(codeFormat: EnumFormatControl) =
    allowedCodeFormatControl.contains(codeFormat)

  companion object {

    @JvmStatic
    fun createPotentialCodeFormatterList(vararg formatters: ShellCommandOnPath?) =
      formatters
        .asSequence()
        .filter { it!=null }
        .fold(
          ImmutableList.builder<ShellCommandOnPath>(),
          { builder, formatter -> builder.add(formatter!!) })
        .build()!!

  }

}
