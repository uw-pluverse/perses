/*
 * Copyright (C) 2018-2020 University of Waterloo.
 *
 * This file is part of Perses.
 *
 * Perses is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * Perses is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Perses; see the file LICENSE.  If not see <http://www.gnu.org/licenses/>.
 */
package org.perses.tree.spar;

import com.google.common.base.MoreObjects;
import com.google.common.collect.ImmutableList;
import org.checkerframework.checker.nullness.qual.Nullable;
import org.perses.antlr.RuleHierarchyInfo;
import org.perses.antlr.RuleType;
import org.perses.util.Util;

import java.io.IOError;
import java.io.IOException;
import java.io.StringWriter;
import java.io.Writer;
import java.util.*;
import java.util.function.Consumer;
import java.util.function.Predicate;
import java.util.stream.Collectors;

import static com.google.common.base.Preconditions.checkArgument;
import static com.google.common.base.Preconditions.checkState;

public abstract class AbstractSparTreeNode implements Comparable<AbstractSparTreeNode> {
  private static int INVALID_LEAF_TOKEN_COUNT = Integer.MIN_VALUE;

  private final int nodeId;
  protected final RuleType nodeType;
  private final Optional<RuleHierarchyInfo> antlrRule;
  private final ArrayList<AbstractSparTreeNode> children;
  private final List<AbstractSparTreeNode> immutableChildView;
  /** Each element is the expected Antlr rule for each child. */
  private final ArrayList<Optional<RuleHierarchyInfo>> expectedAntlrRuleTypesOfChildren;

  @Nullable protected ParentInfo parent;
  private boolean isDeleted;
  /** The count of tokens under this node. */
  private int leafTokenCount = INVALID_LEAF_TOKEN_COUNT;

  AbstractSparTreeNode(int nodeId, RuleType nodeType, Optional<RuleHierarchyInfo> antlrRule) {
    super();
    this.nodeId = nodeId;
    this.antlrRule = antlrRule;
    this.isDeleted = false;
    this.nodeType = nodeType;

    this.children = new ArrayList<>();
    this.immutableChildView = Collections.unmodifiableList(this.children);
    this.expectedAntlrRuleTypesOfChildren = new ArrayList<>();
  }

  public static String printTreeStructure(AbstractSparTreeNode root) {
    final StringWriter writer = new StringWriter();
    try {
      printTreeStructure(root, writer);
    } catch (IOException e) {
      throw new IOError(e);
    }
    writer.flush();
    return writer.toString();
  }

  @Override
  public int compareTo(AbstractSparTreeNode o) {
    return Integer.compare(nodeId, o.nodeId);
  }

  public static void printTreeStructure(AbstractSparTreeNode root, Writer writer)
      throws IOException {
    writer.append(getStringLabel(root)).append('\n');
    printTreeStructure(root, writer, new ArrayList<String>());
  }

  private static Writer outputPrefix(
      Writer writer, ArrayList<String> prefix, String additionalPrefix) throws IOException {
    for (String p : prefix) {
      writer.append(p);
    }
    writer.append(additionalPrefix);
    return writer;
  }

  public static void printTreeStructure(
      AbstractSparTreeNode root, Writer writer, ArrayList<String> prefix) throws IOException {
    final int childCount = root.getChildCount();
    if (childCount == 0) {
      return;
    }
    for (int i = 0; i < childCount; ++i) {
      outputPrefix(writer, prefix, "|___");
      prefix.add((i == childCount - 1) ? "    " : "|   ");
      final AbstractSparTreeNode child = root.getChild(i);
      writer.append(getStringLabel(child)).append('\n');
      printTreeStructure(child, writer, prefix);
      prefix.remove(prefix.size() - 1);
    }
  }

  public static String getStringLabel(AbstractSparTreeNode node) {
    final StringBuilder builder = new StringBuilder();
    builder.append(node.getLabelPrefix());
    builder.append(" {");
    builder.append("id=").append(node.getNodeId());
    if (node.getParentInfo() != null) {
      builder
          .append(",")
          .append("slot_type=")
          .append(
              node.getParentInfo()
                  .getAntlrRuleForTheChild()
                  .map(RuleHierarchyInfo::getRuleName)
                  .orElse("Token"));
    }
    builder.append("}");
    return builder.toString();
  }

  protected abstract String getLabelPrefix();

  /** @return the count of the children. */
  public final int getChildCount() {
    return children.size();
  }

  /** Return the child at the specified index. */
  public final AbstractSparTreeNode getChild(int index) {
    return children.get(index);
  }

  /**
   * Return an immutable view of the children. The underlying children list of this node can still
   * change.
   *
   * @return an immutable view of the children.
   */
  public final List<AbstractSparTreeNode> getImmutableChildView() {
    return immutableChildView;
  }

  public final String printTreeStructure() {
    return printTreeStructure(this);
  }

  public final boolean isTokenNode() {
    return nodeType == RuleType.TOKEN;
  }

  public final boolean isKleeneStarRuleNode() {
    return nodeType == RuleType.KLEENE_STAR;
  }

  public final boolean isKleenePlusRuleNode() {
    return nodeType == RuleType.KLEENE_PLUS;
  }

  /** Return {@code true} if the node is *, +, or ?. */
  public final boolean isQuantifierNode() {
    return isKleenePlusRuleNode() || isKleeneStarRuleNode() || isOptionalRuleNode();
  }

  public final boolean isOptionalRuleNode() {
    return nodeType == RuleType.OPTIONAL;
  }

  public final Optional<RuleHierarchyInfo> getAntlrRule() {
    return antlrRule;
  }

  public final String getRuleName() {
    assert this.antlrRule.isPresent() : toString();
    return this.antlrRule.get().getRuleName();
  }

  public final int getLeafTokenCount() {
    return leafTokenCount;
  }

  public ParserRuleSparTreeNode asParserRule() {
    throw new UnsupportedOperationException();
  }

  public LexerRuleSparTreeNode asLexerRule() {
    throw new UnsupportedOperationException();
  }

  /**
   * Update the leaf token count
   *
   * @return
   */
  public int updateLeafTokenCount() {
    if (isTokenNode()) {
      leafTokenCount = 1;
      return leafTokenCount;
    }
    leafTokenCount =
        children.stream()
            .mapToInt(
                child -> {
                  child.updateLeafTokenCount();
                  return child.getLeafTokenCount();
                })
            .sum();
    return leafTokenCount;
  }

  /**
   * Permanently delete this node, and its children recursively.
   *
   * <p>
   *
   * <p>Package-private, so that this can only be called within this package.
   */
  final void delete() {
    if (this.isDeleted) {
      return;
    }

    this.preOrderVisit(
        node -> {
          node.isDeleted = true;
          final List<AbstractSparTreeNode> children = new ArrayList<>(node.children);
          node.children.clear();
          node.expectedAntlrRuleTypesOfChildren.clear();
          assert node.checkNodeIntegrity().isEmpty() : node.checkNodeIntegrity();
          return children;
        });
  }

  public final boolean isPermanentlyDeleted() {
    return isDeleted;
  }

  public final RuleType getNodeType() {
    return nodeType;
  }

  /** package-private. */
  final void cleanDeletedImmediateChildren() {
    assert checkNodeIntegrity().isEmpty() : checkNodeIntegrity();
    final int size = children.size();
    for (int i = 0; i < size; ++i) {
      if (children.get(i).isPermanentlyDeleted()) {
        children.set(i, null);
        expectedAntlrRuleTypesOfChildren.set(i, null);
      }
    }
    Util.removeElementsFromList(children, Objects::isNull);
    Util.removeElementsFromList(expectedAntlrRuleTypesOfChildren, Objects::isNull);
    assert checkNodeIntegrity().isEmpty() : checkNodeIntegrity();
  }

  /** Return the element rule of the kleene rule. For example, E*, E+. The element rule is "E". */
  public RuleHierarchyInfo getKleeneElementRule() {
    assert isKleenePlusRuleNode() || isKleeneStarRuleNode()
        : "The current rule is not a Kleene rule. " + antlrRule;
    assert !expectedAntlrRuleTypesOfChildren.isEmpty()
        : this + "\n" + expectedAntlrRuleTypesOfChildren + "\n" + this.printTreeStructure();
    assert expectedAntlrRuleTypesOfChildren.stream()
                .map(Optional::get)
                .collect(Collectors.toSet())
                .size()
            == 1
        : expectedAntlrRuleTypesOfChildren;
    return expectedAntlrRuleTypesOfChildren.get(0).get();
  }

  @Override
  public final String toString() {
    return MoreObjects.toStringHelper(this)
        .add("id", nodeId)
        .add("parent", parent == null ? "" : parent.toString())
        .toString();
  }

  public final int getNodeId() {
    return nodeId;
  }

  /**
   * Get the parent information of the current node.
   *
   * @return the parent of the current Node.
   */
  @Nullable
  public final ParentInfo getParentInfo() {
    return parent;
  }

  /** Clear the parent of the current node to {@code null}. */
  public final void resetParentToNull() {
    this.parent = null;
  }

  private final void setParent(ParentInfo parent) {
    checkState(
        this.parent == null, "The parent (%s) of this node (%s) has been set.", this.parent, this);
    this.parent = parent;
  }

  /** @return {@code true} if the node has any child. */
  public final boolean hasChildren() {
    return getChildCount() > 0;
  }

  /** Visit each child of this node. */
  public final void forEachChild(Consumer<AbstractSparTreeNode> consumer) {
    children.forEach(consumer);
    //    final int childCount = getChildCount();
    //    for (int i = 0; i < childCount; ++i) {
    //      consumer.accept(getChild(i));
    //    }
  }

  /**
   * Perform breadth-first search from this node. The depth is bounded by the specified parameter.
   *
   * <p>A node below this node (this node is excluded) and above/at the max depth (included) is
   * returned, if
   * <li>it passes the given {@code predicate}
   * <li>and is the first node along the path from this to the node at the max depth.
   */
  public ArrayList<AbstractSparTreeNode> boundedBreadthFirstSearchForFirstQualifiedNodes(
      final Predicate<AbstractSparTreeNode> predicate, final int maxBfsDepth) {

    assert maxBfsDepth > 0 : "The max bfs depth cannot be zero or negative " + maxBfsDepth;

    final ArrayList<AbstractSparTreeNode> result = new ArrayList<>();
    final ArrayDeque<AbstractSparTreeNode> queue = new ArrayDeque<>();
    this.forEachChild(queue::addLast);
    int depth = maxBfsDepth;

    while (!queue.isEmpty() && depth-- > 0) {
      final int queueSize = queue.size(); // Iterate over the nodes on the same level.
      for (int i = 0; i < queueSize; ++i) {
        final AbstractSparTreeNode node = queue.pollFirst();
        if (predicate.test(node)) {
          result.add(node);
          continue;
        }
        if (depth > 0) {
          // Have not reached the
          node.forEachChild(queue::addLast);
        }
      }
    }
    return result;
  }

  public final ImmutableList<AbstractSparTreeNode> copyChildren() {
    return ImmutableList.copyOf(children);
  }

  public final ImmutableList<AbstractSparTreeNode> copyAndReverseChildren() {
    final ImmutableList.Builder<AbstractSparTreeNode> builder = ImmutableList.builder();
    final int length = children.size();
    for (int i = length - 1; i >= 0; --i) {
      builder.add(children.get(i));
    }
    return builder.build();
  }


  /**
   * This method should be only called when a spar-tree is constructed from a Antlr parse tree. Add
   * a child to the current node.
   *
   * <p>
   *
   * <p>Note that the child's parent should be null.
   *
   * @param child, a tree node whose parent is null.
   */
  void addChild(AbstractSparTreeNode child) {
    assert child.getParentInfo() == null
        : "The parent of the parameter " + child + " is not null: " + child.getParentInfo();

    child.setParent(new ParentInfo(asParserRule(), child.getAntlrRule()));
    children.add(child);
    expectedAntlrRuleTypesOfChildren.add(child.getAntlrRule());
    assert checkNodeIntegrity().isEmpty() : checkNodeIntegrity().toString();
  }

  /**
   * Remove a child from the current node.
   *
   * <p>
   *
   * <p>Note that the child's parent must be the current node.
   *
   * @param child, a tree node whose parent is the current node.
   */
  final void removeChild(AbstractSparTreeNode child) {
    checkArgument(
        child.getParentInfo().getNode() == this,
        "The child (%s) is not a child of this node (%s)",
        child,
        this);
    final int index = children.indexOf(child);
    assert index >= 0 : index;
    final AbstractSparTreeNode removedChild = children.remove(index);
    expectedAntlrRuleTypesOfChildren.remove(index);
    child.resetParentToNull();

    assert removedChild == child
        : "The child is not in the child list of this node. Child:" + child + ", This:" + this;
    assert checkNodeIntegrity().isEmpty() : checkNodeIntegrity().toString();
  }

  /**
   * Replace the old child with the new child. The old child should be already in the child list,
   * and the parent of the new child should be null.
   *
   * <p>
   *
   * <p>TODO: need to check whether the newChild is assignable to {@code oldChild}
   *
   * @param oldChild, the existing child to be removed from the list.
   * @param newChild, the new child to be added in the position of the old child.
   */
  public final void replaceChild(AbstractSparTreeNode oldChild, AbstractSparTreeNode newChild) {
    assert checkNodeIntegrity().isEmpty() : checkNodeIntegrity().toString();
    assert newChild.getParentInfo() == null;
    assert oldChild.getParentInfo().getNode() == this;
    final int index = children.indexOf(oldChild);
    assert index >= 0 : index;
    children.set(index, newChild);
    newChild.setParent(oldChild.getParentInfo());
    oldChild.resetParentToNull();

    assert newChild.getParentInfo().getNode() == this;
    assert checkNodeIntegrity().isEmpty() : checkNodeIntegrity().toString();
  }

  /**
   * Traverse the tree with the given visitor.
   *
   * <p>
   *
   * <p>This method is safe to manipulate the children
   */
  public final void preOrderVisit(ISparTreeNodeVisitor visitor) {
    final Stack<AbstractSparTreeNode> stack = new Stack<>();
    stack.push(this);
    while (stack.size() > 0) {
      final AbstractSparTreeNode top = stack.pop();
      final List<AbstractSparTreeNode> childrenToVisit = visitor.visit(top);

      final int childCount = childrenToVisit.size();
      for (int i = childCount - 1; i >= 0; --i) {
        final AbstractSparTreeNode child = childrenToVisit.get(i);
        stack.add(child);
      }
    }
  }

  public abstract LexerRuleSparTreeNode beginToken();

  public abstract LexerRuleSparTreeNode endToken();

  private final ErrorMessage checkNodeIntegrity() {
    final ErrorMessage result = new ErrorMessage();
    if (children.size() != expectedAntlrRuleTypesOfChildren.size()) {
      result.errors.add(
          "The size of children should equale the size of expectedAntlrRuleTypesOfChildren:"
              + children.size()
              + " vs "
              + expectedAntlrRuleTypesOfChildren.size());
    }
    return result;
  }

  @Override
  public boolean equals(Object obj) {
    return this == obj;
  }

  @Override
  public int hashCode() {
    return getNodeId();
  }

  private static final class ErrorMessage {
    private final ArrayList<String> errors = new ArrayList<>();

    public boolean isEmpty() {
      return errors.isEmpty();
    }

    @Override
    public String toString() {
      final StringBuilder builder = new StringBuilder();
      for (int i = 0, size = errors.size(); i < size; ++i) {
        builder.append("Error ").append(i).append(": ").append(errors.get(i)).append('\n');
      }
      return builder.toString();
    }
  }

  public static final class ParentInfo {
    private final ParserRuleSparTreeNode node;
    /**
     * The top Antlr rule type for the child. For example
     *
     * <p>
     *
     * <p>expr ::= '(' expr ')' | constant
     *
     * <p>
     *
     * <p>constant ::= ID | NUMBER
     *
     * <p>
     *
     * <p>Say we have the expression "(1)", the leaf node INTEGER's Antlr rule type is 'constant',
     * its antlrRuleForTheChild should be 'expr',
     */
    private final Optional<RuleHierarchyInfo> antlrRuleForTheChild;

    private ParentInfo(
        ParserRuleSparTreeNode parentNode, Optional<RuleHierarchyInfo> antlrRuleForTheChild) {
      assert parentNode != null;
      this.node = parentNode;
      this.antlrRuleForTheChild = antlrRuleForTheChild;
    }

    @Override
    public String toString() {
      return MoreObjects.toStringHelper("ParentInfo")
          .add("node", node.getNodeId())
          .add(
              "expected_slot_rule",
              antlrRuleForTheChild.map(RuleHierarchyInfo::getRuleName).orElse("Token"))
          .toString();
    }

    public ParserRuleSparTreeNode getNode() {
      return node;
    }

    public Optional<RuleHierarchyInfo> getAntlrRuleForTheChild() {
      return antlrRuleForTheChild;
    }
  }

  /**
   * The statistics of the edit operations performed on this node. This information is used for
   * guiding whether to replace or delete this node during reduction.
   *
   * <p>
   *
   * <p>TODO: to implement and enable.
   */
  public static class EditOperationStatistics {}
}
