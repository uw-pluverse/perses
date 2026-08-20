package org.apache.beam.sdk.transforms;

import java.io.Serializable;

public final class Contextful<ClosureT> implements Serializable {

    public interface Fn<InputT, OutputT> extends Serializable {
    }
}
