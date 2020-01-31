



import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import javax.tools.Diagnostic;
import javax.tools.DiagnosticListener;
import javax.tools.JavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.StandardLocation;
import com.sun.source.util.JavacTask;
import com.sun.tools.javac.api.JavacTool;

public class T6410706 {
    public static void main(String... args) throws IOException {
        String testSrc = System.getProperty("test.src", ".");
        String testClasses = System.getProperty("test.classes", ".");
        JavacTool tool = JavacTool.create();
        MyDiagListener dl = new MyDiagListener();
        StandardJavaFileManager fm = tool.getStandardFileManager(dl, null, null);
        fm.setLocation(StandardLocation.CLASS_OUTPUT, Arrays.asList(new File(testClasses)));
        Iterable<? extends JavaFileObject> files =
            fm.getJavaFileObjectsFromFiles(Arrays.asList(new File(testSrc, T6410706.class.getName()+".java")));
        JavacTask task = tool.getTask(null, fm, dl, null, null, files);
        task.parse();
        task.analyze();
        task.generate();

        
        
        

        if (dl.notes != 2)
            throw new AssertionError(dl.notes + " notes given");
    }

    private static class MyDiagListener implements DiagnosticListener<JavaFileObject>
    {
        public void report(Diagnostic d) {
            System.err.println(d);
            if (d.getKind() == Diagnostic.Kind.NOTE)
                notes++;
        }

        int notes;
    }

    Foo foo; 
}

@Deprecated class Foo { }
