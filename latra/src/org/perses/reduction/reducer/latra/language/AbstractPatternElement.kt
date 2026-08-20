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

import com.google.common.base.MoreObjects
import org.antlr.v4.runtime.CommonToken
import org.antlr.v4.runtime.Token
import org.perses.program.TokenPosition

sealed class AbstractPatternElement {
  abstract val originalSourceCode: String

  abstract fun replaceHolesWith(holeReplacements: Map<Hole.HoleName, String>): String

  /**
   * We use system identity for equality test.
   */
  final override fun hashCode(): Int = super.hashCode()

  /**
   * We use system identity for equality test.
   */
  final override fun equals(other: Any?): Boolean = super.equals(other)

  abstract fun line(): Int

  abstract fun charPositionInLine(): Int

  class ConcreteToken(
    token: Token,
  ) : AbstractPatternElement() {
    // Make sure a new token is created because the Antlr-created token can reference many
    // irrelevant objects.
    val token =
      CommonToken(
        token.type,
        token.text.plus(""),
      ).also {
        it.line = token.line
        it.charPositionInLine = token.charPositionInLine
      }

    override fun line(): Int = token.line

    override fun charPositionInLine(): Int = token.charPositionInLine

    override val originalSourceCode: String
      get() = token.text

    override fun replaceHolesWith(holeReplacements: Map<Hole.HoleName, String>): String =
      originalSourceCode

    override fun toString(): String =
      MoreObjects.toStringHelper(this).addValue("'${token.text}'").toString()
  }

  data class Hole(
    val holeName: HoleName,
    val greedyKleenePlusMatching: Boolean,
    val tokenPosition: TokenPosition,
  ) : AbstractPatternElement() {
    override val originalSourceCode: String by lazy {
      printHoleDefinition(holeName, greedyKleenePlusMatching)
    }

    override fun line(): Int = tokenPosition.line

    override fun charPositionInLine(): Int = tokenPosition.charPositionInLine

    override fun replaceHolesWith(holeReplacements: Map<HoleName, String>): String =
      holeReplacements[holeName] ?: error("No value for hole $this")

    override fun toString(): String =
      MoreObjects
        .toStringHelper(this)
        .addValue(holeName)
        .add("greedy", greedyKleenePlusMatching)
        .toString()

    data class HoleName(
      val name: String,
    ) {
      init {
        require(name.isNotEmpty())
        require(Character.isLetter(name.first()))
        (1 until name.length).forEach {
          require(
            Character.isLetterOrDigit(name[it]) || name[it] == '_',
          )
        }
      }

      override fun toString(): String = name

      fun printAsHoleDefinition(): String =
        printHoleDefinition(holeName = this, greedyKleenePlusMatching = false)
    }

    companion object {
      fun create(
        holeName: String,
        greedyKleenePlusMatching: Boolean,
        tokenPosition: TokenPosition,
      ) = Hole(HoleName(holeName), greedyKleenePlusMatching, tokenPosition)

      fun printHoleDefinition(
        holeName: HoleName,
        greedyKleenePlusMatching: Boolean,
      ): String = ":[${holeName.name}${if (greedyKleenePlusMatching) "+" else ""}]"
    }
  }

  data class Trivia(
    override val originalSourceCode: String,
    val tokenPosition: TokenPosition,
  ) : AbstractPatternElement() {
    init {
      require(originalSourceCode.isNotEmpty())
    }

    override fun line(): Int = tokenPosition.line

    override fun charPositionInLine(): Int = tokenPosition.charPositionInLine

    fun isBlank() = originalSourceCode.isBlank()

    override fun replaceHolesWith(holeReplacements: Map<Hole.HoleName, String>): String =
      originalSourceCode

    override fun toString(): String =
      MoreObjects
        .toStringHelper(this)
        .addValue("\"$originalSourceCode\"")
        .toString()
  }
}
