package org.perses.antlr.pnf;

import com.beust.jcommander.JCommander;
import com.beust.jcommander.Parameter;
import com.google.common.base.Preconditions;
import com.google.common.io.Files;
import org.perses.antlr.ast.PersesAstBuilder;
import org.perses.antlr.ast.PersesGrammar;

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
            .copyWithNewName(extractGrammarNameFrom(cmd.outputFile));

    PnfPassManager passes = new PnfPassManager();
    PersesGrammar processedGrammar = passes.process(origGrammar, cmd.startRuleName);
    final String output = processedGrammar.getSourceCode();
    Files.asCharSink(new File(cmd.outputFile), StandardCharsets.UTF_8).write(output);
  }

  private static String extractGrammarNameFrom(String fileName) {
    Preconditions.checkState(fileName.endsWith(".g4"));
    final File file = new File(fileName);
    final String name = file.getName();
    return name.substring(0, name.lastIndexOf(".g4"));
  }
}
