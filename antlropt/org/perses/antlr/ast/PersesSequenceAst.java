package org.perses.antlr.ast;

import com.google.common.base.MoreObjects;
import com.google.common.collect.ImmutableList;

import java.io.PrintStream;
import java.util.List;

import static com.google.common.base.Preconditions.checkArgument;

public final class PersesSequenceAst extends AbstractPersesRuleElement {

  private final ImmutableList<AbstractPersesRuleElement> children;

  public PersesSequenceAst(ImmutableList<AbstractPersesRuleElement> children) {
    checkArgument(children.size() > 1);
    for (AbstractPersesRuleElement child : children) {
      checkArgument(child.getTag() != AstTag.EPSILON);
      checkArgument(child.getTag() != AstTag.SEQUENCE);
    }
    this.children = children;
  }

  @Override
  public AbstractPersesRuleElement createWithNewChildren(
      List<AbstractPersesRuleElement> newChildren) {
    return new PersesSequenceAst(ImmutableList.copyOf(newChildren));
  }

  public ImmutableList<AbstractPersesRuleElement> getChildren() {
    return children;
  }

  @Override
  public void toSourceCode(PrintStream stream, int indent, boolean multiLineMode) {
    boolean isFirst = true;
    for (AbstractPersesAst child : children) {
      if (isFirst) {
        isFirst = false;
      } else {
        stream.print(' ');
      }
      if (child.getPrecedence().gt(getPrecedence())) {
        child.toSourceCode(stream, indent, false);
      } else {
        stream.print('(');
        child.toSourceCode(stream, indent, false);
        stream.print(')');
      }
    }
  }

  @Override
  public AbstractPersesRuleElement getChild(int index) {
    return children.get(index);
  }

  public AbstractPersesRuleElement getFirstChild() {
    return children.get(0);
  }

  public AbstractPersesRuleElement getLastChild() {
    return children.get(children.size() - 1);
  }

  @Override
  public int getChildCount() {
    return children.size();
  }

  @Override
  public AstTag getTag() {
    return AstTag.SEQUENCE;
  }

  @Override
  public String toString() {
    return MoreObjects.toStringHelper(this).add("code", getSourceCode()).toString();
  }

  public AbstractPersesRuleElement subsequence(int from, int toExcusive) {
    final int size = getChildCount();
    checkArgument(from >= 0 && from < size, "Invalid index %s", from);
    checkArgument(toExcusive > from && toExcusive <= size);
    if (from == 0 && toExcusive == size) {
      return this;
    }
    if (from + 1 == toExcusive) {
      return getChild(from);
    }
    ImmutableList.Builder<AbstractPersesRuleElement> builder = ImmutableList.builder();
    for (int i = from; i < toExcusive; ++i) {
      builder.add(getChild(i));
    }
    return new PersesSequenceAst(builder.build());
  }

  public AbstractPersesRuleElement subsequence(int from) {
    return subsequence(from, children.size());
  }
}
