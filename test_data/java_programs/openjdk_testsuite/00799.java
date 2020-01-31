



import java.io.*;
import java.util.*;
import javax.lang.model.element.*;
import javax.tools.*;
import com.sun.source.tree.*;
import com.sun.source.util.*;

public class TestJavacTask_ParseAttrGen {
    public static void main(String... args) throws Exception {
        new TestJavacTask_ParseAttrGen().run();
    }

    JavaCompiler comp;
    StandardJavaFileManager fm;

    void run() throws Exception {
        comp = ToolProvider.getSystemJavaCompiler();
        fm = comp.getStandardFileManager(null, null, null);

        final boolean[] booleanValues = { false, true };
        for (boolean pk: booleanValues) {
            for (boolean ak: booleanValues) {
                for (boolean gk: booleanValues) {
                    test(pk, ak, gk);
                }
            }
        }
    }

    void test(boolean pk, boolean ak, boolean gk) throws Exception {
        if (!pk && !ak && !gk)  
            return;

        System.err.println("test: pk:" + pk + ", ak:" + ak + ", gk: " + gk);
        File testSrc = new File(System.getProperty("test.src"));
        String thisClassName = TestJavacTask_ParseAttrGen.class.getName();
        Iterable<? extends JavaFileObject> files =
                fm.getJavaFileObjects(new File(testSrc, thisClassName + ".java"));
        File tmpDir = new File((pk ? "p" : "") + (ak ? "a" : "") + (gk ? "g" : ""));
        tmpDir.mkdirs();
        fm.setLocation(StandardLocation.CLASS_OUTPUT, Arrays.asList(tmpDir));
        JavacTask t = (JavacTask) comp.getTask(null, fm, null, null, null, files);
        

        try {
            if (pk) {
                Iterable<? extends CompilationUnitTree> trees = t.parse();
                System.err.println(count(trees) + " trees parsed");
            }

            if (ak) {
                Iterable<? extends Element> elems = t.analyze();
                System.err.println(count(elems) + " elements analyzed");
            }

            if (gk) {
                Iterable<? extends JavaFileObject> classfiles = t.generate();
                System.err.println(count(classfiles) + " class files generated");
            }
        } catch (IOException e) {
            error("unexpected exception caught: " + e);
        }

        File[] genFiles = tmpDir.listFiles();
        int expect = (gk ? 2 : 0); 
        if (genFiles.length != expect)
            error("unexpected number of files generated: " + genFiles.length
                    + ", expected: " + expect);

        System.err.println();
    }

    TaskListener createTaskListener() {
        return new TaskListener() {
            public void started(TaskEvent e) {
                System.err.println(e + " started");
            }

            public void finished(TaskEvent e) {
                System.err.println(e + " finished");
            }
        };
    }

    <T> int count(Iterable<T> items) {
        int count = 0;
        for (T item: items)
            count++;
        return count;
    }

    void error(String msg) {
        System.err.println("Error: " + msg);
        errors++;
    }

    int errors;
}
