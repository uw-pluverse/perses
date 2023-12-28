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
package org.perses.antlr.pnf

import com.google.common.collect.ImmutableList
import org.perses.antlr.RuleType
import org.perses.antlr.ast.AbstractPersesRuleDefAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AbstractPersesTerminalAst
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesPlusAst
import org.perses.antlr.ast.PersesSequenceAst
import org.perses.antlr.ast.PersesStarAst
import org.perses.antlr.ast.SmartAstConstructor
import org.perses.util.Interval
import org.perses.util.toImmutableList

object AstUtil {

  inline fun <T> fixpoint(
    initial: T,
    stopCriterion: (prev: T, transformed: T) -> Boolean =
      { prev, transformed -> prev != transformed },
    transform: (T) -> T,
  ): T {
    var current = initial
    var changed: Boolean
    do {
      val prev = current
      current = transform(prev)
      changed = stopCriterion(prev, current)
    } while (changed)
    return current
  }

  fun isSeqOrRuleRefOrTerminal(e: AbstractPersesRuleElement): Boolean {
    when (e.tag) {
      AstTag.SEQUENCE,
      AstTag.RULE_REF,
      AstTag.TERMINAL,
      AstTag.UNKNOWN_TERMINAL_WITH_UNIT_PRECEDENCE,
      -> return true
      else -> {}
    }
    if (e is AbstractPersesTerminalAst) {
      return true
    }
    return false
  }

  class AstEquivalenceClass(val representative: AbstractPersesRuleElement) {

    private val asts = ArrayList<AbstractPersesRuleElement>().apply { add(representative) }

    fun addIfEquivalent(ast: AbstractPersesRuleElement): Boolean {
      if (representative.isEquivalent(ast)) {
        asts.add(ast)
        return true
      }
      return false
    }

    fun getAsts(): Iterable<AbstractPersesRuleElement> = asts

    fun size() = asts.size
  }

  // TODO: test...
  @JvmStatic
  fun findEquivalenceAst(asts: Iterable<AbstractPersesRuleElement>): List<AstEquivalenceClass> {
    val result = ArrayList<AstEquivalenceClass>()
    for (ast in asts) {
      if (!result.any { it.addIfEquivalent(ast) }) {
        result.add(AstEquivalenceClass(ast))
      }
    }
    return result
  }

  @JvmStatic
  fun computeNodeType(ruleDef: AbstractPersesRuleDefAst): RuleType {
    if (ruleDef.isLexerRule) {
      return RuleType.TOKEN
    }
    val ruleBody = ruleDef.body
    return when (ruleBody.tag) {
      AstTag.STAR -> RuleType.KLEENE_STAR
      AstTag.PLUS -> RuleType.KLEENE_PLUS
      AstTag.OPTIONAL -> RuleType.OPTIONAL
      AstTag.ALTERNATIVE_BLOCK -> RuleType.ALT_BLOCKS
      else -> RuleType.OTHER_RULE
    }
  }

  fun concatenateByIgnoringEpsilon(
    elements: List<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    val children = normalizeElementList(elements)
    return SmartAstConstructor.createForSequence(children)
  }

  private fun normalizeElementList(
    elements: List<AbstractPersesRuleElement>,
  ): ImmutableList<AbstractPersesRuleElement> {
    // TODO: convert 'a a*' into a+
    var changed = true
    var current = ImmutableList.copyOf(elements)
    while (changed) {
      changed = false
      val prev = current
      current = removeEpsilon(current)
      current = PersesSequenceAst.flatten(current)
      current = convertStarToPlus(current)
      if (prev != current) {
        changed = true
      }
    }
    return current
  }

  internal fun convertStarToPlus(
    list: List<AbstractPersesRuleElement>,
  ): ImmutableList<AbstractPersesRuleElement> {
    return fixpoint(ImmutableList.copyOf(list)) { current ->
      val starList = current.withIndex()
        .asSequence()
        .filter { it.value is PersesStarAst }
        .map { it.index to it.value as PersesStarAst }
        .toList()
      for (starAndIndex in starList) {
        val star = starAndIndex.second
        val index = starAndIndex.first
        val quantifiedAst = star.body
        val quantifiedElements = if (quantifiedAst is PersesSequenceAst) {
          quantifiedAst.children
        } else {
          ImmutableList.of(quantifiedAst)
        }
        val rangeToReplace: IntRange =
          if (doesBodyAppearBeforeStar(quantifiedElements, index, current)) {
            index - quantifiedElements.size..index
          } else if (doesBodyAppearAfterStar(quantifiedElements, index, current)) {
            index..quantifiedElements.size + index
          } else {
            continue
          }
        return@fixpoint ImmutableList.builder<AbstractPersesRuleElement>().apply {
          (0 until rangeToReplace.first).forEach { add(current[it]) }
          if (star.body is PersesPlusAst) {
            add(star.body)
          } else {
            add(PersesPlusAst(star.body, isGreedy = star.isGreedy))
          }
          (rangeToReplace.last + 1 until current.size).forEach { add(current[it]) }
        }.build()
      }
      current
    }
  }

  private fun doesBodyAppearAfterStar(
    quantifiedElements: ImmutableList<AbstractPersesRuleElement>,
    index: Int,
    current: List<AbstractPersesRuleElement>,
  ) =
    quantifiedElements.size + index < current.size &&
      areEquivalent(
        quantifiedElements,
        current.subList(index + 1, quantifiedElements.size + index + 1),
      )

  private fun doesBodyAppearBeforeStar(
    quantifiedElements: ImmutableList<AbstractPersesRuleElement>,
    index: Int,
    list: List<AbstractPersesRuleElement>,
  ) =
    quantifiedElements.size <= index &&
      areEquivalent(
        quantifiedElements,
        list.subList(index - quantifiedElements.size, index),
      )

  private fun areEquivalent(
    list1: List<AbstractPersesRuleElement>,
    list2: List<AbstractPersesRuleElement>,
  ): Boolean {
    require(list1.size == list2.size) {
      "Two lists should have the same length"
    }
    return list1.zip(list2).all {
      it.first.isEquivalent(it.second)
    }
  }

  private fun removeEpsilon(
    list: ImmutableList<AbstractPersesRuleElement>,
  ): ImmutableList<AbstractPersesRuleElement> {
    return list.asSequence()
      .filter { it.tag != AstTag.EPSILON }
      .toImmutableList()
  }

  fun replaceGapInSequence(
    seq: PersesSequenceAst,
    gap: Interval,
    replacement: AbstractPersesRuleElement,
  ): PersesSequenceAst {
    require(gap.length > 0)
    require(gap.length < seq.childCount)
    val builder = ImmutableList.builder<AbstractPersesRuleElement>()
    var i = 0
    val size = seq.childCount
    while (i < size) {
      if (i == gap.leftInclusive) {
        builder.add(replacement)
      }
      if (gap.leftInclusive <= i && i < gap.rightExclusive) {
        ++i
        continue
      }
      builder.add(seq.getChild(i))
      ++i
    }
    return PersesSequenceAst(builder.build())
  }

  // TODO: needs tests
  fun createAltBlockIfNecessary(
    alternatives: Collection<AbstractPersesRuleElement>,
  ): AbstractPersesRuleElement {
    val flattened = flattenAndDeduplicateAlternatives(alternatives)
    require(flattened.isNotEmpty())
    if (flattened.size == 1) {
      return flattened.single()
    }
    if (flattened.any { it.tag == AstTag.EPSILON }) {
      val nonEpsilonAlternatives =
        flattened
          .asSequence()
          .filter { it.tag != AstTag.EPSILON }
          .toImmutableList()
      assert(nonEpsilonAlternatives.size + 1 == flattened.size)
      assert(nonEpsilonAlternatives.isNotEmpty())
      return if (nonEpsilonAlternatives.size == 1) {
        SmartAstConstructor.createForOptional(
          nonEpsilonAlternatives.single(),
          isGreedy = true,
        )
      } else {
        SmartAstConstructor.createForOptional(
          OptionalExtractionUtil.rewriteAltBlockByExtractingOptionals(
            nonEpsilonAlternatives,
          ),
          isGreedy = true,
        )
      }
    } else {
      return OptionalExtractionUtil.rewriteAltBlockByExtractingOptionals(flattened)
    }
  }

  @JvmStatic
  fun flattenAndDeduplicateAlternatives(
    alternatives: Collection<AbstractPersesRuleElement>,
  ): List<AbstractPersesRuleElement> {
    val flattened = flattenAltBlocks(alternatives)
    val size = flattened.size
    require(size > 0)
    if (size == 1) {
      return ImmutableList.of(flattened.single())
    }
    return SmartAstConstructor.deduplicate(flattened)
  }

  private fun flattenAltBlocks(
    alternatives: Collection<AbstractPersesRuleElement>,
  ): ArrayList<AbstractPersesRuleElement> {
    val result = ArrayList<AbstractPersesRuleElement>()
    for (alternative in alternatives) {
      flatten(alternative, result)
    }
    return result
  }

  private fun flatten(
    element: AbstractPersesRuleElement,
    result: ArrayList<AbstractPersesRuleElement>,
  ) {
    if (element is PersesAlternativeBlockAst) {
      for (blockAlternative in element.alternatives) {
        flatten(blockAlternative, result)
      }
    } else {
      result.add(element)
    }
  }

  @JvmStatic
  fun inPlaceFlattenAltBlocks(alternatives: MutableList<AbstractPersesRuleElement>) {
    val result = flattenAltBlocks(alternatives)
    alternatives.clear()
    alternatives.addAll(result)
  }
}
