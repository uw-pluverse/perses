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
package org.perses.reduction.reducer.latra

import org.perses.reduction.reducer.latra.language.LatraTransformationDefinition
import org.perses.reduction.reducer.latra.language.io.RawDefinition
import org.perses.reduction.reducer.latra.language.io.RawGlobalReplaceClausesBuilder
import org.perses.reduction.reducer.latra.language.io.RawInsertClausesBuilder
import org.perses.util.transformToImmutableList

abstract class AbstractLatraTransformationList {
  private val transformations = ArrayList<Transformation>()

  fun transformations(): List<Transformation> = transformations

  fun createLatraTransformations(latraArgs: LatraArguments) =
    transformations.transformToImmutableList {
      it.create(
        latraArgs.createWithNewExtraSuffixOfPrefix(
          extraSuffixOfPrefix = "[${it.rawDefinition.name}]",
        ),
      )
    }

  protected fun registerTransformation(
    name: String,
    from: String = "",
    such_as: String = "",
    where: String = "",
    to: String = "",
    insert: RawInsertClausesBuilder.() -> Unit = {},
    global_replace: RawGlobalReplaceClausesBuilder.() -> Unit = {},
  ): Transformation {
    val rawDefinition =
      RawDefinition(
        name = name,
        from = from,
        such_as = such_as,
        where = where,
        to = to,
        insert =
          RawInsertClausesBuilder().let {
            it.insert()
            it.build()
          },
        global_replace =
          RawGlobalReplaceClausesBuilder().let {
            it.global_replace()
            it.build()
          },
      )
    return registerTransformation(rawDefinition)
  }

  private fun registerTransformation(rawDefinition: RawDefinition): Transformation {
    require(transformations.none { it.rawDefinition.name == rawDefinition.name }) {
      "Duplicate transformation ${rawDefinition.name}"
    }
    val transformation =
      Transformation(
        rawDefinition,
        creator = { parsingRelatedArguments: LatraArguments ->
          createTransformation(parsingRelatedArguments, rawDefinition)
        },
      )
    check(transformations.add(transformation))
    return transformation
  }

  data class Transformation(
    val rawDefinition: RawDefinition,
    val creator: (LatraArguments) -> LatraTransformation,
  ) {
    fun create(parsingRelatedArguments: LatraArguments): LatraTransformation =
      creator(parsingRelatedArguments)
  }

  companion object {
    fun createTransformation(
      parsingRelatedArguments: LatraArguments,
      rawDefinition: RawDefinition,
    ): LatraTransformation =
      LatraTransformation(
        latraArguments = parsingRelatedArguments,
        definition =
          LatraTransformationDefinition.parse(
            rawDefinition = rawDefinition,
            parserFacade = parsingRelatedArguments.parserFacade,
          ),
      )
  }
}
