package org.apache.calcite.sql;

import org.apache.calcite.sql.parser.SqlParserPos;

public abstract class SqlNode {

    public SqlParserPos getParserPosition() {
        throw new java.lang.Error();
    }
}
