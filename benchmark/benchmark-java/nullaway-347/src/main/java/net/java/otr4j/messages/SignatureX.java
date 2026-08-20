package net.java.otr4j.messages;

import net.java.otr4j.io.OtrEncodable;
import javax.annotation.Nonnull;
import java.security.interfaces.DSAPublicKey;
import static java.util.Objects.requireNonNull;
import static net.java.otr4j.crypto.DSAKeyPair.DSA_SIGNATURE_LENGTH_BYTES;
import static net.java.otr4j.util.ByteArrays.allZeroBytes;
import static net.java.otr4j.util.ByteArrays.requireLengthExactly;
import static net.java.otr4j.util.Integers.requireNotEquals;

public final class SignatureX implements OtrEncodable {

    @Nonnull
    private final DSAPublicKey longTermPublicKey;

    private final int dhKeyID;

    @Nonnull
    private final byte[] signature;

    public SignatureX(final DSAPublicKey ourLongTermPublicKey, final int ourKeyID, final byte[] signature) {
        this.longTermPublicKey = requireNonNull(ourLongTermPublicKey);
        this.dhKeyID = requireNotEquals(0, ourKeyID);
        this.signature = requireLengthExactly(DSA_SIGNATURE_LENGTH_BYTES, signature);
        assert !allZeroBytes(this.signature) : "Expected non-zero bytes for signature. This may indicate that a critical bug is present, or it may be a false warning.";
    }
}
