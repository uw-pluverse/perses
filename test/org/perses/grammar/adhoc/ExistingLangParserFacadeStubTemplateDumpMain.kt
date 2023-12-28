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

import org.perses.util.Util.ensureDirExists
import java.nio.file.Paths

object ExistingLangParserFacadeStubTemplateDumpMain {
  @JvmStatic
  fun main(args: Array<String>) {
    require(args.size == 1 || args.size == 2) { args.toList() }
    val output = Paths.get(args[0]).toAbsolutePath()
    val lexerFile = if (args.size == 2) { Paths.get(args[1]) } else { null }
    val parent = output.parent!!
    ensureDirExists(parent)
    ExistingLangParserFacadeStubTemplate(
      packageName = "org.fake.package",
      parserClassSimpleName = "FakeParser",
      lexerClassSimpleName = "FakeLexer",
      startRuleName = "start_rule",
      grammarName = "Fake",
      parserFile = Paths.get("Parser.g4"),
      lexerFile = lexerFile,
      existingLanguageFullClassName = "org.fake.package.LanguageFake",
      parserFacadeClassSimpleName = "FakeParserFacade",
      tokenNamesOfIdentifiers = listOf("Identifier"),
    ).writeTo(output)
    System.err.println("Written the template to $output")
  }
}
