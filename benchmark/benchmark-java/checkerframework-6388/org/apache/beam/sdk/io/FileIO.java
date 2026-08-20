package org.apache.beam.sdk.io;

import static org.apache.beam.vendor.guava.v32_1_2_jre.com.google.common.base.Preconditions.checkArgument;
import com.google.auto.value.AutoValue;
import java.io.Serializable;
import org.apache.beam.sdk.transforms.Contextful;
import org.apache.beam.sdk.transforms.Contextful.Fn;
import org.apache.beam.sdk.transforms.PTransform;
import org.apache.beam.sdk.values.PCollection;

@SuppressWarnings({ "nullness" })
public class FileIO {

    public interface Sink<ElementT> extends Serializable {
    }

    @AutoValue
    public abstract static class Write<DestinationT, UserT> extends PTransform<PCollection<UserT>, WriteFilesResult<DestinationT>> {

        abstract Builder<DestinationT, UserT> toBuilder();

        @AutoValue.Builder
        abstract static class Builder<DestinationT, UserT> {

            abstract Builder<DestinationT, UserT> setSinkFn(Contextful<Fn<DestinationT, Sink<?>>> sink);

            abstract Builder<DestinationT, UserT> setOutputFn(Contextful<Fn<UserT, ?>> outputFn);

            abstract Write<DestinationT, UserT> build();
        }

        public <OutputT> Write<DestinationT, UserT> via(Contextful<Fn<UserT, OutputT>> outputFn, Contextful<Fn<DestinationT, Sink<OutputT>>> sinkFn) {
            checkArgument(sinkFn != null, "sinkFn can not be null");
            checkArgument(outputFn != null, "outputFn can not be null");
            return toBuilder().setSinkFn((Contextful) sinkFn).setOutputFn(outputFn).build();
        }
    }
}
