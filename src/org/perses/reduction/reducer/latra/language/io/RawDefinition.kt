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
package org.perses.reduction.reducer.latra.language.io

import com.fasterxml.jackson.core.type.TypeReference
import com.google.common.collect.ImmutableList
import org.perses.util.Serialization

data class RawDefinition(
  val name: String,
  val from: String,
  val such_as: String = "",
  val where: String = "",
  val to: String,
  val insert: ImmutableList<RawInsertClause> = ImmutableList.of(),
  val global_replace: ImmutableList<RawGlobalReplaceClause> = ImmutableList.of(),
) {
  fun toYamlString(): String = Serialization.toYamlString(this)

  companion object {
    fun fromYamlString(string: String): RawDefinition =
      Serialization.fromYamlString(
        string,
        typeReference = TYPE_REFERENCE,
      )

    private val TYPE_REFERENCE = object : TypeReference<RawDefinition>() {}
  }
}

class RawInsertClausesBuilder {
  private val builder = ImmutableList.builder<RawInsertClause>()

  fun insert(
    pattern: String,
    location: String,
  ) {
    builder.add(RawInsertClause(pattern, location))
  }

  fun build(): ImmutableList<RawInsertClause> = builder.build()
}

class RawGlobalReplaceClausesBuilder {
  private val builder = ImmutableList.builder<RawGlobalReplaceClause>()

  fun replace(
    pattern: String,
    such_as: String = "",
    inside: String = "",
    with: String = "",
    mustMatch: Boolean = false,
    matchAll: Boolean = false,
  ) {
    builder.add(RawGlobalReplaceClause(pattern, such_as, inside, with, mustMatch, matchAll))
  }

  fun build() = builder.build()
}

data class RawInsertClause(
  val pattern: String,
  val location: String,
)

/**
 * @property mustMatch If true, the pattern must match at least once;
 * otherwise, this clause may be skipped.
 * @property matchAll If true, all occurrences of the pattern are replaced;
 * if false, only the first match is replaced.
 */
data class RawGlobalReplaceClause(
  val pattern: String,
  val such_as: String = "",
  val inside: String = "",
  val with: String = "",
  val mustMatch: Boolean = false,
  val matchAll: Boolean = false,
)
