package org.perses.antlr.util;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class UtilTest {

  @Test
  public void test_extractGrammarNameFromGrammarFileName() {
    assertThat(Util.extractGrammarNameFromGrammarFileName("x.g4")).isEqualTo("x");
    assertThat(Util.extractGrammarNameFromGrammarFileName("a/b/x.g4")).isEqualTo("x");
  }
}
