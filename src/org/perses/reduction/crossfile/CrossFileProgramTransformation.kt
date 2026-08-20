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
package org.perses.reduction.crossfile

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import org.perses.program.AbstractReductionFile

/**
 * The language-agnostic contract for a *cross-file* transformation: given the content of the whole
 * mutable-file set, it produces zero or more whole-set variants -- each a candidate reduction that
 * may change several files at once (e.g. removing an overriding method from a base class and all its
 * subclasses together). The transformation is free to parse and analyze across files to decide its
 * edits; the reduction framework only depends on this contract.
 *
 * Both the input and every returned variant map **every** mutable file to its content; a variant
 * omits no file (and adds none). The reducer tests each variant as a whole set and keeps the best
 * property-preserving one.
 */
interface CrossFileProgramTransformation {
  fun transform(
    fileContents: ImmutableMap<AbstractReductionFile<*, *>, String>,
  ): ImmutableList<ImmutableMap<AbstractReductionFile<*, *>, String>>
}
