package org.perses.grammar.c

import org.junit.Ignore
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.io.File

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

  @Ignore
  @Test
  fun testParseClang_preprocessed() {
    parseFile("clang_preprocessed.c")
  }

  @Ignore
  @Test
  fun testParseGcc_preprocessed() {
    parseFile("gcc_preprocessed.c")
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
    File("test_data/c_programs/preprocessed_files/$fileName")
}
