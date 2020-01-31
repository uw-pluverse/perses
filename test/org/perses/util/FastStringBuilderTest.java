package org.perses.util;

import com.google.common.truth.Truth;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

import java.io.IOException;
import java.io.StringWriter;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class FastStringBuilderTest {

  @Test
  public void testAppendChar() throws IOException {
    final FastStringBuilder builder = new FastStringBuilder(2);

    {
      builder.append('a');
      assertThat(builder.toString()).isEqualTo("a");
      assertThat(builder.length()).isEqualTo(1);
      assertThat(builder.capacity()).isEqualTo(2);
      assertThat(toStringWithWriter(builder)).isEqualTo("a");
    }
    {
      builder.append('b');
      assertThat(builder.toString()).isEqualTo("ab");
      assertThat(builder.length()).isEqualTo(2);
      assertThat(builder.capacity()).isEqualTo(2);
      assertThat(toStringWithWriter(builder)).isEqualTo("ab");
    }
    {
      builder.append('c');
      assertThat(builder.toString()).isEqualTo("abc");
      assertThat(builder.length()).isEqualTo(3);
      assertThat(builder.capacity()).isEqualTo(3);
      assertThat(toStringWithWriter(builder)).isEqualTo("abc");
    }
    {
      builder.append('d');
      assertThat(builder.toString()).isEqualTo("abcd");
      assertThat(builder.length()).isEqualTo(4);
      assertThat(builder.capacity()).isEqualTo(4);
      assertThat(toStringWithWriter(builder)).isEqualTo("abcd");
    }
    {
      builder.append('e');
      assertThat(builder.toString()).isEqualTo("abcde");
      assertThat(builder.length()).isEqualTo(5);
      assertThat(builder.capacity()).isEqualTo(6);
      assertThat(toStringWithWriter(builder)).isEqualTo("abcde");
    }
  }

  @Test
  public void testAppendString() throws IOException {
    final FastStringBuilder builder = new FastStringBuilder(2);

    {
      builder.append("a");
      assertThat(builder.toString()).isEqualTo("a");
      assertThat(builder.length()).isEqualTo(1);
      assertThat(builder.capacity()).isEqualTo(2);
      assertThat(toStringWithWriter(builder)).isEqualTo("a");
    }
    {
      builder.append("b");
      assertThat(builder.toString()).isEqualTo("ab");
      assertThat(builder.length()).isEqualTo(2);
      assertThat(builder.capacity()).isEqualTo(2);
      assertThat(toStringWithWriter(builder)).isEqualTo("ab");
    }
    {
      builder.append("c");
      assertThat(builder.toString()).isEqualTo("abc");
      assertThat(builder.length()).isEqualTo(3);
      assertThat(builder.capacity()).isEqualTo(3);
      assertThat(toStringWithWriter(builder)).isEqualTo("abc");
    }
    {
      builder.append("d");
      assertThat(builder.toString()).isEqualTo("abcd");
      assertThat(builder.length()).isEqualTo(4);
      assertThat(builder.capacity()).isEqualTo(4);
      assertThat(toStringWithWriter(builder)).isEqualTo("abcd");
    }
    {
      builder.append("e");
      assertThat(builder.toString()).isEqualTo("abcde");
      assertThat(builder.length()).isEqualTo(5);
      assertThat(builder.capacity()).isEqualTo(6);
      assertThat(toStringWithWriter(builder)).isEqualTo("abcde");
    }
  }

  private String toStringWithWriter(FastStringBuilder builder) throws IOException {
    final StringWriter writer = new StringWriter();
    builder.writeToWriter(writer);
    return writer.toString();
  }
}
