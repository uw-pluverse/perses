package org.perses.antlr.util;

import com.beust.jcommander.JCommander;
import com.beust.jcommander.Parameter;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.Iterables;
import com.google.common.io.Files;
import org.perses.antlr.ast.AbstractPersesRuleDefAst;
import org.perses.antlr.ast.PersesAstBuilder;
import org.perses.antlr.ast.PersesGrammar;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.nio.charset.StandardCharsets;

@Deprecated
// Not being used.
public final class LexerParserCombiner {

  public static String combineLexerAndParser(
      String lexerGrammarString, String parserGrammarString, String targetGrammarName) {
    final PersesGrammar lexer = PersesAstBuilder.loadGrammarFromString(lexerGrammarString);
    final PersesGrammar parser = PersesAstBuilder.loadGrammarFromString(parserGrammarString);
    final ImmutableList<AbstractPersesRuleDefAst> lexerRules = lexer.getRules();
    final ImmutableList<AbstractPersesRuleDefAst> parserRules = parser.getRules();

    final ByteArrayOutputStream baos = new ByteArrayOutputStream();
    try (PrintStream ps = new PrintStream(baos, true, StandardCharsets.UTF_8.name())) {
      ps.printf("// Combined by %s\n", LexerParserCombiner.class.getCanonicalName());
      ps.println("// DO NOT MODIFY.");
      ps.printf("grammar %s;\n", targetGrammarName);
      ps.println();

      for (AbstractPersesRuleDefAst rule : Iterables.concat(lexerRules, parserRules)) {
        rule.toSourceCode(ps, /*indent=*/ 0, /*multilineMode=*/ true);
      }
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
    return baos.toString();
  }

  public static class Options {

    @Parameter(
        names = "--lexer-grammar",
        required = true,
        description = "The lexer grammar file to combine.")
    public String lexerFile;

    @Parameter(
        names = "--parser-grammar",
        required = true,
        description = "The parser grammar file to combine.")
    public String parserFile;

    @Parameter(
        names = "--target-grammar",
        required = true,
        description = "The file to save the combine grammar")
    public String resultGrammarFile;

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

    final String lexer = read(cmd.lexerFile);
    final String parser = read(cmd.parserFile);

    final String targetGrammarName =
        Util.extractGrammarNameFromGrammarFileName(cmd.resultGrammarFile);
    Files.asCharSink(new File(targetGrammarName), StandardCharsets.UTF_8)
        .write(combineLexerAndParser(lexer, parser, targetGrammarName));
  }

  private static String read(String filepath) throws IOException {
    return Files.asCharSource(new File(filepath), StandardCharsets.UTF_8).read();
  }
}
