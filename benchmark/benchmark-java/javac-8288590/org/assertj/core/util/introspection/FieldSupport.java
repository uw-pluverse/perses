package org.assertj.core.util.introspection;

import static java.util.stream.Collectors.collectingAndThen;
import static java.util.stream.Collectors.toList;
import static org.assertj.core.util.Streams.stream;
import java.util.Collections;
import java.util.List;

public enum FieldSupport {
    ;

    FieldSupport(boolean allowUsingPrivateFields) {
        throw new java.lang.Error();
    }

    public <T> List<T> fieldValues(String fieldName, Class<T> fieldClass, Iterable<?> target) {
        throw new java.lang.Error();
    }

    public List<Object> fieldValues(String fieldName, Iterable<?> target) {
        throw new java.lang.Error();
    }

    public <T> List<T> fieldValues(String fieldName, Class<T> fieldClass, Object[] target) {
        throw new java.lang.Error();
    }

    private <T> List<T> simpleFieldValues(String fieldName, Class<T> clazz, Iterable<?> target) {
        return stream(target).map(e -> e == null ? null : fieldValue(fieldName, clazz, e)).collect(collectingAndThen(toList(), Collections::unmodifiableList));
    }

    public <T> T fieldValue(String fieldName, Class<T> fieldClass, Object target) {
        throw new java.lang.Error();
    }
}
