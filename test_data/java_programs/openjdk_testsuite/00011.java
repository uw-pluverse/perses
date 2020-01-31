



import java.util.Arrays;
import javax.tools.JavaFileObject;
import java.net.URI;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;
import javax.tools.JavaCompiler;
import com.sun.source.util.JavacTask;
import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.ConstantPoolException;
import java.io.File;
import java.io.IOException;

public class InnerClassCannotBeVerified {

    private static final String errorMessage =
            "Compile error while compiling the following source:\n";

    public static void main(String... args) throws Exception {
        new InnerClassCannotBeVerified().run();
    }

    void run() throws Exception {
        JavaCompiler comp = ToolProvider.getSystemJavaCompiler();
        JavaSource source = new JavaSource();
        JavacTask ct = (JavacTask)comp.getTask(null, null, null,
                null, null, Arrays.asList(source));
        try {
            if (!ct.call()) {
                throw new AssertionError(errorMessage +
                        source.getCharContent(true));
            }
        } catch (Throwable ex) {
            throw new AssertionError(errorMessage +
                    source.getCharContent(true));
        }
        check();
    }

    private void check() throws IOException, ConstantPoolException {
        File file = new File("Test$1.class");
        ClassFile classFile = ClassFile.read(file);
        boolean inheritsFromObject =
                classFile.getSuperclassName().equals("java/lang/Object");
        boolean implementsNoInterface = classFile.interfaces.length == 0;
        boolean noMethods = classFile.methods.length == 0;
        if (!(inheritsFromObject &&
              implementsNoInterface &&
              noMethods)) {
            throw new AssertionError("The inner classes reused as " +
                    "access constructor tag for this code must be empty");
        }
    }

    class JavaSource extends SimpleJavaFileObject {

        String internalSource =
                              "public class Test {\n" +
                              "    private static class Foo {}\n" +
                              "    public static void main(String[] args){ \n" +
                              "        new Foo();\n" +
                              "        if(false) {\n" +
                              "            new Runnable() {\n" +
                              "                @Override\n" +
                              "                public void run() {\n" +
                              "                    System.out.println();\n" +
                              "                }\n" +
                              "            }.run();\n" +
                              "        }\n" +
                              "   }\n" +
                              "}";
        public JavaSource() {
            super(URI.create("Test.java"), JavaFileObject.Kind.SOURCE);
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return internalSource;
        }
    }
}
