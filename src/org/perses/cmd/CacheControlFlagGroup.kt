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
package org.perses.cmd

import com.beust.jcommander.IStringConverter
import com.beust.jcommander.Parameter
import com.beust.jcommander.ParameterException
import org.perses.reduction.cache.EnumQueryCachingControl
import org.perses.util.Fraction
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import java.nio.file.Files
import java.nio.file.Path

class CacheControlFlagGroup : AbstractCommandLineFlagGroup(groupName = "Cache Control") {
  @Parameter(
    names = ["--query-caching"],
    description = "Enable query caching for test script executions.",
    arity = 1,
    converter = QueryCachingControlConverter::class,
    order = 0,
  )
  var queryCaching = EnumQueryCachingControl.AUTO

  @Parameter(
    names = ["--edit-caching"],
    description = "Enable caching for edits performed between two successful reductions.",
    arity = 1,
    order = 1,
    hidden = true,
  )
  var nodeActionSetCaching = true

  @Parameter(
    names = ["--query-cache-refresh-threshold"],
    description = "The threshold triggers a refresh of the query cache. " +
      "The refresh follows the equation: t' - t'' >= t * threshold(%). " +
      "t 	- original tokens. " +
      "t' 	- tokens of the best program at last refresh. " +
      "t''	- tokens of the current best program. " +
      "Refresh threshold requires an integer input ranging [0, 100]. " +
      "e.g. 0 represents 0%, 85 represents 85%.",
    order = 2,
    hidden = true,
  )
  var queryCacheRefreshThreshold = 0 // Represent 0/100 = 0%

  @Parameter(
    names = ["--enable-lightweight-refreshing"],
    description = "Whether to enable lightweight refreshing",
    order = 3,
    hidden = true,
    arity = 1,
  )
  var enableLightweightRefreshing = false

  @Parameter(
    names = ["--pass-level-caching"],
    description = "Whether to enable pass-level cache. If enabled, a reducer might be skipped",
    order = 4,
    hidden = true,
    arity = 1,
  )
  var enablePassCache = false

  @Parameter(
    names = ["--global-cache-file"],
    description = "The file that stores the global cache",
    order = 5,
    hidden = true,
    arity = 1,
  )
  var globalCacheFile: Path? = null

  @Parameter(
    names = ["--path-to-save-updated-global-cache"],
    description = "The file to write the updated global cache",
    order = 6,
    hidden = true,
    arity = 1,
  )
  var pathToSaveUpdatedGlobalCache: Path? = null
  fun getQueryCacheRefreshThreshold(): Fraction {
    return Fraction(queryCacheRefreshThreshold, 100)
  }

  override fun validate() {
    getQueryCacheRefreshThreshold() // Should not throw exceptions.
    globalCacheFile?.let {
      check(Files.isRegularFile(it)) {
        "The global cache file $it is not a file."
      }
    }
  }

  class QueryCachingControlConverter : IStringConverter<EnumQueryCachingControl> {
    override fun convert(flagValue: String?): EnumQueryCachingControl {
      return EnumQueryCachingControl.convert(flagValue!!)
        ?: throw ParameterException(
          "Cannot convert '$flagValue' to an instanceof ${EnumQueryCachingControl::class}",
        )
    }
  }
}
