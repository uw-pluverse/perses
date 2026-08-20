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
package org.perses.reduction.reducer

enum class EnumMimirReductionAlgorithm(
  val deleteShadowing: Boolean,
  // If the property is null, that means the value is not applicable.
  val deleteLayersFromTopToBottom: Boolean?,
) {
  LAYER_BY_LAYER_TOP_DOWN(
    deleteShadowing = false,
    deleteLayersFromTopToBottom = true,
  ),
  LAYER_BY_LAYER_TOP_DOWN_PLUS(
    deleteShadowing = true,
    deleteLayersFromTopToBottom = true,
  ),
  LAYER_BY_LAYER_BOTTOM_UP(
    deleteShadowing = false,
    deleteLayersFromTopToBottom = false,
  ),
  LAYER_BY_LAYER_BOTTOM_UP_PLUS(
    deleteShadowing = true,
    deleteLayersFromTopToBottom = false,
  ),

  BOTTOM_LAYER_FIRST_THEN_TOPDOWN_PLUS(
    deleteShadowing = true,
    deleteLayersFromTopToBottom = true,
  ),

  DAG_AS_LIST(
    deleteShadowing = true,
    deleteLayersFromTopToBottom = null,
  ),

  FINE_DAG_AS_LIST(
    deleteShadowing = true,
    deleteLayersFromTopToBottom = null,
  ),

  FINER_DAG_AS_LIST(
    deleteShadowing = true,
    deleteLayersFromTopToBottom = null,
  ),

  /**
   * Very bad performance.
   */
  DFS_DAG(deleteShadowing = true, deleteLayersFromTopToBottom = null),
}
