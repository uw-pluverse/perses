package org.apache.calcite.sql.parser;

import org.apache.calcite.sql.SqlNode;
import org.apache.calcite.util.Util;
import org.checkerframework.checker.nullness.qual.PolyNull;
import java.io.Serializable;
import static org.apache.calcite.linq4j.Nullness.castNonNull;

public class SqlParserPos implements Serializable {

    private static Iterable<@PolyNull SqlParserPos> toPos(Iterable<? extends @PolyNull SqlNode> nodes) {
        return Util.transform(nodes, node -> node == null ? castNonNull(null) : node.getParserPosition());
    }
}
