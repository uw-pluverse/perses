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
    //    testGetAnnotationWithName(KleeneLevelHDDReducer.NAME);
    //    testGetAnnotationWithName(PersesLevelReducer.NAME); Will be removed soon.
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
            //            KleeneLevelHDDReducer.NAME,
            //            PersesLevelReducer.NAME,
            TokenSlicer.NAME,
            PersesNodeBfsReducer.NAME,
            PersesNodeDfsReducer.NAME,
            PersesNodePrioritizedBfsReducer.NAME,
            PersesNodePrioritizedDfsReducer.NAME);
  }
}
