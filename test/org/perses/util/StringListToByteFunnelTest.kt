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

import com.google.common.hash.PrimitiveSink
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.StringListToByteFunnel.BYTE_LIST_END_SEPARATOR
import org.perses.util.StringListToByteFunnel.BYTE_LIST_START_SEPARATOR
import org.perses.util.StringListToByteFunnel.ELEMENT_SEPARATOR
import java.nio.ByteBuffer
import java.nio.charset.Charset

@RunWith(JUnit4::class)
class StringListToByteFunnelTest {

  val funnel = StringListToByteFunnel
  val sinkData = mutableListOf<String>()
  val sink = object : PrimitiveSink {
    override fun putByte(p0: Byte): PrimitiveSink {
      sinkData.add(p0.toString())
      return this
    }

    override fun putBytes(p0: ByteArray): PrimitiveSink {
      TODO("Not yet implemented")
    }

    override fun putBytes(p0: ByteArray, p1: Int, p2: Int): PrimitiveSink {
      TODO("Not yet implemented")
    }

    override fun putBytes(p0: ByteBuffer): PrimitiveSink {
      TODO("Not yet implemented")
    }

    override fun putShort(p0: Short): PrimitiveSink {
      TODO("Not yet implemented")
    }

    override fun putInt(p0: Int): PrimitiveSink {
      TODO("Not yet implemented")
    }

    override fun putLong(p0: Long): PrimitiveSink {
      TODO("Not yet implemented")
    }

    override fun putFloat(p0: Float): PrimitiveSink {
      TODO("Not yet implemented")
    }

    override fun putDouble(p0: Double): PrimitiveSink {
      TODO("Not yet implemented")
    }

    override fun putBoolean(p0: Boolean): PrimitiveSink {
      TODO("Not yet implemented")
    }

    override fun putChar(p0: Char): PrimitiveSink {
      TODO("Not yet implemented")
    }

    override fun putUnencodedChars(p0: CharSequence): PrimitiveSink {
      TODO("Not yet implemented")
    }

    override fun putString(p0: CharSequence, p1: Charset): PrimitiveSink {
      sinkData.add(p0.toString())
      return this
    }
  }

  @Test
  fun testEmptyList() {
    funnel.funnel(listOf(), sink)
    assertThat(sinkData).containsExactly(START, START, END, END).inOrder()
  }

  @Test
  fun testListOfOneEmptyString() {
    funnel.funnel(listOf(""), sink)
    assertThat(sinkData).containsExactly(START, START, "", SEPARATOR, END, END).inOrder()
  }

  @Test
  fun testListOfTwoEmptyStrings() {
    funnel.funnel(listOf("", ""), sink)
    assertThat(
      sinkData,
    ).containsExactly(START, START, "", SEPARATOR, "", SEPARATOR, END, END).inOrder()
  }

  @Test
  fun testListOfOneNonemptyString() {
    funnel.funnel(listOf("a"), sink)
    assertThat(sinkData).containsExactly(START, START, "a", SEPARATOR, END, END).inOrder()
  }

  @Test
  fun testListOfTwoNonemptyStrings() {
    funnel.funnel(listOf("a", "b"), sink)
    assertThat(
      sinkData,
    ).containsExactly(START, START, "a", SEPARATOR, "b", SEPARATOR, END, END).inOrder()
  }

  companion object {
    val START = BYTE_LIST_START_SEPARATOR.toString()
    val END = BYTE_LIST_END_SEPARATOR.toString()
    val SEPARATOR = ELEMENT_SEPARATOR.toString()
  }
}
