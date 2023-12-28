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
package org.perses.grammar.glsl

import com.google.common.collect.ImmutableSet
import org.perses.program.EnumFormatControl
import org.perses.program.LanguageKind

object LanguageGlsl : LanguageKind(
  name = "Glsl",
  extensions = ImmutableSet.of("glsl", "comp", "frag", "vert"),
  defaultCodeFormatControl = EnumFormatControl.COMPACT_ORIG_FORMAT,
  origCodeFormatControl = EnumFormatControl.ORIG_FORMAT,
  allowedCodeFormatControl = ImmutableSet.of(
    EnumFormatControl.SINGLE_TOKEN_PER_LINE,
    EnumFormatControl.COMPACT_ORIG_FORMAT,
    EnumFormatControl.ORIG_FORMAT,
  ),
)
