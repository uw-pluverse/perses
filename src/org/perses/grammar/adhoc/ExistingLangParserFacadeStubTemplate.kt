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
package org.perses.grammar.adhoc

import java.nio.file.Path

class ExistingLangParserFacadeStubTemplate(
  packageName: String,
  parserClassSimpleName: String,
  lexerClassSimpleName: String,
  startRuleName: String,
  grammarName: String,
  parserFile: Path,
  lexerFile: Path?,
  private val existingLanguageFullClassName: String,
  parserFacadeClassSimpleName: String,
  tokenNamesOfIdentifiers: List<String>,
) : AbstractParserFacadeStubTemplate(
  packageName,
  parserClassSimpleName,
  lexerClassSimpleName,
  startRuleName,
  grammarName,
  parserFile,
  lexerFile,
  parserFacadeClassSimpleName,
  tokenNamesOfIdentifiers,
) {

  override fun createLanguageKind(): String {
    return """
     
  static {
    try {
      $fieldNameLanguage = (LanguageKind)Class.forName("$existingLanguageFullClassName")
      .getField("INSTANCE").get(null);
    } catch(Exception e) {
      throw new RuntimeException(e); 
    }
  } 
  
    """
  }
}
