package net.java.otr4j.util;

import com.google.errorprone.annotations.CanIgnoreReturnValue;

public final class Integers {

    @CanIgnoreReturnValue
    public static int requireNotEquals(final int forbidden, final int value) {
        throw new java.lang.Error();
    }
}
