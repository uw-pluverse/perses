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
package org.perses.util.cmd

import com.beust.jcommander.JCommander
import com.beust.jcommander.ParameterDescription
import org.perses.util.IoUtil
import java.nio.charset.StandardCharsets
import java.nio.file.Path

/**
 * Prints the bash completion script for `perses`: the hand-written template [TEMPLATE_RESOURCE],
 * followed by the flag list it reads. The script is generated rather than computed at TAB time
 * because starting the JVM on every TAB takes 0.2 to 1.4 seconds.
 *
 * The flag list, modelled on `bazel help completion`, is a shell variable whose value holds one
 * line per flag name, where the suffix after the name tells the template how to complete the
 * flag's value.
 *
 * ```
 * --fixpoint={true,false}      a boolean that takes an explicit value (arity 1)
 * --help                       a boolean switch: no value
 * --code-format={A,B,C}        an enum: one of the listed constants
 * --test-script=path           a file or directory
 * --threads=                   a free-form value; the template offers nothing
 * ```
 *
 * The lines are sorted so the output is stable across runs and usable as a golden file.
 */
class BashCompletionScriptPrinter(
  private val jCommander: JCommander,
) {
  fun print(): String = readTemplate() + printFlagList()

  private fun readTemplate(): String =
    IoUtil
      .openResourceAsStream(TEMPLATE_RESOURCE, BashCompletionScriptPrinter::class.java)
      .use { String(it.readAllBytes(), StandardCharsets.UTF_8) }

  fun printFlagList(): String {
    val builder = StringBuilder()
    builder.append(FLAG_LIST_VARIABLE).append("=\"\n")
    jCommander.parameters
      .asSequence()
      .filterNot { isHidden(it) }
      .flatMap { description ->
        val suffix = computeValueSuffix(description)
        description.parameter
          .names()
          .asSequence()
          .map { name -> name + suffix }
      }.sorted()
      .forEach { builder.append(it).append('\n') }
    builder.append("\"\n")
    return builder.toString()
  }

  private fun isHidden(description: ParameterDescription): Boolean {
    if (description.parameter.hidden()) {
      return true
    }
    val owner = description.`object`
    return owner is AbstractCommandLineFlagGroup && owner.hidden
  }

  private fun computeValueSuffix(description: ParameterDescription): String {
    val parameterized = description.parameterized
    val valueType = parameterized.findFieldGenericType() as? Class<*> ?: parameterized.type
    return when {
      isBoolean(valueType) ->
        // JCommander reads a boolean with the default arity as a bare switch; only an explicit
        // arity makes it consume `true`/`false` as the next argument.
        if (description.parameter.arity() >= 1) "={true,false}" else ""
      valueType.isEnum ->
        valueType.enumConstants.joinToString(
          separator = ",",
          prefix = "={",
          postfix = "}",
        ) { (it as Enum<*>).name }
      Path::class.java.isAssignableFrom(valueType) ||
        java.io.File::class.java.isAssignableFrom(valueType) -> "=path"
      else -> "="
    }
  }

  private fun isBoolean(type: Class<*>) =
    type == Boolean::class.javaPrimitiveType || type == Boolean::class.javaObjectType

  companion object {
    const val FLAG_LIST_VARIABLE = "PERSES_COMPLETION_FLAGS"
    const val TEMPLATE_RESOURCE = "/perses-complete-template.bash"
  }
}
