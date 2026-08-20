package io.github.mmm.property;

import io.github.mmm.marshall.MarshallingObject;
import io.github.mmm.value.observable.WritableObservableValue;

public interface WritableProperty<V> extends WritableObservableValue<V>, ReadableProperty<V>, MarshallingObject {
}
