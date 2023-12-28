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

import com.google.common.base.MoreObjects
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableListMultimap
import com.google.common.collect.ImmutableMap
import com.google.common.collect.Multimap
import org.perses.antlr.ast.AbstractPersesRuleDefAst
import org.perses.antlr.ast.AbstractPersesRuleElement
import org.perses.antlr.ast.PersesAlternativeBlockAst
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.ast.PersesParserRuleAst
import org.perses.antlr.ast.PersesParserRuleAst.ParserRuleAttributes
import org.perses.antlr.ast.RuleNameRegistry.RuleNameHandle
import org.perses.antlr.ast.TransformDecision
import org.perses.util.toImmutableList
import org.perses.util.toImmutableMap
import java.util.AbstractMap
import java.util.concurrent.atomic.AtomicBoolean

class MutableGrammar(
  private val parserRuleAttributesMap: ImmutableMap<RuleNameHandle, ParserRuleAttributes> =
    ImmutableMap.of(),
) {

  // [LinkedHashMap] is for deterministic iteration order.
  private val map = LinkedHashMap<RuleNameHandle, MutableAltBlock>()

  fun ruleNameAltPairSequence(): Sequence<Map.Entry<RuleNameHandle, AbstractPersesRuleElement>> {
    return map.entries
      .asSequence()
      .flatMap { entry ->
        entry.value.asSequence().map { AbstractMap.SimpleEntry(entry.key, it) }
      }
  }

  fun alternativeSequence(): Sequence<AbstractPersesRuleElement> {
    return map.values
      .asSequence()
      .flatMap { it.asSequence() }
  }

  fun nonEmptyAltBlockSequence(): Sequence<Map.Entry<RuleNameHandle, MutableAltBlock>> {
    return map.entries
      .asSequence()
      .filter { it.value.isNotEmpty }
  }

  inline fun forEachAlt(action: (RuleNameHandle, AbstractPersesRuleElement) -> Unit) {
    ruleNameAltPairSequence().forEach { action(it.key, it.value) }
  }

  val isEmpty: Boolean
    get() = !ruleNameAltPairSequence().any()

  val isNotEmpty: Boolean
    get() = !isEmpty

  fun containsRule(name: RuleNameHandle): Boolean {
    val result = map[name] ?: return false
    return !result.isEmpty
  }

  fun getAltBlock(key: RuleNameHandle): MutableAltBlock {
    return map.computeIfAbsent(key) {
      MutableAltBlock()
    }
  }

  fun ruleNameSequence(): Sequence<RuleNameHandle> = map.entries
    .asSequence()
    .filter { it.value.isNotEmpty }
    .map { it.key }

  fun removeRule(key: RuleNameHandle): MutableAltBlock? {
    val oldValue = map.remove(key) ?: return null
    return if (oldValue.isEmpty) {
      null
    } else {
      oldValue
    }
  }

  fun toImmutableMultiMap(): ImmutableListMultimap<RuleNameHandle, AbstractPersesRuleElement> {
    return ImmutableListMultimap.copyOf(ruleNameAltPairSequence().asIterable())
  }

  fun toParserRuleAstList(): ImmutableList<PersesParserRuleAst> {
    return nonEmptyAltBlockSequence()
      .map { (name, altBlock) ->
        val parserRuleAttributes: ParserRuleAttributes = parserRuleAttributesMap.getOrDefault(
          name,
          ParserRuleAttributes.EMPTY,
        )!!
        PersesParserRuleAst(name, altBlock.asRuleBody(), parserRuleAttributes)
      }.toImmutableList()
  }

  fun copyFrom(defMap: Multimap<RuleNameHandle, AbstractPersesRuleElement>): MutableGrammar {
    defMap.forEach { key, value ->
      getAltBlock(key).addIfNotEquivalent(value)
    }
    return this
  }

  override fun toString(): String {
    return MoreObjects
      .toStringHelper(this).add("keys", map.keys).add("values", map.values).toString()
  }

  fun validate() {
    val result = validateNoThrow()
    if (result.isNotEmpty()) {
      throw AssertionError(result.joinToString("\n"))
    }
  }

  fun validateNoThrow(): List<String> {
    val result = ArrayList<String>()
    nonEmptyAltBlockSequence().forEach { (key, block) ->
      block.validateNoThrow().let {
        if (it.isNotEmpty()) {
          result.add("Error in the definition of $key")
          result.addAll(it)
          result.add("")
        }
      }
    }
    return result
  }

  // TODO: need test
  fun transform(
    transformer: (RuleNameHandle, AbstractPersesRuleElement) -> TransformDecision,
  ): MutableGrammar {
    val copy = MutableGrammar()
    ruleNameAltPairSequence().forEach { (ruleName, oldDef) ->
      when (val decision = transformer.invoke(ruleName, oldDef)) {
        is TransformDecision.Keep -> copy.getAltBlock(ruleName).addIfNotEquivalent(oldDef)
        is TransformDecision.Delete -> Unit // do nothing.
        is TransformDecision.Replace -> copy.getAltBlock(ruleName)
          .addIfNotEquivalent(decision.newValue)
        else -> error("Unhandled case $decision")
      }
    }
    return copy
  }

  fun duplicateByReplacing(
    ruleName: RuleNameHandle,
    oldDef: AbstractPersesRuleElement,
    newDef: AbstractPersesRuleElement,
  ): MutableGrammar {
    val found = AtomicBoolean(false)
    val newGrammar = transform { name, existingDef ->
      if (name == ruleName && existingDef === oldDef) {
        found.set(true)
        return@transform TransformDecision.Replace(oldValue = oldDef, newValue = newDef)
      } else {
        return@transform TransformDecision.Keep(oldDef)
      }
    }
    check(found.get())
    return newGrammar
  }

  companion object {
    @JvmStatic
    fun createParserRulesFrom(grammar: PersesGrammar): MutableGrammar {
      val parserRuleAttributesMap = grammar.parserRules
        .asSequence()
        .map {
          it.ruleNameHandle to it.attributes
        }.toImmutableMap()

      return createRulesFrom(grammar.parserRules, parserRuleAttributesMap)
    }

    @JvmStatic
    fun createRulesFrom(
      rules: Iterable<AbstractPersesRuleDefAst>,
      parserRuleAttributesMap: ImmutableMap<RuleNameHandle, ParserRuleAttributes> =
        ImmutableMap.of(),
    ): MutableGrammar {
      val result = MutableGrammar(parserRuleAttributesMap)
      rules.forEach { rule ->
        val name = rule.ruleNameHandle
        val altBlock = result.getAltBlock(name)

        val body = rule.body
        if (body is PersesAlternativeBlockAst) {
          body.foreachChildRuleElement { alt ->
            altBlock.addIfNotEquivalent(alt)
          }
        } else {
          altBlock.addIfNotEquivalent(body)
        }
      }
      return result
    }
  }
}
