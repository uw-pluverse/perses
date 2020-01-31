



import java.io.*;
import java.net.*;
import java.util.*;
import javax.annotation.processing.*;
import javax.lang.model.element.*;
import javax.tools.*;
import com.sun.source.util.*;
import com.sun.tools.javac.api.*;
import com.sun.source.util.Trees;

@SupportedAnnotationTypes("*")
public class T6361619 extends AbstractProcessor {
    public static void main(String... args) throws Throwable {
        String testSrcDir = System.getProperty("test.src");
        String testClassDir = System.getProperty("test.classes");
        String self = T6361619.class.getName();

        JavacTool tool = JavacTool.create();

        final PrintWriter out = new PrintWriter(System.err, true);

        Iterable<String> flags = Arrays.asList("-processorpath", testClassDir,
                                               "-processor", self,
                                               "-d", ".");
        DiagnosticListener<JavaFileObject> dl = new DiagnosticListener<JavaFileObject>() {
            public void report(Diagnostic<? extends JavaFileObject> m) {
                out.println(m);
            }
        };

        StandardJavaFileManager fm = tool.getStandardFileManager(dl, null, null);
        Iterable<? extends JavaFileObject> f =
            fm.getJavaFileObjectsFromFiles(Arrays.asList(new File(testSrcDir,
                                                                  self + ".java")));

        JavacTask task = tool.getTask(out, fm, dl, flags, null, f);
        MyTaskListener tl = new MyTaskListener(task);
        task.setTaskListener(tl);

        
        task.call();
    }

    public boolean process(Set<? extends TypeElement> elems, RoundEnvironment renv) {
        return true;
    }


    static class MyTaskListener implements TaskListener {
        public MyTaskListener(JavacTask task) {
            this.task = task;
        }

        public void started(TaskEvent e) {
            System.err.println("Started: " + e);
            Trees t = Trees.instance(task);
        }
        public void finished(TaskEvent e) {
            System.err.println("Finished: " + e);
            Trees t = Trees.instance(task);
        }

        JavacTask task;
    }
}
