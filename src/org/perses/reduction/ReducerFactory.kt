/*
 * Copyright (C) 2018-2025 University of Waterloo.
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
package org.perses.reduction

import com.google.common.base.Strings
import com.google.common.collect.ImmutableSet
import com.google.common.flogger.FluentLogger
import org.perses.reduction.reducer.NonSyntacticSingleTreeNodeReducer
import org.perses.reduction.reducer.PersesNodeBfsReducer
import org.perses.reduction.reducer.PersesNodeDfsReducer
import org.perses.reduction.reducer.PersesNodePrioritizedBfsReducer
import org.perses.reduction.reducer.PersesNodePrioritizedDfsReducer
import org.perses.reduction.reducer.hdd.HDDReducer
import org.perses.reduction.reducer.hdd.PristineHDDReducer
import org.perses.reduction.reducer.latra.CoarseGritLatraReducerAnnotation
import org.perses.reduction.reducer.latra.FineGritLatraReducerAnnotation
import org.perses.reduction.reducer.lpr.LLMBasedDataTypeEliminationReducer
import org.perses.reduction.reducer.lpr.LLMBasedDataTypeSimplificationReducer
import org.perses.reduction.reducer.lpr.LLMBasedFunctionInliningReducer
import org.perses.reduction.reducer.lpr.LLMBasedLoopUnrollingReducer
import org.perses.reduction.reducer.lpr.LLMBasedVariableEliminationReducer
import org.perses.reduction.reducer.token.ConcurrentStateBasedDeltaReducer
import org.perses.reduction.reducer.token.ConcurrentStateBasedLineSlicer
import org.perses.reduction.reducer.token.ConcurrentStateBasedTokenSlicer
import org.perses.reduction.reducer.token.ConcurrentTokenSlicer
import org.perses.reduction.reducer.token.DeltaDebuggingReducer
import org.perses.reduction.reducer.token.LineBasedConcurrentTokenSlicer
import org.perses.reduction.reducer.token.LineBasedTokenSlicer
import org.perses.reduction.reducer.token.TokenSlicer
import org.perses.reduction.reducer.trec.TokenCanonicalizer
import org.perses.reduction.reducer.vulcan.IdentifierReplacementReducer
import org.perses.reduction.reducer.vulcan.SubTreeReplacementReducer
import org.perses.reduction.reducer.vulcan.pattern.LocalExhaustivePatternReducer
import org.perses.util.Util.lazyAssert
import org.perses.util.ktInfo
import org.perses.util.ktWarning
import org.perses.util.toImmutableMap
import java.lang.RuntimeException
import kotlin.reflect.full.createInstance

/** Factory to create various reducers.  */
object ReducerFactory {
  private val DEFAULT_REDUCTION_ALG = PersesNodePrioritizedDfsReducer.META

  val registeredReductionAlgorithms =
    ImmutableSet
      .builder<ReducerAnnotation>()
      .add(HDDReducer.META)
      .add(TokenSlicer.META)
      .addAll(ConcurrentTokenSlicer.REDUCER_ANNOTATIONS)
      .add(ConcurrentTokenSlicer.CompositeReducerAnnotation)
      .addAll(LineBasedConcurrentTokenSlicer.REDUCER_ANNOTATIONS)
      .add(LineBasedConcurrentTokenSlicer.CompositeReducerAnnotation)
      .add(ConcurrentStateBasedDeltaReducer.META)
      .addAll(ConcurrentStateBasedLineSlicer.REDUCER_ANNOTATIONS)
      .add(ConcurrentStateBasedLineSlicer.CompositeReducerAnnotation)
      .addAll(ConcurrentStateBasedTokenSlicer.REDUCER_ANNOTATIONS)
      .add(ConcurrentStateBasedTokenSlicer.CompositeReducerAnnotation)
      .add(NonSyntacticSingleTreeNodeReducer.META)
      .add(PersesNodeBfsReducer.META)
      .add(PersesNodePrioritizedBfsReducer.META)
      .add(PersesNodeDfsReducer.META)
      .add(PristineHDDReducer.META)
      .add(DeltaDebuggingReducer.META)
      .add(DEFAULT_REDUCTION_ALG)
      .add(FineGritLatraReducerAnnotation)
      .add(CoarseGritLatraReducerAnnotation)
      .add(LLMBasedFunctionInliningReducer.META)
      .add(LLMBasedLoopUnrollingReducer.META)
      .add(LLMBasedDataTypeEliminationReducer.META)
      .add(LLMBasedDataTypeSimplificationReducer.META)
      .add(LLMBasedVariableEliminationReducer.META)
      .add(SubTreeReplacementReducer.META)
      .add(IdentifierReplacementReducer.META)
      .add(LocalExhaustivePatternReducer.META)
      .add(TokenCanonicalizer.META)
      .add(LineBasedTokenSlicer.META)
      .build()
      .toImmutableMap(
        keyFunc = { it.shortName },
        valueFunc = { it },
      )

  @JvmStatic
  val defaultReductionAlgName: String
    get() {
      val defaultAlgName = PersesNodePrioritizedDfsReducer.NAME
      lazyAssert { isValidReducerName(defaultAlgName) }
      return defaultAlgName
    }

  @JvmStatic
  fun isValidReducerName(shortName: String): Boolean {
    val result = registeredReductionAlgorithms.containsKey(shortName)
    if (result) {
      return true
    }
    logger.ktInfo { "Try to use the algorithm name as a class name" }
    try {
      Class.forName(shortName)
      return true
    } catch (e: Throwable) {
      logger.ktInfo { "Unable to load the class $shortName" }
      return false
    }
  }

  @JvmStatic
  fun getReductionAlgorithm(reducerShortName: String): ReducerAnnotation {
    var annotation = registeredReductionAlgorithms[reducerShortName]
    if (annotation == null) {
      logger.ktWarning {
        "No registered reducer annotation with the name $reducerShortName." +
          "Retrying to load the reducer by using the given name as a class name"
      }
      try {
        annotation = getReducerAnnotationWithReducerClassName(reducerShortName)
      } catch (e: Throwable) {
        logger.ktWarning { "Fail to load the class $reducerShortName. ${e.message}" }
        throw e
      }
    }
    return annotation
  }

  @JvmStatic
  fun getReducerAnnotationWithReducerClassName(klassName: String): ReducerAnnotation {
    val klass = Class.forName(klassName).kotlin
    klass.objectInstance?.let {
      return it as ReducerAnnotation
    }
    return try {
      klass.createInstance() as ReducerAnnotation
    } catch (e: Exception) {
      throw RuntimeException("Cannot create an instance of $klassName", e)
    }
  }

  @JvmStatic
  fun printAllReductionAlgorithms(): String =
    registeredReductionAlgorithms.values
      .asSequence()
      .sortedBy { it.shortName }
      .withIndex()
      .map { (index, reducerAnnotation) ->
        val indexComponent = Strings.padStart((index + 1).toString(), 2, ' ')
        buildString {
          append(indexComponent).append(": ").append(reducerAnnotation.shortName).append("\n")
          append("    desc : ")
            .append(
              reducerAnnotation.description.replace('\n', ' '),
            ).append('\n')
          val klass = reducerAnnotation::class.java
          append("    class: ").append(klass.name).append('\n')
        }
      }.joinToString(separator = "\n")

  private val logger = FluentLogger.forEnclosingClass()
}
