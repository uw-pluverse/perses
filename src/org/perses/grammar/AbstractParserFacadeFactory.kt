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

import com.google.common.io.Files
import org.perses.program.LanguageKind
import java.nio.file.Path

abstract class AbstractParserFacadeFactory {

  abstract fun createParserFacade(languageKind: LanguageKind): AbstractParserFacade

  fun containsLanguage(languageKind: LanguageKind): Boolean {
    return languageSequence().any { it == languageKind }
  }

  fun computeLanguageKindWithFileName(file: Path): LanguageKind? {
    val ext = Files.getFileExtension(file.fileName.toString())
    return languageSequence().firstOrNull {
      ext in it.extensions
    }
  }

  fun computeLanguageKindWithLanguageNameIgnoreCase(languageName: String): LanguageKind? {
    val lowerCase = languageName.lowercase()
    return languageSequence().firstOrNull() {
      it.name.lowercase() == lowerCase
    }
  }

  fun computeLanguageKindOrThrow(file: Path): LanguageKind {
    val language = computeLanguageKindWithFileName(file)
    if (language != null) {
      return language
    }
    reportError("Failed to detect the language kind for file $file\n")
  }

  internal abstract fun languageSequence(): Sequence<LanguageKind>

  internal fun reportError(prefix: String): Nothing {
    val errorMessage = buildString {
      append(prefix).append('\n')
      append("The available languages are listed below:\n")
      languageSequence().forEach { language ->
        append("  ${language.name}: exts=${language.extensions}\n")
      }
    }
    error(errorMessage)
  }
}
