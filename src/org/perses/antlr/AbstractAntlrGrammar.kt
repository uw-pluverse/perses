package org.perses.antlr

import com.google.common.collect.ImmutableList
import org.perses.antlr.ast.AbstractPersesRuleDefAst
import org.perses.antlr.ast.PersesGrammar

abstract class AbstractAntlrGrammar {

  abstract val isCombined: Boolean

  abstract fun getCombinedRules(): ImmutableList<AbstractPersesRuleDefAst>

  open fun asCombined(): CombinedAntlrGrammar {
    check(isCombined)
    throw UnsupportedOperationException()
  }

  open fun asSeparate(): SeparateAntlrGrammar {
    check(!isCombined)
    throw UnsupportedOperationException()
  }

  class CombinedAntlrGrammar(val grammar: PersesGrammar)
    : AbstractAntlrGrammar() {

    override val isCombined = true

    init {
      require(grammar.grammarType == PersesGrammar.GrammarType.COMBINED)
    }

    override fun getCombinedRules() = grammar.rules;

    override fun asCombined() = this
  }

  class SeparateAntlrGrammar(val parserGrammar: PersesGrammar, val lexerGrammar: PersesGrammar)
    : AbstractAntlrGrammar() {

    override val isCombined = false

    init {
      require(parserGrammar.grammarType == PersesGrammar.GrammarType.PARSER)
      require(lexerGrammar.grammarType == PersesGrammar.GrammarType.LEXER)
    }

    override fun getCombinedRules(): ImmutableList<AbstractPersesRuleDefAst> {
      val builder = ImmutableList.builderWithExpectedSize<AbstractPersesRuleDefAst>(
        parserGrammar.rules.size + lexerGrammar.rules.size)
      builder.addAll(parserGrammar.rules)
      builder.addAll(lexerGrammar.rules)
      return builder.build()
    }

    override fun asSeparate() = this
  }

}