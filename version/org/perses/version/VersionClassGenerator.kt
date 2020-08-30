/*
 * Copyright (C) 2018-2020 University of Waterloo.
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
package org.perses.version

import com.google.common.base.Preconditions
import com.google.common.collect.ImmutableList
import com.google.common.collect.ImmutableMap
import com.google.common.io.Files
import java.io.BufferedWriter
import java.io.File
import java.nio.charset.StandardCharsets
import java.time.ZonedDateTime
import java.time.format.DateTimeFormatter

object VersionClassGenerator {

  private const val MAJOR_VERSION = "1"
  private const val MINOR_VERSION = "1"

  @JvmStatic
  fun generate(args: Array<String>) {
    Preconditions.checkArgument(args.size == 2)
    val lines = Files.asCharSource(File(args[0]), StandardCharsets.UTF_8).readLines()
    val map = parse(lines)
    val outputFile = File(args[1])
    writeVersionClass(map, outputFile)
  }

  private fun writeVersionClass(map: ImmutableMap<String, String>, outputFile: File) {
    val branch = map["PERSES_GIT_BRANCH"]
    val hash = map["PERSES_GIT_COMMIT_HASH"]
    val status = map["PERSES_GIT_STATUS"]
    val timestamp = ZonedDateTime.now().format(DateTimeFormatter.ISO_ZONED_DATE_TIME)
    Files.newWriter(outputFile, StandardCharsets.UTF_8).use { writer ->
      line(writer, "package org.perses.version")
      line(writer, "object Version {")
      line(writer, "  val BRANCH=\"%s\"", branch!!)
      line(writer, "  val COMMIT_HASH=\"%s\"", hash!!)
      line(writer, "  val STATUS=\"%s\"", status!!)
      line(writer, "  val MAJOR_VERSION=\"%s\"", MAJOR_VERSION)
      line(writer, "  val MINOR_VERSION=\"%s\"", MINOR_VERSION)
      line(writer, "  val BUILD_TIME=\"%s\"", timestamp)
      line(writer, "}")
    }
  }

  private fun line(writer: BufferedWriter, template: String, vararg args: String) {
    writer.append(String.format(template, *args)).append("\n")
  }

  private fun parse(lines: ImmutableList<String>): ImmutableMap<String, String> {
    val builder = ImmutableMap.builder<String, String>()
    for (line in lines) {
      val segments = line.split("\\s|=".toRegex()).toTypedArray()
      Preconditions.checkState(segments.size == 2)
      builder.put(segments[0].trim { it <= ' ' }, segments[1].trim { it <= ' ' })
    }
    return builder.build()
  }
}
