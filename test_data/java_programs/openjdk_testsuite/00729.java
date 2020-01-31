



import java.io.File;
import java.util.Arrays;
import javax.tools.*;

public class T6265137 {
    public static void main(String... args) {
        JavaCompiler javac = ToolProvider.getSystemJavaCompiler();
        DiagnosticListener<JavaFileObject> dl =  new DiagnosticListener<JavaFileObject>() {
                public void report(Diagnostic<? extends JavaFileObject> message) {
                    System.out.println(message.getSource()
                                       +":"+message.getStartPosition()+":"
                                       +message.getStartPosition()+":"+message.getPosition());
                    System.out.println(message.toString());
                    System.out.format("Found problem: %s%n", message.getCode());
                    System.out.flush();
                }
        };
        StandardJavaFileManager fm = javac.getStandardFileManager(dl, null, null);
        String srcdir = System.getProperty("test.src");
        Iterable<? extends JavaFileObject> files =
            fm.getJavaFileObjectsFromFiles(Arrays.asList(new File(srcdir, "T6265137a.java")));
        javac.getTask(null, fm, dl, Arrays.asList("-target","1.5"), null, files).call();
    }
}
