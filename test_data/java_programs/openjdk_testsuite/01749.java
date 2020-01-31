



import java.io.File;
import com.sun.tools.classfile.Attribute;
import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.Code_attribute;
import com.sun.tools.classfile.ConstantPool.CPRefInfo;
import com.sun.tools.classfile.Instruction;
import com.sun.tools.classfile.Method;
import com.sun.tools.classfile.Opcode;

interface BaseInterface {
    public default int testedMethod(){ return 1; }
}

interface IntermediateInterface extends BaseInterface {
}

interface TestInterface extends IntermediateInterface {
    public default void test() {
        IntermediateInterface.super.testedMethod();
    }
}

abstract class BaseClass implements BaseInterface { }

class TestClass extends BaseClass implements BaseInterface {
    public int testedMethod() {return 9;}
    public void test() {
        if (super.testedMethod() != 1)
            throw new IllegalStateException();
        if (TestClass.super.testedMethod() != 1)
            throw new IllegalStateException();
        new Runnable() {
            public void run() {
                if (TestClass.super.testedMethod() != 1)
                    throw new IllegalStateException();
            }
        }.run();
    }
}

public class TestDirectSuperInterfaceInvoke {
    public static void main(String... args) throws Exception {
        new TestDirectSuperInterfaceInvoke().run();
    }

    public void run() throws Exception {
        new TestClass().test();
        verifyDefaultBody("TestClass.class");
        new TestInterface() {}.test();
        verifyDefaultBody("TestInterface.class");
    }

    void verifyDefaultBody(String classFile) {
        String workDir = System.getProperty("test.classes");
        File file = new File(workDir, classFile);
        try {
            final ClassFile cf = ClassFile.read(file);
            for (Method m : cf.methods) {
                Code_attribute codeAttr = (Code_attribute)m.attributes.get(Attribute.Code);
                for (Instruction instr : codeAttr.getInstructions()) {
                    if (instr.getOpcode() == Opcode.INVOKESPECIAL) {
                        int pc_index = instr.getShort(1);
                        CPRefInfo ref = (CPRefInfo)cf.constant_pool.get(pc_index);
                        String className = ref.getClassName();
                        if (className.equals("BaseInterface"))
                            throw new IllegalStateException("Must not directly refer to TestedInterface");
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
            throw new Error("error reading " + file +": " + e);
        }
    }

}
