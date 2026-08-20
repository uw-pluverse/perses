package io.github.mmm.property.factory;

import io.github.mmm.property.PropertyMetadata;
import io.github.mmm.property.WritableProperty;

public interface PropertyFactory<V, P extends WritableProperty<V>> {

    default P create(String name, PropertyTypeInfo<V> valueClass, PropertyMetadata<V> metadata) {
        throw new java.lang.Error();
    }
}
