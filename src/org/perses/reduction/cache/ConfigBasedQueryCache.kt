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
package org.perses.reduction.cache

import org.perses.program.TokenizedProgram
import org.perses.reduction.PropertyTestResult
import org.perses.reduction.io.AbstractOutputManager
import org.perses.util.Util.lazyAssert
import java.util.HashMap

class ConfigBasedQueryCache : AbstractQueryCache() {
  private val root = CacheNode()
  private var size = 0

  override fun getCachedResult(
    program: TokenizedProgram,
    outputManager: AbstractOutputManager,
  ): AbstractCacheRetrievalResult {
    val tokens = program.tokens
    var node: CacheNode? = root
    for (token in tokens) {
      node = node!!.getOrNull(token.lexemeText)
      if (node == null) {
        return AbstractCacheRetrievalResult.create(
          owner = this,
          program = program,
          encoding = null,
          isCacheHit = false,
        )
      }
    }
    lazyAssert { node != null }
    return AbstractCacheRetrievalResult.create(
      owner = this,
      program = program,
      encoding = null,
      isCacheHit = node!!.result != null,
    )
  }

  override fun constructObjectsForMemoryMeasurement(): Any = this

  @Synchronized
  override fun cacheProgramAndResult(
    program: AbstractCacheRetrievalResult.CacheMiss,
    result: PropertyTestResult,
  ) {
    check(program.owner === this)
    val tokens = program.program.tokens
    var node = root
    for (token in tokens) {
      val lexeme = token.lexemeText
      node = node.getOrCreateChild(lexeme)
    }
    if (node.isResultEmpty) {
      ++size
      node.result = result
    }
    lazyAssert { !node.isResultEmpty }
  }

  override fun cacheSize(): Int = size

  override fun evictEntriesLargerThan(best: TokenizedProgram) {
    // TODO: need to support eviction.
  }

  override fun clearCache() {
    root.clear()
  }

  override fun triggerHeartBeat() {}

  private class CacheNode {
    var result: PropertyTestResult? = null
      set(value) {
        check(this.result == null)
        field = value
        lazyAssert { this.result != null }
      }

    private var children = HashMap<String, CacheNode>()

    fun clear() {
      children = HashMap()
      result = null
    }

    fun getOrCreateChild(lexeme: String): CacheNode {
      var child = children[lexeme]
      if (child == null) {
        child = CacheNode()
        children[lexeme] = child
      }
      lazyAssert { children[lexeme] == child }
      return child
    }

    fun getOrNull(lexeme: String): CacheNode? = children[lexeme]

    val isResultEmpty: Boolean
      get() = result == null
  }
}
