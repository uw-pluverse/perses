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
package org.perses.reduction.semantics

import com.google.common.collect.ImmutableList

class LayerHierarchy<T : Any>(
  val layersFromTopToBottom: ImmutableList<AbstractLayer<T>>,
) {
  init {
    require(layersFromTopToBottom.isNotEmpty()) { "There must be at least one layer" }
  }

  fun isBottomLayer(layer: AbstractLayer<T>): Boolean = layersFromTopToBottom.last() === layer

  companion object {
    private val EMPTY =
      LayerHierarchy(
        layersFromTopToBottom = ImmutableList.of(AbstractLayer.Layer(nodes = ImmutableList.of())),
      )

    fun <T : Any> emptyHierarchy(): LayerHierarchy<T> {
      @Suppress("UNCHECKED_CAST")
      return EMPTY as LayerHierarchy<T>
    }
  }
}
