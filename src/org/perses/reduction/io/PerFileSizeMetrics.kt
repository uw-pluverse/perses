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
package org.perses.reduction.io

import com.google.common.collect.ImmutableList
import org.perses.program.AbstractReductionFile
import org.perses.program.ProgramSize
import org.perses.util.ImmutableIntArray
import org.perses.util.toImmutableList

/**
 * The size metrics of every mutable file of a reduction, one slot per file, aligned by index with
 * [AbstractOriginalReductionInputs.mutableFiles] (see [AbstractOriginalReductionInputs.indexOfMutableFile]).
 *
 * Every slot is always known: the caller provides the size of each mutable file at construction.
 * A caller that learns sizes incrementally (e.g. a sweep that reduces one file at a time) tracks
 * its partial knowledge itself and constructs this class once every file has been measured.
 *
 * The slots keep their payloads as given. A caller that retains an instance for long can strip
 * them with [ProgramSize.withoutPayload].
 *
 * Instances are immutable; updating a slot returns a new instance.
 */
class PerFileSizeMetrics(
  val originalReductionInputs: AbstractOriginalReductionInputs,
  private val sizes: ImmutableList<out ProgramSize<*>>,
) {
  init {
    check(sizes.size == originalReductionInputs.mutableFiles.size) {
      "Expected one slot per mutable file: " +
        "sizes=$sizes, mutableFiles=${originalReductionInputs.mutableFiles}"
    }
  }

  fun sizeAt(index: Int): ProgramSize<*> = sizes[index]

  fun sizeOf(file: AbstractReductionFile<*, *>): ProgramSize<*> =
    sizes[originalReductionInputs.indexOfMutableFile(file)]

  /** The c-vise-style user-facing total over all mutable files. */
  val totalCanonicalTokenCount: Int
    get() = sizes.sumOf { it.canonicalTokenCount }

  val totalSurrogateTokenCount: Int
    get() = sizes.sumOf { it.surrogateTokenCount }

  val totalCharacterCount: Int
    get() = sizes.sumOf { it.totalCharacterCount }

  val totalNonBlankCharacterCount: Int
    get() = sizes.sumOf { it.nonBlankCharacterCount }

  fun replacingAt(
    index: Int,
    newSize: ProgramSize<*>,
  ): PerFileSizeMetrics {
    require(index in sizes.indices) {
      "index=$index, size=${sizes.size}"
    }
    return PerFileSizeMetrics(
      originalReductionInputs,
      sizes
        .mapIndexed { i, size -> if (i == index) newSize else size }
        .toImmutableList(),
    )
  }

  fun replacing(
    file: AbstractReductionFile<*, *>,
    newSize: ProgramSize<*>,
  ): PerFileSizeMetrics = replacingAt(originalReductionInputs.indexOfMutableFile(file), newSize)

  /**
   * The size vector the query cache evicts against (`evictEntriesNotSmallerThan`): the non-blank
   * character count of each mutable file, in slot order.
   *
   * Non-blank character count, rather than token count, is used because it is a pure function of the
   * rendered lexemes (see `TokenizedProgram.nonBlankCharacterCount`) and so needs no canonical
   * re-lexing -- it is well-defined and identical across every reducer, including surrogate-facade
   * ones (line slicer, Dyck/wasm) whose candidates are not always canonically lexable. A variant
   * that is a subsequence of the current minimum has no more non-blank characters than it, so the
   * eviction-safety argument still holds.
   */
  fun perFileNonBlankCharacterCounts(): ImmutableIntArray {
    val builder = ImmutableIntArray.builder(sizes.size)
    sizes.forEach { builder.add(it.nonBlankCharacterCount) }
    return builder.build()
  }

  override fun toString(): String =
    sizes
      .mapIndexed { index, size ->
        "${originalReductionInputs.mutableFiles[index].baseName}=$size"
      }.joinToString(prefix = "PerFileSizeMetrics{", separator = ", ", postfix = "}")
}
