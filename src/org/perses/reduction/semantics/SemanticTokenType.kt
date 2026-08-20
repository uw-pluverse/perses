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

import com.google.common.base.MoreObjects
import java.util.concurrent.ConcurrentHashMap

class SemanticTokenType private constructor(
  val typeName: String,
) {
  override fun toString(): String = MoreObjects.toStringHelper(this).addValue(typeName).toString()

  companion object {
    private val allTypes = ConcurrentHashMap<String, SemanticTokenType>()

    fun of(typeName: String): SemanticTokenType =
      allTypes.computeIfAbsent(typeName) {
        SemanticTokenType(typeName)
      }

    val VARIABLE = of("variable")
    val FUNCTION = of("function")
    val METHOD = of("method")
    val PARAMETER = of("parameter")
    val FIELD = of("field")

    /**
     * Used for language servers (like JDTLS) that classify class fields as "property"
     * in their semantic tokens.
     */
    val PROPERTY = of("property")
  }
}
