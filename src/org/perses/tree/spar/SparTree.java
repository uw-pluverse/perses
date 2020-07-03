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

import com.google.common.annotations.VisibleForTesting;
import com.google.common.base.Preconditions;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.Iterables;
import org.checkerframework.checker.nullness.qual.Nullable;
import org.perses.antlr.RuleType;
import org.perses.program.PersesToken;
import org.perses.program.TokenizedProgram;
import org.perses.program.TokenizedProgramFactory;

import java.util.*;
import java.util.function.Consumer;

/** A spar-tree, the primary data structure for the Perses program reduction. */
public final class SparTree extends AbstractUnmodifiableSparTree {

  private static int globalTreeIdGenerator;

  private final int treeId;
  private final int originalTokenCount;
  private final AbstractSparTreeNode root;
  private final LexerRuleSparTreeNode dummyTokenHead;
  private final LexerRuleSparTreeNode dummyTokenTail;
  private final TokenizedProgramFactory tokenizedProgramFactory;

  private TokenizedProgram program;
  private final ArrayList<AbstractSparTreeEditListener> editListeners;

  SparTree(AbstractSparTreeNode root, TokenizedProgramFactory tokenizedProgramFactory) {
    this.tokenizedProgramFactory = tokenizedProgramFactory;
    treeId = ++globalTreeIdGenerator;
    this.root = root;

    dummyTokenHead = new LexerRuleSparTreeNode(Integer.MIN_VALUE, null, null, Optional.empty());
    dummyTokenTail = new LexerRuleSparTreeNode(Integer.MIN_VALUE, null, null, Optional.empty());
    linkLeaves(dummyTokenHead, dummyTokenTail);
    buildTokenIntervalInfo(root);

    editListeners = new ArrayList<>();
    program = computeTokenizedProgram();
    originalTokenCount = program.tokenCount();

    registerSparTreeEditListener(
        new AbstractSparTreeEditListener() {
          @Override
          public void onAfterSparTreeEditApplied(SparTreeEditEvent event) {
            program = event.getProgram();
            assert program.getTokens().equals(SparTree.this.computeTokenizedProgram().getTokens());
          }
        });
  }

  public int getOriginalTokenCount() {
    return originalTokenCount;
  }

  public TokenizedProgramFactory getTokenizedProgramFactory() {
    return tokenizedProgramFactory;
  }

  @Override
  public final AbstractSparTreeNode getRoot() {
    return root;
  }

  /**
   * Create an edit of this spar-tree. Any modification to the edit is not materialized on this
   * tree.
   */
  public final NodeDeletionTreeEdit createNodeDeletionEdit(NodeDeletionActionSet actionSet) {
    assert !actionSet.isEmpty();
    return AbstractSparTreeEdit.createDeletionSparTreeEdit(this, actionSet);
  }

//  public final NodeDeletionTreeEdit createNodeDeletionEditByDeletingNode(
//      AbstractSparTreeNode node) {
//    final NodeDeletionActionSet actionSet = NodeDeletionActionSet.createByDeleteSingleNode(node);
//    return createNodeDeletionEdit(actionSet);
//  }

//  public final NodeReplacementTreeEdit createNodeReplacementEditByReplacingNode(
//      AbstractSparTreeNode targetNode, AbstractSparTreeNode replacingNode) {
//    return createNodeReplacementEdit(
//        ChildHoistingActionSet.createByReplacingSingleNode(targetNode, replacingNode));
//  }

//  public final NodeReplacementTreeEdit createNodeReplacementEditByReplacingNode(
//      ChildHoistingAction action) {
//    return createNodeReplacementEdit(ChildHoistingActionSet.createByReplacingSingleNode(action));
//  }

  public NodeReplacementTreeEdit createNodeReplacementEdit(ChildHoistingActionSet actionSet) {
    return AbstractSparTreeEdit.createReplacementSparTreeEdit(this, actionSet);
  }

  public synchronized void applyEdit(AbstractSparTreeEdit treeEdit) {
    if (treeEdit instanceof NodeReplacementTreeEdit) {
      applyNodeReplacementTreeEdit(treeEdit.asNodeReplacementEdit());
    } else if (treeEdit instanceof NodeDeletionTreeEdit) {
      applyNodeDeletionTreeEdit(treeEdit.asNodeDeleteEdit());
    } else {
      throw new RuntimeException("Unhandled tree edit. " + treeEdit);
    }

    final AbstractSparTreeEditListener.SparTreeEditEvent event =
        new AbstractSparTreeEditListener.SparTreeEditEvent(treeEdit);
    editListeners.forEach(listener -> listener.onAfterSparTreeEditApplied(event));
  }

  private void applyNodeDeletionTreeEdit(NodeDeletionTreeEdit deletionEdit) {
    final ImmutableList<NodeDeletionAction> actions = deletionEdit.getActions();
    final HashSet<AbstractSparTreeNode.ParentInfo> parents = new HashSet<>();
    for (NodeDeletionAction action : actions) {
      final AbstractSparTreeNode targetNode = action.getTargetNode();
      targetNode.delete();
      fixLeafLinkByDeleting(targetNode.beginToken(), targetNode.endToken().getNext());
      parents.add(targetNode.getParentInfo());
    }
    for (AbstractSparTreeNode.ParentInfo parent : parents) {
      parent.getNode().cleanDeletedImmediateChildren();
    }
    boolean changed;
    do {
      changed = false;
      for (AbstractSparTreeNode.ParentInfo parent : parents) {
        if (updateTokenIntervalUpToRoot(parent)) {
          changed = true;
        }
      }
    } while (changed);
  }

  private void applyNodeReplacementTreeEdit(NodeReplacementTreeEdit replacement) {
    final ChildHoistingAction action = Iterables.getOnlyElement(replacement.getActions());
    final AbstractSparTreeNode targetNode = action.getTargetNode();

    final AbstractSparTreeNode childToHoist = action.getReplacingChild();
    childToHoist.getParentInfo().getNode().removeChild(childToHoist);
    assert childToHoist.getParentInfo() == null;
    targetNode.getParentInfo().getNode().replaceChild(targetNode, childToHoist);
    assert targetNode.getParentInfo() == null;
    targetNode.delete();

    fixLeafLinkByDeleting(targetNode.beginToken(), childToHoist.beginToken());
    fixLeafLinkByDeleting(childToHoist.endToken().getNext(), targetNode.endToken().getNext());
    updateTokenIntervalUpToRoot(childToHoist.getParentInfo());
  }

  private static void fixLeafLinkByDeleting(
      LexerRuleSparTreeNode leftInclusive, LexerRuleSparTreeNode rightExclusive) {
    if (leftInclusive == rightExclusive) {
      return;
    }
    final LexerRuleSparTreeNode prevLeftInclusive = leftInclusive.getPrev();
    rightExclusive.resetPrev();
    prevLeftInclusive.resetNext();
    prevLeftInclusive.setNext(rightExclusive);
    rightExclusive.setPrev(prevLeftInclusive);
  }

  private boolean updateTokenIntervalUpToRoot(AbstractSparTreeNode.ParentInfo nodeInfo) {
    boolean globalChanged = false;
    while (nodeInfo != null) {
      final ParserRuleSparTreeNode node = nodeInfo.getNode().asParserRule();
      boolean changed = false;
      final LexerRuleSparTreeNode leftmostToken = getLeftmostToken(node);
      if (node.beginToken() != leftmostToken) {
        node.setBeginToken(leftmostToken);
        changed = true;
      }
      final LexerRuleSparTreeNode rightmostToken = getRightmostToken(node);
      if (node.endToken() != rightmostToken) {
        node.setEndToken(rightmostToken);
        changed = true;
      }
      if (!changed) {
        break;
      }
      globalChanged = true;
      nodeInfo = node.getParentInfo();
    }
    return globalChanged;
  }

  @Nullable
  private LexerRuleSparTreeNode getLeftmostToken(ParserRuleSparTreeNode node) {
    final int size = node.getChildCount();
    for (int i = 0; i < size; ++i) {
      final AbstractSparTreeNode child = node.getChild(i);
      final LexerRuleSparTreeNode leftToken = child.beginToken();
      if (leftToken != null) {
        return leftToken;
      }
    }
    return null;
  }

  @Nullable
  private LexerRuleSparTreeNode getRightmostToken(ParserRuleSparTreeNode node) {
    final int size = node.getChildCount();
    for (int i = size - 1; i >= 0; --i) {
      final AbstractSparTreeNode child = node.getChild(i);
      final LexerRuleSparTreeNode rightToken = child.endToken();
      if (rightToken != null) {
        return rightToken;
      }
    }
    return null;
  }

  public final void registerSparTreeEditListeners(List<AbstractSparTreeEditListener> listeners) {
    listeners.forEach(this::registerSparTreeEditListener);
  }

  public final void registerSparTreeEditListener(AbstractSparTreeEditListener listener) {
    Preconditions.checkArgument(!editListeners.contains(listener));
    editListeners.add(listener);
  }

  public void visitRemainingTokens(Consumer<LexerRuleSparTreeNode> consumer) {
    LexerRuleSparTreeNode node = dummyTokenHead.getNext();
    while (node != dummyTokenTail) {
      assert !node.isPermanentlyDeleted();
      consumer.accept(node);
      node = node.getNext();
    }
  }

  private void buildTokenIntervalInfo(AbstractSparTreeNode node) {
    if (node instanceof LexerRuleSparTreeNode) {
      return;
    }
    final int count = node.getChildCount();
    if (count == 0) {
      return;
    }
    for (int i = 0; i < count; ++i) {
      buildTokenIntervalInfo(node.getChild(i));
    }
    final ParserRuleSparTreeNode parserNode = node.asParserRule();
    parserNode.setBeginToken(getLeftmostToken(parserNode));
    parserNode.setEndToken(getRightmostToken(parserNode));
  }

  /**
   * This operation is expensive. It scans the entire tree to find the node. Be careful when you
   * call this API.
   *
   * <p>This API should be only used in testing, and should be replaced with {@link
   * org.perses.TestUtility#getNodeWithTokens(SparTree, ImmutableList, String)}
   */
  @VisibleForTesting
  public final Optional<AbstractSparTreeNode> getNodeByTreeScanForId(final int id) {
    class NodeRetriever implements ISparTreeNodeVisitor {
      AbstractSparTreeNode node;

      @Override
      public List<AbstractSparTreeNode> visit(AbstractSparTreeNode node) {
        if (node.getNodeId() == id) {
          this.node = node;
          return ImmutableList.of();
        }
        return node.getImmutableChildView();
      }
    }
    final NodeRetriever retriever = new NodeRetriever();
    root.preOrderVisit(retriever);
    return Optional.ofNullable(retriever.node);
  }

  /** The returned program might be stale if this tree is modified later. */
  public TokenizedProgram getProgramSnapshot() {
    assert program
        .getTokens()
        .equals(computeTokenizedProgram().getTokens()); // This assertion may be slow.
    return program;
  }

  public TokenizedProgram customizeProgram(AbstractTokenizedProgramCustomizer customizer) {
    root.preOrderVisit(customizer);
    return new TokenizedProgram(customizer.getResult());
  }

  public void updateLeafTokenCount() {
    root.updateLeafTokenCount();
  }

  public final void printTreeStructureToStdout() {
    System.out.println(printTreeStructure());
  }

  public final String printTreeStructure() {
    return root.printTreeStructure();
  }

  public int getTreeId() {
    return treeId;
  }

  private final void linkLeaves(
      final LexerRuleSparTreeNode dummyTokenHead, final LexerRuleSparTreeNode dummyTokenTail) {
    assert this.root != null : "The root cannot be null";
    final ArrayList<LexerRuleSparTreeNode> nodes = new ArrayList<>(5000);
    nodes.add(dummyTokenHead);
    this.root.preOrderVisit(
        node -> {
          if (node.isPermanentlyDeleted()) {
            return Collections.emptyList();
          }
          if (node.getNodeType().equals(RuleType.TOKEN)) {
            nodes.add((LexerRuleSparTreeNode) node);
            return Collections.emptyList();
          }
          return node.getImmutableChildView();
        });
    nodes.add(dummyTokenTail);
    final int size = nodes.size();
    assert size >= 2;
    for (int i = 1; i < size; ++i) {
      final LexerRuleSparTreeNode prev = nodes.get(i - 1);
      final LexerRuleSparTreeNode curr = nodes.get(i);
      prev.setNext(curr);
      curr.setPrev(prev);
    }
  }

  private final TokenizedProgram computeTokenizedProgram() {
    final ImmutableList.Builder<PersesToken> builder = ImmutableList.builder();
    visitRemainingTokens(
        node -> {
          builder.add(node.getToken());
        });
    return new TokenizedProgram(builder.build());
  }
}
