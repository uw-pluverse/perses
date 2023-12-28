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
package org.perses.reduction.cache

import it.unimi.dsi.fastutil.ints.IntArrayList
import me.lemire.integercompression.IntWrapper
import me.lemire.integercompression.differential.IntegratedBinaryPacking
import me.lemire.integercompression.differential.IntegratedVariableByte
import me.lemire.integercompression.differential.SkippableIntegratedComposition
import me.lemire.integercompression.differential.SkippableIntegratedIntegerCODEC

/**
 * This class is kept in Java but not converted to Kotlin, because this class deals with int arrays.
 * Better to use Java.
 */
class CompressorForIntArrayList {

  private val codec: SkippableIntegratedIntegerCODEC = SkippableIntegratedComposition(
    IntegratedBinaryPacking(),
    IntegratedVariableByte(),
  )

  fun compress(intArrayList: IntArrayList): IntArray {
    val input = intArrayList.elements()
    val inputLength = intArrayList.size
    val compressed = IntArray(inputLength + 1)
    compressed[0] = inputLength
    val outpos = IntWrapper(1)
    val initvalue = IntWrapper(0)
    codec.headlessCompress(input, IntWrapper(0), inputLength, compressed, outpos, initvalue)
    val newLength = outpos.toInt()
    return compressed.copyOf(newLength)
  }

  fun uncompress(compressed: IntArray): IntArray {
    val decompressed = IntArray(compressed[0])
    val inpos = IntWrapper(1)
    codec.headlessUncompress(
      compressed,
      inpos,
      compressed.size - inpos.toInt(),
      decompressed,
      IntWrapper(0),
      decompressed.size,
      IntWrapper(0),
    )
    return decompressed
  }
}
