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
package org.perses.antlr.ast

abstract class AbstractLexerCommand protected constructor(protected val commandName: String) {
  abstract fun toSourceCode(): String
  class LexerCommandWithNoArg(commandName: String) : AbstractLexerCommand(commandName) {
    override fun toSourceCode(): String {
      return commandName
    }
  }

  class LexerCommandWithArg(
    commandName: String,
    private val arg: String,
  ) : AbstractLexerCommand(commandName) {
    override fun toSourceCode(): String {
      return "$commandName($arg)"
    }
  }

  companion object {
    fun create(command: String): LexerCommandWithNoArg {
      return LexerCommandWithNoArg(command)
    }

    fun create(command: String, arg: String): LexerCommandWithArg {
      return LexerCommandWithArg(command, arg)
    }
  }
}
