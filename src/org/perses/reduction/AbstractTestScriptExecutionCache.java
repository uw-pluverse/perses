package org.perses.reduction;

import org.perses.program.TokenizedProgram;

import java.util.Optional;

public abstract class AbstractTestScriptExecutionCache {
  public abstract Optional<TestScript.TestResult> getCachedResult(TokenizedProgram program);

  abstract void addResult(TokenizedProgram program, TestScript.TestResult result);

  public abstract int size();

  public abstract int memoryFootprintInBytes();

  public abstract void evictEntriesLargerThan(TokenizedProgram best);
}
