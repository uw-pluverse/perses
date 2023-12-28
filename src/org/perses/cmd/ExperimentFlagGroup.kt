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
import org.perses.reduction.cache.QueryCacheType
import org.perses.util.cmd.AbstractCommandLineFlagGroup

class ExperimentFlagGroup : AbstractCommandLineFlagGroup(groupName = "Experiment Control") {
  @JvmField
  @Parameter(
    names = ["--query-cache-type"],
    description = "the algorithm of the query cache",
    hidden = true,
    order = 1,
  )
  var cacheType: QueryCacheType = QueryCacheType.COMPACT_QUERY_CACHE

  @JvmField
  @Parameter(
    names = ["--on-demand-reducer-classes"],
    description = "the list of reducer classes to be called after the main reduction",
    hidden = true,
    order = 100,
    converter = ClassConverter::class,
  )
  var onDemandReducerClasses: List<Class<*>>? = null

  override fun validate() = Unit

  class ClassConverter : IStringConverter<Class<*>> {
    override fun convert(className: String?): Class<*> {
      requireNotNull(className)
      return Class.forName(className)
    }
  }
}
