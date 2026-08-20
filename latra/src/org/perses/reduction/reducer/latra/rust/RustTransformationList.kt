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
package org.perses.reduction.reducer.latra.rust

import org.perses.reduction.reducer.latra.AbstractLatraTransformationList

object RustTransformationList : AbstractLatraTransformationList() {
  val clearBlock =
    registerTransformation(
      name = "ClearBlockTransformation",
      from = "",
      such_as = "fn g (f: impl c<e, j>) -> impl c<e, e::b> {:{ f }:}",
      where = "",
      to = "{ unimplemented!() }",
    )

  val clearStruct =
    registerTransformation(
      name = "ClearStructTransformation",
      from = "",
      such_as =
        """
        struct Person {:{
          name: String,
          age: u32,
        }:}
        """.trimIndent(),
      where = "",
      to = ";",
    )

  val noneDefaulting =
    registerTransformation(
      name = "NoneDefaultingTransformation",
      from = "let :[name] = :[expr+];",
      such_as = "",
      where = "",
      to = "let :[name] = None.unwrap();",
    )
}
