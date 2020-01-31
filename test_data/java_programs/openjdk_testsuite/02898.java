



import com.sun.source.util.JavacTask;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import javax.tools.Diagnostic;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import javax.tools.ToolProvider;

public class CompletionFailure {

    public static void main(String... args) throws Exception {

        String SCRATCH_DIR = System.getProperty("user.dir");
        JavaCompiler javacTool = ToolProvider.getSystemJavaCompiler();
        File scratchDir = new File(SCRATCH_DIR);

        sourceA.dumpTo(scratchDir);
        sourceB.dumpTo(scratchDir);

        JavacTask ct = (JavacTask)javacTool.getTask(null, null, null,
                null, null, Arrays.asList(sourceA.asJFO(scratchDir), sourceB.asJFO(scratchDir)));

        ct.generate();

        remove(scratchDir, "A.java");
        remove(scratchDir, "B.java");
        remove(scratchDir, "A.class");

        sourceC.dumpTo(scratchDir);
        sourceD.dumpTo(scratchDir);

        DiagnosticChecker diagChecker = new DiagnosticChecker();
        ct = (JavacTask)javacTool.getTask(null, null, diagChecker,
                Arrays.asList("-XDrawDiagnostics", "-cp", scratchDir.getAbsolutePath()),
                null, Arrays.asList(sourceC.asJFO(scratchDir), sourceD.asJFO(scratchDir)));
        try {
            ct.analyze();
        } catch (Throwable ex) {
            
        }

        if (!diagChecker.errorFound) {
            throw new AssertionError("Missing diagnostic");
        }
    }

    static void remove(File dir, String fileName) {
        File fileToRemove = new File(dir, fileName);
        fileToRemove.delete();
    }

    static class JavaSource {
        String contents;
        String filename;

        public JavaSource(String filename, String contents) {
            this.filename =  filename;
            this.contents = contents;
        }

        void dumpTo(java.io.File loc) throws Exception {
            File file = new File(loc, filename);
            BufferedWriter bw = new java.io.BufferedWriter(new FileWriter(file));
            bw.append(contents);
            bw.close();
        }

        SimpleJavaFileObject asJFO(java.io.File dir) {
            return new SimpleJavaFileObject(new File(dir, filename).toURI(), JavaFileObject.Kind.SOURCE) {
                @Override
                public CharSequence getCharContent(boolean ignoreEncodingErrors) throws IOException {
                    return contents;
                }
            };
        }
    }

    static JavaSource sourceA = new JavaSource("A.java", "public interface A { }\n");

    static JavaSource sourceB = new JavaSource("B.java", "public class B implements A {\n" +
                                               "   public static Object n() { return null; }\n" +
                                               "}\n");

    static JavaSource sourceC = new JavaSource("C.java", "public class C {\n" +
                                               "   void test(B b) {\n" +
                                               "      D.m(B.n());\n" +
                                               "}  }\n");

    static JavaSource sourceD = new JavaSource("D.java", "public class D {\n" +
                                               "   static void m(Object o) { }\n" +
                                               "}\n");

    static class DiagnosticChecker implements javax.tools.DiagnosticListener<JavaFileObject> {

        boolean errorFound;

        public void report(Diagnostic<? extends JavaFileObject> diagnostic) {
            if (diagnostic.getKind() == Diagnostic.Kind.ERROR &&
                    diagnostic.getCode().contains("compiler.err.cant.access")) {
                errorFound = true;
            }
        }
    }
}
