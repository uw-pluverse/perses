



import com.sun.tools.classfile.ClassFile;
import com.sun.tools.classfile.Method;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.tools.FileObject;
import javax.tools.ForwardingJavaFileManager;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileManager;
import javax.tools.JavaFileObject;
import javax.tools.JavaFileObject.Kind;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;

public class TestNonSerializableLambdaNameStability {

    public static void main(String... args) throws Exception {
        new TestNonSerializableLambdaNameStability().run();
    }

    String lambdaSource = "public class L%d {\n" +
                          "    public static class A {\n" +
                          "        private Runnable r = () -> { };\n" +
                          "    }\n" +
                          "    public static class B {\n" +
                          "        private Runnable r = () -> { };\n" +
                          "    }\n" +
                          "    private Runnable r = () -> { };\n" +
                          "}\n";

    String expectedLambdaMethodName = "lambda$new$0";

    void run() throws Exception {
        List<JavaFileObject> sources = new ArrayList<>();

        for (int i = 0; i < 3; i++) {
            sources.add(new SourceJavaFileObject("L" + i, String.format(lambdaSource, i)));
        }

        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();

        try (MemoryFileManager fm = new MemoryFileManager(compiler.getStandardFileManager(null, null, null))) {
            if (!compiler.getTask(null, fm, null, null, null, sources).call()) {
                throw new AssertionError("Compilation failed!");
            }

            for (String file : fm.name2Content.keySet()) {
                byte[] fileBytes = fm.name2Content.get(file);
                try (InputStream in = new ByteArrayInputStream(fileBytes)) {
                    boolean foundLambdaMethod = false;
                    ClassFile cf = ClassFile.read(in);
                    StringBuilder seenMethods = new StringBuilder();
                    String sep = "";
                    for (Method m : cf.methods) {
                        String methodName = m.getName(cf.constant_pool);
                        if (expectedLambdaMethodName.equals(methodName)) {
                            foundLambdaMethod = true;
                            break;
                        }
                        seenMethods.append(sep);
                        seenMethods.append(methodName);
                        sep = ", ";
                    }

                    if (!foundLambdaMethod) {
                        throw new AbstractMethodError("Did not find the lambda method, " +
                                                      "found methods: " + seenMethods.toString());
                    }
                }
            }
        }
    }

    class MemoryFileManager extends ForwardingJavaFileManager<JavaFileManager> {

        final Map<String, byte[]> name2Content = new HashMap<>();

        public MemoryFileManager(JavaFileManager fileManager) {
            super(fileManager);
        }

        @Override
        public JavaFileObject getJavaFileForOutput(Location location, String className, Kind kind, FileObject sibling) throws IOException {
            try {
                return new SimpleJavaFileObject(new URI("mem://" + className.replace('.', '/') + kind.extension), kind) {
                    @Override public OutputStream openOutputStream() throws IOException {
                        return new ByteArrayOutputStream() {
                            @Override public void close() throws IOException {
                                super.close();
                                name2Content.put(className, toByteArray());
                            }
                        };
                    }
                };
            } catch (URISyntaxException ex) {
                throw new AssertionError(ex);
            }
        }

    }

    class SourceJavaFileObject extends SimpleJavaFileObject {

        private final String code;

        public SourceJavaFileObject(String name, String code) throws URISyntaxException {
            super(new URI("mem:///" + name + ".java"), Kind.SOURCE);
            this.code = code;
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) throws IOException {
            return code;
        }

    }
}
