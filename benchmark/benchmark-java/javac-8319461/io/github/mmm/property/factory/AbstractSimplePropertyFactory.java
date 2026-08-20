package io.github.mmm.property.factory;

import io.github.mmm.property.PropertyMetadata;
import io.github.mmm.property.WritableProperty;

public abstract class AbstractSimplePropertyFactory<V, P extends WritableProperty<V>> extends AbstractPropertyFactory<V, P> {

    public final P create(String name, PropertyTypeInfo<V> valueClass, PropertyMetadata<V> metadata) {
        throw new java.lang.Error();
    }

    protected abstract P create(String name, PropertyMetadata<V> metadata);
}
