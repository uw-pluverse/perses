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
package org.perses

import com.google.common.collect.ImmutableList
import org.perses.listener.LoggingListener
import org.perses.listener.ProgressMonitorForNodeReducer
import org.perses.listener.StatisticsListener
import org.perses.listener.TestScriptExecutionListener
import org.perses.reduction.AbstractReductionListener
import org.perses.reduction.AsyncReductionListenerManager
import org.perses.util.FileStreamPool
import kotlin.io.path.name

object PersesListenerManagerCreator {

  fun createAsyncReductionListenerManager(
    cmd: CommandOptions,
    fileStreamPool: FileStreamPool,
  ): AsyncReductionListenerManager {
    val builder = ImmutableList.builder<AbstractReductionListener>()
    builder.add(LoggingListener())
    cmd.profilingFlags.statDumpFile?.let {
      builder.add(
        StatisticsListener(
          fileStreamPool.rentStream(
            path = it,
            description = StatisticsListener::class.toString(),
          ),
        ),
      )
    }
    cmd.profilingFlags.progressDumpFile?.let {
      val stream = fileStreamPool.rentStream(
        path = it,
        description = ProgressMonitorForNodeReducer::class.toString(),
      )
      builder.add(
        ProgressMonitorForNodeReducer(stream),
      )
    }
    cmd.profilingFlags.statDumpFile?.parent?.resolve(
      "testscript-" + cmd.profilingFlags.statDumpFile?.name,
    )?.let {
      builder.add(
        TestScriptExecutionListener(
          fileStreamPool.rentStream(
            path = it,
            description = TestScriptExecutionListener::class.toString(),
          ),
        ),
      )
    }
    return AsyncReductionListenerManager(listeners = builder.build())
  }
}
