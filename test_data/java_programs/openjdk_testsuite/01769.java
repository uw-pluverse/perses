



import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.ConstantPool.*;
import com.sun.tools.classfile.Method;

import java.io.*;

public class TestNoBridgeOnDefaults {

    interface A<X> {
        default <Y> A<X> m(X x, Y y) { return Impl.<X,Y>m1(this, x, y); }
    }

    static abstract class B<X> implements A<X> { }

    interface C<X> extends A<X> {
        default <Y> C<X> m(X x, Y y) { return Impl.<X,Y>m2(this, x, y); }
    }

    static abstract class D<X> extends B<X> implements C<X> { }

    static class Impl {
       static <X, Y> A<X> m1(A<X> rec, X x, Y y) { return null; }
       static <X, Y> C<X> m2(C<X> rec, X x, Y y) { return null; }
    }

    static final String[] SUBTEST_NAMES = { B.class.getName() + ".class", D.class.getName() + ".class" };
    static final String TEST_METHOD_NAME = "m";

    public static void main(String... args) throws Exception {
        new TestNoBridgeOnDefaults().run();
    }

    public void run() throws Exception {
        String workDir = System.getProperty("test.classes");
        for (int i = 0 ; i < SUBTEST_NAMES.length ; i ++) {
            File compiledTest = new File(workDir, SUBTEST_NAMES[i]);
            checkNoBridgeOnDefaults(compiledTest);
        }
    }

    void checkNoBridgeOnDefaults(File f) {
        System.err.println("check: " + f);
        try {
            ClassFile cf = ClassFile.read(f);
            for (Method m : cf.methods) {
                String mname = m.getName(cf.constant_pool);
                if (mname.equals(TEST_METHOD_NAME)) {
                    throw new Error("unexpected bridge method found " + m);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
            throw new Error("error reading " + f +": " + e);
        }
    }
}
