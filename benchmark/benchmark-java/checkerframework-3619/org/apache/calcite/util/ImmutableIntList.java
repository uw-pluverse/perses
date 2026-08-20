package org.apache.calcite.util;

import org.apache.calcite.runtime.FlatLists;
import java.util.Arrays;
import java.util.List;
import org.checkerframework.checker.nullness.qual.Nullable;

public class ImmutableIntList extends FlatLists.AbstractFlatList<Integer> {

    private final int[] ints = null;

    public boolean equals(@Nullable Object obj) {
        return this == obj || obj instanceof ImmutableIntList ? Arrays.equals(ints, ((ImmutableIntList) obj).ints) : obj instanceof List && obj.equals(this);
    }

    public int size() {
        throw new java.lang.Error();
    }

    public Object[] toArray() {
        throw new java.lang.Error();
    }

    public <T> T[] toArray(T[] a) {
        throw new java.lang.Error();
    }

    public Integer get(int index) {
        throw new java.lang.Error();
    }

    public int indexOf(Object o) {
        throw new java.lang.Error();
    }

    public int indexOf(int seek) {
        throw new java.lang.Error();
    }

    public int lastIndexOf(Object o) {
        throw new java.lang.Error();
    }

    public int lastIndexOf(int seek) {
        throw new java.lang.Error();
    }
}
