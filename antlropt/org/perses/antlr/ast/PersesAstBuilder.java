package org.perses.antlr.ast;

import com.google.common.annotations.VisibleForTesting;
import com.google.common.collect.ImmutableList;
import org.antlr.runtime.RecognitionException;
import org.antlr.runtime.tree.Tree;
import org.antlr.v4.parse.ANTLRParser;
import org.antlr.v4.tool.ast.*;
import org.perses.antlr.AntlrGrammarParser;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

import static com.google.common.base.Preconditions.checkArgument;
import static com.google.common.base.Preconditions.checkState;

public final class PersesAstBuilder {

  private final SymbolTable symbolTable = new SymbolTable();

  public static PersesGrammar loadGrammarFromString(String grammarContent) {
    try {
      return new PersesAstBuilder()
          .buildFromAntlrRootAst(AntlrGrammarParser.parseRawGrammarASTFromString(grammarContent));
    } catch (RecognitionException e) {
      throw new AssertionError(e);
    }
  }

  public PersesGrammar buildFromAntlrRootAst(GrammarRootAST root) {
    checkArgument(root.getChildCount() == 2);

    final Tree firstChild = root.getChild(0);
    checkArgument(firstChild instanceof GrammarAST);
    final String grammarName = ((GrammarAST) firstChild).getToken().getText();

    final Tree secondChild = root.getChild(1);
    checkArgument(secondChild instanceof GrammarAST);
    final GrammarAST rulesAst = (GrammarAST) root.getChild(1);

    final ImmutableList<AbstractPersesRuleDefAst> rules =
        convertRuleDefinitions(rulesAst, symbolTable);
    return new PersesGrammar(grammarName, rules, symbolTable);
  }

  private static ImmutableList<AbstractPersesRuleDefAst> convertRuleDefinitions(
      GrammarAST rulesAst, SymbolTable symbolTable) {
    checkArgument("RULES".equals(rulesAst.getToken().getText()));
    final ImmutableList.Builder<AbstractPersesRuleDefAst> builder = ImmutableList.builder();
    final int childCount = rulesAst.getChildCount();
    for (int i = 0; i < childCount; ++i) {
      final Tree childTree = rulesAst.getChild(i);
      checkState(childTree instanceof RuleAST, "The actual type is %s", childTree.getClass());
      final RuleAST ast = (RuleAST) childTree;
      checkState("RULE".equals(ast.getToken().getText()));
      builder.add(convertRuleDefinition(ast, symbolTable));
    }
    return builder.build();
  }

  private static AbstractPersesRuleDefAst convertRuleDefinition(
      RuleAST ruleAST, SymbolTable symbolTable) {
    final int childCount = ruleAST.getChildCount();
    checkArgument(childCount == 2 || childCount == 3);
    checkArgument(ruleAST.getChild(0) instanceof GrammarAST);
    checkArgument(ruleAST.getChild(childCount - 1) instanceof BlockAST);

    final GrammarAST ruleNameAst = (GrammarAST) ruleAST.getChild(0);
    final RuleNameRegistry.RuleNameHandle ruleNameHandle =
        symbolTable.getRuleNameRegistry().getOrCreate(ruleNameAst.getToken().getText());

    BlockAST ruleBody = (BlockAST) ruleAST.getChild(childCount - 1);

    if (childCount == 3) {
      GrammarAST second = (GrammarAST) ruleAST.getChild(1);
      checkArgument(second.getText().equals("RULEMODIFIERS"));
      checkArgument(second.getChildCount() == 1);
      checkArgument(second.getChild(0).getText().equals("fragment"));

      AbstractPersesRuleElement body = convertAlternativeBlock(ruleBody, symbolTable);
      return new PersesFragmentLexerRuleAst(ruleNameHandle, body);
    }
    checkState(childCount == 2, "Invalid child count: %s", childCount);

    if (!ruleAST.isLexerRule()) {
      AbstractPersesRuleElement body = convertAlternativeBlock(ruleBody, symbolTable);
      return createRuleDef(ruleNameHandle, body);
    }
    if (ruleBody.getChildCount() == 1
        && ((GrammarAST) ruleBody.getChild(0)).getToken().getType()
            == ANTLRParser.LEXER_ALT_ACTION) {
      AltAST lexerAltAction = (AltAST) ruleBody.getChild(0);
      checkState(lexerAltAction.getChildCount() == 2);
      Tree firstChild = lexerAltAction.getChild(0);
      checkState(firstChild instanceof AltAST);
      AbstractPersesRuleElement body = convertSingleAlternative((AltAST) firstChild, symbolTable);
      GrammarAST secondChild = (GrammarAST) lexerAltAction.getChild(1);
      checkState(secondChild.getText().equals("skip"));
      return createRuleDef(ruleNameHandle, new PersesLexerSkipCommandAst(body));
    } else {
      AbstractPersesRuleElement body = convertAlternativeBlock(ruleBody, symbolTable);
      return createRuleDef(ruleNameHandle, body);
    }
  }

  public static AbstractPersesRuleDefAst createRuleDef(
      RuleNameRegistry.RuleNameHandle ruleNameHandle, AbstractPersesRuleElement body) {
    switch (ruleNameHandle.getType()) {
      case KLEENE_PLUS:
      case KLEENE_STAR:
      case OPTIONAL:
      case OTHER_RULE:
      case ALT_BLOCKS:
        return new PersesParserRuleAst(ruleNameHandle, body);
      case TOKEN:
        return new PersesLexerRuleAst(ruleNameHandle, body);
      default:
        throw new RuntimeException("Unhandled rule type: " + ruleNameHandle);
    }
  }

  private static AbstractPersesRuleElement convertAlternativeBlock(
      BlockAST block, SymbolTable symbolTable) {
    final HashSet<Class<?>> childNodeClasses = collectChildNodeClasses(block);
    checkArgument(childNodeClasses.size() == 1, childNodeClasses);
    checkArgument(childNodeClasses.iterator().next().equals(AltAST.class));

    ImmutableList.Builder<AbstractPersesRuleElement> builder = ImmutableList.builder();
    final int childCount = block.getChildCount();
    for (int i = 0; i < childCount; ++i) {
      final AltAST child = (AltAST) block.getChild(i);
      AbstractPersesRuleElement convertedChild = convertSingleAlternative(child, symbolTable);
      if (convertedChild instanceof PersesTokenSetAst
          || convertedChild instanceof PersesAlternativeBlockAst) {
        // Inline the alternative block.
        for (int j = 0, size = convertedChild.getChildCount(); j < size; ++j) {
          builder.add(convertedChild.getChild(j));
        }
      } else {
        builder.add(convertedChild);
      }
    }
    ImmutableList<AbstractPersesRuleElement> alternatives = builder.build();
    checkState(alternatives.size() > 0, alternatives);
    if (alternatives.size() == 1) {
      return alternatives.get(0);
    } else {
      return new PersesAlternativeBlockAst(alternatives);
    }
  }

  private static AbstractPersesRuleElement convertSingleAlternative(
      AltAST ast, SymbolTable symbolTable) {
    final int astTokenType = ast.getToken().getType();
    checkArgument(astTokenType == ANTLRParser.LEXER_ALT_ACTION || astTokenType == ANTLRParser.ALT);
    if (astTokenType == ANTLRParser.LEXER_ALT_ACTION) {
      checkArgument(ast.getChildCount() == 2);
      Tree child = ast.getChild(0);
      checkArgument(
          child instanceof AltAST && ((AltAST) child).getToken().getType() == ANTLRParser.ALT);
      ast = (AltAST) child;
    }

    ArrayList<AbstractPersesRuleElement> children = new ArrayList<>();
    final int childCount = ast.getChildCount();
    for (int i = 0; i < childCount; ++i) {
      AbstractPersesRuleElement convertedChild =
          dispatchConversion((GrammarAST) ast.getChild(i), symbolTable);
      children.add(convertedChild);
    }
    return combineIntoSequence(children);
  }

  public static AbstractPersesRuleElement combineIntoSequence(
      List<AbstractPersesRuleElement> children) {
    if (children.size() == 1) {
      return children.get(0);
    }
    ImmutableList.Builder<AbstractPersesRuleElement> builder = ImmutableList.builder();
    for (AbstractPersesRuleElement child : children) {
      final AstTag tag = child.getTag();
      if (tag == AstTag.EPSILON) {
        continue;
      }
      if (tag == AstTag.SEQUENCE) {
        child.foreachChildRuleElement(builder::add);
      } else {
        builder.add(child);
      }
    }
    ImmutableList<AbstractPersesRuleElement> processedChildren = builder.build();
    checkState(processedChildren.size() > 0);
    if (processedChildren.size() == 1) {
      return processedChildren.get(0);
    }
    return new PersesSequenceAst(processedChildren);
  }

  @VisibleForTesting
  static PersesRuleReferenceAst convertRuleRefAst(RuleRefAST ruleRefAst, SymbolTable symbolTable) {
    final RuleNameRegistry.RuleNameHandle ruleNameHandle =
        symbolTable.getRuleNameRegistry().getOrCreate(ruleRefAst.getToken().getText());
    return new PersesRuleReferenceAst(ruleNameHandle);
  }

  static PersesOptionalAst convertOptionalBlockAst(OptionalBlockAST ast, SymbolTable symbolTable) {
    final AbstractPersesRuleElement body = checkAndConvertBodyOfQuantifiedBlock(ast, symbolTable);
    return ast.isGreedy()
        ? PersesOptionalAst.createGreedy(body)
        : PersesOptionalAst.createNonGreedy(body);
  }

  static PersesStarAst convertStarBlockAst(StarBlockAST ast, SymbolTable symbolTable) {
    final AbstractPersesRuleElement body = checkAndConvertBodyOfQuantifiedBlock(ast, symbolTable);
    return ast.isGreedy() ? PersesStarAst.createGreedy(body) : PersesStarAst.createNonGreedy(body);
  }

  static PersesPlusAst convertPlusBlockAst(PlusBlockAST ast, SymbolTable symbolTable) {
    final AbstractPersesRuleElement body = checkAndConvertBodyOfQuantifiedBlock(ast, symbolTable);
    return ast.isGreedy() ? PersesPlusAst.createGreedy(body) : PersesPlusAst.createNonGreedy(body);
  }

  private static AbstractPersesRuleElement checkAndConvertBodyOfQuantifiedBlock(
      GrammarAST ast, SymbolTable symbolTable) {
    checkArgument(ast.getChildCount() == 1);
    checkArgument(ast.getChild(0) instanceof BlockAST);
    BlockAST block = (BlockAST) ast.getChild(0);
    return dispatchConversion(block, symbolTable);
  }

  private static AbstractPersesRuleElement convertTerminalSetAst(GrammarAST ast) {
    checkArgument(isTerminalSetAst(ast), "Unhandled ast: %s, %s", ast, ast.getClass());
    checkArgument(ast.getToken().getText().equals("SET"));

    ImmutableList.Builder<AbstractPersesTerminalAst> builder = ImmutableList.builder();
    final int childCount = ast.getChildCount();
    for (int i = 0; i < childCount; ++i) {
      final GrammarAST child = (GrammarAST) ast.getChild(i);
      if (child instanceof TerminalAST) {
        TerminalAST terminal = (TerminalAST) child;
        builder.add(new PersesTerminalAst(terminal.getText(), terminal.getToken().getType()));
      } else if (PersesLexerCharSet.isLexerCharSet(child)) {
        builder.add(new PersesLexerCharSet(child.getText()));
      } else {
        throw new RuntimeException("Unreachable. " + child);
      }
    }
    ImmutableList<AbstractPersesTerminalAst> terminals = builder.build();
    checkState(terminals.size() > 0);
    if (terminals.size() == 1) {
      return terminals.get(0);
    } else {
      return new PersesTokenSetAst(terminals);
    }
  }

  private static PersesNotAst convertNotAst(NotAST notAST, SymbolTable symbolTable) {
    checkArgument(notAST.getChildCount() == 1);
    Tree child = notAST.getChild(0);
    checkArgument(child instanceof GrammarAST);
    GrammarAST childAst = (GrammarAST) child;
    checkArgument(isTerminalSetAst(childAst));
    AbstractPersesRuleElement tokens = dispatchConversion(childAst, symbolTable);
    return new PersesNotAst(tokens);
  }

  @VisibleForTesting
  static AbstractPersesRuleElement dispatchConversion(GrammarAST ast, SymbolTable symbolTable) {
    if (ast instanceof TerminalAST) {
      TerminalAST terminal = (TerminalAST) ast;
      return new PersesTerminalAst(terminal.getText(), terminal.getToken().getType());
    }
    if (ast instanceof RuleRefAST) {
      return convertRuleRefAst((RuleRefAST) ast, symbolTable);
    }
    if (ast instanceof OptionalBlockAST) {
      return convertOptionalBlockAst((OptionalBlockAST) ast, symbolTable);
    }
    if (ast instanceof PlusBlockAST) {
      return convertPlusBlockAst((PlusBlockAST) ast, symbolTable);
    }
    if (ast instanceof StarBlockAST) {
      return convertStarBlockAst((StarBlockAST) ast, symbolTable);
    }
    if (ast instanceof BlockAST) {
      return convertAlternativeBlock((BlockAST) ast, symbolTable);
    }
    if (ast instanceof ActionAST) {
      return PersesActionAst.INSTANCE;
    }
    if (isTerminalSetAst(ast)) {
      return convertTerminalSetAst(ast);
    }
    if (ast instanceof NotAST) {
      return convertNotAst((NotAST) ast, symbolTable);
    }
    if (PersesEpsilonAst.isEpsilonAst(ast)) {
      return PersesEpsilonAst.INSTANCE;
    }
    if (PersesLexerCharSet.isLexerCharSet(ast)) {
      return new PersesLexerCharSet(ast.getText());
    }
    throw new RuntimeException("Unhandled ast: " + ast + ", " + ast.getClass());
  }

  private static boolean isTerminalSetAst(GrammarAST ast) {
    if (ast instanceof SetAST) {
      return true;
    }
    if (ast.getToken().getType() == ANTLRParser.SET) {
      return true;
    }
    return false;
  }

  private static HashSet<Class<?>> collectChildNodeClasses(BlockAST ast) {
    HashSet<Class<?>> childNodeClasses = new HashSet<>();
    final int childCount = ast.getChildCount();
    for (int i = 0; i < childCount; ++i) {
      childNodeClasses.add(ast.getChild(i).getClass());
    }
    return childNodeClasses;
  }
}
