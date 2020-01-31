package org.perses.reduction;

import it.unimi.dsi.fastutil.ints.Int2IntOpenHashMap;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;
import org.perses.reduction.AbstractForwardAdjacencyMap.DelegatingForwardAdjacencyIndex;
import org.perses.reduction.AbstractForwardAdjacencyMap.HashForwardAdjacencyIndex;

import static com.google.common.truth.Truth.assertThat;
import static org.perses.reduction.AbstractForwardAdjacencyMap.NOT_FOUND;
import static org.perses.reduction.AbstractForwardAdjacencyMap.create;

@RunWith(JUnit4.class)
public class ForwardAdjacencyMapTest {

  @Test
  public void testEmptyMap() {
    final AbstractForwardAdjacencyMap map = AbstractForwardAdjacencyMap.EMPTY;
    assertThat(map.getNearestForwardIndex(1)).isEqualTo(NOT_FOUND);
    assertThat(map.getNumberOfIndirections()).isEqualTo(0);
    assertThat(map.size()).isEqualTo(0);
    Int2IntOpenHashMap collector = new Int2IntOpenHashMap();
    map.writeIndicesToMap(collector);
    assertThat(collector).isEmpty();
  }

  @Test
  public void testIndexDelegation() {
    final AbstractForwardAdjacencyMap first = AbstractForwardAdjacencyMap.EMPTY;
    final AbstractForwardAdjacencyMap second = create(first, 0, 0);
    {
      assertThat(second).isInstanceOf(DelegatingForwardAdjacencyIndex.class);
      assertThat(second.getNumberOfIndirections()).isEqualTo(1);
      assertThat(second.getNearestForwardIndex(0)).isEqualTo(0);
      assertThat(second.getNearestForwardIndex(1)).isEqualTo(NOT_FOUND);
      assertThat(second.size()).isEqualTo(1);

      Int2IntOpenHashMap collector = new Int2IntOpenHashMap();
      second.writeIndicesToMap(collector);
      assertThat(collector.keySet()).containsExactly(0);
      assertThat(collector.values()).containsExactly(0);
    }
    final AbstractForwardAdjacencyMap third = create(second, 1, 1);
    {
      assertThat(third).isInstanceOf(DelegatingForwardAdjacencyIndex.class);
      assertThat(third.getNumberOfIndirections()).isEqualTo(2);
      assertThat(third.getNearestForwardIndex(0)).isEqualTo(0);
      assertThat(third.getNearestForwardIndex(1)).isEqualTo(1);
      assertThat(third.getNearestForwardIndex(2)).isEqualTo(NOT_FOUND);
      assertThat(third.size()).isEqualTo(2);

      Int2IntOpenHashMap collector = new Int2IntOpenHashMap();
      third.writeIndicesToMap(collector);
      assertThat(collector.keySet()).containsExactly(0, 1);
      assertThat(collector.values()).containsExactly(0, 1);
    }
    final AbstractForwardAdjacencyMap fourth = create(third, 0, 1);
    {
      assertThat(fourth).isInstanceOf(DelegatingForwardAdjacencyIndex.class);
      assertThat(fourth.getNumberOfIndirections()).isEqualTo(3);
      assertThat(fourth.getNearestForwardIndex(0)).isEqualTo(1);
      assertThat(fourth.getNearestForwardIndex(1)).isEqualTo(1);
      assertThat(fourth.getNearestForwardIndex(2)).isEqualTo(NOT_FOUND);
      assertThat(fourth.size()).isEqualTo(3);
    }
  }

  @Test
  public void testHashForwardAdjacencyIndex() {
    final AbstractForwardAdjacencyMap first = AbstractForwardAdjacencyMap.EMPTY;
    AbstractForwardAdjacencyMap prev = first;
    for (int i = 0; i < AbstractForwardAdjacencyMap.NUM_INDIRECTIONS_THRESHOLD; ++i) {
      prev = AbstractForwardAdjacencyMap.create(prev, i, i);
    }
    assertThat(prev).isInstanceOf(DelegatingForwardAdjacencyIndex.class);
    for (int i = 0; i < AbstractForwardAdjacencyMap.NUM_INDIRECTIONS_THRESHOLD; ++i) {
      assertThat(prev.getNearestForwardIndex(i)).isEqualTo(i);
    }

    final AbstractForwardAdjacencyMap hash = AbstractForwardAdjacencyMap.create(prev, 0, 100);
    assertThat(hash).isInstanceOf(HashForwardAdjacencyIndex.class);
    assertThat(hash.getNearestForwardIndex(0)).isEqualTo(100);
    assertThat(hash.getNearestForwardIndex(1)).isEqualTo(1);
    assertThat(hash.getNumberOfIndirections()).isEqualTo(0);
  }
}
