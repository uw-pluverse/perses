package org.perses.antlr.ast;

import com.google.common.collect.ImmutableList;

import java.util.Optional;

public abstract class AstEdit {

  public final Optional<AbstractPersesRuleElement> apply(AbstractPersesRuleElement ast) {
    return apply(ast, /*isRoot=*/ true);
  }

  private final Optional<AbstractPersesRuleElement> apply(
      AbstractPersesRuleElement ast, boolean isRoot) {
    final int size = ast.getChildCount();
    ImmutableList.Builder<AbstractPersesRuleElement> newChildren = ImmutableList.builder();
    boolean childrenChanged = false;
    for (int i = 0; i < size; ++i) {
      AbstractPersesRuleElement oldChild = ast.getChild(i);
      Optional<AbstractPersesRuleElement> newChild = apply(oldChild, /*isRoot=*/ false);
      if (newChild.isPresent()) {
        childrenChanged = true;
        newChildren.add(newChild.get());
      } else {
        newChildren.add(oldChild);
      }
    }
    if (childrenChanged) {
      return Optional.of(internalApplyWithNewChildren(ast, newChildren.build(), isRoot));
    } else {
      return internalApply(ast, isRoot);
    }
  }

  protected abstract Optional<AbstractPersesRuleElement> internalApply(
      AbstractPersesRuleElement element, boolean isRoot);

  protected final AbstractPersesRuleElement internalApplyWithNewChildren(
      AbstractPersesRuleElement element,
      ImmutableList<AbstractPersesRuleElement> children,
      boolean isRoot) {
    AbstractPersesRuleElement newElement = element.createWithNewChildren(children);
    Optional<AbstractPersesRuleElement> appliedElement = internalApply(newElement, isRoot);
    return appliedElement.isPresent() ? appliedElement.get() : newElement;
  }
}
