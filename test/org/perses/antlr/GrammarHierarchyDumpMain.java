package org.perses.antlr;

import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import org.perses.grammar.c.PnfCParserFacade;

import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.Comparator;

public class GrammarHierarchyDumpMain {

  public static void main(String[] args) throws IOException {
    Preconditions.checkArgument(args.length == 1);
    final GrammarHierarchy hierarchy = new PnfCParserFacade().getRuleHierarchy();
    final ImmutableList<RuleHierarchyInfo> rules =
        hierarchy.getRuleList().stream()
            .sorted(Comparator.comparing(RuleHierarchyInfo::getRuleName))
            .collect(ImmutableList.toImmutableList());
    try (BufferedWriter writer =
        Files.newBufferedWriter(
            Paths.get(args[0]), StandardCharsets.UTF_8, StandardOpenOption.CREATE)) {
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
