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
package org.perses.fuzzer

import org.perses.TestUtility
import org.perses.grammar.AbstractParserFacade
import java.nio.file.Files
import java.nio.file.Paths

/**
 * The shared parser facade of `Tiny.g4`; see that grammar for why the golden-pinning
 * kitten tests use it instead of a real language.
 *
 * Generating the facade normalizes the grammar and compiles it into a jar, so it is
 * built lazily once per test JVM. The working directory must outlive every test that
 * may still load classes from the jar, so its cleanup is left to the test tmpdir.
 */
object TinyGrammarFacade {
  val facade: AbstractParserFacade by lazy {
    TestUtility.generateAdhocFacade(
      Paths.get("kitten/test/fuzzer_test_data/grammar_for_testing/Tiny.g4"),
      startRule = "program",
      tokenNamesOfIdentifiers = listOf("ID"),
      workingDir = Files.createTempDirectory(TinyGrammarFacade::class.java.simpleName),
      enablePnfNormalization = true,
    )
  }
}
