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
package org.perses.reduction

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.TestUtility
import org.perses.grammar.c.LanguageC
import org.perses.reduction.AbstractGlobalExecutionCache.GlobalExecutionCache
import org.perses.reduction.io.CommonReductionIOManagerData
import org.perses.util.shell.ExitCode
import java.nio.file.Files

@RunWith(JUnit4::class)
class ExternalTestScriptExecutionCacheTest :
  CommonReductionIOManagerData(ExternalTestScriptExecutionCacheTest::class.java) {
  val program = TestUtility.createTokenizedProgramFromString("int a;", LanguageC)

  @After
  fun teardown() {
    close()
  }

  @Test
  fun test() {
    val cache = GlobalExecutionCache.createEmpty(shaAlgorithm)
    val outputManager = outputManagerFactory.createManagerFor(program)
    assertThat(cache.getCachedResultOrNull(outputManager)).isNull()

    val propertyTestResult = PropertyTestResult(exitCode = ExitCode.ZERO, elapsedMillis = 1)
    cache.cacheTestScriptResult(outputManager, propertyTestResult)
    cache.getCachedResultOrNull(outputManagerFactory.createManagerFor(program)).let {
      assertThat(it!!.exitCode.intValue).isSameInstanceAs(propertyTestResult.exitCode.intValue)
      assertThat(it.elapsedMillis).isEqualTo(propertyTestResult.elapsedMillis)
    }

    val resultFile = workingDir.resolve("result.csv")
    assertThat(Files.exists(resultFile)).isFalse()
    cache.saveCacheEntriesToCsvFile(resultFile)
    assertThat(Files.exists(resultFile)).isTrue()

    val anotherCache = GlobalExecutionCache.createFromHistoryCvsFile(shaAlgorithm, resultFile)
    anotherCache.getCachedResultOrNull(outputManager)!!.let {
      assertThat(it.exitCode.intValue).isEqualTo(propertyTestResult.exitCode.intValue)
      assertThat(it.elapsedMillis).isEqualTo(propertyTestResult.elapsedMillis)
    }
  }
}
