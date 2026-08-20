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
package org.perses.reduction.scheduler

import com.fasterxml.jackson.annotation.JsonSubTypes
import com.fasterxml.jackson.annotation.JsonTypeInfo
import com.fasterxml.jackson.core.type.TypeReference
import com.fasterxml.jackson.dataformat.yaml.YAMLGenerator
import org.perses.util.Serialization

class ExecutionPlanYamlDefinition {
  @JsonTypeInfo(
    use = JsonTypeInfo.Id.NAME,
    include = JsonTypeInfo.As.PROPERTY,
    property = "type",
  )
  @JsonSubTypes(
    JsonSubTypes.Type(value = FixpointLoopStepDef::class, name = "fixpoint"),
    JsonSubTypes.Type(value = SequenceDef::class, name = "sequence"),
    JsonSubTypes.Type(value = AtomicReducerStepDef::class, name = "atomic"),
    JsonSubTypes.Type(value = IfProgressedThenStepDef::class, name = "if"),
  )
  sealed class AbstractExecutionPlanStepDef {
    fun toYamlString(): String =
      Serialization.toYamlString(
        value = this,
        yamlFactoryCustomizer = { factory ->
          factory
            .enable(YAMLGenerator.Feature.USE_NATIVE_TYPE_ID)
            .enable(YAMLGenerator.Feature.MINIMIZE_QUOTES)
        },
      )

    fun prettyPrint(): String {
      val stringBuilder = StringBuilder()
      prettyPrint(stringBuilder, indent = 0)
      return stringBuilder.toString()
    }

    abstract fun prettyPrint(
      builder: StringBuilder,
      indent: Int,
    )

    companion object {
      fun fromYamlString(yaml: String): AbstractExecutionPlanStepDef =
        Serialization.fromYamlString(
          yaml,
          typeReference = object : TypeReference<AbstractExecutionPlanStepDef>() {},
        )

      const val INDENT = 4
    }
  }

  class FixpointLoopStepDef(
    val body: AbstractExecutionPlanStepDef,
    val condition: String,
  ) : AbstractExecutionPlanStepDef() {
    override fun prettyPrint(
      builder: StringBuilder,
      indent: Int,
    ) {
      builder.appendLine("fixpoint ($condition) {")
      builder.append(" ".repeat(indent + INDENT))
      body.prettyPrint(builder, indent + INDENT)
      builder.appendLine()
      builder.append(" ".repeat(indent)).append('}')
    }
  }

  class SequenceDef(
    val reducers: List<AbstractExecutionPlanStepDef>,
  ) : AbstractExecutionPlanStepDef() {
    override fun prettyPrint(
      builder: StringBuilder,
      indent: Int,
    ) {
      if (reducers.isEmpty()) {
        return
      }
      reducers.first().prettyPrint(builder, indent)
      reducers.asSequence().drop(1).forEach { reducer ->
        builder.appendLine()
        builder.append(" ".repeat(indent))
        reducer.prettyPrint(builder, indent)
      }
    }
  }

  class AtomicReducerStepDef(
    val reducer: String,
  ) : AbstractExecutionPlanStepDef() {
    override fun prettyPrint(
      builder: StringBuilder,
      indent: Int,
    ) {
      builder.append(reducer)
    }
  }

  class IfProgressedThenStepDef(
    val condition: AbstractExecutionPlanStepDef,
    val then: AbstractExecutionPlanStepDef,
  ) : AbstractExecutionPlanStepDef() {
    override fun prettyPrint(
      builder: StringBuilder,
      indent: Int,
    ) {
      builder.append("if (")
      condition.prettyPrint(builder, indent)
      builder.append(") {").appendLine()
      builder.append(" ".repeat(indent + INDENT))
      then.prettyPrint(builder, indent + INDENT)
      builder.appendLine().append(" ".repeat(indent)).append("}")
    }
  }
}
