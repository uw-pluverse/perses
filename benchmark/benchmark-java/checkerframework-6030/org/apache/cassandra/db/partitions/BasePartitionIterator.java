package org.apache.cassandra.db.partitions;

import org.apache.cassandra.db.rows.BaseRowIterator;
import org.apache.cassandra.utils.CloseableIterator;

public interface BasePartitionIterator<I extends BaseRowIterator<?>> extends CloseableIterator<I> {

    public default void close() {
        throw new java.lang.Error();
    }
}
