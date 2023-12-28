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
package org.perses.antlr.ast

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.antlr.GrammarTestingUtility

@RunWith(JUnit4::class)
class PersesSequenceAstTest {

  @Test
  fun test() {
    val seq = GrammarTestingUtility.createSeqOfTerminals("a", "b", "c")
    val a = seq.getChild(0)
    val b = seq.getChild(1)
    val c = seq.getChild(2)
    assertThat(seq.subsequence(0, 1)).isSameInstanceAs(a)
    assertThat(seq.subsequence(1, 2)).isSameInstanceAs(b)
    assertThat(seq.subsequence(2, 3)).isSameInstanceAs(c)
    seq.subsequence(0, 2).let {
      assertThat(it.childCount).isEqualTo(2)
      assertThat(it.getChild(0)).isSameInstanceAs(a)
      assertThat(it.getChild(1)).isSameInstanceAs(b)
    }
    assertThat(seq.subsequence(0, 0).tag).isEqualTo(AstTag.EPSILON)
  }
}
