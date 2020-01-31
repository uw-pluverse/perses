



import java.io.File;
import java.io.IOException;

import com.sun.tools.classfile.Attribute;
import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.Code_attribute;
import com.sun.tools.classfile.Code_attribute.InvalidIndex;
import com.sun.tools.classfile.ConstantPool;
import com.sun.tools.classfile.ConstantPoolException;
import com.sun.tools.classfile.Descriptor.InvalidDescriptor;
import com.sun.tools.classfile.Method;

public class RedundantByteCodeInArrayTest {
    public static void main(String[] args)
            throws IOException, ConstantPoolException, InvalidDescriptor, InvalidIndex {
        new RedundantByteCodeInArrayTest()
                .checkClassFile(new File(System.getProperty("test.classes", "."),
                    RedundantByteCodeInArrayTest.class.getName() + ".class"));
    }

    void arrMethod(int[] array, int p, int inc) {
        array[p] += inc;
    }

    void checkClassFile(File file)
            throws IOException, ConstantPoolException, InvalidDescriptor, InvalidIndex {
        ClassFile classFile = ClassFile.read(file);
        ConstantPool constantPool = classFile.constant_pool;

        
        for (Method method : classFile.methods) {
            if (method.getName(constantPool).equals("arrMethod")) {
                Code_attribute code = (Code_attribute) method.attributes
                        .get(Attribute.Code);
                if (code.max_locals > 4)
                    throw new AssertionError("Too many locals for method arrMethod");
            }
        }
    }
}
