

import java.io.*;
import java.util.*;
import javax.tools.*;
import com.sun.tools.javac.file.*;
import com.sun.tools.javac.file.JavacFileManager;
import com.sun.tools.javac.util.*;


public class T6625520 {
    public static void main(String[] args) throws Exception {
        new T6625520().run();
    }

    void run() throws Exception {
        Context c = new Context();
        DiagnosticCollector<JavaFileObject> dc =
            new DiagnosticCollector<JavaFileObject>();
        c.put(DiagnosticListener.class, dc);
        StandardJavaFileManager fm = new JavacFileManager(c, false, null);
        fm.setLocation(StandardLocation.CLASS_PATH,
                       Arrays.asList(new File("DOES_NOT_EXIST.jar")));
        FileObject fo = fm.getFileForInput(StandardLocation.CLASS_PATH,
                                           "p", "C.java");
        System.err.println(fo + "\n" + dc.getDiagnostics());
        if (dc.getDiagnostics().size() > 0)
            throw new Exception("unexpected diagnostics found");
    }
}
