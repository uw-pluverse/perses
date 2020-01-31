


import java.io.*;
import java.util.Arrays;
import javax.tools.*;
import com.sun.source.util.*;

public class T6357331
{
    public static void main(String... args) {
        JavaCompiler tool = ToolProvider.getSystemJavaCompiler();
        PrintWriter out = new PrintWriter(new StringWriter());
        final JavacTask task = (JavacTask) (tool.getTask(out, null, null, null, null, null));

        
        
        task.setTaskListener(new TaskListener() {
                public void started(TaskEvent e) {
                    task.getElements();
                    task.getTypes();
                }
                public void finished(TaskEvent e) { }
            });

        task.call();

        
        try {
            task.getElements();
            throw new AssertionError("IllegalStateException not thrown");
        }
        catch (IllegalStateException e) {
            
        }

        try {
            task.getTypes();
            throw new AssertionError("IllegalStateException not thrown");
        }
        catch (IllegalStateException e) {
            
        }
    }
}
