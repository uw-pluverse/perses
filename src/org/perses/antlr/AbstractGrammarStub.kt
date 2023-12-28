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
package org.perses.antlr

import java.nio.file.Path
import kotlin.io.path.writeText

abstract class AbstractGrammarStub(
  protected val packageName: String,
  protected val parserClassSimpleName: String,
  protected val lexerClassSimpleName: String,
  protected val startRuleName: String,
) {
  init {
    require(packageName.isNotEmpty() && packageName.trim().equals(packageName)) {
      "packageName name must non-empty with no trailing/leading spaces"
    }

    require(
      parserClassSimpleName.isNotEmpty() &&
        parserClassSimpleName.trim().equals(parserClassSimpleName),
    ) {
      "parserClassSimpleName must non-empty with no trailing/leading spaces"
    }

    require(
      lexerClassSimpleName.isNotEmpty() &&
        lexerClassSimpleName.trim().equals(lexerClassSimpleName),
    ) {
      "lexerClassSimpleName name must non-empty with no trailing/leading spaces"
    }

    require(
      startRuleName.isNotEmpty() &&
        startRuleName.trim().equals(startRuleName),
    ) {
      "startRuleName name must non-empty with no trailing/leading spaces"
    }
  }

  abstract fun classSimpleName(): String

  abstract fun classFullName(): String

  fun writeTo(file: Path) {
    file.writeText(generateCode())
  }

  abstract fun generateCode(): String
}
