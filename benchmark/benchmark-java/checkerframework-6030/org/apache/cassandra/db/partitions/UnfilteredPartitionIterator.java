package org.apache.cassandra.db.partitions;

import org.apache.cassandra.db.rows.UnfilteredRowIterator;

public interface UnfilteredPartitionIterator extends BasePartitionIterator<UnfilteredRowIterator> {
}
