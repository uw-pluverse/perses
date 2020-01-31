



import java.io.*;
import java.util.Arrays;
import javax.tools.*;

public class T6258271 {
    public static void main(String... args) {
        JavaCompiler javac = ToolProvider.getSystemJavaCompiler();
        DiagnosticListener<JavaFileObject> dl =  new DiagnosticListener<JavaFileObject>() {
                public void report(Diagnostic<? extends JavaFileObject> message) {
                    JavaFileObject fo = message.getSource();
                    if ("__input".equals(fo.toUri().getPath()))
                        throw new AssertionError(fo);
                    System.out.println(message);
                }
            };
        StandardJavaFileManager fm = javac.getStandardFileManager(dl, null, null);
        Iterable<? extends JavaFileObject> files =
            fm.getJavaFileObjectsFromStrings(Arrays.asList("nofile.java"));
        javac.getTask(null, fm, dl, null, null, files).call();
    }
}
