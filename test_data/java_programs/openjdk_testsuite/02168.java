



import java.io.*;
import java.util.*;
import javax.tools.*;
import com.sun.source.util.*;
import com.sun.tools.javac.api.*;

public class T6397286 {

    public static void main(String[] args) throws IOException {
        String testSrcDir = System.getProperty("test.src");
        String self = T6397286.class.getName();

        JavacTool tool = JavacTool.create();
        StandardJavaFileManager fm = tool.getStandardFileManager(null, null, null);
        Iterable<? extends JavaFileObject> files =
            fm.getJavaFileObjectsFromFiles(Arrays.asList(new File(testSrcDir, self + ".java")));

        JavacTask task = tool.getTask(null, fm, null, null, null, files);
        task.setTaskListener(new TaskListener() {
                public void started(TaskEvent e) {
                    throw new TaskEventError(e);
                }
                public void finished(TaskEvent e) {
                }
            });

        try {
            task.call();
            throw new AssertionError("no exception thrown");
        } catch (RuntimeException e) {
            if (e.getCause() instanceof TaskEventError) {
                TaskEventError tee = (TaskEventError) e.getCause();
                System.err.println("Exception thrown for " + tee.event + " as expected");
            } else {
                e.printStackTrace();
                throw new AssertionError("TaskEventError not thrown");
            }
        }
    }
}

class TaskEventError extends Error {
    public TaskEventError(TaskEvent ev) {
        event = ev;
    }

    TaskEvent event;
}
