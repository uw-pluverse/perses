



import java.io.*;
import java.util.*;
import com.sun.tools.classfile.*;

public class SyntheticClasses {

    public static void main(String[] args) throws IOException, ConstantPoolException {
        new SyntheticClasses().run();
    }

    private void run() throws IOException, ConstantPoolException {
        File testClasses = new File(System.getProperty("test.classes"));
        for (File classFile : testClasses.listFiles(f -> f.getName().endsWith(".class"))) {
            ClassFile cf = ClassFile.read(classFile);
            if (cf.getName().matches(".*\\$[0-9]+")) {
                EnclosingMethod_attribute encl =
                        (EnclosingMethod_attribute) cf.getAttribute(Attribute.EnclosingMethod);
                if (encl != null) {
                    if (encl.method_index != 0)
                        throw new IllegalStateException("Invalid EnclosingMethod.method_index: " +
                                                        encl.method_index + ".");
                }
            }
            InnerClasses_attribute attr =
                    (InnerClasses_attribute) cf.getAttribute(Attribute.InnerClasses);
            if (attr != null) {
                for (InnerClasses_attribute.Info info : attr.classes) {
                    if (cf.major_version < 51)
                        throw new IllegalStateException();
                    if (info.inner_name_index == 0 && info.outer_class_info_index != 0)
                        throw new IllegalStateException("Invalid outer_class_info_index=" +
                                                        info.outer_class_info_index +
                                                        "; inner_name_index=" +
                                                        info.inner_name_index + ".");
                }
            }
        }
    }
}

class SyntheticConstructorAccessTag {

    private static class A {
        private A(){}
    }

    public void test() {
        new A();
    }
}

class SyntheticEnumMapping {
    private int convert(E e) {
        switch (e) {
            case A: return 0;
            default: return -1;
        }
    }
    enum E { A }
}

interface SyntheticAssertionsDisabled {
    public default void test() {
        assert false;
    }
}
