/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.fuzzer.organizer

import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import java.io.BufferedReader
import java.io.InputStreamReader

class TextUI private constructor(private val commands: ImmutableMap<String, Command>) {

  fun run() {
    val stdin = BufferedReader(InputStreamReader(System.`in`))
    printCommands()
    while (true) {
      print("$ ")
      val line = stdin.readLine().trim()
      if (line.isBlank()) {
        continue
      }
      val tokens = line.split(Regex("\\s+"))
      if (tokens.isEmpty()) {
        continue
      }
      val firstToken = tokens[0]
      val normalizedCommand = computeCommand(firstToken)

      if (normalizedCommand == null) {
        println("Invalid command: $line")
        continue
      }
      if (normalizedCommand == CMD_EXIT.name) {
        break
      }
      if (normalizedCommand == CMD_HELP.name) {
        printCommands()
        continue
      }
      try {
        commands[normalizedCommand]!!.perform(ImmutableList.copyOf(tokens.subList(1, tokens.size)))
      } catch (e: Exception) {
        println("Error during executing command '$normalizedCommand'")
        e.printStackTrace()
      }
    }
  }

  private fun computeCommand(firstToken: String): String? {
    return try {
      val commandId = Integer.parseInt(firstToken)
      commands.keys.withIndex().firstOrNull { it.index == commandId }?.value
    } catch (e: Exception) {
      firstToken
    }
  }

  private fun printCommands() {
    println()
    println()
    println(">> Type one of the following commands:")
    for (cmd in commands.values.withIndex()) {
      println(">>    ${cmd.index}: ${cmd.value.usage}")
    }
  }

  companion object {
    private val CMD_EXIT = Command(
      "exit",
      ImmutableList.of(),
    ) {}

    private val CMD_HELP = Command(
      "help",
      ImmutableList.of(),
    ) {}
  }

  class Command(
    val name: String,
    val parameters: ImmutableList<String>,
    val action: (ImmutableList<String>) -> Unit,
  ) {

    val usage = StringBuilder().apply {
      append(name)
      parameters.forEach {
        append(" <$it>")
      }
    }.toString()

    fun perform(arguments: ImmutableList<String>) {
      action.invoke(arguments)
    }
  }

  class Builder {

    private val commands = ImmutableMap.builder<String, Command>()

    fun addCommand(
      commandName: String,
      action: (ImmutableList<String>) -> Unit,
    ) {
      addCommand(commandName, EMPTY_PARAMETERS, action)
    }

    fun addCommand(
      commandName: String,
      parameters: ImmutableList<String>,
      action: (ImmutableList<String>) -> Unit,
    ): Builder {
      val normalizedCommand = commandName.trim().replace(Regex("\\s+"), "")
      require(commandName == normalizedCommand) {
        "The command should not have any whitespaces. '$commandName'"
      }
      require(commandName != CMD_EXIT.name) {
        "${CMD_EXIT.name} is a reserved keyword."
      }
      require(commandName != CMD_HELP.name) {
        "${CMD_HELP.name} is a reserved keyword."
      }
      val command = Command(commandName, parameters, action)
      commands.put(command.name, command)
      return this
    }

    fun build(): TextUI {
      CMD_EXIT.let { commands.put(it.name, it) }
      CMD_HELP.let { commands.put(it.name, it) }
      return TextUI(commands.build())
    }

    companion object {
      val EMPTY_PARAMETERS = ImmutableList.of<String>()
    }
  }
}
