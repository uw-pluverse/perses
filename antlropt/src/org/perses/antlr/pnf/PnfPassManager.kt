/*
 * Copyright (C) 2018-2026 University of Waterloo.
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
import org.perses.antlr.pnf.PnfGrammarChecker.Companion.checkAntlrAcceptsTheGrammar
import org.perses.antlr.pnf.PnfGrammarChecker.Companion.validateIntermediateGrammar
import org.perses.util.ktInfo
import java.util.concurrent.TimeUnit

class PnfPassManager(
  val repetitivePassCreator: (
    startRuleName: String,
  ) -> ImmutableList<AbstractPnfPass> = ::createDefaultRepetitivePasses,
  val finalizingPassCreator: () -> ImmutableList<AbstractPnfPass> = ::createDefaultFinalizingPasses,
) {
  abstract class Listener {
    open fun start(
      grammar: GrammarPair,
      startRuleName: String,
    ) {}

    open fun beforePass(
      grammar: GrammarPair,
      passClass: Class<*>,
      iteration: Int,
    ) {}

    open fun afterPass(
      grammar: GrammarPair,
      passClass: Class<*>,
      iteration: Int,
    ) {}
  }

  fun process(
    origGrammar: GrammarPair,
    startRuleName: String,
    vararg listeners: Listener,
  ): GrammarPair {
    logger.ktInfo { "Checking whether the original grammar can be accepted by Antlr." }
    checkAntlrAcceptsTheGrammar(origGrammar)
    var currentGrammar = origGrammar
    val allListeners =
      ImmutableList
        .builder<Listener>()
        .add(*listeners)
        .add(LoggingListener())
        .build()
    allListeners.forEach { it.start(origGrammar, startRuleName) }
    var converged = false
    for (i in 0 until MAX_ITERATIONS) {
      val iterationBefore = currentGrammar
      for (pass in repetitivePassCreator(startRuleName)) {
        for (listener in allListeners) {
          listener.beforePass(currentGrammar, pass.javaClass, i)
        }

        val grammarBefore = currentGrammar
        currentGrammar = pass.processGrammar(currentGrammar)

        validateIntermediateGrammar(
          currentGrammar,
          pass.javaClass,
          grammarBefore,
        )
        for (listener in allListeners) {
          listener.afterPass(currentGrammar, pass.javaClass, i)
        }
      }
      if (currentGrammar.isEquivalentTo(iterationBefore)) {
        converged = true
        break
      }
    }
    // Every shipped grammar converges within 4 iterations. Hitting the cap means a pair of
    // passes is undoing each other's work, and emitting the 20th iteration would hide that.
    check(converged) {
      "PNF normalization did not converge after $MAX_ITERATIONS iterations " +
        "for start rule $startRuleName"
    }
    // The following passes are intended to run only once.
    finalizingPassCreator().forEach { pass ->
      currentGrammar = pass.processGrammar(currentGrammar)
    }
    return currentGrammar
  }

  private class LoggingListener : Listener() {
    private val stopwatch = Stopwatch.createUnstarted()

    override fun start(
      grammar: GrammarPair,
      startRuleName: String,
    ) {
      logger.ktInfo {
        val grammarName =
          grammar.grammarSequence().joinToString(separator = ",") {
            it.grammarName
          }
        "Starting to process grammar $grammarName with start rule $startRuleName"
      }
    }

    override fun beforePass(
      grammar: GrammarPair,
      passClass: Class<*>,
      iteration: Int,
    ) {
      stopwatch.reset().start()
      logger.ktInfo { "Pass $passClass at iteration $iteration" }
    }

    override fun afterPass(
      grammar: GrammarPair,
      passClass: Class<*>,
      iteration: Int,
    ) {
      logger.ktInfo { "Pass $passClass takes ${stopwatch.elapsed(TimeUnit.SECONDS)} seconds." }
    }
  }

  companion object {
    private val logger = FluentLogger.forEnclosingClass()
    private const val MAX_ITERATIONS = 20

    fun createDefaultFinalizingPasses(): ImmutableList<AbstractPnfPass> =
      ImmutableList.of(
        ConvertAllAltToRuleReferenceOrTerminalPass(),
        PnfCheckPass(),
      )

    fun createDefaultRepetitivePasses(startRuleName: String): ImmutableList<AbstractPnfPass> {
      val result = ImmutableList.builder<AbstractPnfPass>()
      result.add(RemoveUnusedLabelPass())
      result.add(AssociativityParserRuleEliminatorPass())
      result.add(QuantifiedAstNormalizationPass())
      result.add(IndirectLeftRecursionEliminationPass())
      result.add(StarLeftIntroducerPass())
      // To fix the bug #771
      result.add(StarRightIntroducerPass())
      result.add(PlusIntroducerLeftPass())
      result.add(OptionalIntroducerPass())
      result.add(MultiAltBlockExtractionPass())
      result.add(InlineSingleUseAltRulePass())
      result.add(EliminateEpsilonPass())
      // The right-recursion counterpart of the passes above is intentionally not run:
      //   IndirectRightRecursionEliminationPass()
      //   PlusIntroducerLeftPass()
      //   OptionalIntroducerPass()
      // Measured on all shipped grammars (2026-08-21), the rightmost-transition SCCs that
      // survive this pipeline are small (median ~4 rules, max 24 in SystemVerilog) and fall
      // into three shapes: statement nesting (`if (...) stmt`, `label: stmt`), prefix or
      // right-assoc chains (`unaryOperator castExpression`, `?:`, type constructors), and
      // direct recursion hidden under a trailing optional (`a : Y (Z a)?`). The first two
      // are nestings that node replacement already collapses; inlining through their SCCs
      // would merge rule boundaries without exposing lists. Only the third shape is
      // list-like, and StarRightIntroducerPass handles it by seeing through the optional.
      result.add(EliminateUnreachableRulePass(startRuleName))
      result.add(DuplicateRuleEliminationPass(startRuleName))
      result.add(OutlineAltBlockPass())
      return result.build()
    }
  }
}
