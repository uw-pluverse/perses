/*
 * Copyright (C) 2018-2024 University of Waterloo.
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
package org.perses.grammar

import com.google.common.collect.ImmutableList

data class ParserFacadeTag private constructor(val tagName: String) {

  init {
    check(tagName.lowercase() == tagName) { "The tag name should be in lower case." }
  }

  companion object {

    const val NAME_PNF = "pnf"
    const val NAME_ORIGINAL = "original"
    private val BUILTIN_TAGS = ImmutableList.of(
      ParserFacadeTag(NAME_PNF),
      ParserFacadeTag(NAME_ORIGINAL),
    )

    val BUILTIN_TAG_PNF = BUILTIN_TAGS.single { it.tagName == NAME_PNF }

    val BUILTIN_TAG_ORIGINAL = BUILTIN_TAGS.single { it.tagName == NAME_ORIGINAL }

    fun create(tagName: String): ParserFacadeTag {
      require(BUILTIN_TAGS.none { it.tagName == tagName }) {
        "tag name clashes with builtin tags. $tagName"
      }
      return ParserFacadeTag(tagName)
    }
  }
}
