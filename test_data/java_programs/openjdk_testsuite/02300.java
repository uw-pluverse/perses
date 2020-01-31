


import java.nio.file.Paths;
import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.Method;

public class ConstDebugTest {

    public static final long l = 12;

    public static void main(String args[]) throws Exception {
        ClassFile classFile = ClassFile.read(Paths.get(System.getProperty("test.classes"),
                ConstDebugTest.class.getSimpleName() + ".class"));
        for (Method method: classFile.methods) {
            if (method.getName(classFile.constant_pool).equals("<clinit>")) {
                throw new AssertionError(
                    "javac should not create a <clinit> method for ConstDebugTest class");
            }
        }
    }

}
