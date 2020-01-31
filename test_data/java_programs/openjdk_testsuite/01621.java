



import com.sun.tools.classfile.Attribute;
import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.Code_attribute;
import com.sun.tools.classfile.Code_attribute.Exception_data;
import com.sun.tools.classfile.Method;
import java.io.*;

public class Pos05 {

    static class Pos05sub {

        class A extends Exception {}
        class B extends Exception {}
        class C extends Exception {}

        void test(boolean b1, boolean b2) {
            try {
                if (b1) {
                    throw new A();
                }
                else if (b2) {
                    throw new B();
                }
                else {
                    throw new C();
                }
            }
            catch (final A | B | C ex) {
                System.out.println("Exception caught");
            }
        }
    }

    static final int TYPES_IN_MULTICATCH = 3;
    static final String SUBTEST_NAME = Pos05sub.class.getName() + ".class";
    static final String TEST_METHOD_NAME = "test";

    public static void main(String... args) throws Exception {
        new Pos05().run();
    }

    public void run() throws Exception {
        String workDir = System.getProperty("test.classes");
        File compiledTest = new File(workDir, SUBTEST_NAME);
        verifyMulticatchExceptionRanges(compiledTest);
    }

    void verifyMulticatchExceptionRanges(File f) {
        System.err.println("verify: " + f);
        try {
            int count = 0;
            ClassFile cf = ClassFile.read(f);
            Method testMethod = null;
            for (Method m : cf.methods) {
                if (m.getName(cf.constant_pool).equals(TEST_METHOD_NAME)) {
                    testMethod = m;
                    break;
                }
            }
            if (testMethod == null) {
                throw new Error("Test method not found");
            }
            Code_attribute ea = (Code_attribute)testMethod.attributes.get(Attribute.Code);
            if (testMethod == null) {
                throw new Error("Code attribute for test() method not found");
            }
            Exception_data firstExceptionTable = null;
            for (int i = 0 ; i < ea.exception_table_length; i++) {
                if (firstExceptionTable == null) {
                    firstExceptionTable = ea.exception_table[i];
                }
                if (ea.exception_table[i].handler_pc != firstExceptionTable.handler_pc ||
                        ea.exception_table[i].start_pc != firstExceptionTable.start_pc ||
                        ea.exception_table[i].end_pc != firstExceptionTable.end_pc) {
                    throw new Error("Multiple overlapping catch clause found in generated code");
                }
                count++;
            }
            if (count != TYPES_IN_MULTICATCH) {
                throw new Error("Wrong number of exception data found: " + count);
            }
        } catch (Exception e) {
            e.printStackTrace();
            throw new Error("error reading " + f +": " + e);
        }
    }
}
