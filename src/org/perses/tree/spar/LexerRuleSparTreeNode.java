package org.perses.tree.spar;

import org.perses.antlr.RuleHierarchyInfo;
import org.perses.antlr.RuleType;
import org.perses.program.PersesToken;

import java.util.Optional;

public final class LexerRuleSparTreeNode extends AbstractSparTreeNode {

  private final PersesToken token;
  private LexerRuleSparTreeNode prev;
  private LexerRuleSparTreeNode next;

  LexerRuleSparTreeNode(
      int nodeId, PersesToken token, RuleType nodeType, Optional<RuleHierarchyInfo> antlrRule) {
    super(nodeId, nodeType, antlrRule);
    this.token = token;
  }

  public PersesToken getToken() {
    return token;
  }

  @Override
  protected String getLabelPrefix() {
    return "Token:" + token.getText();
  }

  @Override
  public LexerRuleSparTreeNode asLexerRule() {
    return this;
  }

  @Override
  public LexerRuleSparTreeNode beginToken() {
    return this;
  }

  @Override
  public LexerRuleSparTreeNode endToken() {
    return this;
  }

  public void resetPrev() {
    prev = null;
  }

  public void resetNext() {
    next = null;
  }

  public void setNext(LexerRuleSparTreeNode next) {
    assert next != null;
    assert this.next == null;
    this.next = next;
    assert this.next != null;
  }

  public void setPrev(LexerRuleSparTreeNode prev) {
    assert prev != null;
    assert this.prev == null;
    this.prev = prev;
    assert this.prev != null;
  }

  public LexerRuleSparTreeNode getNext() {
    return next;
  }

  public LexerRuleSparTreeNode getPrev() {
    return prev;
  }
}
