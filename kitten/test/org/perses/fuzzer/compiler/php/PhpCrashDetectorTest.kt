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
package org.perses.fuzzer.compiler.php

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.fuzzer.compiler.CrashDetectorHelper
import org.perses.fuzzer.compilers.php.PhpCrashDetector

@RunWith(JUnit4::class)
class PhpCrashDetectorTest {

  val detector = PhpCrashDetector()

  private fun computeSignature(path: String): List<String> {
    return CrashDetectorHelper.computeSignature(
      "kitten/test/org/perses/fuzzer/compiler/php/$path",
      detector,
    )
  }

  @Test
  fun test_bug() {
    val signature = computeSignature("php_crash.txt")
    assertThat(signature).containsExactly(
      "PHP Fatal error: Allowed memory size of 536870912 bytes exhausted " +
        "(tried to allocate 268435464 bytes) in " +
        "/usr/local/pkg/pfblockerng/pfblockerng.inc on line 2511",
    )
  }
}
