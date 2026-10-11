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
package org.perses.listminimizer.microbenchmark

import com.google.common.hash.HashCode
import org.perses.util.AtomicSequenceGenerator
import org.perses.util.CollectionUtil
import org.perses.util.hashing.EnumShaAlgorithm
import org.perses.util.hashing.ShaHashCode

/**
 * Issues the ids of recorded problems and remembers which problems they were, so that a problem is
 * recorded once. One instance is shared by every writer of a reduction: a multi-file reduction runs
 * a driver per file, and a registry each would restart the sequence, collide folder names, turn the
 * cap into a per-file limit, and record again a problem another driver already recorded.
 */
class ListMinimizationProblemRegistry(
  idWidth: Int,
  val shaAlgorithm: EnumShaAlgorithm,
) {
  private val idGenerator = AtomicSequenceGenerator(start = 0, minLengthForPadding = idWidth)

  private val registeredDigests = CollectionUtil.createConcurrentSet<ProblemDigest>()

  val registeredCount: Int
    get() = idGenerator.issuedCount

  /**
   * Issues a new id to the problem with [digest], or returns null if a problem with the same digest
   * already has one. Two writers that meet the same problem at once cannot both record it, because
   * only one of them adds the digest.
   */
  fun register(digest: ProblemDigest): String? =
    if (registeredDigests.add(digest)) idGenerator.next() else null

  /** What identifies a recorded problem; the writer's `computeProblemDigest` says why. */
  data class ProblemDigest(
    /** The target file's path first, then every input file's, relative to `input/`. */
    val filePaths: ShaHashCode,
    val fileContents: ShaHashCode,
    /** The token offsets and the elements' token ranges. */
    val list: HashCode,
  )
}
