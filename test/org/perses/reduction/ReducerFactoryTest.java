/*
 * Copyright (C) 2018-2020 University of Waterloo.
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

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.reduction.reducer.*;

import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

import static com.google.common.truth.Truth.assertThat;

@RunWith(JUnit4.class)
public class ReducerFactoryTest {

  @Test
  public void testGetAnnotationWithName() {
    testGetAnnotationWithName(HDDReducer.NAME);
    testGetAnnotationWithName(PersesNodeBfsReducer.NAME);
    testGetAnnotationWithName(PersesNodeDfsReducer.NAME);
    testGetAnnotationWithName(PersesNodePrioritizedBfsReducer.NAME);
    testGetAnnotationWithName(PersesNodePrioritizedDfsReducer.NAME);
  }

  private static void testGetAnnotationWithName(String name) {
    Optional<ReducerAnnotation> annotation = ReducerFactory.getAnnotationWithName(name);
    assertThat(annotation.get().shortName()).isEqualTo(name);
  }

  @Test
  public void testIsValidReducerName() {
    assertThat(ReducerFactory.isValidReducerName("dd")).isFalse();
    assertThat(ReducerFactory.isValidReducerName(HDDReducer.NAME)).isTrue();
  }

  @Test
  public void testGetReductionAlgorithm() {
    ReducerAnnotation hdd = ReducerFactory.getReductionAlgorithm(HDDReducer.NAME);
    assertThat(hdd).isEqualTo(HDDReducer.META);
  }

  @Test
  public void testGetAllReducerAlgorithms() {
    List<String> names =
        ReducerFactory.getAllReducerAlgorithms().stream()
            .map(ReducerAnnotation::shortName)
            .collect(Collectors.toList());
    assertThat(names)
        .containsExactly(
            HDDReducer.NAME,
            TokenSlicer.NAME,
            TreeSlicer.NAME,
            ConcurrentTokenSlicer.NAME,
            PersesNodeBfsReducer.NAME,
            PersesNodeDfsReducer.NAME,
            PersesNodePrioritizedBfsReducer.NAME,
            PersesNodePrioritizedDfsReducer.NAME);
  }
}
