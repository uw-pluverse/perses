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
