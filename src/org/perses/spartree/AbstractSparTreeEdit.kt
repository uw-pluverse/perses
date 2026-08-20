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
package org.perses.spartree
import com.google.common.base.MoreObjects
import com.google.common.collect.ComparisonChain
import com.google.common.collect.ImmutableList
import org.perses.program.AbstractPersesToken
import org.perses.program.TokenizedProgram
import java.util.concurrent.atomic.AtomicInteger
import kotlin.getValue

sealed class AbstractSparTreeEdit<T : AbstractTreeEditAction>(
  val actionSet: AbstractActionSet<T>,
  val tree: SparTree,
) : Comparable<AbstractSparTreeEdit<*>> {
  private val id: Int = idGenerator.getAndIncrement()
  private val treeSnapshotVersion = tree.version
  val tokenCountBeforeEdit = tree.programSnapshot

  val program by lazy {
    checkTreeVersion()
    computeProgram()
  }

  val structureDescription: String
    get() =
      if (structureDescriptionPrefix.isEmpty()) {
        actionSet.structureDescription
      } else {
        "$structureDescriptionPrefix:${actionSet.structureDescription}"
      }

  val lazilyComputedDeletedTokens by lazy {
    if (tree.version != treeSnapshotVersion) {
      AbstractDeletedTokens.Errored(
        message = "The tree has been modified.",
        editClass = this::class.java,
      )
    } else {
      checkTreeVersion()
      computeDeletedTokens()
    }
  }

  protected abstract fun computeDeletedTokens(): AbstractDeletedTokens

  protected abstract val structureDescriptionPrefix: String

  fun asNodeDeleteEdit(): NodeDeletionTreeEdit = this as NodeDeletionTreeEdit

  fun asNodeReplacementEdit(): DescendantHoistingTreeEdit = this as DescendantHoistingTreeEdit

  fun asLatraGeneralEdit() = this as LatraGeneralTreeEdit

  fun asAnyNodeReplacementEdit(): AnyNodeReplacementTreeEdit = this as AnyNodeReplacementTreeEdit

  val numberOfActions: Int
    get() = actionSet.size()

  fun isNodeATarget(node: AbstractSparTreeNode?): Boolean = actionSet.containsNodeAsTarget(node!!)

  override fun compareTo(other: AbstractSparTreeEdit<*>): Int =
    ComparisonChain
      .start()
      .compare(program.tokenCount, other.program.tokenCount)
      .compare(program.totalCharacterCount, other.program.totalCharacterCount)
      .compare(id, other.id)
      .result()

  fun computeProgram(): TokenizedProgram {
    // Trigger the computation of the deleted tokens as well, before the edit is materialized.
    lazilyComputedDeletedTokens
    return internalComputeProgram(tree)
  }

  protected abstract fun internalComputeProgram(tree: SparTree): TokenizedProgram

  override fun toString(): String =
    MoreObjects.toStringHelper(this).addValue(actionSet.structureDescription).toString()

  /**
   * This method is marked internal, because we do not want this method to be called
   * outside of SparTree. This method should be only called in SparTree so that we can
   * track the edits to a spar tree.
   */
  internal fun applyToTree() {
    checkTreeVersion()
    // Trigger the computation of the deleted tokens as well, before the edit is materialized.
    lazilyComputedDeletedTokens
    internalApplyToTree()
  }

  private fun checkTreeVersion() {
    check(tree.version == treeSnapshotVersion) {
      "Different tree versions: current: ${tree.version}, snapshot version: $treeSnapshotVersion"
    }
  }

  internal abstract fun internalApplyToTree()

  sealed class AbstractDeletedTokens {
    val sourceCode by lazy {
      toCode()
    }

    protected abstract fun toCode(): String

    override fun toString(): String = sourceCode

    class Errored(
      val message: String,
      val editClass: Class<out AbstractSparTreeEdit<*>>,
    ) : AbstractDeletedTokens() {
      override fun toCode(): String =
        MoreObjects
          .toStringHelper(this)
          .addValue(message)
          .addValue(editClass)
          .toString()
    }

    class Unsupported(
      val editClass: Class<out AbstractSparTreeEdit<*>>,
    ) : AbstractDeletedTokens() {
      override fun toCode(): String =
        MoreObjects.toStringHelper(this).addValue(editClass).toString()
    }

    class DeletedTokens(
      val tokens: ImmutableList<AbstractPersesToken.AntlrToken>,
    ) : AbstractDeletedTokens() {
      override fun toCode(): String = computeDeletedCodeForAntlrTokens(tokens)
    }
  }

  companion object {
    fun createDeletionSparTreeEdit(
      tree: SparTree,
      actionSet: NodeDeletionActionSet,
    ): NodeDeletionTreeEdit = NodeDeletionTreeEdit(tree, actionSet)

    fun createReplacementSparTreeEdit(
      tree: SparTree,
      actionSet: NodeReplacementActionSet,
    ): DescendantHoistingTreeEdit = DescendantHoistingTreeEdit(tree, actionSet)

    fun computeDeletedCodeForAntlrTokens(
      deletedNodes: List<AbstractPersesToken.AntlrToken>,
    ): String {
      if (deletedNodes.isEmpty()) return "<empty>"

      val maxLineNum = deletedNodes.maxOf { it.position.line }
      val maxLineNumWidth = maxLineNum.toString().length

      return buildString {
        var currentLine = -1
        var currentPos = 0
        for (token in deletedNodes) {
          if (token.position.line != currentLine) {
            if (currentLine != -1) append("\n")
            currentLine = token.position.line
            append(currentLine.toString().padStart(maxLineNumWidth)).append(":")
            currentPos = 0
          }

          val charPos = token.position.charPositionInLine
          if (charPos > currentPos) {
            append(" ".repeat(charPos - currentPos))
          }
          append(token.lexemeText)
          currentPos = charPos + token.lexemeText.length
        }
      }
    }

    fun createAnyNodeReplacementTreeEdit(
      tree: SparTree,
      actionSet: NodeReplacementActionSet,
    ): AnyNodeReplacementTreeEdit = AnyNodeReplacementTreeEdit(tree, actionSet)

    fun createLatraGeneralTreeEdit(
      tree: SparTree,
      actionSet: LatraGeneralActionSet,
    ): LatraGeneralTreeEdit = LatraGeneralTreeEdit(tree, actionSet)

    private val idGenerator = AtomicInteger()
  }
}
