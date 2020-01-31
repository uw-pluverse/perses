



import java.io.*;
import java.util.*;
import javax.tools.*;
import com.sun.source.util.*;
import com.sun.tools.javac.api.*;


public class T6395974 {
    public static void main(String... args) throws Throwable {
        String self = T6395974.class.getName();

        String testSrc = System.getProperty("test.src");

        JavacTool tool = JavacTool.create();
        StandardJavaFileManager fm = tool.getStandardFileManager(null, null, null);
        Iterable<?extends JavaFileObject> f =
            fm.getJavaFileObjectsFromFiles(Arrays.asList(new File(testSrc, self + ".java")));

        PrintWriter out = new PrintWriter(System.err, true);

        JavacTaskImpl task = (JavacTaskImpl) tool.getTask(out,
                                                          fm,
                                                          null,
                                                          Arrays.asList("-processor",
                                                                        "Foo.java"),
                                                          null,
                                                          f);

        MyTaskListener tl = new MyTaskListener();
        task.setTaskListener(tl);

        task.call();

        if (tl.event != null)
            throw new AssertionError("Unexpected TaskListener event: " + tl.event);
    }

    static class MyTaskListener implements TaskListener {
        public void started(TaskEvent e) {
            System.err.println("Started: " + e);
            if (event == null)
                event = e;
        }
        public void finished(TaskEvent e) {
        }

        TaskEvent event;
    }
}
