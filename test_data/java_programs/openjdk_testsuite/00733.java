



import java.io.*;
import java.util.*;
import javax.tools.*;
import javax.tools.JavaCompiler.CompilationTask;
import com.sun.source.util.*;

public class TestJavacTask_Multiple {
    public static void main(String... args) throws Exception {
        new TestJavacTask_Multiple().run();
    }

    final int MAX_TASKS = 3;

    enum TestKind {
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

    int count;

    void run() throws Exception {
        JavaCompiler comp = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager fm = comp.getStandardFileManager(null, null, null);
        for (TestKind tk: TestKind.values()) {
            test(comp, fm, tk);
        }

        int expect = TestKind.values().length * MAX_TASKS;
        if (count != expect) {
            throw new Exception("Unexpected number of tests completed: " + count
                    + ", expected: " + expect);
        }

    }

    void test(JavaCompiler comp, StandardJavaFileManager fm, TestKind tk) {
        System.err.println("test " + tk);
        File testSrc = new File(System.getProperty("test.src"));
        String thisClassName = TestJavacTask_Multiple.class.getName();
        Iterable<? extends JavaFileObject> files =
                fm.getJavaFileObjects(new File(testSrc, thisClassName + ".java"));

        List<CompilationTask> tasks = new ArrayList<CompilationTask>();
        for (int i = 1; i <= MAX_TASKS; i++) {
            File tmpDir = new File(tk + "_" + i);
            tmpDir.mkdirs();
            List<String> options = Arrays.asList( "-d", tmpDir.getPath() );
            CompilationTask t = comp.getTask(null, fm, null, options, null, files);
            ((JavacTask) t).setTaskListener(createTaskListener(tk, i));
            tasks.add(t);
        }

        for (CompilationTask t: tasks)
            count += tk.test(t);

        System.err.println();
    }

    TaskListener createTaskListener(final TestKind tk, final int i) {
        return new TaskListener() {

            public void started(TaskEvent e) {
                System.err.println(tk + "." + i + ": " + e + " started");
            }

            public void finished(TaskEvent e) {
                System.err.println(tk + "." + i + ": " + e + " finished");
            }
        };
    }
}
