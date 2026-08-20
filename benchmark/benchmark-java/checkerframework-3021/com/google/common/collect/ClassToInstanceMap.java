package com.google.common.collect;

import com.google.common.annotations.GwtCompatible;
import java.util.Map;
import org.checkerframework.checker.nullness.qual.NonNull;
import org.checkerframework.checker.nullness.qual.Nullable;

@GwtCompatible
public interface ClassToInstanceMap<B extends @NonNull Object> extends Map<Class<? extends B>, @Nullable B> {
}
