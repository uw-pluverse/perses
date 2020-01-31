/*
 * Copyright (C) 2003-2017 Chengnian Sun.
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
package org.perses.reduction;

import com.google.common.base.Functions;
import com.google.common.collect.ImmutableCollection;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableMap;
import com.google.common.collect.ImmutableSet;
import org.perses.reduction.reducer.*;

import java.util.Comparator;
import java.util.Optional;

import static com.google.common.base.Preconditions.checkState;

/** Factory to create various reducers. */
public final class ReducerFactory {

  private static final ReducerAnnotation DEFAULT_REDUCTION_ALG =
      PersesNodePrioritizedDfsReducer.META;

  private static final ImmutableMap<String, ReducerAnnotation> REDUCTION_ALGs =
      ImmutableSet.<ReducerAnnotation>builder().add(HDDReducer.META).add(PersesNodeBfsReducer.META)
          .add(PersesNodePrioritizedBfsReducer.META).add(PersesNodeDfsReducer.META)
          .add(DEFAULT_REDUCTION_ALG).build().stream()
          .collect(ImmutableMap.toImmutableMap(ReducerAnnotation::shortName, Functions.identity()));

  public static String getDefaultReductionAlgName() {
    final String defaultAlgName = PersesNodePrioritizedDfsReducer.NAME;
    assert isValidReducerName(defaultAlgName);
    return defaultAlgName;
  }

  private ReducerFactory() {}

  public static Optional<ReducerAnnotation> getAnnotationWithName(String algorithmName) {
    return Optional.ofNullable(REDUCTION_ALGs.get(algorithmName));
  }

  public static boolean isValidReducerName(String shortName) {
    return REDUCTION_ALGs.containsKey(shortName);
  }

  public static ImmutableCollection<ReducerAnnotation> getAllReducerAlgorithms() {
    return REDUCTION_ALGs.values();
  }

  public static ReducerAnnotation getReductionAlgorithm(String reducerShortName) {
    final Optional<ReducerAnnotation> annotation = getAnnotationWithName(reducerShortName);
    checkState(annotation.isPresent(), "Cannot find annotation for the name %s", reducerShortName);
    return annotation.get();
  }

  public static String printAllReductionAlgorithms() {
    final StringBuilder builder = new StringBuilder();
    final ImmutableList<ReducerAnnotation> algorithms =
        REDUCTION_ALGs.values().stream()
            .sorted(Comparator.comparing(ReducerAnnotation::shortName))
            .collect(ImmutableList.toImmutableList());

    for (int i = 0, size = algorithms.size(); i < size; ++i) {
      final ReducerAnnotation algorithm = algorithms.get(i);
      builder.append(i + 1).append(". ").append(algorithm.shortName()).append(":\n");
      builder.append("    ");
      final String description = algorithm.description().replace('\n', ' ');
      builder.append(description).append('\n');
    }

    return builder.toString();
  }
}
