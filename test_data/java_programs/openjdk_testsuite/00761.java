



import java.io.StringWriter;
import java.io.PrintWriter;
import java.net.URI;
import java.util.Arrays;
import java.util.List;
import javax.tools.JavaFileObject;
import javax.tools.SimpleJavaFileObject;
import static javax.tools.JavaFileObject.Kind;
import com.sun.source.util.JavacTask;

public class T6733837 extends ToolTester {

    public static void main(String... args) {
        new T6733837().exec();
    }

    public void exec() {
        JavaFileObject sfo = new SimpleJavaFileObject(URI.create("myfo:/Test.java"),Kind.SOURCE) {
            public CharSequence getCharContent(boolean ignoreEncodingErrors) {
                return "\tclass ErroneousWithTab";
            }
        };
        StringWriter sw = new StringWriter();
        PrintWriter out = new PrintWriter(sw);
        List<? extends JavaFileObject> files = Arrays.asList(sfo);
        task = tool.getTask(sw, fm, null, null, null, files);
        try {
            ((JavacTask)task).analyze();
        }
        catch (Throwable t) {
            throw new Error("Compiler threw an exception");
        }
        System.err.println(sw.toString());
        if (!sw.toString().contains("/Test.java"))
            throw new Error("Bad source name in diagnostic");
    }
}
