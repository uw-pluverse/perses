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
package org.perses

import org.perses.util.Util
import java.nio.file.Files
import java.nio.file.Path
import java.nio.file.Paths

class PersesConstants private constructor(
  val userHomeFolder: Path,
) {

  init {
    check(Files.isDirectory(userHomeFolder))
  }

  fun getPersesRootFolderOrCreate() = PersesRoot(
    Util.ensureDirExists(userHomeFolder.resolve(".perses")),
  )

  data class PersesRoot(val file: Path) {
    init {
      require(Files.isDirectory(file)) {
        "The folder $file is not a directory"
      }
    }

    fun getPersesAdhocRootOrCreate() = AdhocGrammarRoot(
      Util.ensureDirExists(
        file.resolve("installed_adhoc_languages"),
      ),
    )
  }

  data class AdhocGrammarRoot(val file: Path) {
    init {
      require(Files.isDirectory(file)) {
        "The folder $file is not a directory."
      }
    }
  }

  companion object {
    const val HOME_DIR_PROPERTY_NAME = "org.perses.home"

    @JvmStatic
    fun createDefaultConstants(): PersesConstants {
      val customizedHomeDir = System.getProperty(HOME_DIR_PROPERTY_NAME, "")
      return if (customizedHomeDir.isNotBlank()) {
        PersesConstants(Paths.get(customizedHomeDir))
      } else {
        PersesConstants(Util.getUserHomeDirectory())
      }
    }

    @JvmStatic
    fun createCustomizedConstants(userHomeFolder: Path) = PersesConstants(userHomeFolder)
  }
}
