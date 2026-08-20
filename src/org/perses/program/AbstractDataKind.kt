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
package org.perses.program

import com.google.common.collect.ImmutableSet
import com.google.common.io.Files
import org.perses.util.containsNoWhitespace
import java.nio.file.Path

abstract class AbstractDataKind(
  val name: String,
  val extensions: ImmutableSet<String>,
) {
  init {
    extensions.forEach {
      require(it.isNotBlank() && it.first() != '.') {
        "File extension $it should not start with '.'"
      }
      require(it.containsNoWhitespace()) {
        "Extension should contain no whitespace. $it"
      }
    }
  }

  // Whether [file] belongs to this data kind. Takes a Path (not a String) so the caller need not
  // decide between full path and basename: this method extracts the basename itself. The default
  // matches by file extension; a subclass whose files can also be identified by exact name (e.g. an
  // extension-less "Makefile") overrides this, falls back to super, and then compares the name.
  open fun isOfThisLanguageKind(file: Path): Boolean =
    Files.getFileExtension(file.fileName.toString()) in extensions

  final override fun equals(other: Any?): Boolean {
    if (other === this) {
      return true
    }
    if (other == null) {
      return false
    }
    if (other::class.java != this::class.java) {
      return false
    }
    check(other is AbstractDataKind)
    return (name == other.name).also {
      if (it) {
        onEquals(other)
      }
    }
  }

  protected open fun onEquals(other: Any) {}

  final override fun hashCode(): Int = name.hashCode()

  object UnknownDataKind : AbstractDataKind(name = "", extensions = ImmutableSet.of())
}
