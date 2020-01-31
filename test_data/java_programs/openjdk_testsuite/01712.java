



import com.sun.tools.classfile.Instruction;
import com.sun.tools.classfile.Attribute;
import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.Code_attribute;
import com.sun.tools.classfile.ConstantPool.*;
import com.sun.tools.classfile.Method;

import java.lang.invoke.*;
import java.io.*;

public class TestCP {

    static class TestClass {
        void test(MethodHandle mh) throws Throwable {
            Number n = (Number)mh.invokeExact("daddy",1,'n');
            n = (Number)mh.invokeExact("bunny",1,'d');
            n = (Number)(mh.invokeExact("foo",1,'d'));
            n = (Number)((mh.invokeExact("bar",1,'d')));
        }
    }

    static final String PS_TYPE = "(Ljava/lang/String;IC)Ljava/lang/Number;";
    static final int PS_CALLS_COUNT = 4;
    static final String SUBTEST_NAME = TestClass.class.getName() + ".class";
    static final String TEST_METHOD_NAME = "test";

    public static void main(String... args) throws Exception {
        new TestCP().run();
    }

    public void run() throws Exception {
        String workDir = System.getProperty("test.classes");
        File compiledTest = new File(workDir, SUBTEST_NAME);
        verifyMethodHandleInvocationDescriptors(compiledTest);
    }

    void verifyMethodHandleInvocationDescriptors(File f) {
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
            int instr_count = 0;
            int cp_entry = -1;

            for (Instruction i : ea.getInstructions()) {
                if (i.getMnemonic().equals("invokevirtual")) {
                    instr_count++;
                    if (cp_entry == -1) {
                        cp_entry = i.getUnsignedShort(1);
                    } else if (cp_entry != i.getUnsignedShort(1)) {
                        throw new Error("Unexpected CP entry in polymorphic signature call");
                    }
                    CONSTANT_Methodref_info methRef =
                            (CONSTANT_Methodref_info)cf.constant_pool.get(cp_entry);
                    String type = methRef.getNameAndTypeInfo().getType();
                    if (!type.equals(PS_TYPE)) {
                        throw new Error("Unexpected type in polymorphic signature call: " + type);
                    }
                }
            }
            if (instr_count != PS_CALLS_COUNT) {
                throw new Error("Wrong number of polymorphic signature call found: " + instr_count);
            }
        } catch (Exception e) {
            e.printStackTrace();
            throw new Error("error reading " + f +": " + e);
        }
    }
}
