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
package org.perses.spartree

import com.google.common.collect.ImmutableList
import org.perses.antlr.RuleHierarchyEntry
import org.perses.util.toImmutableList

/**
 * The top Antlr rule type for the child. For example
 *
 * <p>
 *
 * <p>expr ::= '(' expr ')' | constant
 *
 * <p>
 *
 * <p>constant ::= ID | NUMBER
 *
 * <p>
 *
 * <p>Say we have the expression "(1)", the leaf node INTEGER's Antlr rule type is 'constant',
 * its antlrRuleForTheChild should be 'expr',
 */
abstract class AbstractNodePayload {

  abstract val expectedAntlrRuleType: RuleHierarchyEntry?
  abstract val actualAntlrRuleType: RuleHierarchyEntry?

  abstract fun label(): String

  abstract val asSinglePayloadList: ImmutableList<SinglePayload>

  fun createByAppending(suffix: AbstractNodePayload): CollapsingPayload {
    val collapsedAncestorsFromTop =
      asSinglePayloadList
        .asSequence()
        .plus(suffix.asSinglePayloadList.asSequence())
        .toImmutableList()
    return CollapsingPayload(collapsedAncestorsFromTop)
  }

  data class SinglePayload(
    override val expectedAntlrRuleType: RuleHierarchyEntry?,
  ) : AbstractNodePayload() {

    override val actualAntlrRuleType: RuleHierarchyEntry?
      get() = expectedAntlrRuleType

    override val asSinglePayloadList: ImmutableList<SinglePayload> = ImmutableList.of(this)

    override fun label(): String {
      return expectedAntlrRuleType?.ruleName ?: "Token"
    }
  }

  data class CollapsingPayload(
    val collapsedAncestorsFromTop: ImmutableList<SinglePayload>,
  ) : AbstractNodePayload() {

    init {
      require(collapsedAncestorsFromTop.size > 1)
    }

    override val expectedAntlrRuleType: RuleHierarchyEntry?
      get() = collapsedAncestorsFromTop.first().expectedAntlrRuleType

    override val actualAntlrRuleType: RuleHierarchyEntry?
      get() = collapsedAncestorsFromTop.last().expectedAntlrRuleType

    override val asSinglePayloadList = collapsedAncestorsFromTop

    override fun label(): String {
      val builder = StringBuilder()
      builder.append('[')
      collapsedAncestorsFromTop
        .asSequence()
        .map { it.label() }
        .joinTo(builder, ",")
      builder.append(']')
      return builder.toString()
    }
  }

  companion object {

    fun create(payloads: ImmutableList<SinglePayload>): AbstractNodePayload {
      return when (payloads.size) {
        0 -> error("cannot be empty")
        1 -> payloads.single()
        else -> CollapsingPayload(payloads)
      }
    }

    fun concatenatePaylods(
      ancestor: AbstractNodePayload,
      descendant: AbstractNodePayload,
    ): AbstractNodePayload {
      // TODO(cnsun): this needs more thoughts.
      val ancestorTopToBottom = ancestor.asSinglePayloadList
      val descendantTopToBottom = descendant.asSinglePayloadList
      for (desc in descendantTopToBottom.withIndex()) {
        val match = ancestorTopToBottom.withIndex().findLast { it.value == desc.value } ?: continue
        return AbstractNodePayload.create(
          ImmutableList.builder<AbstractNodePayload.SinglePayload>()
            .addAll(ancestorTopToBottom.subList(0, match.index + 1))
            .addAll(descendantTopToBottom.subList(desc.index + 1, descendantTopToBottom.size))
            .build(),
        )
      }
      return ancestor.createByAppending(descendantTopToBottom.last())
    }
  }
}
