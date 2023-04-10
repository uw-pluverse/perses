/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import org.perses.util.shell.ShellCommandOnPath
import org.perses.util.toImmutableList

abstract class LanguageKind(
  name: String,
  extensions: ImmutableSet<String>,
  val defaultCodeFormatControl: EnumFormatControl,
  val origCodeFormatControl: EnumFormatControl,
  val allowedCodeFormatControl: ImmutableSet<EnumFormatControl>,
  val defaultFormatterCommands: ImmutableList<ShellCommandOnPath> = ImmutableList.of(),
) : AbstractDataKind(name, extensions) {

  init {
    check(defaultCodeFormatControl in allowedCodeFormatControl) {
      "The default code format $defaultFormatterCommands is not in $allowedCodeFormatControl"
    }
    check(origCodeFormatControl in allowedCodeFormatControl) {
      "The orig code format $origCodeFormatControl is not in $allowedCodeFormatControl"
    }
  }

  open fun getDefaultWorkingFormatter(): ShellCommandOnPath? {
    return if (defaultFormatterCommands.isEmpty()) {
      null
    } else {
      defaultFormatterCommands[0]
    }
  }

  override fun onEquals(other: Any) {
    check(other is LanguageKind)
    check(other.extensions == extensions)
    check(other.defaultCodeFormatControl == defaultCodeFormatControl)
    check(other.origCodeFormatControl == origCodeFormatControl)
    check(other.allowedCodeFormatControl == allowedCodeFormatControl)
  }

  fun getAllDefaultFormatterCommandStrings() = defaultFormatterCommands
    .joinToString(separator = ", ")

  fun isCodeFormatAllowed(codeFormat: EnumFormatControl) =
    allowedCodeFormatControl.contains(codeFormat)

  override fun toString() = MoreObjects.toStringHelper(this)
    .add("name", name)
    .add("extensions", extensions)
    .add("defaultCodeFormatControl", defaultCodeFormatControl)
    .toString()

  companion object {

    @JvmStatic
    fun createPotentialCodeFormatterList(vararg formatters: ShellCommandOnPath?) =
      formatters
        .asSequence()
        .filter { it != null }
        .map { it!! }
        .toImmutableList()
  }
}
