package org.apache.cassandra.schema;

import org.apache.cassandra.cql3.*;
import org.apache.cassandra.cql3.selection.Selectable;
import org.apache.cassandra.db.marshal.*;
import org.github.jamm.Unmetered;

@Unmetered
public final class ColumnMetadata extends ColumnSpecification implements Selectable, Comparable<ColumnMetadata> {

    public int compareTo(ColumnMetadata other) {
        throw new java.lang.Error();
    }

    public AbstractType<?> cellValueType() {
        throw new java.lang.Error();
    }
}
