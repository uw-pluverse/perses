package org.apache.cassandra.index.sasi.disk;

import java.util.EnumSet;
import java.util.Set;
import org.apache.cassandra.index.sasi.plan.Expression.Op;

public class OnDiskIndexBuilder {

    public enum Mode {

        PREFIX(EnumSet.of(Op.EQ, Op.MATCH, Op.PREFIX, Op.NOT_EQ, Op.RANGE));

        Mode(Set<Op> ops) {
            throw new java.lang.Error();
        }

        public static Mode mode(String mode) {
            throw new java.lang.Error();
        }
    }
}
