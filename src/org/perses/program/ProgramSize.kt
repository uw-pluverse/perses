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
package org.perses.program

import com.google.common.base.MoreObjects
import kotlin.comparisons.compareValuesBy

class ProgramSize<PayloadType : Any>(
  val payload: PayloadType,
  /** The number of canonical (primary) tokens in the program.
   *  This is computed based on the actual syntax of the language of the program.
   */
  canonicalTokenCount: Int?,
  /** The number of surrogate (placeholder/alternate) tokens in the program.
   *  This is the number of tokens in the current program. However the tokens
   *  can be obtained from a grammar that does not represent the language, such
   *  as a Dyck language grammar.
   */
  val surrogateTokenCount: Int,
  val totalCharacterCount: Int,
  val nonBlankCharacterCount: Int,
) : Comparable<ProgramSize<*>> {
  val canonicalTokenCount: Int = canonicalTokenCount ?: surrogateTokenCount

  override fun compareTo(other: ProgramSize<*>): Int =
    compareValuesBy(
      this,
      other,
      { it.canonicalTokenCount },
      { it.nonBlankCharacterCount },
      { it.totalCharacterCount },
      // Surrogate token count is not a real measure of program size.
      { it.surrogateTokenCount },
    )

  fun <T : Any> withNewPayload(newPayload: T): ProgramSize<T> =
    ProgramSize(
      payload = newPayload,
      canonicalTokenCount = canonicalTokenCount,
      surrogateTokenCount = surrogateTokenCount,
      totalCharacterCount = totalCharacterCount,
      nonBlankCharacterCount = nonBlankCharacterCount,
    )

  /**
   * The same counts with the program dropped, matching the payload-free [ZERO].
   *
   * Use this whenever a size outlives the program it measures -- a size kept per reducer call, per
   * file, or for the whole run -- because a retained payload pins that program in memory for as
   * long as the size is held.
   */
  fun withoutPayload(): ProgramSize<Unit> = withNewPayload(Unit)

  override fun toString(): String =
    MoreObjects
      .toStringHelper(this)
      .add("payload", payload::class.simpleName)
      .add("canonicalTokenCount", canonicalTokenCount)
      .add("surrogateTokenCount", surrogateTokenCount)
      .add("totalCharacterCount", totalCharacterCount)
      .add("nonBlankCharacterCount", nonBlankCharacterCount)
      .toString()

  companion object {
    /** A payload-free size with every count set to zero. */
    val ZERO: ProgramSize<Unit> =
      ProgramSize(
        payload = Unit,
        canonicalTokenCount = 0,
        surrogateTokenCount = 0,
        totalCharacterCount = 0,
        nonBlankCharacterCount = 0,
      )
  }
}
