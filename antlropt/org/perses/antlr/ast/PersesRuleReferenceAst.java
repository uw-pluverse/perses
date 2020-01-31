package org.perses.antlr.ast;

import com.google.common.base.MoreObjects;

import java.io.PrintStream;
import java.util.List;

public final class PersesRuleReferenceAst extends AbstractPersesRuleElement {

  private final RuleNameRegistry.RuleNameHandle ruleNameHandle;

  public PersesRuleReferenceAst(RuleNameRegistry.RuleNameHandle ruleNameHandle) {
    this.ruleNameHandle = ruleNameHandle;
  }

  public RuleNameRegistry.RuleNameHandle getRuleNameHandle() {
    return ruleNameHandle;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    stream.print(ruleNameHandle.get());
  }

  @Deprecated
  @Override
  public AbstractPersesRuleElement getChild(int index) {
    throw new UnsupportedOperationException();
  }

  @Override
  public int getChildCount() {
    return 0;
  }

  @Override
  protected String getExtraLabelForTreeStructurePrinting() {
    return "rule_name=" + ruleNameHandle.get();
  }

  @Override
  public AstTag getTag() {
    return AstTag.RULE_REF;
  }

  @Override
  public String toString() {
    return MoreObjects.toStringHelper(this).add("ref", ruleNameHandle.get()).toString();
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    return this;
  }

  @Override
  protected boolean extraEquivalenceTest(AbstractPersesRuleElement other) {
    return ruleNameHandle.get().equals(((PersesRuleReferenceAst) other).ruleNameHandle.get());
  }
}
