



import java.io.File;
import java.io.IOException;
import java.io.StringWriter;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.ToolProvider;
import com.sun.source.tree.ClassTree;
import com.sun.source.util.JavacTask;
import com.sun.source.util.TreeScanner;
import java.io.FileWriter;

public class T6665791 {
    static String test = "public @interface Annotation { boolean booleanProperty() default false; }";
    static File test_java = new File("Test.java");

    public static void main(String[] args) throws Exception {
        write(test_java, test);

        JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
        StandardJavaFileManager manager =
                compiler.getStandardFileManager(null, null, null);
        Iterable<? extends JavaFileObject> units = manager.getJavaFileObjects(test_java);
        final StringWriter sw = new StringWriter();
        JavacTask task = (JavacTask) compiler.getTask(sw, manager, null, null,
                null, units);

        new TreeScanner<Boolean, Void>() {
            @Override
            public Boolean visitClass(ClassTree arg0, Void arg1) {
                sw.write(arg0.toString());
                return super.visitClass(arg0, arg1);
            }
        }.scan(task.parse(), null);

        System.out.println("output:");
        System.out.println(sw.toString());
        String found = sw.toString().replaceAll("\\s+", " ").trim();
        String expect = test.replaceAll("\\s+", " ").trim();
        if (!expect.equals(found)) {
            System.out.println("expect: " + expect);
            System.out.println("found:  " + found);
            throw new Exception("unexpected output");
        }
    }

    static void write(File file, String body) throws IOException {
        FileWriter out = new FileWriter(file);
        out.write(body);
        out.close();
    }
}
