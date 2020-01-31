

package org.openjdk.tests.separate;

public interface ClassFilePreprocessor {
    public byte[] preprocess(String name, byte[] classfile);
};
