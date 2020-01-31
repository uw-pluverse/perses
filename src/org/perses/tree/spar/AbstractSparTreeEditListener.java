package org.perses.tree.spar;

import org.perses.program.TokenizedProgram;

public abstract class AbstractSparTreeEditListener {

  public static final class SparTreeEditEvent {
    private final AbstractSparTreeEdit edit;

    public SparTreeEditEvent(AbstractSparTreeEdit edit) {
      this.edit = edit;
    }

    public TokenizedProgram getProgram() {
      return edit.getProgram();
    }
  }

  public abstract void onAfterSparTreeEditApplied(SparTreeEditEvent event);
}
