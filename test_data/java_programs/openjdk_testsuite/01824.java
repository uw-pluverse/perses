






import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.tools.*;
import com.sun.source.util.*;
import com.sun.tools.javac.api.*;


public class T6348499 {
    public static void main(String... args) {
        String testSrc = System.getProperty("test.src", ".");
        String testClasses = System.getProperty("test.classes");
        String testClassPath = System.getProperty("test.class.path", testClasses);
        String A_java = new File(testSrc, "A.java").getPath();
        JavacTool tool = JavacTool.create();
        MyDiagListener dl = new MyDiagListener();
        StandardJavaFileManager fm = tool.getStandardFileManager(dl, null, null);
        Iterable<? extends JavaFileObject> files =
            fm.getJavaFileObjectsFromFiles(Arrays.asList(new File(testSrc, "A.java")));
        Iterable<String> opts = Arrays.asList("-proc:only",
                                              "-processor", "A",
                                              "-processorpath", testClassPath);
        StringWriter out = new StringWriter();
        JavacTask task = tool.getTask(out, fm, dl, opts, null, files);
        task.call();
        String s = out.toString();
        System.err.print(s);
        
        
        
        
        
        System.err.println(dl.count + " diagnostics; " + s.length() + " characters");
        if (dl.count != 1 || s.length() != 0)
            throw new AssertionError("unexpected output from compiler");
    }

    static class MyDiagListener implements DiagnosticListener<JavaFileObject> {
        public void report(Diagnostic d) {
            System.err.println(d);
            count++;
        }

        public int count;
    }

    private static String self = T6348499.class.getName();
}
