package com.google.common.collect;

import com.google.common.annotations.GwtIncompatible;
import com.google.errorprone.annotations.CanIgnoreReturnValue;
import java.util.Map;
import org.checkerframework.checker.nullness.qual.NonNull;
import org.checkerframework.checker.nullness.qual.Nullable;

@GwtIncompatible
@SuppressWarnings("serial")
public final class MutableClassToInstanceMap<B extends @NonNull Object> extends ForwardingMap<Class<? extends B>, @Nullable B> implements ClassToInstanceMap<B> {

    private static <B extends @NonNull Object> Entry<Class<? extends B>, @Nullable B> checkedEntry(Entry<Class<? extends B>, @Nullable B> entry) {
        return new ForwardingMapEntry<Class<? extends B>, @Nullable B>() {

            protected Entry<Class<? extends B>, @Nullable B> delegate() {
                return entry;
            }

            @Nullable
            public B setValue(@Nullable B value) {
                return super.setValue(cast(getKey(), value));
            }
        };
    }

    @CanIgnoreReturnValue
    @Nullable
    private static <T extends @NonNull Object> T cast(Class<T> type, @Nullable Object value) {
        throw new java.lang.Error();
    }
}
