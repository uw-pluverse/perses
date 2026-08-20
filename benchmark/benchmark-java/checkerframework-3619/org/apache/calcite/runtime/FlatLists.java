package org.apache.calcite.runtime;

import java.util.List;

public class FlatLists {

    public abstract static class AbstractFlatList<T> extends AbstractImmutableList<T> {
    }

    public interface ComparableList<T> extends List<T>, Comparable<List> {
    }
}
