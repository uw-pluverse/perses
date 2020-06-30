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
