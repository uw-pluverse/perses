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
 * The "language" of a recorded program rebuilt from its token spans: tokens at their line and
 * column in the recorded file, with the whitespace between them dropped. Its one code format is
 * [EnumFormatControl.ORIG_FORMAT], which puts every token back at its position: the recorded
 * file is printer output, so between its tokens there are only spaces and newlines, and printing
 * the full tree reproduces it, while a deleted token leaves its place blank, as in the reduction
 * that recorded the problem. Blank lines are kept, so the compact format would not reproduce it.
 */
object LanguageRecordedRanges : LanguageKind(
  name = "recorded-ranges",
  extensions = ImmutableSet.of("recorded_ranges"),
  defaultCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
  origCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
  allowedCodeFormatControl = ImmutableSet.of(EnumFormatControl.ORIG_FORMAT),
  hidden = true,
)
