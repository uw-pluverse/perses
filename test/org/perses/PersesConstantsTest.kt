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

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import org.perses.PersesConstants.Companion.HOME_DIR_PROPERTY_NAME
import org.perses.util.Util
import java.nio.file.Files

@RunWith(JUnit4::class)
class PersesConstantsTest {

  val workingDir = Files.createTempDirectory("PersesConstantsTest_")
  val constants = PersesConstants.createCustomizedConstants(
    userHomeFolder = workingDir,
  )

  @After
  fun teardown() {
    workingDir.toFile().deleteRecursively()
  }

  @Test
  fun testCreateDefaultPersesConstants_AtHomeDir() {
    val homeDir = PersesConstants.createDefaultConstants()
    assertThat(homeDir.userHomeFolder.startsWith(Util.getUserHomeDirectory())).isTrue()
  }

  // This test is tricky, as it modifies a global variable. Be careful of using
  // the system property.
  @Test
  fun testCreateDefaultPersesConstants_AtSystemProperty() {
    try {
      System.setProperty(HOME_DIR_PROPERTY_NAME, workingDir.toString())
      val constants = PersesConstants.createDefaultConstants()
      assertThat(constants.userHomeFolder.startsWith(workingDir)).isTrue()
    } finally {
      System.clearProperty(HOME_DIR_PROPERTY_NAME)
    }
  }

  @Test
  fun testPersesRootFolder() {
    val persesRoot = constants.getPersesRootFolderOrCreate()
    assertThat(persesRoot.file.parent.toAbsolutePath()).isEqualTo(workingDir.toAbsolutePath())
    assertThat(Files.isDirectory(persesRoot.file)).isTrue()
  }

  @Test
  fun testAdhodLanguageRoot() {
    val root = constants.getPersesRootFolderOrCreate().getPersesAdhocRootOrCreate()
    assertThat(root.file.parent.toAbsolutePath()).isEqualTo(
      constants.getPersesRootFolderOrCreate().file.toAbsolutePath(),
    )
    assertThat(Files.isDirectory(root.file)).isTrue()
  }
}
