



import java.io.File;
import java.io.IOException;
import java.net.URI;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;
import com.sun.source.util.JavacTask;
import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.ConstantPoolException;
import com.sun.tools.classfile.Descriptor;
import com.sun.tools.classfile.Descriptor.InvalidDescriptor;
import com.sun.tools.classfile.Method;

import static com.sun.tools.classfile.AccessFlags.ACC_STRICT;

public class CheckACC_STRICTFlagOnPkgAccessClassTest {

    private static final String AssertionErrorMessage =
        "All methods should have the ACC_STRICT access flag " +
        "please check output";
    private static final String CompilationErrorMessage =
        "Error thrown when compiling the following source:\n";
    private static final String offendingMethodErrorMessage =
        "Method %s of class %s doesn't have the ACC_STRICT access flag";

    JavaSource source = new JavaSource();

    private List<String> errors = new ArrayList<>();

    public static void main(String[] args)
            throws IOException, ConstantPoolException, InvalidDescriptor {
        JavaCompiler comp = ToolProvider.getSystemJavaCompiler();
        new CheckACC_STRICTFlagOnPkgAccessClassTest().run(comp);
    }

    private void run(JavaCompiler comp)
            throws IOException, ConstantPoolException, InvalidDescriptor {
        compile(comp);
        check();
        if (errors.size() > 0) {
            for (String error: errors) {
                System.err.println(error);
            }
            throw new AssertionError(AssertionErrorMessage);
        }
    }

    private void compile(JavaCompiler comp) {
        JavacTask ct = (JavacTask)comp.getTask(null, null, null, null, null,
                Arrays.asList(source));
        try {
            if (!ct.call()) {
                throw new AssertionError(CompilationErrorMessage +
                        source.getCharContent(true));
            }
        } catch (Throwable ex) {
            throw new AssertionError(CompilationErrorMessage +
                    source.getCharContent(true));
        }
    }

    void check()
        throws
            IOException,
            ConstantPoolException,
            Descriptor.InvalidDescriptor {
        ClassFile classFileToCheck = ClassFile.read(new File("Test.class"));

        for (Method method : classFileToCheck.methods) {
            if ((method.access_flags.flags & ACC_STRICT) == 0) {
                errors.add(String.format(offendingMethodErrorMessage,
                        method.getName(classFileToCheck.constant_pool),
                        classFileToCheck.getName()));
            }
        }
    }

    class JavaSource extends SimpleJavaFileObject {

        String source = "strictfp class Test {" +
                "    Test(){}" +
                "    void m(){}" +
                "}";

        public JavaSource() {
            super(URI.create("Test.java"), JavaFileObject.Kind.SOURCE);
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return source;
        }
    }
}
