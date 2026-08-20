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
package org.perses.reduction.reducer.latra.language

import com.google.common.collect.ImmutableList
import org.perses.grammar.AbstractParserFacade
import org.perses.reduction.reducer.latra.language.io.RawDefinition
import org.perses.reduction.reducer.latra.language.io.RawGlobalReplaceClause
import org.perses.reduction.reducer.latra.language.io.RawInsertClause
import org.perses.util.Serialization
import org.perses.util.toImmutableList
import org.perses.util.transformToImmutableList

data class LatraTransformationDefinition(
  val name: String,
  val matchingTemplate: MatchingTemplate,
  val rewritingTemplate: RewritingTemplate,
) {
  init {
    validateHolesInRewritePattern()
  }

  fun toYamlString(): String = Serialization.toYamlString(this)

  private fun validateHolesInRewritePattern() {
    val fromClause = matchingTemplate.from
    val toClause = rewritingTemplate.to
    val rewriteHoles = toClause.pattern.holes
    val matchHoles = fromClause.pattern.holes.map { it.holeName }
    rewriteHoles.forEach {
      require(it.holeName in matchHoles) {
        """
          |Hole $it is not defined in the match pattern.
          |match pattern: ${fromClause.sourceCode}
          |rewrite pattern: ${toClause.sourceCode}
        """.trimMargin()
      }
    }
  }

  data class MatchingTemplate(
    val from: FromClause,
    val suchAs: SuchAsClause = SuchAsClause.EMPTY,
    val where: WhereClause = WhereClause.EMPTY,
  ) {
    companion object {
      fun parse(
        rawDefinition: RawDefinition,
        parserFacade: AbstractParserFacade,
      ): MatchingTemplate =
        MatchingTemplate(
          from = FromClause.parse(rawDefinition.from, parserFacade),
          suchAs = SuchAsClause(rawDefinition.such_as),
          where = WhereClause.parse(rawDefinition.where, parserFacade),
        )

      val EMPTY =
        MatchingTemplate(
          from = FromClause.EMPTY,
          suchAs = SuchAsClause.EMPTY,
          where = WhereClause.EMPTY,
        )
    }
  }

  data class RewritingTemplate(
    val to: ToClause,
    val insert: ImmutableList<InsertClause> = ImmutableList.of(),
    val globalReplace: ImmutableList<GlobalReplaceClause> = ImmutableList.of(),
  ) {
    companion object {
      fun parse(
        rawDefinition: RawDefinition,
        parserFacade: AbstractParserFacade,
      ): RewritingTemplate =
        RewritingTemplate(
          to = ToClause.parse(rawDefinition.to, parserFacade),
          insert =
            rawDefinition.insert.transformToImmutableList { rawInsert ->
              InsertClause.parse(rawInsert, parserFacade)
            },
          globalReplace =
            rawDefinition.global_replace.transformToImmutableList { raw ->
              GlobalReplaceClause.parse(raw, parserFacade)
            },
        )

      val EMPTY =
        RewritingTemplate(
          to = ToClause.EMPTY,
          insert = ImmutableList.of(),
          globalReplace = ImmutableList.of(),
        )
    }
  }

  data class InsertClause(
    val contentToInsert: ToClause,
    val location: InsertPosition,
  ) {
    companion object {
      fun parse(
        rawInsertClause: RawInsertClause,
        parserFacade: AbstractParserFacade,
      ): InsertClause =
        InsertClause(
          contentToInsert = ToClause.parse(rawInsertClause.pattern, parserFacade),
          location = InsertPosition.parse(rawInsertClause.location),
        )
    }

    enum class InsertPosition(
      val value: String,
    ) {
      INSERT_AT_TOP("top"),
      INSERT_AT_BOTTOM("bottom"),
      INSERT_BEFORE_MATCH("before"),
      INSERT_AFTER_MATCH("after"),
      ;

      companion object {
        private val VALUE_LIST = entries.toTypedArray().toImmutableList()

        fun parse(value: String): InsertPosition {
          val result = VALUE_LIST.singleOrNull { it.value == value }
          checkNotNull(result) {
            "Cannot find insertion position for $value in $VALUE_LIST"
          }
          return result
        }
      }
    }
  }

  data class GlobalReplaceClause(
    val from: FromClause,
    val suchAs: SuchAsClause,
    val inside: AbstractPatternElement.Hole.HoleName?,
    val with: ToClause,
    val mustMatch: Boolean,
    val matchAll: Boolean,
  ) {
    companion object {
      fun parse(
        raw: RawGlobalReplaceClause,
        parserFacade: AbstractParserFacade,
      ): GlobalReplaceClause =
        GlobalReplaceClause(
          from = FromClause.parse(raw.pattern, parserFacade),
          suchAs = SuchAsClause(raw.such_as),
          inside =
            if (raw.inside == "") {
              null
            } else {
              AbstractPatternElement.Hole.HoleName(raw.inside)
            },
          with = ToClause.parse(raw.with, parserFacade),
          mustMatch = raw.mustMatch,
          matchAll = raw.matchAll,
        )
    }
  }

  companion object {
    val EMPTY =
      LatraTransformationDefinition(
        name = "",
        matchingTemplate = MatchingTemplate.EMPTY,
        rewritingTemplate = RewritingTemplate.EMPTY,
      )

    fun parseYamlDefinition(
      rawDefinition: String,
      parserFacade: AbstractParserFacade,
    ): LatraTransformationDefinition =
      parse(RawDefinition.fromYamlString(rawDefinition), parserFacade)

    fun parse(
      rawDefinition: RawDefinition,
      parserFacade: AbstractParserFacade,
    ): LatraTransformationDefinition {
      val name = rawDefinition.name
      val matchingTemplate = MatchingTemplate.parse(rawDefinition, parserFacade)
      val rewritingTemplate = RewritingTemplate.parse(rawDefinition, parserFacade)
      return LatraTransformationDefinition(name, matchingTemplate, rewritingTemplate)
    }
  }
}
