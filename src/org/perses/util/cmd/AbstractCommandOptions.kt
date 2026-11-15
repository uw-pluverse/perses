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

import com.beust.jcommander.DefaultUsageFormatter
import com.beust.jcommander.JCommander
import com.beust.jcommander.ParameterDescription
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import com.google.common.flogger.FluentLogger
import org.perses.util.ktSevere
import org.perses.util.toImmutableMap
import java.lang.StringBuilder
import java.util.IdentityHashMap

abstract class AbstractCommandOptions {
  protected val allFlags = mutableListOf<AbstractCommandLineFlagGroup>()

  @JvmField
  val helpFlags = registerFlags(HelpFlagGroup())

  @JvmField
  val verbosityFlags = registerFlags(VerbosityFlagGroup())

  @JvmField
  val versionFlags = registerFlags(VersionFlagGroup())

  fun validate() {
    allFlags.forEach { it.validate() }
    validateExtra()
  }

  fun copyParameterValuesFrom(other: AbstractCommandOptions) {
    allFlags.forEach { toGroup ->
      val fromGroup =
        other.allFlags.singleOrNull {
          it.groupName == toGroup.groupName
        } ?: return@forEach
      toGroup.copyParameterValuesFrom(fromGroup)
    }
  }

  protected open fun validateExtra() = Unit

  protected fun <T : AbstractCommandLineFlagGroup> registerFlags(flags: T): T {
    check(flags !in allFlags) { "The flag is already registered: $flags" }
    check(
      allFlags.none { existing ->
        existing.groupName == flags.groupName
      },
    ) {
      "Duplicate group name ${flags.groupName}"
    }
    allFlags.add(flags)
    return flags
  }

  fun parseArguments(
    programName: String,
    args: Array<String>,
  ): CmdUsagePrinter {
    val builder = JCommander.newBuilder().programName(programName)
    builder.addObject(this)
    builder.addObject(allFlags)
    val commander = builder.build()
    try {
      commander.parse(*args)
    } catch (e: Throwable) {
      logger.ktSevere {
        "Fail to parse the flags ${args.toList()}"
      }
      throw e
    }
    return CmdUsagePrinter(commander)
  }

  inner class CmdUsagePrinter(
    private val jCommander: JCommander,
  ) {
    fun printUsage(): String {
      val formatter = PersesCmdUsageFormatter(jCommander)
      val stringBuilder = StringBuilder()
      formatter.usage(stringBuilder)
      val message = stringBuilder.toString()
      println(message)
      return message
    }

    fun renderMarkdownUsage(): String {
      val stringBuilder = StringBuilder()
      MarkdownUsageFormatter(jCommander).usage(stringBuilder)
      return stringBuilder.toString()
    }

    fun getLongestFlagNameToValueMap(): ImmutableMap<String, String> {
      val result = ImmutableMap.builder<String, String>()
      for (field in jCommander.fields) {
        val description = field.value
        val optionNames = description.longestName ?: continue
        val value = description.parameterized[description.`object`] ?: continue
        result.put(optionNames, value.toString())
      }
      return result
        .build()
        .entries
        .asSequence()
        .sortedBy { it.key }
        .toImmutableMap()
    }
  }

  private inner class PersesCmdUsageFormatter(
    jCommander: JCommander,
  ) : DefaultUsageFormatter(jCommander) {
    override fun appendAllParametersDetails(
      out: StringBuilder,
      indentCount: Int,
      indent: String,
      sortedParameters: List<ParameterDescription>,
    ) {
      val grouped = groupParameters(sortedParameters)
      super.appendAllParametersDetails(out, indentCount, indent, grouped.ungroupedFlags)
      out.append("\n")

      var isFirst = true
      grouped.groups.forEach { (group, flags) ->
        if (isFirst) {
          isFirst = false
        } else {
          out.append("\n")
        }
        out.append("[${group.groupName}]")
        super.appendAllParametersDetails(out, indentCount, indent, flags)
      }
    }
  }

  private class GroupedParameters(
    val ungroupedFlags: List<ParameterDescription>,
    val groups: List<Pair<AbstractCommandLineFlagGroup, List<ParameterDescription>>>,
  )

  private fun groupParameters(sortedParameters: List<ParameterDescription>): GroupedParameters {
    val identityMap =
      IdentityHashMap<AbstractCommandLineFlagGroup, MutableList<ParameterDescription>>()
    val ownerObject = this
    val ownerFlags = mutableListOf<ParameterDescription>()
    sortedParameters.forEach { flag ->
      val flagGroup = flag.`object`
      if (flagGroup === ownerObject) {
        ownerFlags.add(flag)
      } else {
        check(flagGroup is AbstractCommandLineFlagGroup) { "Flag group: ${flagGroup::class}" }
        if (flagGroup.hidden) {
          return@forEach
        }
        identityMap.computeIfAbsent(flagGroup) { mutableListOf() }.add(flag)
      }
    }

    val unimportantGroups = ImmutableList.of(verbosityFlags, versionFlags, helpFlags)
    val sortedGroups =
      identityMap.entries
        .partition { it.key in unimportantGroups }
        .let { (unimportant, important) ->
          important.sortedBy { allFlags.indexOf(it.key) } +
            unimportant.sortedBy { unimportantGroups.indexOf(it.key) }
        }.map { it.key to it.value }
    return GroupedParameters(ownerFlags, sortedGroups)
  }

  /**
   * Renders the same flags, groups and order as [PersesCmdUsageFormatter], as a
   * markdown document with one table per flag group.
   */
  private inner class MarkdownUsageFormatter(
    jCommander: JCommander,
  ) : DefaultUsageFormatter(jCommander) {
    override fun appendMainLine(
      out: StringBuilder,
      hasOptions: Boolean,
      hasCommands: Boolean,
      indentCount: Int,
      indent: String,
    ) {
      val mainLine = StringBuilder()
      super.appendMainLine(mainLine, hasOptions, hasCommands, indentCount, indent)
      out.append("# Command Line Arguments\n\n")
      out.append("```\n").append(mainLine.toString().trim()).append("\n```\n")
    }

    override fun appendAllParametersDetails(
      out: StringBuilder,
      indentCount: Int,
      indent: String,
      sortedParameters: List<ParameterDescription>,
    ) {
      val grouped = groupParameters(sortedParameters)
      if (grouped.ungroupedFlags.isNotEmpty()) {
        appendTable(out, "Options", grouped.ungroupedFlags)
      }
      grouped.groups.forEach { (group, flags) -> appendTable(out, group.groupName, flags) }
    }

    private fun appendTable(
      out: StringBuilder,
      title: String,
      flags: List<ParameterDescription>,
    ) {
      out.append("\n## ").append(title).append("\n\n")
      out.append("| Flag | Description | Default |\n")
      out.append("| --- | --- | --- |\n")
      flags.forEach { flag ->
        val cells = listOf(renderNames(flag), renderDescription(flag), renderDefault(flag))
        out.append(cells.joinToString(separator = " | ", prefix = "| ", postfix = " |\n"))
      }
    }

    private fun renderNames(flag: ParameterDescription) =
      flag.parameter.names().joinToString(separator = ", ") { inlineCode(it) }

    private fun renderDescription(flag: ParameterDescription): String {
      val sentences = mutableListOf<String>()
      if (flag.parameter.required()) {
        sentences.add("**Required.**")
      }
      val description = flag.description.trim().replace(WHITESPACE, " ")
      if (description.isNotEmpty()) {
        sentences.add(escapeText(description))
      }
      val lines = mutableListOf(sentences.joinToString(separator = " "))
      val type = flag.parameterized.type
      if (type.isEnum) {
        val values = type.enumConstants.joinToString(separator = ", ") { inlineCode(it.toString()) }
        lines.add("Possible values: $values")
      }
      return lines.filter { it.isNotEmpty() }.joinToString(separator = "<br>")
    }

    private fun renderDefault(flag: ParameterDescription): String {
      val default = flag.default
      if (default == null || flag.isHelp) {
        return ""
      }
      val text = default.toString()
      return when {
        flag.parameter.password() -> "********"
        text.isEmpty() -> "*empty string*"
        else -> inlineCode(text)
      }
    }

    private fun inlineCode(text: String) = "`" + text.replace("|", "\\|") + "`"

    // Without the escapes, `|` would end the table cell, a `<...>` placeholder
    // would be swallowed as an HTML tag, and `*` or `_` would start emphasis.
    private fun escapeText(text: String) =
      text.replace(MARKDOWN_SPECIAL_CHARACTER) {
        "\\" +
          it.value
      }
  }

  companion object {
    val logger: FluentLogger = FluentLogger.forEnclosingClass()
    private val WHITESPACE = Regex("\\s+")
    private val MARKDOWN_SPECIAL_CHARACTER = Regex("[|<>*_`\\[\\]\\\\]")
  }
}
