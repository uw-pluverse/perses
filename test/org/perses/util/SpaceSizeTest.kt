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
package org.perses.util

import com.google.common.truth.Truth.assertThat
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4

@RunWith(JUnit4::class)
class SpaceSizeTest {
  @Test
  fun testSpaceSize() {
    SpaceSize(bytes = 1000).let {
      assertThat(it.bytes).isEqualTo(1000)
    }
    SpaceSize.kiloBytes(kb = 1).let {
      assertThat(it.bytes).isEqualTo(1000)
      assertThat(it.toKiloBytes()).isEqualTo(1)
      assertThat(it.toMegaBytes()).isEqualTo(0)
      assertThat(it.toGigaBytes()).isEqualTo(0)
    }
    SpaceSize.megaBytes(mb = 1).let {
      assertThat(it.bytes).isEqualTo(1000 * 1000)
      assertThat(it.toKiloBytes()).isEqualTo(1000)
      assertThat(it.toMegaBytes()).isEqualTo(1)
      assertThat(it.toGigaBytes()).isEqualTo(0)
    }
    SpaceSize.megaBytes(mb = 1000).let {
      assertThat(it.toMegaBytes()).isEqualTo(1000)
      assertThat(it.toGigaBytes()).isEqualTo(1)
    }
  }
}
