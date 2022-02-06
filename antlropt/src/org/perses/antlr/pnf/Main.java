/*
 * Copyright (C) 2018-2022 University of Waterloo.
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

import static com.google.common.base.Preconditions.checkArgument;

import com.beust.jcommander.JCommander;
import com.beust.jcommander.Parameter;
import com.google.common.io.Files;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Path;
import java.nio.file.Paths;
import org.perses.antlr.ast.PersesAstBuilder;
import org.perses.antlr.ast.PersesGrammar;
import org.perses.antlr.util.Util;
import org.perses.util.FileNameContentPair;

public class Main {

  public static class Options {

    @Parameter(
        names = "--source",
        required = true,
        description = "The Antlr grammar file for processing.")
    public String sourceFile;

    @Parameter(names = "--lexer", description = "The lexer definition for the parser grammar.")
    public Path lexerFile;

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

    final Path sourceFile = Paths.get(cmd.sourceFile);
    checkArgument(java.nio.file.Files.exists(sourceFile), sourceFile);
    checkArgument(java.nio.file.Files.isRegularFile(sourceFile), sourceFile);
    final String sourceAntlrFileContent =
        Files.asCharSource(sourceFile.toFile(), StandardCharsets.UTF_8).read();

    final PersesGrammar origGrammar =
        PersesAstBuilder.loadGrammarFromString(sourceAntlrFileContent)
            .copyWithNewName(Util.extractGrammarNameFromGrammarFileName(cmd.outputFile));
    final FileNameContentPair lexerGrammar =
        cmd.lexerFile == null ? null : FileNameContentPair.createFromFile(cmd.lexerFile);

    PnfPassManager passes = new PnfPassManager();
    PersesGrammar processedGrammar = passes.process(origGrammar, cmd.startRuleName, lexerGrammar);
    final String output = processedGrammar.getSourceCode();
    Files.asCharSink(Paths.get(cmd.outputFile).toFile(), StandardCharsets.UTF_8).write(output);
  }
}
