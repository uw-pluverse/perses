

package org.openjdk.tests.separate;

import java.io.*;

public class AttributeInjector implements ClassFilePreprocessor {

    private String attributeName;
    private byte[] attributeData;

    public AttributeInjector(String attributeName, byte[] attributeData) {
        this.attributeName = attributeName;
        this.attributeData = attributeData;
    }

    public byte[] preprocess(String name, byte[] cf) {
        ClassFile classfile = new ClassFile(cf);

        short cpIndex = (short)classfile.constant_pool.size();

        ClassFile.CpUtf8 entry = new ClassFile.CpUtf8();
        entry.bytes = new byte[attributeName.length()];
        for (int i = 0; i < attributeName.length(); ++i) {
            entry.bytes[i] = (byte)attributeName.charAt(i);
        }

        classfile.constant_pool.add(entry);

        ClassFile.Attribute attr = new ClassFile.Attribute();
        attr.attribute_name_index = cpIndex;
        attr.info = attributeData;

        classfile.attributes.add(attr);
        return classfile.toByteArray();
    }


}
