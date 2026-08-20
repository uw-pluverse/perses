package io.github.mmm.property.factory;

import io.github.mmm.property.PropertyMetadata;
import io.github.mmm.property.ReadableProperty;

public interface PropertyFactoryManager {

    @SuppressWarnings({ "rawtypes", "unchecked" })
    default <V, P extends ReadableProperty<V>> P create(Class<P> propertyType, Class<V> valueClass, String name, PropertyMetadata<V> metadata) {
        PropertyFactory factory = getRequiredFactory(propertyType, valueClass);
        if (factory instanceof AbstractSimplePropertyFactory) {
            AbstractSimplePropertyFactory simpleFactory = ((AbstractSimplePropertyFactory) factory);
            return (P) simpleFactory.create(name, metadata);
        } else {
            return (P) factory.create(name, PropertyTypeInfo.ofValueClass(valueClass), metadata);
        }
    }

    @SuppressWarnings({ "unchecked", "rawtypes" })
    default <V, P extends ReadableProperty<V>> PropertyFactory<V, ? extends P> getRequiredFactory(Class<P> propertyType, Class<V> valueType) {
        throw new java.lang.Error();
    }
}
