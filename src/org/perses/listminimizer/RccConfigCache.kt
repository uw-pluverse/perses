/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
package org.perses.listminimizer

import com.google.common.collect.ImmutableList
import it.unimi.dsi.fastutil.ints.IntArrayList
import org.perses.reduction.cache.CompressorForIntArrayList

class RccConfigEncoding private constructor(
  private val encoding: IntArray,
) {
  override fun equals(other: Any?): Boolean {
    if (this === other) return true
    if (javaClass != other?.javaClass) return false
    other as RccConfigEncoding
    return encoding.contentEquals(other.encoding)
  }

  private val cachedHashCode = encoding.contentHashCode()

  override fun hashCode(): Int = cachedHashCode

  val intervalsFromEncoding: IntArray
    get() = COMPRESSOR.uncompress(encoding)

  companion object {
    fun createCompressedEncoding(intervals: IntArrayList): RccConfigEncoding {
      check(intervals.size % 2 == 0)
      return RccConfigEncoding(COMPRESSOR.compress(intervals))
    }

    private val COMPRESSOR = CompressorForIntArrayList()
  }
}

/**
 * The Refreshable Compact Caching (RCC) scheme from the paper below. A list-minimizer configuration
 * is a sorted integer array, so each is stored as a compact interval encoding
 * ([RccConfigEncoding] / [CompressorForIntArrayList], Section 4.3.2) and the cache is refreshed
 * against each new best ([refreshAndUpdateBest], Section 4.3.4): survivors are re-encoded relative to
 * the new base and any configuration that is no longer a subsequence of it is dropped.
 *
 * The whole-program query cache ([org.perses.reduction.cache.ContentShaHashBasedFormatQueryCache])
 * keys on content hashes, where interval encoding does not apply; it instead uses the size-based
 * refresh variant (Section 6.2) of the same paper.
 *
 * Yongqiang Tian, Xueyan Zhang, Yiwen Dong, Zhenyang Xu, Mengxiao Zhang, Yu Jiang, Shing-Chi Cheung, Chengnian Sun:
 * On the Caching Schemes to Speed Up Program Reduction. ACM Trans. Softw. Eng. Methodol. 33(1): 17:1-17:30 (2024)
 */
class RccConfigCache<T : Any>(
  private var baseProgram: ImmutableList<ElementWrapper<T>>,
) : AbstractConfigCache<T>() {
  private val cache = HashSet<RccConfigEncoding>()

  val size: Int
    get() = cache.size

  override fun add(config: ImmutableList<ElementWrapper<T>>) {
    val encoding = encode(config)
    if (encoding != null) {
      cache.add(encoding)
    }
  }

  override fun contains(config: ImmutableList<ElementWrapper<T>>): Boolean {
    val encoding = encode(config)
    return encoding != null && cache.contains(encoding)
  }

  override fun refreshAndUpdateBest(newBest: ImmutableList<ElementWrapper<T>>) {
    val oldBase = baseProgram
    baseProgram = newBest

    val newKeys = HashSet<RccConfigEncoding>()
    val iter = cache.iterator()
    while (iter.hasNext()) {
      val oldEncoding = iter.next()
      iter.remove()

      val decoded = decode(oldBase, oldEncoding)
      val newEncoding = encode(decoded)
      if (newEncoding != null) {
        newKeys.add(newEncoding)
      }
    }
    cache.addAll(newKeys)
  }

  internal fun encode(config: ImmutableList<ElementWrapper<T>>): RccConfigEncoding? {
    val intervals = IntArrayList(8)
    var origIndex = 0
    var configIndex = 0
    while (configIndex < config.size) {
      val currentElement = config[configIndex]
      // Search for currentElement in baseProgram starting from origIndex
      while (origIndex < baseProgram.size && baseProgram[origIndex] !== currentElement) {
        origIndex++
      }
      if (origIndex == baseProgram.size) return null // Element not found

      intervals.add(origIndex)

      do {
        configIndex++
        origIndex++
      } while (configIndex < config.size &&
        origIndex < baseProgram.size &&
        config[configIndex] === baseProgram[origIndex]
      )

      intervals.add(origIndex)
    }
    return RccConfigEncoding.createCompressedEncoding(intervals)
  }

  internal fun decode(
    base: ImmutableList<ElementWrapper<T>>,
    encoding: RccConfigEncoding,
  ): ImmutableList<ElementWrapper<T>> {
    val intervals = encoding.intervalsFromEncoding
    val builder = ImmutableList.builder<ElementWrapper<T>>()
    for (i in 0 until intervals.size step 2) {
      for (j in intervals[i] until intervals[i + 1]) {
        builder.add(base[j])
      }
    }
    return builder.build()
  }
}
