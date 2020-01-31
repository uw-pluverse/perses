

package org.openjdk.tests.separate;

import java.io.*;
import java.util.*;

public class ClassToInterfaceConverter implements ClassFilePreprocessor {

    private String whichClass;

    public ClassToInterfaceConverter(String className) {
        this.whichClass = className;
    }

    private boolean utf8Matches(ClassFile.CpEntry entry, String v) {
        if (!(entry instanceof ClassFile.CpUtf8)) {
            return false;
        }
        ClassFile.CpUtf8 utf8 = (ClassFile.CpUtf8)entry;
        if (v.length() != utf8.bytes.length) {
            return false;
        }
        for (int i = 0; i < v.length(); ++i) {
            if (v.charAt(i) != utf8.bytes[i]) {
                return false;
            }
        }
        return true;
    }

    private void convertToInterface(ClassFile cf) {
        cf.access_flags = 0x0601; 
        ArrayList<ClassFile.Method> new_methods = new ArrayList<>();
        
        for (int i = 0; i < cf.methods.size(); ++i) {
            ClassFile.Method method = cf.methods.get(i);
            ClassFile.CpEntry name = cf.constant_pool.get(method.name_index);
            if (!utf8Matches(name, "<init>")) {
                new_methods.add(method);
            }
        }
        cf.methods = new_methods;
    }

    public byte[] preprocess(String classname, byte[] bytes) {
        ClassFile cf = new ClassFile(bytes);

        ClassFile.CpEntry entry = cf.constant_pool.get(cf.this_class);
        ClassFile.CpEntry name = cf.constant_pool.get(
            ((ClassFile.CpClass)entry).name_index);
        if (utf8Matches(name, whichClass)) {
            convertToInterface(cf);
            return cf.toByteArray();
        } else {
            return bytes; 
        }
    }


}
