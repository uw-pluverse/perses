



import java.io.*;
import java.net.URL;
import com.sun.tools.classfile.*;
import static com.sun.tools.classfile.AccessFlags.ACC_STRICT;

public class LambdaTestStrictFPFlag {
    public static void main(String[] args) throws Exception {
        new LambdaTestStrictFPFlag().run();
    }

    void run() throws Exception {
        ClassFile cf = getClassFile("LambdaTestStrictFPFlag$Test.class");
        ConstantPool cp = cf.constant_pool;
        boolean found = false;
        for (Method meth: cf.methods) {
            if (meth.getName(cp).startsWith("lambda$")) {
                if ((meth.access_flags.flags & ACC_STRICT) == 0) {
                    throw new Exception("strict flag missing from lambda");
                }
                found = true;
            }
        }
        if (!found) {
            throw new Exception("did not find lambda method");
        }
    }

    ClassFile getClassFile(String name) throws IOException, ConstantPoolException {
        URL url = getClass().getResource(name);
        InputStream in = url.openStream();
        try {
            return ClassFile.read(in);
        } finally {
            in.close();
        }
    }

    class Test {
        strictfp void test() {
            Face itf = () -> { };
        }
    }

    interface Face {
        void m();
    }
}
