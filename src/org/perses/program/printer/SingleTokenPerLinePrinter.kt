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
package org.perses.program.printer

import org.perses.program.AbstractLazySourceCode
import org.perses.program.TokenizedProgram
import org.perses.util.FastStringBuilder

object SingleTokenPerLinePrinter : AbstractTokenizedProgramPrinter() {

  override fun print(
    program: TokenizedProgram,
    tokenPlacementListener: AbstractTokenPlacementListener?,
  ) = object : AbstractLazySourceCode() {
    override fun computeStringBuilder() = program.tokens.fold(
      FastStringBuilder(program.tokenCount() * 5),
    ) { builder, token -> builder.append(token.text).append('\n') }
  }

  override fun extraEquals(other: Any): Boolean {
    return this == other
  }

  override fun extraHashCode(): Int {
    return 0
  }
}
