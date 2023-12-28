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
package org.perses.cmd

import com.beust.jcommander.Parameter
import org.perses.util.cmd.AbstractCommandLineFlagGroup
import java.nio.file.Files
import java.nio.file.Path
import java.util.jar.JarFile

class LanguageControlFlagGroup : AbstractCommandLineFlagGroup(groupName = "Language Control") {

  @JvmField
  @Parameter(
    names = ["--list-langs"],
    required = false,
    help = true,
    description = "List all the supported langauges.",
    order = 100,
  )
  var listLangs = false

  @JvmField
  @Parameter(
    names = ["--designated-parser-facade-class-name"],
    required = false,
    description = "The parser facade to be used to parse the input program",
    order = 1000,
  )
  var designatedParserFacadeClassName: String = ""

  @JvmField
  @Parameter(
    names = ["--list-parser-facades"],
    required = false,
    help = true,
    description = "List all the available parser facades.",
    order = 2000,
  )
  var listParserFacades = false

  @JvmField
  @Parameter(
    names = ["--language-ext-jars"],
    required = false,
    description = "A list of JAR files to support new languages",
    order = 3000,
  )
  var languageJarFiles: List<Path> = listOf()

  override fun validate() {
    languageJarFiles.forEach {
      check(Files.isRegularFile(it))
      JarFile(it.toFile()).use {
        /*to validate and close this file*/
      }
    }
  }
}
