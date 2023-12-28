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
package org.perses.version

import org.perses.version.Version.BRANCH
import org.perses.version.Version.BUILD_TIME
import org.perses.version.Version.COMMIT_HASH
import org.perses.version.Version.MAJOR_VERSION
import org.perses.version.Version.MINOR_VERSION
import org.perses.version.Version.STATUS
import java.io.PrintStream

object VersionHelper {

  @JvmStatic
  fun printVersionInfo(programName: String, stream: PrintStream) {
    stream.println("$programName version $MAJOR_VERSION.$MINOR_VERSION")
    if (COMMIT_HASH.isNotBlank()) {
      stream.println("Git Version: $COMMIT_HASH")
    }
    if (BRANCH.isNotBlank()) {
      stream.println("Git Branch: $BRANCH")
    }
    if (STATUS.isNotBlank()) {
      stream.println("Git Status: $STATUS")
    }
    stream.println("Built on $BUILD_TIME")
  }
}
