package net.java.otr4j.util;

import com.google.errorprone.annotations.CanIgnoreReturnValue;
import com.google.errorprone.annotations.CheckReturnValue;
import javax.annotation.Nonnull;

public final class ByteArrays {

    @CanIgnoreReturnValue
    @Nonnull
    public static byte[] requireLengthExactly(final int length, final byte[] bytes) {
        throw new java.lang.Error();
    }

    @CheckReturnValue
    public static boolean allZeroBytes(final byte[] data) {
        throw new java.lang.Error();
    }
}
