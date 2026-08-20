package org.apache.cassandra.index.sasi.plan;

public class Expression {

    public enum Op {

        EQ,
        MATCH,
        PREFIX,
        SUFFIX,
        CONTAINS,
        NOT_EQ,
        RANGE
    }
}
