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
package org.perses.util;

import com.google.common.base.Preconditions;
import com.google.common.io.MoreFiles;
import com.google.common.io.RecursiveDeleteOption;

import java.io.Closeable;
import java.io.File;
import java.io.IOException;

public class AutoDeletableFolder implements Closeable {

  private final File folder;

  public AutoDeletableFolder(File folder) {
    this.folder = folder;
    if (!folder.exists()) {
      folder.mkdirs();
    }
    Preconditions.checkArgument(folder.isDirectory());
  }

  public File toFile() {
    return folder;
  }

  @Override
  public void close() throws IOException {
    if (folder.exists()) {
      MoreFiles.deleteRecursively(folder.toPath(), RecursiveDeleteOption.ALLOW_INSECURE);
    }
  }
}
