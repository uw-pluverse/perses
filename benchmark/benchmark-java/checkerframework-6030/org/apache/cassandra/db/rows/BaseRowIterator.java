package org.apache.cassandra.db.rows;

import org.apache.cassandra.utils.CloseableIterator;

public interface BaseRowIterator<U extends Unfiltered> extends CloseableIterator<U> {
}
