package org.perses.reduction;

import com.google.common.collect.ArrayListMultimap;
import com.google.common.collect.Multimap;
import org.junit.Ignore;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.TestUtility;
import org.perses.program.TokenizedProgram;
import org.perses.tree.spar.AbstractSparTreeNode;
import org.perses.tree.spar.NodeDeletionActionSet;
import org.perses.tree.spar.SparTree;

import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayDeque;
import java.util.Queue;

@RunWith(JUnit4.class)
public class TokenizedProgramEncoderBenchmark {

  @Ignore
  @Test
  public void benchmarkEncoderConstruction() throws IOException {
    final SparTree tree =
        TestUtility.createSparTreeFromFile("test/org/perses/reduction/clang-22704.c");
    final TokenizedProgram program = tree.getProgramSnapshot();
    Multimap<Integer, Long> programSizeToConstructionTime = ArrayListMultimap.create();

    Queue<AbstractSparTreeNode> worklist = new ArrayDeque<>();
    tree.getRoot().forEachChild(worklist::offer);
    while (!worklist.isEmpty()) {
      AbstractSparTreeNode node = worklist.poll();
      NodeDeletionActionSet edit =
          NodeDeletionActionSet.createByDeleteSingleNode(node, "dummy desc");
      final TokenizedProgram p = tree.createNodeDeletionEdit(edit).getProgram();
      final int iterations = 1;
      final long startTime = System.currentTimeMillis();
      for (int i = 0; i < iterations; ++i) {
        new TokenizedProgramEncoder(
            p.getTokens(), AbstractTestScriptExecutionCacheProfiler.NULL_PROFILER);
      }
      final long endTime = System.currentTimeMillis();
      final long avgTime = (endTime - startTime) / iterations;
      programSizeToConstructionTime.put(p.getTokens().size(), avgTime);

      node.forEachChild(worklist::offer);
      System.out.println("worklist size = " + worklist.size());
    }

    final File tempFile = File.createTempFile("benchmark-encoder_construction", ".txt");
    try (BufferedWriter writer =
        Files.newBufferedWriter(tempFile.toPath(), StandardCharsets.UTF_8)) {
      programSizeToConstructionTime
          .asMap()
          .entrySet()
          .forEach(
              entry -> {
                try {
                  writer
                      .append(String.valueOf(entry.getKey()))
                      .append("\t")
                      .append(
                          String.valueOf(
                              entry.getValue().stream().mapToLong(Long::longValue).average()))
                      .append("\n");
                } catch (IOException e) {
                  e.printStackTrace();
                }
              });
    }
    System.err.println("the result file is " + tempFile);
  }
}
