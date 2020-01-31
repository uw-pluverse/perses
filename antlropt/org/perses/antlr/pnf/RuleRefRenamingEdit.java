package org.perses.antlr.pnf;

import org.perses.antlr.ast.*;

import java.util.ArrayList;
import java.util.Map;
import java.util.Optional;

public class RuleRefRenamingEdit extends AstEdit {

  public static void renameDefMap(
      MutableRuleDefMap defMap,
      RuleNameRegistry.RuleNameHandle oldName,
      RuleNameRegistry.RuleNameHandle newName) {
    RuleRefRenamingEdit edit = new RuleRefRenamingEdit(oldName, newName);
    ArrayList<RuleEditTriple> ruleEditTriples = new ArrayList<>();
    for (Map.Entry<RuleNameRegistry.RuleNameHandle, AbstractPersesRuleElement> entry :
        defMap.entries()) {
      Optional<AbstractPersesRuleElement> result = edit.apply(entry.getValue());
      if (result.isPresent()) {
        ruleEditTriples.add(new RuleEditTriple(entry.getKey(), entry.getValue(), result.get()));
      }
    }
    ruleEditTriples.forEach(triple -> triple.applyTo(defMap));
  }

  private final RuleNameRegistry.RuleNameHandle oldName;
  private final RuleNameRegistry.RuleNameHandle newName;

  public RuleRefRenamingEdit(
      RuleNameRegistry.RuleNameHandle oldName, RuleNameRegistry.RuleNameHandle newName) {
    this.oldName = oldName;
    this.newName = newName;
  }

  @Override
  public Optional<AbstractPersesRuleElement> internalApply(
      AbstractPersesRuleElement element, boolean isRoot) {
    if (element.getTag() != AstTag.RULE_REF) {
      return Optional.empty();
    }
    PersesRuleReferenceAst ref = (PersesRuleReferenceAst) element;
    RuleNameRegistry.RuleNameHandle name = ref.getRuleNameHandle();
    if (!name.equals(oldName)) {
      return Optional.empty();
    }
    return Optional.of(new PersesRuleReferenceAst(newName));
  }
}
