package org.perses.program;

import org.checkerframework.checker.nullness.qual.MonotonicNonNull;
import org.perses.util.FastStringBuilder;

import java.io.IOException;
import java.io.Writer;

abstract class AbstractLazySourceCode {
  @MonotonicNonNull private String sourceCode;
  @MonotonicNonNull private FastStringBuilder stringBuilder;

  public final synchronized String getSourceCode() {
    if (sourceCode == null) {
      final FastStringBuilder builder = getStringBuilder();
      sourceCode = builder.toString();
    }
    assert sourceCode != null;
    return sourceCode;
  }

  public final void writeTo(Writer writer) throws IOException {
    getStringBuilder().writeToWriter(writer);
  }

  private final FastStringBuilder getStringBuilder() {
    if (stringBuilder == null) {
      stringBuilder = computeStringBuilder();
    }
    assert stringBuilder != null;
    return stringBuilder;
  }

  protected abstract FastStringBuilder computeStringBuilder();
}
