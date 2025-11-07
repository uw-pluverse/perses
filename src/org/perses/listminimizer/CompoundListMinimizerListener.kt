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

import com.google.common.collect.ImmutableList
import com.google.common.io.Closer
import kotlin.reflect.KClass

class CompoundListMinimizerListener(
  private val listeners: ImmutableList<AbstractListMinimizerListener>,
) : AbstractListMinimizerListener() {
  init {
    require(listeners.size > 1) {
      "$listeners must have at least two listener."
    }
    require(listeners.isNotEmpty()) {
      "The listeners are empty."
    }
    require(listeners.none { it === NullListMinimizerListener }) {
      "Cannot have null listeners inside"
    }
  }

  override fun startReduction(
    originalInput: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
  ) {
    listeners.forEach { it.startReduction(originalInput, listMinimizerClass) }
  }

  override fun endReduction(
    minimizationResult: List<ElementWrapper<*>>,
    listMinimizerClass: KClass<out AbstractListMinimizer<*, *>>,
    sizeOfOriginalInput: Int,
  ) {
    listeners.forEach {
      it.endReduction(
        minimizationResult,
        listMinimizerClass,
        sizeOfOriginalInput,
      )
    }
  }

  override fun onBestUpdate(newBest: List<ElementWrapper<*>>) {
    listeners.forEach { it.onBestUpdate(newBest) }
  }

  override fun onPropertyTest(
    configuration: Candidate<*>,
    result: LMPropertyTestResult<*, *>,
    sizeOfOriginalList: Int,
    sizeOfCurrentMinimizationResult: Int,
  ) {
    listeners.forEach {
      it.onPropertyTest(
        configuration,
        result,
        sizeOfOriginalList = sizeOfOriginalList,
        sizeOfCurrentMinimizationResult = sizeOfCurrentMinimizationResult,
      )
    }
  }

  override fun log(msg: () -> String) {
    listeners.forEach { it.log(msg) }
  }

  override fun close() {
    val closer = Closer.create()
    // The Closer object handles exceptions better.
    listeners.forEach { closer.register(it) }
    closer.close()
  }

  companion object {
    // TODO(cnsun): test this method.
    fun smartCombine(
      listenerOne: AbstractListMinimizerListener,
      listenerTwo: AbstractListMinimizerListener,
    ): CompoundListMinimizerListener {
      require(
        listenerOne != NullListMinimizerListener &&
          listenerTwo != NullListMinimizerListener,
      ) {
        "Cannot combine ${NullListMinimizerListener::class} with other listeners."
      }
      return CompoundListMinimizerListener(
        ImmutableList.of(listenerOne, listenerTwo),
      )
    }
  }
}
