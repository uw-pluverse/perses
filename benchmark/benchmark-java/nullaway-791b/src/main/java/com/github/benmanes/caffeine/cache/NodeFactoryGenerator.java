package com.github.benmanes.caffeine.cache;

import java.util.LinkedHashSet;
import java.util.List;
import com.google.common.collect.ImmutableSet;

@SuppressWarnings("PMD.AvoidDuplicateLiterals")
public final class NodeFactoryGenerator {

    private final Feature[] featureByIndex = null;

    private ImmutableSet<Feature> getFeatures(List<Object> combination) {
        var features = new LinkedHashSet<Feature>();
        features.add((Feature) combination.get(0));
        features.add((Feature) combination.get(1));
        for (int i = 2; i < combination.size(); i++) {
            if ((Boolean) combination.get(i)) {
                features.add(featureByIndex[i]);
            }
        }
        if (features.contains(Feature.MAXIMUM_WEIGHT)) {
            features.remove(Feature.MAXIMUM_SIZE);
        }
        return ImmutableSet.copyOf(features);
    }
}
