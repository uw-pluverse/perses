package org.apache.beam.sdk.transforms;

import java.io.Serializable;
import org.apache.beam.sdk.transforms.display.HasDisplayData;
import org.apache.beam.sdk.values.PInput;
import org.apache.beam.sdk.values.POutput;

public abstract class PTransform<InputT extends PInput, OutputT extends POutput> implements Serializable, HasDisplayData {
}
