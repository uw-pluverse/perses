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
package org.perses.util.shell

import com.google.common.collect.ImmutableList

class CommonShellCommands {
  /**
   * Note that all commands should be lazily initialized, because not all commands are required.
   * Initializing a command requires the command to be present on the PATH.
   */
  companion object {

    val CLANG_FORMAT_IN_PLACE: ShellCommandOnPath by lazy {
      ShellCommandOnPath("clang-format", ImmutableList.of(FLAG_INPLACE_EDIT))
    }

    private const val FLAG_INPLACE_EDIT = "-i"
  }
}
