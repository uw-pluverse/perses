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
package org.perses.listminimizer

import kotlin.reflect.KClass

object NullListMinimizerListener : AbstractListMinimizerListener() {
  override fun startReduction(
    originalInput: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
  ) {
  }

  override fun endReduction(
    minimizationResult: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
    sizeOfOriginalInput: Int,
  ) {
  }

  override fun onBestUpdate(newBest: List<ElementWrapper<*>>) {
  }

  override fun onPropertyTest(
    configuration: Candidate<*>,
    result: LMPropertyTestResult<*, *>,
    sizeOfOriginalList: Int,
    sizeOfCurrentMinimizationResult: Int,
  ) {
  }

  override fun log(msg: () -> String) {
  }

  override fun close() {
  }
}
