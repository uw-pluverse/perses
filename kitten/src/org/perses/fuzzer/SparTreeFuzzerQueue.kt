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
package org.perses.fuzzer

import java.util.Random
import java.util.concurrent.atomic.AtomicInteger

class SparTreeFuzzerQueue(sparTreeFuzzers: Iterable<SparTreeFuzzer>) {

  val content = ArrayList(sparTreeFuzzers.toList())

  @Synchronized fun getSize(): Int {
    return content.size
  }

  private val index = AtomicInteger(0)

  @Synchronized fun next(): SparTreeFuzzer {
    return content[index.getAndIncrement() % getSize()]
  }

  @Synchronized fun add(sparTreeFuzzer: SparTreeFuzzer) {
    content.add(sparTreeFuzzer)
  }

  @Synchronized fun remove(sparTreeFuzzer: SparTreeFuzzer) {
    content.remove(sparTreeFuzzer)
  }

  @Synchronized fun getRandomFuzzer(random: Random): SparTreeFuzzer {
    return content[random.nextInt(getSize())]
  }
}
