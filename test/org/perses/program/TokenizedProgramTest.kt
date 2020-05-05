package org.perses.program

import com.google.common.base.Joiner
import com.google.common.io.Files
import com.google.common.truth.Truth
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.LanguageKind
import org.perses.TestUtility
import java.io.File
import java.nio.charset.StandardCharsets
import java.util.stream.Collectors

@RunWith(JUnit4::class)
class TokenizedProgramTest {
  @Test
  fun testCodeFormatRemains() {
    testCodeFormatRemains("test_data/java_helloworld/t.java")
    testCodeFormatRemains("test_data/parentheses/t.c")
  }

  @Test
  fun testPrintCodeInLines() {
    testTokenEquivalence("test_data/java_helloworld/t.java")
    testTokenEquivalence("test_data/parentheses/t.c")
  }

  @Test
  fun testSourceCodeIsCached() {
    val filepath = "test_data/java_helloworld/t.java"
    val p = TestUtility.createTokenizedProgramFromFile(filepath)
    Truth.assertThat(p.toSourceCodeInOrigFormatWithBlankLines())
      .isSameInstanceAs(p.toSourceCodeInOrigFormatWithBlankLines())
  }

  @Test
  fun testCompactSourceCode() {
    val sourceCode = """int a = 0;
      |
      |int b = 0;
      |
      |int c = 0;
    """.trimMargin()
    val program = TestUtility.createTokenizedProgramFromString(sourceCode, LanguageKind.C)
    Truth.assertThat(program.toSourceCodeInOrigFormatWithBlankLines().trim())
      .isEqualTo(sourceCode.trim())
    Truth.assertThat(program.toCompactSourceCode().trim()).isEqualTo("""int a = 0;
      |int b = 0;
      |int c = 0;
      """.trimMargin())
  }

  private fun testTokenEquivalence(filepath: String) {
    val program = Joiner.on("")
      .join(
        TestUtility.createTokenizedProgramFromFile(filepath).tokens.stream()
          .map { obj: PersesToken -> obj.text }
          .map { s: String -> s.replace("\\s|\n".toRegex(), "") }
          .collect(Collectors.toList<String>()))
    val text = Files.asCharSource(File(filepath), StandardCharsets.UTF_8)
      .read()
      .replace("\\s|\n".toRegex(), "")
    Truth.assertThat(program).isEqualTo(text)
  }

  private fun testCodeFormatRemains(filepath: String) {
    val program = TestUtility.createTokenizedProgramFromFile(filepath)
    Truth.assertThat(program.toSourceCodeInOrigFormatWithBlankLines().trim())
      .isEqualTo(Files.asCharSource(File(filepath), StandardCharsets.UTF_8).read().trim())
  }
}