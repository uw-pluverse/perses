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
package org.perses.reduction

import com.google.common.base.Strings
import com.google.common.collect.ImmutableMap
import com.google.common.collect.ImmutableSet
import com.google.common.flogger.FluentLogger
import org.perses.reduction.reducer.NonSyntacticSingleTreeNodeReducer
import org.perses.reduction.reducer.PersesNodeReducerAnnotations
import org.perses.reduction.reducer.hdd.HDDReducerAnnotations
import org.perses.reduction.reducer.hdd.PristineHDDReducer
import org.perses.reduction.reducer.latra.CoarseGritLatraReducerAnnotation
import org.perses.reduction.reducer.latra.FineGritLatraReducerAnnotation
import org.perses.reduction.reducer.line.TopFormFlatReducer
import org.perses.reduction.reducer.lpr.LlmBasedDataTypeEliminationReducer
import org.perses.reduction.reducer.lpr.LlmBasedDataTypeSimplificationReducer
import org.perses.reduction.reducer.lpr.LlmBasedFunctionInliningReducer
import org.perses.reduction.reducer.lpr.LlmBasedLoopUnrollingReducer
import org.perses.reduction.reducer.lpr.LlmBasedVariableEliminationReducer
import org.perses.reduction.reducer.sfc.IdentifierUseEliminationReducer
import org.perses.reduction.reducer.sfc.SmallerStructureReplacementReducer
import org.perses.reduction.reducer.sfc.StructureCanonicalizationReducer
import org.perses.reduction.reducer.token.CanonicalConcurrentStateBasedLineSlicer
import org.perses.reduction.reducer.token.CanonicalLineBasedConcurrentTokenSlicer
import org.perses.reduction.reducer.token.CanonicalLineBasedTokenSlicer
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
import org.perses.util.ktInfo
import org.perses.util.ktWarning
import org.perses.util.lazyAssert
import org.perses.util.toImmutableMap
import java.lang.RuntimeException
import kotlin.reflect.full.createInstance

/**
 * Resolves reduction algorithms by name. An instance exposes the built-in algorithms plus any extra
 * reducers it was created with (e.g. an active [LanguageProfile]'s) -- so it is immutable and holds no
 * global mutable state. Create one per run with [create] (or use [DEFAULT] for built-ins only).
 */
class ReducerFactory private constructor(
  /** All algorithms addressable by short name: the built-ins plus this factory's extra reducers. */
  val registeredReductionAlgorithms: ImmutableMap<String, ReducerAnnotation>,
) {
  fun isValidReducerName(shortName: String): Boolean {
    if (registeredReductionAlgorithms.containsKey(shortName)) {
      return true
    }
    logger.ktInfo { "Try to use the algorithm name as a class name" }
    return try {
      Class.forName(shortName)
      true
    } catch (e: Throwable) {
      logger.ktInfo { "Unable to load the class $shortName" }
      false
    }
  }

  fun getReductionAlgorithm(reducerName: String): ReducerAnnotation {
    // Prefer an available annotation, addressed either by its short name or by its class name, so a
    // profile-contributed reducer is returned as the same instance however it is referenced -- rather
    // than re-instantiated via Class.forName below.
    registeredReductionAlgorithms[reducerName]?.let { return it }
    registeredReductionAlgorithms.values
      .firstOrNull { it::class.qualifiedName == reducerName }
      ?.let { return it }

    logger.ktWarning {
      "No registered reducer annotation with the name $reducerName." +
        "Retrying to load the reducer by using the given name as a class name"
    }
    return try {
      getReducerAnnotationWithReducerClassName(reducerName)
    } catch (e: Throwable) {
      logger.ktWarning { "Fail to load the class $reducerName. ${e.message}" }
      throw e
    }
  }

  fun printAllReductionAlgorithms(): String =
    registeredReductionAlgorithms
      .values
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

  fun copyWithExtra(extraReducers: List<ReducerAnnotation>): ReducerFactory {
    if (extraReducers.isEmpty()) {
      return this
    }
    val merged = LinkedHashMap(registeredReductionAlgorithms)
    extraReducers.forEach {
      val previous = merged.put(it.shortName, it)
      check(previous == null) {
        "Duplicate reduction algorithm registration: ${it.shortName}"
      }
    }
    return ReducerFactory(merged.toImmutableMap())
  }

  companion object {
    private val DEFAULT_REDUCTION_ALG = PersesNodeReducerAnnotations.PrioritizedDfs

    private val builtinReductionAlgorithms: ImmutableMap<String, ReducerAnnotation> =
      ImmutableSet
        .builder<ReducerAnnotation>()
        .add(HDDReducerAnnotations.Hdd)
        .add(HDDReducerAnnotations.HddWithMimir)
        .add(TokenSlicer.META)
        .addAll(ConcurrentTokenSlicer.REDUCER_ANNOTATIONS)
        .add(ConcurrentTokenSlicer.CompositeReducerAnnotation)
        .addAll(LineBasedConcurrentTokenSlicer.REDUCER_ANNOTATIONS)
        .add(LineBasedConcurrentTokenSlicer.CompositeReducerAnnotation)
        .addAll(CanonicalLineBasedConcurrentTokenSlicer.REDUCER_ANNOTATIONS)
        .add(CanonicalLineBasedConcurrentTokenSlicer.CompositeReducerAnnotation)
        .add(ConcurrentStateBasedDeltaReducer.META)
        .addAll(ConcurrentStateBasedLineSlicer.REDUCER_ANNOTATIONS)
        .add(ConcurrentStateBasedLineSlicer.CompositeReducerAnnotation)
        .addAll(CanonicalConcurrentStateBasedLineSlicer.REDUCER_ANNOTATIONS)
        .add(CanonicalConcurrentStateBasedLineSlicer.CompositeReducerAnnotation)
        .addAll(ConcurrentStateBasedTokenSlicer.REDUCER_ANNOTATIONS)
        .add(ConcurrentStateBasedTokenSlicer.CompositeReducerAnnotation)
        .add(NonSyntacticSingleTreeNodeReducer.META)
        .add(PersesNodeReducerAnnotations.Dyck)
        .add(PersesNodeReducerAnnotations.PristineDyck)
        .add(PersesNodeReducerAnnotations.Bfs)
        .add(PersesNodeReducerAnnotations.PrioritizedBfs)
        .add(PersesNodeReducerAnnotations.Dfs)
        .add(PersesNodeReducerAnnotations.PrioritizedDfs)
        .add(PersesNodeReducerAnnotations.Mimir)
        .add(PristineHDDReducer.META)
        .add(DeltaDebuggingReducer.META)
        .add(DEFAULT_REDUCTION_ALG)
        .add(FineGritLatraReducerAnnotation)
        .add(CoarseGritLatraReducerAnnotation)
        .add(LlmBasedFunctionInliningReducer.META)
        .add(LlmBasedLoopUnrollingReducer.META)
        .add(LlmBasedDataTypeEliminationReducer.META)
        .add(LlmBasedDataTypeSimplificationReducer.META)
        .add(LlmBasedVariableEliminationReducer.META)
        .add(SubTreeReplacementReducer.META)
        .add(SmallerStructureReplacementReducer.META)
        .add(StructureCanonicalizationReducer.META)
        .add(IdentifierUseEliminationReducer.META)
        .add(IdentifierReplacementReducer.META)
        .add(LocalExhaustivePatternReducer.META)
        .add(TokenCanonicalizer.META)
        .add(LineBasedTokenSlicer.META)
        .add(CanonicalLineBasedTokenSlicer.META)
        .addAll(TopFormFlatReducer.REDUCER_ANNOTATIONS)
        .add(TopFormFlatReducer.CompositeReducerAnnotation)
        .build()
        .toImmutableMap(
          keyFunc = { it.shortName },
          valueFunc = { it },
        )

    /** A factory exposing only the built-in algorithms (no profile contributions). */
    val DEFAULT: ReducerFactory = ReducerFactory(builtinReductionAlgorithms)

    /** A factory exposing the built-in algorithms plus [extraReducers] (e.g. an active profile's). */
    @JvmStatic
    fun createWithExtra(extraReducers: List<ReducerAnnotation>): ReducerFactory =
      DEFAULT.copyWithExtra(extraReducers)

    @JvmStatic
    val defaultReductionAlgName: String
      get() {
        val defaultAlgName = DEFAULT_REDUCTION_ALG.shortName
        lazyAssert { DEFAULT.isValidReducerName(defaultAlgName) }
        return defaultAlgName
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

    private val logger = FluentLogger.forEnclosingClass()
  }
}
