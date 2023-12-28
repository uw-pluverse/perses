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
package org.perses

import com.google.common.collect.ImmutableList
import com.google.common.truth.Truth.assertWithMessage
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.grammar.SingleParserFacadeFactory.Companion.builderWithBuiltinLanguages
import org.perses.program.LanguageKind
import org.perses.util.toImmutableList
import java.nio.file.Files
import java.nio.file.Paths
import kotlin.io.path.bufferedReader

@RunWith(JUnit4::class)
class ReadmeTest {
  private val readmeFile = Paths.get("README.md")

  @Test
  fun testSupportedLanguage() {
    val persesSupported = getActuallySupportedLanguages()
    val readmeListed = parseReadmeSupportedLanguages()
    assertWithMessage(
      """You need to update //README.md to reflect the latest language support.
      ${persesSupported.joinToString { "\n" }}
      """.trimIndent(),
    ).that(readmeListed).containsExactlyElementsIn(persesSupported)
  }

  private fun getActuallySupportedLanguages(): ImmutableList<String> {
    val builder = builderWithBuiltinLanguages()
    val parserFacadeFactory = builder.build()
    return parserFacadeFactory.languageSequence()
      .map { languageToString(it) }
      .toImmutableList()
  }

  private fun languageToString(language: LanguageKind): String {
    return "${language.name.lowercase()}: ${language.extensions}"
  }

  private fun parseReadmeSupportedLanguages(): ImmutableList<String> {
    check(Files.exists(readmeFile))
    val lineRegex = """^\+ .+: \[.+]$""".toRegex()
    return readmeFile.bufferedReader().use { reader ->
      reader
        .lineSequence()
        .filter { lineRegex.containsMatchIn(it) }
        .map { it.substring(2).lowercase() }
        .toImmutableList()
    }
  }
}
