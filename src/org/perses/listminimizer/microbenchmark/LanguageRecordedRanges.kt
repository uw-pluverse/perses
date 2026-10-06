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
package org.perses.listminimizer.microbenchmark

import com.google.common.collect.ImmutableSet
import org.perses.program.EnumFormatControl
import org.perses.program.LanguageKind

/**
 * The "language" of a recorded program cut at its ranges: pieces of text that carry their own
 * whitespace. Its one code format is [EnumFormatControl.VERBATIM], because concatenating the
 * pieces is the only rendering that reproduces the text and removes exactly a deleted element's
 * span; any format that spaces tokens would alter the program under measurement.
 */
object LanguageRecordedRanges : LanguageKind(
  name = "recorded-ranges",
  extensions = ImmutableSet.of("recorded_ranges"),
  defaultCodeFormatControl = EnumFormatControl.VERBATIM,
  origCodeFormatControl = EnumFormatControl.VERBATIM,
  allowedCodeFormatControl = ImmutableSet.of(EnumFormatControl.VERBATIM),
  hidden = true,
)
