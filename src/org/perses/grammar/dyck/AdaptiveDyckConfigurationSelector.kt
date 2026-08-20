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
package org.perses.grammar.dyck

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableSet
import com.google.common.collect.Sets
import org.antlr.v4.runtime.Token

/**
 * Derives the delimiter kinds from the input instead of fixing them up front: it enables the largest
 * set of kinds whose delimiters, taken together, form a well-nested (Dyck) string, and demotes the
 * rest to `OTHER`.
 *
 * Enabling a kind whose delimiters do not nest is what makes a fixed Dyck facade fail: an unmatched
 * `}` (say, one arm of an `#if`) has no parse under any of the Dyck grammars. Dropping that kind
 * always yields a parse, because a stream with no enabled delimiter is a flat run of `OTHER`. So
 * this selector always returns a configuration the Dyck parsers accept, while keeping every kind
 * that does carry structure.
 *
 * The search runs in two steps, and the first prunes the second:
 *  1. [collectIndividuallyPairedDelimiters] discards every kind that does not pair within itself.
 *  2. [selectKindsThatNestTogether] settles the kinds that are left but interleave.
 */
object AdaptiveDyckConfigurationSelector : DyckLexer.ConfigurationSelector {
  override fun selectFor(tokens: List<Token>): DyckLexer.Configuration {
    val paired = collectIndividuallyPairedDelimiters(tokens)
    val enabledKinds = selectKindsThatNestTogether(paired)
    return DyckLexer.Configuration(
      enableBraces = DelimiterKind.BRACE in enabledKinds,
      enableBrackets = DelimiterKind.BRACKET in enabledKinds,
      enableParentheses = DelimiterKind.PARENTHESIS in enabledKinds,
    )
  }

  /**
   * The delimiters of the kinds that pair within themselves, in source order, plus those kinds. A
   * kind pairs when its own opens and closes match up, each kind judged on its own with interleaving
   * across kinds ignored -- `{ ( } )` pairs both kinds here, and is left to
   * [selectKindsThatNestTogether].
   *
   * A kind that does not even pair on its own is dropped outright, delimiters and all: it can belong
   * to no well-nested set, because projecting a well-nested string onto a single kind leaves a
   * well-nested string over that kind. Everything downstream therefore works on a smaller array and
   * a smaller set of kinds.
   */
  private fun collectIndividuallyPairedDelimiters(tokens: List<Token>): PairedDelimiters {
    val delimiters = StringBuilder()
    val depths = IntArray(DelimiterKind.entries.size)
    val isBroken = BooleanArray(DelimiterKind.entries.size)
    for (token in tokens) {
      val text = token.text
      val kind = (if (text.length == 1) DelimiterKind.ofOrNull(text[0]) else null) ?: continue
      val delimiter = text[0]
      delimiters.append(delimiter)
      if (delimiter == kind.open) {
        ++depths[kind.ordinal]
      } else if (depths[kind.ordinal]-- == 0) {
        // A close with nothing open before it breaks the kind for good: a later open must not bring
        // the depth back to zero and hide it.
        isBroken[kind.ordinal] = true
      }
    }
    val pairedKinds =
      setOfKinds(DelimiterKind.entries.filter { depths[it.ordinal] == 0 && !isBroken[it.ordinal] })
    return PairedDelimiters(retainKindsOf(delimiters, pairedKinds), pairedKinds)
  }

  private fun retainKindsOf(
    delimiters: StringBuilder,
    kinds: ImmutableSet<DelimiterKind>,
  ): CharArray {
    if (kinds.size == DelimiterKind.entries.size) {
      return delimiters.copyToCharArray()
    }
    val retained = StringBuilder(delimiters.length)
    for (delimiter in delimiters) {
      val kind = DelimiterKind.ofOrNull(delimiter)
      if (kind != null && kind in kinds) {
        retained.append(delimiter)
      }
    }
    return retained.copyToCharArray()
  }

  /**
   * The largest subset of [PairedDelimiters.kinds] whose delimiters also nest across kinds, dropping
   * the least preferred kind first when the choice is otherwise a tie.
   *
   * Trying only the subsets that drop a single kind is exhaustive because there are three kinds: the
   * remaining subsets hold at most one kind, and a single kind nests by construction -- it paired in
   * step one -- so the fallback needs no test and is simply the most preferred kind still in play.
   * That also covers fewer than two paired kinds, which [testKindsNestTogether] accepts outright.
   */
  private fun selectKindsThatNestTogether(paired: PairedDelimiters): ImmutableSet<DelimiterKind> {
    if (testKindsNestTogether(paired.delimiters, paired.kinds)) {
      return paired.kinds
    }
    val byDecreasingPreference =
      DELIMITER_KINDS_BY_DECREASING_PREFERENCE.filter {
        it in
          paired.kinds
      }
    var enabledKinds: ImmutableSet<DelimiterKind> = setOfKinds(byDecreasingPreference.take(1))
    for (droppedKind in byDecreasingPreference.reversed()) {
      val candidate = setOfKinds(paired.kinds - droppedKind)
      if (testKindsNestTogether(paired.delimiters, candidate)) {
        enabledKinds = candidate
        break
      }
    }
    return enabledKinds
  }

  /** A single kind needs no test: it paired in step one, and no other kind can interleave with it. */
  private fun testKindsNestTogether(
    delimiters: CharArray,
    kinds: ImmutableSet<DelimiterKind>,
  ): Boolean = kinds.size < 2 || isWellNested(delimiters, kinds)

  private fun isWellNested(
    delimiters: CharArray,
    kinds: ImmutableSet<DelimiterKind>,
  ): Boolean {
    val expectedCloses = CharArray(delimiters.size)
    var depth = 0
    for (delimiter in delimiters) {
      val kind = DelimiterKind.ofOrNull(delimiter)
      if (kind == null || kind !in kinds) {
        continue
      }
      if (delimiter == kind.open) {
        expectedCloses[depth++] = kind.close
      } else if (depth == 0 || expectedCloses[--depth] != delimiter) {
        return false
      }
    }
    return depth == 0
  }

  /** What step one leaves behind: the surviving delimiters, and the kinds they belong to. */
  private class PairedDelimiters(
    /** In source order, and holding only delimiters of a kind in [kinds]. */
    val delimiters: CharArray,
    val kinds: ImmutableSet<DelimiterKind>,
  )

  /**
   * The declaration order carries no meaning; which kind outranks which is stated once, in
   * [DELIMITER_KINDS_BY_DECREASING_PREFERENCE].
   */
  private enum class DelimiterKind(
    val open: Char,
    val close: Char,
  ) {
    BRACE('{', '}'),
    PARENTHESIS('(', ')'),
    BRACKET('[', ']'),
    ;

    companion object {
      // A switch on the character rather than a scan of the constants: this runs once per token of
      // the file. It restates the characters above, which is why it lives next to them.
      fun ofOrNull(character: Char): DelimiterKind? =
        when (character) {
          '{', '}' -> BRACE
          '(', ')' -> PARENTHESIS
          '[', ']' -> BRACKET
          else -> null
        }
    }
  }

  /**
   * Which kind to keep when two of them pair but interleave, so only one can stay enabled. Braces
   * delimit the largest blocks and brackets the smallest, so keeping a brace nested groups the most
   * text; this is the single place that ordering is decided.
   */
  private val DELIMITER_KINDS_BY_DECREASING_PREFERENCE: ImmutableList<DelimiterKind> =
    ImmutableList.of(DelimiterKind.BRACE, DelimiterKind.PARENTHESIS, DelimiterKind.BRACKET).also {
      check(it.containsAll(DelimiterKind.entries)) {
        "A delimiter kind is missing a preference: ${DelimiterKind.entries - it}"
      }
    }

  /** One copy, unlike `toString().toCharArray()`, which builds a throwaway `String` on the way. */
  private fun StringBuilder.copyToCharArray(): CharArray {
    val characters = CharArray(length)
    getChars(0, length, characters, 0)
    return characters
  }

  /**
   * [Sets.immutableEnumSet] wraps an `EnumSet` only from two elements up; below that it answers the
   * empty or singleton `ImmutableSet`. Two kinds up is exactly what [isWellNested] is called with --
   * [testKindsNestTogether] settles the smaller sets without looking at a delimiter -- so the
   * membership test it runs per delimiter is an `EnumSet` bit test. Every set of kinds in this file
   * is built here, so no hash-backed set can reach that loop.
   */
  private fun setOfKinds(kinds: Iterable<DelimiterKind>): ImmutableSet<DelimiterKind> =
    Sets.immutableEnumSet(kinds)
}
