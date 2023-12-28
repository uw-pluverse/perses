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
package org.perses.reduction.cache

import com.google.common.collect.ImmutableList
import org.perses.program.PersesTokenFactory
import org.perses.program.TokenizedProgram
import org.perses.util.Util.lazyAssert

abstract class AbstractTokenizedProgramEncoder<Encoding> protected constructor(
  protected var baseProgram: TokenizedProgram,
  protected val profiler: AbstractQueryCacheProfiler,
) {

  abstract fun encode(program: TokenizedProgram): Encoding?

  abstract fun reEncode(previousEncoding: Encoding): Encoding?

  fun updateEncoder(newBaseProgram: TokenizedProgram) {
    lazyAssert { newBaseProgram.factory == baseProgram.factory }
    baseProgram = newBaseProgram
    updateEncoderMore(baseProgram)
  }

  protected abstract fun updateEncoderMore(encoderBaseProgram: TokenizedProgram)

  val tokensInBaseProgram: ImmutableList<PersesTokenFactory.PersesToken>
    get() = baseProgram.tokens
}
