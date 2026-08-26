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
package org.perses.reduction.reducer.sfc

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableListMultimap
import com.google.common.collect.ImmutableSet
import com.google.common.collect.Sets
import org.perses.antlr.RuleHierarchyEntry
import org.perses.spartree.AbstractSparTreeNode
import org.perses.util.toImmutableList

/**
 * Fills the holes of a [RuleAlternativeTemplate] with subtrees of the subtree being converted.
 * Filling a hole picks which subtree's content the candidate will spell; the subtree itself
 * stays where it is, and [CandidateSubtreeBuilder] copies it.
 *
 * Take the template `'<' <expr> ',' <expr> '>'` and the subtree `< a , b >`, whose reusable
 * `expr` subtrees are `a` and `b`. The two holes compete for those two subtrees, so they are
 * filled together: `a` goes to the first hole and `b` to the second, and that is the only
 * filling, because each subtree is used at most once (Principle 2 of the SFC paper) and their
 * order is kept (Principle 3).
 *
 * Competing holes are what makes this more than a loop over the holes, so the holes are put in
 * groups: the holes of one symbol are filled together by [groupHoles], while a quantified hole
 * takes one subtree, none, or every one of them, and forms a group of its own.
 */
object TemplateHoleFiller {
  /**
   * Every way to fill the holes of [template] with subtrees under [subtreeRootToConvert].
   * [isReuseAllowed] is the caller's veto over which of those subtrees may be reused.
   */
  fun findEveryFillingOfHoles(
    template: RuleAlternativeTemplate,
    subtreeRootToConvert: AbstractSparTreeNode,
    isReuseAllowed: (subtreeRoot: AbstractSparTreeNode) -> Boolean,
  ): Sequence<TemplateFilling> =
    when (
      val grouping =
        groupHolesToFillTogether(template.holes, subtreeRootToConvert, isReuseAllowed)
    ) {
      is HoleGrouping.UnfillableHole -> emptySequence()
      is HoleGrouping.Grouped -> searchFillingsGroupByGroup(template.holes, grouping.holeGroups)
    }

  /**
   * The holes of [holes] in the groups that are filled together, each group carrying every way
   * of filling its own holes. Holes of one symbol compete for the subtrees that symbol offers,
   * so they land in one group; a quantified hole takes its subtrees on its own.
   */
  private fun groupHolesToFillTogether(
    holes: ImmutableList<TemplateElement.Hole>,
    subtreeRootToConvert: AbstractSparTreeNode,
    isReuseAllowed: (subtreeRoot: AbstractSparTreeNode) -> Boolean,
  ): HoleGrouping {
    val reusableSubtreesMap = SymbolToReusableSubtreesMap(subtreeRootToConvert, isReuseAllowed)
    val quantifiedHoleGroups = ImmutableList.builder<HoleGroup>()
    val competingHolesPerSymbol =
      ImmutableListMultimap.builder<RuleHierarchyEntry, TemplateElement.Hole>()
    holes.forEach { hole ->
      val reuseableSubtrees = reusableSubtreesMap.lookUpOrCompute(hole.symbol)
      when (hole.quantifier) {
        Quantifier.EXACTLY_ONE -> competingHolesPerSymbol.put(hole.symbol, hole)
        Quantifier.OPTIONAL ->
          quantifiedHoleGroups.add(HoleGroup.takingOneSubtreeOrNothing(hole, reuseableSubtrees))
        Quantifier.STAR ->
          quantifiedHoleGroups.add(HoleGroup.takingEverySubtreeOrNothing(hole, reuseableSubtrees))
        Quantifier.PLUS -> {
          if (reuseableSubtrees.isEmpty()) {
            return HoleGrouping.UnfillableHole
          }
          quantifiedHoleGroups.add(HoleGroup.takingEverySubtree(hole, reuseableSubtrees))
        }
      }
    }

    val groupsOfCompetingHoles = ImmutableList.builder<HoleGroup>()
    for ((symbol, competingHoles) in competingHolesPerSymbol.build().asMap()) {
      val subtrees = reusableSubtreesMap.lookUpOrCompute(symbol)
      if (subtrees.size < competingHoles.size) {
        return HoleGrouping.UnfillableHole
      }
      groupsOfCompetingHoles.add(
        HoleGroup.distributingSubtreesOverHoles(competingHoles.toImmutableList(), subtrees),
      )
    }
    // The competing holes constrain the search the most, so they are filled first.
    return HoleGrouping.Grouped(
      ImmutableList
        .builder<HoleGroup>()
        .addAll(groupsOfCompetingHoles.build())
        .addAll(quantifiedHoleGroups.build())
        .build(),
    )
  }

  /**
   * What [groupHolesToFillTogether] found: either the groups to fill, or a hole that cannot be
   * filled.
   */
  private sealed class HoleGrouping {
    /**
     * The groups to fill. There are none when the alternative spells only constants, which is
     * filled in exactly one way, by filling nothing -- not the same as [UnfillableHole].
     */
    class Grouped(
      val holeGroups: ImmutableList<HoleGroup>,
    ) : HoleGrouping()

    /**
     * A hole has no subtree to take: a `+` hole with nothing to reuse, or holes of one symbol
     * outnumbering the subtrees that symbol offers. The template cannot be filled at all.
     */
    data object UnfillableHole : HoleGrouping()
  }

  /**
   * Every way to take one candidate filling from each group, in the order the holes are spelled
   * so that the fillings of one template are easy to compare and to print.
   */
  private fun searchFillingsGroupByGroup(
    holes: ImmutableList<TemplateElement.Hole>,
    holeGroups: List<HoleGroup>,
  ): Sequence<TemplateFilling> =
    takeOneFillingPerGroup(holeGroups, ImmutableList.of()).map { filledHoles ->
      val inHoleOrder = ImmutableList.builder<FilledHole>()
      holes.forEach { hole -> inHoleOrder.add(filledHoles.single { it.hole === hole }) }
      TemplateFilling(inHoleOrder.build())
    }

  /**
   * Every way to take one candidate filling from each of [holeGroups], skipping a candidate
   * whose subtrees overlap [subtreesTakenByEarlierGroups] or one another, since an overlapping
   * part would be spelled twice.
   */
  private fun takeOneFillingPerGroup(
    holeGroups: List<HoleGroup>,
    subtreesTakenByEarlierGroups: ImmutableList<AbstractSparTreeNode>,
  ): Sequence<List<FilledHole>> {
    val firstGroup = holeGroups.firstOrNull() ?: return sequenceOf(emptyList())
    val remainingGroups = holeGroups.subList(1, holeGroups.size)
    return firstGroup.candidateFillings
      .filter { canTakeAllOf(it.subtreesToTake(), subtreesTakenByEarlierGroups) }
      .flatMap { candidateFilling ->
        val subtreesTaken =
          ImmutableList
            .builder<AbstractSparTreeNode>()
            .addAll(subtreesTakenByEarlierGroups)
            .addAll(candidateFilling.subtreesToTake())
            .build()
        takeOneFillingPerGroup(remainingGroups, subtreesTaken).map { candidateFilling + it }
      }
  }

  private fun List<FilledHole>.subtreesToTake(): List<AbstractSparTreeNode> =
    flatMap { it.subtreesToCopy }

  /** Whether all of [subtreesToTake] can join [subtreesTakenSoFar] without any overlap. */
  private fun canTakeAllOf(
    subtreesToTake: List<AbstractSparTreeNode>,
    subtreesTakenSoFar: List<AbstractSparTreeNode>,
  ): Boolean =
    subtreesToTake.indices.none { index ->
      val subtree = subtreesToTake[index]
      subtreesTakenSoFar.any { StructureReuseFinder.doSubtreesOverlap(it, subtree) } ||
        (index + 1 until subtreesToTake.size).any {
          StructureReuseFinder.doSubtreesOverlap(subtree, subtreesToTake[it])
        }
    }

  /**
   * The subtrees a symbol offers for reuse. Computing them walks the converted subtree, so the
   * first lookup of a symbol pays for a search and the later ones do not.
   */
  private class SymbolToReusableSubtreesMap(
    private val subtreeRootToConvert: AbstractSparTreeNode,
    private val isReuseAllowed: (subtreeRoot: AbstractSparTreeNode) -> Boolean,
  ) {
    // A map of lists rather than a multimap: a multimap answers an absent key with an empty
    // collection, which is also the answer for a symbol that offers nothing, and the search
    // would then be redone on every lookup for exactly those symbols.
    private val subtreesPerSymbol =
      HashMap<RuleHierarchyEntry, ImmutableList<AbstractSparTreeNode>>()

    fun lookUpOrCompute(symbol: RuleHierarchyEntry): ImmutableList<AbstractSparTreeNode> =
      subtreesPerSymbol.getOrPut(symbol) {
        StructureReuseFinder.findHighestReusableSubtreesUnder(
          subtreeRootToConvert,
          symbol,
          isReuseAllowed,
        )
      }
  }

  /**
   * The holes that are filled together, and every candidate filling of them: a candidate covers
   * the holes of this group, whereas a [TemplateFilling] covers the holes of the template.
   *
   * [candidateFillings] is a sequence because a group can offer many candidates and the search
   * rarely wants them all: it stops at the first that fits, and the reducer downstream caps how
   * many candidates it tests. The sequence must be re-iterable, since the search walks a group's
   * candidates once per combination the earlier groups chose.
   */
  private class HoleGroup(
    val candidateFillings: Sequence<ImmutableList<FilledHole>>,
  ) {
    companion object {
      /** A `?` hole: each subtree in turn, and then no subtree at all. */
      fun takingOneSubtreeOrNothing(
        hole: TemplateElement.Hole,
        reusableSubtrees: ImmutableList<AbstractSparTreeNode>,
      ) = HoleGroup(
        reusableSubtrees
          .asSequence()
          .map { ImmutableList.of(FilledHole.withSubtree(hole, it)) }
          .plus(sequenceOf(ImmutableList.of(FilledHole.withoutSubtree(hole)))),
      )

      /** A `*` hole: every subtree at once (Principle 5), and then no subtree at all. */
      fun takingEverySubtreeOrNothing(
        hole: TemplateElement.Hole,
        reusableSubtrees: ImmutableList<AbstractSparTreeNode>,
      ) = HoleGroup(
        sequenceOf(
          ImmutableList.of(everySubtreeAtOnce(hole, reusableSubtrees)),
          ImmutableList.of(FilledHole.withoutSubtree(hole)),
        ),
      )

      /** A `+` hole: every subtree at once, and nothing else, as it cannot stay empty. */
      fun takingEverySubtree(
        hole: TemplateElement.Hole,
        reusableSubtrees: ImmutableList<AbstractSparTreeNode>,
      ) = HoleGroup(
        sequenceOf(ImmutableList.of(everySubtreeAtOnce(hole, reusableSubtrees))),
      )

      /**
       * Holes of one symbol: each way of dealing the subtrees out to them, one subtree per hole,
       * keeping the order of the subtrees (Principle 3) and using each at most once
       * (Principle 2). The caller has checked that there are enough subtrees, which is what
       * Sets.combinations requires.
       */
      fun distributingSubtreesOverHoles(
        competingHoles: ImmutableList<TemplateElement.Hole>,
        reusableSubtrees: ImmutableList<AbstractSparTreeNode>,
      ) = HoleGroup(
        Sets
          .combinations(ImmutableSet.copyOf(reusableSubtrees), competingHoles.size)
          .asSequence()
          .map { chosenSubtrees ->
            competingHoles
              .zip(chosenSubtrees) { hole, subtree -> FilledHole.withSubtree(hole, subtree) }
              .toImmutableList()
          },
      )

      /**
       * The subtrees of [reusableSubtrees] that no other one of them contains. Reusable subtrees
       * can contain one another: [StructureReuseFinder] keeps looking below a subtree that spans
       * the whole converted subtree, and those spans nest by construction.
       */
      private fun everySubtreeAtOnce(
        hole: TemplateElement.Hole,
        reusableSubtrees: ImmutableList<AbstractSparTreeNode>,
      ): FilledHole =
        FilledHole.withSubtrees(
          hole,
          reusableSubtrees
            .filter { subtree ->
              reusableSubtrees.none { other ->
                other !== subtree &&
                  StructureReuseFinder.doSubtreesOverlap(other, subtree) &&
                  other.leafTokenCount > subtree.leafTokenCount
              }
            }.toImmutableList(),
        )
    }
  }
}
