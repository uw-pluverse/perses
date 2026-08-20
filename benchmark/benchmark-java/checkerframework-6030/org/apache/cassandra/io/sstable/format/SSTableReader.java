package org.apache.cassandra.io.sstable.format;

import org.apache.cassandra.db.rows.UnfilteredSource;
import org.apache.cassandra.io.sstable.SSTable;
import org.apache.cassandra.utils.concurrent.SelfRefCounted;

public abstract class SSTableReader extends SSTable implements UnfilteredSource, SelfRefCounted<SSTableReader> {
}
