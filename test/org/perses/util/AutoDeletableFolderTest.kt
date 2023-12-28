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
package org.perses.util

import com.google.common.truth.Truth.assertThat
import org.junit.After
import org.junit.Before
import org.junit.Test
import org.junit.runner.RunWith
import org.junit.runners.JUnit4
import java.nio.file.Files
import java.nio.file.Path
import kotlin.io.path.exists
import kotlin.io.path.isDirectory

@RunWith(JUnit4::class)
class AutoDeletableFolderTest {

  private lateinit var workingDir: Path

  @Before
  fun setup() {
    workingDir = Files.createTempDirectory("AutoDeletableFolderTest_")
  }

  @After
  fun teardown() {
    workingDir.toFile().deleteRecursively()
  }

  @Test
  fun testFolderIsDeletedAfterBeingClosed() {
    val folderFile = workingDir.resolve("test")
    val autoFolder = AutoDeletableFolder(folderFile)
    autoFolder.use { folder -> assertThat(folder.file.isDirectory()).isTrue() }

    assertThat(autoFolder.file.exists()).isFalse()
    assertThat(Files.exists(folderFile)).isFalse()
  }
}
