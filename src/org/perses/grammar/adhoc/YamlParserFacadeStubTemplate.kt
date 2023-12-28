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

import com.google.common.io.BaseEncoding
import java.nio.file.Path

class YamlParserFacadeStubTemplate(
  packageName: String,
  parserClassSimpleName: String,
  lexerClassSimpleName: String,
  startRuleName: String,
  grammarName: String,
  parserFile: Path,
  lexerFile: Path?,
  val languageKindYamlString: String,
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
  parserFacadeClassSimpleName, tokenNamesOfIdentifiers,
) {

  override fun createLanguageKind(): String {
    return """
    private static String LANGUAGE_YAML_BASE64_ENCODED = 
      "${BaseEncoding.base64().encode(languageKindYamlString.toByteArray())}";
   
    static {
      $fieldNameLanguage = SerializableLanguageKind.fromYamlString(
        new String(BaseEncoding.base64().decode(LANGUAGE_YAML_BASE64_ENCODED), 
                java.nio.charset.StandardCharsets.UTF_8)
      );
    }
    """.trimIndent()
  }
}
