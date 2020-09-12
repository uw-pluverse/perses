/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.program

import com.google.common.collect.ImmutableMap
import com.google.common.collect.ImmutableSet
import com.google.common.io.Files
import java.io.File

object LanguageRegistry {

  val buildinLanguages = ImmutableSet.of(
    LanguageC,
    LanguageJava,
    LanguageRust,
    LanguageGo,
    LanguageScala
  )

  private val fileExtToLanguageMap = buildinLanguages
    .asSequence()
    .flatMap { language -> language.extensions.asSequence().map { it to language } }
    .fold(
      ImmutableMap.builder<String, LanguageKind>(),
      { builder, pair -> builder.put(pair.first, pair.second) }
    )
    .build()

  fun computeLanguageKind(file: File): LanguageKind? {
    val ext = Files.getFileExtension(file.name)
    return fileExtToLanguageMap.get(ext)
  }
}
