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
package org.perses.reduction.crossfile

import com.google.common.collect.ImmutableMap
import org.perses.program.AbstractReductionFile

/**
 * The whole-set program a *true* multi-file reduction reduces: the current content of every mutable
 * file, keyed by the file.
 *
 * Unlike single-tree reduction -- which reduces one file at a time against fixed siblings -- a
 * [CrossFileProgram] describes the entire mutable-file set at once, so a single transformation can
 * change several files together (e.g. removing an overriding method from a base class and all its
 * subclasses in one edit). It is the `Program` type plugged into the generic reduction stack
 * (`AbstractReductionIOManager` / `AbstractOutputManagerFactory` / `AbstractReducer`), exactly as
 * the ppr list-diff reducer plugs in its diff op-list.
 *
 * [fileContents] holds content for every *currently-live* mutable file of the reduction; the output
 * manager reads each file's content straight from it. The set of keys is the live set: it starts as
 * every mutable file and only ever shrinks, when a file driven down to empty is dropped from the set
 * by the empty-file-deletion reducer (a file-set change, not a content edit). The set can shrink all
 * the way to empty: the interestingness test is an arbitrary shell script and may require no input
 * files at all, so dropping every file is a legitimate (maximal) outcome.
 */
class CrossFileProgram(
  val fileContents: ImmutableMap<AbstractReductionFile<*, *>, String>,
) {
  /** The content of [file]; [file] must be one of the live files this program was built over. */
  operator fun get(file: AbstractReductionFile<*, *>): String =
    requireNotNull(fileContents[file]) {
      "The multi-file program has no content for mutable file: $file"
    }

  /**
   * A copy of this program with [filesToDrop] removed from the live set. The result may be empty:
   * a test can require no input files, so dropping every file is a valid candidate. Used by the
   * empty-file-deletion reducer to render a candidate in which the dropped files are absent.
   */
  fun without(filesToDrop: Collection<AbstractReductionFile<*, *>>): CrossFileProgram {
    if (filesToDrop.isEmpty()) {
      return this
    }
    // For a tiny drop list (e.g. the greedy path drops a single file), a linear `contains` is cheaper
    // than building a hash set; only pay to convert when the list is large enough for the O(1) lookup
    // to win.
    val dropLookup =
      if (filesToDrop.size <= SMALL_DROP_LIST_THRESHOLD) filesToDrop else filesToDrop.toHashSet()
    return CrossFileProgram(ImmutableMap.copyOf(fileContents.filterKeys { it !in dropLookup }))
  }

  private companion object {
    private const val SMALL_DROP_LIST_THRESHOLD = 4
  }
}
