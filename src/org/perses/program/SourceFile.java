/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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
package org.perses.program;

import com.google.common.base.MoreObjects;
import com.google.common.flogger.FluentLogger;
import com.google.common.io.MoreFiles;
import org.perses.LanguageKind;

import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

import static com.google.common.base.Preconditions.checkState;

/**
 * Abstraction for a source file. It encapsulates the details of a source file. Note that this class
 * loads the content of the passed-in file. So when you create an object of this class, the file
 * must already exist.
 */
public class SourceFile {

  private static final FluentLogger logger = FluentLogger.forEnclosingClass();

  public static SourceFile createFromPath(File file) {
    final LanguageKind kind = LanguageKind.computeLanguageKind(file);
    logger.atInfo().log("The source file %s is identified as %s", file, kind);
    return new SourceFile(file, kind);
  }

  private final File file;
  private final LanguageKind kind;
  private final String fileContent;

  private SourceFile(File file, LanguageKind languageKind) {
    checkState(file.isFile(), "The file should be a file: %s", file);
    this.file = file;
    this.kind = languageKind;
    try {
      this.fileContent = MoreFiles.asCharSource(file.toPath(), StandardCharsets.UTF_8).read();
    } catch (IOException e) {
      throw new RuntimeException("Error in reading file " + file, e);
    }
  }

  public LanguageKind getLanguageKind() {
    return kind;
  }

  public String getBaseName() {
    return file.getName();
  }

  public File getFile() {
    return file;
  }

  public String getFileContent() {
    return fileContent;
  }

  public void writeTo(File path) throws IOException {
    try (BufferedWriter writer =
        java.nio.file.Files.newBufferedWriter(path.toPath(), StandardCharsets.UTF_8)) {
      writer.write(fileContent);
    }
  }

  @Override
  public String toString() {
    return MoreObjects.toStringHelper(this).add("file", file).add("lang", kind).toString();
  }
}
