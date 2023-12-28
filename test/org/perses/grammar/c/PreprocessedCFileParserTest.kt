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
package org.perses.grammar.c

import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.nio.file.Paths

@RunWith(JUnit4::class)
class PreprocessedCFileParserTest {

  private val facade = PnfCParserFacade()

  @Test
  fun testParseClang_nonnull_attribute() {
    parseFile("clang_nonnull_attribute.c")
  }

  @Test
  fun testParseClang_nullable_attribute() {
    parseFile("clang_nullable_attribute.c")
  }

  // FIXME: enable this when the C parse can parse clang-preprocessed code.
  @Ignore
  @Test
  fun testParseClang_preprocessed() {
    parseFile("clang_preprocessed.c")
  }

  @Test
  fun testParseGcc_preprocessed() {
    parseFile("gcc_preprocessed.c")
  }

  @Test
  fun testParse_gcc_inline_static_extension_example() {
    parseFile("gcc_inline_static_extension_example.c")
  }

  @Test
  fun testParse_gcc_extension_keyword() {
    parseFile("gcc_extension_keyword.c")
  }

  @Test
  fun testParse_gcc_alignof() {
    parseFile("gcc_alignof.c")
  }

  @Test
  fun testParseGcc_restrict_keyword() {
    parseFile("gcc_restrict_keyword.c")
  }

  @Ignore
  @Test
  fun testParseClang_function_attribute() {
    parseFile("clang_attribute_availability_introduced_version.c")
  }

  private fun parseFile(fileName: String) {
    facade.parseFile(getFile(fileName))
  }

  private fun getFile(fileName: String) =
    Paths.get("test_data/c_programs/preprocessed_files/$fileName")
}
