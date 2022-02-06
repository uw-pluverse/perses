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
package org.perses.antlr;

import com.beust.jcommander.JCommander;
import com.beust.jcommander.Parameter;
import com.google.common.collect.ImmutableList;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.Comparator;
import org.perses.grammar.c.PnfCParserFacade;
import org.perses.grammar.go.PnfGoParserFacade;
import org.perses.grammar.scala.PnfScalaParserFacade;

public class GrammarHierarchyDumpMain {

  private static final class Options {
    @Parameter(names = "-c", required = true)
    public String c;

    @Parameter(names = "-go", required = true)
    public String go;

    @Parameter(names = "-scala", required = true)
    public String scala;
  }

  public static void main(String[] args) throws IOException {
    final Options cmd = new Options();
    final JCommander commander = JCommander.newBuilder().addObject(cmd).build();
    commander.parse(args);

    dumpGrammarHierarchy(cmd.c, new PnfCParserFacade().getRuleHierarchy());
    dumpGrammarHierarchy(cmd.go, new PnfGoParserFacade().getRuleHierarchy());
    dumpGrammarHierarchy(cmd.scala, new PnfScalaParserFacade().getRuleHierarchy());
  }

  private static void dumpGrammarHierarchy(String outputPath, GrammarHierarchy hierarchy)
      throws IOException {
    final ImmutableList<RuleHierarchyInfo> rules =
        hierarchy.getRuleList().stream()
            .sorted(Comparator.comparing(RuleHierarchyInfo::getRuleName))
            .collect(ImmutableList.toImmutableList());
    try (BufferedWriter writer =
        Files.newBufferedWriter(
            Paths.get(outputPath), StandardCharsets.UTF_8, StandardOpenOption.CREATE)) {
      for (RuleHierarchyInfo rule : rules) {
        if (rule.getTransitiveSubRules().isEmpty()) {
          continue;
        }
        writer.append(rule.getRuleName()).append('\n');

        writer
            .append(INDENT)
            .append("epsilonable: ")
            .append(Boolean.toString(rule.canRuleBeEpsilon()))
            .append("\n");

        writer.append(INDENT).append("immediate sub-rule names:\n");
        for (String subruleName :
            rule.getImmediateSubRuleNames().stream()
                .sorted()
                .collect(ImmutableList.toImmutableList())) {
          writer.append(INDENT).append(INDENT).append(subruleName).append('\n');
        }

        writer.append(INDENT).append("transitive sub-rule names:\n");
        for (String ruleName :
            rule.getTransitiveSubRules().stream()
                .map(RuleHierarchyInfo::getRuleName)
                .sorted()
                .collect(ImmutableList.toImmutableList())) {
          writer.append(INDENT).append(INDENT).append(ruleName).append('\n');
        }
      }
    }
  }

  private static final String INDENT = "    ";
}
