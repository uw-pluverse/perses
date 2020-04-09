package org.perses.antlr.ast;

import java.util.List;
import java.util.function.Consumer;

public abstract class AbstractPersesRuleElement extends AbstractPersesAst {

  @Override
  public abstract AbstractPersesRuleElement getChild(int index);

  public void foreachChildRuleElement(Consumer<? super AbstractPersesRuleElement> consumer) {
    for (int i = 0, size = getChildCount(); i < size; ++i) {
      consumer.accept(getChild(i));
    }
  }

  public abstract AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren);

  public final boolean isEquivalent(AbstractPersesRuleElement other) {
    if (other.getClass() != getClass()) {
      return false;
    }
    if (!areChildrenEquivalent(other)) {
      return false;
    }
    return extraEquivalenceTest(other);
  }

  protected boolean areChildrenEquivalent(AbstractPersesRuleElement other) {
    final int size = getChildCount();
    if (size != other.getChildCount()) {
      return false;
    }
    // Note that all Perses ASTs should normalize to a single form.
    for (int i = 0; i < size; ++i) {
      if (!getChildForEquivalenceChecking(i)
          .isEquivalent(other.getChildForEquivalenceChecking(i))) {
        return false;
      }
    }
    return true;
  }

  protected AbstractPersesRuleElement getChildForEquivalenceChecking(int index) {
    return getChild(index);
  }

  protected boolean extraEquivalenceTest(AbstractPersesRuleElement other) {
    return true;
  }
}
