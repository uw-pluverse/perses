



import com.sun.tools.javac.api.JavacTaskImpl;
import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import javax.lang.model.element.TypeElement;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.ToolProvider;

public class TestJavacTask {
    static final JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
    static JavacTaskImpl getTask(File... file) {
        StandardJavaFileManager fm = compiler.getStandardFileManager(null, null, null);
        Iterable<? extends JavaFileObject> files =
            fm.getJavaFileObjectsFromFiles(Arrays.asList(file));
        return (JavacTaskImpl)compiler.getTask(null, fm, null, null, null, files);
    }

    static void basicTest(String... args) throws IOException {
        String srcdir = System.getProperty("test.src");
        File file = new File(srcdir, args[0]);
        JavacTaskImpl task = getTask(file);
        for (TypeElement clazz : task.enter(task.parse()))
            System.out.println(clazz.getSimpleName());
    }

    static void checkKindError() {
        final File testFile = new File("Test.java "); 
        try {
            getTask(testFile);
        } catch (IllegalArgumentException iae) {
            if (!iae.getMessage().contains("\"" + testFile.getName() + "\"")) {
                System.err.println("Got message: " + iae.getMessage());
                throw new RuntimeException("Error: expected string not found");
            }
        }
    }

    public static void main(String... args) throws IOException {
        basicTest(args);
        checkKindError();
    }
}
