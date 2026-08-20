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
package org.perses.cmd

/**
 * The two halves of list-minimizer microbenchmarking. One flag rather than two independent switches,
 * so that "recording and evaluating at once" is unrepresentable rather than a state `validate()` has
 * to reject.
 *
 * Unset -- the flag is nullable and defaults to null -- means neither: an ordinary reduction.
 */
enum class EnumListMinimizerMicrobenchmarkingMode {
  /**
   * Run an ordinary reduction, capturing each list-minimization problem it encounters. The reduction
   * itself is unaffected; recording is a side effect of the reducers invoking a list minimizer.
   */
  RECORD,

  /** Run one list minimizer against one recorded problem, and report its cost and result. */
  EVALUATE,
}
