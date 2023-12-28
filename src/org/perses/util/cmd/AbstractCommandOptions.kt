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
package org.perses.util.cmd

import com.beust.jcommander.DefaultUsageFormatter
import com.beust.jcommander.JCommander
import com.beust.jcommander.Parameter
import com.beust.jcommander.ParameterDescription
import com.google.common.collect.ImmutableMap
import com.google.common.flogger.FluentLogger
import org.perses.util.ktSevere
import org.perses.util.toImmutableMap
import java.lang.StringBuilder
import java.util.IdentityHashMap

abstract class AbstractCommandOptions {

  inner class CmdUsagePrinter(private val jCommander: JCommander) {
    fun printUsage(): String {
      val formatter = PersesCmdUsageFormatter(jCommander)
      val stringBuilder = java.lang.StringBuilder()
      formatter.usage(stringBuilder)
      val message = stringBuilder.toString()
      println(message)
      return message
    }

    fun getFlagNameValueMap(): ImmutableMap<String, String> {
      val result = ImmutableMap.builder<String, String>()
      for (field in jCommander.fields) {
        val description = field.value
        val optionNames = description.names ?: continue
        val value = description.parameterized[description.`object`] ?: continue
        result.put(optionNames, value.toString())
      }
      return result.build().entries.asSequence().sortedBy { it.key }.toImmutableMap()
    }
  }

  private inner class PersesCmdUsageFormatter(jCommander: JCommander) :
    DefaultUsageFormatter(jCommander) {
    override fun appendAllParametersDetails(
      out: StringBuilder,
      indentCount: Int,
      indent: String,
      sortedParameters: List<ParameterDescription>,
    ) {
      val identityMap =
        IdentityHashMap<AbstractCommandLineFlagGroup, MutableList<ParameterDescription>>()
      val ownerObject = this@AbstractCommandOptions
      val ownerFlags = mutableListOf<ParameterDescription>()
      sortedParameters.forEach { flag ->
        val flagGroup = flag.`object`
        if (flagGroup === ownerObject) {
          ownerFlags.add(flag)
        } else {
          check(flagGroup is AbstractCommandLineFlagGroup) { "Flag group: ${flagGroup::class}" }
          val groupFlagList = identityMap.computeIfAbsent(flagGroup) {
            mutableListOf()
          }
          groupFlagList.add(flag)
        }
      }

      super.appendAllParametersDetails(out, indentCount, indent, ownerFlags)
      out.append("\n")

      val sortedGroupedFlags = identityMap.entries
        .sortedBy { entry ->
          allFlags.withIndex().single { it.value === entry.key }.index
        }.toList()

      var isFirst = true
      sortedGroupedFlags.forEach { (group, flags) ->
        if (flags.isEmpty()) {
          return@forEach
        }
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

  @JvmField
  @Parameter(
    names = ["--help", "-h"],
    description = "print help message",
    help = true,
    order = 0,
  )
  var help = false

  private val allFlags = mutableListOf<AbstractCommandLineFlagGroup>()

  @JvmField
  val verbosityFlags = registerFlags(VerbosityFlagGroup())

  @JvmField
  val versionFlags = registerFlags(VersionFlagGroup())

  fun validate() {
    allFlags.forEach { it.validate() }
    validateExtra()
  }

  protected open fun validateExtra() = Unit

  protected fun <T : AbstractCommandLineFlagGroup> registerFlags(flags: T): T {
    check(flags !in allFlags)
    allFlags.add(flags)
    return flags
  }

  fun parseArguments(programName: String, args: Array<String>): CmdUsagePrinter {
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

  companion object {
    val logger: FluentLogger = FluentLogger.forEnclosingClass()
  }
}
