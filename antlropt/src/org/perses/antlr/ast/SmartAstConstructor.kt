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
package org.perses.antlr.ast

import com.google.common.collect.ImmutableList
import org.perses.util.toImmutableList

object SmartAstConstructor {

  fun createForAlternatives(
    origAlternatives: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    val alternatives = deduplicate(origAlternatives)
    require(alternatives.isNotEmpty())
    if (alternatives.size == 1) {
      return alternatives.single()
    }
    val hasStarOrEpsilon = alternatives.any {
      it.tag == AstTag.EPSILON || it.tag == AstTag.STAR
    }
    if (!hasStarOrEpsilon) {
      return PersesAlternativeBlockAst(alternatives.toImmutableList())
    }

    val nonEpsilonAlternatives = alternatives
      .asSequence()
      .filter { it.tag != AstTag.EPSILON }
      .map {
        if (it.tag == AstTag.STAR) {
          createPlusFromStarByCopyingBody(it as PersesStarAst)
        } else {
          it
        }
      }.toImmutableList()
    val body = createForAlternatives(nonEpsilonAlternatives)
    return createForOptional(body, isGreedy = true)
  }

  fun createForSequence(
    sequence: Iterable<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    val nonEpsilon = sequence
      .asSequence()
      .filter { it.tag != AstTag.EPSILON }
      .toMutableList()
    removeRedundantQuantifiedNodesInPlace(nonEpsilon)
    return when (nonEpsilon.size) {
      0 -> PersesEpsilonAst()
      1 -> nonEpsilon.single()
      else -> PersesSequenceAst(nonEpsilon.toImmutableList())
    }
  }

  private fun removeRedundantQuantifiedNodesInPlace(
    sequence: MutableList<AbstractPersesRuleElement>,
  ) {
    while (true) {
      val candidate = sequence.withIndex()
        .asSequence()
        .zipWithNext()
        .firstOrNull { (first, second) ->
          areMergeableQuantifiedNodesInSequence(first.value, second.value)
        } ?: return
      val first = candidate.first.value as AbstractPersesQuantifiedAst
      val second = candidate.second.value as AbstractPersesQuantifiedAst
      assert(first.body.isEquivalent(second.body))
      val replacement = tryToMergeQuantifiedNodesInSequence(first, second)!!
      sequence[candidate.first.index] = replacement
      sequence.removeAt(candidate.second.index)
    }
  }

  fun areMergeableQuantifiedNodesInSequence(
    first: AbstractPersesRuleElement,
    second: AbstractPersesRuleElement,
  ): Boolean {
    return tryToMergeQuantifiedNodesInSequence(first, second) != null
  }

  fun tryToMergeQuantifiedNodesInSequence(
    first: AbstractPersesRuleElement,
    second: AbstractPersesRuleElement,
  ): AbstractPersesQuantifiedAst? {
    if (first !is AbstractPersesQuantifiedAst ||
      second !is AbstractPersesQuantifiedAst ||
      !first.body.isEquivalent(second.body)
    ) {
      return null
    }
    return when (first.tag to second.tag) {
      AstTag.STAR to AstTag.STAR,
      AstTag.STAR to AstTag.OPTIONAL,
      -> first as PersesStarAst
      AstTag.STAR to AstTag.PLUS -> second as PersesPlusAst
      AstTag.PLUS to AstTag.STAR,
      AstTag.PLUS to AstTag.OPTIONAL,
      -> first as PersesPlusAst
      AstTag.OPTIONAL to AstTag.STAR -> second as PersesStarAst
      AstTag.OPTIONAL to AstTag.PLUS -> second as PersesPlusAst
      else -> null
    }
  }

  fun createForStar(
    body: AbstractPersesRuleElement,
    isGreedy: Boolean,
  ): AbstractPersesRuleElement {
    return when (body.tag) {
      AstTag.STAR -> body
      AstTag.PLUS -> {
        val plus = body as PersesPlusAst
        PersesStarAst(plus.body, plus.isGreedy)
      }
      AstTag.OPTIONAL -> {
        val optional = body as PersesOptionalAst
        PersesStarAst(optional.body, optional.isGreedy)
      }
      else -> PersesStarAst(body, isGreedy)
    }
  }

  fun createForOptional(
    optionalBody: AbstractPersesRuleElement,
    isGreedy: Boolean,
  ): AbstractPersesRuleElement {
    return when (optionalBody.tag) {
      AstTag.STAR, AstTag.OPTIONAL -> optionalBody
      AstTag.PLUS -> (optionalBody as PersesPlusAst).let {
        PersesStarAst(it.body, it.isGreedy)
      }
      AstTag.EPSILON -> optionalBody
      else -> PersesOptionalAst(optionalBody, isGreedy)
    }
  }

  fun createPlusFromStarByCopyingBody(star: PersesStarAst): PersesPlusAst {
    return PersesPlusAst(body = star.body, isGreedy = star.isGreedy)
  }

  fun createWithNewChildren(
    elementToCopy: AbstractPersesRuleElement,
    children: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    return when (elementToCopy.tag) {
      AstTag.ALTERNATIVE_BLOCK -> createForAlternatives(children)
      AstTag.SEQUENCE -> createForSequence(children)
      else -> elementToCopy.createWithNewChildren(children)
    }
  }

  fun deduplicate(
    alternatives: List<AbstractPersesRuleElement>,
  ): ImmutableList<AbstractPersesRuleElement> {
    val result = ArrayList<AbstractPersesRuleElement>()
    alternatives.forEach { alt ->
      if (result.none { existing -> existing.isEquivalent(alt) }) {
        result.add(alt)
      }
    }
    return result.toImmutableList()
  }
}
