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
package org.perses.reduction

import org.perses.spartree.NodeReplacementAction
import java.io.BufferedWriter
import java.io.IOException
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path

abstract class AbstractActionSetProfiler {
  abstract fun onReplaceKleeneQualifiedNodeWithKleeneQualifiedDescendant(
    kleeneDescendant: NodeReplacementAction,
  )

  abstract fun onReplaceNodeWithNearestCompatibleDescendant(
    replacement: NodeReplacementAction,
  )

  class ActionSetProfiler(file: Path) : AbstractActionSetProfiler(), AutoCloseable {
    private var writer: BufferedWriter?
    override fun onReplaceKleeneQualifiedNodeWithKleeneQualifiedDescendant(
      kleeneDescendant: NodeReplacementAction,
    ) {
      try {
        writer!!
          .append("onReplaceKleeneQualifiedNodeWithKleeneQualifiedDescendant: ")
          .append("1")
          .append('\n')
          .flush()
      } catch (e: IOException) {
        throw RuntimeException(e)
      }
    }

    override fun onReplaceNodeWithNearestCompatibleDescendant(
      replacement: NodeReplacementAction,
    ) {
      try {
        writer!!
          .append("onReplaceNodeWithNearestCompatibleDescendant: size=")
          .append("1")
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
      writer = Files.newBufferedWriter(file, StandardCharsets.UTF_8)
      Runtime.getRuntime().addShutdownHook(Thread(Runnable { close() }))
    }
  }

  companion object {
    val NULL_PROFILER = object : AbstractActionSetProfiler() {
      override fun onReplaceKleeneQualifiedNodeWithKleeneQualifiedDescendant(
        kleeneDescendant: NodeReplacementAction,
      ) {
      }

      override fun onReplaceNodeWithNearestCompatibleDescendant(
        replacement: NodeReplacementAction,
      ) {
      }
    }
  }
}
