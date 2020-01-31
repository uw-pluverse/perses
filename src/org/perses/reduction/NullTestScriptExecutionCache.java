package org.perses.reduction;

import org.perses.program.TokenizedProgram;

import java.util.Optional;

public final class NullTestScriptExecutionCache extends AbstractTestScriptExecutionCache {
  @Override
  public Optional<TestScript.TestResult> getCachedResult(TokenizedProgram program) {
    return Optional.empty();
  }

  @Override
  void addResult(TokenizedProgram program, TestScript.TestResult result) {}

  @Override
  public int size() {
    return 0;
  }

  @Override
  public int memoryFootprintInBytes() {
    return 0;
  }

  @Override
  public void evictEntriesLargerThan(TokenizedProgram best) {}
}
