package io.github.mmm.property.factory;

public interface PropertyTypeInfo<V> {

    static <V> PropertyTypeInfo<V> ofValueClass(Class<V> valueClass) {
        throw new java.lang.Error();
    }
}
