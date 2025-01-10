/*
 * Copyright (C) 2018-2025 University of Waterloo.
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

import com.google.common.hash.Funnel
import com.google.common.hash.PrimitiveSink
import java.nio.charset.StandardCharsets

class ListToByteFunnel<T : Any>(
  private val elementFunnel: (T, PrimitiveSink) -> Unit,
) : Funnel<List<T>> {

  override fun funnel(data: List<T>, primitiveSink: PrimitiveSink) {
    writeListStart(primitiveSink)
    data.forEach {
      elementFunnel(it, primitiveSink)
      writeElementSeparator(primitiveSink)
    }
    writeListEnd(primitiveSink)
  }

  private fun writeListStart(sink: PrimitiveSink) {
    sink.putByte(BYTE_LIST_START_SEPARATOR).putByte(BYTE_LIST_START_SEPARATOR)
  }

  private fun writeListEnd(sink: PrimitiveSink) {
    sink.putByte(BYTE_LIST_END_SEPARATOR).putByte(BYTE_LIST_END_SEPARATOR)
  }

  private fun writeElementSeparator(sink: PrimitiveSink) {
    sink.putByte(ELEMENT_SEPARATOR)
  }

  companion object {

    val StringListToByteFunnel = ListToByteFunnel<String> { element, sink ->
      sink.putString(element, StandardCharsets.UTF_8)
    }

    const val BYTE_LIST_START_SEPARATOR: Byte = Byte.MIN_VALUE

    const val BYTE_LIST_END_SEPARATOR: Byte = (Byte.MIN_VALUE + 1).toByte()

    const val ELEMENT_SEPARATOR: Byte = (Byte.MIN_VALUE + 2).toByte()
  }
}
