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
package org.perses.util;

import com.google.common.annotations.VisibleForTesting;
import com.google.common.base.Preconditions;
import it.unimi.dsi.fastutil.chars.CharArrays;

import java.io.IOException;
import java.io.Writer;

public final class FastStringBuilder {

  private static final char[] EMPTY = new char[0];

  private int size;
  private char[] data;

  public FastStringBuilder(int capacity) {
    Preconditions.checkArgument(capacity >= 0);
    if (capacity == 0) {
      data = EMPTY;
    } else {
      data = new char[capacity];
    }
  }

  public FastStringBuilder append(String s) {
    final int stringLength = s.length();
    final int newSize = size + stringLength;
    ensureCapacity(newSize);
    s.getChars(0, stringLength, data, size);
    size = newSize;
    return this;
  }

  public int length() {
    return size;
  }

  public boolean isEmpty() {
    return length() == 0;
  }

  public boolean isNotEmpty() {
    return !isEmpty();
  }

  public FastStringBuilder append(char c) {
    final int newSize = size + 1;
    ensureCapacity(newSize);
    data[size] = c;
    size = newSize;
    return this;
  }

  @Override
  public String toString() {
    return new String(data, 0, size);
  }

  public void writeToWriter(Writer writer) throws IOException {
    writer.write(data, 0, size);
  }

  private void ensureCapacity(int newLength) {
    if (newLength > data.length) {
      final int newCapacity = Math.max(data.length + data.length / 2, newLength);
      data = CharArrays.forceCapacity(data, newCapacity, data.length);
    }
  }

  public char lastChar() {
    return data[length() - 1];
  }

  @VisibleForTesting
  int capacity() {
    return data.length;
  }
}
