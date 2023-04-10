/*
 * Copyright (C) 2018-2022 University of Waterloo.
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
package org.perses.antlr.pnf

import com.google.common.base.Stopwatch
import com.google.common.collect.ImmutableList
import com.google.common.flogger.FluentLogger
import org.perses.antlr.ast.PersesGrammar
import org.perses.antlr.pnf.PnfGrammarChecker.Companion.validateIntermediateGrammar
import org.perses.util.ktInfo
import java.util.concurrent.TimeUnit

class PnfPassManager {

  abstract class Listener {
    open fun start(grammar: PersesGrammar, startRuleName: String) {}
    open fun beforePass(grammar: PersesGrammar, passClass: Class<*>, iteration: Int) {}
    open fun afterPass(grammar: PersesGrammar, passClass: Class<*>, iteration: Int) {}
  }

  fun process(
    origGrammar: PersesGrammar,
    startRuleName: String,
    lexerGramamr: PersesGrammar?,
    vararg listeners: Listener,
  ): PersesGrammar {
    var currentGrammar = origGrammar
    val allListeners = ImmutableList
      .builder<Listener>()
      .add(*listeners)
      .add(LoggingListener())
      .build()
    allListeners.forEach { it.start(origGrammar, startRuleName) }
    for (i in 0..19) {
      val iterationBefore = currentGrammar
      for (pass in createPasses(startRuleName)) {
        for (listener in allListeners) {
          listener.beforePass(currentGrammar, pass.javaClass, i)
        }

        val grammarBefore = currentGrammar
        currentGrammar = pass.processParserGrammar(currentGrammar, lexerGramamr)

        validateIntermediateGrammar(
          currentGrammar,
          pass.javaClass,
          grammarBefore,
          lexerGramamr,
        )
        for (listener in allListeners) {
          listener.afterPass(currentGrammar, pass.javaClass, i)
        }
      }
      if (currentGrammar.isEquivalent(iterationBefore)) {
        break
      }
    }
    // The following passes are intended to run only once.
    sequenceOf(
      ConvertAllAltToRuleReferenceOrTerminalPass(),
      PnfCheckPass(),
    ).forEach { pass ->
      currentGrammar = pass.processParserGrammar(currentGrammar, lexerGramamr)
    }
    // TODO: enable the following passes when pnd refactoring is done.
    //    final NormalizeRuleNamePass renamingPass = new NormalizeRuleNamePass(startRuleName);
    //    after = renamingPass.process(after);
    //    final PnfCheckPass pnfCheckPass = new PnfCheckPass();
    //    after = pnfCheckPass.process(after);
    return currentGrammar
  }

  private fun createPasses(startRuleName: String): ArrayList<AbstractPnfPass> {
    val result = ArrayList<AbstractPnfPass>()
    result.add(AssociativityParserRuleEliminatorPass())
    result.add(QuantifiedAstNormalizationPass())
    result.add(IndirectLeftRecursionEliminationPass())
    result.add(StarLeftIntroducerPass())
    result.add(PlusIntroducerLeftPass())
    result.add(OptionalIntroducerPass())
    result.add(MultiAltBlockExtractionPass())
    result.add(InlineSingleUseAltRulePass())
    result.add(EliminateEpsilonPass())
    // TODO: need to study why right recursion is hard to eliminate. Currently this is toooo slow.
    //    result.add(new IndirectRightRecursionEliminationPass());
    //    result.add(new StarRightIntroducerPass());
    //    result.add(new PlusIntroducerLeftPass());
    //    result.add(new OptionalIntroducerPass());
    result.add(EliminateUnreachableRulePass(startRuleName))
    result.add(DuplicateRuleEliminationPass(startRuleName))
    result.add(OutlineAltBlockPass())
    return result
  }

  private class LoggingListener : Listener() {

    private val stopwatch = Stopwatch.createUnstarted()

    override fun start(grammar: PersesGrammar, startRuleName: String) {
      logger.ktInfo {
        "Starting to process grammar ${grammar.grammarName} with start rule $startRuleName"
      }
    }

    override fun beforePass(grammar: PersesGrammar, passClass: Class<*>, iteration: Int) {
      stopwatch.reset().start()
      logger.ktInfo { "Pass $passClass at iteration $iteration" }
    }

    override fun afterPass(grammar: PersesGrammar, passClass: Class<*>, iteration: Int) {
      logger.ktInfo { "Pass $passClass takes ${stopwatch.elapsed(TimeUnit.SECONDS)} seconds." }
    }
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
  }
}
