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
package org.perses.antlr

import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path

abstract class AbstractGrammarStub(
  protected val packageName: String,
  protected val parserClassSimpleName: String,
  protected val lexerClassSimpleName: String,
  protected val startRuleName: String
) {
  init {
    require(!packageName.isEmpty() && packageName.trim().equals(packageName)) {
      "packageName name must non-empty with no trailing/leading spaces"
    }

    require(
      !parserClassSimpleName.isEmpty() &&
        parserClassSimpleName.trim().equals(parserClassSimpleName)
    ) {
      "parserClassSimpleName must non-empty with no trailing/leading spaces"
    }

    require(
      !lexerClassSimpleName.isEmpty() &&
        lexerClassSimpleName.trim().equals(lexerClassSimpleName)
    ) {
      "lexerClassSimpleName name must non-empty with no trailing/leading spaces"
    }

    require(
      !startRuleName.isEmpty() &&
        startRuleName.trim().equals(startRuleName)
    ) {
      "startRuleName name must non-empty with no trailing/leading spaces"
    }
  }

  abstract fun classSimpleName(): String

  abstract fun classFullName(): String

  fun writeTo(file: Path) {
    Files.write(file, generateCode().toByteArray(StandardCharsets.UTF_8))
  }

  abstract fun generateCode(): String
}
