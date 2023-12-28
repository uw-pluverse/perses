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
package org.perses.reduction

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.program.LanguageKind
import org.perses.program.TokenizedProgram
import org.perses.reduction.io.CommonReductionIOManagerData
import org.perses.reduction.io.token.TokenReductionIOManager

@RunWith(JUnit4::class)
class AbstractReducerContextTest : CommonReductionIOManagerData(
  AbstractReducerContextTest::class.java,
) {

  @After
  fun teardown() {
    close()
  }

  class DummyReducerContext(
    ioManager: TokenReductionIOManager,
    executorService: TestScriptExecutorService,
  ) : AbstractReducerContext<
    TokenizedProgram,
    LanguageKind,
    TokenReductionIOManager,
    DummyReducerContext,
    >(
    ioManager,
    executorService,
  )

  val dummy = DummyReducerContext(
    ioManager,
    executorService,
  )

  @Test
  fun test() {
    val payload = "hello"
    val key = this::class.java
    val value = dummy.computePiggybackPayloadIfAbsent(key) {
      Pair(key, payload)
    }
    assertThat(value).isInstanceOf(Pair::class.java)
    val pair = value as Pair<*, *>
    assertThat(pair.first).isSameInstanceAs(this::class.java)
    assertThat(pair.second).isSameInstanceAs(payload)
  }
}
