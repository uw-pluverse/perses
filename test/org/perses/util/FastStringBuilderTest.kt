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
package org.perses.util

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.io.StringWriter

@RunWith(JUnit4::class)
class FastStringBuilderTest {

  @Test
  fun testPosition() {
    val builder = FastStringBuilder(capacity = 1)
    assertThat(builder.currentLineNo).isEqualTo(1)
    assertThat(builder.charPositionInLine).isEqualTo(0)

    builder.append('a')
    assertThat(builder.currentLineNo).isEqualTo(1)
    assertThat(builder.charPositionInLine).isEqualTo(1)

    builder.append("a")
    assertThat(builder.currentLineNo).isEqualTo(1)
    assertThat(builder.charPositionInLine).isEqualTo(2)

    builder.append("\n")
    assertThat(builder.currentLineNo).isEqualTo(2)
    assertThat(builder.charPositionInLine).isEqualTo(0)

    builder.append("a\na")
    assertThat(builder.currentLineNo).isEqualTo(3)
    assertThat(builder.charPositionInLine).isEqualTo(1)

    builder.append('\n')
    assertThat(builder.currentLineNo).isEqualTo(4)
    assertThat(builder.charPositionInLine).isEqualTo(0)
  }

  @Test
  fun testAppendChar() {
    val builder = FastStringBuilder(2)
    run {
      builder.append('a')
      assertThat(builder.toString()).isEqualTo("a")
      assertThat(builder.length()).isEqualTo(1)
      assertThat(builder.capacity()).isEqualTo(2)
      assertThat(toStringWithWriter(builder)).isEqualTo("a")
    }
    run {
      builder.append('b')
      assertThat(builder.toString()).isEqualTo("ab")
      assertThat(builder.length()).isEqualTo(2)
      assertThat(builder.capacity()).isEqualTo(2)
      assertThat(toStringWithWriter(builder)).isEqualTo("ab")
    }
    run {
      builder.append('c')
      assertThat(builder.toString()).isEqualTo("abc")
      assertThat(builder.length()).isEqualTo(3)
      assertThat(builder.capacity()).isEqualTo(3)
      assertThat(toStringWithWriter(builder)).isEqualTo("abc")
    }
    run {
      builder.append('d')
      assertThat(builder.toString()).isEqualTo("abcd")
      assertThat(builder.length()).isEqualTo(4)
      assertThat(builder.capacity()).isEqualTo(4)
      assertThat(toStringWithWriter(builder)).isEqualTo("abcd")
    }
    run {
      builder.append('e')
      assertThat(builder.toString()).isEqualTo("abcde")
      assertThat(builder.length()).isEqualTo(5)
      assertThat(builder.capacity()).isEqualTo(6)
      assertThat(toStringWithWriter(builder)).isEqualTo("abcde")
    }
  }

  @Test
  fun testAppendString() {
    val builder = FastStringBuilder(2)
    run {
      builder.append("a")
      assertThat(builder.toString()).isEqualTo("a")
      assertThat(builder.length()).isEqualTo(1)
      assertThat(builder.capacity()).isEqualTo(2)
      assertThat(toStringWithWriter(builder)).isEqualTo("a")
    }
    run {
      builder.append("b")
      assertThat(builder.toString()).isEqualTo("ab")
      assertThat(builder.length()).isEqualTo(2)
      assertThat(builder.capacity()).isEqualTo(2)
      assertThat(toStringWithWriter(builder)).isEqualTo("ab")
    }
    run {
      builder.append("c")
      assertThat(builder.toString()).isEqualTo("abc")
      assertThat(builder.length()).isEqualTo(3)
      assertThat(builder.capacity()).isEqualTo(3)
      assertThat(toStringWithWriter(builder)).isEqualTo("abc")
    }
    run {
      builder.append("d")
      assertThat(builder.toString()).isEqualTo("abcd")
      assertThat(builder.length()).isEqualTo(4)
      assertThat(builder.capacity()).isEqualTo(4)
      assertThat(toStringWithWriter(builder)).isEqualTo("abcd")
    }
    run {
      builder.append("e")
      assertThat(builder.toString()).isEqualTo("abcde")
      assertThat(builder.length()).isEqualTo(5)
      assertThat(builder.capacity()).isEqualTo(6)
      assertThat(toStringWithWriter(builder)).isEqualTo("abcde")
    }
  }

  private fun toStringWithWriter(builder: FastStringBuilder): String {
    val writer = StringWriter()
    builder.writeToWriter(writer)
    return writer.toString()
  }
}
