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
package org.perses.cmd

import com.beust.jcommander.Parameter
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import org.perses.util.hashing.EnumShaAlgorithm
import java.nio.file.Files
import java.nio.file.Path

class CacheControlFlagGroup : AbstractCommandLineFlagGroup(groupName = "Cache Control") {
  @Parameter(
    names = ["--query-caching"],
    description = "Enable query caching for test script executions.",
    arity = 1,
    order = 0,
  )
  var queryCaching = true

  @Parameter(
    names = ["--edit-caching"],
    description = "Enable caching for edits performed between two successful reductions.",
    arity = 1,
    order = 20,
    hidden = true,
  )
  var nodeActionSetCaching = true

  @Parameter(
    names = ["--pass-level-caching"],
    description = "Whether to enable pass-level cache. If enabled, a reducer might be skipped",
    order = 50,
    hidden = true,
    arity = 1,
  )
  var enablePassCache = true

  @Parameter(
    names = ["--global-caching"],
    description = "Whether to enable pass-level cache. If enabled, a reducer might be skipped",
    order = 55,
    hidden = true,
    arity = 1,
  )
  var enableGlobalCache = false

  @Parameter(
    names = ["--global-cache-file"],
    description = "The file that stores the global cache",
    order = 60,
    hidden = true,
    arity = 1,
  )
  var globalCacheFile: Path? = null

  @Parameter(
    names = ["--path-to-save-updated-global-cache"],
    description = "The file to write the updated global cache",
    order = 70,
    hidden = true,
    arity = 1,
  )
  var pathToSaveUpdatedGlobalCache: Path? = null

  @Parameter(
    names = ["--default-sha-alg-type"],
    description = "The SHA algorithm used in the reduction process",
    order = 100,
    hidden = false,
    arity = 1,
  )
  var defaultShaAlgorithm: EnumShaAlgorithm = EnumShaAlgorithm.SHA256

  override fun validate() {
    globalCacheFile?.let {
      check(Files.isRegularFile(it)) {
        "The global cache file $it is not a file."
      }
      check(enableGlobalCache) {
        "The global cache file is specified, but --global-caching is not specified."
      }
    }
    if (!enableGlobalCache) {
      check(globalCacheFile == null && pathToSaveUpdatedGlobalCache == null) {
        "The global cache is disabled, and all global-cache-related flags should not specified."
      }
    }
  }
}
