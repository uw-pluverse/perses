package org.perses.reduction;

import com.google.common.collect.ImmutableList;
import org.perses.tree.spar.ChildHoistingAction;

public abstract class AbstractActionSetProfiler {


  public static final AbstractActionSetProfiler NULL_PROFILER = new AbstractActionSetProfiler() {
    @Override
    public void onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren(ImmutableList<ChildHoistingAction> kleeneReplacements) {

    }
  };

  public abstract void onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren(ImmutableList<ChildHoistingAction> kleeneReplacements);

  public static final class ActionSetProfiler extends AbstractActionSetProfiler {



    @Override
    public void onReplaceKleeneQualifiedNodeWithKleeneQualifiedChildren(ImmutableList<ChildHoistingAction> kleeneReplacements) {

    }
  }
}
