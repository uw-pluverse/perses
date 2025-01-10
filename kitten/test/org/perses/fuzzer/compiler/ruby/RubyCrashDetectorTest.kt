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
package org.perses.fuzzer.compiler.ruby

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compiler.CrashDetectorHelper
import org.perses.fuzzer.compilers.ruby.RubyCrashDetector

@RunWith(JUnit4::class)
class RubyCrashDetectorTest {

  val detector = RubyCrashDetector()

  private fun computeSignature(path: String): List<String> {
    return CrashDetectorHelper.computeSignature(
      "kitten/test/org/perses/fuzzer/compiler/ruby/$path",
      detector,
    )
  }

  @Test
  fun test_bug() {
    val signature = computeSignature("ruby_bug.txt")
    assertThat(signature).containsExactly(
      "Ruby/Gems/2.6.0/gems/ethon-0.15.0/lib/ethon/curls/classes.rb:36: " +
        "[BUG] Illegal instruction at 0x0000000104978000",
    )
  }
}
