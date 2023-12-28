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

import org.perses.program.TokenizedProgram
import org.perses.reduction.PropertyTestResult

abstract class AbstractCacheRetrievalResult private constructor(
  val owner: Any,
  val program: TokenizedProgram,
  private val encodingField: AbstractProgramEncoding<*>?,
) {

  fun hasEncoding() = encodingField != null

  fun getEncodingOrFail() = encodingField!!

  fun isHit() = this is CacheHit

  fun isMiss() = this is CacheMiss

  fun asCacheHit() = this as CacheHit

  fun asCacheMiss() = this as CacheMiss

  class CacheHit(
    owner: Any,
    program: TokenizedProgram,
    encoding: AbstractProgramEncoding<*>?,
    val testResult: PropertyTestResult,
  ) :
    AbstractCacheRetrievalResult(owner, program, encoding)

  class CacheMiss(
    owner: Any,
    program: TokenizedProgram,
    encoding: AbstractProgramEncoding<*>?,
  ) : AbstractCacheRetrievalResult(owner, program, encoding)

  companion object {
    fun create(
      owner: Any,
      program: TokenizedProgram,
      encoding: AbstractProgramEncoding<*>?,
      testResult: PropertyTestResult?,
    ): AbstractCacheRetrievalResult {
      return if (testResult == null) {
        CacheMiss(owner, program, encoding)
      } else {
        CacheHit(owner, program, encoding, testResult)
      }
    }
  }
}
