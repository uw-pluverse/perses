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
package org.perses.reduction.reducer.latra.wat

import org.perses.reduction.reducer.latra.AbstractLatraTransformationList

object WatFineGritTransformationList : AbstractLatraTransformationList() {
  val replaceBranchIfWithDrop =
    registerTransformation(
      name = "ReplaceBrIfWithDrop",
      from =
        """
        br_if :[number]  
        """.trimIndent(),
      to =
        """
        drop  
        """.trimIndent(),
    )

  val dropPairedBlockEndTokens =
    registerTransformation(
      name = "DropPairedBlockEndTokens",
      from =
        """
        block
          :[body+]
        br :[number]
        end
        """.trimIndent(),
      to =
        """
        :[body]
        """.trimIndent(),
    )

  val removePairedIfEndTokens =
    registerTransformation(
      name = "RemovePairedIfEndTokens",
      from =
        """
        if
          :[body+]
        end
        """.trimIndent(),
      to =
        """
        drop
        :[body]
        """.trimIndent(),
    )

  val replaceIfBlockWithTrueBranch =
    registerTransformation(
      name = "ReplaceIfBlockWithTrueBranch",
      from =
        """
        if
          :[true_branch+]
        else
          :[else_branch+]
        end  
        """.trimIndent(),
      to =
        """
        drop
         :[true_branch]
        """.trimIndent(),
    )

  /**
   * TODO(cnsun): we need to support Kleene Star, so that we can merge this with
   *  replaceIfBlockWithTrueBranch
   */
  val replaceIfBlockWithTrueBranch2 =
    registerTransformation(
      name = "ReplaceIfBlockWithTrueBranch2",
      from =
        """
        if
          :[true_branch+]
        else
        end  
        """.trimIndent(),
      to =
        """
        drop
         :[true_branch]
        """.trimIndent(),
    )

  val replaceIfBlockWithFalseBranch =
    registerTransformation(
      name = "ReplaceIfBlockWithFalseBranch",
      from =
        """
        if
          :[true_branch+]
        else
          :[else_branch+]
        end  
        """.trimIndent(),
      to =
        """
        drop
         :[else_branch]
        """.trimIndent(),
    )

  /**
   * TODO(cnsun): we need to support Kleene Star, so that we can merge this with
   *  replaceIfBlockWithTrueBranch
   */
  val replaceIfBlockWithFalseBranch2 =
    registerTransformation(
      name = "ReplaceIfBlockWithFalseBranch2",
      from =
        """
        if
        else
          :[else_branch+]
        end  
        """.trimIndent(),
      to =
        """
        drop
         :[else_branch]
        """.trimIndent(),
    )
}
