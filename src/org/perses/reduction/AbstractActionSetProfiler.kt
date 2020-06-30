/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.reduction

import com.google.common.collect.ImmutableList
import org.perses.tree.spar.ChildHoistingAction
import java.io.BufferedWriter
import java.io.File
import java.io.IOException
import java.nio.charset.StandardCharsets
import java.nio.file.Files

abstract class AbstractActionSetProfiler {
  abstract fun onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren(
    kleeneReplacements: ImmutableList<ChildHoistingAction>
  )

  abstract fun onReplaceNodeWithNearestCompatibleChildren(
    replacements: ImmutableList<ChildHoistingAction>
  )

  class ActionSetProfiler(file: File) : AbstractActionSetProfiler(), AutoCloseable {
    private var writer: BufferedWriter?
    override fun onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren(
      kleeneReplacements: ImmutableList<ChildHoistingAction>
    ) {
      try {
        writer!!
          .append("onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren: size=")
          .append(kleeneReplacements.size.toString())
          .append('\n')
          .flush()
      } catch (e: IOException) {
        throw RuntimeException(e)
      }
    }

    override fun onReplaceNodeWithNearestCompatibleChildren(
      replacements: ImmutableList<ChildHoistingAction>
    ) {
      try {
        writer!!
          .append("onReplaceNodeWithNearestCompatibleChildren: size=")
          .append(replacements.size.toString())
          .append('\n')
          .flush()
      } catch (e: IOException) {
        throw RuntimeException(e)
      }
    }

    override fun close() {
      try {
        val local = writer
        writer = null
        local?.close()
      } catch (e: IOException) {
        throw RuntimeException(e)
      }
    }

    init {
      writer = Files.newBufferedWriter(file.toPath(), StandardCharsets.UTF_8)
      Runtime.getRuntime().addShutdownHook(Thread(Runnable { close() }))
    }
  }

  companion object {
    val NULL_PROFILER = object : AbstractActionSetProfiler() {
      override fun onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren(
        kleeneReplacements: ImmutableList<ChildHoistingAction>
      ) {
      }

      override fun onReplaceNodeWithNearestCompatibleChildren(
        replacements: ImmutableList<ChildHoistingAction>
      ) {
      }
    }
  }
}
