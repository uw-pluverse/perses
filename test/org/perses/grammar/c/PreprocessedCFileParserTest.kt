package org.perses.grammar.c

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

  private fun parseFile(fileName: String) {
    facade.parseFile(getFile(fileName))
  }

  private fun getFile(fileName: String) =
    File("test_data/c_programs/preprocessed_files/$fileName")

}
