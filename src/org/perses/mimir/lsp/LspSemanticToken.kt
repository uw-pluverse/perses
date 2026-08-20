/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.mimir.lsp

import com.google.common.base.MoreObjects
import org.eclipse.lsp4j.Position
import org.perses.program.TokenPosition
import org.perses.reduction.semantics.SemanticTokenType

class LspSemanticToken(
  val type: SemanticTokenType,
  val lexeme: String,
  private val modifiers: List<String>,
  val position: Position,
  val length: Int,
) {
  val isDefinition: Boolean by lazy {
    modifiers.any { it == "definition" }
  }

  val isDeclaration: Boolean by lazy {
    modifiers.any { it == "declaration" }
  }

  val isDeclarationOnlyButNotDefinition: Boolean by lazy {
    isDeclaration && !isDefinition
  }

  val antlrTokenPosition =
    TokenPosition(
      line = position.line + 1,
      charPositionInLine = position.character,
    )

  override fun toString(): String =
    MoreObjects
      .toStringHelper(this)
      .addValue(type)
      .add("lexeme", lexeme)
      .add("modifiers", modifiers)
      .add("position", "${position.line}:${position.character}")
      .add("length", length)
      .toString()
}
