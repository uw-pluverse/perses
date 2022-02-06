/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.util.cmd

object CommonCmdOptionGroupOrder {

  const val COMPULSORY = 0
  const val RESULT_OUTPUT = 20000
  const val REDUCTION_CONTROL = 40000
  const val OUTPUT_REFINING = 60000
  const val ALG_CONTROL = 80000
  const val GRAMMAR_CONTROL = 90000
  const val CACHE_CONTROL = 100000
  const val PROFILING_CONTROL = 120000
  const val VERBOSITY_CONTROL = 130000
  const val HELP = 160000
  const val EXPERIMENT = 180000
}
