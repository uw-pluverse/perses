/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
