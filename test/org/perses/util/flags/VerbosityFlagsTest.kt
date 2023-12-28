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
package org.perses.util.flags

import org.junit.Assert
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.util.cmd.VerbosityFlagGroup
import java.lang.RuntimeException

@RunWith(JUnit4::class)
class VerbosityFlagsTest {

  @Test
  fun testInvalidValueTriggersException() {
    val flags = VerbosityFlagGroup()
    flags.verbosity = "invalid"
    Assert.assertThrows(RuntimeException::class.java) {
      flags.validate()
    }
  }

  @Test
  fun test() {
    val flags = VerbosityFlagGroup()
    flags.validate()
  }
}
