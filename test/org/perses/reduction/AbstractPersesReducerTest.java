/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.reduction;

import org.perses.TestUtility;
import org.perses.tree.spar.SparTree;

import java.io.IOException;

/** Base class for Perses reducer tests. */
public class AbstractPersesReducerTest {

  private static final String MISC_FOLDER = "test_data/misc/";
  protected final SparTree treeT1 = TestUtility.createSparTreeFromFile(MISC_FOLDER + "t1.c");
  protected final SparTree treeT8LongExpression2 =
      TestUtility.createSparTreeFromFile(MISC_FOLDER + "t8-long-expression-2.c");
  protected final SparTree treeEnclosedExpression =
      TestUtility.createSparTreeFromFile(MISC_FOLDER + "enclosed_expression.c");
  protected final SparTree treeEnclosedExpressionInFuncCall =
      TestUtility.createSparTreeFromFile(MISC_FOLDER + "enclosed-expressions-in-function-call.c");
  protected final SparTree treeChildTree3 =
      TestUtility.createSparTreeFromFile("test_data/child_tree_3/t.c");
  protected final SparTree treeDelta1 = TestUtility.createSparTreeFromFile("test_data/delta_1/t.c");
  protected final SparTree treeDelta2 = TestUtility.createSparTreeFromFile("test_data/delta_2/t.c");
  protected final SparTree treeChildTree4 =
      TestUtility.createSparTreeFromFile("test_data/child_tree_4/t.c");
  protected final SparTree treeFuncNameWithParen =
      TestUtility.createSparTreeFromFile("test_data/func_name_with_paren_1/t.c");

  protected AbstractPersesReducerTest() throws IOException {}
}
