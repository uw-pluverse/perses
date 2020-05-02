package org.perses.listener;

import com.google.common.base.Splitter;
import com.google.common.base.Strings;
import com.google.common.collect.ImmutableList;
import org.checkerframework.checker.nullness.qual.Nullable;
import org.perses.reduction.AbstractReductionEvent;
import org.perses.reduction.TestScript;
import org.perses.tree.spar.AbstractActionSet;
import org.perses.tree.spar.AbstractSparTreeEdit;
import org.perses.tree.spar.AbstractSparTreeNode;
import org.perses.tree.spar.AbstractUnmodifiableSparTree;

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.nio.charset.StandardCharsets;

public class ProgressMonitorForNodeReducer extends DefaultReductionListener {

  public static ProgressMonitorForNodeReducer createForFile(File resultFile) {
    return new ProgressMonitorForNodeReducer(resultFile);
  }

  public static ProgressMonitorForNodeReducer createForSystemOut() {
    return new ProgressMonitorForNodeReducer(null);
  }

  private int beforeSize;
  @Nullable private PrintStream stream;
  private int testSuccessCount;
  private int testFailureCount;
  private int testResultCacheHitCount;
  private int testExcecutionCancelled;
  private int nodeEditActionSetCacheHitCount;
  @Nullable private final File resultFile;

  /** Note that this listener will NOT close the stream. The client needs to close it manually. */
  private ProgressMonitorForNodeReducer(@Nullable File resultFile) {
    this.resultFile = resultFile;
  }

  @Override
  public void onReductionStart(AbstractReductionEvent.ReductionStartEvent event) {
    if (resultFile != null) {
      try {
        this.stream = new PrintStream(resultFile, StandardCharsets.UTF_8.name());
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
    } else {
      this.stream = System.out;
    }

    printBegin("Reduction starts");
    stream.println("The spar tree is the following.");
    stream.println(event.getTree().printTreeStructure().trim());
    printEnd();
  }

  @Override
  public void onReductionEnd(AbstractReductionEvent.ReductionEndEvent event) {
    stream.printf("#test success = %d\n", testSuccessCount);
    stream.printf("#test failure = %d\n", testFailureCount);
    stream.printf("#test result cache hits = %d\n", testResultCacheHitCount);
    stream.printf("#test execution cancelled = %d\n", testExcecutionCancelled);
    stream.printf("#node edit action set cache hits = %d\n", nodeEditActionSetCacheHitCount);
    if (stream != System.out) {
      stream.close();
      stream = null;
    }
  }

  @Override
  public void onTestScriptExecution(AbstractReductionEvent.TestScriptExecutionEvent event) {
    final TestScript.TestResult result = event.getResult();
    final AbstractSparTreeEdit edit = event.getEdit();
    printBegin("Testing the following program: " + (result.isPass() ? "pass" : "fail"));
    stream.printf("// edit action set type: %s\n", event.getEdit().getActionSet().getActionsDescription());
    printCode(edit.getProgram().getSourceCodeInOrigFormatWithBlankLines().trim());
    printEnd();

    if (result.isPass()) {
      ++testSuccessCount;
    } else {
      ++testFailureCount;
    }
  }

  @Override
  public void onNodeEditActionSetCacheHit(
      AbstractReductionEvent.NodeEditActionSetCacheHitEvent event) {
    printBegin("Node edit action set cache hit.");
    final AbstractActionSet<?> query = event.getQuery();
    final ImmutableList<?> actions = query.getActions();
    for (Object action : actions) {
      stream.printf("    %s\n", action);
    }
    printEnd();
    ++nodeEditActionSetCacheHitCount;
  }

  @Override
  public void onNodeActionSetCacheClearance(
      AbstractReductionEvent.NodeEditActionSetCacheClearanceEvent event) {
    printBegin("Node edit action set cache is cleared.");
    stream.printf("    size before clearance = %d\n", event.getOriginalEntrySize());
    printEnd();
  }

  @Override
  public void onTestResultCacheHit(AbstractReductionEvent.TestResultCacheHitEvent event) {
    final TestScript.TestResult result = event.getResult();
    printBegin("Cache hit for the following program: " + (result.isPass() ? "pass" : "fail"));
    printCode(event.getEdit().getProgram().getSourceCodeInOrigFormatWithBlankLines().trim());
    printEnd();
    ++testResultCacheHitCount;
  }

  @Override
  public void onTestScriptExecutionCancelled(
      AbstractReductionEvent.TestScriptExecutionCanceledEvent event) {
    printBegin("Test script execution is cancelled.");
    stream.printf(
        "It took %s than 1 second to cancel the task.\n\n",
        (event.getMillisToCancelTheTask() <= 1000 ? "less" : "more"));
    printCode(event.getProgram().getSourceCodeInOrigFormatWithBlankLines().trim());
    printEnd();
    ++testExcecutionCancelled;
  }

  @Override
  public void onNodeReductionStart(AbstractReductionEvent.NodeReductionStartEvent event) {
    final AbstractSparTreeNode node = event.getNode();
    final int programSize = event.getProgramSize();
    final AbstractUnmodifiableSparTree tree = event.getTree();
    printBegin(String.format("Reducing node %d, size=%d", node.getNodeId(), programSize));
    this.beforeSize = programSize;
    stream.println("The current best program is the following\n");
    printCode(tree.getProgramSnapshot().getSourceCodeInOrigFormatWithBlankLines().trim());
    printEnd();
  }

  @Override
  public void onNodeReductionEnd(AbstractReductionEvent.NodeReductionEndEvent event) {
    printBegin("Node reduction is done");
    final int programSize = event.getProgramSize();
    final AbstractSparTreeNode node = event.getNode();
    if (this.beforeSize > programSize) {
      stream.printf(
          "Succeeded to reduce node %d from %d to %d\n",
          node.getNodeId(), this.beforeSize, programSize);
    } else {
      stream.printf("Failed to reduce node %d\n", node.getNodeId());
    }
    printEnd();
  }

  @Override
  public void onTestScriptExecutionCacheEntryEviction(
      AbstractReductionEvent.TestScriptExecutionCacheEntryEvictionEvent event) {
    printBegin("TestScriptExecutionCacheEntryEviction");
    stream.printf(
        "%d entries are removed: %d --> %d.\n",
        event.getSizeBefore() - event.getSizeAfter(), event.getSizeBefore(), event.getSizeAfter());
    printEnd();
  }

  private void printBegin(String section) {
    final int length = PROGRAM_END_MARKER.length();
    final int paddingLength = Math.max((length - section.length()) / 2, 1);
    final String padding = Strings.padEnd("", paddingLength, '=');

    final StringBuilder builder = new StringBuilder();
    builder.append(padding);
    builder.append(section);
    while (builder.length() < length) {
      builder.append('=');
    }
    stream.println(builder.toString());
    stream.println();
  }

  private void printEnd() {
    stream.println(PROGRAM_END_MARKER);
    stream.println("\n");
  }

  private void printCode(String code) {
    Iterable<String> split = Splitter.on('\n').omitEmptyStrings().split(code);
    split.forEach(
        line -> {
          if (line.trim().length() > 0) stream.println("    " + line);
        });
  }

  private static final String PROGRAM_END_MARKER = Strings.padEnd("", 60, '-');
}
