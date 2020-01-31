



import java.util.Arrays;

import java.io.*;
import javax.tools.*;

public class T6265400 {
    public static final String SILLY_BILLY = "oh what a silly billy I am";

    public static void main (String... args) {
        try {
            JavaCompiler javac = javax.tools.ToolProvider.getSystemJavaCompiler();
            DiagnosticListener<JavaFileObject> dl =  new DiagnosticListener<JavaFileObject>() {
                    public void report (Diagnostic<? extends JavaFileObject> message) {
                        throw new NullPointerException(SILLY_BILLY);
                    }
                };
            StandardJavaFileManager fm = javac.getStandardFileManager(dl, null, null);
            Iterable<? extends JavaFileObject> files =
                fm.getJavaFileObjectsFromStrings(Arrays.asList("badfile.java"));
            javac.getTask(null, fm, dl, null, null, files).call();
        }
        catch (RuntimeException e) {
            Throwable cause = e.getCause();
            if (cause instanceof NullPointerException
                && cause.getMessage().equals(SILLY_BILLY))
                return;
            throw new Error("unexpected exception caught: " + e);
        }
        catch (Throwable t) {
            throw new Error("unexpected exception caught: " + t);
        }
        throw new Error("no exception caught");
    }
}
