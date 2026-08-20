package org.apache.cassandra.db.marshal;

import java.nio.ByteBuffer;
import org.apache.cassandra.cql3.AssignmentTestable;
import org.github.jamm.Unmetered;

@Unmetered
public abstract class AbstractType<T> implements AssignmentTestable {

    public final int compare(ByteBuffer left, ByteBuffer right) {
        throw new java.lang.Error();
    }
}
