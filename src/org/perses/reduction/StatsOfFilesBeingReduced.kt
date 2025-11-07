/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
import org.perses.util.hashing.ShaHashCode

data class StatsOfFilesBeingReduced(
  val tokenCount: Int,
  val characterCount: Int,
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
