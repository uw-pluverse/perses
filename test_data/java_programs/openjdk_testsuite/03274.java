



import java.io.IOException;
import java.net.URI;
import java.util.Arrays;
import java.util.List;

import javax.tools.DiagnosticListener;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;

import com.sun.source.util.JavacTask;

public class T8031967 {

    public static void main(String... args) throws IOException {
        new T8031967().run();
    }

    final int depth = 50;

    private void run() throws IOException {
        runTestCase(true);
        runTestCase(false);
    }

    private void runTestCase(boolean withErrors) throws IOException {
        StringBuilder code = new StringBuilder();

        code.append("public class Test {\n" +
                    "    private void test() {\n" +
                    "        GroupLayout l = new GroupLayout();\n" +
                    "        l.setHorizontalGroup(\n");

        gen(code, depth);
        code.append("        );\n" +
                    "    }\n");
        if (!withErrors) {
            code.append("    class GroupLayout {\n" +
                        "        ParallelGroup createParallelGroup() {return null;}\n" +
                        "        ParallelGroup createParallelGroup(int i) {return null;}\n" +
                        "        ParallelGroup createParallelGroup(int i, int j) {return null;}\n" +
                        "        void setHorizontalGroup(Group g) { }\n" +
                        "    }\n" +
                        "    \n" +
                        "    class Group {\n" +
                        "        Group addGroup(Group g) { return this; }\n" +
                        "        Group addGroup(int i, Group g) { return this; }\n" +
                        "        Group addGap(int i) { return this; }\n" +
                        "        Group addGap(long l) { return this; }\n" +
                        "        Group addGap(int i, int j) { return this; }\n" +
                        "        Group addComponent(Object c) { return this; }\n" +
                        "        Group addComponent(int i, Object c) { return this; }\n" +
                        "    }\n" +
                        "    class ParallelGroup extends Group {\n" +
                        "        Group addGroup(Group g) { return this; }\n" +
                        "        Group addGroup(int i, Group g) { return this; }\n" +
                        "        Group addGap(int i) { return this; }\n" +
                        "        Group addGap(int i, int j) { return this; }\n" +
                        "        Group addComponent(Object c) { return this; }\n" +
                        "        Group addComponent(int i, Object c) { return this; }\n" +
                        "    }\n");
        }

        code.append("}\n");

        JavaSource source = new JavaSource(code.toString());
        List<JavaSource> sourceList = Arrays.asList(source);
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        DiagnosticListener<JavaFileObject> noErrors = (diagnostic) -> {
            throw new IllegalStateException("Should not produce errors: " + diagnostic);
        };
        JavacTask task = (JavacTask) compiler.getTask(null, null, withErrors ? null : noErrors,
                null, null, sourceList);

        task.analyze();
    }

    private void gen(StringBuilder code, int depth) {
        code.append("l.createParallelGroup()\n");
        if (depth > 0) {
            code.append(".addGroup(\n");
            gen(code, depth - 1);
            code.append(")");
        }

        code.append(".addGap(1)\n" +
                    ".addComponent(new Object())\n" +
                    ".addGap(1)\n" +
                    ".addComponent(new Object())");
    }

    class JavaSource extends SimpleJavaFileObject {

        final String code;
        public JavaSource(String code) {
            super(URI.create("myfo:/Test.java"), JavaFileObject.Kind.SOURCE);
            this.code = code;
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return code;
        }
    }
}
