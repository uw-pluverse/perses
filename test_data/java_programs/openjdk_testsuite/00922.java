



import com.sun.source.util.JavacTask;
import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.ConstantPoolException;
import java.io.File;
import java.io.IOException;
import java.net.URI;
import java.util.Arrays;
import java.util.List;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;



public class DuplicateConstantPoolEntry {

    public static void main(String args[]) throws Exception {
        new DuplicateConstantPoolEntry().run();
    }

    void run() throws Exception {
        generateFilesNeeded();
        checkReference();
    }

    void generateFilesNeeded() throws Exception {

        StringJavaFileObject[] CSource = new StringJavaFileObject[] {
            new StringJavaFileObject("C.java",
                "class C {C(String s) {}}"),
        };

        List<StringJavaFileObject> AandBSource = Arrays.asList(
                new StringJavaFileObject("A.java",
                    "class A {void test() {new B(null);new C(null);}}"),
                new StringJavaFileObject("B.java",
                    "class B {B(String s) {}}")
        );

        final JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        JavacTask compileC = (JavacTask)tool.getTask(null, null, null, null, null,
                Arrays.asList(CSource));
        if (!compileC.call()) {
            throw new AssertionError("Compilation error while compiling C.java sources");
        }
        JavacTask compileAB = (JavacTask)tool.getTask(null, null, null,
                Arrays.asList("-cp", "."), null, AandBSource);
        if (!compileAB.call()) {
            throw new AssertionError("Compilation error while compiling A and B sources");
        }
    }

    void checkReference() throws IOException, ConstantPoolException {
        File file = new File("A.class");
        ClassFile classFile = ClassFile.read(file);
        for (int i = 1;
                i < classFile.constant_pool.size() - 1;
                i += classFile.constant_pool.get(i).size()) {
            for (int j = i + classFile.constant_pool.get(i).size();
                    j < classFile.constant_pool.size();
                    j += classFile.constant_pool.get(j).size()) {
                if (classFile.constant_pool.get(i).toString().
                        equals(classFile.constant_pool.get(j).toString())) {
                    throw new AssertionError(
                            "Duplicate entries in the constant pool at positions " +
                            i + " and " + j);
                }
            }
        }
    }

    private static class StringJavaFileObject extends SimpleJavaFileObject {
        StringJavaFileObject(String name, String text) {
            super(URI.create(name), JavaFileObject.Kind.SOURCE);
            this.text = text;
        }
        @Override
        public CharSequence getCharContent(boolean b) {
            return text;
        }
        private String text;
    }
}
