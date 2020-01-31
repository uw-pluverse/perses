



import java.io.File;
import java.lang.annotation.ElementType;
import java.lang.annotation.Target;
import java.nio.file.Paths;

import com.sun.tools.classfile.Attribute;
import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.Code_attribute;
import com.sun.tools.classfile.Method;

public class DontGenerateLVTForGNoneOpTest {

    public static void main(String[] args) throws Exception {
        new DontGenerateLVTForGNoneOpTest().run();
    }

    void run() throws Exception {
        checkClassFile(new File(Paths.get(System.getProperty("test.classes"),
                this.getClass().getName() + ".class").toUri()));
    }

    void checkClassFile(final File cfile) throws Exception {
        ClassFile classFile = ClassFile.read(cfile);
        for (Method method : classFile.methods) {
            Code_attribute code = (Code_attribute)method.attributes.get(Attribute.Code);
            if (code != null) {
                if (code.attributes.get(Attribute.LocalVariableTable) != null) {
                    throw new AssertionError("LVT shouldn't be generated for g:none");
                }
            }
        }
    }

    public void bar() {
        try {
            System.out.println();
        } catch(@TA Exception e) {
        } catch(Throwable t) {}
    }

    @Target(ElementType.TYPE_USE)
    @interface TA {}
}
