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
import com.google.common.collect.ImmutableMap
import com.google.common.collect.ImmutableSet
import org.perses.util.toImmutableList

class RuleEpsilonComputer private constructor(grammar: ImmutableList<AbstractPersesRuleDefAst>) {

  private val epsilonable = LinkedHashSet<AbstractPersesRuleElement>()

  private val nameToRuleMap = ImmutableMap
    .builder<String, AbstractPersesRuleDefAst>()
    .apply { grammar.forEach { put(it.ruleNameHandle.ruleName, it) } }
    .build()

  fun containsEpsilon(rule: AbstractPersesRuleDefAst): Boolean {
    return epsilonable.contains(rule.body)
  }

  val epsilonableElements: ImmutableSet<AbstractPersesRuleElement>
    get() = ImmutableSet.copyOf(epsilonable)

  fun compute() {
    val visitor = EpsilonComputingVisitor()
    var prevSize: Int
    do {
      prevSize = epsilonable.size
      val rules = nameToRuleMap.values
        .asSequence()
        .filter { def: AbstractPersesRuleDefAst -> !epsilonable.contains(def.body) }
        .toImmutableList()
      for (rule in rules) {
        val body = rule.body
        visitor.postorder(body)
      }
    } while (prevSize < epsilonable.size)
  }

  private inner class EpsilonComputingVisitor : DefaultAstVisitor() {
    override fun visit(ast: PersesSequenceAst) {
      val count = ast.childCount
      for (i in 0 until count) {
        if (!epsilonable.contains(ast.getChild(i))) {
          return
        }
      }
      epsilonable.add(ast)
    }

    override fun visit(ast: PersesPlusAst) {
      if (epsilonable.contains(ast.body)) {
        epsilonable.add(ast)
      }
    }

    override fun visit(ast: PersesStarAst) {
      epsilonable.add(ast)
    }

    override fun visit(ast: PersesOptionalAst) {
      epsilonable.add(ast)
    }

    override fun visit(ast: PersesLexerCommandAst) {
      if (epsilonable.contains(ast.body)) {
        epsilonable.add(ast)
      }
    }

    override fun visit(ast: PersesEpsilonAst) {
      epsilonable.add(ast)
    }

    override fun visit(ast: PersesAlternativeBlockAst) {
      val count = ast.childCount
      for (i in 0 until count) {
        if (epsilonable.contains(ast.getChild(i))) {
          epsilonable.add(ast)
          break
        }
      }
    }

    override fun visit(ast: PersesRuleReferenceAst) {
      val def = nameToRuleMap[ast.ruleNameHandle.ruleName]
      if (epsilonable.contains(def!!.body)) {
        epsilonable.add(ast)
      }
    }
  }

  companion object {
    @JvmStatic
    fun computeEpsilonableRules(
      grammar: ImmutableList<AbstractPersesRuleDefAst>,
    ): EpsilonInfo {
      val computer = RuleEpsilonComputer(grammar)
      computer.compute()
      val builder = ImmutableSet.builder<AbstractPersesRuleDefAst>()
      for (rule in grammar) {
        if (computer.containsEpsilon(rule)) {
          builder.add(rule)
        }
      }
      return EpsilonInfo(builder.build(), computer.epsilonableElements)
    }
  }
}
