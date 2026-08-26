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
package org.perses.program.printer
import org.perses.program.AbstractPersesToken
import org.perses.program.TokenPosition
import org.perses.util.lazyAssert

class TokenPlacementRecorder : AbstractTokenPlacementListener() {
  private val placement = HashMap<AbstractPersesToken, TokenPosition>()

  override fun onTokenPlacement(
    token: AbstractPersesToken,
    line: Int,
    charPositionInLine: Int,
  ) {
    lazyAssert({ placement.containsKey(token).not() }) {
      "The token $token has been added to the placement map. ${placement[token]}"
    }
    placement[token] = TokenPosition(line = line, charPositionInLine = charPositionInLine)
  }

  fun getPositionOrNull(token: AbstractPersesToken): TokenPosition? = placement[token]
}
