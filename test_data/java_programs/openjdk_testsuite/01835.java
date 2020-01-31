






import java.io.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.*;
import javax.lang.model.element.*;
import javax.tools.*;
import com.sun.source.util.*;
import com.sun.tools.javac.api.*;


public class T6430209 {
    public static void main(String... args) throws IOException {
        
        File dir1 = new File("dir1");
        dir1.mkdir();
        BufferedWriter fout = new BufferedWriter(new FileWriter(new File(dir1, "test0.java")));
        fout.write("public class test0 { }");
        fout.close();

        
        
        String testSrc = System.getProperty("test.src", ".");
        String testClasses = System.getProperty("test.classes") + System.getProperty("path.separator") + "../../lib";
        JavacTool tool = JavacTool.create();
        MyDiagListener dl = new MyDiagListener();
        StandardJavaFileManager fm = tool.getStandardFileManager(dl, null, null);
        fm.setLocation(StandardLocation.CLASS_PATH, Arrays.asList(new File(".")));
        Iterable<? extends JavaFileObject> files = fm.getJavaFileObjectsFromFiles(Arrays.asList(
            new File(testSrc, "test0.java"), new File(testSrc, "test1.java")));
        Iterable<String> opts = Arrays.asList("-proc:only",
                                              "-processor", "b6341534",
                                              "-processorpath", testClasses);
        StringWriter out = new StringWriter();
        JavacTask task = tool.getTask(out, fm, dl, opts, null, files);
        task.call();
        String s = out.toString();
        System.err.print(s);
        
        System.err.println(dl.count + " diagnostics; " + s.length() + " characters");
        if (dl.count != 2 || s.length() != 0)
            throw new AssertionError("unexpected output from compiler");
    }

    static class MyDiagListener implements DiagnosticListener<JavaFileObject> {
        public void report(Diagnostic d) {
            System.err.println(d);
            count++;
        }

        public int count;
    }
}
