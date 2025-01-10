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
package org.perses.fuzzer.organizer;

import com.beust.jcommander.Parameter;
import java.io.File;
import java.util.Objects;
import org.perses.grammar.SingleParserFacadeFactory;
import org.perses.program.LanguageKind;
import org.perses.util.cmd.AbstractCommandOptions;

public class CommandOptions extends AbstractCommandOptions {

  @Parameter(
      names = "--finding-folder",
      required = true,
      description = "the folder storing all the found bugs")
  public File findingFolder;

  @Parameter(
      names = "--recompute-crash-signatures",
      required = false,
      description = "recompute the crash signatures of the found bugs.")
  public boolean recomputeCrashSignatures = false;

  @Parameter(
      names = "--processing-folder",
      required = true,
      description = "the folder to process the found bugs")
  public File processingFolder;

  @Parameter(
      names = "--reported-folder",
      required = true,
      description = "the folder to store the reported bugs")
  public File reportedFolder;

  @Parameter(
      names = "--duplicate-folder",
      required = true,
      description = "the folder to store the duplicate bugs")
  public File duplicateBugFolder;

  @Parameter(
      names = "--delete-duplicates",
      arity = 1,
      required = true,
      description =
          "whether to delete the duplicates. If no, duplicates will be saved to the duplicate"
              + " folder.")
  public boolean deleteDuplicates = true;

  @Parameter(names = "--lang", required = true, description = "language of input file")
  private String lang;

  public void setLang(String lang) {
    this.lang = lang;
  }

  public LanguageKind getLanguage() {
    return Objects.requireNonNull(
        SingleParserFacadeFactory.builderWithBuiltinLanguages()
            .build()
            .computeLanguageKindWithLanguageNameIgnoreCase(lang),
        "the given language is not supported");
  }
}
