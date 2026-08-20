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
package org.perses.grammar.makefile

import com.google.common.collect.ImmutableSet
import org.perses.program.EnumFormatControl
import org.perses.program.LanguageKind
import java.nio.file.Path

// Reduced line-by-line via the same flat grammar as LanguageLine. Recipe lines depend on a leading
// TAB, so the original byte layout must be preserved: only ORIG_FORMAT is allowed and no reformatter
// is configured.
object LanguageMakefile : LanguageKind(
  name = "makefile",
  extensions = ImmutableSet.of("mk"),
  defaultCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
  origCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
  allowedCodeFormatControl = ImmutableSet.of(EnumFormatControl.ORIG_FORMAT),
) {
  // Canonical make file names carry no extension, so the extension match in super misses them. The
  // comparison is case-insensitive: a test script may load any of these via `make -f <file>`, so we
  // cannot assume make's default (case-sensitive) lookup and do not know which casing the user uses.
  private val lowerCaseFileNames = ImmutableSet.of("makefile", "gnumakefile")

  override fun isOfThisLanguageKind(file: Path): Boolean =
    super.isOfThisLanguageKind(file) || file.fileName.toString().lowercase() in lowerCaseFileNames
}
