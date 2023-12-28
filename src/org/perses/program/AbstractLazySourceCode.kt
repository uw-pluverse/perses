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
package org.perses.program

import org.perses.util.FastStringBuilder
import java.io.Writer
import java.nio.charset.StandardCharsets
import java.nio.file.Files
import java.nio.file.Path

abstract class AbstractLazySourceCode {

  val sourceCode: String by lazy {
    stringBuilder.toString()
  }

  private val stringBuilder: FastStringBuilder by lazy {
    computeStringBuilder()
  }

  fun writeTo(writer: Writer) = stringBuilder.writeToWriter(writer)

  fun writeTo(file: Path) =
    Files.newBufferedWriter(file, StandardCharsets.UTF_8).use {
      writeTo(it)
    }

  protected abstract fun computeStringBuilder(): FastStringBuilder
}
