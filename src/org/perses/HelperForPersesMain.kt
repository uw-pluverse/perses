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
package org.perses

import org.perses.AbstractMain.LanguageAndParserConfiguration
import org.perses.cmd.LanguageControlFlagGroup
import org.perses.grammar.AbstractParserFacadeFactory

object HelperForPersesMain {
  fun computeLanguageAndParserConfiguration(
    parserFacadeFactory: AbstractParserFacadeFactory,
    flags: LanguageControlFlagGroup,
  ): LanguageAndParserConfiguration =
    when {
      flags.designatedParserFacadeClassName.isNotBlank() -> {
        val result =
          parserFacadeFactory.getParserFacadeClassForClassNameOrNull(
            flags.designatedParserFacadeClassName,
          )
        check(result != null) {
          "Failed to find parser facade for ${flags.designatedParserFacadeClassName}"
        }
        LanguageAndParserConfiguration.UserSpecifiedParser(
          languageKind = result.first,
          parserFacade = result.second,
        )
      }

      flags.languageName.isNotBlank() -> {
        val result =
          parserFacadeFactory.computeLanguageKindWithLanguageNameIgnoreCase(flags.languageName)
        check(result != null) {
          "Failed to find the language for ${flags.languageName}"
        }
        LanguageAndParserConfiguration.UserSpecifiedLanguage(
          languageKind = result,
        )
      }

      else -> {
        LanguageAndParserConfiguration.Automatic
      }
    }
}
