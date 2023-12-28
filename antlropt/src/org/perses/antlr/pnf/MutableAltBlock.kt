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

import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.AstTag
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.SmartAstConstructor

class MutableAltBlock : Iterable<AbstractPersesRuleElement> {

  private val alternatives = ArrayList<AbstractPersesRuleElement>()

  fun asSequence(): Sequence<AbstractPersesRuleElement> = alternatives.asSequence()

  fun asIterable(): Iterable<AbstractPersesRuleElement> = alternatives

  inline fun forEachAlternative(visitor: (AbstractPersesRuleElement) -> Unit) {
    asSequence().forEach(visitor)
  }

  fun addIfNotEquivalent(newAlt: AbstractPersesRuleElement): Boolean {
    if (newAlt.tag == AstTag.ALTERNATIVE_BLOCK) {
      return (newAlt as PersesAlternativeBlockAst)
        .alternatives
        .map { alt -> addIfNotEquivalent(alt) }
        .any { it }
    }
    require(newAlt.tag != AstTag.ALTERNATIVE_BLOCK) { newAlt }
    if (containsEquivalent(newAlt)) {
      return false
    }
    return alternatives.add(newAlt)
  }

  fun containsEquivalent(alt: AbstractPersesRuleElement): Boolean {
    return alternatives.any { alt.isEquivalent(it) }
  }

  fun addAllIfInequivalent(newAlt: Iterable<AbstractPersesRuleElement>) {
    newAlt.forEach {
      addIfNotEquivalent(it)
    }
  }

  fun decomposeAltBlockAndAddIfInequivalent(value: AbstractPersesRuleElement) {
    if (value is PersesAlternativeBlockAst) {
      value.foreachChildRuleElement {
        decomposeAltBlockAndAddIfInequivalent(it)
      }
    } else {
      addIfNotEquivalent(value)
    }
  }

  fun copy(): MutableAltBlock = MutableAltBlock().let { copy ->
    copy.alternatives.addAll(alternatives)
    copy
  }

  operator fun get(index: Int): AbstractPersesRuleElement = alternatives[index]

  override fun iterator(): Iterator<AbstractPersesRuleElement> {
    return alternatives.iterator()
  }

  fun removeAlt(alt: AbstractPersesRuleElement): Boolean {
    return alternatives.remove(alt)
  }

  fun removeAltIf(criteria: (AbstractPersesRuleElement) -> Boolean): Boolean {
    return alternatives.removeIf(criteria)
  }

  fun clear() {
    alternatives.clear()
  }

  fun asRuleBody(): AbstractPersesRuleElement {
    return SmartAstConstructor.createForAlternatives(alternatives)
  }

  fun replace(existingAlt: AbstractPersesRuleElement, newAlt: AbstractPersesRuleElement) {
    require(existingAlt !== newAlt)
    require(!existingAlt.isEquivalent(newAlt)) {
      "existing=$existingAlt, new=$newAlt"
    }
    val first = alternatives
      .withIndex()
      .first { it.value === existingAlt } // this can throw.
    alternatives[first.index] = newAlt
    alternatives.withIndex()
      .asSequence()
      .filter { it.value.isEquivalent(newAlt) }
      .toList().let {
        check(it.size == 1) { it }
      }
  }

  val isEmpty: Boolean
    get() = alternatives.isEmpty()

  val isNotEmpty: Boolean
    get() = !isEmpty

  fun size() = alternatives.size

  fun validateNoThrow(): List<String> {
    val result = ArrayList<String>()
    asSequence().forEach {
      if (it.tag == AstTag.ALTERNATIVE_BLOCK) {
        result.add("Invalid tag type: ${it.tag}, expected=${AstTag.ALTERNATIVE_BLOCK}")
      }
    }
    val equivalentAsts = AstUtil.findEquivalenceAst(alternatives)
      .asSequence()
      .filter { ec -> ec.size() > 1 }
      .toList()
    if (equivalentAsts.isNotEmpty()) {
      result.add("Duplicate rules")
      for (i in equivalentAsts.indices) {
        result.add("# $i")
        equivalentAsts[i].getAsts().forEach { result.add(it.sourceCode) }
      }
    }
    return result
  }
}
