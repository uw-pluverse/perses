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
package org.perses.spartree

import org.perses.program.TokenizedProgram

/**
 * The primary tree data structure for Perses program reduction. This interface serves as an
 * immutable information provider.
 */
abstract class AbstractUnmodifiableSparTree {

  val tokenCount: Int
    get() = programSnapshot.tokenCount()

  abstract val programSnapshot: TokenizedProgram

  abstract val root: AbstractSparTreeNode

  abstract fun printTreeStructure(): String
}
