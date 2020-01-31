



import java.io.*;
import java.util.*;
import javax.tools.*;
import com.sun.source.util.*;
import com.sun.tools.javac.api.*;

public class T6431435 {
    public static void main(String... args) throws IOException {
        String testSrc = System.getProperty("test.src", ".");
        String testClasses = System.getProperty("test.classes", ".");
        JavacTool tool = JavacTool.create();
        StandardJavaFileManager fm = tool.getStandardFileManager(null, null, null);
        fm.setLocation(StandardLocation.CLASS_OUTPUT, Arrays.asList(new File(".")));
        fm.setLocation(StandardLocation.SOURCE_PATH, Arrays.asList(new File(testSrc)));
        Iterable<? extends JavaFileObject> files = fm.getJavaFileObjectsFromFiles(Arrays.asList(
                new File(testSrc, "A.java")));
        JavacTask task = tool.getTask(null, fm, null, null, null, files);
        boolean ok = true;
        ok &= check("parse", task.parse(), 1);       
        ok &= check("analyze", task.analyze(), 3);   
        ok &= check("generate", task.generate(), 5); 
        if (!ok)
            throw new AssertionError("Test failed");
    }

    private static boolean check(String name, Iterable<?> iter, int expect) {
        int found = 0;
        for (Object o: iter) {
            found++;
            
        }
        if (found == expect)
            return true;
        System.err.println(name + ": found " + found + " -- expected " + expect);
        return false;
    }
}
