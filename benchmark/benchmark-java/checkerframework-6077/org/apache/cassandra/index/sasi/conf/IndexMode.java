package org.apache.cassandra.index.sasi.conf;

import java.util.Map;
import org.apache.cassandra.schema.ColumnMetadata;
import org.apache.cassandra.index.sasi.disk.OnDiskIndexBuilder.Mode;
import org.apache.cassandra.db.marshal.AbstractType;
import org.apache.cassandra.db.marshal.AsciiType;
import org.apache.cassandra.db.marshal.UTF8Type;
import org.apache.cassandra.exceptions.ConfigurationException;
import org.slf4j.Logger;

public class IndexMode {

    private static final Logger logger = null;

    public static final IndexMode NOT_INDEXED = null;

    private static final String INDEX_MODE_OPTION = null;

    private static final String INDEX_ANALYZED_OPTION = null;

    private static final String INDEX_ANALYZER_CLASS_OPTION = null;

    private static final String INDEX_IS_LITERAL_OPTION = null;

    private static final String INDEX_MAX_FLUSH_MEMORY_OPTION = null;

    private static final long DEFAULT_MAX_MEM_BYTES = 0L;

    private IndexMode(Mode mode, boolean isLiteral, boolean isAnalyzed, Class analyzerClass, long maxMemBytes) {
        throw new java.lang.Error();
    }

    public static IndexMode getMode(ColumnMetadata column, Map<String, String> indexOptions) throws ConfigurationException {
        if (indexOptions == null || indexOptions.isEmpty())
            return IndexMode.NOT_INDEXED;
        Mode mode;
        try {
            mode = indexOptions.get(INDEX_MODE_OPTION) == null ? Mode.PREFIX : Mode.mode(indexOptions.get(INDEX_MODE_OPTION));
        } catch (IllegalArgumentException e) {
            throw new ConfigurationException("Incorrect index mode: " + indexOptions.get(INDEX_MODE_OPTION));
        }
        boolean isAnalyzed = false;
        Class analyzerClass = null;
        try {
            if (indexOptions.get(INDEX_ANALYZER_CLASS_OPTION) != null) {
                analyzerClass = Class.forName(indexOptions.get(INDEX_ANALYZER_CLASS_OPTION));
                isAnalyzed = indexOptions.get(INDEX_ANALYZED_OPTION) == null ? true : Boolean.parseBoolean(indexOptions.get(INDEX_ANALYZED_OPTION));
            } else if (indexOptions.get(INDEX_ANALYZED_OPTION) != null) {
                isAnalyzed = Boolean.parseBoolean(indexOptions.get(INDEX_ANALYZED_OPTION));
            }
        } catch (ClassNotFoundException e) {
            logger.error("Failed to find specified analyzer class [{}]. Falling back to default analyzer", indexOptions.get(INDEX_ANALYZER_CLASS_OPTION));
        }
        boolean isLiteral = false;
        try {
            String literalOption = indexOptions.get(INDEX_IS_LITERAL_OPTION);
            AbstractType<?> validator = column.cellValueType();
            isLiteral = literalOption == null ? (validator instanceof UTF8Type || validator instanceof AsciiType) : Boolean.parseBoolean(literalOption);
        } catch (Exception e) {
            logger.error("failed to parse {} option, defaulting to 'false'.", INDEX_IS_LITERAL_OPTION);
        }
        long maxMemBytes = indexOptions.get(INDEX_MAX_FLUSH_MEMORY_OPTION) == null ? DEFAULT_MAX_MEM_BYTES : 1048576L * Long.parseLong(indexOptions.get(INDEX_MAX_FLUSH_MEMORY_OPTION));
        if (maxMemBytes > 100L * 1073741824) {
            logger.error("{} configured as {} is above 100GiB, reverting to default 1GB", INDEX_MAX_FLUSH_MEMORY_OPTION, maxMemBytes);
            maxMemBytes = DEFAULT_MAX_MEM_BYTES;
        }
        return new IndexMode(mode, isLiteral, isAnalyzed, analyzerClass, maxMemBytes);
    }
}
