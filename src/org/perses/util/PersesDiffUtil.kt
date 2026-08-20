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
package org.perses.util

import difflib.DiffUtils

object PersesDiffUtil {
  fun <T> diff(
    main: List<T>,
    other: List<T>,
    equalizer: (T, T) -> Boolean,
  ) = DiffUtils.diff(main, other, equalizer)

  /**
   * Renders the line-level changes from [originalLines] to [revisedLines] as a unified diff (the same
   * `--- / +++ / @@ / -/+` format `diff -u` produces), with [contextSize] lines of unchanged context
   * around each hunk. [originalLabel] and [revisedLabel] become the `---`/`+++` header names. Returns
   * an empty list when the two inputs are identical.
   */
  fun unifiedDiff(
    originalLabel: String,
    revisedLabel: String,
    originalLines: List<String>,
    revisedLines: List<String>,
    contextSize: Int,
  ): List<String> {
    val patch = DiffUtils.diff(originalLines, revisedLines)
    return DiffUtils.generateUnifiedDiff(originalLabel, revisedLabel, originalLines, patch, contextSize)
  }
}
