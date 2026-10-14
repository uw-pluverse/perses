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
package org.perses.spartree

import com.google.common.hash.HashCode
import org.perses.util.CollectionUtil

/**
 * Remembers each action set by its fingerprint, not the set itself. A set holds an action, and a map
 * entry, per node, and the cache lives until the tree changes, so storing sets costs the sum of their
 * sizes. A ddmin-style minimizer that finds nothing to delete tries complements of ever finer
 * partitions, each nearly the whole list: on a 12,399-element list that is quadratic and exhausted a
 * 48 GB heap. A 128-bit fingerprint makes every entry the same small size, and a collision, which
 * would only skip one candidate, is not a practical concern. A set's class is not in the
 * fingerprint: sets with the same actions make the same tree, whatever produced them.
 */
class NodeActionSetCache : AbstractNodeActionSetCache() {
  // For thread-safety.
  private val cache = CollectionUtil.createConcurrentSet<HashCode>()

  override fun isCachedOrCacheIt(actionSet: AbstractActionSet<*>): NodeActionSetCacheResult =
    if (cache.add(actionSet.computeFingerprint())) {
      NodeActionSetCacheResult.MISS_BUT_CACHED_NOW
    } else {
      NodeActionSetCacheResult.HIT
    }

  override fun clear() {
    cache.clear()
  }

  override val size: Int
    get() = cache.size
}
