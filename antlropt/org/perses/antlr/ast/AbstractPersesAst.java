package org.perses.antlr.ast;

import org.checkerframework.checker.nullness.qual.MonotonicNonNull;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.nio.charset.StandardCharsets;
import java.util.function.Consumer;

/** The Perses ASTs are IMMUTABLE. */
public abstract class AbstractPersesAst implements Comparable<AbstractPersesAst> {

  @MonotonicNonNull private String sourceCode;

  public final synchronized String getSourceCode() {
    if (sourceCode == null) {
      final ByteArrayOutputStream baos = new ByteArrayOutputStream();
      try (PrintStream ps = new PrintStream(baos, true, StandardCharsets.UTF_8.name())) {
        toSourceCode(ps, /*indent=*/ 0, /*multilineMode=*/ true);
      } catch (Exception e) {
        throw new RuntimeException(e);
      }
      sourceCode = baos.toString();
    }
    return sourceCode;
  }

  public abstract void toSourceCode(PrintStream stream, int indent, boolean multiLineMode);

  public final String printTreeStructure() {
    final ByteArrayOutputStream baos = new ByteArrayOutputStream();
    try (PrintStream ps = new PrintStream(baos, true, StandardCharsets.UTF_8.name())) {
      printTreeStructure(ps, /*indent=*/ 0);
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
    return baos.toString();
  }

  public void printTreeStructure(PrintStream stream, int indent) {
    printIndent(stream, indent)
        .append(getClass().getSimpleName())
        .append(" ")
        .append(getExtraLabelForTreeStructurePrinting())
        .println();
    final int newIndent = indent + 4;
    final int childCount = getChildCount();
    for (int i = 0; i < childCount; ++i) {
      getChild(i).printTreeStructure(stream, newIndent);
    }
  }

  protected final Precedence getPrecedence() {
    return getTag().getPrecedence();
  }

  protected String getExtraLabelForTreeStructurePrinting() {
    return "";
  }

  public abstract int getChildCount();

  public abstract AbstractPersesAst getChild(int index);

  public final void foreachChild(Consumer<? super AbstractPersesAst> consumer) {
    for (int i = 0, size = getChildCount(); i < size; ++i) {
      consumer.accept(getChild(i));
    }
  }

  protected static PrintStream printIndent(PrintStream stream, int indent) {
    for (int i = 0; i < indent; ++i) {
      stream.print(' ');
    }
    return stream;
  }

  public abstract AstTag getTag();

  @Override
  public int compareTo(AbstractPersesAst o) {
    return getSourceCode().compareTo(o.getSourceCode());
  }
}
