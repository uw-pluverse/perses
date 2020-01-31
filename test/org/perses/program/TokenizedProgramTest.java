package org.perses.program;

import com.google.common.base.Joiner;
import com.google.common.io.Files;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.stream.Collectors;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class TokenizedProgramTest {

  @Test
  public void testCodeFormatRemains() throws IOException {
    testCodeFormatRemains("test_data/java_helloworld/t.java");
    testCodeFormatRemains("test_data/parentheses/t.c");
  }

  @Test
  public void testPrintCodeInLines() throws IOException {
    testTokenEquivalence("test_data/java_helloworld/t.java");
    testTokenEquivalence("test_data/parentheses/t.c");
  }

  @Test
  public void testSourceCodeIsCached() throws IOException {
    final String filepath = "test_data/java_helloworld/t.java";
    TokenizedProgram p = TestUtility.createTokenizedProgramFrom(filepath);
    assertThat(p.getSourceCodeInOrigFormat()).isSameInstanceAs(p.getSourceCodeInOrigFormat());
  }

  private void testTokenEquivalence(String filepath) throws IOException {
    final String program =
        Joiner.on("")
            .join(
                TestUtility.createTokenizedProgramFrom(filepath).getTokens().stream()
                    .map(PersesToken::getText)
                    .map(s -> s.replaceAll("\\s|\n", ""))
                    .collect(Collectors.toList()));
    final String text =
        Files.asCharSource(new File(filepath), StandardCharsets.UTF_8)
            .read()
            .replaceAll("\\s|\n", "");
    assertThat(program).isEqualTo(text);
  }

  private void testCodeFormatRemains(String filepath) throws IOException {
    TokenizedProgram program = TestUtility.createTokenizedProgramFrom(filepath);
    assertThat(program.getSourceCodeInOrigFormat().trim())
        .isEqualTo(Files.asCharSource(new File(filepath), StandardCharsets.UTF_8).read().trim());
  }
}
