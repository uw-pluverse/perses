



import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.URI;
import java.util.ArrayList;
import java.util.List;
import javax.tools.Diagnostic;
import javax.tools.DiagnosticCollector;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileManager;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;

public class TreeEndPosTest {
    private static JavaFileManager getJavaFileManager(JavaCompiler compiler,
            DiagnosticCollector dc) {
        return compiler.getStandardFileManager(dc, null, null);
    }

    static class JavaSource extends SimpleJavaFileObject {

        final String source;
        int startPos;
        int endPos;

        private JavaSource(String filename, String source) {
            super(URI.create("myfo:/" + filename), JavaFileObject.Kind.SOURCE);
            this.source = source;
        }

        @Override
        public CharSequence getCharContent(boolean ignoreEncodingErrors) {
            return source;
        }

        static JavaSource createJavaSource(String preamble, String body,
                String postamble, String expected) {
            JavaSource js = createJavaSource(preamble, body, postamble, -1, -1);
            js.startPos = js.source.indexOf(expected);
            js.endPos   = js.startPos + expected.length();
            return js;
        }

        static JavaSource createJavaSource(String body, String expected) {
            return createJavaSource(null, body, null, expected);
        }

        private static JavaSource createJavaSource(String preamble, String body,
                String postamble, int start, int end) {
            final String name = "Bug";
            StringBuilder code = new StringBuilder();
            if (preamble != null) {
                code.append(preamble);
            }
            code.append("public class " + name + "{");
            if (body != null) {
                code.append(body);
            }
            code.append("}");
            if (postamble != null) {
                code.append(postamble);
            }
            JavaSource js = new JavaSource(name + ".java", code.toString());
            js.startPos = start;
            js.endPos = end;
            return js;
        }
    }

    public static void main(String... args) throws IOException {
        testUninitializedVariable();
        testMissingAnnotationValue();
        testFinalVariableWithDefaultConstructor();
        testFinalVariableWithConstructor();
    }

    static void testUninitializedVariable() throws IOException {
        compile(JavaSource.createJavaSource("Object o = new A().new B(); class A { }",
                "B()"));
    }
    static void testMissingAnnotationValue() throws IOException {
        compile(JavaSource.createJavaSource("@Foo(\"vvvv\")",
                null, "@interface Foo { }", "\"vvvv\""));
    }

    static void testFinalVariableWithDefaultConstructor() throws IOException {
        compile(JavaSource.createJavaSource("private static final String Foo; public void bar() { }",
                "private static final String Foo;"));
    }

    static void testFinalVariableWithConstructor() throws IOException {
        compile(JavaSource.createJavaSource("public Bug (){} private static final String Foo; public void bar() { }",
                "{}"));
    }

    static void compile(JavaSource src) throws IOException {
        ByteArrayOutputStream ba = new ByteArrayOutputStream();
        PrintWriter writer = new PrintWriter(ba);
        File tempDir = new File(".");
        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        DiagnosticCollector dc = new DiagnosticCollector();
        JavaFileManager javaFileManager = getJavaFileManager(compiler, dc);
        List<String> options = new ArrayList<>();
        options.add("-cp");
        options.add(tempDir.getPath());
        options.add("-d");
        options.add(tempDir.getPath());
        options.add("-XDshouldStopPolicy=GENERATE");

        List<JavaFileObject> sources = new ArrayList<>();
        sources.add(src);
        JavaCompiler.CompilationTask task =
                compiler.getTask(writer, javaFileManager,
                dc, options, null,
                sources);
        task.call();
        for (Diagnostic diagnostic : (List<Diagnostic>) dc.getDiagnostics()) {
            long actualStart = diagnostic.getStartPosition();
            long actualEnd = diagnostic.getEndPosition();
            System.out.println("Source: " + src.source);
            System.out.println("Diagnostic: " + diagnostic);
            System.out.print("Start position: Expected: " + src.startPos);
            System.out.println(", Actual: " + actualStart);
            System.out.print("End position: Expected: " + src.endPos);
            System.out.println(", Actual: " + actualEnd);
            if (src.startPos != actualStart || src.endPos != actualEnd) {
                throw new RuntimeException("error: trees don't match");
            }
        }
    }
}
