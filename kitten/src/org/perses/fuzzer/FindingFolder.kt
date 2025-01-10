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

import com.google.common.base.Strings
import org.perses.util.TimeUtil.formatDateForFileName
import java.io.File
import java.util.concurrent.atomic.AtomicInteger

class FindingFolder(root: File) : AbstractFlatCrashFolder(root) {

  private val counter = AtomicInteger(0)

  fun createBugFolder(prefix: String): File {
    val folderName = (
      prefix +
        formatDateForFileName(System.currentTimeMillis()) +
        "_" +
        Strings.padStart(Integer.toHexString(counter.getAndIncrement()), 4, '0')
      )
    val result = File(root, folderName)
    check(result.mkdir())
    return result
  }

  fun clusterCrashesOnCrashSignatures(): CrashClusterIndex {
    val builder = CrashClusterIndex.Builder()
    for (instance in getAllCrashInstances()) {
      builder.add(instance)
    }
    return builder.build()
  }
}
