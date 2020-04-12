package org.perses.antlr.ast;

// TODO: I should deprecate this class. This default visitor might makes subclass error-prone to
//      miss some cases.
public class DefaultAstVisitor extends AbstractAstVisitor {

  @Override
  protected void visit(PersesTokenSetAst ast) {}

  @Override
  protected void visit(PersesRangeAst ast) {}

  @Override
  protected void visit(PersesTerminalAst ast) {}

  @Override
  protected void visit(PersesSequenceAst ast) {}

  @Override
  protected void visit(PersesPlusAst ast) {}

  @Override
  protected void visit(PersesStarAst ast) {}

  @Override
  protected void visit(PersesOptionalAst ast) {}

  @Override
  protected void visit(PersesNotAst ast) {}

  @Override
  protected void visit(PersesLexerSkipCommandAst ast) {}

  @Override
  protected void visit(PersesLexerChannelCommandAst ast) {}

  @Override
  protected void visit(PersesLexerCharSet ast) {}

  @Override
  protected void visit(PersesEpsilonAst ast) {}

  @Override
  protected void visit(PersesAlternativeBlockAst ast) {}

  @Override
  protected void visit(PersesActionAst ast) {}

  @Override
  protected void visit(PersesFragmentLexerRuleAst ast) {}

  @Override
  protected void visit(PersesParserRuleAst ast) {}

  @Override
  protected void visit(PersesLexerRuleAst ast) {}

  @Override
  protected void visit(PersesRuleReferenceAst ast) {}

  @Override
  protected void visit(PersesGrammar ast) {}
}
