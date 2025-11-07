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

import org.perses.util.Util
import org.perses.util.toImmutableList
import java.io.Closeable
import kotlin.reflect.KClass

abstract class AbstractListMinimizerListener : Closeable {
  abstract fun startReduction(
    originalInput: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
  )

  abstract fun endReduction(
    minimizationResult: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
    sizeOfOriginalInput: Int,
  )

  abstract fun onBestUpdate(newBest: List<ElementWrapper<*>>)

  abstract fun onPropertyTest(
    configuration: Candidate<*>,
    result: LMPropertyTestResult<*, *>,
    sizeOfOriginalList: Int,
    sizeOfCurrentMinimizationResult: Int,
  )

  abstract fun log(msg: () -> String)

  companion object {
    fun convertElementListToCompactString(list: List<ElementWrapper<*>>): String {
      val clusteredString = clusterIdsIntoRanges(list).joinToString(separator = ",")
      val maxLength = 20
      return if (clusteredString.length > maxLength) {
        "[${clusteredString.substring(0, maxLength)}...]"
      } else {
        "[$clusteredString]"
      } + "#${list.size}"
    }

    fun clusterIdsIntoRanges(list: List<ElementWrapper<*>>): List<String> =
      Util.clusterIdsIntoRanges(list, idExtractor = {
        it.index
      })

    // TODO(cnsun): need tests.
    fun smartCombine(
      listenerOne: AbstractListMinimizerListener?,
      listenerTwo: AbstractListMinimizerListener?,
    ): AbstractListMinimizerListener {
      val result = mutableListOf<AbstractListMinimizerListener>()
      if (listenerOne != null && listenerOne !is NullListMinimizerListener) {
        result.add(listenerOne)
      }
      if (listenerTwo != null && listenerTwo !is NullListMinimizerListener) {
        result.add(listenerTwo)
      }
      return when (result.size) {
        0 -> NullListMinimizerListener
        1 -> result.single()
        else -> CompoundListMinimizerListener(listeners = result.toImmutableList())
      }
    }
  }
}
