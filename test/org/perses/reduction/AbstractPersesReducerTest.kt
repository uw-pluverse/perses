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
package org.perses.reduction

import org.perses.TestUtility.createSparTreeFromFile

/** Base class for Perses reducer tests.  */
open class AbstractPersesReducerTest protected constructor() {
  protected val treeT1 = createSparTreeFromFile(MISC_FOLDER + "t1.c")
  protected val treeT8LongExpression2 =
    createSparTreeFromFile(MISC_FOLDER + "t8-long-expression-2.c")
  protected val treeEnclosedExpression =
    createSparTreeFromFile(MISC_FOLDER + "enclosed_expression.c")
  protected val treeEnclosedExpressionInFuncCall =
    createSparTreeFromFile(MISC_FOLDER + "enclosed-expressions-in-function-call.c")
  protected val treeChildTree3 = createSparTreeFromFile("test_data/child_tree_3/t.c")
  protected val treeDelta1 = createSparTreeFromFile("test_data/delta_1/t.c")
  protected val treeDelta2 = createSparTreeFromFile("test_data/delta_2/t.c")
  protected val treeChildTree4 = createSparTreeFromFile("test_data/child_tree_4/t.c")
  protected val treeFuncNameWithParen =
    createSparTreeFromFile("test_data/func_name_with_paren_1/t.c")

  companion object {
    private const val MISC_FOLDER = "test_data/misc/"
  }
}
