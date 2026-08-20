package io.github.mmm.property;

import io.github.mmm.marshall.MarshallableObject;
import io.github.mmm.validation.Validatable;
import io.github.mmm.value.TypedPropertyPath;
import io.github.mmm.value.observable.ObservableValue;

public interface ReadableProperty<V> extends ObservableValue<V>, TypedPropertyPath<V>, MarshallableObject, Validatable, AttributeReadOnly, Comparable<ReadableProperty<?>> {
}
