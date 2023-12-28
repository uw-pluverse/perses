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
package org.perses.delta

import org.perses.util.Util
import java.nio.file.Path

class DeltaDebuggerProgressListener(
  file: Path,
) : AbstractDeltaDebuggerListener() {

  private val stream = Util.createNonAppendablePrintStream(
    path = file,
  )

  override fun startReduction(originalInput: List<AbstractDeltaDebugger.ElementWrapper<*>>) {
    val size = originalInput.size
    stream.println("Reduction starts: algorithm=${this::class.qualifiedName}")
    stream.println("The original input has $size element(s).")
    for (i in 0 until size) {
      val element = originalInput[i]
      stream.println("--Element $i")
      stream.println("  index=${element.index}, payload=$element.elementPayload}")
      stream.println("  element=${element.element}")
    }
  }

  override fun endReduction() {
    stream.println("Reduction ends.")
  }

  override fun onBestUpdate(newBest: List<AbstractDeltaDebugger.ElementWrapper<*>>) {
    newBest.map { it.index }.let {
      stream.println("New best is found: $it")
    }
  }

  override fun onPropertyTest(
    configuration: Configuration<*>,
    result: AbstractPropertyTestResultWithPayload<*>,
  ) {
    val idList = configuration.deletedWrappers.map { it.index }
    val resultString = when (result) {
      is SkipPropertyTestResult -> "skip"
      is PropertyTestResultWithPayload -> if (result.result.isInteresting) {
        "interesting"
      } else {
        "uninteresting"
      }
    }
    stream.println("Property Test. Deleted elements: $idList. Interestingness: $resultString")
  }

  override fun log(msg: () -> String) {
    stream.println(msg())
  }

  override fun close() {
    stream.close()
  }
}
