package org.apache.cassandra.io.sstable.format;

import org.apache.cassandra.db.rows.UnfilteredRowIterator;
import org.apache.cassandra.io.sstable.AbstractRowIndexEntry;
import org.apache.cassandra.io.sstable.ISSTableScanner;
import org.apache.cassandra.utils.AbstractIterator;
import org.checkerframework.checker.mustcall.qual.Owning;

public abstract class SSTableScanner<S extends SSTableReader, E extends AbstractRowIndexEntry, I extends SSTableScanner<S, E, I>.BaseKeyScanningIterator> implements ISSTableScanner {

    @Owning
    protected I iterator;

    @SuppressWarnings("missing.creates.mustcall.for")
    public boolean hasNext() {
        if (iterator == null)
            iterator = createIterator();
        return iterator.hasNext();
    }

    private I createIterator() {
        throw new java.lang.Error();
    }

    public abstract class BaseKeyScanningIterator extends AbstractIterator<UnfilteredRowIterator> {
    }
}
