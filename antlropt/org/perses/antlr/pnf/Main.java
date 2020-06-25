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
package org.perses.antlr.pnf;

import com.beust.jcommander.JCommander;
import com.beust.jcommander.Parameter;
import com.google.common.io.Files;
import org.perses.antlr.ast.PersesAstBuilder;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.antlr.util.Util;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;

import static com.google.common.base.Preconditions.checkArgument;

public class Main {

  public static class Options {

    @Parameter(
        names = "--source",
        required = true,
        description = "The Antlr grammar file for processing.")
    public String sourceFile;

    @Parameter(
        names = "--output",
        required = true,
        description = "The file to save the processed grammar.")
    public String outputFile;

    @Parameter(
        names = "--start_rule_name",
        required = true,
        description = "The name of the start rule in the source grammar.")
    public String startRuleName;

    @Parameter(names = "--help", description = "print help message", help = true)
    public boolean help;
  }

  public static void main(String[] args) throws IOException {
    final Options cmd = new Options();
    JCommander commander = new JCommander(cmd);
    commander.parse(args);
    if (cmd.help) {
      commander.usage();
      return;
    }

    final File sourceFile = new File(cmd.sourceFile);
    checkArgument(sourceFile.exists(), sourceFile);
    checkArgument(sourceFile.isFile(), sourceFile);
    final String sourceAntlrFileContent =
        Files.asCharSource(sourceFile, StandardCharsets.UTF_8).read();

    final PersesGrammar origGrammar =
        PersesAstBuilder.loadGrammarFromString(sourceAntlrFileContent)
            .copyWithNewName(Util.extractGrammarNameFromGrammarFileName(cmd.outputFile));

    PnfPassManager passes = new PnfPassManager();
    PersesGrammar processedGrammar = passes.process(origGrammar, cmd.startRuleName);
    final String output = processedGrammar.getSourceCode();
    Files.asCharSink(new File(cmd.outputFile), StandardCharsets.UTF_8).write(output);
  }
}
