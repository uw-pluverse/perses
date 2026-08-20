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
package org.perses.reduction

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import org.perses.program.ProgramSize
import org.perses.util.hashing.ShaHashCode

data class StatsOfFilesBeingReduced(
  /**
   * The size of the program being reduced, carried whole rather than projected onto a couple of
   * Ints, so that the scheduler orders snapshots by the very [ProgramSize.compareTo] the reducers
   * use to pick the reduction result. Payload-free: a snapshot is appended for every reducer call,
   * and retaining the payloads would pin every intermediate program for the whole run.
   */
  val size: ProgramSize<Unit>,
  val fileContents: ImmutableList<FileNameAndContentDigestPair>,
) {
  data class FileNameAndContentDigestPair(
    val fileName: String,
    val contentDigest: ShaHashCode,
  ) {
    override fun toString(): String =
      MoreObjects
        .toStringHelper(this)
        .add("fileName", fileName)
        .add("contentDigest", contentDigest.numOfStrings)
        .toString()
  }
}
