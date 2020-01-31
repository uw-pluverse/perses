



import java.io.*;
import java.util.*;
import javax.tools.*;
import javax.tools.JavaCompiler.CompilationTask;
import com.sun.source.util.*;

public class TestJavacTask_Lock {
    public static void main(String... args) throws Exception {
        new TestJavacTask_Lock().run();
    }

    enum MethodKind {
        CALL {
            int test(CompilationTask t) {
                boolean ok = t.call();
                if (!ok)
                    throw new Error("compilation failed");
                return 1;
            }
        },
        PARSE {
            int test(CompilationTask t) {
                try {
                    ((JavacTask) t).parse();
                return 1;
                } catch (IOException ex) {
                    throw new Error(ex);
                }
            }

        };
        abstract int test(CompilationTask t);
    }

    JavaCompiler comp;
    StandardJavaFileManager fm;

    void run() throws Exception {
        comp = ToolProvider.getSystemJavaCompiler();
        fm = comp.getStandardFileManager(null, null, null);

        for (MethodKind first: MethodKind.values()) {
            for (MethodKind second: MethodKind.values()) {
                test(first, second);
            }
        }

        if (errors > 0)
            throw new Exception(errors + " errors found");
    }

    void test(MethodKind first, MethodKind second) {
        System.err.println("test: " + first + ", " + second);
        File testSrc = new File(System.getProperty("test.src"));
        String thisClassName = TestJavacTask_Lock.class.getName();
        Iterable<? extends JavaFileObject> files =
                fm.getJavaFileObjects(new File(testSrc, thisClassName + ".java"));
        File tmpDir = new File(first + "_" + second);
        tmpDir.mkdirs();
        List<String> options = Arrays.asList( "-d", tmpDir.getPath() );
        CompilationTask t = comp.getTask(null, fm, null, options, null, files);

        try {
            first.test(t);
            second.test(t);
            error("No exception thrown");
        } catch (IllegalStateException e) {
            System.err.println("Expected exception caught: " + e);
        } catch (Exception e) {
            error("Unexpected exception caught: " + e);
            e.printStackTrace(System.err);
        }

    }

    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    int errors;
}
