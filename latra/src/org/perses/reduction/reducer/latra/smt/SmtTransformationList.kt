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
package org.perses.reduction.reducer.latra.smt

import org.perses.reduction.reducer.latra.AbstractLatraTransformationList

object SmtTransformationList : AbstractLatraTransformationList() {
  val annotationRemoval =
    registerTransformation(
      name = "AnnotationRemovalTransformation",
      from = "( ! :[term] :[attribute+] )",
      such_as = "",
      where = "",
      to = ":[term]",
    )

  val bvConvertion =
    registerTransformation(
      name = "BvConvertionTransformation",
      from = "(bvnot ( _ bv0 :[num]))",
      such_as = "",
      where = "",
      to = "( _ bv1 :[num])",
    )

  val checkSatAssuming =
    registerTransformation(
      name = "CheckSatAssuminTransformation",
      from = "(check-sat-assuming (:[term]))",
      such_as = "",
      where = "",
      to = "( check-sat )",
    )

  val doubleNeg =
    registerTransformation(
      name = "DoubleNegElimTransformation",
      from = "(bvneg (bvneg :[tem+]))",
      such_as = "",
      where = "",
      to = ":[tem]",
    )

  val doubleNot =
    registerTransformation(
      name = "DoubleNotElimTransformation",
      from = "(bvnot ( bvnot :[tem+]))",
      such_as = "",
      where = "",
      to = ":[tem]",
    )

  val evalFalse =
    registerTransformation(
      name = "EvalFalseTransformation",
      from = "( = false :[term+])",
      such_as = "",
      where = "",
      to = "( not :[term] )",
    )

  val existsRemoval =
    registerTransformation(
      name = "ExistsRemovalTransformation",
      from = "( exists ( :[var+] ) :[term+] )",
      such_as = "",
      where = "",
      to = ":[term]",
    )

  val forallRemoval =
    registerTransformation(
      name = "ForallRemovalTransformation",
      from = "( forall ( :[var+] ) :[term+] )",
      such_as = "",
      where = "",
      to = ":[term]",
    )

  val letSubstitution =
    registerTransformation(
      name = "LetSubstitution",
      from = "( let  (  ( :[sym] :[tem+]) )  :[body+])",
      such_as = "",
      where = "",
      to = ":[body]",
      global_replace = {
        replace(
          pattern = ":[sym]",
          inside = "body",
          with = ":[tem]",
        )
      },
    )

  val mergeAnd =
    registerTransformation(
      name = "MergeAndTransformation",
      from = "(and :[term1+] ( and :[term2+] :[term3+]))",
      such_as = "",
      where = "",
      to = "(and :[term1] :[term2] :[term3])",
    )

  val mergePlus =
    registerTransformation(
      name = "MergePlusTransformation",
      from = "(+ :[term1+] ( + :[term2+] :[term3+]))",
      such_as = "",
      where = "",
      to = "(+ :[term1] :[term2] :[term3])",
    )

  val mergeVariable =
    registerTransformation(
      name = "MergeVariableTransformation",
      from = "( declare-fun :[name] () :[sort] )",
      such_as = "",
      where = "",
      to = "",
      global_replace = {
        replace(
          pattern = "( declare-fun :[name2] () :[sort] )",
          with = "( declare-fun :[name2] () :[sort] )",
        )
        replace(
          pattern = ":[name]",
          with = ":[name2]",
        )
      },
    )

  val substituteWithConst =
    registerTransformation(
      name = "SubstituteWithConstTransformation",
      from = "",
      such_as = "( assert {g:( = false ( _ bv1 123 )):})",
      where = "",
      to = "( _ bv0 1)",
    )
}
