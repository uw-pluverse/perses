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
import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.listminimizer.xfs.DeltaDebugger
import org.perses.listminimizer.xfs.UnweightedBfsListMinimizer
import org.perses.reduction.CandidateOutcome
import org.perses.reduction.TestScriptVerdict

@RunWith(JUnit4::class)
class DeltaDebuggerFactoryTest {
  val args =
    ListMinimizerArguments(
      needToTestEmpty = true,
      input = ImmutableList.of("a"),
      isElementDeletedElsewhere = { false },
      propertyTester = {
        ImmediatePropertyTestHandle(
          CandidateOutcome.Interesting(
            "payload",
            TestScriptVerdict.INTERESTING,
          ),
        )
      },
      onBestUpdateHandler = { _, _ -> },
      descriptionPrefix = "",
    )

  @Test
  fun testCreationWithEnum() {
    ListMinimizerFactory.create(EnumListMinimizerType.BFS, args).let {
      assertThat(it).isInstanceOf(UnweightedBfsListMinimizer::class.java)
    }
    ListMinimizerFactory
      .create(
        EnumListMinimizerType.PERSES_VARIANT_OF_PRISTINE,
        args,
      ).let {
        assertThat(it).isInstanceOf(DeltaDebugger::class.java)
      }
  }

  @Test
  fun testCreationWithClassName() {
    ListMinimizerFactory.create(UnweightedBfsListMinimizer::class.java.canonicalName, args).let {
      assertThat(it).isInstanceOf(UnweightedBfsListMinimizer::class.java)
    }
  }
}
