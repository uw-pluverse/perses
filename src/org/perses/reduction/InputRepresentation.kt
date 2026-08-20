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
package org.perses.reduction

import com.google.common.collect.ImmutableMap
import org.perses.program.AbstractReductionFile
import org.perses.program.ProgramSize
import org.perses.program.TokenizedProgram
import org.perses.reduction.io.AbstractOriginalReductionInputs
import org.perses.reduction.io.PerFileSizeMetrics
import org.perses.reduction.semantics.ISemanticsProvider
import org.perses.spartree.SparTree
import org.perses.spartree.SparTreeSimplifier
import org.perses.util.transformToImmutableList

/**
 * A snapshot of what a single-file reduction is reducing: the [tree] for the active file
 * [fileRepresentedByTree], plus the content of the other (fixed) mutable files in
 * [otherMutableFileContents]. The tree is built from the active file's best program, so the other
 * files' content is read alongside it; together they fully describe the program set under test.
 *
 * Every file's size has exactly one owner: the active file's size lives in the (live)
 * [SparTree.programSnapshot], and each sibling's size lives in its [otherMutableFileContents]
 * entry, paired with the very content it measures. [computePerFileSizeMetrics] composes the two
 * on demand.
 */
class InputRepresentation(
  /** The whole mutable-file set this snapshot belongs to. */
  val originalReductionInputs: AbstractOriginalReductionInputs,
  val tree: SparTree,
  val fileRepresentedByTree: AbstractReductionFile<*, *>,
  /**
   * The content of every mutable file other than [fileRepresentedByTree], each paired with its
   * size as the [ProgramSize] payload. The sibling files are fixed for this snapshot's lifetime,
   * so the sizes cannot go stale. Each sibling's size is lexed with that sibling's own canonical
   * parser facade, so the counts are each file's canonical-grammar counts regardless of the
   * surrogate facade the active tree may use (in a mixed-language set, siblings may resolve to
   * different facades).
   */
  val otherMutableFileContents: ImmutableMap<AbstractReductionFile<*, *>, ProgramSize<String>>,
  /** The semantics for [tree], or null when none are computed (every non-mimir reduction). Computed
   * synchronously when this representation is built, so it reflects the exact source content the tree
   * was parsed from (see [AbstractProgramReductionDriver.createInputRepresentation]). */
  val semantics: ISemanticsProvider?,
) {
  /**
   * Returns the content of a fixed mutable file -- any mutable file other than
   * [fileRepresentedByTree]. This is the textual view of [otherMutableFileContents] for the
   * output-manager machinery, which only needs the content; the size travels with it but is
   * unused there. Throws if [file] is not a carried sibling.
   */
  fun otherMutableFileContentProvider(file: AbstractReductionFile<*, *>): String =
    checkNotNull(otherMutableFileContents[file]) {
      "Not a fixed sibling file of this representation: $file. " +
        "carried=${otherMutableFileContents.keys}"
    }.payload

  /**
   * Computes the moment-in-time size vector of the whole mutable-file set: the active file's
   * slot is read from the live [tree], the sibling slots from [otherMutableFileContents]. The
   * returned object is a snapshot -- recompute after further edits for fresh values.
   *
   * A sibling whose content this representation does not carry contributes a zero-size slot. This
   * is the ppr seed/variant case: those trees derive the other file from the diff and carry no
   * sibling content, so only the represented file has a real size. A regular reduction always
   * carries every sibling, so every slot is real there.
   *
   * The siblings are fixed for this snapshot's lifetime, so the only varying input is
   * [SparTree.programSnapshot], which is reference-stable between tree edits. The result is cached
   * and reused while that snapshot is unchanged. The (snapshot, metrics) pair is held in a single
   * volatile field so concurrent callers always read a consistent pair; a concurrent miss simply
   * recomputes the same value.
   */
  fun computePerFileSizeMetrics(): PerFileSizeMetrics {
    val snapshot = tree.programSnapshot
    cachedMetricsForSnapshot?.let { if (it.snapshot === snapshot) return it.metrics }
    val metrics =
      PerFileSizeMetrics(
        originalReductionInputs,
        originalReductionInputs.mutableFiles.transformToImmutableList<_, ProgramSize<*>> { file ->
          if (file === fileRepresentedByTree) {
            snapshot
          } else {
            otherMutableFileContents[file] ?: ProgramSize.ZERO
          }
        },
      )
    cachedMetricsForSnapshot = MetricsComputedForSnapshot(snapshot, metrics)
    return metrics
  }

  fun simplifySparTree() {
    SparTreeSimplifier.simplify(tree)
  }

  /** The [metrics] last computed by [computePerFileSizeMetrics] and the tree [snapshot] they
   * describe, so they can be reused while the snapshot is unchanged. */
  private class MetricsComputedForSnapshot(
    val snapshot: ProgramSize<TokenizedProgram>,
    val metrics: PerFileSizeMetrics,
  )

  @Volatile
  private var cachedMetricsForSnapshot: MetricsComputedForSnapshot? = null
}
